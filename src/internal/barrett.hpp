#pragma once
#include <cstdint>
namespace kyopro {
namespace internal {
class barrett {
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using u128 = __uint128_t;

    u32 m;
    u64 im;

public:
    constexpr barrett() : m(0), im(0) {}
    constexpr barrett(u32 m)
        : m(m), im(static_cast<u64>(-1) / m + 1) {}

    constexpr u32 get_mod() const { return m; }
    constexpr u32 reduce(u32 a) const { return mul(1, a); }
    constexpr u32 mul(u32 a, u32 b) const {
        u64 z = (u64)a * b;
        u64 x = (u64)(((u128)(z)*im) >> 64);
        u64 y = x * m;
        return (u32)(z - y + (z < y ? m : 0));
    }
};
};  // namespace internal
};  // namespace kyopro

/**
 * @brief Barrett Reduction
 * @see https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
 */