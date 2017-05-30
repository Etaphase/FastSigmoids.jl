
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P32e0.h"
#include <stdexcept>


P32e0::P32e0(){ this->data = P32ZER; }

P32e0::P32e0(const float a){ this->data = f_to_p32e0((double) a).udata; }

P32e0::P32e0(const double a){ this->data = f_to_p32e0(a).udata; }

P32e0::P32e0(const P32e0 &a){ this->data = a.data; }

P32e0::P32e0(const p32e0_t a){ this->data = a.udata; }



P32e0 &P32e0::operator *=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator *(const P32e0 rhs){
  P32e0 res;          //create a return value on the stack.
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_t(p32e0_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator -=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator -(const P32e0 rhs){
  P32e0 res;          //create a return value on the stack.
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_t(p32e0_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator +=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator +(const P32e0 rhs){
  P32e0 res;          //create a return value on the stack.
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_t(p32e0_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e0(res);
}

P32e0 &P32e0::operator /=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e0 P32e0::operator /(const P32e0 rhs){
  P32e0 res;          //create a return value on the stack.
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e0_t(p32e0_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e0(res);
}


bool P32e0::operator >(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_gt(lhs_p, rhs_p);
}


bool P32e0::operator >=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_gte(lhs_p, rhs_p);
}


bool P32e0::operator <=(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_lte(lhs_p, rhs_p);
}


bool P32e0::operator <(const P32e0 rhs){
  p32e0_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e0_lt(lhs_p, rhs_p);
}



