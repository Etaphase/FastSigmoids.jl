macro linklibrary(n, es)
  path = normpath(Pkg.dir("FastSigmoid"),"c-src","libfastposit.so")
  fnname = QuoteNode(Symbol(:p, n, :e, es, :_to_f))

  esc(quote
    p2f = (v) -> ccall( ($fnname, $path), Float32, (UInt16,), v)
  end)
end

@linklibrary(16, 0)

@test p2f(0x0000) == zero(Float32)
@test p2f(0x8000) == Inf32
@test p2f(0b1100_0000_0000_0000) == -1.0f0
@test p2f(0x4000) == 1.0f0
@test p2f(0b0110_0000_0000_0000) == 2.0f0
@test p2f(0b0101_0000_0000_0000) == 1.5f0

@linklibrary(16, 1)

@test p2f(0x0000) == zero(Float32)
@test p2f(0x8000) == Inf32
@test p2f(0b1100_0000_0000_0000) == -1.0f0
@test p2f(0x4000) == 1.0f0
@test p2f(0b0110_0000_0000_0000) == 4.0f0
@test p2f(0b0101_0000_0000_0000) == 2.0f0
@test p2f(0b0101_1000_0000_0000) == 3.0f0
