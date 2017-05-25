#include "include/posit.h"
#include "include/posit_conv.h"
#include <errno.h>


///////////////////////////////////////////////////////////////
//  posit_8 section, div sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_div_8(uint8_t lhs, uint8_t rhs){
  if (lhs == P8INF) {
    if (rhs == P8INF) { return 3; }
    return 2;
  }
  if (lhs == P8ZER) {
    if (rhs == P8ZER) { return 3; }
    return 1;
  }
  if (rhs == P8INF) { return 1; }
  if (rhs == P8ZER) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for div
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_div(p8e0_t *res, p8e0_t *a, p8e0_t *b) {
  p8e0_t pres;
  int status = sanitize_div_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e0_to_f(*a) / p8e0_to_f(*b);
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_div_j(p8e0_t a, p8e0_t b) {
  p8e0_t pres;
  int status = sanitize_div_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e0_to_f(a) / p8e0_to_f(b);
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_div(p8e1_t *res, p8e1_t *a, p8e1_t *b) {
  p8e1_t pres;
  int status = sanitize_div_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e1_to_f(*a) / p8e1_to_f(*b);
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_div_j(p8e1_t a, p8e1_t b) {
  p8e1_t pres;
  int status = sanitize_div_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e1_to_f(a) / p8e1_to_f(b);
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_div(p8e2_t *res, p8e2_t *a, p8e2_t *b) {
  p8e2_t pres;
  int status = sanitize_div_8((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p8e2_to_f(*a) / p8e2_to_f(*b);
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_div_j(p8e2_t a, p8e2_t b) {
  p8e2_t pres;
  int status = sanitize_div_8((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p8e2_to_f(a) / p8e2_to_f(b);
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, div sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_div_16(uint16_t lhs, uint16_t rhs){
  if (lhs == P16INF) {
    if (rhs == P16INF) { return 3; }
    return 2;
  }
  if (lhs == P16ZER) {
    if (rhs == P16ZER) { return 3; }
    return 1;
  }
  if (rhs == P16INF) { return 1; }
  if (rhs == P16ZER) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for div
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_div(p16e0_t *res, p16e0_t *a, p16e0_t *b) {
  p16e0_t pres;
  int status = sanitize_div_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e0_to_f(*a) / p16e0_to_f(*b);
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_div_j(p16e0_t a, p16e0_t b) {
  p16e0_t pres;
  int status = sanitize_div_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e0_to_f(a) / p16e0_to_f(b);
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_div(p16e1_t *res, p16e1_t *a, p16e1_t *b) {
  p16e1_t pres;
  int status = sanitize_div_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e1_to_f(*a) / p16e1_to_f(*b);
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_div_j(p16e1_t a, p16e1_t b) {
  p16e1_t pres;
  int status = sanitize_div_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e1_to_f(a) / p16e1_to_f(b);
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_div(p16e2_t *res, p16e2_t *a, p16e2_t *b) {
  p16e2_t pres;
  int status = sanitize_div_16((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = p16e2_to_f(*a) / p16e2_to_f(*b);
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_div_j(p16e2_t a, p16e2_t b) {
  p16e2_t pres;
  int status = sanitize_div_16((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = p16e2_to_f(a) / p16e2_to_f(b);
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, div sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_div_32(uint32_t lhs, uint32_t rhs){
  if (lhs == P32INF) {
    if (rhs == P32INF) { return 3; }
    return 2;
  }
  if (lhs == P32ZER) {
    if (rhs == P32ZER) { return 3; }
    return 1;
  }
  if (rhs == P32INF) { return 1; }
  if (rhs == P32ZER) { return 2; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for div
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_div(p32e0_t *res, p32e0_t *a, p32e0_t *b) {
  p32e0_t pres;
  int status = sanitize_div_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e0_to_f(*a) / p32e0_to_f(*b);
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_div_j(p32e0_t a, p32e0_t b) {
  p32e0_t pres;
  int status = sanitize_div_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e0_to_f(a) / p32e0_to_f(b);
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_div(p32e1_t *res, p32e1_t *a, p32e1_t *b) {
  p32e1_t pres;
  int status = sanitize_div_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e1_to_f(*a) / p32e1_to_f(*b);
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_div_j(p32e1_t a, p32e1_t b) {
  p32e1_t pres;
  int status = sanitize_div_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e1_to_f(a) / p32e1_to_f(b);
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_div(p32e2_t *res, p32e2_t *a, p32e2_t *b) {
  p32e2_t pres;
  int status = sanitize_div_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e2_to_f(*a) / p32e2_to_f(*b);
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_div_j(p32e2_t a, p32e2_t b) {
  p32e2_t pres;
  int status = sanitize_div_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e2_to_f(a) / p32e2_to_f(b);
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_div(p32e3_t *res, p32e3_t *a, p32e3_t *b) {
  p32e3_t pres;
  int status = sanitize_div_32((*a).udata, (*b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = p32e3_to_f(*a) / p32e3_to_f(*b);
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_div_j(p32e3_t a, p32e3_t b) {
  p32e3_t pres;
  int status = sanitize_div_32((a).udata, (b).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = p32e3_to_f(a) / p32e3_to_f(b);
  pres = f_to_p32e3(fres);
  return pres;
}





///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for mulinv
///////////////////////////////////////////////////////////////
extern "C"    p8e0_t p8e0_mulinv_j(p8e0_t a) {
  float fres = p8e0_to_f(a);
  return f_to_p8e0(1/fres);
}

extern "C"    int p8e0_mulinv(p8e0_t *res, p8e0_t *a) {
  p8e0_t pres;
  float fres = p8e0_to_f(*a);
  pres = f_to_p8e0(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p8e1_t p8e1_mulinv_j(p8e1_t a) {
  float fres = p8e1_to_f(a);
  return f_to_p8e1(1/fres);
}

extern "C"    int p8e1_mulinv(p8e1_t *res, p8e1_t *a) {
  p8e1_t pres;
  float fres = p8e1_to_f(*a);
  pres = f_to_p8e1(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p8e2_t p8e2_mulinv_j(p8e2_t a) {
  float fres = p8e2_to_f(a);
  return f_to_p8e2(1/fres);
}

extern "C"    int p8e2_mulinv(p8e2_t *res, p8e2_t *a) {
  p8e2_t pres;
  float fres = p8e2_to_f(*a);
  pres = f_to_p8e2(1/fres);
  res->udata = pres.udata;
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for mulinv
///////////////////////////////////////////////////////////////
extern "C"    p16e0_t p16e0_mulinv_j(p16e0_t a) {
  float fres = p16e0_to_f(a);
  return f_to_p16e0(1/fres);
}

extern "C"    int p16e0_mulinv(p16e0_t *res, p16e0_t *a) {
  p16e0_t pres;
  float fres = p16e0_to_f(*a);
  pres = f_to_p16e0(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p16e1_t p16e1_mulinv_j(p16e1_t a) {
  float fres = p16e1_to_f(a);
  return f_to_p16e1(1/fres);
}

extern "C"    int p16e1_mulinv(p16e1_t *res, p16e1_t *a) {
  p16e1_t pres;
  float fres = p16e1_to_f(*a);
  pres = f_to_p16e1(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p16e2_t p16e2_mulinv_j(p16e2_t a) {
  float fres = p16e2_to_f(a);
  return f_to_p16e2(1/fres);
}

extern "C"    int p16e2_mulinv(p16e2_t *res, p16e2_t *a) {
  p16e2_t pres;
  float fres = p16e2_to_f(*a);
  pres = f_to_p16e2(1/fres);
  res->udata = pres.udata;
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for mulinv
///////////////////////////////////////////////////////////////
extern "C"    p32e0_t p32e0_mulinv_j(p32e0_t a) {
  double fres = p32e0_to_f(a);
  return f_to_p32e0(1/fres);
}

extern "C"    int p32e0_mulinv(p32e0_t *res, p32e0_t *a) {
  p32e0_t pres;
  double fres = p32e0_to_f(*a);
  pres = f_to_p32e0(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p32e1_t p32e1_mulinv_j(p32e1_t a) {
  double fres = p32e1_to_f(a);
  return f_to_p32e1(1/fres);
}

extern "C"    int p32e1_mulinv(p32e1_t *res, p32e1_t *a) {
  p32e1_t pres;
  double fres = p32e1_to_f(*a);
  pres = f_to_p32e1(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p32e2_t p32e2_mulinv_j(p32e2_t a) {
  double fres = p32e2_to_f(a);
  return f_to_p32e2(1/fres);
}

extern "C"    int p32e2_mulinv(p32e2_t *res, p32e2_t *a) {
  p32e2_t pres;
  double fres = p32e2_to_f(*a);
  pres = f_to_p32e2(1/fres);
  res->udata = pres.udata;
  return 0;
}

extern "C"    p32e3_t p32e3_mulinv_j(p32e3_t a) {
  double fres = p32e3_to_f(a);
  return f_to_p32e3(1/fres);
}

extern "C"    int p32e3_mulinv(p32e3_t *res, p32e3_t *a) {
  p32e3_t pres;
  double fres = p32e3_to_f(*a);
  pres = f_to_p32e3(1/fres);
  res->udata = pres.udata;
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_8 section, log2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log2_8(uint8_t arg){
  if (arg == P8INF) { return 2; }
  if (arg == P8ZER) { return 2; }
  if ((arg & P8INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for log2
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_log2(p8e0_t *res, p8e0_t *a) {
  p8e0_t pres;
  int status = sanitize_log2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p8e0_to_f(*a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_log2_j(p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_log2(p8e1_t *res, p8e1_t *a) {
  p8e1_t pres;
  int status = sanitize_log2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p8e1_to_f(*a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_log2_j(p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_log2(p8e2_t *res, p8e2_t *a) {
  p8e2_t pres;
  int status = sanitize_log2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p8e2_to_f(*a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_log2_j(p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, log2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log2_16(uint16_t arg){
  if (arg == P16INF) { return 2; }
  if (arg == P16ZER) { return 2; }
  if ((arg & P16INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for log2
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_log2(p16e0_t *res, p16e0_t *a) {
  p16e0_t pres;
  int status = sanitize_log2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p16e0_to_f(*a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_log2_j(p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_log2(p16e1_t *res, p16e1_t *a) {
  p16e1_t pres;
  int status = sanitize_log2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p16e1_to_f(*a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_log2_j(p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_log2(p16e2_t *res, p16e2_t *a) {
  p16e2_t pres;
  int status = sanitize_log2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log2(p16e2_to_f(*a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_log2_j(p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = log2(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, log2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log2_32(uint32_t arg){
  if (arg == P32INF) { return 2; }
  if (arg == P32ZER) { return 2; }
  if ((arg & P32INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for log2
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_log2(p32e0_t *res, p32e0_t *a) {
  p32e0_t pres;
  int status = sanitize_log2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log2(p32e0_to_f(*a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_log2_j(p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = log2(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_log2(p32e1_t *res, p32e1_t *a) {
  p32e1_t pres;
  int status = sanitize_log2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log2(p32e1_to_f(*a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_log2_j(p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = log2(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_log2(p32e2_t *res, p32e2_t *a) {
  p32e2_t pres;
  int status = sanitize_log2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log2(p32e2_to_f(*a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_log2_j(p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = log2(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_log2(p32e3_t *res, p32e3_t *a) {
  p32e3_t pres;
  int status = sanitize_log2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log2(p32e3_to_f(*a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_log2_j(p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = log2(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, exp2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp2_8(uint8_t arg){
  if (arg == P8INF) { return 3; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for exp2
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_exp2(p8e0_t *res, p8e0_t *a) {
  p8e0_t pres;
  int status = sanitize_exp2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p8e0_to_f(*a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_exp2_j(p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_exp2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_exp2(p8e1_t *res, p8e1_t *a) {
  p8e1_t pres;
  int status = sanitize_exp2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p8e1_to_f(*a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_exp2_j(p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_exp2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_exp2(p8e2_t *res, p8e2_t *a) {
  p8e2_t pres;
  int status = sanitize_exp2_8((*a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p8e2_to_f(*a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_exp2_j(p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_exp2_8((a).udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, exp2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp2_16(uint16_t arg){
  if (arg == P16INF) { return 3; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for exp2
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_exp2(p16e0_t *res, p16e0_t *a) {
  p16e0_t pres;
  int status = sanitize_exp2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p16e0_to_f(*a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_exp2_j(p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_exp2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_exp2(p16e1_t *res, p16e1_t *a) {
  p16e1_t pres;
  int status = sanitize_exp2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p16e1_to_f(*a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_exp2_j(p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_exp2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_exp2(p16e2_t *res, p16e2_t *a) {
  p16e2_t pres;
  int status = sanitize_exp2_16((*a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp2(p16e2_to_f(*a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_exp2_j(p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_exp2_16((a).udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: throw_nan_jmp();
  }

  float fres = exp2(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, exp2 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp2_32(uint32_t arg){
  if (arg == P32INF) { return 3; }
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for exp2
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_exp2(p32e0_t *res, p32e0_t *a) {
  p32e0_t pres;
  int status = sanitize_exp2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp2(p32e0_to_f(*a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_exp2_j(p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_exp2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = exp2(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_exp2(p32e1_t *res, p32e1_t *a) {
  p32e1_t pres;
  int status = sanitize_exp2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp2(p32e1_to_f(*a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_exp2_j(p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_exp2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = exp2(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_exp2(p32e2_t *res, p32e2_t *a) {
  p32e2_t pres;
  int status = sanitize_exp2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp2(p32e2_to_f(*a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_exp2_j(p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_exp2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = exp2(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_exp2(p32e3_t *res, p32e3_t *a) {
  p32e3_t pres;
  int status = sanitize_exp2_32((*a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp2(p32e3_to_f(*a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_exp2_j(p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_exp2_32((a).udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: throw_nan_jmp();
  }

  double fres = exp2(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



