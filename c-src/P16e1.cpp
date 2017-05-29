
#include "P16e1.h"


P16e1::P16e1(){ this.data = P16ZER; }

P16e1::P16e1(float a){ this.data = f_to_p16e1(a).udata; }

P16e1::P16e1(double a){ this.data = f_to_p16e1((float) a).udata; }

P16e1::P16e1(P16e1 a){ this.data = a.udata; }

P16e1::P16e1(p16e1_t a){ this.data = a.udata; }



P16e1 &P16e1::operator *=(const P16e1 rhs){
  p16e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e1_mul_j((p16e1_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P16e1 P16e1::operator *(const P16e1 rhs){
  p16e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e1_mul(&res, (p16e1_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P16e1 &P16e1::operator -=(const P16e1 rhs){
  p16e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e1_sub_j((p16e1_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P16e1 P16e1::operator -(const P16e1 rhs){
  p16e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e1_sub(&res, (p16e1_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P16e1 &P16e1::operator +=(const P16e1 rhs){
  p16e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e1_add_j((p16e1_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P16e1 P16e1::operator +(const P16e1 rhs){
  p16e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e1_add(&res, (p16e1_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P16e1 &P16e1::operator /=(const P16e1 rhs){
  p16e1_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e1_div_j((p16e1_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P16e1 P16e1::operator /(const P16e1 rhs){
  p16e1_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e1_div(&res, (p16e1_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


