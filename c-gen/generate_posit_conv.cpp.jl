const bits_to_UInt = Dict(8=>UInt8, 16=>UInt16, 32=>UInt32, 64=>UInt64)

exp_bits(n) = Dict(32 => 8, 64 => 11)[n]
exp_shift(n) = n - exp_bits(n) - 1
exp_bias(n) = (1 << (exp_bits(n) - 1)) - 1
exp_mask(n) = top_bits(n) - (top_bits(n) >> exp_bits(n))

frac_mask(n)  = (top_bits(n) >> 1) - one(bits_to_UInt[n])
guard_mask(n, fpsize) = top_bits(fpsize) >> n
inner_mask(n, fpsize) = top_bits(fpsize) >> (n - 1)
summ_mask(n, fpsize) = guard_mask(n, fpsize) - one(bits_to_UInt[n])

function floatconvert(n, es)
  maximum_exponent = (n - 2) * (2 ^ es)
  minimum_exponent = -((n - 1) * (2 ^ es))

  ftype = c_ftype(float_for_posit_size(n))

  fcall = (es == 0) ? "$(ftype)_to_p$(n)_zero_es(fval)" : "$(ftype)_to_p$(n)(fval, $(es), $maximum_exponent, $minimum_exponent)"

  """
$(f2pheader(n,es)){
  $(p(n,es)) res;
  res.udata = $(fcall);
  return res;
}
  """
end

function floatconvert(n; zero_es = false)

  fpsize = float_for_posit_size(n)  #for now.
  ftype = c_ftype(fpsize)

  es_fn = zero_es ? "_zero_es" : ""
  es_hd = zero_es ? "" : ", int16_t es, int16_t maximum_exponent, int16_t minimum_exponent"

  max_exp = zero_es ? n - 2 : "maximum_exponent"
  min_exp = zero_es ? 1 - n : "minimum_exponent"

  es_expfrc = zero_es ? """
  //use an uint$(fpsize)_t value as an intermediary store for
    //raw fraction bits.  Shift all the way to the right and then

    int16_t regime = exponent;
    uint$(fpsize)_t frac = (*ival) << ($(exp_bits(fpsize) - 1));
    //there are no exponent bits.
    frac &= $(c_literal((top_bits(fpsize) >> 1) - one(bits_to_UInt[fpsize])));
  """ : """
  //divide up this exponent into a proper exponent and regime.
    int16_t regime = exponent >> es;
    exponent = exponent & ((1 << es) - 1);
    //use an uint$(fpsize)_t value as an intermediary store for
    //all off the fraction bits, initially backing off by es.  Mask out the top
    //two bits.
    uint$(fpsize)_t frac = ((*ival) << ($(exp_bits(fpsize) - 1) - es)) & ($(c_literal(frac_mask(fpsize))) >> es);
    //append the exponent bits to frac representation.
    frac |= ((uint$(fpsize)_t) exponent) << ($(fpsize - 2) - es);
  """

  """
static uint$(n)_t $(ftype)_to_p$(n)$(es_fn)($(ftype) fval$(es_hd)){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return $(c_literal(top_bits(n)));};
  if (fval == 0)   {return $(c_literal(zero_bits(n)));};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from $(ftype) precision to UInt$(n)
  uint$(fpsize)_t *ival = (uint$(fpsize)_t *) &fval;
  bool signbit = (($(c_literal(top_bits(fpsize))) & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = ((($(c_literal(exp_mask(fpsize))) & (*ival)) >> $(exp_shift(fpsize))) - $(exp_bias(fpsize)));
  //pin the exponent.
  exponent = (exponent > $(max_exp)) ? $(max_exp) : exponent;
  exponent = (exponent < $(min_exp)) ? $(min_exp) : exponent;

  $(es_expfrc)

  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= $(c_literal(top_bits(fpsize)));
  } else {
    shift = -regime;
    frac |= $(c_literal(top_bits(fpsize) >> 1));
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint$(fpsize)_t)(((int$(fpsize)_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & $(c_literal(top_bits(fpsize) - one(bits_to_UInt[fpsize])));

  bool guard = (frac & $(c_literal(guard_mask(n,fpsize)))) != 0;
  bool summ  = (frac & $(c_literal(summ_mask(n,fpsize))) ) != 0;
  bool inner = (frac & $(c_literal(inner_mask(n,fpsize)))) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? $(c_literal(inner_mask(n, fpsize))) : $(c_literal(zero_bits(fpsize)));
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> $(fpsize - n);

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? $(c_literal(one(bits_to_UInt[fpsize]))) : frac;

  uint$(n)_t sfrac = (uint$(n)_t) frac;

  return (signbit ? -sfrac : sfrac);
}
"""
end

function positconvert(n, es)

  fpsize = float_for_posit_size(n)
  ftype = c_ftype(fpsize)

  """
$(p2fheader(n,es)){
  return p$(n)_to_$(ftype)(pval.udata, $(es), $(c_literal(-(top_bits(n) >> (es - 1)))));
}
  """
end

function positconvert(n)

  fpsize = float_for_posit_size(n)
  ftype = c_ftype(fpsize)
  clz = (n == 64) ? "__builtin_clzl" : "__builtin_clz"

  """
static $(ftype) p$(n)_to_$(ftype)(uint$(n)_t pval, int16_t es, uint$(n)_t es_mask){
  //check for infs and zeros, which do not necessarily play nice with our algorithm.
  if (pval == $(c_literal(top_bits(n)))) return INFINITY;
  if (pval == $(c_literal(zero_bits(n)))) return ($(ftype)) 0;
  //next, determine the sign of the posit value
  bool negative = ((pval & $(c_literal(top_bits(n)))) != 0);
  uint$(n)_t pos_val = negative ? -pval : pval;
  //ascertain if it's inverted.
  bool inverted = (pos_val & $(c_literal(top_bits(n) >> 1))) == 0;
  //note that the clz/clo intrinsics operate on 32-bit data types.
  uint16_t u_regime;
  int16_t s_regime;
  if (inverted){
    //just count the leading zeros, which will tell you the regime.
    u_regime = $(clz)(pos_val)$(n < 32 ? n - 32 : "") - 1;
    s_regime = - u_regime;
  } else {
    //there's no "clo" intrinsic in standard c (whether or not there is a
    //machine opcode) so we have to do this very awkward transformation first.
    uint$(n)_t z_posit = ~pos_val & $(c_literal(~top_bits(n)));
    //__builtin_clz has "undefined" state for a value of 0.  W.T.F, C??
    u_regime = (z_posit == 0) ? $(n - 1) : $(clz)(z_posit)$(n < 32 ? n - 32 : "") - 1;
    s_regime = u_regime - 1;
  }
  //next create the proper exp/frac value by shifting the pos_val, based on the
  //unsigned regime value.
  uint$(n)_t p_exp_frac = (pos_val << (u_regime + 2));

  //extract the exponent value by grabbing the top bits.
  int16_t exponent = (p_exp_frac & es_mask) >> ($(n) - es);

  //append the (signed) regime value to this.
  exponent |= (s_regime << es);
  //finally, add the bias value
  exponent += $(exp_bias(fpsize));

  //shift the fraction again to obliterate the exponent section.
  uint$(n)_t p_frac = p_exp_frac << es;

  uint$(fpsize)_t result;
  result = (negative ? $(c_literal(top_bits(fpsize))) : $(c_literal(zero_bits(fpsize)))) |
    (((uint$(fpsize)_t) exponent) << $(exp_shift(fpsize))) |
    (((uint$(fpsize)_t) p_frac) << ($(exp_shift(fpsize) - n)));

  //convert the result floatint to the desired float type
  return *(($ftype *) &result);
}
"""
end

function generate_posit_conv_c(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, "#include \"include/posit.h\"\n")
  write(io, "#include <stdio.h>")
  write(io, "\n")

  for n in sort(collect(keys(posit_defs)))

    write(io, "/*************************************************************/\n")
    write(io, "/* posit_$(n) section, general form                          */\n")
    write(io, "/*************************************************************/\n")
    write(io, "\n")

    #write down the the general float conversion
    write(io, floatconvert(n))
    write(io, "\n")
    write(io, floatconvert(n, zero_es = true))
    write(io, "\n")
    #write down the general posit conversion
    write(io, positconvert(n))
    write(io, "\n")

    write(io, "/*************************************************************/\n")
    write(io, "/* posit_$(n) section, variable ES adapters                  */\n")
    write(io, "/*************************************************************/\n")
    write(io, "\n")
    for es in posit_defs[n]
      write(io, floatconvert(n, es))
      write(io, "\n")
      write(io, positconvert(n, es))
      write(io, "\n")
    end
  end
end
