FastSigmoid
===========

FastSigmoid-c
=============

FastSigmoid-c is a hybrid C/C++ library for the deployment of posit numerical
types.  By default, it implements the following posit environments:

* Posit{8,0}
* Posit{8,1}
* Posit{8,2}
* Posit{16,0}
* Posit{16,1}
* Posit{16,2}
* Posit{32,0}
* Posit{32,1}
* Posit{32,2}
* Posit{32,3}

Support for 64- bit environments is forthcoming.  You may generate a custom C
library by importing the cgen spec in julia and generating a library as follows:

```julia
julia> include("cgen.jl")

julia> generate_fastsigmoid_c_library(Dict(8=>[0,1,2],16=>[0,1,2],32=>[0,1,2,3]))
```

If you have a suitable C compiler, this will automatically compile libfastposit.so
into the ./c-src library.  The companion libfastvalid.so library is forthcoming.  You
may also enter the ./c-src library and execute make to generate libfastposit.so.

USING C FUNCTIONS
-----------------

FastSigmoid-c implements C types of the form p(N)e(ES)\_t.  These correspond to
Posit{N,ES}.  For example, p16e2_t represents Posit{16,2}.  To use these types,
`#include "posit.h"`

**Conversions** are implemented as the functions f_to_p(N)e(ES) and
p(N)e(ES)\_to_f.  Note that Posit{32,X} converts to double instead of float.
To use these functions `#include "posit_conv.h"`
Example functions:
```
  float p16e2_to_f(p16e2_t);
  double p32e1_to_f(p32e1_t);

  p16e1_t f_to_p16e1(float);
  p32e2_t f_to_p32e2(double);
```

**Functions** are implemented as p(N)e(ES)\_(fun).  For example, p16e2_add is the
addition function over Posit{16,2}.  Under the hood, these functions wrap
conversion of the posit to the smallest IEEE floating point form, evaulation
using standard hardware, followed by conversion back to the posit form.

To use this these functions `#include "posit_ops.h"`

Supported functions (described as p32e2_t but implemented for all types):

* `status_t p32e2_add(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`          **res <- lhs + rhs**
* `status_t p32e2_sub(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`          **res <- lhs - rhs**
* `status_t p32e2_mul(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`          **res <- lhs * rhs**
* `status_t p32e2_addinv(p32e2_t *res, p32e2_t *arg)`                     **res <- -arg**
* `bool p32e2_lt(p32e2_t lhs, p32e2_t rhs)`                               **==> lhs < rhs**
* `bool p32e2_lte(p32e2_t lhs, p32e2_t rhs)`                              **==> lhs <= rhs**
* `status_t p32e2_div(p32e2_t *res, p32e2_t *lhs, p32e2_t *rhs)`          **res <- lhs / rhs**
* `status_t p32e2_mulinv(p32e2_t *res, p32e2_t *arg)`                     **res <- 1/arg**
* `status_t p32e2_log2(p32e2_t *res, p32e2_t *arg)`                       **res <- log2(arg)**
* `status_t p32e2_exp2(p32e2_t *res, p32e2_t *arg)`                       **res <- 2^(arg)**
* `status_t p32e2_fma(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c)`  **res <- a * b + c**
* `status_t p32e2_fms(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c)`  **res <- a * b - c**
* `status_t p32e2_nfma(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c)` **res <- -(a * b) + c**
* `status_t p32e2_nfms(p32e2_t *res, p32e2_t *a, p32e2_t *b, p32e2_t *c)` **res <- -(a * b) - c**
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `status_t p32e2_sqrt(p32e2_t *res p32e2_t *arg)`                        **res <- sqrt(arg)**
* `status_t p32e2_log1p(p32e2_t *res p32e2_t *arg)`                       **res <- ln(arg + 1)**
* `status_t p32e2_log(p32e2_t *res p32e2_t *arg)`                         **res <- ln(arg)**
* `status_t p32e2_log10(p32e2_t *res p32e2_t *arg)`                       **res <- log10(arg)**
* `status_t p32e2_exp(p32e2_t *res p32e2_t *arg)`                         **res <- e^(arg)**
* `status_t p32e2_pow(p32e2_t *res p32e2_t *lhs, p32e2_t *rhs)`           **res <- (lhs)^(rhs)**
* `status_t p32e2_logx(p32e2_t *res p32e2_t *lhs, p32e2_t *rhs)`          **res <- log_lhs(rhs)**
* `status_t p32e2_sin(p32e2_t *res p32e2_t *arg)`                         **res <- sin(arg)**
* `status_t p32e2_cos(p32e2_t *res p32e2_t *arg)`                         **res <- cos(arg)**
* `status_t p32e2_atan(p32e2_t *res p32e2_t *arg)`                        **res <- atan(arg)**
* `status_t p32e2_atan2(p32e2_t *res p32e2_t *y, p32e2_t *x)`             **res <- atan(y/x)**

_italic_ functions are not currently implemented.

**NaN Exceptions** are implemented by returning EDOM (33) as a status_t value for all
functions which return a status_t.  Functions which do not return status_t are
well-defined over all possible inputs.  If you prefer using setjmp/longjmp error
handling, the following functions are defined which will pass control to the jump
point defined by the function `set_nan_jmp()`.  To use these functions, `#include "posit_ops_status.h"`

* `p32e2_t p32e2_add_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_sub_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_mul_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_addinv_j(p32e2_t arg)`
* `p32e2_t p32e2_div_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_mulinv_j(p32e2_t arg)`
* `p32e2_t p32e2_log2_j(p32e2_t arg)`
* `p32e2_t p32e2_exp2_j(p32e2_t arg)`
* `p32e2_t p32e2_fma_j(p32e2_t a, p32e2_t b, p32e2_t c)`
* `p32e2_t p32e2_fms_j(p32e2_t a, p32e2_t b, p32e2_t c)`
* `p32e2_t p32e2_nfma_j(p32e2_t a, p32e2_t b, p32e2_t c)`
* `p32e2_t p32e2_nfms_j(p32e2_t a, p32e2_t b, p32e2_t c)`
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* `p32e2_t p32e2_sqrt_j(p32e2_t arg)`
* `p32e2_t p32e2_log1p_j(p32e2_t arg)`
* `p32e2_t p32e2_log_j(p32e2_t arg)`
* `p32e2_t p32e2_log10_j(p32e2_t arg)`
* `p32e2_t p32e2_exp_j(p32e2_t arg)`
* `p32e2_t p32e2_pow_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_logx_j(p32e2_t lhs, p32e2_t rhs)`
* `p32e2_t p32e2_sin_j(p32e2_t arg)`               
* `p32e2_t p32e2_cos_j(p32e2_t arg)`               
* `p32e2_t p32e2_atan_j(p32e2_t arg)`
* `p32e2_t p32e2_atan2_j(p32e2_t y, p32e2_t x)`

USING C++ CLASSES
-----------------

The posit data type is also implemented as C++ classes.  These classes are given
the labels p(N)e(ES).  The classes are available when you `#include "posit.hpp"`
To use these functions, `#include "posit_ops.hpp"`.  The following functions are
functionally overloaded to support all posit classes:

* `p32e2 mulinv(p32e2 arg)`                    **==> 1/arg**
* `p32e2 log2(p32e2 arg)`                      **==> log2(arg)**
* `p32e2 exp2(p32e2 arg)`                      **==> 2^(arg)**
* `p32e2 fma(p32e2 a, p32e2_t b, p32e2_t c)`   **==> a * b + c**
* `p32e2 fms(p32e2 a, p32e2_t b, p32e2_t c)`   **==> a * b - c**
* `p32e2 nfma(p32e2 a, p32e2_t b, p32e2_t c)`  **==> -(a * b) + c**
* `p32e2 nfms(p32e2 a, p32e2_t b, p32e2_t c)`  **==> -(a * b) - c**
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `p32e2 sqrt(p32e2 arg)`                      **==> sqrt(arg)**
* `p32e2 log1p(p32e2 arg)`                     **==> ln(arg + 1)**
* `p32e2 log(p32e2 arg)`                       **==> ln(arg)**
* `p32e2 log10(p32e2 arg)`                     **==> log10(arg)**
* `p32e2 exp(p32e2 arg)`                       **==> e^(arg)**
* `p32e2 pow(p32e2 lhs, p32e2_t rhs)`          **==> (lhs)^(rhs)**
* `p32e2 logx(p32e2 lhs, p32e2_t rhs)`         **==> log_lhs(rhs)**
* `p32e2 sin(p32e2 arg)`                       **==> sin(arg)**
* `p32e2 cos(p32e2 arg)`                       **==> cos(arg)**
* `p32e2 atan (p32e2 arg)`                     **==> atan(arg)**
* `p32e2 atan2(p32e2 y, p32e2_t x)`            **==> atan(y/x)**

The following operators are overloaded for all posit classes:

* `p32e2 operator +(p32e2 lhs, p32e2 rhs)`     **==> lhs + rhs**
* `p32e2 operator -(p32e2 lhs, p32e2 rhs)`     **==> lhs - rhs**
* `p32e2 operator *(p32e2 lhs, p32e2 rhs)`     **==> lhs * rhs**
* `p32e2 operator -(p32e2 arg)`                **==> -arg**
* `bool operator <(p32e2 lhs, p32e2 rhs)`      **==> lhs < rhs**
* `bool operator <=(p32e2 lhs, p32e2 rhs)`     **==> lhs <= rhs**
* `p32e2 operator /(p32e2 lhs, p32e2 rhs)`     **==> lhs / rhs**

**NaN Exceptions** are implemented for the C++ library by throwing a
domain_error object.  These should be caught using an outside try/catch block.
