#include "posit.h"

  static bool z_count_valid_float(float a, float b, float c){
    //convert a, b, and c to their respective integers
    uint32_t a_int = *((uint32_t *) &a);
    uint32_t b_int = *((uint32_t *) &b);
    uint32_t c_int = *((uint32_t *) &c);

    int64_t trailing_a = __builtin_ctz(a_int);
    int64_t trailing_b = __builtin_ctz(b_int);
    int64_t trailing_c = __builtin_ctz(c_int);

    return trailing_c == trailing_a + trailing_b - 23;
  }

  static bool z_count_valid_double(double a, double b, double c){
    //convert a, b, and c to their respective integers
    uint64_t a_int = *((uint64_t *) &a);
    uint64_t b_int = *((uint64_t *) &b);
    uint64_t c_int = *((uint64_t *) &c);

    int64_t trailing_a = __builtin_ctzl(a_int);
    int64_t trailing_b = __builtin_ctzl(b_int);
    int64_t trailing_c = __builtin_ctzl(c_int);

    return trailing_c == trailing_a + trailing_b - 52;
  }


static uint8_t sanitize_div8(uint8_t lhs, uint8_t rhs, float fres, uint8_t pres){
  bool lhs_inf = (lhs == P8INF);
  bool rhs_inf = (rhs == P8INF);
  bool lhs_zer = (lhs == P8ZER);
  bool rhs_zer = (rhs == P8ZER);

  //throw or long jump with the global NaNJump on division of two infinities.
  if ( lhs_inf && rhs_inf ){ throw_nan_jmp(); }
  //throw or long jump with the global NaNJump on division of zero by zero.
  if ( lhs_zer && rhs_zer ){ throw_nan_jmp(); }

  //check for legitimate infinities vs. overflow.
  if (!isfinite(fres)){
    if (lhs_inf || rhs_zer) { return P8INF; }

    pres = (fres > 0) ? P8MAXREAL : P8MINREAL;
  };

  //check to see if we became zero correctly or through underflow.
  if (res == 0.0){
    if (lhs_zer || rhs_inf) { return P8ZER; }
    pres = (((lhs & P8INF) ^ (rhs & P8INF)) != 0) ? P8NEGSMALL : P8POSSMALL;
  };

  return pres;
}


extern "C" void p8e0_div(p8e0_t *res, p8e0_t *lhs, p8e0_t *rhs){

  float fres = p8e0_to_f(*lhs) / p8e0_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div8(lhs->udata, rhs->udata, fres, f_to_p8e0(fres));

}

extern "C" void p8e1_div(p8e1_t *res, p8e1_t *lhs, p8e1_t *rhs){

  float fres = p8e1_to_f(*lhs) / p8e1_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div8(lhs->udata, rhs->udata, fres, f_to_p8e1(fres));

}

extern "C" void p8e2_div(p8e2_t *res, p8e2_t *lhs, p8e2_t *rhs){

  float fres = p8e2_to_f(*lhs) / p8e2_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div8(lhs->udata, rhs->udata, fres, f_to_p8e2(fres));

}

static uint16_t sanitize_div16(uint16_t lhs, uint16_t rhs, float fres, uint16_t pres){
  bool lhs_inf = (lhs == P16INF);
  bool rhs_inf = (rhs == P16INF);
  bool lhs_zer = (lhs == P16ZER);
  bool rhs_zer = (rhs == P16ZER);

  //throw or long jump with the global NaNJump on division of two infinities.
  if ( lhs_inf && rhs_inf ){ throw_nan_jmp(); }
  //throw or long jump with the global NaNJump on division of zero by zero.
  if ( lhs_zer && rhs_zer ){ throw_nan_jmp(); }

  //check for legitimate infinities vs. overflow.
  if (!isfinite(fres)){
    if (lhs_inf || rhs_zer) { return P16INF; }

    pres = (fres > 0) ? P16MAXREAL : P16MINREAL;
  };

  //check to see if we became zero correctly or through underflow.
  if (res == 0.0){
    if (lhs_zer || rhs_inf) { return P16ZER; }
    pres = (((lhs & P16INF) ^ (rhs & P16INF)) != 0) ? P16NEGSMALL : P16POSSMALL;
  };

  return pres;
}


extern "C" void p16e0_div(p16e0_t *res, p16e0_t *lhs, p16e0_t *rhs){

  float fres = p16e0_to_f(*lhs) / p16e0_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div16(lhs->udata, rhs->udata, fres, f_to_p16e0(fres));

}

extern "C" void p16e1_div(p16e1_t *res, p16e1_t *lhs, p16e1_t *rhs){

  float fres = p16e1_to_f(*lhs) / p16e1_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div16(lhs->udata, rhs->udata, fres, f_to_p16e1(fres));

}

extern "C" void p16e2_div(p16e2_t *res, p16e2_t *lhs, p16e2_t *rhs){

  float fres = p16e2_to_f(*lhs) / p16e2_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div16(lhs->udata, rhs->udata, fres, f_to_p16e2(fres));

}

static uint32_t sanitize_div32(uint32_t lhs, uint32_t rhs, double fres, uint32_t pres){
  bool lhs_inf = (lhs == P32INF);
  bool rhs_inf = (rhs == P32INF);
  bool lhs_zer = (lhs == P32ZER);
  bool rhs_zer = (rhs == P32ZER);

  //throw or long jump with the global NaNJump on division of two infinities.
  if ( lhs_inf && rhs_inf ){ throw_nan_jmp(); }
  //throw or long jump with the global NaNJump on division of zero by zero.
  if ( lhs_zer && rhs_zer ){ throw_nan_jmp(); }

  //check for legitimate infinities vs. overflow.
  if (!isfinite(fres)){
    if (lhs_inf || rhs_zer) { return P32INF; }

    pres = (fres > 0) ? P32MAXREAL : P32MINREAL;
  };

  //check to see if we became zero correctly or through underflow.
  if (res == 0.0){
    if (lhs_zer || rhs_inf) { return P32ZER; }
    pres = (((lhs & P32INF) ^ (rhs & P32INF)) != 0) ? P32NEGSMALL : P32POSSMALL;
  };

  return pres;
}


extern "C" void p32e0_div(p32e0_t *res, p32e0_t *lhs, p32e0_t *rhs){

  double fres = p32e0_to_f(*lhs) / p32e0_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div32(lhs->udata, rhs->udata, fres, f_to_p32e0(fres));

}

extern "C" void p32e1_div(p32e1_t *res, p32e1_t *lhs, p32e1_t *rhs){

  double fres = p32e1_to_f(*lhs) / p32e1_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div32(lhs->udata, rhs->udata, fres, f_to_p32e1(fres));

}

extern "C" void p32e2_div(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs){

  double fres = p32e2_to_f(*lhs) / p32e2_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div32(lhs->udata, rhs->udata, fres, f_to_p32e2(fres));

}

extern "C" void p32e3_div(p32e3_t *res, p32e3_t *lhs, p32e3_t *rhs){

  double fres = p32e3_to_f(*lhs) / p32e3_to_f(*rhs);

  //sanitize the resulting data and store as an update to res.

  res->udata = sanitize_div32(lhs->udata, rhs->udata, fres, f_to_p32e3(fres));

}




extern "C" p8e0_t p8e0_mulinv(p8e0_t x){
  p8e0_t res;

  if (x.udata == P8INF) { res.udata = P8ZER; return res; }
  if (x.udata == P8ZER) { res.udata = P8INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p8e0(1 / p8e0_to_f(x));
}

extern "C" p8e1_t p8e1_mulinv(p8e1_t x){
  p8e1_t res;

  if (x.udata == P8INF) { res.udata = P8ZER; return res; }
  if (x.udata == P8ZER) { res.udata = P8INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p8e1(1 / p8e1_to_f(x));
}

extern "C" p8e2_t p8e2_mulinv(p8e2_t x){
  p8e2_t res;

  if (x.udata == P8INF) { res.udata = P8ZER; return res; }
  if (x.udata == P8ZER) { res.udata = P8INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p8e2(1 / p8e2_to_f(x));
}



extern "C" p16e0_t p16e0_mulinv(p16e0_t x){
  p16e0_t res;

  if (x.udata == P16INF) { res.udata = P16ZER; return res; }
  if (x.udata == P16ZER) { res.udata = P16INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p16e0(1 / p16e0_to_f(x));
}

extern "C" p16e1_t p16e1_mulinv(p16e1_t x){
  p16e1_t res;

  if (x.udata == P16INF) { res.udata = P16ZER; return res; }
  if (x.udata == P16ZER) { res.udata = P16INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p16e1(1 / p16e1_to_f(x));
}

extern "C" p16e2_t p16e2_mulinv(p16e2_t x){
  p16e2_t res;

  if (x.udata == P16INF) { res.udata = P16ZER; return res; }
  if (x.udata == P16ZER) { res.udata = P16INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p16e2(1 / p16e2_to_f(x));
}



extern "C" p32e0_t p32e0_mulinv(p32e0_t x){
  p32e0_t res;

  if (x.udata == P32INF) { res.udata = P32ZER; return res; }
  if (x.udata == P32ZER) { res.udata = P32INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p32e0(1 / p32e0_to_f(x));
}

extern "C" p32e1_t p32e1_mulinv(p32e1_t x){
  p32e1_t res;

  if (x.udata == P32INF) { res.udata = P32ZER; return res; }
  if (x.udata == P32ZER) { res.udata = P32INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p32e1(1 / p32e1_to_f(x));
}

extern "C" p32e2_t p32e2_mulinv(p32e2_t x){
  p32e2_t res;

  if (x.udata == P32INF) { res.udata = P32ZER; return res; }
  if (x.udata == P32ZER) { res.udata = P32INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p32e2(1 / p32e2_to_f(x));
}

extern "C" p32e3_t p32e3_mulinv(p32e3_t x){
  p32e3_t res;

  if (x.udata == P32INF) { res.udata = P32ZER; return res; }
  if (x.udata == P32ZER) { res.udata = P32INF; return res; }

  //by nature of encapsulation we don't have to worry about overflow or underflow.

  return f_to_p32e3(1 / p32e3_to_f(x));
}




extern "C" p8e0_t p8e0_log2(p8e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e0(log2(p8e0_to_f(x)));
}

extern "C" p8e1_t p8e1_log2(p8e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e1(log2(p8e1_to_f(x)));
}

extern "C" p8e2_t p8e2_log2(p8e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p8e2(log2(p8e2_to_f(x)));
}



extern "C" p16e0_t p16e0_log2(p16e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e0(log2(p16e0_to_f(x)));
}

extern "C" p16e1_t p16e1_log2(p16e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e1(log2(p16e1_to_f(x)));
}

extern "C" p16e2_t p16e2_log2(p16e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p16e2(log2(p16e2_to_f(x)));
}



extern "C" p32e0_t p32e0_log2(p32e0_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e0(log2(p32e0_to_f(x)));
}

extern "C" p32e1_t p32e1_log2(p32e1_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e1(log2(p32e1_to_f(x)));
}

extern "C" p32e2_t p32e2_log2(p32e2_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e2(log2(p32e2_to_f(x)));
}

extern "C" p32e3_t p32e3_log2(p32e3_t x){
  if ( x.sdata < 0 ){ throw_nan_jmp(); }

  return f_to_p32e3(log2(p32e3_to_f(x)));
}




extern "C" p8e0_t p8e0_exp2(p8e0_t x){
  p8e0_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P8INF ) { throw_nan_jmp(); }

  float fres = exp2(p8e0_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P8MAXREAL; return;}
  if (fres == 0)  {res.udata = P8POSSMALL; return;}

  return f_to_p8e0(res);
}

extern "C" p8e1_t p8e1_exp2(p8e1_t x){
  p8e1_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P8INF ) { throw_nan_jmp(); }

  float fres = exp2(p8e1_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P8MAXREAL; return;}
  if (fres == 0)  {res.udata = P8POSSMALL; return;}

  return f_to_p8e1(res);
}

extern "C" p8e2_t p8e2_exp2(p8e2_t x){
  p8e2_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P8INF ) { throw_nan_jmp(); }

  float fres = exp2(p8e2_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P8MAXREAL; return;}
  if (fres == 0)  {res.udata = P8POSSMALL; return;}

  return f_to_p8e2(res);
}



extern "C" p16e0_t p16e0_exp2(p16e0_t x){
  p16e0_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P16INF ) { throw_nan_jmp(); }

  float fres = exp2(p16e0_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P16MAXREAL; return;}
  if (fres == 0)  {res.udata = P16POSSMALL; return;}

  return f_to_p16e0(res);
}

extern "C" p16e1_t p16e1_exp2(p16e1_t x){
  p16e1_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P16INF ) { throw_nan_jmp(); }

  float fres = exp2(p16e1_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P16MAXREAL; return;}
  if (fres == 0)  {res.udata = P16POSSMALL; return;}

  return f_to_p16e1(res);
}

extern "C" p16e2_t p16e2_exp2(p16e2_t x){
  p16e2_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P16INF ) { throw_nan_jmp(); }

  float fres = exp2(p16e2_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P16MAXREAL; return;}
  if (fres == 0)  {res.udata = P16POSSMALL; return;}

  return f_to_p16e2(res);
}



extern "C" p32e0_t p32e0_exp2(p32e0_t x){
  p32e0_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P32INF ) { throw_nan_jmp(); }

  double fres = exp2(p32e0_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P32MAXREAL; return;}
  if (fres == 0)  {res.udata = P32POSSMALL; return;}

  return f_to_p32e0(res);
}

extern "C" p32e1_t p32e1_exp2(p32e1_t x){
  p32e1_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P32INF ) { throw_nan_jmp(); }

  double fres = exp2(p32e1_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P32MAXREAL; return;}
  if (fres == 0)  {res.udata = P32POSSMALL; return;}

  return f_to_p32e1(res);
}

extern "C" p32e2_t p32e2_exp2(p32e2_t x){
  p32e2_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P32INF ) { throw_nan_jmp(); }

  double fres = exp2(p32e2_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P32MAXREAL; return;}
  if (fres == 0)  {res.udata = P32POSSMALL; return;}

  return f_to_p32e2(res);
}

extern "C" p32e3_t p32e3_exp2(p32e3_t x){
  p32e3_t res;
  //check to see if the result will be infinite, which causes NaN (not sure if zero or infinity).
  if ( x.udata == P32INF ) { throw_nan_jmp(); }

  double fres = exp2(p32e3_to_f(x);

  //clear on infinite and zero values.

  if (isinf(fres)){res.udata = P32MAXREAL; return;}
  if (fres == 0)  {res.udata = P32POSSMALL; return;}

  return f_to_p32e3(res);
}


static uint8_t sanitize_fma8(uint8_t a, uint8_t b, uint8_t c, float fres, uint8_t pres, bool z_valid){

  //check the muliplicands for infinities and zero values.
  bool a_inf = (a == P8INF);
  bool a_zer = (a == P8ZER);
  bool b_inf = (b == P8INF);
  bool b_zer = (b == P8ZER);
  bool c_inf = (c == P8INF);

  bool nan_from_mult = (a_inf && b_zer) || (a_zer && b_inf);
  bool mulinf = a_inf || b_inf;  //to check for sum of two infs.

  if (nan_from_mult || (mulinf && c_inf)) { throw_nan_jmp(); }

  //check to see if we throw a legitimate infinity.
  if (mulinf || c_inf) { return P8INF; }

  //luckily for us, IEEE floating point infinities keep their sign.
  if (isinf(fres)) {return (fres > 0) ? P8MAXREAL : P8MINREAL;}

  //true zeroes take a bit of work.
  if (fres == 0.0) {
    if (c == P8ZER){ //if the addend is zero, make sure at least one of the multipliers is zero.
      if (a_inf || b_inf) { return P8ZER; }
    } else {
      //to decide if we reached exactly zero, convert a, b & c to floats and
      //count trailing zeros, which we did earlier in the "z_count_valid" function
      if (zvalid) { return P8ZER; }
    }
    uint32_t zero_check = *((uint32_t *) &fres)
    return (zero_check == 0) ? P8POSSMALL : P8NEGSMALL
  }

  return pres;
}


extern "C" void p8e0_fma(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c){

  float fres = fma( p8e0_to_f(a),  p8e0_to_f(b),  p8e0_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e0_to_f(a),  p8e0_to_f(b),  p8e0_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e0(fres), z_count_valid);
}

extern "C" void p8e1_fma(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c){

  float fres = fma( p8e1_to_f(a),  p8e1_to_f(b),  p8e1_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e1_to_f(a),  p8e1_to_f(b),  p8e1_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e1(fres), z_count_valid);
}

extern "C" void p8e2_fma(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c){

  float fres = fma( p8e2_to_f(a),  p8e2_to_f(b),  p8e2_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e2_to_f(a),  p8e2_to_f(b),  p8e2_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e2(fres), z_count_valid);
}

static uint16_t sanitize_fma16(uint16_t a, uint16_t b, uint16_t c, float fres, uint16_t pres, bool z_valid){

  //check the muliplicands for infinities and zero values.
  bool a_inf = (a == P16INF);
  bool a_zer = (a == P16ZER);
  bool b_inf = (b == P16INF);
  bool b_zer = (b == P16ZER);
  bool c_inf = (c == P16INF);

  bool nan_from_mult = (a_inf && b_zer) || (a_zer && b_inf);
  bool mulinf = a_inf || b_inf;  //to check for sum of two infs.

  if (nan_from_mult || (mulinf && c_inf)) { throw_nan_jmp(); }

  //check to see if we throw a legitimate infinity.
  if (mulinf || c_inf) { return P16INF; }

  //luckily for us, IEEE floating point infinities keep their sign.
  if (isinf(fres)) {return (fres > 0) ? P16MAXREAL : P16MINREAL;}

  //true zeroes take a bit of work.
  if (fres == 0.0) {
    if (c == P16ZER){ //if the addend is zero, make sure at least one of the multipliers is zero.
      if (a_inf || b_inf) { return P16ZER; }
    } else {
      //to decide if we reached exactly zero, convert a, b & c to floats and
      //count trailing zeros, which we did earlier in the "z_count_valid" function
      if (zvalid) { return P16ZER; }
    }
    uint32_t zero_check = *((uint32_t *) &fres)
    return (zero_check == 0) ? P16POSSMALL : P16NEGSMALL
  }

  return pres;
}


extern "C" void p16e0_fma(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c){

  float fres = fma( p16e0_to_f(a),  p16e0_to_f(b),  p16e0_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e0_to_f(a),  p16e0_to_f(b),  p16e0_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e0(fres), z_count_valid);
}

extern "C" void p16e1_fma(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c){

  float fres = fma( p16e1_to_f(a),  p16e1_to_f(b),  p16e1_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e1_to_f(a),  p16e1_to_f(b),  p16e1_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e1(fres), z_count_valid);
}

extern "C" void p16e2_fma(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c){

  float fres = fma( p16e2_to_f(a),  p16e2_to_f(b),  p16e2_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e2_to_f(a),  p16e2_to_f(b),  p16e2_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e2(fres), z_count_valid);
}

static uint32_t sanitize_fma32(uint32_t a, uint32_t b, uint32_t c, double fres, uint32_t pres, bool z_valid){

  //check the muliplicands for infinities and zero values.
  bool a_inf = (a == P32INF);
  bool a_zer = (a == P32ZER);
  bool b_inf = (b == P32INF);
  bool b_zer = (b == P32ZER);
  bool c_inf = (c == P32INF);

  bool nan_from_mult = (a_inf && b_zer) || (a_zer && b_inf);
  bool mulinf = a_inf || b_inf;  //to check for sum of two infs.

  if (nan_from_mult || (mulinf && c_inf)) { throw_nan_jmp(); }

  //check to see if we throw a legitimate infinity.
  if (mulinf || c_inf) { return P32INF; }

  //luckily for us, IEEE floating point infinities keep their sign.
  if (isinf(fres)) {return (fres > 0) ? P32MAXREAL : P32MINREAL;}

  //true zeroes take a bit of work.
  if (fres == 0.0) {
    if (c == P32ZER){ //if the addend is zero, make sure at least one of the multipliers is zero.
      if (a_inf || b_inf) { return P32ZER; }
    } else {
      //to decide if we reached exactly zero, convert a, b & c to floats and
      //count trailing zeros, which we did earlier in the "z_count_valid" function
      if (zvalid) { return P32ZER; }
    }
    uint64_t zero_check = *((uint64_t *) &fres)
    return (zero_check == 0) ? P32POSSMALL : P32NEGSMALL
  }

  return pres;
}


extern "C" void p32e0_fma(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c){

  double fres = fma( p32e0_to_f(a),  p32e0_to_f(b),  p32e0_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e0_to_f(a),  p32e0_to_f(b),  p32e0_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e0(fres), z_count_valid);
}

extern "C" void p32e1_fma(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c){

  double fres = fma( p32e1_to_f(a),  p32e1_to_f(b),  p32e1_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e1_to_f(a),  p32e1_to_f(b),  p32e1_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e1(fres), z_count_valid);
}

extern "C" void p32e2_fma(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c){

  double fres = fma( p32e2_to_f(a),  p32e2_to_f(b),  p32e2_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e2_to_f(a),  p32e2_to_f(b),  p32e2_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e2(fres), z_count_valid);
}

extern "C" void p32e3_fma(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c){

  double fres = fma( p32e3_to_f(a),  p32e3_to_f(b),  p32e3_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e3_to_f(a),  p32e3_to_f(b),  p32e3_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e3(fres), z_count_valid);
}




extern "C" void p8e0_fms(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c){

  float fres = fma( p8e0_to_f(a),  p8e0_to_f(b), -p8e0_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e0_to_f(a),  p8e0_to_f(b), -p8e0_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e0(fres), z_count_valid);
}

extern "C" void p8e1_fms(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c){

  float fres = fma( p8e1_to_f(a),  p8e1_to_f(b), -p8e1_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e1_to_f(a),  p8e1_to_f(b), -p8e1_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e1(fres), z_count_valid);
}

extern "C" void p8e2_fms(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c){

  float fres = fma( p8e2_to_f(a),  p8e2_to_f(b), -p8e2_to_f(c))

  bool z_count_valid = z_count_valid_float( p8e2_to_f(a),  p8e2_to_f(b), -p8e2_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e2(fres), z_count_valid);
}



extern "C" void p16e0_fms(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c){

  float fres = fma( p16e0_to_f(a),  p16e0_to_f(b), -p16e0_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e0_to_f(a),  p16e0_to_f(b), -p16e0_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e0(fres), z_count_valid);
}

extern "C" void p16e1_fms(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c){

  float fres = fma( p16e1_to_f(a),  p16e1_to_f(b), -p16e1_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e1_to_f(a),  p16e1_to_f(b), -p16e1_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e1(fres), z_count_valid);
}

extern "C" void p16e2_fms(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c){

  float fres = fma( p16e2_to_f(a),  p16e2_to_f(b), -p16e2_to_f(c))

  bool z_count_valid = z_count_valid_float( p16e2_to_f(a),  p16e2_to_f(b), -p16e2_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e2(fres), z_count_valid);
}



extern "C" void p32e0_fms(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c){

  double fres = fma( p32e0_to_f(a),  p32e0_to_f(b), -p32e0_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e0_to_f(a),  p32e0_to_f(b), -p32e0_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e0(fres), z_count_valid);
}

extern "C" void p32e1_fms(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c){

  double fres = fma( p32e1_to_f(a),  p32e1_to_f(b), -p32e1_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e1_to_f(a),  p32e1_to_f(b), -p32e1_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e1(fres), z_count_valid);
}

extern "C" void p32e2_fms(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c){

  double fres = fma( p32e2_to_f(a),  p32e2_to_f(b), -p32e2_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e2_to_f(a),  p32e2_to_f(b), -p32e2_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e2(fres), z_count_valid);
}

extern "C" void p32e3_fms(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c){

  double fres = fma( p32e3_to_f(a),  p32e3_to_f(b), -p32e3_to_f(c))

  bool z_count_valid = z_count_valid_double( p32e3_to_f(a),  p32e3_to_f(b), -p32e3_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e3(fres), z_count_valid);
}




extern "C" void p8e0_nfma(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c){

  float fres = fma(-p8e0_to_f(a), -p8e0_to_f(b), -p8e0_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e0_to_f(a), -p8e0_to_f(b), -p8e0_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e0(fres), z_count_valid);
}

extern "C" void p8e1_nfma(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c){

  float fres = fma(-p8e1_to_f(a), -p8e1_to_f(b), -p8e1_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e1_to_f(a), -p8e1_to_f(b), -p8e1_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e1(fres), z_count_valid);
}

extern "C" void p8e2_nfma(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c){

  float fres = fma(-p8e2_to_f(a), -p8e2_to_f(b), -p8e2_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e2_to_f(a), -p8e2_to_f(b), -p8e2_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e2(fres), z_count_valid);
}



extern "C" void p16e0_nfma(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c){

  float fres = fma(-p16e0_to_f(a), -p16e0_to_f(b), -p16e0_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e0_to_f(a), -p16e0_to_f(b), -p16e0_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e0(fres), z_count_valid);
}

extern "C" void p16e1_nfma(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c){

  float fres = fma(-p16e1_to_f(a), -p16e1_to_f(b), -p16e1_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e1_to_f(a), -p16e1_to_f(b), -p16e1_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e1(fres), z_count_valid);
}

extern "C" void p16e2_nfma(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c){

  float fres = fma(-p16e2_to_f(a), -p16e2_to_f(b), -p16e2_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e2_to_f(a), -p16e2_to_f(b), -p16e2_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e2(fres), z_count_valid);
}



extern "C" void p32e0_nfma(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c){

  double fres = fma(-p32e0_to_f(a), -p32e0_to_f(b), -p32e0_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e0_to_f(a), -p32e0_to_f(b), -p32e0_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e0(fres), z_count_valid);
}

extern "C" void p32e1_nfma(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c){

  double fres = fma(-p32e1_to_f(a), -p32e1_to_f(b), -p32e1_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e1_to_f(a), -p32e1_to_f(b), -p32e1_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e1(fres), z_count_valid);
}

extern "C" void p32e2_nfma(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c){

  double fres = fma(-p32e2_to_f(a), -p32e2_to_f(b), -p32e2_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e2_to_f(a), -p32e2_to_f(b), -p32e2_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e2(fres), z_count_valid);
}

extern "C" void p32e3_nfma(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c){

  double fres = fma(-p32e3_to_f(a), -p32e3_to_f(b), -p32e3_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e3_to_f(a), -p32e3_to_f(b), -p32e3_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e3(fres), z_count_valid);
}




extern "C" void p8e0_nfms(p8e0_t *res, p8e0_t *a,   p8e0_t *b,   p8e0_t *c){

  float fres = fma(-p8e0_to_f(a), -p8e0_to_f(b),  p8e0_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e0_to_f(a), -p8e0_to_f(b),  p8e0_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e0(fres), z_count_valid);
}

extern "C" void p8e1_nfms(p8e1_t *res, p8e1_t *a,   p8e1_t *b,   p8e1_t *c){

  float fres = fma(-p8e1_to_f(a), -p8e1_to_f(b),  p8e1_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e1_to_f(a), -p8e1_to_f(b),  p8e1_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e1(fres), z_count_valid);
}

extern "C" void p8e2_nfms(p8e2_t *res, p8e2_t *a,   p8e2_t *b,   p8e2_t *c){

  float fres = fma(-p8e2_to_f(a), -p8e2_to_f(b),  p8e2_to_f(c))

  bool z_count_valid = z_count_valid_float(-p8e2_to_f(a), -p8e2_to_f(b),  p8e2_to_f(c))

  res->udata = sanitize_fma8(a->udata, b->udata, c->udata, fres, f_to_p8e2(fres), z_count_valid);
}



extern "C" void p16e0_nfms(p16e0_t *res, p16e0_t *a,   p16e0_t *b,   p16e0_t *c){

  float fres = fma(-p16e0_to_f(a), -p16e0_to_f(b),  p16e0_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e0_to_f(a), -p16e0_to_f(b),  p16e0_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e0(fres), z_count_valid);
}

extern "C" void p16e1_nfms(p16e1_t *res, p16e1_t *a,   p16e1_t *b,   p16e1_t *c){

  float fres = fma(-p16e1_to_f(a), -p16e1_to_f(b),  p16e1_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e1_to_f(a), -p16e1_to_f(b),  p16e1_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e1(fres), z_count_valid);
}

extern "C" void p16e2_nfms(p16e2_t *res, p16e2_t *a,   p16e2_t *b,   p16e2_t *c){

  float fres = fma(-p16e2_to_f(a), -p16e2_to_f(b),  p16e2_to_f(c))

  bool z_count_valid = z_count_valid_float(-p16e2_to_f(a), -p16e2_to_f(b),  p16e2_to_f(c))

  res->udata = sanitize_fma16(a->udata, b->udata, c->udata, fres, f_to_p16e2(fres), z_count_valid);
}



extern "C" void p32e0_nfms(p32e0_t *res, p32e0_t *a,   p32e0_t *b,   p32e0_t *c){

  double fres = fma(-p32e0_to_f(a), -p32e0_to_f(b),  p32e0_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e0_to_f(a), -p32e0_to_f(b),  p32e0_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e0(fres), z_count_valid);
}

extern "C" void p32e1_nfms(p32e1_t *res, p32e1_t *a,   p32e1_t *b,   p32e1_t *c){

  double fres = fma(-p32e1_to_f(a), -p32e1_to_f(b),  p32e1_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e1_to_f(a), -p32e1_to_f(b),  p32e1_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e1(fres), z_count_valid);
}

extern "C" void p32e2_nfms(p32e2_t *res, p32e2_t *a,   p32e2_t *b,   p32e2_t *c){

  double fres = fma(-p32e2_to_f(a), -p32e2_to_f(b),  p32e2_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e2_to_f(a), -p32e2_to_f(b),  p32e2_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e2(fres), z_count_valid);
}

extern "C" void p32e3_nfms(p32e3_t *res, p32e3_t *a,   p32e3_t *b,   p32e3_t *c){

  double fres = fma(-p32e3_to_f(a), -p32e3_to_f(b),  p32e3_to_f(c))

  bool z_count_valid = z_count_valid_double(-p32e3_to_f(a), -p32e3_to_f(b),  p32e3_to_f(c))

  res->udata = sanitize_fma32(a->udata, b->udata, c->udata, fres, f_to_p32e3(fres), z_count_valid);
}




extern "C" p8e0_t p8e0_fas(p8e0_t a, p8e0_t b, p8e0_t c){
  throw_nan_jmp();
}

extern "C" p8e1_t p8e1_fas(p8e1_t a, p8e1_t b, p8e1_t c){
  throw_nan_jmp();
}

extern "C" p8e2_t p8e2_fas(p8e2_t a, p8e2_t b, p8e2_t c){
  throw_nan_jmp();
}



extern "C" p16e0_t p16e0_fas(p16e0_t a, p16e0_t b, p16e0_t c){
  throw_nan_jmp();
}

extern "C" p16e1_t p16e1_fas(p16e1_t a, p16e1_t b, p16e1_t c){
  throw_nan_jmp();
}

extern "C" p16e2_t p16e2_fas(p16e2_t a, p16e2_t b, p16e2_t c){
  throw_nan_jmp();
}



extern "C" p32e0_t p32e0_fas(p32e0_t a, p32e0_t b, p32e0_t c){
  throw_nan_jmp();
}

extern "C" p32e1_t p32e1_fas(p32e1_t a, p32e1_t b, p32e1_t c){
  throw_nan_jmp();
}

extern "C" p32e2_t p32e2_fas(p32e2_t a, p32e2_t b, p32e2_t c){
  throw_nan_jmp();
}

extern "C" p32e3_t p32e3_fas(p32e3_t a, p32e3_t b, p32e3_t c){
  throw_nan_jmp();
}




extern "C" p8e0_t p8e0_fcp(p8e0_t a, p8e0_t b, p8e0_t c, p8e0_t b){
  throw_nan_jmp();
}

extern "C" p8e1_t p8e1_fcp(p8e1_t a, p8e1_t b, p8e1_t c, p8e1_t b){
  throw_nan_jmp();
}

extern "C" p8e2_t p8e2_fcp(p8e2_t a, p8e2_t b, p8e2_t c, p8e2_t b){
  throw_nan_jmp();
}



extern "C" p16e0_t p16e0_fcp(p16e0_t a, p16e0_t b, p16e0_t c, p16e0_t b){
  throw_nan_jmp();
}

extern "C" p16e1_t p16e1_fcp(p16e1_t a, p16e1_t b, p16e1_t c, p16e1_t b){
  throw_nan_jmp();
}

extern "C" p16e2_t p16e2_fcp(p16e2_t a, p16e2_t b, p16e2_t c, p16e2_t b){
  throw_nan_jmp();
}



extern "C" p32e0_t p32e0_fcp(p32e0_t a, p32e0_t b, p32e0_t c, p32e0_t b){
  throw_nan_jmp();
}

extern "C" p32e1_t p32e1_fcp(p32e1_t a, p32e1_t b, p32e1_t c, p32e1_t b){
  throw_nan_jmp();
}

extern "C" p32e2_t p32e2_fcp(p32e2_t a, p32e2_t b, p32e2_t c, p32e2_t b){
  throw_nan_jmp();
}

extern "C" p32e3_t p32e3_fcp(p32e3_t a, p32e3_t b, p32e3_t c, p32e3_t b){
  throw_nan_jmp();
}




extern "C" p8e0_t p8e0_fdp(fdp_cache8e0_t *fc, p8e0_t a, p8e0_t b){
  throw_nan_jmp();
}

extern "C" p8e1_t p8e1_fdp(fdp_cache8e1_t *fc, p8e1_t a, p8e1_t b){
  throw_nan_jmp();
}

extern "C" p8e2_t p8e2_fdp(fdp_cache8e2_t *fc, p8e2_t a, p8e2_t b){
  throw_nan_jmp();
}



extern "C" p16e0_t p16e0_fdp(fdp_cache16e0_t *fc, p16e0_t a, p16e0_t b){
  throw_nan_jmp();
}

extern "C" p16e1_t p16e1_fdp(fdp_cache16e1_t *fc, p16e1_t a, p16e1_t b){
  throw_nan_jmp();
}

extern "C" p16e2_t p16e2_fdp(fdp_cache16e2_t *fc, p16e2_t a, p16e2_t b){
  throw_nan_jmp();
}



extern "C" p32e0_t p32e0_fdp(fdp_cache32e0_t *fc, p32e0_t a, p32e0_t b){
  throw_nan_jmp();
}

extern "C" p32e1_t p32e1_fdp(fdp_cache32e1_t *fc, p32e1_t a, p32e1_t b){
  throw_nan_jmp();
}

extern "C" p32e2_t p32e2_fdp(fdp_cache32e2_t *fc, p32e2_t a, p32e2_t b){
  throw_nan_jmp();
}

extern "C" p32e3_t p32e3_fdp(fdp_cache32e3_t *fc, p32e3_t a, p32e3_t b){
  throw_nan_jmp();
}




extern "C" void p8e0_dpi(fdp_cache8e0_t *fc){
  throw_nan_jmp();
}

extern "C" void p8e1_dpi(fdp_cache8e1_t *fc){
  throw_nan_jmp();
}

extern "C" void p8e2_dpi(fdp_cache8e2_t *fc){
  throw_nan_jmp();
}



extern "C" void p16e0_dpi(fdp_cache16e0_t *fc){
  throw_nan_jmp();
}

extern "C" void p16e1_dpi(fdp_cache16e1_t *fc){
  throw_nan_jmp();
}

extern "C" void p16e2_dpi(fdp_cache16e2_t *fc){
  throw_nan_jmp();
}



extern "C" void p32e0_dpi(fdp_cache32e0_t *fc){
  throw_nan_jmp();
}

extern "C" void p32e1_dpi(fdp_cache32e1_t *fc){
  throw_nan_jmp();
}

extern "C" void p32e2_dpi(fdp_cache32e2_t *fc){
  throw_nan_jmp();
}

extern "C" void p32e3_dpi(fdp_cache32e3_t *fc){
  throw_nan_jmp();
}


