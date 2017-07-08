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
@test get_roundstozero() == true;
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
@test get_roundstozero() == false;
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