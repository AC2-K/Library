#pragma once
namespace kyopro {
namespace internal {
/// @brief barrett reduction
/// @ref https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
class barrett {
    using u32 = uint32_t;
    using u64 = uint64_t;

    u64 m;
    u64 im;

public:
    explicit barrett() = default;
    explicit barrett(u64 m_)
        : m(m_), im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}

    u64 get_mod() const { return m; }
    constexpr u64 reduce(int64_t a) const {
        if (a < 0) return m - reduce(-a);
        u64 q = ((__uint128_t)a * im) >> 64;
        a -= m * q;
        if (a >= m) a -= m;
        return a;
    }
    constexpr u64 mul(u64 a, u64 b) const {
        if (a == 0 || b == 0) {
            return 0;
        }
        u64 z = a;
        z *= b;
        u64 x = (u64)(((__uint128_t)z * im) >> 64);

        u32 v = (u32)(z - x * m);

        if (v >= m) v += m;
        return v;
    }
};
};  // namespace internal
};  // namespace kyopro