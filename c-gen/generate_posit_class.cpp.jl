
function constructors(n, es)
  if n < 32
    floatdef = "f_to_p$(n)e$(es)(a)"
    doubledef = "f_to_p$(n)e$(es)((float) a)"
  else
    floatdef = "f_to_p$(n)e$(es)((double) a)"
    doubledef = "f_to_p$(n)e$(es)(a)"
  end

  """

  $(c(n,es))::$(c(n,es))(){ this.data = P$(n)ZER; }

  $(c(n,es))::$(c(n,es))(float a){ this.data = $floatdef.udata; }

  $(c(n,es))::$(c(n,es))(double a){ this.data = $doubledef.udata; }

  $(c(n,es))::$(c(n,es))($(c(n,es)) a){ this.data = a.udata; }

  $(c(n,es))::$(c(n,es))($(p(n,es)) a){ this.data = a.udata; }

  """
end

const CPP_ARITH_OPS = Dict(:add => :+, :sub => :-, :mul => :*, :div => :/)

function arith_operators(n,es)
  operator_code = []

  for op in keys(CPP_ARITH_OPS)
    arith_opsymbol = CPP_ARITH_OPS[op]
    assn_opsymbol = Symbol(arith_opsymbol, :(=))
    #creates the reassignment binding then the arithmetic binding.
    push!(operator_code, """
    $(c(n,es)) &$(c(n,es))::operator $(assn_opsymbol)(const $(c(n,es)) rhs){
      $(p(n,es)) lhs;          //create an lhs on the stack.
      lhs.udata = this->data;   //set it to the value of the current item.

      if (set_nan_jmp()) {
        $(p(n,es,op))_j(($(p(n,es)) *) this, &lhs, &rhs);
      } else {
        throw domain_error("NaN value obtained in operator $assn_opsymbol");
      }
      return (*this);
    }

    $(c(n,es)) $(c(n,es))::operator $(arith_opsymbol)(const $(c(n,es)) rhs){
      $(p(n,es)) res;          //create a return value on the stack.
      if (set_nan_jmp()){
        $(p(n,es,op))(&res, ($(p(n,es)) *) this, &rhs);
      } else {
        throw domain_error("NaN value obtained in operator $arith_opsymbol");
      }
      return res;
    }
    """)
  end

  join(operator_code, "\n")
end


const CPP_BOOL_OPS = Dict(:lt => "<", :gt => ">", :lte => "<=", :gte => ">=")

function bool_operators(n,es)
  operator_code = []

  for op in keys(CPP_BOOL_OPS)
    bool_opsymbol = CPP_BOOL_OPS[op]
    #creates the reassignment binding then the arithmetic binding.
    push!(operator_code, """
    bool $(c(n,es))::operator $(bool_opsymbol)(const $(c(n,es)) rhs){
      return $(p(n,es,op))(*this, rhs);
    }

    """)
  end

  join(operator_code, "\n")
end





doc"""
  adlibbed- file which fills in the implementation of the functions
"""
function generate_posit_class_cpp(io, n, es)
  write(io, """

  #include "$(c(n,es)).h"

  $(constructors(n,es))

  $(arith_operators(n,es))

  """)

  #=
  //redeclaration of the functions that were just friended
  $(c(n,es)) operator -(const $(c(n,es)) rhs);
  $(c(n,es)) operator float(const $(c(n,es)) rhs);
  $(c(n,es)) operator double(const $(c(n,es)) rhs);



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

  """)=#
end
