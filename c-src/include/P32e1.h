#ifndef POSIT_32_1_H
#define POSIT_32_1_H

#include "posit.h"

class P32e1{
  public:
    uint32_t data;

    //various public constructors
    P32e1();             //defaults to zero
    P32e1(const float);        //conversion constructor from IEEE32
    P32e1(const double);       //conversion constructor from IEEE64
    P32e1(const P32e1 &); //copy constructor
    P32e1(const p32e1_t);   //bridge constructor from c functionality.

    //public operators
    P32e1 operator -() const;
    P32e1 operator +(const P32e1 rhs) const;
    P32e1 operator -(const P32e1 rhs) const;
    P32e1 operator *(const P32e1 rhs) const;
    P32e1 &operator +=(const P32e1 rhs);
    P32e1 &operator -=(const P32e1 rhs);
    P32e1 &operator *=(const P32e1 rhs);
    bool operator <(const P32e1 rhs) const;
    bool operator <=(const P32e1 rhs) const;
    bool operator >(const P32e1 rhs) const;
    bool operator >=(const P32e1 rhs) const;
    P32e1 operator /(const P32e1 rhs) const;
    P32e1 &operator /=(const P32e1 rhs);

    operator float() const;
    operator double() const;
    operator p32e1_t() const;
};

P32e1 mulinv(const P32e1 arg);
P32e1 log2(const P32e1 arg);
P32e1 exp2(const P32e1 arg);
P32e1 fma(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 fms(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 nfma(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 nfms(const P32e1 a, const P32e1 b, const P32e1 c);
P32e1 sqrt(const P32e1 arg);
P32e1 log1p(const P32e1 arg);
P32e1 log(const P32e1 arg);
P32e1 log10(const P32e1 arg);
P32e1 exp(const P32e1 arg);
P32e1 pow(const P32e1 lhs, const P32e1 rhs);
P32e1 sin(const P32e1 arg);
P32e1 cos(const P32e1 arg);
P32e1 atan(const P32e1 arg);
P32e1 atan2(const P32e1 y, const P32e1 x);

#endif

