macro linklibrary_modes()
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")

  esc(quote
    set_nanmode = () -> ccall( (:set_nanmode, $path), Void, (Bool,), true )
    set_infmode = () -> ccall( (:set_nanmode, $path), Void, (Bool,), false )
    set_roundstozero   = () -> ccall( (:set_underflow, $path), Void, (Bool,), true )
    set_roundsfromzero = () -> ccall( (:set_underflow, $path), Void, (Bool,), false )

    get_nanmode = () -> ccall( (:get_nanmode, $path), Bool, ())
    get_roundstozero   = () -> ccall( (:get_underflow, $path), Bool, ())
  end)
end

@linklibrary_modes

set_roundstozero()
#test that the interaction is stateful.
@test get_roundstozero();
println("testing underflow rounding mode")
#multiplication is the major operation that can cause underflow.
@linklibrary_mul(8,0)
@test pmul(0x01, 0x01) == 0x00
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x00
@test pmul(0x09, 0x04) == 0x01
@linklibrary_mul(8,1)
@test pmul(0x01, 0x01) == 0x00
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x00
@test pmul(0x09, 0x04) == 0x01
@linklibrary_mul(8,2)
@test pmul(0x01, 0x01) == 0x00
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x00
@test pmul(0x09, 0x04) == 0x01

@linklibrary_mul(16,0)
@test pmul(0x0001, 0x0001) == 0x0000
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0000
@test pmul(0x0081, 0x0040) == 0x0001
@linklibrary_mul(16,1)
@test pmul(0x0001, 0x0001) == 0x0000
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0000
@test pmul(0x0081, 0x0040) == 0x0001
@linklibrary_mul(16,2)
@test pmul(0x0001, 0x0001) == 0x0000
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0000
@test pmul(0x0081, 0x0040) == 0x0001

@linklibrary_mul(32,0)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0000
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0000
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,1)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0000
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0000
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,2)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0000
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0000
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,3)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0000
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0000
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001

set_roundsfromzero()
#test that the interaction is stateful.
@test !get_roundstozero();
println("testing non-underflowing rounding mode")
@linklibrary_mul(8,0)
@test pmul(0x01, 0x01) == 0x01
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x01
@test pmul(0x09, 0x04) == 0x01
@linklibrary_mul(8,1)
@test pmul(0x01, 0x01) == 0x01
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x01
@test pmul(0x09, 0x04) == 0x01
@linklibrary_mul(8,2)
@test pmul(0x01, 0x01) == 0x01
@test pmul(0x08, 0x08) == 0x01
@test pmul(0x08, 0x04) == 0x01
@test pmul(0x09, 0x04) == 0x01

@linklibrary_mul(16,0)
@test pmul(0x0001, 0x0001) == 0x0001
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0001
@test pmul(0x0081, 0x0040) == 0x0001
@linklibrary_mul(16,1)
@test pmul(0x0001, 0x0001) == 0x0001
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0001
@test pmul(0x0081, 0x0040) == 0x0001
@linklibrary_mul(16,2)
@test pmul(0x0001, 0x0001) == 0x0001
@test pmul(0x0080, 0x0080) == 0x0001
@test pmul(0x0080, 0x0040) == 0x0001
@test pmul(0x0081, 0x0040) == 0x0001

@linklibrary_mul(32,0)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0001
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,1)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0001
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,2)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0001
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001
@linklibrary_mul(32,3)
@test pmul(0x0000_0001, 0x0000_0001) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_8000) == 0x0000_0001
@test pmul(0x0000_8000, 0x0000_4000) == 0x0000_0001
@test pmul(0x0000_8001, 0x0000_4000) == 0x0000_0001

################################################################################
# nan mode testing.

macro linklibrary_gt(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_gt))

  posittype = Symbol(:UInt, n)

  esc(:(pgt = (a, b) -> ccall( ($fnname, $path), Bool, ($posittype, $posittype), a, b )))
end
macro linklibrary_lt(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_gt))

  posittype = Symbol(:UInt, n)

  esc(:(plt = (a, b) -> ccall( ($fnname, $path), Bool, ($posittype, $posittype), a, b )))
end
macro linklibrary_gte(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_gt))

  posittype = Symbol(:UInt, n)

  esc(:(pgte = (a, b) -> ccall( ($fnname, $path), Bool, ($posittype, $posittype), a, b )))
end
macro linklibrary_lte(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_gt))

  posittype = Symbol(:UInt, n)

  esc(:(plte = (a, b) -> ccall( ($fnname, $path), Bool, ($posittype, $posittype), a, b )))
end
macro linklibrary_eq(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_eq))

  posittype = Symbol(:UInt, n)

  esc(:(peq = (a, b) -> ccall( ($fnname, $path), Bool, ($posittype, $posittype), a, b )))
end



@linklibrary_add(8,0)
@linklibrary_mul(8,0)
@linklibrary_div(8,0)
@linklibrary_gt(8,0)
@linklibrary_lt(8,0)
@linklibrary_gte(8,0)
@linklibrary_lte(8,0)
@linklibrary_eq(8,0)

set_nanmode()
@test get_nanmode()

@test padd(0x80, 0x40) == 0x80
@test padd(0x80, 0x80) == 0x80
@test pmul(0x80, 0x40) == 0x80
@test pmul(0x80, 0x00) == 0x80
@test pmul(0x80, 0x80) == 0x80
@test pdiv(0x80, 0x40) == 0x80
@test pdiv(0x80, 0x80) == 0x80
@test pdiv(0x40, 0x80) == 0x80

@test pgt(0x80, 0x40) == false
@test plt(0x80, 0x40) == false
@test pgte(0x80, 0x40) == false
@test plte(0x80, 0x40) == false
@test peq(0x80, 0x80) == false

set_infmode()
@test !get_nanmode()
@test padd(0x80, 0x40) == 0x80
#@test padd(0x80, 0x80) == 0x80  <== this should set errno.
@test pmul(0x80, 0x40) == 0x80
#@test pmul(0x80, 0x00) == 0x80 <== this should set errno.
@test pmul(0x80, 0x80) == 0x80
@test pdiv(0x80, 0x40) == 0x80
#@test pdiv(0x80, 0x80) == 0x80 <== this should set errno.
@test pdiv(0x40, 0x80) == 0x00   # note this is different.

@test pgt(0x80, 0x40) == true
@test plt(0x80, 0x40) == true
@test pgte(0x80, 0x40) == true
@test plte(0x80, 0x40) == true
@test peq(0x80, 0x80) == true
