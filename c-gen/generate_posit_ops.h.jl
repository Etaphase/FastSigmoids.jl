
function general_header(op::Symbol, n::Integer, es::Integer, arity::Integer, status = false)
  prefix = "  "
  output = status ? "status_t" : p(n,es)
  ident  = string(p(n,es,op), status ? "" : "_j")
  statusarg = status ? ["$(p(n,es)) *res"] : []
  pointer = status ? "*" : ""

  args   = join(vcat(statusarg, ["$(p(n,es)) $pointer$(sym[idx])" for idx = 1:arity]),", ")
  "$prefix $output $ident($args)"
end

const binops = Dict(:add => :+, :sub => :-, :mul => :*, :div => :/, :lt => :<, :lte => :(<=) )

function cplusplus_header(op::Symbol, n::Integer, es::Integer, arity::Integer, status = false)
  if op in keys(binops)
    "extern $(c(n,es)) operator $(binops[op])($(c(n,es)) lhs, $(c(n,es)) rhs)"
  elseif op == :addinv
    "extern $(c(n,es)) operator -($(c(n,es)) arg)"
  else
    arglist = join(["$(c(n,es)) $(sym[n])" for n = 1:arity], ", ")
    "extern $(c(n,es)) $op($arglist)"
  end
end

header_set(op::Symbol, arity::Integer) = [(n, es) -> general_header(op, n, es, arity),
                                          (n, es) -> general_header(op, n, es, arity, true)]
#headers for special functions
boolean_header_c(op::Symbol) =   (n, es) -> "  bool $(p(n,es,op))($(p(n,es)) a, $(p(n,es)) b)"
boolean_header_cpp(op::Symbol) = (n, es) -> "extern bool operator $(binops[op])($(c(n,es)) a, $(c(n,es)) b)"

fdp_header_c(op::Symbol) =       (n, es) -> "  $(p(n,es)) $(p(n,es,op))(fdp_cache$(n)e$(es)_t *fc, $(p(n,es)) a, $(p(n,es)) b)"
fdp_header_cpp(op::Symbol) =     (n, es) -> "extern $(c(n,es)) fdp(fdp_cache$(n)e$(es) *fc, $(c(n,es)) a, $(c(n,es)) b)"

dpi_header_c(op::Symbol) =       (n, es) -> "  void $(p(n,es,op))(fdp_cache$(n)e$(es)_t *fc)"
dpi_header_cpp(op::Symbol) =     (n, es) -> "extern void dpi(fdp_cache$(n)e$(es) *fc)"

newc_header(op::Symbol) =        (n, es) -> "  fdp_cache$(n)e$(es)_t* newcache$(n)e$(es)()"

const ordered_oplist =  [:add, :mul, :sub, :addinv, :lt, :lte, :div,
                         :mulinv, :log2, :exp2, :fma, :fms, :nfma, :nfms, :fas, :fcp, :fdp, :dpi, :newc,
                         :sqrt, :log10, :log, :exp, :pow, :logx, :sin, :cos, :atan, :atan2]

#the ops dictionary lists

const ops = Dict(#required for all posit implementations
                 :add    => header_set(:add, 2),
                 :mul    => header_set(:mul, 2),
                 :sub    => header_set(:sub, 2),
                 :addinv => header_set(:addinv, 1),
                 :lt     => [nothing, boolean_header_c(:lt)],
                 :lte    => [nothing, boolean_header_c(:lte)],
                 #full posit required functions
                 :div    => header_set(:div, 2),
                 :mulinv => header_set(:mulinv, 1),
                 :log2   => header_set(:log2, 1),
                 :exp2   => header_set(:exp2, 1),
                 :fma    => header_set(:fma, 3),
                 :fms    => header_set(:fms, 3),
                 :nfma   => header_set(:nfma, 3),
                 :nfms   => header_set(:nfms, 3),
                 :fas    => header_set(:fas, 3),
                 :fcp    => header_set(:fcp, 4),
                 :fdp    => [nothing, fdp_header_c(:fdp)],
                 :dpi    => [nothing, dpi_header_c(:dpi)],
                 :newc   => [nothing, newc_header(:newc)],
                 #extended functions,
                 :sqrt   => header_set(:sqrt, 1),
                 :log1p  => header_set(:log1p, 1),
                 :log    => header_set(:log, 1),
                 :log10  => header_set(:log10, 1),
                 :exp    => header_set(:exp, 1),
                 :pow    => header_set(:pow, 2),
                 :logx   => header_set(:logx, 2),
                 :sin    => header_set(:sin, 1),
                 :cos    => header_set(:cos, 1),
                 :atan   => header_set(:atan, 1),
                 :atan2  => header_set(:atan2, 2))

function writefndef(io, op, n, es, version)
  op_fn = ops[op][version]
  write(io, op_fn(n, es))
end

function generate_posit_ops_status_h(io, posit_defs)
  write(io, """

    #ifndef __POSIT_OPS_STATUS_H
    #define __POSIT_OPS_STATUS_H

    #include "posit.h"

    #ifdef __cplusplus
      extern "C"{
    #else
      extern {
    #endif

    """)
  for op in ordered_oplist
    for n in sort(collect(keys(posit_defs)))
      for es in posit_defs[n]
        writefndef(io, op, n, es, 2)
        write(io, ";\n")
      end
    end

    write(io, "\n")
  end
  write(io, "}\n")
  write(io, "#endif\n")
end

function generate_posit_ops_jumps_h(io, posit_defs)
  write(io, """

    #ifndef __POSIT_OPS_JUMPS_H
    #define __POSIT_OPS_JUMPS_H

    #include "posit.h"

    #ifdef __cplusplus
      extern "C"{
    #endif

    """)
  for op in ordered_oplist
    for n in sort(collect(keys(posit_defs)))
      for es in posit_defs[n]
        if ops[op][1] != nothing
          writefndef(io, op, n, es, 1)
          write(io, ";\n")
        end
      end
    end

    write(io, "\n")
  end
  write(io, """
  #ifdef __cplusplus
  }
  #endif
  #endif
  """)
end
