const FULL_FNS = [:div, :mulinv, :log2, :exp2, :fma]#, :fms, :nfma, :nfms, :fas, :fcp, :fdp, :dpi]

const fmasig = Dict(:fma  => (n, es) -> " $(to_f(n,es,"*a")),  $(to_f(n,es,"*b")),  $(to_f(n,es, "*c"))",
                    :fms  => (n, es) -> " $(to_f(n,es,"*a")),  $(to_f(n,es,"*b")), -$(to_f(n,es, "*c"))",
                    :nfma => (n, es) -> "-$(to_f(n,es,"*a")), -$(to_f(n,es,"*b")), -$(to_f(n,es, "*c"))",
                    :nfms => (n, es) -> "-$(to_f(n,es,"*a")), -$(to_f(n,es,"*b")),  $(to_f(n,es, "*c"))")
doc"""
  z-counting functions for fused operations
"""
function zcounts()
  """
  static bool z_count_valid_float(float a, float b, float c){
    //convert a, b, and c to their respective integers
    uint32_t a_int = *((uint32_t *) &a);
    uint32_t b_int = *((uint32_t *) &b);
    uint32_t c_int = *((uint32_t *) &c);

    int64_t trailing_a = __builtin_ctz(a_int);
    int64_t trailing_b = __builtin_ctz(b_int);
    int64_t trailing_c = __builtin_ctz(c_int);

    return trailing_c == trailing_a + trailing_b - 23;
  }

  static bool z_count_valid_double(double a, double b, double c){
    //convert a, b, and c to their respective integers
    uint64_t a_int = *((uint64_t *) &a);
    uint64_t b_int = *((uint64_t *) &b);
    uint64_t c_int = *((uint64_t *) &c);

    int64_t trailing_a = __builtin_ctzl(a_int);
    int64_t trailing_b = __builtin_ctzl(b_int);
    int64_t trailing_c = __builtin_ctzl(c_int);

    return trailing_c == trailing_a + trailing_b - 52;
  }
  """
end


doc"""
  The skeleton of a unary operation, with adlibbable values
"""
function unop_fn(n::Integer ,es::Integer, op::Symbol, status::Bool)
  opfn = ops[op][status + 1]
  val = status ? "int" : p(n,es)
  arg = status ? "*a" : "a"
  err = status ? "return EDOM" : "throw_nan_jmp()"
  ret = status ? "res->udata = pres.udata; return 0" : "return pres"

"""
extern "C" $(opfn(n,es)) {
  $(p(n,es)) pres;
  int status = sanitize_$(op)\_$(n)(($arg).udata);
  switch (status){
   case 1: pres.udata = P$(n)ZER; $ret;
   case 2: pres.udata = P$(n)INF; $ret;
   case 3: $err;
  }

  $(ftype[n]) fres = $(op)($(to_f(n,es,arg)));
  pres = $(to_p(n,es,:fres));
  $ret;
}
"""
end

doc"""
  The skeleton of a ternary operation, with adlibbable values
"""
function terop_fn(n::Integer, es::Integer, op::Symbol, status::Bool)
  opfn = ops[op][status + 1]
  """
  $(opfn(n,es)){
    $(p(n,es)) result;
    //two ways to fail: add/sub of infinity or infinity times zero.  Both
    //require at least one of a and b to be infinity.
    if ((($a).udata == P$(n)INF) || (($b).udata == P$(n)INF)){
      if (($c).udata == P$(n)INF) { $quit; }
      result.udata = P$(n)INF;
      goto finish;
    }
    if ($c == P$(n)INF) { $retinf }  //or just be standard infinity if the adder is.

    //two ways to get zero:  one of the muliplicands is zero, add/sub is zero.
    if ((($a).udata == P$(n)ZER) || (($b).udata == P$(n)ZER))){
      if (($c).udata == P$(n)ZER) { result.udata = P$(n)ZER; goto finish;}
      //here we can quit early.
      result.udata = ($c).udata
    }

    //the other way to get zero is when the two values match exactly except for
    //sign

    $(ftype[n]) f_a, f_b, f_c;

    finish:
    $return;
  }
  """
end


const fulls_sanitizers = Dict(:div => (n) -> """
  static int sanitize_div_$(n)(uint$(n)_t lhs, uint$(n)_t rhs){
    if (lhs == P$(n)INF) {
      if (rhs == P$(n)INF) { return 3; }
      return 2;
    }
    if (lhs == P$(n)ZER) {
      if (rhs == P$(n)ZER) { return 3; }
      return 1;
    }
    if (rhs == P$(n)INF) { return 1; }
    if (rhs == P$(n)ZER) { return 2; }
    return 0;
  }
  """,
  :log2 => (n) -> """
  static int sanitize_log2_$(n)(uint$(n)_t arg){
    if (arg == P$(n)INF) { return 2; }
    if (arg == P$(n)ZER) { return 2; }
    if ((arg & P$(n)INF) != 0) { return 3; } //negative values are rejected
    return 0;
  }
  """,
  :exp2 => (n) -> """
  static int sanitize_exp2_$(n)(uint$(n)_t arg){
    if (arg == P$(n)INF) { return 3; }
    return 0;
  }
  """,)

const fulls_code = Dict(
  :div => (n, es) -> """
  $(binop_fn(n,es,:div,true))
  $(binop_fn(n,es,:div,false))
  """,
  :mulinv => (n, es) -> """
  extern "C" $(ops[:mulinv][1](n,es)) {
    $(ftype[n]) fres = $(to_f(n,es,:a));
    return $(to_p(n,es,"1/fres"));
  }

  extern "C" $(ops[:mulinv][2](n,es)) {
    $(p(n,es)) pres;
    $(ftype[n]) fres = $(to_f(n,es,"*a"));
    pres = $(to_p(n,es,"1/fres"));
    res->udata = pres.udata;
    return 0;
  }
  """,
  :log2 => (n, es) -> """
  $(unop_fn(n,es,:log2,true))
  $(unop_fn(n,es,:log2,false))
  """,
  :exp2 => (n, es) -> """
  $(unop_fn(n,es,:exp2,true))
  $(unop_fn(n,es,:exp2,false))
  """)


function generate_posit_full_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io,"""
  #include "include/posit.h"
  #include "include/posit_conv.h"
  #include <errno.h>
  """)
  #write(io, zcounts())
  write(io, "\n\n")


  for fn in FULL_FNS
    for n in sort(collect(keys(posit_defs)))

      sanitizer = haskey(fulls_sanitizers, fn) ? """
      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, $(fn) sanitizers
      ///////////////////////////////////////////////////////////////

      $(fulls_sanitizers[fn](n))
      """ : ""

      write(io, """
      $sanitizer

      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, variable ES adapters for $(fn)
      ///////////////////////////////////////////////////////////////
      """)

      for es in posit_defs[n]
        write(io, fulls_code[fn](n, es))
        write(io, "\n")
      end
    end
    write(io,"\n")
  end
end
