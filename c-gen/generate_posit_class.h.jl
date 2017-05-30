doc"""
  unlike the other files, generate_posit_class_h creates a separate file for
  each header file.
"""
function generate_posit_class_h(io, n, es)
  write(io, """
  #ifndef POSIT_$(n)_$(es)_H
  #define POSIT_$(n)_$(es)_H

  #include "posit.h"

  class $(c(n,es)){
    public:
      uint$(n)_t data;

      //various public constructors
      $(c(n,es))();             //defaults to zero
      $(c(n,es))(const float);        //conversion constructor from IEEE32
      $(c(n,es))(const double);       //conversion constructor from IEEE64
      $(c(n,es))(const $(c(n,es)) &); //copy constructor
      $(c(n,es))(const $(p(n,es)));   //bridge constructor from c functionality.

      //public operators
      $(c(n,es)) operator -();
      $(c(n,es)) operator +(const $(c(n,es)) rhs);
      $(c(n,es)) operator -(const $(c(n,es)) rhs);
      $(c(n,es)) operator *(const $(c(n,es)) rhs);
      $(c(n,es)) &operator +=(const $(c(n,es)) rhs);
      $(c(n,es)) &operator -=(const $(c(n,es)) rhs);
      $(c(n,es)) &operator *=(const $(c(n,es)) rhs);
      bool operator <(const $(c(n,es)) rhs);
      bool operator <=(const $(c(n,es)) rhs);
      bool operator >(const $(c(n,es)) rhs);
      bool operator >=(const $(c(n,es)) rhs);
      $(c(n,es)) operator /(const $(c(n,es)) rhs);
      $(c(n,es)) &operator /=(const $(c(n,es)) rhs);

      operator float();
      operator double();
      operator $(p(n,es))();
  };

  $(c(n,es)) mulinv(const $(c(n,es)) arg);
  $(c(n,es)) log2(const $(c(n,es)) arg);
  $(c(n,es)) exp2(const $(c(n,es)) arg);
  $(c(n,es)) fma(const $(c(n,es)) a, const $(c(n,es)) b, const $(c(n,es)) c);
  $(c(n,es)) fms(const $(c(n,es)) a, const $(c(n,es)) b, const $(c(n,es)) c);
  $(c(n,es)) nfma(const $(c(n,es)) a, const $(c(n,es)) b, const $(c(n,es)) c);
  $(c(n,es)) nfms(const $(c(n,es)) a, const $(c(n,es)) b, const $(c(n,es)) c);
  $(c(n,es)) sqrt(const $(c(n,es)) arg);
  $(c(n,es)) log1p(const $(c(n,es)) arg);
  $(c(n,es)) log(const $(c(n,es)) arg);
  $(c(n,es)) log10(const $(c(n,es)) arg);
  $(c(n,es)) exp(const $(c(n,es)) arg);
  $(c(n,es)) pow(const $(c(n,es)) lhs, const $(c(n,es)) rhs);
  $(c(n,es)) sin(const $(c(n,es)) arg);
  $(c(n,es)) cos(const $(c(n,es)) arg);
  $(c(n,es)) atan(const $(c(n,es)) arg);
  $(c(n,es)) atan2(const $(c(n,es)) y, const $(c(n,es)) x);

  #endif

  """)
end
