
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P16e2.h"
#include <stdexcept>


P16e2::P16e2(){ this->data = P16ZER; }

P16e2::P16e2(const float a){ this->data = f_to_p16e2(a).udata; }

P16e2::P16e2(const double a){ this->data = f_to_p16e2((float) a).udata; }

P16e2::P16e2(const P16e2 &a){ this->data = a.data; }

P16e2::P16e2(const p16e2_t a){ this->data = a.udata; }



P16e2 &P16e2::operator *=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator *(const P16e2 rhs){
  P16e2 res;          //create a return value on the stack.
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_t(p16e2_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator -=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator -(const P16e2 rhs){
  P16e2 res;          //create a return value on the stack.
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_t(p16e2_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator +=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator +(const P16e2 rhs){
  P16e2 res;          //create a return value on the stack.
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_t(p16e2_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P16e2(res);
}

P16e2 &P16e2::operator /=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P16e2 P16e2::operator /(const P16e2 rhs){
  P16e2 res;          //create a return value on the stack.
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p16e2_t(p16e2_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P16e2(res);
}


bool P16e2::operator >(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_gt(lhs_p, rhs_p);
}


bool P16e2::operator >=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_gte(lhs_p, rhs_p);
}


bool P16e2::operator <=(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_lte(lhs_p, rhs_p);
}


bool P16e2::operator <(const P16e2 rhs){
  p16e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p16e2_lt(lhs_p, rhs_p);
}



