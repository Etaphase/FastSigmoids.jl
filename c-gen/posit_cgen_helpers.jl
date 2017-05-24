#posit_cgen_helpers.jl.  A bunch of helper functions that make the cgen
#process smoother.

#symbols for each number
const sym = Dict(1 => :a, 2 => :b, 3 => :c, 4 => :d)

float_for_posit_size(n) = (n < 32) ? 32 : 64
c_ftype(n) = Dict(32 => "float", 64 => "double")[n]

#C internal use conversion functions
to_f(n, es, v) = "p$(n)e$(es)_to_f($v)"
to_p(n, es, v) = "f_to_p$(n)e$(es)($v)"

#C datatype names
p(n,es) = "p$(n)e$(es)_t"
#C function names
p(n,es,op) = "p$(n)e$(es)_$(op)"
#C++  class names
c(n,es) = "P$(n)e$(es)"

function c_literal(n::Unsigned)
  if isa(n, UInt8)
    "((uint8_t) 0x$(hex(n,2)))"
  elseif isa(n, UInt16)
    "((uint16_t) 0x$(hex(n,4)))"
  elseif isa(n, UInt32)
    "0x$(hex(n,8))L"
  elseif isa(n, UInt64)
    "0x$(hex(n,16))LL"
  end
end

const bits_to_UInt = Dict(8=>UInt8, 16=>UInt16, 32=>UInt32, 64=>UInt64)

top_bits(n) = one(bits_to_UInt[n]) << (n - 1)
zero_bits(n) = zero(bits_to_UInt[n])
