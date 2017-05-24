
const arith_ops = [:+, :-, :*, :/]
const modifying_ops = [:+=, :-=, :*=, :/=]
const bool_ops = [:<, :>, :<=, :>=, :(==), :!=]

const posit_fns = [:mulinv, :log2,  :exp2, :fma,   :fms, :nfma, :nfms, :fas, :fcp,
                    :sqrt,   :log1p, :log,  :log10, :exp, :pow,  :logx, :sin, :cos, :atan, :atan2]

const posit_arities = Dict(:mulinv => 1,
                           :log2   => 1,
                           :exp2   => 1,
                           :fma    => 3,
                           :fms    => 3,
                           :nfma   => 3,
                           :nfms   => 3,
                           :fas    => 3,
                           :fcp    => 4,
                           #extended functions,
                           :sqrt   => 1,
                           :log1p  => 1,
                           :log    => 1,
                           :log10  => 1,
                           :exp    => 1,
                           :pow    => 2,
                           :logx   => 2,
                           :sin    => 1,
                           :cos    => 1,
                           :atan   => 1,
                           :atan2  => 2)

function generate_posit_hpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io, """
    #ifndef __POSIT_HPP
    #define __POSIT_HPP

    """)

  for n in sort(collect(keys(posit_defs)))
    for es in posit_defs[n]

      #create lists of all the friend operators and friend functions
      direct_oplist = []
      friend_fnlist = []

      #populate the oplists
      for op in arith_ops
        push!(direct_oplist, "    $(c(n,es)) operator $(op)(const $(c(n,es)))")
      end

      for op in modifying_ops
        push!(direct_oplist, "    $(c(n,es)) &operator $(op)(const $(c(n,es)))")
      end

      for op in bool_ops
        push!(direct_oplist, "    bool operator $(op)(const $(c(n,es)))")
      end

      direct_ops = join(direct_oplist, "; \n")

      for fn in posit_fns
        arity = posit_arities[fn]
        arglist = join(["const $(c(n,es)) $(sym[idx])" for idx = 1:arity], ", ")
        push!(friend_fnlist, "    friend $(c(n,es)) $(fn)($arglist)")
      end

      friend_fns = join(friend_fnlist, "; \n")

      write(io, """
        class $(c(n,es)){
          private:

          public:
            $(c(n,es))();                                     //blank constructor which initializes to zero
            $(c(n,es))(const double);                         //constructor which takes a double
            $(c(n,es))(const $(p(n,es)));                     //constructor which takes the c type

            //direct operators
        $direct_ops;

            //conversion operators

            friend double operator double(const $(c(n,es)));  //explicit conversion to double
            friend $(c(n,es)) operator $(c(n,es))(const double);
            friend $(c(n,es)) operator $(c(n,es))(const int64_t);

            //friended functions
        $friend_fns;

        }
        """);
    end
    write(io, "\n")
  end

  write(io, "#endif\n")
end
