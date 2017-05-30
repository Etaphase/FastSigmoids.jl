const BASICS_FNS = [:add, :mul, :sub, :addinv, :lt, :lte, :gt, :gte]
const TPTR_TO_BINF = Dict(:add => "+", :mul => "*", :sub => "-", :div => "/")
const ftype = Dict(8 => :float, 16 => :float, 32 => :double)

doc"""
  The skeleton of a binary operation, with adlibbable values
"""
function binop_fn(n::Integer ,es::Integer, op::Symbol, status::Bool)
  opfn = ops[op][status + 1]

  #build up the assignment expression.  Start with the basics:  decide if the
  #main is going to be a C operator or a function call.
  fexpr = haskey(TPTR_TO_BINF, op) ? "$(to_f(n,es,:a)) $(TPTR_TO_BINF[op]) $(to_f(n,es,:b))" :
    "$(op)($(to_f(n,es,:a)), $(to_f(n,es,:b)))"

  #finally wrap it in a jump call detection if we're returning status_t.
  fexpr = status ? """
    $(ftype[n]) fres;
    if (set_nan_jmp()){
      fres = $fexpr;
    } else {
      return EDOM;
    }
  """ : "$(ftype[n]) fres = $(fexpr)"

  #generate the return statement, which depends on whether or not we're status or jump.
  ret = status ? "res->udata = pres.udata; return 0" : "return pres"

"""
extern "C" $(opfn(n,es)) {
  $(p(n,es)) pres;

  $(fexpr);

  pres = $(to_p(n,es,:fres));
  $ret;
}
"""
end

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
    res->udata = -(a.udata);
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

      write(io, """

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
