
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P16e0.h"
#include <stdexcept>


P16e0::P16e0(){ this->data = P16ZER; }

P16e0::P16e0(const float a){ this->data = f_to_p16e0(a).udata; }

P16e0::P16e0(const double a){ this->data = f_to_p16e0((float) a).udata; }

P16e0::P16e0(const P16e0 &a){ this->data = a.data; }

P16e0::P16e0(const p16e0_t a){ this->data = a.udata; }



P16e0 &P16e0::operator *=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator *(const P16e0 rhs){
  P16e0 res;          //create a return value on the stack.
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_t(p16e0_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator -=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator -(const P16e0 rhs){
  P16e0 res;          //create a return value on the stack.
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_t(p16e0_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator +=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator +(const P16e0 rhs){
  P16e0 res;          //create a return value on the stack.
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_t(p16e0_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e0(res);
}

P16e0 &P16e0::operator /=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e0 P16e0::operator /(const P16e0 rhs){
  P16e0 res;          //create a return value on the stack.
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e0_t(p16e0_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e0(res);
}


bool P16e0::operator >(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_gt(lhs_p, rhs_p);
}


bool P16e0::operator >=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_gte(lhs_p, rhs_p);
}


bool P16e0::operator <=(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_lte(lhs_p, rhs_p);
}


bool P16e0::operator <(const P16e0 rhs){
  p16e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e0_lt(lhs_p, rhs_p);
}



