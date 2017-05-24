const BASICS_FNS = [:add, :mul, :sub, :addinv, :lt, :lte]
const TPTR_TO_BINF = Dict(:add => "+", :mul => "*", :sub => "-", :div => "/")
const UNV_TO_UNF = Dict(:addinv => "-")
const BOOLF = Dict(:lt => "<", :lte => "<=")
#=
function basics_output(op::Symbol, n::Integer, es::Integer)
  headerfn = ops[op]
  ftype = ((n == 8) || (n == 16)) ? "float" : "double"
  if (op == :add || op == :sub)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{
    bool lhs_inf = (lhs->udata == P$(n)INF);
    bool rhs_inf = (rhs->udata == P$(n)INF);

    if (lhs_inf || rhs_inf) {
      if (lhs_inf && rhs_inf) { throw_nan_jmp(); }
      res->udata = P$(n)INF;
      return;
    }

    //throw or long jump with the global NaNJump on addition of two infinities.

    $(ftype) fres = $(to_f(n,es,"*lhs")) $(binf) $(to_f(n,es,"*rhs"));

    //check to see if we became infinity.
    if (!isfinite(fres)){
      //turn it into infinity.
      if (lhs_inf || rhs_inf) { res->udata = P$(n)INF; }
      //check the sign and assign maxreal/minreal
      res->udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;
    };

    //in the basic case, just output the result.
    *res = $(to_p(n,es,:fres));
}""")
  elseif (op == :mul)
    binf = TPTR_TO_BINF[op]
    string(headerfn(op, n, es), """{
    bool lhs_inf = (lhs->udata == P$(n)INF);
    bool rhs_inf = (rhs->udata == P$(n)INF);
    bool lhs_zer = (lhs->udata == P$(n)ZER);
    bool rhs_zer = (rhs->udata == P$(n)ZER);

    //long jump on multiplication of infinity times zero.
    if ( (lhs_inf && rhs_zer) || (rhs_inf && lhs_zer)) { throw_nan_jmp(); }

    $(ftype) fres = $(to_f(n,es,"*lhs")) $(binf) $(to_f(n,es,"*rhs"));

    //check to see if we became infinity correctly.
    if (!isfinite(fres)){
      if (lhs_inf || rhs_inf) { res->udata = P$(n)INF; }
      else {res->udata = (fres > 0) ? P$(n)MAXREAL : P$(n)MINREAL;}
      return;
    };

    //IEEE numbers underflow to zero.  sad!
    if (fres == 0){
      if (lhs_zer || rhs_zer) { res->udata = 0; }
      else {res->udata = (((lhs->udata & P$(n)INF) ^ (rhs->udata & P$(n)INF)) != 0) ? P$(n)NEGSMALL : P$(n)POSSMALL;}
      return;
    };

    //in the basic case, just output the result.
    *res = $(to_p(n,es,:fres));
}""")
  elseif (op == :addinv)
    #additive inverse should be coded directly.
    string(headerfn(op, n, es), """{
  $(p(n,es)) res;
  res.udata = -x.udata;
  return res;
}""")
  elseif (headerfn == boolean_header)
    boolf = BOOLF[op]
    string(headerfn(op, n, es), """{
  if ((lhs.udata == P$(n)INF) || (rhs.udata == P$(n)INF)) { return true; }
  return (lhs.sdata $(boolf) rhs.sdata);
}""")
  end
end
=#

const basics_sanitizer = Dict(:add => (n) -> """
  """, :sub => (n) -> """
  """, :mul => (n) -> """
  """)

const basics_code = Dict(:add => (n, es) -> """
  //jump_version
  extern "C" $(op[:add][1](n,es)) {
    $(p(n,es)) res;
    status = sanitized_add(a, b);
    switch (status){
      case 1: res->udata = P$(n)ZER; return res;
      case 2: res->udata = P$(n)INF; return res;
      case 3: throw_nan_jmp();
    }

  }

  //status_t version
  extern "C" $(op[:add][2](n,es)) {
    status = sanitized_add(a, b);
    switch (status){
      case 1: res->udata = P$(n)ZER; return;
      case 2: res->udata = P$(n)INF; return;
      case 3: throw_nan_jmp();
    }
    
  }
  """)

function generate_posit_basics_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io,"""
  #include "include/posit.h"
  #include "include/posit_conv.h"
  """)

  for fn in BASICS_FNS
    for n in sort(collect(keys(posit_defs)))

      sanitizer = haskey(basics_sanitizer, fn) ? """
      /*************************************************************/
      /*  posit_$(n) section, $(fn) sanitizers                              */
      /*************************************************************/

      $(basics_sanitizer[fn](n))
      """ : ""

      write(io, """
      $sanitizer

      /*************************************************************/
      /*  posit_$(n) section, variable ES adapters for $(fn)                */
      /*************************************************************/
      """)


      for es in posit_defs[n]
        write(io, basics_output(fn, n, es))
        write(io, "\n")
      end
    end
    write(io,"\n")
  end
end
