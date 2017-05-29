
#include "P8e0.h"


P8e0::P8e0(){ this.data = P8ZER; }

P8e0::P8e0(float a){ this.data = f_to_p8e0(a).udata; }

P8e0::P8e0(double a){ this.data = f_to_p8e0((float) a).udata; }

P8e0::P8e0(P8e0 a){ this.data = a.udata; }

P8e0::P8e0(p8e0_t a){ this.data = a.udata; }



P8e0 &P8e0::operator *=(const P8e0 rhs){
  p8e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e0_mul_j((p8e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P8e0 P8e0::operator *(const P8e0 rhs){
  p8e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e0_mul(&res, (p8e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P8e0 &P8e0::operator -=(const P8e0 rhs){
  p8e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e0_sub_j((p8e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P8e0 P8e0::operator -(const P8e0 rhs){
  p8e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e0_sub(&res, (p8e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P8e0 &P8e0::operator +=(const P8e0 rhs){
  p8e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e0_add_j((p8e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P8e0 P8e0::operator +(const P8e0 rhs){
  p8e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e0_add(&res, (p8e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P8e0 &P8e0::operator /=(const P8e0 rhs){
  p8e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p8e0_div_j((p8e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P8e0 P8e0::operator /(const P8e0 rhs){
  p8e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p8e0_div(&res, (p8e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


