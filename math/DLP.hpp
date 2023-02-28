#pragma once
#include"math/mod_pow.hpp"

ll dlp(ll x, ll y, ll p) {
    if (y == 1 || p == 1) {
        return 0;
    }
    if (x == 0) {
        if (y == 0) {
            return 1;
        }
        else {
            return -1;
        }
    }
    ll m = sqrt(p) + 1;
    unordered_map<ll, int> mp;
    ll xm = mod_pow(x, m, p);
    ll add = 0, g, k = 1 % p;
    while ((g = gcd(x, p)) > 1) {
        if (y == k)return add;
        if (y % g)return -1;
        y /= g, p /= g, add++;
        k = (k * (x / g)) % p;
    }
    ll pr = y;
    for (int j = 0; j <= m; j++) {
        mp[pr] = j;
        (pr *= x) %= p;
    }
    pr = k;
    for (int i = 1; i <= m; i++) {
        (pr *= xm) %= p;
        if (mp.find(pr) != mp.end()) {
            int j = mp[pr];
            return m * i - j + add;
        }
    }
    return -1;
}

///@brief Discrete Logarithm(離散対数)
///@docs docs/math/DLP.md