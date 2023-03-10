#pragma once
namespace internal {
	//burret reduction
	class barrett {
		using u32 = uint32_t;
		using u64 = uint64_t;

		u32 m;
		u64 im;
	public:
		explicit barrett() = default;
		explicit barrett(const u32& m_) :m(m_), im((u64)(-1) / m_ + 1) {}

		u32 get_mod() const { return m; }
		u32 mul(u32 a, u32 b) {
			if (a == 0 || b == 0) {
				return 0;
			}
			u64 z = a;
			z *= b;
#ifdef _MSC_VER
			u64 x;

			_umul128(z, im, &x);
#else
			u64 x = (u64)(((__uint128_t)(z)*im) >> 64);
#endif

			u32 v = (u32)(z - x * m);

			if (v >= m)v += m;
			return v;
		}
	};
}