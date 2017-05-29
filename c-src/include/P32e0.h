#ifndef POSIT_32_0_H
#define POSIT_32_0_H

class P32e0{
  private:
    uint32_t data;
  public:

    //various public constructors
    P32e0();             //defaults to zero
    P32e0(float);        //conversion constructor from IEEE32
    P32e0(double);       //conversion constructor from IEEE64
    P32e0(P32e0);   //copy constructor
    P32e0(p32e0_t);   //bridge constructor from c functionality.

    //public operators
    P32e0 operator +(const P32e0 rhs);
    P32e0 operator -(const P32e0 rhs);
    P32e0 operator *(const P32e0 rhs);
    P32e0 &operator +=(const P32e0 rhs);
    P32e0 &operator -=(const P32e0 rhs);
    P32e0 &operator *=(const P32e0 rhs);
    bool operator <(const P32e0 rhs);
    bool operator <=(const P32e0 rhs);
    bool operator >(const P32e0 rhs);
    bool operator >=(const P32e0 rhs);
    P32e0 operator /(const P32e0 rhs);
    P32e0 &operator /=(const P32e0 rhs);

    //external friended operators
    friend P32e0 operator -(const P32e0 rhs);
    friend P32e0 operator float(const P32e0 rhs);
    friend P32e0 operator double(const P32e0 rhs);

    //friended functions
    friend P32e0 mulinv(const P32e0 arg);
    friend P32e0 log2(const P32e0 arg);
    friend P32e0 exp2(const P32e0 arg);
    friend P32e0 fma(const P32e0 a, const P32e0 b, const P32e0 c);
    friend P32e0 fms(const P32e0 a, const P32e0 b, const P32e0 c);
    friend P32e0 nfma(const P32e0 a, const P32e0 b, const P32e0 c);
    friend P32e0 nfms(const P32e0 a, const P32e0 b, const P32e0 c);
    friend P32e0 sqrt(const P32e0 arg);
    friend P32e0 log1p(const P32e0 arg);
    friend P32e0 log(const P32e0 arg);
    friend P32e0 log10(const P32e0 arg);
    friend P32e0 exp(const P32e0 arg);
    friend P32e0 pow(const P32e0 lhs, const P32e0 rhs);
    friend P32e0 sin(const P32e0 arg);
    friend P32e0 cos(const P32e0 arg);
    friend P32e0 atan(const P32e0 arg);
    friend P32e0 atan2(const P32e0 y, const P32e0 x);
}

//redeclaration of the functions that were just friended
P32e0 operator -(const P32e0 rhs);
P32e0 operator float(const P32e0 rhs);
P32e0 operator double(const P32e0 rhs);



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

