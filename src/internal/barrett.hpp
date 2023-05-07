#pragma once
#include <cstdint>
namespace kyopro {
namespace internal {

/**
 * @brief Barrett Reduction
 */
class barrett {
    using u32 = uint32_t;
    using u64 = uint64_t;

    u32 m;
    u64 im;

public:
    constexpr barrett() : m(0), im(0) {}
    constexpr barrett(u32 m_)
        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}

    constexpr u32 get_mod() const { return m; }
    constexpr u32 reduce(int64_t a) const { return mul(a, 1); }
    constexpr u32 mul(u32 a, u32 b) const {
        if (!a || !b) {
            return 0;
        }
        u64 z = (u64)a * b;
        u64 x = (u64)(((__uint128_t)z * im) >> 64);

        u64 y = x * m;
        return (u32)(z - y + (z < y ? m : 0));
    }
};
};  // namespace internal
};  // namespace kyopro

/**
 * @ref
 * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
 */