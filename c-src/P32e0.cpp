
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_errno.h"
#include "include/P32e0.h"
#include "errno.h"
#include <stdexcept>


P32e0::P32e0(){ this->data = P32ZER; }

P32e0::P32e0(const float a){
  this->data = f_to_p32e0((double) a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e0::P32e0(const double a){
  this->data = f_to_p32e0(a).udata;
  if (errno) {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e0::P32e0(const P32e0 &a){ this->data = a.data; }

P32e0::P32e0(const p32e0_t a){ this->data = a.udata; }



P32e0 P32e0::operator -() const{
  P32e0 res;
  res.data = -(this->data);
  return res;
}

P32e0 &P32e0::operator *=(const P32e0 rhs){
  p32e0_t res;

  res = p32e0_mul_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator *(const P32e0 rhs) const{
  P32e0 res;          //create a return value from the stack.

  res = p32e0_t(p32e0_mul_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator -=(const P32e0 rhs){
  p32e0_t res;

  res = p32e0_sub_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator -(const P32e0 rhs) const{
  P32e0 res;          //create a return value from the stack.

  res = p32e0_t(p32e0_sub_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator +=(const P32e0 rhs){
  p32e0_t res;

  res = p32e0_add_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator +(const P32e0 rhs) const{
  P32e0 res;          //create a return value from the stack.

  res = p32e0_t(p32e0_add_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator /=(const P32e0 rhs){
  p32e0_t res;

  res = p32e0_div_e(*this, rhs);
  if (errno) {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator /(const P32e0 rhs) const{
  P32e0 res;          //create a return value from the stack.

  res = p32e0_t(p32e0_div_e(*this, rhs));

  if (errno) {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e0(res);
}


bool P32e0::operator ==(const P32e0 rhs) const{
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_eq(lhs_p, rhs_p);
}


bool P32e0::operator >(const P32e0 rhs) const{
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_gt(lhs_p, rhs_p);
}


bool P32e0::operator >=(const P32e0 rhs) const{
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_gte(lhs_p, rhs_p);
}


bool P32e0::operator <=(const P32e0 rhs) const{
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_lte(lhs_p, rhs_p);
}


bool P32e0::operator <(const P32e0 rhs) const{
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_lt(lhs_p, rhs_p);
}



P32e0::operator float() const{
  return (float) p32e0_to_f((p32e0_t)(*this));
}

P32e0::operator double() const{
  return (double) p32e0_to_f((p32e0_t)(*this));
}

P32e0::operator p32e0_t() const{
  p32e0_t res;
  res.udata = this->data;
  return res;
}


bool isequal(const P32e0 a, const P32e0 b){
  return a.data == b.data;
}


P32e0 mulinv (const P32e0 x){
  p32e0_t res;

  res = p32e0_mulinv_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 log2 (const P32e0 x){
  p32e0_t res;

  res = p32e0_log2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 exp2 (const P32e0 x){
  p32e0_t res;

  res = p32e0_exp2_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 sqrt (const P32e0 x){
  p32e0_t res;

  res = p32e0_sqrt_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 log1p (const P32e0 x){
  p32e0_t res;

  res = p32e0_log1p_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 log (const P32e0 x){
  p32e0_t res;

  res = p32e0_log_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 log10 (const P32e0 x){
  p32e0_t res;

  res = p32e0_log10_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 exp (const P32e0 x){
  p32e0_t res;

  res = p32e0_exp_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 sin (const P32e0 x){
  p32e0_t res;

  res = p32e0_sin_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 cos (const P32e0 x){
  p32e0_t res;

  res = p32e0_cos_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 atan (const P32e0 x){
  p32e0_t res;

  res = p32e0_atan_e(x);

  if (errno) {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P32e0 res_c(res);
  return res_c;
}



P32e0 pow (const P32e0 a, const P32e0 b){
  p32e0_t res;

  res = p32e0_pow_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 atan2 (const P32e0 a, const P32e0 b){
  p32e0_t res;

  res = p32e0_atan2_e(a, b);
  if (errno) {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P32e0 res_c(res);
  return res_c;
}



P32e0 fma(const P32e0 a, const P32e0 b, const P32e0 c){
  p32e0_t res;

  res = p32e0_fma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 fms(const P32e0 a, const P32e0 b, const P32e0 c){
  p32e0_t res;

  res = p32e0_fms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 nfma(const P32e0 a, const P32e0 b, const P32e0 c){
  p32e0_t res;

  res = p32e0_nfma_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P32e0 res_c(res);
  return res_c;
}


P32e0 nfms(const P32e0 a, const P32e0 b, const P32e0 c){
  p32e0_t res;

  res = p32e0_nfms_e(a, b, c);

  if (errno) {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P32e0 res_c(res);
  return res_c;
}

