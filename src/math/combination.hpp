#pragma once
#include <cassert>
#include "../internal/barrett.hpp"
namespace kyopro {
template <int MAX> class dynamic_combination {
    int fac[MAX], ifac[MAX];
    const int sz;
    constexpr int inverse(int a) const {
        int p = bar.get_mod() - 2;
        int ans = 1;
        while (p) {
            if (p & 1) ans = bar.mul(ans, a);
            p >>= 1;
            a = bar.mul(a, a);
        }
        return ans;
    }

    const internal::barrett bar;

public:
    constexpr explicit dynamic_combination(int modulo)
        : sz(std::min(MAX, modulo)), bar(modulo) {
        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;

        for (int i = 2; i < sz; ++i) {
            fac[i] = bar.mul(fac[i - 1], i);
        }

        ifac[sz - 1] = inverse(fac[sz - 1]);
        for (int i = sz - 2; i > 1; --i) {
            ifac[i] = bar.mul(ifac[i + 1], i + 1);
        }
    }

    constexpr int binom(int n, int r) const {
        assert(n >= r);
        return bar.mul(fac[n], bar.mul(ifac[r], ifac[n - r]));
    }
    constexpr int perm(int n, int r) const {
        assert(n >= r);
        return bar.mul(fac[n], ifac[n - r]);
    }
    constexpr int fact(int n) const { return fac[n]; }
};

template <int modulo, int MAX> class combination {
    static constexpr int sz = std::min(modulo, MAX);
    int fac[sz + 1], ifac[sz + 1];
    constexpr int inverse(int a) const {
        int ans = 1;
        int p = modulo - 2;
        while (p) {
            if (p & 1) (ans *= a) %= modulo;
            p >>= 1;
            (a *= a) %= modulo;
        }
        return ans;
    }

public:
    constexpr explicit combination() {
        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;

        for (int i = 2; i < sz; ++i) {
            fac[i] = fac[i - 1] * i % modulo;
        }

        ifac[sz - 1] = inverse(fac[sz - 1]);
        for (int i = sz - 2; i > 1; --i) {
            ifac[i] = (long long)ifac[i + 1] * (i + 1) % modulo;
        }
    }

    constexpr int binom(int n, int r) const {
        assert(n >= r);
        return (long long)fac[n] * ifac[r] % modulo * ifac[n - r] % modulo;
    }
    constexpr int perm(int n, int r) const {
        assert(n >= r);
        return fac[n] * ifac[n - r] % modulo;
    }
    constexpr int fact(int n) const { return fac[n]; }
};

};  // namespace kyopro

/**
 * @brief 二項係数など
 */