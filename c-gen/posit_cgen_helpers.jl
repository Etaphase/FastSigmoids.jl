#posit_cgen_helpers.jl.  A bunch of helper functions that make the cgen
#process smoother.

float_for_posit_size(n) = (n < 32) ? 32 : 64
c_ftype(n) = Dict(32 => "float", 64 => "double")[n]

to_f(n, es, v) = "p$(n)e$(es)_to_f($v)"
to_p(n, es, v) = "f_to_p$(n)e$(es)($v)"
p(n,es) = "p$(n)e$(es)_t"
p(n,es,op) = "p$(n)e$(es)_$(op)"

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

top_bits(n) = one(bits_to_UInt[n]) << (n - 1)
zero_bits(n) = zero(bits_to_UInt[n])
