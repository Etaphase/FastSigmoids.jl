#include "include/posit.h"
#include "include/posit_conv.h"
#include <errno.h>
///////////////////////////////////////////////////////////////
//  posit_8 section, add sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_add_8(uint8_t lhs, uint8_t rhs){
  if (lhs == P8INF) {
    if (rhs == P8INF) { return 3; }
    return 2;
  }
  if (rhs == P8INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_add(p8e0_t *res, p8e0_t *a, p8e0_t *b) {
  p8e0_t pres;
  int status = sanitize_add_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e0_to_f(*a) + p8e0_to_f(*b);
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_add_j(p8e0_t a, p8e0_t b) {
  p8e0_t pres;
  int status = sanitize_add_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e0_to_f(a) + p8e0_to_f(b);
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_add(p8e1_t *res, p8e1_t *a, p8e1_t *b) {
  p8e1_t pres;
  int status = sanitize_add_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e1_to_f(*a) + p8e1_to_f(*b);
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_add_j(p8e1_t a, p8e1_t b) {
  p8e1_t pres;
  int status = sanitize_add_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e1_to_f(a) + p8e1_to_f(b);
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_add(p8e2_t *res, p8e2_t *a, p8e2_t *b) {
  p8e2_t pres;
  int status = sanitize_add_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e2_to_f(*a) + p8e2_to_f(*b);
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_add_j(p8e2_t a, p8e2_t b) {
  p8e2_t pres;
  int status = sanitize_add_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e2_to_f(a) + p8e2_to_f(b);
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, add sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_add_16(uint16_t lhs, uint16_t rhs){
  if (lhs == P16INF) {
    if (rhs == P16INF) { return 3; }
    return 2;
  }
  if (rhs == P16INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_add(p16e0_t *res, p16e0_t *a, p16e0_t *b) {
  p16e0_t pres;
  int status = sanitize_add_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e0_to_f(*a) + p16e0_to_f(*b);
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_add_j(p16e0_t a, p16e0_t b) {
  p16e0_t pres;
  int status = sanitize_add_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e0_to_f(a) + p16e0_to_f(b);
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_add(p16e1_t *res, p16e1_t *a, p16e1_t *b) {
  p16e1_t pres;
  int status = sanitize_add_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e1_to_f(*a) + p16e1_to_f(*b);
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_add_j(p16e1_t a, p16e1_t b) {
  p16e1_t pres;
  int status = sanitize_add_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e1_to_f(a) + p16e1_to_f(b);
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_add(p16e2_t *res, p16e2_t *a, p16e2_t *b) {
  p16e2_t pres;
  int status = sanitize_add_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e2_to_f(*a) + p16e2_to_f(*b);
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_add_j(p16e2_t a, p16e2_t b) {
  p16e2_t pres;
  int status = sanitize_add_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e2_to_f(a) + p16e2_to_f(b);
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, add sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_add_32(uint32_t lhs, uint32_t rhs){
  if (lhs == P32INF) {
    if (rhs == P32INF) { return 3; }
    return 2;
  }
  if (rhs == P32INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for add
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_add(p32e0_t *res, p32e0_t *a, p32e0_t *b) {
  p32e0_t pres;
  int status = sanitize_add_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e0_to_f(*a) + p32e0_to_f(*b);
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_add_j(p32e0_t a, p32e0_t b) {
  p32e0_t pres;
  int status = sanitize_add_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e0_to_f(a) + p32e0_to_f(b);
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_add(p32e1_t *res, p32e1_t *a, p32e1_t *b) {
  p32e1_t pres;
  int status = sanitize_add_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e1_to_f(*a) + p32e1_to_f(*b);
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_add_j(p32e1_t a, p32e1_t b) {
  p32e1_t pres;
  int status = sanitize_add_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e1_to_f(a) + p32e1_to_f(b);
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_add(p32e2_t *res, p32e2_t *a, p32e2_t *b) {
  p32e2_t pres;
  int status = sanitize_add_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e2_to_f(*a) + p32e2_to_f(*b);
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_add_j(p32e2_t a, p32e2_t b) {
  p32e2_t pres;
  int status = sanitize_add_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e2_to_f(a) + p32e2_to_f(b);
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_add(p32e3_t *res, p32e3_t *a, p32e3_t *b) {
  p32e3_t pres;
  int status = sanitize_add_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e3_to_f(*a) + p32e3_to_f(*b);
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_add_j(p32e3_t a, p32e3_t b) {
  p32e3_t pres;
  int status = sanitize_add_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e3_to_f(a) + p32e3_to_f(b);
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, mul sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_mul_8(uint8_t lhs, uint8_t rhs){
  if (lhs == P8ZER) {
    if (rhs == P8INF) { return 3; }
    return 1;
  }
  if (rhs == P8ZER) {
    if (lhs == P8INF) { return 3; }
    return 1;
  }
  if (lhs == P8INF) { return 2; }
  if (rhs == P8INF) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_mul(p8e0_t *res, p8e0_t *a, p8e0_t *b) {
  p8e0_t pres;
  int status = sanitize_mul_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e0_to_f(*a) * p8e0_to_f(*b);
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_mul_j(p8e0_t a, p8e0_t b) {
  p8e0_t pres;
  int status = sanitize_mul_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e0_to_f(a) * p8e0_to_f(b);
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_mul(p8e1_t *res, p8e1_t *a, p8e1_t *b) {
  p8e1_t pres;
  int status = sanitize_mul_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e1_to_f(*a) * p8e1_to_f(*b);
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_mul_j(p8e1_t a, p8e1_t b) {
  p8e1_t pres;
  int status = sanitize_mul_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e1_to_f(a) * p8e1_to_f(b);
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_mul(p8e2_t *res, p8e2_t *a, p8e2_t *b) {
  p8e2_t pres;
  int status = sanitize_mul_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e2_to_f(*a) * p8e2_to_f(*b);
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_mul_j(p8e2_t a, p8e2_t b) {
  p8e2_t pres;
  int status = sanitize_mul_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e2_to_f(a) * p8e2_to_f(b);
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, mul sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_mul_16(uint16_t lhs, uint16_t rhs){
  if (lhs == P16ZER) {
    if (rhs == P16INF) { return 3; }
    return 1;
  }
  if (rhs == P16ZER) {
    if (lhs == P16INF) { return 3; }
    return 1;
  }
  if (lhs == P16INF) { return 2; }
  if (rhs == P16INF) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_mul(p16e0_t *res, p16e0_t *a, p16e0_t *b) {
  p16e0_t pres;
  int status = sanitize_mul_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e0_to_f(*a) * p16e0_to_f(*b);
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_mul_j(p16e0_t a, p16e0_t b) {
  p16e0_t pres;
  int status = sanitize_mul_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e0_to_f(a) * p16e0_to_f(b);
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_mul(p16e1_t *res, p16e1_t *a, p16e1_t *b) {
  p16e1_t pres;
  int status = sanitize_mul_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e1_to_f(*a) * p16e1_to_f(*b);
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_mul_j(p16e1_t a, p16e1_t b) {
  p16e1_t pres;
  int status = sanitize_mul_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e1_to_f(a) * p16e1_to_f(b);
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_mul(p16e2_t *res, p16e2_t *a, p16e2_t *b) {
  p16e2_t pres;
  int status = sanitize_mul_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e2_to_f(*a) * p16e2_to_f(*b);
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_mul_j(p16e2_t a, p16e2_t b) {
  p16e2_t pres;
  int status = sanitize_mul_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e2_to_f(a) * p16e2_to_f(b);
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, mul sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_mul_32(uint32_t lhs, uint32_t rhs){
  if (lhs == P32ZER) {
    if (rhs == P32INF) { return 3; }
    return 1;
  }
  if (rhs == P32ZER) {
    if (lhs == P32INF) { return 3; }
    return 1;
  }
  if (lhs == P32INF) { return 2; }
  if (rhs == P32INF) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for mul
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_mul(p32e0_t *res, p32e0_t *a, p32e0_t *b) {
  p32e0_t pres;
  int status = sanitize_mul_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e0_to_f(*a) * p32e0_to_f(*b);
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_mul_j(p32e0_t a, p32e0_t b) {
  p32e0_t pres;
  int status = sanitize_mul_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e0_to_f(a) * p32e0_to_f(b);
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_mul(p32e1_t *res, p32e1_t *a, p32e1_t *b) {
  p32e1_t pres;
  int status = sanitize_mul_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e1_to_f(*a) * p32e1_to_f(*b);
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_mul_j(p32e1_t a, p32e1_t b) {
  p32e1_t pres;
  int status = sanitize_mul_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e1_to_f(a) * p32e1_to_f(b);
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_mul(p32e2_t *res, p32e2_t *a, p32e2_t *b) {
  p32e2_t pres;
  int status = sanitize_mul_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e2_to_f(*a) * p32e2_to_f(*b);
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_mul_j(p32e2_t a, p32e2_t b) {
  p32e2_t pres;
  int status = sanitize_mul_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e2_to_f(a) * p32e2_to_f(b);
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_mul(p32e3_t *res, p32e3_t *a, p32e3_t *b) {
  p32e3_t pres;
  int status = sanitize_mul_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e3_to_f(*a) * p32e3_to_f(*b);
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_mul_j(p32e3_t a, p32e3_t b) {
  p32e3_t pres;
  int status = sanitize_mul_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e3_to_f(a) * p32e3_to_f(b);
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, sub sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sub_8(uint8_t lhs, uint8_t rhs){
  if (lhs == P8INF) {
    if (rhs == P8INF) { return 3; }
    return 2;
  }
  if (rhs == P8INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_sub(p8e0_t *res, p8e0_t *a, p8e0_t *b) {
  p8e0_t pres;
  int status = sanitize_sub_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e0_to_f(*a) - p8e0_to_f(*b);
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_sub_j(p8e0_t a, p8e0_t b) {
  p8e0_t pres;
  int status = sanitize_sub_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e0_to_f(a) - p8e0_to_f(b);
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_sub(p8e1_t *res, p8e1_t *a, p8e1_t *b) {
  p8e1_t pres;
  int status = sanitize_sub_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e1_to_f(*a) - p8e1_to_f(*b);
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_sub_j(p8e1_t a, p8e1_t b) {
  p8e1_t pres;
  int status = sanitize_sub_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e1_to_f(a) - p8e1_to_f(b);
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_sub(p8e2_t *res, p8e2_t *a, p8e2_t *b) {
  p8e2_t pres;
  int status = sanitize_sub_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e2_to_f(*a) - p8e2_to_f(*b);
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_sub_j(p8e2_t a, p8e2_t b) {
  p8e2_t pres;
  int status = sanitize_sub_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e2_to_f(a) - p8e2_to_f(b);
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, sub sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sub_16(uint16_t lhs, uint16_t rhs){
  if (lhs == P16INF) {
    if (rhs == P16INF) { return 3; }
    return 2;
  }
  if (rhs == P16INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_sub(p16e0_t *res, p16e0_t *a, p16e0_t *b) {
  p16e0_t pres;
  int status = sanitize_sub_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e0_to_f(*a) - p16e0_to_f(*b);
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_sub_j(p16e0_t a, p16e0_t b) {
  p16e0_t pres;
  int status = sanitize_sub_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e0_to_f(a) - p16e0_to_f(b);
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_sub(p16e1_t *res, p16e1_t *a, p16e1_t *b) {
  p16e1_t pres;
  int status = sanitize_sub_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e1_to_f(*a) - p16e1_to_f(*b);
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_sub_j(p16e1_t a, p16e1_t b) {
  p16e1_t pres;
  int status = sanitize_sub_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e1_to_f(a) - p16e1_to_f(b);
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_sub(p16e2_t *res, p16e2_t *a, p16e2_t *b) {
  p16e2_t pres;
  int status = sanitize_sub_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e2_to_f(*a) - p16e2_to_f(*b);
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_sub_j(p16e2_t a, p16e2_t b) {
  p16e2_t pres;
  int status = sanitize_sub_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e2_to_f(a) - p16e2_to_f(b);
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, sub sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sub_32(uint32_t lhs, uint32_t rhs){
  if (lhs == P32INF) {
    if (rhs == P32INF) { return 3; }
    return 2;
  }
  if (rhs == P32INF) { return 2; }
  if (lhs == -rhs) { return 1; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for sub
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_sub(p32e0_t *res, p32e0_t *a, p32e0_t *b) {
  p32e0_t pres;
  int status = sanitize_sub_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e0_to_f(*a) - p32e0_to_f(*b);
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_sub_j(p32e0_t a, p32e0_t b) {
  p32e0_t pres;
  int status = sanitize_sub_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e0_to_f(a) - p32e0_to_f(b);
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_sub(p32e1_t *res, p32e1_t *a, p32e1_t *b) {
  p32e1_t pres;
  int status = sanitize_sub_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e1_to_f(*a) - p32e1_to_f(*b);
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_sub_j(p32e1_t a, p32e1_t b) {
  p32e1_t pres;
  int status = sanitize_sub_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e1_to_f(a) - p32e1_to_f(b);
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_sub(p32e2_t *res, p32e2_t *a, p32e2_t *b) {
  p32e2_t pres;
  int status = sanitize_sub_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e2_to_f(*a) - p32e2_to_f(*b);
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_sub_j(p32e2_t a, p32e2_t b) {
  p32e2_t pres;
  int status = sanitize_sub_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e2_to_f(a) - p32e2_to_f(b);
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_sub(p32e3_t *res, p32e3_t *a, p32e3_t *b) {
  p32e3_t pres;
  int status = sanitize_sub_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e3_to_f(*a) - p32e3_to_f(*b);
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_sub_j(p32e3_t a, p32e3_t b) {
  p32e3_t pres;
  int status = sanitize_sub_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e3_to_f(a) - p32e3_to_f(b);
  pres = f_to_p32e3(fres);
  return pres;
}





///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p8e0_t p8e0_addinv_j(p8e0_t a) {
  p8e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e0_addinv(p8e0_t *res, p8e0_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p8e1_t p8e1_addinv_j(p8e1_t a) {
  p8e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e1_addinv(p8e1_t *res, p8e1_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p8e2_t p8e2_addinv_j(p8e2_t a) {
  p8e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p8e2_addinv(p8e2_t *res, p8e2_t *a) {
  res->udata = -(a->udata);
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p16e0_t p16e0_addinv_j(p16e0_t a) {
  p16e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e0_addinv(p16e0_t *res, p16e0_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p16e1_t p16e1_addinv_j(p16e1_t a) {
  p16e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e1_addinv(p16e1_t *res, p16e1_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p16e2_t p16e2_addinv_j(p16e2_t a) {
  p16e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p16e2_addinv(p16e2_t *res, p16e2_t *a) {
  res->udata = -(a->udata);
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for addinv
///////////////////////////////////////////////////////////////
extern "C"    p32e0_t p32e0_addinv_j(p32e0_t a) {
  p32e0_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e0_addinv(p32e0_t *res, p32e0_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p32e1_t p32e1_addinv_j(p32e1_t a) {
  p32e1_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e1_addinv(p32e1_t *res, p32e1_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p32e2_t p32e2_addinv_j(p32e2_t a) {
  p32e2_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e2_addinv(p32e2_t *res, p32e2_t *a) {
  res->udata = -(a->udata);
  return 0;
}

extern "C"    p32e3_t p32e3_addinv_j(p32e3_t a) {
  p32e3_t res;
  res.udata = -(a.udata);
  return res;
}

extern "C"    int p32e3_addinv(p32e3_t *res, p32e3_t *a) {
  res->udata = -(a->udata);
  return 0;
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_lt(p8e0_t a, p8e0_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p8e1_lt(p8e1_t a, p8e1_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p8e2_lt(p8e2_t a, p8e2_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata < b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_lt(p16e0_t a, p16e0_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p16e1_lt(p16e1_t a, p16e1_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p16e2_lt(p16e2_t a, p16e2_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata < b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for lt
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_lt(p32e0_t a, p32e0_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e1_lt(p32e1_t a, p32e1_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e2_lt(p32e2_t a, p32e2_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}

extern "C"   bool p32e3_lt(p32e3_t a, p32e3_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata < b.sdata);
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_lte(p8e0_t a, p8e0_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p8e1_lte(p8e1_t a, p8e1_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p8e2_lte(p8e2_t a, p8e2_t b) {
  if (b.udata == P8INF) { return true; }
  return (a.sdata <= b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_lte(p16e0_t a, p16e0_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p16e1_lte(p16e1_t a, p16e1_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p16e2_lte(p16e2_t a, p16e2_t b) {
  if (b.udata == P16INF) { return true; }
  return (a.sdata <= b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for lte
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_lte(p32e0_t a, p32e0_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e1_lte(p32e1_t a, p32e1_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e2_lte(p32e2_t a, p32e2_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}

extern "C"   bool p32e3_lte(p32e3_t a, p32e3_t b) {
  if (b.udata == P32INF) { return true; }
  return (a.sdata <= b.sdata);
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_gt(p8e0_t a, p8e0_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p8e1_gt(p8e1_t a, p8e1_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p8e2_gt(p8e2_t a, p8e2_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata > b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_gt(p16e0_t a, p16e0_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p16e1_gt(p16e1_t a, p16e1_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p16e2_gt(p16e2_t a, p16e2_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata > b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for gt
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_gt(p32e0_t a, p32e0_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e1_gt(p32e1_t a, p32e1_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e2_gt(p32e2_t a, p32e2_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}

extern "C"   bool p32e3_gt(p32e3_t a, p32e3_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata > b.sdata);
}




///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p8e0_gte(p8e0_t a, p8e0_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p8e1_gte(p8e1_t a, p8e1_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p8e2_gte(p8e2_t a, p8e2_t b) {
  if (a.udata == P8INF) { return true; }
  return (a.sdata >= b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p16e0_gte(p16e0_t a, p16e0_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p16e1_gte(p16e1_t a, p16e1_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p16e2_gte(p16e2_t a, p16e2_t b) {
  if (a.udata == P16INF) { return true; }
  return (a.sdata >= b.sdata);
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for gte
///////////////////////////////////////////////////////////////
extern "C"   bool p32e0_gte(p32e0_t a, p32e0_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e1_gte(p32e1_t a, p32e1_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e2_gte(p32e2_t a, p32e2_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}

extern "C"   bool p32e3_gte(p32e3_t a, p32e3_t b) {
  if (a.udata == P32INF) { return true; }
  return (a.sdata >= b.sdata);
}


