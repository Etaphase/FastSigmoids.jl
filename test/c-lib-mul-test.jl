macro linklibrary_mul(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_mul_j))

  posittype = Symbol(:UInt, n)

  esc(:(pmul = (a, b) -> ccall( ($fnname, $path), $posittype, ($posittype, $posittype), a, b )))
end

#comprehensive integration testing
@linklibrary_mul(8,0)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yzer) | (xzer & yinf))
    @test (x,y,pmul(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,0}, x) * reinterpret(Posit{8,0}, y))))
  end
end

@linklibrary_mul(8,1)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yzer) | (xzer & yinf))
    @test (x,y,pmul(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,1}, x) * reinterpret(Posit{8,1}, y))))
  end
end

@linklibrary_mul(8,2)
for x = 0x00:0xFF, y = 0x00:0xFF
  xinf = (x == 0x80)
  yinf = (y == 0x80)
  xzer = (x == 0x00)
  yzer = (y == 0x00)
  if !((xinf & yzer) | (xzer & yinf))
    @test (x,y,pmul(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,2}, x) * reinterpret(Posit{8,2}, y))))
  end
end

macro test_big_bittype_mul(N, ES)
  quote
    @linklibrary_mul($N, $ES)

    println("testing multiplication on p$($N)e$($ES)")

    UType = UIntLookup[$N]

    for idx = 1:10000
      x = rand(UType)
      y = rand(UType)

      xinf = (x == topbits($N))
      yinf = (y == topbits($N))
      xzer = (x == zero($N))
      yzer = (y == zero($N))

      if !((xinf & yzer) | (xzer & yinf)) #ignore the one corner case that doesn't work.
        @test (x,y,pmul(x, y)) == (x,y,reinterpret(UType, (reinterpret(Posit{$N,$ES}, x) * reinterpret(Posit{$N,$ES}, y))))
      end
    end
  end
end

@test_big_bittype_mul(16,0)
@test_big_bittype_mul(16,1)
@test_big_bittype_mul(16,2)

@test_big_bittype_mul(32,0)
@test_big_bittype_mul(32,1)
@test_big_bittype_mul(32,2)
@test_big_bittype_mul(32,3)
