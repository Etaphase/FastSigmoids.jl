module FastSigmoid

  abstract Posit{N,ES} <: AbstractFloat
  abstract Valid{N,ES} <: AbstractFloat

  #categorize the different types of posit.
  bitstype 8 Posit8{ES} <: Posit{8,ES}
  bitstype 16 Posit16{ES} <: Posit{16,ES}
  bitstype 32 Posit32{ES} <: Posit{32,ES}
  bitstype 64 Posit64{ES} <: Posit{64,ES}

  #categorize the different types of valid.
  #note that each of the valids is a pair of
  #valids start:stop
  bitstype 16 Valid16{ES} <: Valid{16,ES}
  bitstype 32 Valid32{ES} <: Valid{32,ES}
  bitstype 64 Valid64{ES} <: Valid{64,ES}
  bitstype 128 Valid128{ES} <: Valid{128,ES}

  #for now: make these abstract values
  type QFloat <: AbstractFloat; end

  #allow for a NaN error type.
  type NaNError <: Exception; end

  export Posit, Posit8, Posit16, Posit32, Posit64
  export Valid, Valid16, Valid32, Valid64, Valid128
  export NaNError

  #doing things with fastsigmoids
  include("convertposit.jl")
  include("positops.jl")
  include("positprops.jl")

end # module
