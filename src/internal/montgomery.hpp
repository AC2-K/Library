#pragma once
#include <cassert>
#include <limits>
#include <numeric>
#include "../internal/type_traits.hpp"
namespace kyopro {
namespace internal {
using u32 = uint32_t;
using u64 = uint64_t;
using i32 = int32_t;
using i64 = int64_t;
using u128 = __uint128_t;
using i128 = __int128_t;

template <typename T> class Montgomery {
    static constexpr int lg = std::numeric_limits<T>::digits;
    using LargeT = internal::double_size_uint_t<T>;
    T mod, r, r2, minv;
    T inv() {
        T t = 0, res = 0;
        for (int i = 0; i < lg; ++i) {
            if (~t & 1) {
                t += mod;
                res += static_cast<T>(1) << i;
            }
            t >>= 1;
        }
        return res;
    }

public:
    Montgomery() = default;
    constexpr T get_mod() { return mod; }

    void set_mod(T m) {
        assert(m);
        assert(m & 1);

        mod = m;

        r = (-static_cast<T>(mod)) % mod;
        r2 = (-static_cast<LargeT>(mod)) % mod;
        minv = inv();
    }

    T reduce(LargeT x) const {
        u64 res =
            (x + static_cast<LargeT>(static_cast<T>(x) * minv) * mod) >> lg;

        if (res >= mod) res -= mod;
        return res;
    }

    T generate(LargeT x) { return reduce(x * r2); }

    T mul(T x, T y) { return reduce((LargeT)x * y); }
};
};  // namespace internal
};  // namespace kyopro


/**
 * @brief Montgomery Reduction
 */