macro linklibrary_div(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_div_e))

  posittype = Symbol(:UInt, n)

  esc(:(pdiv = (a, b) -> ccall( ($fnname, $path), $posittype, ($posittype, $posittype), a, b )))
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


macro test_big_bittype_div(N, ES)
  quote
    @linklibrary_div($N, $ES)

    println("testing division on p$($N)e$($ES)")

    UType = UIntLookup[$N]

    for idx = 1:10000
      x = rand(UType)
      y = rand(UType)

      xinf = (x == topbits($N))
      yinf = (y == topbits($N))
      xzer = (x == zero($N))
      yzer = (y == zero($N))

      if !((xinf & yinf) | (xzer & yzer)) #ignore the cases that doesn't work.
        @test (x,y,pdiv(x, y)) == (x,y,reinterpret(UType, (reinterpret(Posit{$N,$ES}, x) / reinterpret(Posit{$N,$ES}, y))))
      end
    end
  end
end

@test_big_bittype_div(16,0)
@test_big_bittype_div(16,1)
@test_big_bittype_div(16,2)

@test_big_bittype_div(32,0)
@test_big_bittype_div(32,1)
@test_big_bittype_div(32,2)
@test_big_bittype_div(32,3)
