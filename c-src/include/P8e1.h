#ifndef POSIT_8_1_H
#define POSIT_8_1_H

#include "posit.h"

class P8e1{
  public:
    uint8_t data;

    //various public constructors
    P8e1();             //defaults to zero
    P8e1(const float);        //conversion constructor from IEEE32
    P8e1(const double);       //conversion constructor from IEEE64
    P8e1(const P8e1 &); //copy constructor
    P8e1(const p8e1_t);   //bridge constructor from c functionality.

    //public operators
    P8e1 operator -() const;
    P8e1 operator +(const P8e1 rhs) const;
    P8e1 operator -(const P8e1 rhs) const;
    P8e1 operator *(const P8e1 rhs) const;
    P8e1 &operator +=(const P8e1 rhs);
    P8e1 &operator -=(const P8e1 rhs);
    P8e1 &operator *=(const P8e1 rhs);
    bool operator <(const P8e1 rhs) const;
    bool operator <=(const P8e1 rhs) const;
    bool operator >(const P8e1 rhs) const;
    bool operator >=(const P8e1 rhs) const;
    bool operator ==(const P8e1 rhs) const;
    P8e1 operator /(const P8e1 rhs) const;
    P8e1 &operator /=(const P8e1 rhs);

    operator float() const;
    operator double() const;
    operator p8e1_t() const;
};

bool isequal(const P8e1 a, const P8e1 b);
P8e1 mulinv(const P8e1 arg);
P8e1 log2(const P8e1 arg);
P8e1 exp2(const P8e1 arg);
P8e1 fma(const P8e1 a, const P8e1 b, const P8e1 c);
P8e1 fms(const P8e1 a, const P8e1 b, const P8e1 c);
P8e1 nfma(const P8e1 a, const P8e1 b, const P8e1 c);
P8e1 nfms(const P8e1 a, const P8e1 b, const P8e1 c);
P8e1 sqrt(const P8e1 arg);
P8e1 log1p(const P8e1 arg);
P8e1 log(const P8e1 arg);
P8e1 log10(const P8e1 arg);
P8e1 exp(const P8e1 arg);
P8e1 pow(const P8e1 lhs, const P8e1 rhs);
P8e1 sin(const P8e1 arg);
P8e1 cos(const P8e1 arg);
P8e1 atan(const P8e1 arg);
P8e1 atan2(const P8e1 y, const P8e1 x);

#endif

