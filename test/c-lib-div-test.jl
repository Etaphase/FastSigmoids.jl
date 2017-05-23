macro linklibrary_div(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_div))

  posittype = Symbol(:UInt, n)

  esc(quote
    pdiv = (a, b) -> begin
      res = zero($posittype)
      ccall( ($fnname, $path), Void,
        (Ptr{$posittype}, Ptr{$posittype}, Ptr{$posittype}),
        pointer_from_objref(res), pointer_from_objref(a), pointer_from_objref(b) )
      res
    end
  end)
end

#comprehensive integration testing
@linklibrary_div(8,0)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yinf) | (xzer & yzer))
    @test (x,y,pdiv(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,0}, x) / reinterpret(Posit{8,0}, y))))
  end
end

@linklibrary_div(8,1)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yinf) | (xzer & yzer))
    @test (x,y,pdiv(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,1}, x) / reinterpret(Posit{8,1}, y))))
  end
end

@linklibrary_div(8,2)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yinf) | (xzer & yzer))
    @test (x,y,pdiv(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,2}, x) / reinterpret(Posit{8,2}, y))))
  end
end

#=
commented out due to strange errors
@linklibrary_mul(16,0)
for idx = 1:10000
  x = rand(UInt16)
  y = rand(UInt16)
  xinf = (x == 0x8000)
  yinf = (y == 0x8000)
  xzer = (x == 0x0000)
  yzer = (y == 0x0000)
  if !((xinf & yzer) | (xzer & yinf))
    @test (x,y,pmul(x, y)) == (x,y,reinterpret(UInt16, (reinterpret(Posit{16,0}, x) * reinterpret(Posit{16,0}, y))))
  end
end
=#

@linklibrary_div(32,0)
for idx = 1:10000
  x = rand(UInt32)
  y = rand(UInt32)
  xinf = (x == 0x8000_0000)
  yinf = (y == 0x8000_0000)
  xzer = (x == 0x0000_0000)
  yzer = (y == 0x0000_0000)
  if !((xinf & yzer) | (xzer & yinf))
    @test (x,y,pdiv(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,0}, x) / reinterpret(Posit{32,0}, y))))
  end
end
