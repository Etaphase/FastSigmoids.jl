FastSigmoid
===========

This is a hybrid julia/C/C++ package which implements sigmoid numbers (aka Type III unums), backed by
IEEE floating point.  This is in contrast to [http://github.com/interplanetary-robot/SigmoidNumbers.jl]
which implements it as strictly binary operations.  This library has been rigorously
validated in templated C++ libraries for scientific applications.  Supports
8, 16, and 32-bit operations.  64-bit operations are forthcoming.

Installation (julia)
--------------------

1.   Download Julia (currently, must be version 0.5.x)
2.   Enter the Julia repl.
3.   `Pkg.clone("git://github.com/Etaphase/FastSigmoids.jl.git", "FastSigmoid")`

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

Support for 64- bit environments is forthcoming.

NB:  The C portion of the library is comprehensively validated using Julia.
basic operations in Posit{8,N} are exhaustively tested and basic operations in
Posit{16,N} and Posit{32,N} are subjected to broad scope random testing.

### Building the default library (does not require Julia)

Enter the `./c-src` library.  Execute the following commands to generate libfastposit.so.
The default installation location is `/usr/lib` - if you'd like it elsewhere,
simply copy it to the desired location after executing `make build`.

```bash
> make clean
> make build
> sudo make install      #optional
> make test              #optional
```

### Generating Custom libraries (requires Julia)

A custom library can implement changes to the code or pared down to only include
desired posit environments, or expanded to support wider posit environments. You
may regenerate the C library by entering the c-gen directory and spinning up
julia and executing the following command:

```julia
julia> include("cgen.jl")
```

Any changes made to the julia library-generating scripts will then be manifested in
the `./c-src` directory.  If you would subsequently like to create a different
set of supported posit environments, execute the following function, passing a
suitable dictionary of N/ES values.

```julia
julia> generate_fastsigmoid_c_library(Dict(8=>[0,1,2],16=>[0,1,2],32=>[0,1,2,3]))
```

OPERATION MODES IN C
--------------------

this library supports two operational mode settings, underflow mode and NaN mode.
You may set the operational modes using the following functions:

```c
  extern "C" set_nanmode(bool);
  extern "C" set_underflow(bool);
```

### Underflow Mode

When in underflow mode, rounding to zero is supported.  Pending review with some
mathematical tests, we recommend underflow mode for:

* functions which are PDFs (integrals over ℝ must be bounded)
* vector valued operations (where the "sacred" value is a multidimensional zero)

we recommend non-underflowing mode for:

* functions which are CDFs (no zone should have zero probability)
* scalar-valued functions where zero has a special meaning (e.g. log, cot)
* dot products of vector values using exact accumulators.

The default is non-underflowing.  A full list of recommended uses is a desired
area of future research.

### NaN mode

see: [https://github.com/interplanetary-robot/SigmoidNumbers/blob/master/NaNmode.md]

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

* `int p32e2_add(p32e2_t *res, const p32e2_t lhs, const p32e2_t rhs)`               **res <- lhs + rhs**
* `int p32e2_sub(p32e2_t *res, const p32e2_t lhs, const p32e2_t rhs)`               **res <- lhs - rhs**
* `int p32e2_mul(p32e2_t *res, const p32e2_t lhs, const p32e2_t rhs)`               **res <- lhs * rhs**
* `int p32e2_addinv(p32e2_t *res, const p32e2_t arg)`                               **res <- -arg**
* `bool p32e2_lt(const p32e2_t lhs, const p32e2_t rhs)`                             **==> lhs < rhs**
* `bool p32e2_lte(const p32e2_t lhs, const p32e2_t rhs)`                            **==> lhs <= rhs**
* `bool p32e2_gt(const p32e2_t lhs, const p32e2_t rhs)`                             **==> lhs > rhs**
* `bool p32e2_gte(const p32e2_t lhs, const p32e2_t rhs)`                            **==> lhs >= rhs**
* `bool p32e2_eq(const p32e2_t lhs, const p32e2_t rhs)`                             **==> lhs == rhs**
* `int p32e2_div(p32e2_t *res, p32e2_t lhs, p32e2_t rhs)`                           **res <- lhs / rhs**
* `int p32e2_mulinv(p32e2_t *res, const p32e2_t arg)`                               **res <- 1/arg**
* `int p32e2_log2(p32e2_t *res, const p32e2_t arg)`                                 **res <- log2(arg)**
* `int p32e2_exp2(p32e2_t *res, const p32e2_t arg)`                                 **res <- 2^(arg)**
* `int p32e2_fma(p32e2_t *res, const p32e2_t a, const p32e2_t b, const p32e2_t c)`  **res <- a * b + c**
* `int p32e2_fms(p32e2_t *res, const p32e2_t a, const p32e2_t b, const p32e2_t c)`  **res <- a * b - c**
* `int p32e2_nfma(p32e2_t *res, const p32e2_t a, const p32e2_t b, const p32e2_t c)` **res <- -(a * b) + c**
* `int p32e2_nfms(p32e2_t *res, const p32e2_t a, const p32e2_t b, const p32e2_t c)` **res <- -(a * b) - c**
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `int p32e2_sqrt(p32e2_t *res, const p32e2_t arg)`                        **res <- sqrt(arg)**
* `int p32e2_log1p(p32e2_t *res, const p32e2_t arg)`                       **res <- ln(arg + 1)**
* `int p32e2_log(p32e2_t *res2, const p32e2_t arg)`                         **res <- ln(arg)**
* `int p32e2_log10(p32e2_t *res, const p32e2_t arg)`                       **res <- log10(arg)**
* `int p32e2_exp(p32e2_t *res, const p32e2_t arg)`                         **res <- e^(arg)**
* `int p32e2_pow(p32e2_t *res, const p32e2_t lhs, const p32e2_t rhs)`           **res <- (lhs)^(rhs)**
* logx    - _logarithm, arbitrary base_
* `int p32e2_sin(p32e2_t *res, const p32e2_t arg)`                         **res <- sin(arg)**
* `int p32e2_cos(p32e2_t *res, const p32e2_t arg)`                         **res <- cos(arg)**
* `int p32e2_atan(p32e2_t *res, const p32e2_t arg)`                        **res <- atan(arg)**
* `int p32e2_atan2(p32e2_t *res, const p32e2_t y, const p32e2_t x)`             **res <- atan(y/x)**

_italic_ functions are not currently implemented.

**NaN Exceptions** are implemented by returning EDOM (33) as a int value for all
functions which return a int.  Functions which do not return int are
well-defined over all possible inputs.  If you prefer being able to chain
functions instead of mutating the first argument, the following functions are
defined which will instead report errors by placing them i nto the global errno
variable.

* `p32e2_t p32e2_add_e(const p32e2_t lhs, const p32e2_t rhs)`
* `p32e2_t p32e2_sub_e(const p32e2_t lhs, const p32e2_t rhs)`
* `p32e2_t p32e2_mul_e(const p32e2_t lhs, const p32e2_t rhs)`
* `p32e2_t p32e2_addinv_e(const p32e2_t arg)`
* `p32e2_t p32e2_div_e(const p32e2_t lhs, const p32e2_t rhs)`
* `p32e2_t p32e2_mulinv_e(const p32e2_t arg)`
* `p32e2_t p32e2_log2_e(const p32e2_t arg)`
* `p32e2_t p32e2_exp2_e(const p32e2_t arg)`
* `p32e2_t p32e2_fma_e(const p32e2_t a, const p32e2_t b, const p32e2_t c)`
* `p32e2_t p32e2_fms_e(const p32e2_t a, const p32e2_t b, const p32e2_t c)`
* `p32e2_t p32e2_nfma_e(const p32e2_t a, const p32e2_t b, const p32e2_t c)`
* `p32e2_t p32e2_nfms_e(const p32e2_t a, const p32e2_t b, const p32e2_t c)`
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* `p32e2_t p32e2_sqrt_e(const p32e2_t arg)`
* `p32e2_t p32e2_log1p_e(const p32e2_t arg)`
* `p32e2_t p32e2_log_e(const p32e2_t arg)`
* `p32e2_t p32e2_log10_e(const p32e2_t arg)`
* `p32e2_t p32e2_exp_e(const p32e2_t arg)`
* `p32e2_t p32e2_pow_e(const p32e2_t lhs, const p32e2_t rhs)`
* logx    - _arbitrary base logarithm_
* `p32e2_t p32e2_sin_e(const p32e2_t arg)`               
* `p32e2_t p32e2_cos_e(const p32e2_t arg)`               
* `p32e2_t p32e2_atan_e(const p32e2_t arg)`
* `p32e2_t p32e2_atan2_e(const p32e2_t y, const p32e2_t x)`

USING C++ CLASSES
-----------------

The posit data type is also implemented as C++ classes.  These classes are given
the labels P(N)e(ES).  If you wish to access the binary form of the posit, there
is a public class member variable `data` which contains this information; it is
of uint(n)\_t type.  These classes are available when you `#include "P32e3.h"`
as an example, (substitute N and ES accordingly).  The following functions are
functionally overloaded to support all posit classes:

* `P32e2 mulinv(const P32e2 arg)`                    **==> 1/arg**
* `P32e2 log2(const P32e2 arg)`                      **==> log2(arg)**
* `P32e2 exp2(const P32e2 arg)`                      **==> 2^(arg)**
* `P32e2 fma(const P32e2 a, const P32e2 b, const P32e2 c)`   **==> a * b + c**
* `P32e2 fms(const P32e2 a, const P32e2 b, const P32e2 c)`   **==> a * b - c**
* `P32e2 nfma(const P32e2 a, const P32e2 b, const P32e2 c)`  **==> -(a * b) + c**
* `P32e2 nfms(const P32e2 a, const P32e2 b, const P32e2 c)`  **==> -(a * b) - c**
* fas     - _fused add/scale_
* fcp     - _fused cross product_
* fdp     - _fused dot product_
* dpi     - _initialize dot product accumulator_
* `bool isequal(const P32e2 a, const P32e2 b)`       **==> a === b** 
* `P32e2 sqrt(const P32e2 arg)`                      **==> sqrt(arg)**
* `P32e2 log1p(const P32e2 arg)`                     **==> ln(arg + 1)**
* `P32e2 log(const P32e2 arg)`                       **==> ln(arg)**
* `P32e2 log10(const P32e2 arg)`                     **==> log10(arg)**
* `P32e2 exp(const P32e2 arg)`                       **==> e^(arg)**
* `P32e2 pow(const P32e2 lhs, const P32e2 rhs)`            **==> (lhs)^(rhs)**
* logx    - _arbitrary base logarithm_
* `P32e2 sin(const P32e2 arg)`                       **==> sin(arg)**
* `P32e2 cos(const P32e2 arg)`                       **==> cos(arg)**
* `P32e2 atan (const P32e2 arg)`                     **==> atan(arg)**
* `P32e2 atan2(const P32e2 y, const P32e2 x)`              **==> atan(y/x)**

The following class operators are overloaded for all posit classes:

* `P32e2 operator -()`                               **==> -this**
* `P32e2 operator +(const P32e2 rhs)`                **==> this + rhs**
* `P32e2 operator -(const P32e2 rhs)`                **==> this - rhs**
* `P32e2 operator *(const P32e2 rhs)`                **==> this * rhs**
* `P32e2 &operator +=(const P32e2 rhs)`              **==> this += rhs**
* `P32e2 &operator -=(const P32e2 rhs)`              **==> this -= rhs**
* `P32e2 &operator *=(const P32e2 rhs)`              **==> this *= rhs**
* `bool operator <(const P32e2 rhs)`                 **==> this < rhs**
* `bool operator <=(const P32e2 rhs)`                **==> this <= rhs**
* `bool operator >(const P32e2 rhs)`                 **==> this > rhs**
* `bool operator >=(const P32e2 rhs)`                **==> this >= rhs**
* `bool operator ==(const P32e2 rhs)`                **==> this == rhs**
* `P32e2 operator /(const P32e2 rhs)`                **==> this / rhs**
* `P32e2 &operator /=(const P32e2 rhs)`              **==> this /= rhs**

The following class conversions are overloaded for all posit classes:

* `operator float()`
* `operator double()`
* `operator p32_e2_t()`

**NaN Exceptions** are implemented for the C++ library by throwing a
domain_error object.  These should be caught using an outside try/catch block.


FastSigmoid library is a part of the uDESIGN project
and is supported by DARPA grant HR0011-17-9-0007 awarded to Etaphase, inc.
