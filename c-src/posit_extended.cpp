#include "include/posit.h"
#include "include/posit_conv.h"
#include <errno.h>


///////////////////////////////////////////////////////////////
//  posit_8 section, sqrt sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sqrt_8(const uint8_t arg){
  if (arg == P8INF) { return 2; }
  if (arg == P8ZER) { return 1; }
  if ((arg & P8INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for sqrt
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_sqrt(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_sqrt_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_sqrt(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_sqrt_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_sqrt(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_sqrt_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_sqrt_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, sqrt sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sqrt_16(const uint16_t arg){
  if (arg == P16INF) { return 2; }
  if (arg == P16ZER) { return 1; }
  if ((arg & P16INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for sqrt
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_sqrt(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_sqrt_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_sqrt(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_sqrt_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_sqrt(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sqrt(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_sqrt_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_sqrt_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sqrt(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, sqrt sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sqrt_32(const uint32_t arg){
  if (arg == P32INF) { return 2; }
  if (arg == P32ZER) { return 1; }
  if ((arg & P32INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for sqrt
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_sqrt(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sqrt(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_sqrt_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sqrt(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_sqrt(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sqrt(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_sqrt_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sqrt(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_sqrt(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sqrt(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_sqrt_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sqrt(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_sqrt(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sqrt(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_sqrt_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_sqrt_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sqrt(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, log1p sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log1p_8(const uint8_t arg){
  if (arg == P8INF) { return 2; }
  if (arg == P8ZER) { return 2; }
  if ((arg & P8INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for log1p
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_log1p(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_log1p_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_log1p(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_log1p_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_log1p(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_log1p_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log1p_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, log1p sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log1p_16(const uint16_t arg){
  if (arg == P16INF) { return 2; }
  if (arg == P16ZER) { return 2; }
  if ((arg & P16INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for log1p
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_log1p(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_log1p_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_log1p(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_log1p_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_log1p(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log1p(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_log1p_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log1p_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log1p(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, log1p sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log1p_32(const uint32_t arg){
  if (arg == P32INF) { return 2; }
  if (arg == P32ZER) { return 2; }
  if ((arg & P32INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for log1p
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_log1p(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log1p(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_log1p_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log1p(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_log1p(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log1p(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_log1p_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log1p(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_log1p(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log1p(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_log1p_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log1p(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_log1p(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log1p(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_log1p_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log1p_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log1p(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, log sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log_8(const uint8_t arg){
  if (arg == P8INF) { return 2; }
  if (arg == P8ZER) { return 2; }
  if ((arg & P8INF) != 0) { return 3; } //negative values are rejected
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for log
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_log(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_log_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_log(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_log_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_log(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_log_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, log sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log_16(const uint16_t arg){
  if (arg == P16INF) { return 2; }
  if (arg == P16ZER) { return 2; }
  if ((arg & P16INF) != 0) { return 3; } //negative values are rejected
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for log
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_log(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_log_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_log(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_log_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_log(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_log_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, log sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log_32(const uint32_t arg){
  if (arg == P32INF) { return 2; }
  if (arg == P32ZER) { return 2; }
  if ((arg & P32INF) != 0) { return 3; } //negative values are rejected
  return 0;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for log
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_log(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_log_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_log(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_log_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_log(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_log_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_log(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_log_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, log10 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log10_8(const uint8_t arg){
  if (arg == P8INF) { return 2; }
  if (arg == P8ZER) { return 2; }
  if ((arg & P8INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for log10
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_log10(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_log10_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log10(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_log10(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_log10_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log10(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_log10(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_log10_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_log10_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = log10(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, log10 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log10_16(const uint16_t arg){
  if (arg == P16INF) { return 2; }
  if (arg == P16ZER) { return 2; }
  if ((arg & P16INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for log10
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_log10(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_log10_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log10(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_log10(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_log10_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log10(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_log10(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = log10(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_log10_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_log10_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = log10(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, log10 sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_log10_32(const uint32_t arg){
  if (arg == P32INF) { return 2; }
  if (arg == P32ZER) { return 2; }
  if ((arg & P32INF) != 0) { return 3; } //negative values are rejected
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for log10
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_log10(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log10(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_log10_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log10(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_log10(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log10(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_log10_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log10(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_log10(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log10(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_log10_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log10(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_log10(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = log10(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_log10_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_log10_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = log10(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, exp sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp_8(const uint8_t arg){
  if (arg == P8INF) { return 3; }  //only infinity is indeterminate
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for exp
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_exp(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_exp_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = exp(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_exp(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_exp_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = exp(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_exp(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_exp_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_exp_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = exp(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, exp sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp_16(const uint16_t arg){
  if (arg == P16INF) { return 3; }  //only infinity is indeterminate
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for exp
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_exp(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_exp_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = exp(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_exp(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_exp_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = exp(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_exp(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = exp(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_exp_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_exp_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = exp(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, exp sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_exp_32(const uint32_t arg){
  if (arg == P32INF) { return 3; }  //only infinity is indeterminate
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for exp
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_exp(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_exp_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = exp(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_exp(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_exp_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = exp(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_exp(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_exp_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = exp(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_exp(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = exp(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_exp_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_exp_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = exp(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}





///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for pow
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_pow(p8e0_t * res, const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = pow(p8e0_to_f(a), p8e0_to_f(b));

  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e0_t p8e0_pow_e(const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = pow(p8e0_to_f(a), p8e0_to_f(b));

  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_pow(p8e1_t * res, const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = pow(p8e1_to_f(a), p8e1_to_f(b));

  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e1_t p8e1_pow_e(const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = pow(p8e1_to_f(a), p8e1_to_f(b));

  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_pow(p8e2_t * res, const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = pow(p8e2_to_f(a), p8e2_to_f(b));

  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e2_t p8e2_pow_e(const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = pow(p8e2_to_f(a), p8e2_to_f(b));

  pres = f_to_p8e2(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for pow
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_pow(p16e0_t * res, const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = pow(p16e0_to_f(a), p16e0_to_f(b));

  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e0_t p16e0_pow_e(const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = pow(p16e0_to_f(a), p16e0_to_f(b));

  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_pow(p16e1_t * res, const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = pow(p16e1_to_f(a), p16e1_to_f(b));

  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e1_t p16e1_pow_e(const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = pow(p16e1_to_f(a), p16e1_to_f(b));

  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_pow(p16e2_t * res, const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = pow(p16e2_to_f(a), p16e2_to_f(b));

  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e2_t p16e2_pow_e(const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = pow(p16e2_to_f(a), p16e2_to_f(b));

  pres = f_to_p16e2(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for pow
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_pow(p32e0_t * res, const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = pow(p32e0_to_f(a), p32e0_to_f(b));

  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e0_t p32e0_pow_e(const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = pow(p32e0_to_f(a), p32e0_to_f(b));

  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_pow(p32e1_t * res, const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = pow(p32e1_to_f(a), p32e1_to_f(b));

  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e1_t p32e1_pow_e(const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = pow(p32e1_to_f(a), p32e1_to_f(b));

  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_pow(p32e2_t * res, const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = pow(p32e2_to_f(a), p32e2_to_f(b));

  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e2_t p32e2_pow_e(const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = pow(p32e2_to_f(a), p32e2_to_f(b));

  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_pow(p32e3_t * res, const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = pow(p32e3_to_f(a), p32e3_to_f(b));

  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e3_t p32e3_pow_e(const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = pow(p32e3_to_f(a), p32e3_to_f(b));

  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, sin sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sin_8(const uint8_t a){
  if (a == P8INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for sin
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_sin(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_sin_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sin(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_sin(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_sin_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sin(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_sin(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_sin_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_sin_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = sin(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, sin sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sin_16(const uint16_t a){
  if (a == P16INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for sin
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_sin(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_sin_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sin(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_sin(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_sin_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sin(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_sin(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = sin(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_sin_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_sin_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = sin(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, sin sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_sin_32(const uint32_t a){
  if (a == P32INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for sin
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_sin(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sin(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_sin_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sin(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_sin(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sin(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_sin_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sin(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_sin(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sin(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_sin_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sin(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_sin(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = sin(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_sin_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_sin_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = sin(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, cos sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_cos_8(const uint8_t a){
  if (a == P8INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for cos
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_cos(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_cos_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = cos(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_cos(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_cos_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = cos(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_cos(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_cos_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_cos_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = cos(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, cos sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_cos_16(const uint16_t a){
  if (a == P16INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for cos
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_cos(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_cos_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = cos(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_cos(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_cos_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = cos(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_cos(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = cos(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_cos_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_cos_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = cos(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, cos sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_cos_32(const uint32_t a){
  if (a == P32INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for cos
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_cos(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = cos(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_cos_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = cos(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_cos(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = cos(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_cos_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = cos(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_cos(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = cos(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_cos_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = cos(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_cos(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = cos(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_cos_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_cos_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = cos(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, atan sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_atan_8(const uint8_t a){
  if (a == P8INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for atan
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_atan(p8e0_t * res, const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e0_t p8e0_atan_e(const p8e0_t a) {
  p8e0_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = atan(p8e0_to_f(a));
  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_atan(p8e1_t * res, const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e1_t p8e1_atan_e(const p8e1_t a) {
  p8e1_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = atan(p8e1_to_f(a));
  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_atan(p8e2_t * res, const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P8INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p8e2_t p8e2_atan_e(const p8e2_t a) {
  p8e2_t pres;
  int status = sanitize_atan_8(a.udata);
  switch (status){
   case 1: pres.udata = P8ZER; return pres;
   case 2: pres.udata = P8INF; return pres;
   case 3: pres.udata = P8ZER; errno = EDOM; return pres;
  }

  float fres = atan(p8e2_to_f(a));
  pres = f_to_p8e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_16 section, atan sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_atan_16(const uint16_t a){
  if (a == P16INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for atan
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_atan(p16e0_t * res, const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e0_t p16e0_atan_e(const p16e0_t a) {
  p16e0_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = atan(p16e0_to_f(a));
  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_atan(p16e1_t * res, const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e1_t p16e1_atan_e(const p16e1_t a) {
  p16e1_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = atan(p16e1_to_f(a));
  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_atan(p16e2_t * res, const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P16INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  float fres = atan(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p16e2_t p16e2_atan_e(const p16e2_t a) {
  p16e2_t pres;
  int status = sanitize_atan_16(a.udata);
  switch (status){
   case 1: pres.udata = P16ZER; return pres;
   case 2: pres.udata = P16INF; return pres;
   case 3: pres.udata = P16ZER; errno = EDOM; return pres;
  }

  float fres = atan(p16e2_to_f(a));
  pres = f_to_p16e2(fres);
  return pres;
}


///////////////////////////////////////////////////////////////
//  posit_32 section, atan sanitizers
///////////////////////////////////////////////////////////////

static int sanitize_atan_32(const uint32_t a){
  if (a == P32INF) {return 3;}  //inf^0 is NaN
  return 0;
}



///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for atan
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_atan(p32e0_t * res, const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = atan(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e0_t p32e0_atan_e(const p32e0_t a) {
  p32e0_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = atan(p32e0_to_f(a));
  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_atan(p32e1_t * res, const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = atan(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e1_t p32e1_atan_e(const p32e1_t a) {
  p32e1_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = atan(p32e1_to_f(a));
  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_atan(p32e2_t * res, const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = atan(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e2_t p32e2_atan_e(const p32e2_t a) {
  p32e2_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = atan(p32e2_to_f(a));
  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_atan(p32e3_t * res, const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; res->udata = pres.udata; return 0;
   case 2: pres.udata = P32INF; res->udata = pres.udata; return 0;
   case 3: return EDOM;
  }

  double fres = atan(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return 0;
}

extern "C"    p32e3_t p32e3_atan_e(const p32e3_t a) {
  p32e3_t pres;
  int status = sanitize_atan_32(a.udata);
  switch (status){
   case 1: pres.udata = P32ZER; return pres;
   case 2: pres.udata = P32INF; return pres;
   case 3: pres.udata = P32ZER; errno = EDOM; return pres;
  }

  double fres = atan(p32e3_to_f(a));
  pres = f_to_p32e3(fres);
  return pres;
}





///////////////////////////////////////////////////////////////
//  posit_8 section, variable ES adapters for atan2
///////////////////////////////////////////////////////////////
extern "C"    int p8e0_atan2(p8e0_t * res, const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = atan2(p8e0_to_f(a), p8e0_to_f(b));

  pres = f_to_p8e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e0_t p8e0_atan2_e(const p8e0_t a, const p8e0_t b) {
  p8e0_t pres;

  float fres;
  fres = atan2(p8e0_to_f(a), p8e0_to_f(b));

  pres = f_to_p8e0(fres);
  return pres;
}


extern "C"    int p8e1_atan2(p8e1_t * res, const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = atan2(p8e1_to_f(a), p8e1_to_f(b));

  pres = f_to_p8e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e1_t p8e1_atan2_e(const p8e1_t a, const p8e1_t b) {
  p8e1_t pres;

  float fres;
  fres = atan2(p8e1_to_f(a), p8e1_to_f(b));

  pres = f_to_p8e1(fres);
  return pres;
}


extern "C"    int p8e2_atan2(p8e2_t * res, const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = atan2(p8e2_to_f(a), p8e2_to_f(b));

  pres = f_to_p8e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p8e2_t p8e2_atan2_e(const p8e2_t a, const p8e2_t b) {
  p8e2_t pres;

  float fres;
  fres = atan2(p8e2_to_f(a), p8e2_to_f(b));

  pres = f_to_p8e2(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_16 section, variable ES adapters for atan2
///////////////////////////////////////////////////////////////
extern "C"    int p16e0_atan2(p16e0_t * res, const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = atan2(p16e0_to_f(a), p16e0_to_f(b));

  pres = f_to_p16e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e0_t p16e0_atan2_e(const p16e0_t a, const p16e0_t b) {
  p16e0_t pres;

  float fres;
  fres = atan2(p16e0_to_f(a), p16e0_to_f(b));

  pres = f_to_p16e0(fres);
  return pres;
}


extern "C"    int p16e1_atan2(p16e1_t * res, const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = atan2(p16e1_to_f(a), p16e1_to_f(b));

  pres = f_to_p16e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e1_t p16e1_atan2_e(const p16e1_t a, const p16e1_t b) {
  p16e1_t pres;

  float fres;
  fres = atan2(p16e1_to_f(a), p16e1_to_f(b));

  pres = f_to_p16e1(fres);
  return pres;
}


extern "C"    int p16e2_atan2(p16e2_t * res, const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = atan2(p16e2_to_f(a), p16e2_to_f(b));

  pres = f_to_p16e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p16e2_t p16e2_atan2_e(const p16e2_t a, const p16e2_t b) {
  p16e2_t pres;

  float fres;
  fres = atan2(p16e2_to_f(a), p16e2_to_f(b));

  pres = f_to_p16e2(fres);
  return pres;
}




///////////////////////////////////////////////////////////////
//  posit_32 section, variable ES adapters for atan2
///////////////////////////////////////////////////////////////
extern "C"    int p32e0_atan2(p32e0_t * res, const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = atan2(p32e0_to_f(a), p32e0_to_f(b));

  pres = f_to_p32e0(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e0_t p32e0_atan2_e(const p32e0_t a, const p32e0_t b) {
  p32e0_t pres;

  double fres;
  fres = atan2(p32e0_to_f(a), p32e0_to_f(b));

  pres = f_to_p32e0(fres);
  return pres;
}


extern "C"    int p32e1_atan2(p32e1_t * res, const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = atan2(p32e1_to_f(a), p32e1_to_f(b));

  pres = f_to_p32e1(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e1_t p32e1_atan2_e(const p32e1_t a, const p32e1_t b) {
  p32e1_t pres;

  double fres;
  fres = atan2(p32e1_to_f(a), p32e1_to_f(b));

  pres = f_to_p32e1(fres);
  return pres;
}


extern "C"    int p32e2_atan2(p32e2_t * res, const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = atan2(p32e2_to_f(a), p32e2_to_f(b));

  pres = f_to_p32e2(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e2_t p32e2_atan2_e(const p32e2_t a, const p32e2_t b) {
  p32e2_t pres;

  double fres;
  fres = atan2(p32e2_to_f(a), p32e2_to_f(b));

  pres = f_to_p32e2(fres);
  return pres;
}


extern "C"    int p32e3_atan2(p32e3_t * res, const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = atan2(p32e3_to_f(a), p32e3_to_f(b));

  pres = f_to_p32e3(fres);
  res->udata = pres.udata; return errno;
}

extern "C"    p32e3_t p32e3_atan2_e(const p32e3_t a, const p32e3_t b) {
  p32e3_t pres;

  double fres;
  fres = atan2(p32e3_to_f(a), p32e3_to_f(b));

  pres = f_to_p32e3(fres);
  return pres;
}



