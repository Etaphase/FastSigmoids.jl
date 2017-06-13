
function constructors(n, es)
  if n < 32
    floatdef = "f_to_p$(n)e$(es)(a)"
    doubledef = "f_to_p$(n)e$(es)((float) a)"
  else
    floatdef = "f_to_p$(n)e$(es)((double) a)"
    doubledef = "f_to_p$(n)e$(es)(a)"
  end

  """

  $(c(n,es))::$(c(n,es))(){ this->data = P$(n)ZER; }

  $(c(n,es))::$(c(n,es))(const float a){
    this->data = $floatdef.udata;
    if (errno) {
      throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
    }
  }

  $(c(n,es))::$(c(n,es))(const double a){
    this->data = $doubledef.udata;
    if (errno) {
      throw std::domain_error("attempted to construct a posit from a NaN IEEE value");
    }
  }

  $(c(n,es))::$(c(n,es))(const $(c(n,es)) &a){ this->data = a.data; }

  $(c(n,es))::$(c(n,es))(const $(p(n,es)) a){ this->data = a.udata; }

  """
end

const CPP_ARITH_OPS = Dict(:add => :+, :sub => :-, :mul => :*, :div => :/)

function arith_operators(n,es)
  #start with the negation code.
  operator_code = ["""
  $(c(n,es)) $(c(n,es))::operator -() const{
    $(c(n,es)) res;
    res.data = -(this->data);
    return res;
  }
  """]

  for op in keys(CPP_ARITH_OPS)
    arith_opsymbol = CPP_ARITH_OPS[op]
    assn_opsymbol = Symbol(arith_opsymbol, :(=))
    #creates the reassignment binding then the arithmetic binding.
    push!(operator_code, """
    $(c(n,es)) &$(c(n,es))::operator $(assn_opsymbol)(const $(c(n,es)) rhs){
      $(p(n,es)) res;

      res = $(p(n,es,op))_e(*this, rhs);
      if (errno) {
        throw std::domain_error("NaN value obtained in operator $assn_opsymbol");
      }

      this->data = res.udata;
      return (*this);
    }

    $(c(n,es)) $(c(n,es))::operator $(arith_opsymbol)(const $(c(n,es)) rhs) const{
      $(c(n,es)) res;          //create a return value from the stack.

      res = $(p(n,es))($(p(n,es,op))_e(*this, rhs));

      if (errno) {
        throw std::domain_error("NaN value obtained in operator $arith_opsymbol");
      }

      return $(c(n,es))(res);
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
    bool $(c(n,es))::operator $(bool_opsymbol)(const $(c(n,es)) rhs) const{
      $(p(n,es)) lhs_p, rhs_p;
      lhs_p.udata = this->data;
      rhs_p.udata = rhs.data;

      return $(p(n,es,op))(lhs_p, rhs_p);
    }

    """)
  end

  join(operator_code, "\n")
end

function conversion_operators(n,es)
  """
  $(c(n,es))::operator float() const{
    return (float) p$(n)e$(es)_to_f(($(p(n,es)))(*this));
  }

  $(c(n,es))::operator double() const{
    return (double) p$(n)e$(es)_to_f(($(p(n,es)))(*this));
  }

  $(c(n,es))::operator $(p(n,es))() const{
    $(p(n,es)) res;
    res.udata = this->data;
    return res;
  }
  """
end

################################################################################

const CPP_UNARY_FNS = [:mulinv, :log2, :exp2 , :sqrt, :log1p, :log, :log10, :exp, :sin, :cos, :atan]

function unary_functions(n, es)
  function_code = []

  for fn in CPP_UNARY_FNS
    #creates the reassignment binding then the arithmetic binding.
    push!(function_code, """

    $(c(n,es)) $(fn) (const $(c(n,es)) x){
      $(p(n,es)) res;

      res = $(p(n,es,fn))_e(x);

      if (errno) {
        throw std::domain_error("NaN value obtained in function $fn");
      }

      $(c(n,es)) res_c(res);
      return res_c;
    }
    """)
  end

  join(function_code, "\n")
end

################################################################################

const CPP_BINARY_FNS = [:pow, :atan2]

function binary_functions(n, es)
  function_code = []

  for fn in CPP_BINARY_FNS
    #creates the reassignment binding then the arithmetic binding.
    push!(function_code, """

    $(c(n,es)) $(fn) (const $(c(n,es)) a, const $(c(n,es)) b){
      $(p(n,es)) res;

      res = $(p(n,es,fn))_e(a, b);
      if (errno) {
        throw std::domain_error("NaN value obtained in function $fn");
      }

      $(c(n,es)) res_c(res);
      return res_c;
    }
    """)
  end

  join(function_code, "\n")
end

################################################################################

const CPP_TERNARY_FNS = [:fma, :fms, :nfma, :nfms]

function ternary_functions(n, es)
  function_code = []

  for fn in CPP_TERNARY_FNS
    #creates the reassignment binding then the arithmetic binding.
    push!(function_code, """

    $(c(n,es)) $(fn)(const $(c(n,es)) a, const $(c(n,es)) b, const $(c(n,es)) c){
      $(p(n,es)) res;

      res = $(p(n,es,fn))_e(a, b, c);

      if (errno) {
        throw std::domain_error("NaN value obtained in function $fn");
      }

      $(c(n,es)) res_c(res);
      return res_c;
    }
    """)
  end

  join(function_code, "\n")
end

doc"""
  adlibbed- file which fills in the implementation of the functions
"""
function generate_posit_class_cpp(io, n, es)
  write(io, """

  #include "include/posit_conv.h"
  #include "include/posit_ops.h"
  #include "include/posit_ops_errno.h"
  #include "include/$(c(n,es)).h"
  #include "errno.h"
  #include <stdexcept>

  $(constructors(n,es))

  $(arith_operators(n,es))

  $(bool_operators(n,es))

  $(conversion_operators(n,es))

  $(unary_functions(n,es))

  $(binary_functions(n,es))

  $(ternary_functions(n,es))
  """)

end
