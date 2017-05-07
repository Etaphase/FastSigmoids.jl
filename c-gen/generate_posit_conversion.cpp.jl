

const bits_to_UInt = Dict(8=>UInt8, 16=>UInt16, 32=>UInt32, 64=>UInt64)

top_bits(n) = one(bits_to_UInt[n]) << (n - 1)
zero_bits(n) = zero(bits_to_UInt[n])
function c_literal(n)
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

c_ftype(n) = Dict(32 => "float", 64 => "double")[n]

exp_bits(n) = Dict(32 => 8, 64 => 11)[n]
exp_shift(n) = n - exp_bits(n) - 1
exp_bias(n) = (1 << (exp_bits(n) - 1)) - 1
exp_mask(n) = top_bits(n) - (top_bits(n) >> exp_bits(n))

frac_mask(n)  = (top_bits(n) >> 1) - 1
guard_mask(n, fpsize) = top_bits(fpsize) >> n
inner_mask(n, fpsize) = top_bits(fpsize) >> (n - 1)
summ_mask(n, fpsize) = guard_mask(n, fpsize) - 1

function floatconvert(n, es)

  fpsize = 64  #for now.
  ftype = c_ftype(fpsize)

  maximum_exponent = (n - 2) * (2 ^ es)
  minimum_exponent = -((n - 1) * (2 ^ es))

  """
extern "C" p$(n)_$(es)_t $(ftype)_to_p$(n)_$(es)($(ftype) fval){
  //create a result value
  p$(n)_$(es)_t res;

  //infinity and NaN checks:
  if (isinf(fval)) {res.udata = $(c_literal(top_bits(n))); return res};
  if (fval == 0)   {res.udata = $(c_literal(zero_bits(n))); return res};

  if (isnan(fval)){
    #ifdef __cplusplus
      throw NaNError();
    #else
      longjmp(__nan_ex_buf__, 1);
    #endif
  }

  //do a surreptitious conversion from double precision to UInt64
  uint$(fpsize)_t *ival = (uint$(fpsize)_t *) &fval;

  bool signbit = (($(c_literal(top_bits(fpsize))) & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = ((($(c_literal(exp_mask(fpsize))) & (*ival)) >> $(exp_shift(fpsize))) - $(exp_bias(fpsize)));

  //pin the exponent.

  exponent = (exponent > $(maximum_exponent)) ? $(maximum_exponent) : exponent;
  exponent = (exponent < $(minimum_exponent)) ? $(minimum_exponent) : exponent;

  //divide up this exponent into a proper exponent and regime based on (es = $es).
  exponent = exponent & $(hex((1 << es) - 1, 4));
  int16_t regime = exponent >> $(es);

  //use an uint$(fpsize)_t value as an intermediary store for
  //all off the fraction bits, backing off by (es = $es) bits.  Mask out the top two bits.

  uint$(fpsize)_t frac = ((*ival) << $(exp_bits(fpsize) - 1 - es)) & ($(c_literal(frac_mask(fpsize) >> es)));

  //append the exponent bits to frac representation.
  frac |= ((uint$(fpsize)_t) exponent) << ($(fpsize - 2 - es))

  //next, append the appropriate shift prefix in front of the value.

  int16_t shift = 0;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= $(c_literal(top_bits(fpsize)));
  } else {
    shift = -regime;
    frac |= $(c_literal(top_bits(fpsize) >> 1));
  }

  //perform an *arithmetic* shift; convert back to unsigned.

  frac = (uint$(fpsize)_t)(((int$(fpsize)_t) frac) >> shift);

  bool guard = (frac & $(c_literal(guard_mask(n,fpsize)))) != 0;
  bool summ  = (frac & $(c_literal(summ_mask(n,fpsize))) ) != 0;
  bool inner = (frac & $(c_literal(inner_mask(n,fpsize)))) != 0;

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.

  frac &= $(c_literal(top_bits(n) - 1));


  //round the frac variable in the event it needs be augmented.
  frac += ((guard && inner) || (guard && summ)) ? $(c_literal(inner_mask(n, fpsize))) : $(c_literal(zero_bits(fpsize)));

  //shift as necessary
  res.udata = signbit ? (-frac >> $(fpsize - n)) : (frac >> $(fpsize-n));

  return res;
}
"""
end
