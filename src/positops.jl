#posit_ops.jl
#posit operations.

macro __unaryshim(fn)
  :($fn{N,ES}(x::Posit{N,ES}) = Posit{N,ES}($fn(__p2f(x))))
end

macro __binaryshim(fn)
  :($fn{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES}) = Posit{N,ES}($fn(__p2f(lhs), __p2f(rhs))))
end

#some unary operations
Base.:+{N,ES}(x::Posit{N,ES}) = x
Base.:-{N,ES}(x::Posit{N,ES}) = reinterpret(__PT(Posit{N,ES}), -__s(x))

#partial required operations
function Base.:+{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES})
  if (isinf(lhs) | isinf(rhs))
    (isinf(lhs) & isinf(rhs)) && (throw(NaNError()))
    return Posit{N,ES}(Inf)
  end

  Posit{N,ES}(__p2f(lhs) + __p2f(rhs))
end

@__binaryshim Base.:-
@__binaryshim Base.:*

function Base.cmp{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES})
  if isinf(lhs) && isinf(rhs)
    throw(DomainError())
  else
    cmp(__s(lhs), __s(rhs))
  end
end

function Base.:<{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES})
  if isinf(lhs) || isinf(rhs)
    true
  else
    __s(lhs) < __s(rhs)
  end
end

function Base.:<={N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES})
  if isinf(lhs) || isinf(rhs)
    true
  else
    __s(lhs) <= __s(rhs)
  end
end

#do not waste time downconverting.
Base.:(==){N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES}) = __u(lhs) == __u(rhs)

#full posit required operations
@__binaryshim Base.:/
@__unaryshim Base.inv
@__unaryshim Base.log2
@__unaryshim Base.exp2

#full posit extended operations
@__unaryshim Base.sqrt
@__unaryshim Base.log10
@__unaryshim Base.log
@__unaryshim Base.exp
@__binaryshim Base.:^
@__binaryshim Base.log
@__unaryshim Base.sin
@__unaryshim Base.cos
@__unaryshim Base.atan
@__binaryshim Base.atan2

#required fused operations - overload julia definition
function Base.fma{N,ES}(a::Posit{N,ES}, b::Posit{N,ES}, c::Posit{N,ES})
  Posit{N,ES}(fma(__p2f(a), __p2f(b), __p2f(c)))
end
function fms{N, ES}(a::Posit{N,ES}, b::Posit{N,ES}, c::Posit{N,ES})
  Posit{N,ES}(fma(__p2f(a), __p2f(b), -__p2f(c)))
end
function nfma{N, ES}(a::Posit{N,ES}, b::Posit{N,ES}, c::Posit{N,ES})
  Posit{N,ES}(-fma(__p2f(a), __p2f(b), __p2f(c)))
end
function nfms{N, ES}(a::Posit{N,ES}, b::Posit{N,ES}, c::Posit{N,ES})
  Posit{N,ES}(-fma(__p2f(a), __p2f(b), -__p2f(c)))
end

export fms, nfma, nfms

#the following operations:
#FAS - fused-add-scale
#FCP - fused cross product
#FDP - fused dot product
# are found in "fusedpositoperations.jl"
