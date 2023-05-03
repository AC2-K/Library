#pragma once
#include "../math/dynamic_modint.hpp"
namespace kyopro {
namespace miller {
using i128 = __int128_t;
using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;

using i128 = __int128_t;
using u128 = __uint128_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <typename T, typename mint, const int bases[], int length>
constexpr bool miller_rabin(T n) {
    T d = n - 1;

    while (~d & 1) {
        d >>= 1;
    }

    const T rev = n - 1;
    if (mint::get_mod() != n) {
        mint::set_mod(n);
    }
    for (int i = 0; i < length; ++i) {
        if (n <= bases[i]) {
            return true;
        }
        T t = d;
        mint y = mint(bases[i]).pow(t);
        
        while (t != n - 1 && y.val() != 1 && y.val() != rev) {
            y *= y;
            t <<= 1;
        }

        if (y.val() != rev && (~t & 1)) return false;
    }
    return true;
}
constexpr int bases_int[3] = {2, 7, 61};  // intだと、2,7,61で十分
constexpr int bases_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
template <typename T>
constexpr bool inline is_prime(T n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (~n & 1) {
        return false;
    };
    if (std::numeric_limits<T>::digits < 32 || n <= 1 << 30) {
        return miller_rabin<T, dynamic_modint<std::make_unsigned_t<T>>, bases_int, 3>(n);
    } else {
        return miller_rabin<T, dynamic_modint<std::make_unsigned_t<T>>, bases_ll, 7>(n);
    }
    return false;
}
};  // namespace miller
};  // namespace kyopro
