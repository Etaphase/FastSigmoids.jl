#val-headers
unary_val_header(op::Symbol, n::Integer, es::Integer) =      "extern \"C\" $(p(n,es)) $(p(n,es,op))($(p(n,es)) x)"
binary_val_header(op::Symbol, n::Integer, es::Integer) =     "extern \"C\" $(p(n,es)) $(p(n,es,op))($(p(n,es)) a, $(p(n,es)) b)"
ternary_val_header(op::Symbol, n::Integer, es::Integer) =    "extern \"C\" $(p(n,es)) $(p(n,es,op))($(p(n,es)) a, $(p(n,es)) b, $(p(n,es)) c)"
quaternary_val_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" $(p(n,es)) $(p(n,es,op))($(p(n,es)) a, $(p(n,es)) b, $(p(n,es)) c, $(p(n,es)) b)"

#boolean headers
boolean_header(op::Symbol, n::Integer, es::Integer) =        "extern \"C\" bool $(p(n,es,op))($(p(n,es)) lhs, $(p(n,es)) rhs)"

#pointer headers
ternary_ptr_header(op::Symbol, n::Integer, es::Integer) =    "extern \"C\" void $(p(n,es,op))($(p(n,es)) *res, $(p(n,es)) *lhs, $(p(n,es)) *rhs)"
quaternary_ptr_header(op::Symbol, n::Integer, es::Integer) = "extern \"C\" void $(p(n,es,op))($(p(n,es)) *res, $(p(n,es)) *a,   $(p(n,es)) *b,   $(p(n,es)) *c)"

#headers for special functions
fdp_header(op::Symbol, n::Integer, es::Integer) =            "extern \"C\" $(p(n,es)) $(p(n,es,op))(fdp_cache$(n)e$(es)_t *fc, $(p(n,es)) a, $(p(n,es)) b)"
dpi_header(op::Symbol, n::Integer, es::Integer) =            "extern \"C\" void $(p(n,es,op))(fdp_cache$(n)e$(es)_t *fc)"
newc_header(op::Symbol, n::Integer, es::Integer) =           "extern \"C\" fdp_cache$(n)e$(es)_t* newcache$(n)e$(es)()"

const ordered_oplist =  [:add, :mul, :sub, :addinv, :lt, :lte, :div,
                         :mulinv, :log2, :exp2, :fma, :fms, :nfma, :nfms, :fas, :fcp, :fdp, :dpi, :newc,
                         :sqrt, :log10, :log, :exp, :pow, :logx, :sin, :cos, :atan, :atan2]

const ops = Dict(#required for all posit implementations
                 :add    => ternary_ptr_header,
                 :mul    => ternary_ptr_header,
                 :sub    => ternary_ptr_header,
                 :addinv => unary_val_header,
                 :lt     => boolean_header,
                 :lte    => boolean_header,
                 #full posit required functions
                 :div    => ternary_ptr_header,
                 :mulinv => unary_val_header,
                 :log2   => unary_val_header,
                 :exp2   => unary_val_header,
                 :fma    => quaternary_ptr_header,
                 :fms    => quaternary_ptr_header,
                 :nfma   => quaternary_ptr_header,
                 :nfms   => quaternary_ptr_header,
                 :fas    => ternary_val_header,
                 :fcp    => quaternary_val_header,
                 :fdp    => fdp_header,
                 :dpi    => dpi_header,
                 :newc   => newc_header,
                 #extended functions,
                 :sqrt   => unary_val_header,
                 :log1p  => unary_val_header,
                 :log    => unary_val_header,
                 :log10  => unary_val_header,
                 :exp    => unary_val_header,
                 :pow    => binary_val_header,
                 :logx   => binary_val_header,
                 :sin    => unary_val_header,
                 :cos    => unary_val_header,
                 :atan   => unary_val_header,
                 :atan2  => binary_val_header)

function writefndef(io, op, n, es)
  write(io, ops[op](op, n, es))
end

function generate_posit_ops_h(io, posit_defs)
  write(io, "#ifndef __POSIT_OPS_H\n")
  write(io, "#define __POSIT_OPS_H\n")
  write(io, "\n")
  write(io, "#include \"posit.h\"")
  write(io, "\n")
  for op in ordered_oplist
    for n in sort(collect(keys(posit_defs)))
      for es in posit_defs[n]
        writefndef(io, op, n, es)
        write(io, ";\n")
      end
    end

    write(io, "\n")
  end
  write(io, "#endif")
end
