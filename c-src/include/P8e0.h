#ifndef POSIT_8_0_H
#define POSIT_8_0_H

class P8e0{
  private:
    uint8_t data;
  public:

    //various public constructors
    P8e0();             //defaults to zero
    P8e0(float);        //conversion constructor from IEEE32
    P8e0(double);       //conversion constructor from IEEE64
    P8e0(P8e0);   //copy constructor
    P8e0(p8e0_t);   //bridge constructor from c functionality.

    //public operators
    P8e0 operator +(const P8e0 rhs);
    P8e0 operator -(const P8e0 rhs);
    P8e0 operator *(const P8e0 rhs);
    P8e0 &operator +=(const P8e0 rhs);
    P8e0 &operator -=(const P8e0 rhs);
    P8e0 &operator *=(const P8e0 rhs);
    bool operator <(const P8e0 rhs);
    bool operator <=(const P8e0 rhs);
    bool operator >(const P8e0 rhs);
    bool operator >=(const P8e0 rhs);
    P8e0 operator /(const P8e0 rhs);
    P8e0 &operator /=(const P8e0 rhs);

    //external friended operators
    friend P8e0 operator -(const P8e0 rhs);
    friend P8e0 operator float(const P8e0 rhs);
    friend P8e0 operator double(const P8e0 rhs);

    //friended functions
    friend P8e0 mulinv(const P8e0 arg);
    friend P8e0 log2(const P8e0 arg);
    friend P8e0 exp2(const P8e0 arg);
    friend P8e0 fma(const P8e0 a, const P8e0 b, const P8e0 c);
    friend P8e0 fms(const P8e0 a, const P8e0 b, const P8e0 c);
    friend P8e0 nfma(const P8e0 a, const P8e0 b, const P8e0 c);
    friend P8e0 nfms(const P8e0 a, const P8e0 b, const P8e0 c);
    friend P8e0 sqrt(const P8e0 arg);
    friend P8e0 log1p(const P8e0 arg);
    friend P8e0 log(const P8e0 arg);
    friend P8e0 log10(const P8e0 arg);
    friend P8e0 exp(const P8e0 arg);
    friend P8e0 pow(const P8e0 lhs, const P8e0 rhs);
    friend P8e0 sin(const P8e0 arg);
    friend P8e0 cos(const P8e0 arg);
    friend P8e0 atan(const P8e0 arg);
    friend P8e0 atan2(const P8e0 y, const P8e0 x);
}

//redeclaration of the functions that were just friended
P8e0 operator -(const P8e0 rhs);
P8e0 operator float(const P8e0 rhs);
P8e0 operator double(const P8e0 rhs);



P8e0 mulinv(const P8e0 arg);
P8e0 log2(const P8e0 arg);
P8e0 exp2(const P8e0 arg);
P8e0 fma(const P8e0 a, const P8e0 b, const P8e0 c);
P8e0 fms(const P8e0 a, const P8e0 b, const P8e0 c);
P8e0 nfma(const P8e0 a, const P8e0 b, const P8e0 c);
P8e0 nfms(const P8e0 a, const P8e0 b, const P8e0 c);
P8e0 sqrt(const P8e0 arg);
P8e0 log1p(const P8e0 arg);
P8e0 log(const P8e0 arg);
P8e0 log10(const P8e0 arg);
P8e0 exp(const P8e0 arg);
P8e0 pow(const P8e0 lhs, const P8e0 rhs);
P8e0 sin(const P8e0 arg);
P8e0 cos(const P8e0 arg);
P8e0 atan(const P8e0 arg);
P8e0 atan2(const P8e0 y, const P8e0 x);

#endif

