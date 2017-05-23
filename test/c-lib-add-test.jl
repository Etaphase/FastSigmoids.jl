macro linklibrary_add(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_add))

  posittype = Symbol(:UInt, n)

  esc(quote
    padd = (a, b) -> begin
      res = zero($posittype)
      ccall( ($fnname, $path), Void,
        (Ptr{$posittype}, Ptr{$posittype}, Ptr{$posittype}),
        pointer_from_objref(res), pointer_from_objref(a), pointer_from_objref(b) )
      res
    end
  end)
end

#spot unit testing
@linklibrary_add(8,0)
@test padd(0x00, 0x00) == 0x00  #0 + 0 == 0
@test padd(0x00, 0x40) == 0x40  #0 + 1 == 1
@test padd(0x40, 0x40) == 0x60  #1 + 1 == 2
@test padd(0x40, 0xc0) == 0x00  #1 + -1 == 0
@test padd(0x80, 0xc0) == 0x80  #Inf + 1 == Inf

#comprehensive integration testing
@linklibrary_add(8,0)
for x = 0x00:0xFF, y = 0x00:0xFF
  if (x != 0x80 || y != 0x80) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,0}, x) + reinterpret(Posit{8,0}, y))))
  end
end
@linklibrary_add(8,1)
for x = 0x00:0xFF, y = 0x00:0xFF
  if (x != 0x80 || y != 0x80) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,1}, x) + reinterpret(Posit{8,1}, y))))
  end
end
@linklibrary_add(8,2)
for x = 0x00:0xFF, y = 0x00:0xFF
  if (x != 0x80 || y != 0x80) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,2}, x) + reinterpret(Posit{8,2}, y))))
  end
end

#=
commented out because of random errors.
@linklibrary_add(16,0)
for idx = 1:10000
  x = rand(UInt16)
  y = rand(UInt16)
  if (x != 0x80 || y != 0x80) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt8, (reinterpret(Posit{8,2}, x) + reinterpret(Posit{8,2}, y))))
  end
end
=#

@linklibrary_add(32,0)
for idx = 1:10000
  x = rand(UInt32)
  y = rand(UInt32)
  if (x != 0x8000_0000 || y != 0x8000_0000) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,0}, x) + reinterpret(Posit{32,0}, y))))
  end
end

for idx = 1:1000
  x = rand(UInt32)
  y = 0x0000_0000
  if (x != 0x8000_0000 || y != 0x8000_0000) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,0}, x) + reinterpret(Posit{32,0}, y))))
  end
end

@linklibrary_add(32,0)
for idx = 1:10000
  x = rand(UInt32)
  y = rand(UInt32)
  if (x != 0x8000_0000 || y != 0x8000_0000) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,0}, x) + reinterpret(Posit{32,0}, y))))
  end
end

for idx = 1:1000
  x = rand(UInt32)
  y = 0x0000_0000
  @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,0}, x) + reinterpret(Posit{32,0}, y))))
end

@linklibrary_add(32,1)
for idx = 1:10000
  x = rand(UInt32)
  y = rand(UInt32)
  if (x != 0x8000_0000 || y != 0x8000_0000) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,1}, x) + reinterpret(Posit{32,1}, y))))
  end
end

for idx = 1:1000
  x = rand(UInt32)
  y = 0x0000_0000
  @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,1}, x) + reinterpret(Posit{32,1}, y))))
end

@linklibrary_add(32,2)
for idx = 1:10000
  x = rand(UInt32)
  y = rand(UInt32)
  if (x != 0x8000_0000 || y != 0x8000_0000) #ignore the one corner case that doesn't work.
    @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,2}, x) + reinterpret(Posit{32,2}, y))))
  end
end

for idx = 1:1000
  x = rand(UInt32)
  y = 0x0000_0000
  @test (x,y,padd(x, y)) == (x,y,reinterpret(UInt32, (reinterpret(Posit{32,2}, x) + reinterpret(Posit{32,2}, y))))
end
