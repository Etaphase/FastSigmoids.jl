macro linklibrary_p2f(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_to_f))
  inputtype = Symbol(:UInt, n)
  outputtype = n == 32 ? Float64 : Float32

  esc(quote
    p2f = (v) -> ccall( ($fnname, $path), $outputtype, ($inputtype,), v)
  end)
end

#spot unit testing
@linklibrary_p2f(8, 0)
@test p2f(0x7F) == 64.0

@linklibrary_p2f(16, 0)
@test p2f(0x0000) == zero(Float32)
@test p2f(0x8000) == Inf32
@test p2f(0b1100_0000_0000_0000) == -1.0f0
@test p2f(0x4000) == 1.0f0
@test p2f(0b0110_0000_0000_0000) == 2.0f0
@test p2f(0b0101_0000_0000_0000) == 1.5f0

@linklibrary_p2f(16, 1)
@test p2f(0x0000) == zero(Float32)
@test p2f(0x8000) == Inf32
@test p2f(0b1100_0000_0000_0000) == -1.0f0
@test p2f(0x4000) == 1.0f0
@test p2f(0b0110_0000_0000_0000) == 4.0f0
@test p2f(0b0101_0000_0000_0000) == 2.0f0
@test p2f(0b0101_1000_0000_0000) == 3.0f0
@test p2f(0b0010_0000_0000_0000) == 0.25f0
@test p2f(0b0011_0000_0000_0000) == 0.50f0

@linklibrary_p2f(16, 2)
@test p2f(0b0100_0000_0000_0000) == 1.0f0
@test p2f(0b0110_0000_0000_0000) == 16.0f0
@test p2f(0b0100_1000_0000_0000) == 2.0f0
@test p2f(0b0101_0000_0000_0000) == 4.0f0
@test p2f(0b0101_1000_0000_0000) == 8.0f0

@linklibrary_p2f(32, 2)
@test p2f(0x4000_0000) == 1.0
@test p2f(0x4400_0000) == 1.5
@test p2f(0x4800_0000) == 2.0
@test p2f(0x5000_0000) == 4.0
@test p2f(0x5800_0000) == 8.0
@test p2f(0x6000_0000) == 16.0

#comprehensive testing on 8,0;8,1;8,2
@linklibrary_p2f(8,0)
for idx=0x00:0xFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{8,0},idx)),idx)
end
@linklibrary_p2f(8,1)
for idx=0x00:0xFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{8,1},idx)),idx)
end
@linklibrary_p2f(8,2)
for idx=0x00:0xFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{8,2},idx)),idx)
end

#comprehensive testing on 16,0; 16,1; 16,2
@linklibrary_p2f(16,0)
for idx=0x0000:0xFFFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{16,0},idx)),idx)
end
@linklibrary_p2f(16,1)
for idx=0x0000:0xFFFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{16,1},idx)),idx)
end
@linklibrary_p2f(16,2)
for idx=0x0000:0xFFFF
  @test (p2f(idx),idx) == (Float32(reinterpret(Posit{16,2},idx)),idx)
end

#randomized testing on 32,0; 32,1; 32,2; 32,3
@linklibrary_p2f(32,0)
for idx=1:5000
  v = rand(UInt32)
  @test (p2f(v),v) == (Float64(reinterpret(Posit{32,0},v)),v)
end
@linklibrary_p2f(32,1)
for idx=1:5000
  v = rand(UInt32)
  @test (p2f(v),v) == (Float64(reinterpret(Posit{32,1},v)),v)
end
@linklibrary_p2f(32,2)
for idx=1:5000
  v = rand(UInt32)
  @test (p2f(v),v) == (Float64(reinterpret(Posit{32,2},v)),v)
end
