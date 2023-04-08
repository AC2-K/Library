#pragma once
#include <cmath>
#include "../data-structure/hash_map.hpp"
#include "../math/dynamic_modint.hpp"
#include "../math/gcd.hpp"
#include "../math/mod_pow.hpp"
namespace kyopro {
namespace internal {
long long __mod_log(uint64_t x, uint64_t y, uint64_t p) {
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
    uint32_t m = (uint32_t)sqrt(p) + 1;
    hash_map<uint64_t, int> mp;
    uint64_t xm = mod_pow<uint64_t>(x, m, p);
    uint64_t add = 0, g, k = (p == 1 ? 0 : 1);
    while ((g = _gcd(x, p)) > 1) {
        if (y == k) return add;
        if (y % g) return -1;
        y /= g, p /= g, add++;
        k = (k * (x / g)) % p;
    }

    long long pr = y;
    for (int j = 0; j <= m; j++) {
        mp[pr] = j;
        (pr *= x) %= p;
    }
    pr = k;
    for (int i = 1; i <= m; i++) {
        (pr *= xm) %= p;
        auto ptr = mp.find(pr);
        if (ptr) {
            int j = *ptr;
            return m * i - j + add;
        }
    }
    return -1;
}

long long __mod_log32(uint32_t x, uint32_t y, uint32_t p) {
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
    uint32_t m = (uint32_t)std::ceil(std::sqrt(p));
    using mint = barrett_modint<10>;
    if (mint::get_mod() != p) {
        mint::set_mod(p);
    }
    uint64_t add = 0, g = 0;
    mint k(1);
    while ((g = _gcd(x, p)) != 1) {
        if (y == k.val()) return add;
        if (y % g) return -1;
        y /= g, p /= g, add++;
        k = (k.val() * (x / g));
    }

    hash_map<uint32_t, uint32_t, 1 << 16> mp;

    mint xm = mint(x).pow(m);
    mint pr = mint(y);
    for (int j = 0; j <= m; j++) {
        mp[pr.val()] = j;
        pr *= x;
    }
    pr = k;
    for (int i = 1; i <= m; i++) {
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

/// @brief Discrete Logarithm(離散対数)
template <typename T> inline long long mod_log(T a, T b, T c) {
    if (c < 1 << 30) {
        return internal::__mod_log32(a, b, c);
    } else {
        return internal::__mod_log(a, b, c);
    }
}
};  // namespace kyopro

///@docs docs/math/mod_log.md