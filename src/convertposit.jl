#convertposit.jl - posit conversions for FastSigmoid

function __UT{T <: Posit}(::Type{T})
  (T == Posit) && throw(ArgumentError("__UT cannot operate on general posit"))
  S = sizeof(T) * 8
  Dict(8 => UInt8, 16 => UInt16, 32 => UInt32, 64 => UInt64)[S]
end
function __ST{T <: Posit}(::Type{T})
  (T == Posit) && throw(ArgumentError("__ST cannot operate on general posit"))
  S = sizeof(T) * 8
  Dict(8 => Int8, 16 => Int16, 32 => Int32, 64 => Int64)[S]
end
function __PT{T <: Posit}(::Type{T})
  isbits(T) && return T
  (T == Posit) && throw(ArgumentError("__PT cannot operate on general posit"))
  S = sizeof(T) * 8
  (Posit{S} <: T) && throw(ArgumentError("__PT requires a type with an ES"))
  __es{N,ES}(::Type{Posit{N,ES}}) = ES
  es = __es(T)
  Dict(8 => Posit8{es}, 16 => Posit16{es}, 32 => Posit32{es}, 64 => Posit64{es})[S]
end

#convenience functions to convert to signed and unsigned representations.
@generated function __u{N,ES}(x::Posit{N,ES})
  UT = __UT(Posit{N,ES})
  :(reinterpret($UT, x))
end
@generated function __s{N,ES}(x::Posit{N,ES})
  ST = __ST(Posit{N,ES})
  :(reinterpret($ST, x))
end

doc"""
  `FastSigmoid.__decomp(x)`
  takes a fastsigmoid number and breaks it up into three parts:
  1) sign (bool)
  2) exponent (int, same as backing int type)
  3) fraction (uint)
"""
@generated function __decomp{N,ES}(x::Posit{N,ES})
  BackingFloat = Dict(8 => Float32, 16 => Float32, 32 => Float64)[N]
  BackingSInt  = Dict(8 => Int32, 16 => Int32, 32 => Int64)[N]
  BackingUInt  = Dict(8 => UInt32, 16 => UInt32, 32 => UInt64)[N]
  IntType = Dict(8 => UInt8, 16 => UInt16, 32 => UInt32)[N]
  topbit = one(IntType) << (N - 1)
  invbit = one(IntType) << (N - 2)
  #exp_mask done in Int64
  exp_mask = BackingSInt((1 << ES) - 1)
  #size delta.
  sizedelta = sizeof(BackingUInt) * 8 - N
  quote
    intdecomp = reinterpret($IntType, x)
    sign = false
    #decide the sign by checking if the topbit is zero.
    if (intdecomp & ($topbit) != 0)
      intdecomp = -intdecomp
      sign = true
    end
    #set up some local values.
    local fraction::($BackingUInt)
    local shift::Int64
    local regime::Int64
    #ascertain the shift and regime.
    if (intdecomp & ($invbit) != 0)
      #note that shift and regime are going to have Int64 data type.
      shift = leading_ones(intdecomp | $topbit) + 1
      regime = shift - 3
    else
      shift = leading_zeros(intdecomp) + 1
      regime = -shift + 2
    end
    #exp_mask is going to have the correct size.
    exponent = $exp_mask & (intdecomp >> (N - shift - ES))
    exponent |= ($BackingSInt(regime) << ES)

    #shift over the fraction, boss.
    fraction = ($BackingUInt(intdecomp) << (shift + ES + $sizedelta))

    (sign, exponent, fraction)
  end
end

doc"""
  `FastSigmoid.__p2f(x)`
  converts a posit(x) to the backing float type.
"""
@generated function __p2f{N,ES}(x::Posit{N,ES})

  BackingFloat = Dict(8 => Float32, 16 => Float32, 32 => Float64)[N]
  BackingUInt  = Dict(8 => UInt32, 16 => UInt32, 32 => UInt64)[N]

  #need to implement promotion to higher types if the ES requires it.
  fracshift = Dict(8 => 9, 16 => 9, 32 => 12)[N]
  bias      = Dict(8 => 127, 16 => 127, 32 => 1023)[N]
  expshift  = Dict(8 => 23, 16 => 23, 32 => 52)[N]
  signbit   = Dict(8 => 0x8000_0000, 16 => 0x8000_0000, 32 => 0x8000_0000_0000_0000)[N]

  quote
    #check for the dropout values
    if iszeroinf(x)
      if __u(x) == 0
        return zero($BackingFloat)
      else
        return $BackingFloat(Inf)
      end
    end

    #next pull parts out of the posit value
    (sign, exponent, fraction) = __decomp(x)
    #put them together.
    intresult::($BackingUInt) = fraction >> $fracshift
    intresult |= (exponent + $bias) << $expshift
    #set the sign.
    intresult |= ($signbit) * sign
    reinterpret($BackingFloat, intresult)
  end
end

typealias IEEEFloat Union{Float16, Float32, Float64}

#for conversions to other IEEE float types, don't bother directly converting.
function Base.convert{T <: IEEEFloat, U <: Posit}(::Type{T}, x::U)
  T(__p2f(x))
end

#for conversions back to a posit type, go ahead and do this:
@generated function Base.convert{N, ES, T <: IEEEFloat}(::Type{Posit{N,ES}}, x::T)

  fullsize = sizeof(x) * 8
  fracsize = Dict(Float16 => 10, Float32 => 23, Float64 => 52)[T]
  IntType = Dict(Float16 => UInt16, Float32 => UInt32, Float64 => UInt64)[T]
  SIntType = Dict(Float16 => Int16, Float32 => Int32, Float64 => Int64)[T]
  bias = SIntType((1 << (fullsize - fracsize - 2)) - 1)
  topbit = one(IntType) << (fullsize - 1)
  topmask = ~topbit
  PositType = __PT(Posit{N,ES})
  pinf = one(__UT(Posit{N, ES})) << (N - 1)

  quote
    intform = reinterpret($IntType, x)
    if isnan(x)
      throw(NaNError())
    elseif isinf(x)
      return reinterpret($PositType, $pinf)
    elseif x == zero(T)
      return zero($PositType)
    end

    sign = ((intform & $topbit) != 0)

    #signed exponent value.
    exponent = ($SIntType((intform & $topmask) >> $fracsize)) - $bias

    #right-shifted fraction value.
    fraction = intform << ($fullsize - $fracsize)

    __build(Posit{N,ES}, sign, exponent, fraction)
  end
end


function regime_exponent{T <: Signed,ES}(exponent::T, ::Type{Val{ES}})
  low_mask = T((1 << ES) - 1)
  (exponent >> ES, exponent & low_mask)
end

@generated function __build{N, ES}(::Type{Posit{N, ES}}, sign::Bool, exponent::Signed, fraction::Unsigned)

  sizeof(exponent) == sizeof(fraction) || throw(ArgumentError("mismatched integer sizes"))

  UIntType = __UT(Posit{N, ES})
  IntType = __ST(Posit{N, ES})
  PositType = __PT(Posit{N, ES})
  topbit = one(IntType) << (N - 1)
  topmask = ~topbit

  #in case our starting floating point was too small, increase the size of the exponent and fraction.
  if N > (sizeof(exponent) * 8)
    shift = N - sizeof(exponent) * 8
    adjuster = quote
      adj_exponent = $IntType(exponent)
      adj_fraction = $UIntType(fraction) << $shift
      summary = false
    end
  elseif N == (sizeof(exponent) * 8)
    adjuster = quote
      adj_exponent = exponent
      adj_fraction = fraction
      summary = false
    end
  else
    shift = (sizeof(exponent) * 8) - N
    guardmask = one(UIntType) << (shift - 1)
    summarymask = guardmask - one(UIntType)
    adjuster = quote
      adj_exponent = $IntType(exponent)
      adj_fraction = $UIntType(fraction >> $shift)
      summary = ($summarymask & fraction) != 0
    end
  end

  quote
    #adjust the integers.
    $adjuster


    if exponent < 0
      (regime, subexponent) = regime_exponent(adj_exponent, Val{ES})

      prefix = $topbit | (subexponent << (N - ES - 1))
      prefix = prefix >>> (-regime + 1)

      fshift = -regime + 2 + ES
    else
      (regime, subexponent) = regime_exponent(adj_exponent, Val{ES})
      #set the regime.
      prefix = $topbit | (subexponent << (N - ES - 2))
      #then add the exponent values
      prefix >>= (regime + 1)
      prefix &= $topmask

      fshift = regime + 3 + ES
    end

    #combine the prefix with the shifted fraction
    absval = prefix | $IntType(adj_fraction >> fshift)

    #decide whether or not we need to round.
    lastbit = (one($UIntType) & absval) != 0
    guardbit = (adj_fraction & (one($UIntType) << (fshift - 1))) != 0
    summmask = guardbit - one($UIntType)
    summary = summary || ((summmask & adj_fraction) != 0)
    absval += (summary & guardbit) | (lastbit & guardbit)

    reinterpret($PositType, sign ? -absval : absval)
  end
end

#__build is much simpler when ES = 0
#=
function __build{N}(::Type{Posit{N, 0}}, sign, exponent, fraction)

  IntType = __ST(Posit{N, 0})
  PositType = __PT(Posit{N, 0})
  topbit = one(IntType) << (N - 1)
  topmask = ~topbit

  quote
  if exponent < 0
    fshift = -exponent + 2
    body = one(@UInt) << (__BITS + exponent - 2)
  else
    #set the prefix.  That's 2^exponent - 1
    prefix = (one(@UInt) << (exponent + 1)) - 1
    #shift the prefix over
    body = prefix << (__BITS - exponent - 2)
    fshift = exponent + 3
  end

  absval = body | (fraction >> fshift)

  reinterpret(Sigmoid{N, 0, mode}, sign ? -absval : absval)
  end
end
=#

#reimplement the reinterpret directive to support non-leaf posit types.
Base.reinterpret{ES}(::Type{Posit{8,ES}}, i::UInt8) = reinterpret(Posit8{ES}, i)
Base.reinterpret{ES}(::Type{Posit{16,ES}}, i::UInt16) = reinterpret(Posit16{ES}, i)
Base.reinterpret{ES}(::Type{Posit{32,ES}}, i::UInt32) = reinterpret(Posit32{ES}, i)
Base.reinterpret{ES}(::Type{Posit{64,ES}}, i::UInt64) = reinterpret(Posit64{ES}, i)
