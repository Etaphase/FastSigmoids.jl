#include "include/posit.h"/*************************************************************/
/*  posit_8 section, general forms                           */
/*************************************************************/

static uint8_t float_to_p8(float fval, int16_t es, int16_t maximum_exponent, int16_t minimum_exponent){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return ((uint8_t) 0x80);};
  if (fval == 0)   {return ((uint8_t) 0x00);};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from float precision to UInt8
  uint32_t *ival = (uint32_t *) &fval;
  bool signbit = ((0x80000000L & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7f800000L & (*ival)) >> 23) - 127);
  //pin the exponent.
  exponent = (exponent > maximum_exponent) ? maximum_exponent : exponent;
  exponent = (exponent < minimum_exponent) ? minimum_exponent : exponent;

  //divide up this exponent into a proper exponent and regime.
  int16_t regime = exponent >> es;
  exponent = exponent & ((1 << es) - 1);
  //use an uint32_t value as an intermediary store for
  //all off the fraction bits, initially backing off by es.  Mask out the top
  //two bits.
  uint32_t frac = ((*ival) << (7 - es)) & (0x3fffffffL >> es);
  //append the exponent bits to frac representation.
  frac |= ((uint32_t) exponent) << (30 - es);


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x80000000L;
  } else {
    shift = -regime;
    frac |= 0x40000000L;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint32_t)(((int32_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffL;

  bool guard = (frac & 0x00800000L) != 0;
  bool summ  = (frac & 0x007fffffL ) != 0;
  bool inner = (frac & 0x01000000L) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x01000000L : 0x00000000L;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 24;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x00000001L : frac;

  uint8_t sfrac = (uint8_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static uint8_t float_to_p8_zero_es(float fval){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return ((uint8_t) 0x80);};
  if (fval == 0)   {return ((uint8_t) 0x00);};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from float precision to UInt8
  uint32_t *ival = (uint32_t *) &fval;
  bool signbit = ((0x80000000L & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7f800000L & (*ival)) >> 23) - 127);
  //pin the exponent.
  exponent = (exponent > 6) ? 6 : exponent;
  exponent = (exponent < -7) ? -7 : exponent;

  //use an uint32_t value as an intermediary store for
  //raw fraction bits.  Shift all the way to the right and then

  int16_t regime = exponent;
  uint32_t frac = (*ival) << (7);
  //there are no exponent bits.
  frac &= 0x3fffffffL;


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x80000000L;
  } else {
    shift = -regime;
    frac |= 0x40000000L;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint32_t)(((int32_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffL;

  bool guard = (frac & 0x00800000L) != 0;
  bool summ  = (frac & 0x007fffffL ) != 0;
  bool inner = (frac & 0x01000000L) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x01000000L : 0x00000000L;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 24;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x00000001L : frac;

  uint8_t sfrac = (uint8_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static float p8_to_float(uint8_t pval, int16_t es, uint8_t es_mask){
  //check for infs and zeros, which do not necessarily play nice with our algorithm.
  if (pval == ((uint8_t) 0x80)) return INFINITY;
  if (pval == ((uint8_t) 0x00)) return (float) 0;
  //next, determine the sign of the posit value
  bool negative = ((pval & ((uint8_t) 0x80)) != 0);
  uint8_t pos_val = negative ? -pval : pval;
  //ascertain if it's inverted.
  bool inverted = (pos_val & ((uint8_t) 0x40)) == 0;
  //note that the clz/clo intrinsics operate on 32-bit data types.
  uint16_t u_regime;
  int16_t s_regime;
  if (inverted){
    //just count the leading zeros, which will tell you the regime.
    u_regime = __builtin_clz(pos_val)-24 - 1;
    s_regime = - u_regime;
  } else {
    //there's no "clo" intrinsic in standard c (whether or not there is a
    //machine opcode) so we have to do this very awkward transformation first.
    uint8_t z_posit = ~pos_val & ((uint8_t) 0x7f);
    //__builtin_clz has "undefined" state for a value of 0.  W.T.F, C??
    u_regime = (z_posit == 0) ? 7 : __builtin_clz(z_posit)-24 - 1;
    s_regime = u_regime - 1;
  }
  //next create the proper exp/frac value by shifting the pos_val, based on the
  //unsigned regime value.
  uint8_t p_exp_frac = (pos_val << (u_regime + 2));

  //extract the exponent value by grabbing the top bits.
  int16_t exponent = (p_exp_frac & es_mask) >> (8 - es);

  //append the (signed) regime value to this.
  exponent |= (s_regime << es);
  //finally, add the bias value
  exponent += 127;

  //shift the fraction again to obliterate the exponent section.
  uint8_t p_frac = p_exp_frac << es;

  uint32_t result;
  result = (negative ? 0x80000000L : 0x00000000L) |
    (((uint32_t) exponent) << 23) |
    (((uint32_t) p_frac) << (15));

  //convert the result floatint to the desired float type
  return *((float *) &result);
}


/*************************************************************/
/*  posit_8 section, variable ES adapters                    */
/*************************************************************/
extern "C"   p8e0_t f_to_p8e0(float fval){
  p8e0_t res;
  res.udata = float_to_p8_zero_es(fval);
  return res;
}
  
extern "C"   float p8e0_to_f(p8e0_t pval){
  return p8_to_float(pval.udata, 0, ((uint8_t) 0x00));
}
  

extern "C"   p8e1_t f_to_p8e1(float fval){
  p8e1_t res;
  res.udata = float_to_p8(fval, 1, 12, -14);
  return res;
}
  
extern "C"   float p8e1_to_f(p8e1_t pval){
  return p8_to_float(pval.udata, 1, ((uint8_t) 0x80));
}
  

extern "C"   p8e2_t f_to_p8e2(float fval){
  p8e2_t res;
  res.udata = float_to_p8(fval, 2, 24, -28);
  return res;
}
  
extern "C"   float p8e2_to_f(p8e2_t pval){
  return p8_to_float(pval.udata, 2, ((uint8_t) 0xc0));
}
  

/*************************************************************/
/*  posit_16 section, general forms                           */
/*************************************************************/

static uint16_t float_to_p16(float fval, int16_t es, int16_t maximum_exponent, int16_t minimum_exponent){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return ((uint16_t) 0x8000);};
  if (fval == 0)   {return ((uint16_t) 0x0000);};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from float precision to UInt16
  uint32_t *ival = (uint32_t *) &fval;
  bool signbit = ((0x80000000L & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7f800000L & (*ival)) >> 23) - 127);
  //pin the exponent.
  exponent = (exponent > maximum_exponent) ? maximum_exponent : exponent;
  exponent = (exponent < minimum_exponent) ? minimum_exponent : exponent;

  //divide up this exponent into a proper exponent and regime.
  int16_t regime = exponent >> es;
  exponent = exponent & ((1 << es) - 1);
  //use an uint32_t value as an intermediary store for
  //all off the fraction bits, initially backing off by es.  Mask out the top
  //two bits.
  uint32_t frac = ((*ival) << (7 - es)) & (0x3fffffffL >> es);
  //append the exponent bits to frac representation.
  frac |= ((uint32_t) exponent) << (30 - es);


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x80000000L;
  } else {
    shift = -regime;
    frac |= 0x40000000L;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint32_t)(((int32_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffL;

  bool guard = (frac & 0x00008000L) != 0;
  bool summ  = (frac & 0x00007fffL ) != 0;
  bool inner = (frac & 0x00010000L) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x00010000L : 0x00000000L;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 16;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x00000001L : frac;

  uint16_t sfrac = (uint16_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static uint16_t float_to_p16_zero_es(float fval){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return ((uint16_t) 0x8000);};
  if (fval == 0)   {return ((uint16_t) 0x0000);};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from float precision to UInt16
  uint32_t *ival = (uint32_t *) &fval;
  bool signbit = ((0x80000000L & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7f800000L & (*ival)) >> 23) - 127);
  //pin the exponent.
  exponent = (exponent > 14) ? 14 : exponent;
  exponent = (exponent < -15) ? -15 : exponent;

  //use an uint32_t value as an intermediary store for
  //raw fraction bits.  Shift all the way to the right and then

  int16_t regime = exponent;
  uint32_t frac = (*ival) << (7);
  //there are no exponent bits.
  frac &= 0x3fffffffL;


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x80000000L;
  } else {
    shift = -regime;
    frac |= 0x40000000L;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint32_t)(((int32_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffL;

  bool guard = (frac & 0x00008000L) != 0;
  bool summ  = (frac & 0x00007fffL ) != 0;
  bool inner = (frac & 0x00010000L) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x00010000L : 0x00000000L;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 16;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x00000001L : frac;

  uint16_t sfrac = (uint16_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static float p16_to_float(uint16_t pval, int16_t es, uint16_t es_mask){
  //check for infs and zeros, which do not necessarily play nice with our algorithm.
  if (pval == ((uint16_t) 0x8000)) return INFINITY;
  if (pval == ((uint16_t) 0x0000)) return (float) 0;
  //next, determine the sign of the posit value
  bool negative = ((pval & ((uint16_t) 0x8000)) != 0);
  uint16_t pos_val = negative ? -pval : pval;
  //ascertain if it's inverted.
  bool inverted = (pos_val & ((uint16_t) 0x4000)) == 0;
  //note that the clz/clo intrinsics operate on 32-bit data types.
  uint16_t u_regime;
  int16_t s_regime;
  if (inverted){
    //just count the leading zeros, which will tell you the regime.
    u_regime = __builtin_clz(pos_val)-16 - 1;
    s_regime = - u_regime;
  } else {
    //there's no "clo" intrinsic in standard c (whether or not there is a
    //machine opcode) so we have to do this very awkward transformation first.
    uint16_t z_posit = ~pos_val & ((uint16_t) 0x7fff);
    //__builtin_clz has "undefined" state for a value of 0.  W.T.F, C??
    u_regime = (z_posit == 0) ? 15 : __builtin_clz(z_posit)-16 - 1;
    s_regime = u_regime - 1;
  }
  //next create the proper exp/frac value by shifting the pos_val, based on the
  //unsigned regime value.
  uint16_t p_exp_frac = (pos_val << (u_regime + 2));

  //extract the exponent value by grabbing the top bits.
  int16_t exponent = (p_exp_frac & es_mask) >> (16 - es);

  //append the (signed) regime value to this.
  exponent |= (s_regime << es);
  //finally, add the bias value
  exponent += 127;

  //shift the fraction again to obliterate the exponent section.
  uint16_t p_frac = p_exp_frac << es;

  uint32_t result;
  result = (negative ? 0x80000000L : 0x00000000L) |
    (((uint32_t) exponent) << 23) |
    (((uint32_t) p_frac) << (7));

  //convert the result floatint to the desired float type
  return *((float *) &result);
}


/*************************************************************/
/*  posit_16 section, variable ES adapters                    */
/*************************************************************/
extern "C"   p16e0_t f_to_p16e0(float fval){
  p16e0_t res;
  res.udata = float_to_p16_zero_es(fval);
  return res;
}
  
extern "C"   float p16e0_to_f(p16e0_t pval){
  return p16_to_float(pval.udata, 0, ((uint16_t) 0x0000));
}
  

extern "C"   p16e1_t f_to_p16e1(float fval){
  p16e1_t res;
  res.udata = float_to_p16(fval, 1, 28, -30);
  return res;
}
  
extern "C"   float p16e1_to_f(p16e1_t pval){
  return p16_to_float(pval.udata, 1, ((uint16_t) 0x8000));
}
  

extern "C"   p16e2_t f_to_p16e2(float fval){
  p16e2_t res;
  res.udata = float_to_p16(fval, 2, 56, -60);
  return res;
}
  
extern "C"   float p16e2_to_f(p16e2_t pval){
  return p16_to_float(pval.udata, 2, ((uint16_t) 0xc000));
}
  

/*************************************************************/
/*  posit_32 section, general forms                           */
/*************************************************************/

static uint32_t double_to_p32(double fval, int16_t es, int16_t maximum_exponent, int16_t minimum_exponent){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return 0x80000000L;};
  if (fval == 0)   {return 0x00000000L;};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from double precision to UInt32
  uint64_t *ival = (uint64_t *) &fval;
  bool signbit = ((0x8000000000000000LL & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7ff0000000000000LL & (*ival)) >> 52) - 1023);
  //pin the exponent.
  exponent = (exponent > maximum_exponent) ? maximum_exponent : exponent;
  exponent = (exponent < minimum_exponent) ? minimum_exponent : exponent;

  //divide up this exponent into a proper exponent and regime.
  int16_t regime = exponent >> es;
  exponent = exponent & ((1 << es) - 1);
  //use an uint64_t value as an intermediary store for
  //all off the fraction bits, initially backing off by es.  Mask out the top
  //two bits.
  uint64_t frac = ((*ival) << (10 - es)) & (0x3fffffffffffffffLL >> es);
  //append the exponent bits to frac representation.
  frac |= ((uint64_t) exponent) << (62 - es);


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x8000000000000000LL;
  } else {
    shift = -regime;
    frac |= 0x4000000000000000LL;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint64_t)(((int64_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffffffffffLL;

  bool guard = (frac & 0x0000000080000000LL) != 0;
  bool summ  = (frac & 0x000000007fffffffLL ) != 0;
  bool inner = (frac & 0x0000000100000000LL) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x0000000100000000LL : 0x0000000000000000LL;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 32;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x0000000000000001LL : frac;

  uint32_t sfrac = (uint32_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static uint32_t double_to_p32_zero_es(double fval){
  //create a result value
  //infinity and NaN checks:
  if (isinf(fval)) {return 0x80000000L;};
  if (fval == 0)   {return 0x00000000L;};
  if (isnan(fval)){ throw_nan_jmp(); }
  //do a surreptitious conversion from double precision to UInt32
  uint64_t *ival = (uint64_t *) &fval;
  bool signbit = ((0x8000000000000000LL & (*ival)) != 0);
  //capture the exponent value
  int16_t exponent = (((0x7ff0000000000000LL & (*ival)) >> 52) - 1023);
  //pin the exponent.
  exponent = (exponent > 30) ? 30 : exponent;
  exponent = (exponent < -31) ? -31 : exponent;

  //use an uint64_t value as an intermediary store for
  //raw fraction bits.  Shift all the way to the right and then

  int16_t regime = exponent;
  uint64_t frac = (*ival) << (10);
  //there are no exponent bits.
  frac &= 0x3fffffffffffffffLL;


  //next, append the appropriate shift prefix in front of the value.
  int16_t shift;
  if (regime >= 0) {
    shift = 1 + regime;
    frac |= 0x8000000000000000LL;
  } else {
    shift = -regime;
    frac |= 0x4000000000000000LL;
  }

  //perform an *arithmetic* shift; convert back to unsigned.
  frac = (uint64_t)(((int64_t) frac) >> shift);

  //mask out the top bit of the fraction, which is going to be the
  //basis for the result.
  frac = frac & 0x7fffffffffffffffLL;

  bool guard = (frac & 0x0000000080000000LL) != 0;
  bool summ  = (frac & 0x000000007fffffffLL ) != 0;
  bool inner = (frac & 0x0000000100000000LL) != 0;

  //round the frac variable in the event it needs be augmented.

  frac += ((guard && inner) || (guard && summ)) ? 0x0000000100000000LL : 0x0000000000000000LL;
  //shift as necessary

  //shift further, as necessary, to match sizes
  frac = frac >> 32;

  //check to recast zeros to the smallest value
  frac = (frac == 0) ? 0x0000000000000001LL : frac;

  uint32_t sfrac = (uint32_t) frac;

  return (signbit ? -sfrac : sfrac);
}


static double p32_to_double(uint32_t pval, int16_t es, uint32_t es_mask){
  //check for infs and zeros, which do not necessarily play nice with our algorithm.
  if (pval == 0x80000000L) return INFINITY;
  if (pval == 0x00000000L) return (double) 0;
  //next, determine the sign of the posit value
  bool negative = ((pval & 0x80000000L) != 0);
  uint32_t pos_val = negative ? -pval : pval;
  //ascertain if it's inverted.
  bool inverted = (pos_val & 0x40000000L) == 0;
  //note that the clz/clo intrinsics operate on 32-bit data types.
  uint16_t u_regime;
  int16_t s_regime;
  if (inverted){
    //just count the leading zeros, which will tell you the regime.
    u_regime = __builtin_clz(pos_val) - 1;
    s_regime = - u_regime;
  } else {
    //there's no "clo" intrinsic in standard c (whether or not there is a
    //machine opcode) so we have to do this very awkward transformation first.
    uint32_t z_posit = ~pos_val & 0x7fffffffL;
    //__builtin_clz has "undefined" state for a value of 0.  W.T.F, C??
    u_regime = (z_posit == 0) ? 31 : __builtin_clz(z_posit) - 1;
    s_regime = u_regime - 1;
  }
  //next create the proper exp/frac value by shifting the pos_val, based on the
  //unsigned regime value.
  uint32_t p_exp_frac = (pos_val << (u_regime + 2));

  //extract the exponent value by grabbing the top bits.
  int16_t exponent = (p_exp_frac & es_mask) >> (32 - es);

  //append the (signed) regime value to this.
  exponent |= (s_regime << es);
  //finally, add the bias value
  exponent += 1023;

  //shift the fraction again to obliterate the exponent section.
  uint32_t p_frac = p_exp_frac << es;

  uint64_t result;
  result = (negative ? 0x8000000000000000LL : 0x0000000000000000LL) |
    (((uint64_t) exponent) << 52) |
    (((uint64_t) p_frac) << (20));

  //convert the result floatint to the desired float type
  return *((double *) &result);
}


/*************************************************************/
/*  posit_32 section, variable ES adapters                    */
/*************************************************************/
extern "C"   p32e0_t f_to_p32e0(double fval){
  p32e0_t res;
  res.udata = double_to_p32_zero_es(fval);
  return res;
}
  
extern "C"   double p32e0_to_f(p32e0_t pval){
  return p32_to_double(pval.udata, 0, 0x00000000L);
}
  

extern "C"   p32e1_t f_to_p32e1(double fval){
  p32e1_t res;
  res.udata = double_to_p32(fval, 1, 60, -62);
  return res;
}
  
extern "C"   double p32e1_to_f(p32e1_t pval){
  return p32_to_double(pval.udata, 1, 0x80000000L);
}
  

extern "C"   p32e2_t f_to_p32e2(double fval){
  p32e2_t res;
  res.udata = double_to_p32(fval, 2, 120, -124);
  return res;
}
  
extern "C"   double p32e2_to_f(p32e2_t pval){
  return p32_to_double(pval.udata, 2, 0xc0000000L);
}
  

extern "C"   p32e3_t f_to_p32e3(double fval){
  p32e3_t res;
  res.udata = double_to_p32(fval, 3, 240, -248);
  return res;
}
  
extern "C"   double p32e3_to_f(p32e3_t pval){
  return p32_to_double(pval.udata, 3, 0xe0000000L);
}
  

