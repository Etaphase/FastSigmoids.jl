
#include "P8e1.h"


P8e1::P8e1(){ this.data = P8ZER; }

P8e1::P8e1(float a){ this.data = f_to_p8e1(a).udata; }

P8e1::P8e1(double a){ this.data = f_to_p8e1((float) a).udata; }

P8e1::P8e1(P8e1 a){ this.data = a.udata; }

P8e1::P8e1(p8e1_t a){ this.data = a.udata; }



P8e1 &P8e1::operator *=(const P8e1 rhs){
  p8e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e1_mul_j((p8e1_t *) this, lhs, (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P8e1 P8e1::operator *(const P8e1 rhs){
  p8e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e1_mul(&res, (p8e1_t) (*this), (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P8e1 &P8e1::operator -=(const P8e1 rhs){
  p8e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e1_sub_j((p8e1_t *) this, lhs, (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P8e1 P8e1::operator -(const P8e1 rhs){
  p8e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e1_sub(&res, (p8e1_t) (*this), (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P8e1 &P8e1::operator +=(const P8e1 rhs){
  p8e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e1_add_j((p8e1_t *) this, lhs, (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P8e1 P8e1::operator +(const P8e1 rhs){
  p8e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e1_add(&res, (p8e1_t) (*this), (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P8e1 &P8e1::operator /=(const P8e1 rhs){
  p8e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e1_div_j((p8e1_t *) this, lhs, (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P8e1 P8e1::operator /(const P8e1 rhs){
  p8e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e1_div(&res, (p8e1_t) (*this), (p8e1_t) rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


