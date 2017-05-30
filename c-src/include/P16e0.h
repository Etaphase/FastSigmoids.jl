#ifndef POSIT_16_0_H
#define POSIT_16_0_H

#include "posit.h"

class P16e0{
  public:
    uint16_t data;

    //various public constructors
    P16e0();             //defaults to zero
    P16e0(const float);        //conversion constructor from IEEE32
    P16e0(const double);       //conversion constructor from IEEE64
    P16e0(const P16e0 &); //copy constructor
    P16e0(const p16e0_t);   //bridge constructor from c functionality.

    //public operators
    P16e0 operator -();
    P16e0 operator +(const P16e0 rhs);
    P16e0 operator -(const P16e0 rhs);
    P16e0 operator *(const P16e0 rhs);
    P16e0 &operator +=(const P16e0 rhs);
    P16e0 &operator -=(const P16e0 rhs);
    P16e0 &operator *=(const P16e0 rhs);
    bool operator <(const P16e0 rhs);
    bool operator <=(const P16e0 rhs);
    bool operator >(const P16e0 rhs);
    bool operator >=(const P16e0 rhs);
    P16e0 operator /(const P16e0 rhs);
    P16e0 &operator /=(const P16e0 rhs);

    operator float();
    operator double();
    operator p16e0_t();
};

P16e0 mulinv(const P16e0 arg);
P16e0 log2(const P16e0 arg);
P16e0 exp2(const P16e0 arg);
P16e0 fma(const P16e0 a, const P16e0 b, const P16e0 c);
P16e0 fms(const P16e0 a, const P16e0 b, const P16e0 c);
P16e0 nfma(const P16e0 a, const P16e0 b, const P16e0 c);
P16e0 nfms(const P16e0 a, const P16e0 b, const P16e0 c);
P16e0 sqrt(const P16e0 arg);
P16e0 log1p(const P16e0 arg);
P16e0 log(const P16e0 arg);
P16e0 log10(const P16e0 arg);
P16e0 exp(const P16e0 arg);
P16e0 pow(const P16e0 lhs, const P16e0 rhs);
P16e0 sin(const P16e0 arg);
P16e0 cos(const P16e0 arg);
P16e0 atan(const P16e0 arg);
P16e0 atan2(const P16e0 y, const P16e0 x);

#endif

