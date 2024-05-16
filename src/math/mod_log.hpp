#pragma once
#include <cmath>
#include "../data-structure/hash_map.hpp"
#include "../math/gcd.hpp"
#include "../math/mod_pow.hpp"
namespace kyopro {

template <typename T> constexpr inline T mod_log(T x, T y, T p) {
    if (y == 1 || p == 1) {
        return 0;
    }
    if (x == 0) {
        if (y == 0) {
            return 1;
        } else {
            return -1;
        }
    }
    int m = (int)sqrt(p) + 1;
    hash_map<T, T> mp;
    T xm = mod_pow<T>(x, m, p);
    internal::double_size_uint_t<T> add = 0, g, k = (p == 1 ? 0 : 1);
    while ((g = _gcd(x, p)) > 1) {
        if (y == k) return add;
        if (y % g) return -1;
        y /= g, p /= g, add++;
        k = (k * (x / g)) % p;
    }

    T pr = y;
    for (int j = 0; j <= m; ++j) {
        mp[pr] = j;
        pr = (internal::double_size_uint_t<T>)pr * x % p;
    }
    pr = k;
    for (int i = 1; i <= m; ++i) {
        pr = (internal::double_size_uint_t<T>)pr * xm % p;
        auto ptr = mp.find(pr);
        if (ptr) {
            int j = *ptr;
            return m * i - j + add;
        }
    }
    return -1;
}

};  // namespace kyopro

/**
 * @brief Discrete Logarithm(離散対数)
 * @docs docs/math/mod_log.md
 */