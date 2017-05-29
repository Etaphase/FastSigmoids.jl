#ifndef POSIT_16_1_H
#define POSIT_16_1_H

class P16e1{
  private:
    uint16_t data;
  public:

    //various public constructors
    P16e1();             //defaults to zero
    P16e1(float);        //conversion constructor from IEEE32
    P16e1(double);       //conversion constructor from IEEE64
    P16e1(P16e1);   //copy constructor
    P16e1(p16e1_t);   //bridge constructor from c functionality.

    //public operators
    P16e1 operator +(const P16e1 rhs);
    P16e1 operator -(const P16e1 rhs);
    P16e1 operator *(const P16e1 rhs);
    P16e1 &operator +=(const P16e1 rhs);
    P16e1 &operator -=(const P16e1 rhs);
    P16e1 &operator *=(const P16e1 rhs);
    bool operator <(const P16e1 rhs);
    bool operator <=(const P16e1 rhs);
    bool operator >(const P16e1 rhs);
    bool operator >=(const P16e1 rhs);
    P16e1 operator /(const P16e1 rhs);
    P16e1 &operator /=(const P16e1 rhs);

    //external friended operators
    friend P16e1 operator -(const P16e1 rhs);
    friend P16e1 operator float(const P16e1 rhs);
    friend P16e1 operator double(const P16e1 rhs);

    //friended functions
    friend P16e1 mulinv(const P16e1 arg);
    friend P16e1 log2(const P16e1 arg);
    friend P16e1 exp2(const P16e1 arg);
    friend P16e1 fma(const P16e1 a, const P16e1 b, const P16e1 c);
    friend P16e1 fms(const P16e1 a, const P16e1 b, const P16e1 c);
    friend P16e1 nfma(const P16e1 a, const P16e1 b, const P16e1 c);
    friend P16e1 nfms(const P16e1 a, const P16e1 b, const P16e1 c);
    friend P16e1 sqrt(const P16e1 arg);
    friend P16e1 log1p(const P16e1 arg);
    friend P16e1 log(const P16e1 arg);
    friend P16e1 log10(const P16e1 arg);
    friend P16e1 exp(const P16e1 arg);
    friend P16e1 pow(const P16e1 lhs, const P16e1 rhs);
    friend P16e1 sin(const P16e1 arg);
    friend P16e1 cos(const P16e1 arg);
    friend P16e1 atan(const P16e1 arg);
    friend P16e1 atan2(const P16e1 y, const P16e1 x);
}

//redeclaration of the functions that were just friended
P16e1 operator -(const P16e1 rhs);
P16e1 operator float(const P16e1 rhs);
P16e1 operator double(const P16e1 rhs);



P16e1 mulinv(const P16e1 arg);
P16e1 log2(const P16e1 arg);
P16e1 exp2(const P16e1 arg);
P16e1 fma(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 fms(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 nfma(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 nfms(const P16e1 a, const P16e1 b, const P16e1 c);
P16e1 sqrt(const P16e1 arg);
P16e1 log1p(const P16e1 arg);
P16e1 log(const P16e1 arg);
P16e1 log10(const P16e1 arg);
P16e1 exp(const P16e1 arg);
P16e1 pow(const P16e1 lhs, const P16e1 rhs);
P16e1 sin(const P16e1 arg);
P16e1 cos(const P16e1 arg);
P16e1 atan(const P16e1 arg);
P16e1 atan2(const P16e1 y, const P16e1 x);

#endif

