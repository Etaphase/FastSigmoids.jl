const BASICS_FNS = [:add, :mul, :sub, :addinv, :lt, :lte, :gt, :gte]
const TPTR_TO_BINF = Dict(:add => "+", :mul => "*", :sub => "-", :div => "/")
const ftype = Dict(8 => :float, 16 => :float, 32 => :double)

doc"""
  The skeleton of a binary operation, with adlibbable values
"""
function binop_fn(n::Integer ,es::Integer, op::Symbol, status::Bool)
  opfn = ops[op][status + 1]
  val = status ? "int" : p(n,es)
  lhs = status ? "*a" : "a"
  rhs = status ? "*b" : "b"
  err = status ? "return EDOM" : "throw_nan_jmp()"
  ret = status ? "res->udata = pres.udata; return 0" : "return pres"
  fexpr = haskey(TPTR_TO_BINF, op) ? "$(to_f(n,es,lhs)) $(TPTR_TO_BINF[op]) $(to_f(n,es,rhs))" :
    "$(op)($(to_f(n,es,lhs)), $(to_f(n,es,rhs)))"

"""
extern "C" $(opfn(n,es)) {
  $(p(n,es)) pres;
  int status = sanitize_$(op)\_$(n)(($lhs).udata, ($rhs).udata);
  switch (status){
   case 1: pres.udata = P$(n)ZER; $ret;
   case 2: pres.udata = P$(n)INF; $ret;
   case 3: $err;
  }

  $(ftype[n]) fres = $(fexpr);
  pres = $(to_p(n,es,:fres));
  $ret;
}
"""
end

const basics_sanitizer = Dict(:add => (n) -> """
  static int sanitize_add_$(n)(uint$(n)_t lhs, uint$(n)_t rhs){
    if (lhs == P$(n)INF) {
      if (rhs == P$(n)INF) { return 3; }
      return 2;
    }
    if (rhs == P$(n)INF) { return 2; }
    if (lhs == -rhs) { return 1; }
    return 0;
  }
  """, :sub => (n) -> """
  static int sanitize_sub_$(n)(uint$(n)_t lhs, uint$(n)_t rhs){
    if (lhs == P$(n)INF) {
      if (rhs == P$(n)INF) { return 3; }
      return 2;
    }
    if (rhs == P$(n)INF) { return 2; }
    if (lhs == -rhs) { return 1; }
    return 0;
  }
  """, :mul => (n) -> """
  static int sanitize_mul_$(n)(uint$(n)_t lhs, uint$(n)_t rhs){
    if (lhs == P$(n)ZER) {
      if (rhs == P$(n)INF) { return 3; }
      return 1;
    }
    if (rhs == P$(n)ZER) {
      if (lhs == P$(n)INF) { return 3; }
      return 1;
    }
    if (lhs == P$(n)INF) { return 2; }
    if (rhs == P$(n)INF) { return 2; }
    return 0;
  }
  """)

const basics_code = Dict(
  :add => (n, es) -> """
  $(binop_fn(n,es,:add,true))
  $(binop_fn(n,es,:add,false))
  """,

  :sub => (n, es) -> """
  $(binop_fn(n,es,:sub,true))
  $(binop_fn(n,es,:sub,false))
  """,

  :mul => (n, es) -> """
  $(binop_fn(n,es,:mul,true))
  $(binop_fn(n,es,:mul,false))
  """,

  :addinv => (n, es) -> """
  extern "C" $(ops[:addinv][1](n,es)) {
    $(p(n,es)) res;
    res.udata = -(a.udata);
    return res;
  }

  extern "C" $(ops[:addinv][2](n,es)) {
    res->udata = -(a->udata);
    return 0;
  }
  """,

  :lt => (n, es) -> """
  extern "C" $(ops[:lt][2](n,es)) {
    if (b.udata == P$(n)INF) { return true; }
    return (a.sdata < b.sdata);
  }
  """,

  :lte => (n, es) -> """
  extern "C" $(ops[:lte][2](n,es)) {
    if (b.udata == P$(n)INF) { return true; }
    return (a.sdata <= b.sdata);
  }
  """,

  :gt => (n, es) -> """
  extern "C" $(ops[:gt][2](n,es)) {
    if (a.udata == P$(n)INF) { return true; }
    return (a.sdata > b.sdata);
  }
  """,

  :gte => (n, es) -> """
  extern "C" $(ops[:gte][2](n,es)) {
    if (a.udata == P$(n)INF) { return true; }
    return (a.sdata >= b.sdata);
  }
  """)

function generate_posit_basics_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io,"""
  #include "include/posit.h"
  #include "include/posit_conv.h"
  #include <errno.h>
  """)

  for fn in BASICS_FNS
    for n in sort(collect(keys(posit_defs)))

      sanitizer = haskey(basics_sanitizer, fn) ? """
      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, $(fn) sanitizers
      ///////////////////////////////////////////////////////////////

      $(basics_sanitizer[fn](n))
      """ : ""

      write(io, """
      $sanitizer

      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, variable ES adapters for $(fn)
      ///////////////////////////////////////////////////////////////
      """)

      for es in posit_defs[n]
        write(io, basics_code[fn](n, es))
        write(io, "\n")
      end
    end
    write(io,"\n")
  end
end
