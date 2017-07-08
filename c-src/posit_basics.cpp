#include "include/posit.h"
#include "include/posit_conv.h"
#include <errno.h>
#include <stdbool.h>

environment_t POSIT_ENV = {false, false};

extern "C" void set_nanmode(bool nanmode){ POSIT_ENV.nanmode = nanmode; }
extern "C" void set_underflow(bool underflows){ POSIT_ENV.underflows = underflows; }
extern "C" bool get_nanmode(){ return POSIT_ENV.nanmode; }
extern "C" bool get_underflow(){ return POSIT_ENV.underflows; }


///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_add(p8e0_t * res, const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) + p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e0_t p8e0_add_e(const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) + p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_add(p8e1_t * res, const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) + p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e1_t p8e1_add_e(const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) + p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_add(p8e2_t * res, const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) + p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e2_t p8e2_add_e(const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) + p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_add(p16e0_t * res, const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) + p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e0_t p16e0_add_e(const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) + p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_add(p16e1_t * res, const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) + p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e1_t p16e1_add_e(const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) + p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_add(p16e2_t * res, const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) + p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e2_t p16e2_add_e(const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) + p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_add(p32e0_t * res, const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) + p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e0_t p32e0_add_e(const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) + p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_add(p32e1_t * res, const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) + p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e1_t p32e1_add_e(const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) + p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_add(p32e2_t * res, const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) + p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e2_t p32e2_add_e(const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) + p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_add(p32e3_t * res, const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) + p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e3_t p32e3_add_e(const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) + p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_mul(p8e0_t * res, const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) * p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e0_t p8e0_mul_e(const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) * p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_mul(p8e1_t * res, const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) * p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e1_t p8e1_mul_e(const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) * p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_mul(p8e2_t * res, const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) * p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e2_t p8e2_mul_e(const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) * p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_mul(p16e0_t * res, const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) * p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e0_t p16e0_mul_e(const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) * p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_mul(p16e1_t * res, const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) * p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e1_t p16e1_mul_e(const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) * p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_mul(p16e2_t * res, const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) * p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e2_t p16e2_mul_e(const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) * p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_mul(p32e0_t * res, const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) * p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e0_t p32e0_mul_e(const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) * p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_mul(p32e1_t * res, const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) * p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e1_t p32e1_mul_e(const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) * p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_mul(p32e2_t * res, const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) * p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e2_t p32e2_mul_e(const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) * p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_mul(p32e3_t * res, const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) * p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e3_t p32e3_mul_e(const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) * p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_sub(p8e0_t * res, const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) - p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e0_t p8e0_sub_e(const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = p8e0_to_f(a) - p8e0_to_f(b);

  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_sub(p8e1_t * res, const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) - p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e1_t p8e1_sub_e(const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = p8e1_to_f(a) - p8e1_to_f(b);

  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_sub(p8e2_t * res, const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) - p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e2_t p8e2_sub_e(const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = p8e2_to_f(a) - p8e2_to_f(b);

  pres = f_to_p8e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_sub(p16e0_t * res, const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) - p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e0_t p16e0_sub_e(const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = p16e0_to_f(a) - p16e0_to_f(b);

  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_sub(p16e1_t * res, const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) - p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e1_t p16e1_sub_e(const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = p16e1_to_f(a) - p16e1_to_f(b);

  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_sub(p16e2_t * res, const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) - p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e2_t p16e2_sub_e(const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = p16e2_to_f(a) - p16e2_to_f(b);

  pres = f_to_p16e2(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_sub(p32e0_t * res, const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) - p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e0_t p32e0_sub_e(const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = p32e0_to_f(a) - p32e0_to_f(b);

  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_sub(p32e1_t * res, const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) - p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e1_t p32e1_sub_e(const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = p32e1_to_f(a) - p32e1_to_f(b);

  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_sub(p32e2_t * res, const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) - p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e2_t p32e2_sub_e(const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = p32e2_to_f(a) - p32e2_to_f(b);

  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_sub(p32e3_t * res, const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) - p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e3_t p32e3_sub_e(const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = p32e3_to_f(a) - p32e3_to_f(b);

  pres = f_to_p32e3(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p8e0_t p8e0_addinv_e(const p8e0_t a) {
  p8e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e0_addinv(p8e0_t * res, const p8e0_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p8e1_t p8e1_addinv_e(const p8e1_t a) {
  p8e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e1_addinv(p8e1_t * res, const p8e1_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p8e2_t p8e2_addinv_e(const p8e2_t a) {
  p8e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e2_addinv(p8e2_t * res, const p8e2_t a) {
  res->udata = -(a.udata);
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p16e0_t p16e0_addinv_e(const p16e0_t a) {
  p16e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e0_addinv(p16e0_t * res, const p16e0_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p16e1_t p16e1_addinv_e(const p16e1_t a) {
  p16e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e1_addinv(p16e1_t * res, const p16e1_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p16e2_t p16e2_addinv_e(const p16e2_t a) {
  p16e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e2_addinv(p16e2_t * res, const p16e2_t a) {
  res->udata = -(a.udata);
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p32e0_t p32e0_addinv_e(const p32e0_t a) {
  p32e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e0_addinv(p32e0_t * res, const p32e0_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p32e1_t p32e1_addinv_e(const p32e1_t a) {
  p32e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e1_addinv(p32e1_t * res, const p32e1_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p32e2_t p32e2_addinv_e(const p32e2_t a) {
  p32e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e2_addinv(p32e2_t * res, const p32e2_t a) {
  res->udata = -(a.udata);
  return 0;
}

extern "C"    p32e3_t p32e3_addinv_e(const p32e3_t a) {
  p32e3_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e3_addinv(p32e3_t * res, const p32e3_t a) {
  res->udata = -(a.udata);
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_lt(const p8e0_t a,const  p8e0_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p8e1_lt(const p8e1_t a,const  p8e1_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p8e2_lt(const p8e2_t a,const  p8e2_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_lt(const p16e0_t a,const  p16e0_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p16e1_lt(const p16e1_t a,const  p16e1_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p16e2_lt(const p16e2_t a,const  p16e2_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_lt(const p32e0_t a,const  p32e0_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e1_lt(const p32e1_t a,const  p32e1_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e2_lt(const p32e2_t a,const  p32e2_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e3_lt(const p32e3_t a,const  p32e3_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_lte(const p8e0_t a,const  p8e0_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p8e1_lte(const p8e1_t a,const  p8e1_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p8e2_lte(const p8e2_t a,const  p8e2_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_lte(const p16e0_t a,const  p16e0_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p16e1_lte(const p16e1_t a,const  p16e1_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p16e2_lte(const p16e2_t a,const  p16e2_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_lte(const p32e0_t a,const  p32e0_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e1_lte(const p32e1_t a,const  p32e1_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e2_lte(const p32e2_t a,const  p32e2_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e3_lte(const p32e3_t a,const  p32e3_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_gt(const p8e0_t a,const  p8e0_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p8e1_gt(const p8e1_t a,const  p8e1_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p8e2_gt(const p8e2_t a,const  p8e2_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_gt(const p16e0_t a,const  p16e0_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p16e1_gt(const p16e1_t a,const  p16e1_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p16e2_gt(const p16e2_t a,const  p16e2_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_gt(const p32e0_t a,const  p32e0_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e1_gt(const p32e1_t a,const  p32e1_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e2_gt(const p32e2_t a,const  p32e2_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e3_gt(const p32e3_t a,const  p32e3_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_gte(const p8e0_t a,const  p8e0_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p8e1_gte(const p8e1_t a,const  p8e1_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p8e2_gte(const p8e2_t a,const  p8e2_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_gte(const p16e0_t a,const  p16e0_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p16e1_gte(const p16e1_t a,const  p16e1_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p16e2_gte(const p16e2_t a,const  p16e2_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_gte(const p32e0_t a,const  p32e0_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e1_gte(const p32e1_t a,const  p32e1_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e2_gte(const p32e2_t a,const  p32e2_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e3_gte(const p32e3_t a,const  p32e3_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}


