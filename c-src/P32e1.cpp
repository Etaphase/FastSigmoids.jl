
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P32e1.h"
#include <stdexcept>


P32e1::P32e1(){ this->data = P32ZER; }

P32e1::P32e1(const float a){
  if (set_nan_jmp()) {
    this->data = f_to_p32e1((double) a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e1::P32e1(const double a){
  if (set_nan_jmp()) {
    this->data = f_to_p32e1(a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P32e1::P32e1(const P32e1 &a){ this->data = a.data; }

P32e1::P32e1(const p32e1_t a){ this->data = a.udata; }



P32e1 P32e1::operator -() const{
  P32e1 res;
  res.data = -(this->data);
  return res;
}

P32e1 &P32e1::operator *=(const P32e1 rhs){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_mul_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator *(const P32e1 rhs) const{
  P32e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_mul_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator -=(const P32e1 rhs){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_sub_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator -(const P32e1 rhs) const{
  P32e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_sub_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator +=(const P32e1 rhs){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_add_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator +(const P32e1 rhs) const{
  P32e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_add_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e1(res);
}

P32e1 &P32e1::operator /=(const P32e1 rhs){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_div_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e1 P32e1::operator /(const P32e1 rhs) const{
  P32e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p32e1_t(p32e1_div_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e1(res);
}


bool P32e1::operator >(const P32e1 rhs) const{
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_gt(lhs_p, rhs_p);
}


bool P32e1::operator >=(const P32e1 rhs) const{
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_gte(lhs_p, rhs_p);
}


bool P32e1::operator <=(const P32e1 rhs) const{
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_lte(lhs_p, rhs_p);
}


bool P32e1::operator <(const P32e1 rhs) const{
  p32e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e1_lt(lhs_p, rhs_p);
}



P32e1::operator float() const{
  return (float) p32e1_to_f((p32e1_t)(*this));
}

P32e1::operator double() const{
  return (double) p32e1_to_f((p32e1_t)(*this));
}

P32e1::operator p32e1_t() const{
  p32e1_t res;
  res.udata = this->data;
  return res;
}



P32e1 mulinv (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_mulinv_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 log2 (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_log2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 exp2 (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_exp2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 sqrt (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_sqrt_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 log1p (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_log1p_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 log (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_log_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 log10 (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_log10_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 exp (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_exp_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 sin (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_sin_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 cos (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_cos_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 atan (const P32e1 x){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_atan_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P32e1 res_c(res);
  return res_c;
}



P32e1 pow (const P32e1 a, const P32e1 b){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_pow_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 atan2 (const P32e1 a, const P32e1 b){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_atan2_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P32e1 res_c(res);
  return res_c;
}



P32e1 fma(const P32e1 a, const P32e1 b, const P32e1 c){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_fma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 fms(const P32e1 a, const P32e1 b, const P32e1 c){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_fms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 nfma(const P32e1 a, const P32e1 b, const P32e1 c){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_nfma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P32e1 res_c(res);
  return res_c;
}


P32e1 nfms(const P32e1 a, const P32e1 b, const P32e1 c){
  p32e1_t res;

  if (set_nan_jmp()){
    res = p32e1_nfms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P32e1 res_c(res);
  return res_c;
}

