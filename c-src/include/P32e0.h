#ifndef POSIT_32_0_H
#define POSIT_32_0_H

#include "posit.h"

class P32e0{
  public:
    uint32_t data;

    //various public constructors
    P32e0();             //defaults to zero
    P32e0(const float);        //conversion constructor from IEEE32
    P32e0(const double);       //conversion constructor from IEEE64
    P32e0(const P32e0 &); //copy constructor
    P32e0(const p32e0_t);   //bridge constructor from c functionality.

    //public operators
    P32e0 operator -() const;
    P32e0 operator +(const P32e0 rhs) const;
    P32e0 operator -(const P32e0 rhs) const;
    P32e0 operator *(const P32e0 rhs) const;
    P32e0 &operator +=(const P32e0 rhs);
    P32e0 &operator -=(const P32e0 rhs);
    P32e0 &operator *=(const P32e0 rhs);
    bool operator <(const P32e0 rhs) const;
    bool operator <=(const P32e0 rhs) const;
    bool operator >(const P32e0 rhs) const;
    bool operator >=(const P32e0 rhs) const;
    P32e0 operator /(const P32e0 rhs) const;
    P32e0 &operator /=(const P32e0 rhs);

    operator float() const;
    operator double() const;
    operator p32e0_t() const;
};

P32e0 mulinv(const P32e0 arg);
P32e0 log2(const P32e0 arg);
P32e0 exp2(const P32e0 arg);
P32e0 fma(const P32e0 a, const P32e0 b, const P32e0 c);
P32e0 fms(const P32e0 a, const P32e0 b, const P32e0 c);
P32e0 nfma(const P32e0 a, const P32e0 b, const P32e0 c);
P32e0 nfms(const P32e0 a, const P32e0 b, const P32e0 c);
P32e0 sqrt(const P32e0 arg);
P32e0 log1p(const P32e0 arg);
P32e0 log(const P32e0 arg);
P32e0 log10(const P32e0 arg);
P32e0 exp(const P32e0 arg);
P32e0 pow(const P32e0 lhs, const P32e0 rhs);
P32e0 sin(const P32e0 arg);
P32e0 cos(const P32e0 arg);
P32e0 atan(const P32e0 arg);
P32e0 atan2(const P32e0 y, const P32e0 x);

#endif

