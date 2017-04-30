
@generated function iszeroinf{N,ES}(x::Posit{N,ES})
  IntType = __UT(Posit{N,ES})
  otherbits = (one(IntType) << (N - 1) - one(IntType))
  z = zero(IntType)
  :(__u(x) & $otherbits == $z)
end

@generated function Base.isinf{N,ES}(x::Posit{N,ES})
  IntType = __UT(Posit{N,ES})
  topbit = one(IntType) << (N - 1)
  :(__u(x) == $topbit)
end
#this code may need to change if we activate NaN mode.
Base.isfinite{N,ES}(x::Posit{N,ES}) = !isinf(x)
Base.isnan{N,ES}(x::Posit{N,ES}) = false

Base.isequal{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES}) = __u(lhs) == __u(rhs)
Base.isless{N,ES}(lhs::Posit{N,ES}, rhs::Posit{N,ES}) = __s(lhs) < __s(rhs)

#zero and one constants
@generated function Base.zero{T <: Posit}(::Type{T})
  IntType = __UT(T)
  PositType = __PT(T)
  :(reinterpret($PositType, zero($IntType)))
end
@generated function Base.zero{N,ES}(::Posit{N,ES})
  IntType = __UT(Posit{N,ES})
  PositType = __PT(Posit{N,ES})
  :(reinterpret($PositType, zero($IntType)))
end

@generated function Base.one{T <: Posit}(::Type{T})
  IntType = __UT(T)
  PositType = __PT(T)
  N = sizeof(T) * 8
  :(reinterpret($PositType, one($IntType) << ($N - 2)))
end
@generated function Base.one{N,ES}(::Posit{N,ES})
  IntType = __UT(Posit{N,ES})
  PositType = __PT(Posit{N,ES})
  :(reinterpret($PositType, one($IntType) << (N - 2)))
end

#spoof the sizeof operator to do the right thing here.
Base.sizeof{N,ES}(::Type{Posit{N,ES}}) = div(N,8)
Base.sizeof{N}(::Type{Posit{N}}) = div(N,8)
