
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P16e1.h"
#include <stdexcept>


P16e1::P16e1(){ this->data = P16ZER; }

P16e1::P16e1(const float a){
  if (set_nan_jmp()) {
    this->data = f_to_p16e1(a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e1::P16e1(const double a){
  if (set_nan_jmp()) {
    this->data = f_to_p16e1((float) a).udata;
  } else {
    throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
  }
}

P16e1::P16e1(const P16e1 &a){ this->data = a.data; }

P16e1::P16e1(const p16e1_t a){ this->data = a.udata; }



P16e1 P16e1::operator -() const{
  P16e1 res;
  res.data = -(this->data);
  return res;
}

P16e1 &P16e1::operator *=(const P16e1 rhs){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_mul_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator *(const P16e1 rhs) const{
  P16e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_mul_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator -=(const P16e1 rhs){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_sub_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator -(const P16e1 rhs) const{
  P16e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_sub_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator +=(const P16e1 rhs){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_add_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator +(const P16e1 rhs) const{
  P16e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_add_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e1(res);
}

P16e1 &P16e1::operator /=(const P16e1 rhs){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_div_j(*this, rhs);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e1 P16e1::operator /(const P16e1 rhs) const{
  P16e1 res;          //create a return value from the stack.

  if (set_nan_jmp()){
    res = p16e1_t(p16e1_div_j(*this, rhs));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e1(res);
}


bool P16e1::operator >(const P16e1 rhs) const{
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_gt(lhs_p, rhs_p);
}


bool P16e1::operator >=(const P16e1 rhs) const{
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_gte(lhs_p, rhs_p);
}


bool P16e1::operator <=(const P16e1 rhs) const{
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_lte(lhs_p, rhs_p);
}


bool P16e1::operator <(const P16e1 rhs) const{
  p16e1_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e1_lt(lhs_p, rhs_p);
}



P16e1::operator float() const{
  return (float) p16e1_to_f((p16e1_t)(*this));
}

P16e1::operator double() const{
  return (double) p16e1_to_f((p16e1_t)(*this));
}

P16e1::operator p16e1_t() const{
  p16e1_t res;
  res.udata = this->data;
  return res;
}



P16e1 mulinv (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_mulinv_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function mulinv");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 log2 (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_log2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log2");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 exp2 (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_exp2_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp2");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 sqrt (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_sqrt_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sqrt");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 log1p (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_log1p_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log1p");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 log (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_log_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 log10 (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_log10_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function log10");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 exp (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_exp_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function exp");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 sin (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_sin_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function sin");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 cos (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_cos_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function cos");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 atan (const P16e1 x){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_atan_j(x);
  } else {
    throw std::domain_error("NaN value obtained in function atan");
  }

  P16e1 res_c(res);
  return res_c;
}



P16e1 pow (const P16e1 a, const P16e1 b){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_pow_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function pow");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 atan2 (const P16e1 a, const P16e1 b){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_atan2_j(a, b);
  } else {
    throw std::domain_error("NaN value obtained in function atan2");
  }

  P16e1 res_c(res);
  return res_c;
}



P16e1 fma(const P16e1 a, const P16e1 b, const P16e1 c){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_fma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fma");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 fms(const P16e1 a, const P16e1 b, const P16e1 c){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_fms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function fms");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 nfma(const P16e1 a, const P16e1 b, const P16e1 c){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_nfma_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfma");
  }

  P16e1 res_c(res);
  return res_c;
}


P16e1 nfms(const P16e1 a, const P16e1 b, const P16e1 c){
  p16e1_t res;

  if (set_nan_jmp()){
    res = p16e1_nfms_j(a, b, c);
  } else {
    throw std::domain_error("NaN value obtained in function nfms");
  }

  P16e1 res_c(res);
  return res_c;
}

