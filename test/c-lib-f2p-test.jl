macro linklibrary_f2p(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:f_to_p, n, :e, es))

  inputtype = n == 32 ? Float64 : Float32
  outputtype = Symbol(:UInt, n)

  esc(quote
    f2p = (v) -> ccall( ($fnname, $path), $outputtype, ($inputtype,), v)
  end)
end
#spot unit testing

@linklibrary_f2p(8,0)
@test f2p(-32.5f0) == 0x82
@test f2p(-48.0f0) == 0x82
@test reinterpret(UInt8, Posit{8,0}(-48.0f0)) == 0x82

@linklibrary_f2p(16, 0)
@test f2p(0.0f0)  == 0x0000
@test f2p(Inf32)  == 0x8000
@test f2p(1.0f0)  == 0x4000
@test f2p(-1.0f0) == 0xc000
@test f2p(2.0f0)  == 0b0110_0000_0000_0000
@test f2p(1.5f0)  == 0b0101_0000_0000_0000

@linklibrary_f2p(16, 1)
@test f2p(0.0f0)  == 0x0000
@test f2p(Inf32)  == 0x8000
@test f2p(-1.0f0) == 0xc000
@test f2p(1.0f0)  == 0x4000
@test f2p(4.0f0)  == 0x6000
@test f2p(2.0f0)  == 0x5000
@test f2p(3.0f0)  == 0x5800
@test f2p(0.25f0) == 0x2000
@test f2p(0.50f0) == 0x3000

@linklibrary_f2p(16, 2)
@test f2p(1.0f0)  == 0x4000
@test f2p(16.0f0) == 0x6000
@test f2p(2.0f0)  == 0x4800
@test f2p(4.0f0)  == 0x5000
@test f2p(8.0f0)  == 0x5800

@linklibrary_f2p(32, 2)
@test f2p(1.0)  == 0x4000_0000
@test f2p(1.5)  == 0x4400_0000
@test f2p(2.0)  == 0x4800_0000
@test f2p(4.0)  == 0x5000_0000
@test f2p(8.0)  == 0x5800_0000
@test f2p(16.0) == 0x6000_0000

#comprehensive testing on 8,0;8,1;8,2
@linklibrary_p2f(8,0)
@linklibrary_f2p(8,0)
for idx=0x00:0xFF
  @test f2p(p2f(idx)) == idx
end
@linklibrary_p2f(8,1)
@linklibrary_f2p(8,1)
for idx=0x00:0xFF
  @test f2p(p2f(idx)) == idx
end
@linklibrary_p2f(8,2)
@linklibrary_f2p(8,2)
for idx=0x00:0xFF
  @test f2p(p2f(idx)) == idx
end

#comprehensive testing on 16,0; 16,1; 16,2
@linklibrary_p2f(16,0)
@linklibrary_f2p(16,0)
for idx=0x0000:0xFFFF
  @test f2p(p2f(idx)) == idx
end
@linklibrary_p2f(16,1)
@linklibrary_f2p(16,1)
for idx=0x0000:0xFFFF
  @test f2p(p2f(idx)) == idx
end
@linklibrary_p2f(16,2)
@linklibrary_f2p(16,2)
for idx=0x0000:0xFFFF
  @test f2p(p2f(idx)) == idx
end

#randomized testing on 32,0; 32,1; 32,2; 32,3
@linklibrary_p2f(32,0)
@linklibrary_f2p(32,0)
for idx=1:5000
  v = rand(UInt32)
  @test f2p(p2f(v)) == v
end
@linklibrary_p2f(32,1)
@linklibrary_f2p(32,1)
for idx=1:5000
  v = rand(UInt32)
  @test f2p(p2f(v)) == v
end
@linklibrary_p2f(32,2)
@linklibrary_f2p(32,2)
for idx=1:5000
  v = rand(UInt32)
  @test f2p(p2f(v)) == v
end
@linklibrary_p2f(32,3)
@linklibrary_f2p(32,3)
for idx=1:5000
  v = rand(UInt32)
  @test f2p(p2f(v)) == v
end

#spot test conversions of extreme values

@linklibrary_f2p(8,0)
#overflow goes to maxreal
@test f2p(prevfloat(Inf32))  == 0x7F
@test f2p(nextfloat(-Inf32)) == 0x81
#underflow doesn't go to zero
@test f2p(eps(0.0f0))        == 0x01
@test f2p(-eps(0.0f0))       == 0xFF
