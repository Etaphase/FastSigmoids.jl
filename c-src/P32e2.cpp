
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P32e2.h"
#include "errno.h"
#include <stdexcept>


P32e2::P32e2(){ this->data = P32ZER; }

P32e2::P32e2(const float a){
  this->data = f_to_p32e2((double) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e2::P32e2(const double a){
  this->data = f_to_p32e2(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e2::P32e2(const P32e2 &a){ this->data = a.data; }

P32e2::P32e2(const p32e2_t a){ this->data = a.udata; }



P32e2 P32e2::operator -() const{
  P32e2 res;
  res.data = -(this->data);
  return res;
}

P32e2 &P32e2::operator *=(const P32e2 rhs){
  p32e2_t res;

  res = p32e2_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator *(const P32e2 rhs) const{
  P32e2 res;          //create a return value from the stack.

  res = p32e2_t(p32e2_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator -=(const P32e2 rhs){
  p32e2_t res;

  res = p32e2_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator -(const P32e2 rhs) const{
  P32e2 res;          //create a return value from the stack.

  res = p32e2_t(p32e2_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator +=(const P32e2 rhs){
  p32e2_t res;

  res = p32e2_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator +(const P32e2 rhs) const{
  P32e2 res;          //create a return value from the stack.

  res = p32e2_t(p32e2_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator /=(const P32e2 rhs){
  p32e2_t res;

  res = p32e2_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator /(const P32e2 rhs) const{
  P32e2 res;          //create a return value from the stack.

  res = p32e2_t(p32e2_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e2(res);
}


bool P32e2::operator >(const P32e2 rhs) const{
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_gt(lhs_p, rhs_p);
}


bool P32e2::operator >=(const P32e2 rhs) const{
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_gte(lhs_p, rhs_p);
}


bool P32e2::operator <=(const P32e2 rhs) const{
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_lte(lhs_p, rhs_p);
}


bool P32e2::operator <(const P32e2 rhs) const{
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_lt(lhs_p, rhs_p);
}



P32e2::operator float() const{
  return (float) p32e2_to_f((p32e2_t)(*this));
}

P32e2::operator double() const{
  return (double) p32e2_to_f((p32e2_t)(*this));
}

P32e2::operator p32e2_t() const{
  p32e2_t res;
  res.udata = this->data;
  return res;
}



P32e2 mulinv (const P32e2 x){
  p32e2_t res;

  res = p32e2_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 log2 (const P32e2 x){
  p32e2_t res;

  res = p32e2_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 exp2 (const P32e2 x){
  p32e2_t res;

  res = p32e2_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 sqrt (const P32e2 x){
  p32e2_t res;

  res = p32e2_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 log1p (const P32e2 x){
  p32e2_t res;

  res = p32e2_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 log (const P32e2 x){
  p32e2_t res;

  res = p32e2_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 log10 (const P32e2 x){
  p32e2_t res;

  res = p32e2_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 exp (const P32e2 x){
  p32e2_t res;

  res = p32e2_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 sin (const P32e2 x){
  p32e2_t res;

  res = p32e2_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 cos (const P32e2 x){
  p32e2_t res;

  res = p32e2_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 atan (const P32e2 x){
  p32e2_t res;

  res = p32e2_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P32e2 res_c(res);
  return res_c;
}



P32e2 pow (const P32e2 a, const P32e2 b){
  p32e2_t res;

  res = p32e2_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 atan2 (const P32e2 a, const P32e2 b){
  p32e2_t res;

  res = p32e2_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P32e2 res_c(res);
  return res_c;
}



P32e2 fma(const P32e2 a, const P32e2 b, const P32e2 c){
  p32e2_t res;

  res = p32e2_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 fms(const P32e2 a, const P32e2 b, const P32e2 c){
  p32e2_t res;

  res = p32e2_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 nfma(const P32e2 a, const P32e2 b, const P32e2 c){
  p32e2_t res;

  res = p32e2_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P32e2 res_c(res);
  return res_c;
}


P32e2 nfms(const P32e2 a, const P32e2 b, const P32e2 c){
  p32e2_t res;

  res = p32e2_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P32e2 res_c(res);
  return res_c;
}

