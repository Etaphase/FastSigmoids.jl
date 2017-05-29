
#include "P16e2.h"


P16e2::P16e2(){ this.data = P16ZER; }

P16e2::P16e2(float a){ this.data = f_to_p16e2(a).udata; }

P16e2::P16e2(double a){ this.data = f_to_p16e2((float) a).udata; }

P16e2::P16e2(P16e2 a){ this.data = a.udata; }

P16e2::P16e2(p16e2_t a){ this.data = a.udata; }



P16e2 &P16e2::operator *=(const P16e2 rhs){
  p16e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e2_mul_j((p16e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *=");
  }
  return (*this);
}

P16e2 P16e2::operator *(const P16e2 rhs){
  p16e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e2_mul(&res, (p16e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator *");
  }
  return res;
}

P16e2 &P16e2::operator -=(const P16e2 rhs){
  p16e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e2_sub_j((p16e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -=");
  }
  return (*this);
}

P16e2 P16e2::operator -(const P16e2 rhs){
  p16e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e2_sub(&res, (p16e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator -");
  }
  return res;
}

P16e2 &P16e2::operator +=(const P16e2 rhs){
  p16e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e2_add_j((p16e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +=");
  }
  return (*this);
}

P16e2 P16e2::operator +(const P16e2 rhs){
  p16e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e2_add(&res, (p16e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator +");
  }
  return res;
}

P16e2 &P16e2::operator /=(const P16e2 rhs){
  p16e2_t lhs;          //create an lhs on the stack.
  lhs.udata = this->data;   //set it to the value of the current item.

  if (set_nan_jmp()) {
    p16e2_div_j((p16e2_t *) this, &lhs, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /=");
  }
  return (*this);
}

P16e2 P16e2::operator /(const P16e2 rhs){
  p16e2_t res;          //create a return value on the stack.
  if (set_nan_jmp()){
    p16e2_div(&res, (p16e2_t *) this, &rhs);
  } else {
    throw domain_error("NaN value obtained in operator /");
  }
  return res;
}


