#pragma once
#include"math/mod_pow.hpp"
#include"math/rho.hpp"
uint64_t primitive_root(uint64_t p) {
    if (p == 2) return 1;
    auto pf = prime::rho::factorize(p - 1);
    pf.erase(unique(all(pf)), pf.end());
    for (auto& q : pf) {
        q = (p - 1) / q;
    }
    using ull = unsigned long long;
    static ull rnd = 7001;
    while (1) {
        rnd ^= rnd << 13; rnd ^= rnd >> 7; rnd ^= rnd << 17;
        ll g = (ull)rnd % p;
        if (g == 0) continue;
        bool is_ok = true;
        for (ll q : pf) {
            if (mod_pow<__uint128_t, __uint128_t>(g, q, p) == 1) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            return g;
        }
    }
}

//@brief primitive root(原始根)