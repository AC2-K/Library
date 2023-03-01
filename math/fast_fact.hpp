#pragma once
#include"math/fast_prime_check.hpp"
#include"math/prime_list.hpp"
namespace prime
{
    using ull = unsigned long long;
    // Rho factorize

    ull find_factor(ull& n) {
        if (is_prime(n)) {
            return n;
        }
        static ull v = 7001;
        v ^= v << 13, v ^= v >> 7, v ^= v << 17;

        if (~n & 1uL) {
            return 2;
        }
        static ull c = v;
        auto f = [&](i128 xx) -> ll {
            xx %= n;
            return (xx * xx % n + c) % n;
        };
        ll x = v % n;
        ll y = x;
        ull d = 1;

        while (d == 1) {
            x = f(x);
            y = f(f(y));
            d = gcd(abs(x - y), n);
        }

        if (d == n) {
            return 0;
        }
        return d;
    }
    vector<ull> rho_fact(ull& n) {
        if (n < 2) {
            return {};
        }
        if (is_prime(n)) {

        }
        vector<ull> res;
        while (n != 1) {
            ull d = 0;
            while (d == 0) {
                d = find_factor(n);
            }
            while (n % d == 0) {
                res.emplace_back(d);
                n /= d;
            }
        }

        return res;
    }

    vector<ull> naive_fact(ull& n) {
        vector<ull> res;

        for (const ull& d : small_prime) {
            while (n % d == 0) {
                res.emplace_back(d);
                n /= d;
            }
        }
        return res;
    }

    vector<ull> fact(ull n) {
        vector<ull> res = naive_fact(n);
        if (n != 1) {
            vector<ull> res2 = rho_fact(n);
            res.insert(res.end(), all(res2));
        }
        sort(all(res));
        return res;
    }
};
///@brief fast factorize(Pollard Rhoの素因数分解)