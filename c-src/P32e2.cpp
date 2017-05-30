
#include "include/posit_conv.h"
#include "include/posit_ops.h"
#include "include/posit_ops_jumps.h"
#include "include/P32e2.h"
#include <stdexcept>


P32e2::P32e2(){ this->data = P32ZER; }

P32e2::P32e2(const float a){ this->data = f_to_p32e2((double) a).udata; }

P32e2::P32e2(const double a){ this->data = f_to_p32e2(a).udata; }

P32e2::P32e2(const P32e2 &a){ this->data = a.data; }

P32e2::P32e2(const p32e2_t a){ this->data = a.udata; }



P32e2 &P32e2::operator *=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_mul_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator *=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator *(const P32e2 rhs){
  P32e2 res;          //create a return value on the stack.
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_t(p32e2_mul_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator *");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator -=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_sub_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator -=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator -(const P32e2 rhs){
  P32e2 res;          //create a return value on the stack.
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_t(p32e2_sub_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator -");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator +=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_add_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator +=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator +(const P32e2 rhs){
  P32e2 res;          //create a return value on the stack.
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_t(p32e2_add_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator +");
  }

  return P32e2(res);
}

P32e2 &P32e2::operator /=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p, res;      //create lhs and res values on the stack.
  lhs_p.udata = this->data;   //set it to the value of the current item.
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_div_j(lhs_p, rhs_p);
  } else {
    throw std::domain_error("NaN value obtained in operator /=");
  }

  this->data = res.udata;
  return (*this);
}

P32e2 P32e2::operator /(const P32e2 rhs){
  P32e2 res;          //create a return value on the stack.
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  if (set_nan_jmp()){
    res = p32e2_t(p32e2_div_j(lhs_p, rhs_p));
  } else {
    throw std::domain_error("NaN value obtained in operator /");
  }

  return P32e2(res);
}


bool P32e2::operator >(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_gt(lhs_p, rhs_p);
}


bool P32e2::operator >=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_gte(lhs_p, rhs_p);
}


bool P32e2::operator <=(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_lte(lhs_p, rhs_p);
}


bool P32e2::operator <(const P32e2 rhs){
  p32e2_t lhs_p, rhs_p;
  lhs_p.udata = this->data;
  rhs_p.udata = rhs.data;

  return p32e2_lt(lhs_p, rhs_p);
}



