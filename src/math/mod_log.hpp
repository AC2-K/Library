#pragma once
#include <cmath>
#include "../data-structure/hash_map.hpp"
#include "../math/dynamic_modint.hpp"
#include "../math/gcd.hpp"
#include "../math/mod_pow.hpp"
namespace kyopro {
namespace internal {

template <typename T> constexpr T __mod_log(T x, T y, T p) {
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
template <typename T> constexpr T __mod_log_odd(T x, T y, T p) {
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
    int m = (int)std::sqrt(p) + 1;
    using mint = dynamic_modint<internal::double_size_uint_t<T>, 10>;
    if (mint::mod() != p) {
        mint::set_mod(p);
    }

    T add = 0, g = 0;
    mint k(1);
    while ((g = _gcd(x, p)) != 1) {
        if (y == k.val()) return add;
        if (y % g) return -1;
        y /= g, p /= g, ++add;
        k = (k.val() * (x / g));
    }

    hash_map<T, T> mp;

    mint xm = mint(x).pow(m);
    mint pr = mint(y);
    for (int j = 0; j <= m; ++j) {
        mp[pr.val()] = j;
        pr *= x;
    }
    pr = k;
    for (int i = 1; i <= m; ++i) {
        pr *= xm;
        auto ptr = mp.find(pr.val());
        if (ptr) {
            int j = *ptr;
            return m * i - j + add;
        }
    }
    return -1;
}

};  // namespace internal

/**
 * @brief 離散対数
 */
template <typename T> constexpr inline T mod_log(T a, T b, T c) {
    if (c & 1) {
        return internal::__mod_log_odd(a, b, c);
    } else {
        return internal::__mod_log(a, b, c);
    }
}

};  // namespace kyopro

/**
 * @docs docs/math/mod_log.md
*/