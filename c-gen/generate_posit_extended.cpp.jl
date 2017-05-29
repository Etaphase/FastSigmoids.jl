
const EXT_FNS = [:sqrt, :log1p, :log, :log10, :exp, :pow, :sin, :cos, :atan, :atan2]

const exts_sanitizers = Dict(:sqrt => (n) -> """
  static int sanitize_sqrt_$(n)(const uint$(n)_t arg){
    if (arg == P$(n)INF) { return 2; }
    if (arg == P$(n)ZER) { return 1; }
    if ((arg & P$(n)INF) != 0) { return 3; } //negative values are rejected
    return 0;
  }
  """, :log1p => (n) -> """
  static int sanitize_log1p_$(n)(const uint$(n)_t arg){
    if (arg == P$(n)INF) { return 2; }
    if (arg == P$(n)ZER) { return 2; }
    if ((arg & P$(n)INF) != 0) { return 3; } //negative values are rejected
    return 0;
  }
  """, :log => (n) -> """
  static int sanitize_log_$(n)(const uint$(n)_t arg){
    if (arg == P$(n)INF) { return 2; }
    if (arg == P$(n)ZER) { return 2; }
    if ((arg & P$(n)INF) != 0) { return 3; } //negative values are rejected
    return 0;
  }""", :log10 => (n) -> """
  static int sanitize_log10_$(n)(const uint$(n)_t arg){
    if (arg == P$(n)INF) { return 2; }
    if (arg == P$(n)ZER) { return 2; }
    if ((arg & P$(n)INF) != 0) { return 3; } //negative values are rejected
    return 0;
  }
  """, :exp => (n) -> """
  static int sanitize_exp_$(n)(const uint$(n)_t arg){
    if (arg == P$(n)INF) { return 3; }  //only infinity is indeterminate
    return 0;
  }
  """, :pow => (n) -> """
  static int sanitize_pow_$(n)(const uint$(n)_t a, const uint$(n)_t b){
    if (a == P$(n)INF) {
      if (b == P$(n)ZER) {return 3;}  //inf^0 is NaN.
      return 2;
    }
    if (a == P$(n)ZER) {
      if (b == P$(n)ZER) { return 3; }  //0^0 -> NaN
      return 1;
    }
    return 0;
  }
  """, :sin => (n) -> """
  static int sanitize_sin_$(n)(const uint$(n)_t a){
    if (a == P$(n)INF) {return 3;}  //inf^0 is NaN
    return 0;
  }
  """, :cos => (n) -> """
  static int sanitize_cos_$(n)(const uint$(n)_t a){
    if (a == P$(n)INF) {return 3;}  //inf^0 is NaN
    return 0;
  }
  """, :atan => (n) -> """
  static int sanitize_atan_$(n)(const uint$(n)_t a){
    if (a == P$(n)INF) {return 3;}  //inf^0 is NaN
    return 0;
  }
  """, :atan2 => (n) -> """
  static int sanitize_atan2_$(n)(const uint$(n)_t a, const uint$(n)_t b){
    if ((a == P$(n)INF) && (b == P$(n)INF)) { return 3; }
    if ((a == P$(n)ZER) && (b == P$(n)ZER)) { return 3; }
    return 0;
  }
  """, )


const exts_code = Dict(
  :sqrt => (n, es) -> """
  $(unop_fn(n,es,:sqrt,true))
  $(unop_fn(n,es,:sqrt,false))
  """, :log1p => (n, es) -> """
  $(unop_fn(n,es,:log1p,true))
  $(unop_fn(n,es,:log1p,false))
  """, :log => (n, es) -> """
  $(unop_fn(n,es,:log,true))
  $(unop_fn(n,es,:log,false))
  """, :log10 => (n, es) -> """
  $(unop_fn(n,es,:log10,true))
  $(unop_fn(n,es,:log10,false))
  """, :exp => (n, es) -> """
  $(unop_fn(n,es,:exp,true))
  $(unop_fn(n,es,:exp,false))
  """, :pow => (n, es) -> """
  $(binop_fn(n,es,:pow,true))
  $(binop_fn(n,es,:pow,false))
  """, :sin => (n, es) -> """
  $(unop_fn(n,es,:sin,true))
  $(unop_fn(n,es,:sin,false))
  """, :cos => (n, es) -> """
  $(unop_fn(n,es,:cos,true))
  $(unop_fn(n,es,:cos,false))
  """, :atan =>  (n, es) -> """
  $(unop_fn(n,es,:atan,true))
  $(unop_fn(n,es,:atan,false))
  """, :atan2 => (n, es) -> """
  $(binop_fn(n,es,:atan2,true))
  $(binop_fn(n,es,:atan2,false))
  """ )

function generate_posit_extended_cpp(io, posit_defs)
  #generates "posit.h" based on the posit_definitions
  write(io,"""
  #include "include/posit.h"
  #include "include/posit_conv.h"
  #include <errno.h>
  """)
  #write(io, zcounts())
  write(io, "\n\n")

  for fn in EXT_FNS
    for n in sort(collect(keys(posit_defs)))

      sanitizer = haskey(exts_sanitizers, fn) ? """
      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, $(fn) sanitizers
      ///////////////////////////////////////////////////////////////

      $(exts_sanitizers[fn](n))
      """ : ""

      write(io, """
      $sanitizer

      ///////////////////////////////////////////////////////////////
      //  posit_$(n) section, variable ES adapters for $(fn)
      ///////////////////////////////////////////////////////////////
      """)

      for es in posit_defs[n]
        write(io, exts_code[fn](n, es))
        write(io, "\n")
      end
    end
    write(io,"\n")
  end
end
