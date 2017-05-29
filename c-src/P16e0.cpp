
#include "P16e0.h"


P16e0::P16e0(){ this.data = P16ZER; }

P16e0::P16e0(float a){ this.data = f_to_p16e0(a).udata; }

P16e0::P16e0(double a){ this.data = f_to_p16e0((float) a).udata; }

P16e0::P16e0(P16e0 a){ this.data = a.udata; }

P16e0::P16e0(p16e0_t a){ this.data = a.udata; }



P16e0 &P16e0::operator *=(const P16e0 rhs){
  p16e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e0_mul_j((p16e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P16e0 P16e0::operator *(const P16e0 rhs){
  p16e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e0_mul(&res, (p16e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P16e0 &P16e0::operator -=(const P16e0 rhs){
  p16e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e0_sub_j((p16e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P16e0 P16e0::operator -(const P16e0 rhs){
  p16e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e0_sub(&res, (p16e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P16e0 &P16e0::operator +=(const P16e0 rhs){
  p16e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e0_add_j((p16e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P16e0 P16e0::operator +(const P16e0 rhs){
  p16e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e0_add(&res, (p16e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P16e0 &P16e0::operator /=(const P16e0 rhs){
  p16e0_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e0_div_j((p16e0_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P16e0 P16e0::operator /(const P16e0 rhs){
  p16e0_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e0_div(&res, (p16e0_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


