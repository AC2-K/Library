#pragma once
#include"internal/barrett.hpp"
#include<cassert>
namespace kyopro {
template <int MAX>
class dynamic_combination {
    int fac[MAX], ifac[MAX];
    int m;
    constexpr int fact_pow(int a, int p) {
        int ans = 1;
        while (p) {
            if (p & 1) ans = bar.mul(ans, a);
            p >>= 1;
            a = bar.mul(a, a);
        }
        return ans;
    }
    void build() {
        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
        int N = std::min(m, MAX);
        for (int i = 2; i < N; ++i) {
            fac[i] = bar.mul(fac[i - 1], i);
        }

        ifac[N - 1] = fact_pow(fac[N - 1], m - 2);
        for (int i = N - 2; i > 1; --i) {
            ifac[i] = bar.mul(ifac[i + 1], i + 1);
        }
    }

    internal::barrett bar;

public:
    constexpr dynamic_combination(int modulo) : m(modulo), bar(modulo) {
        build();
    }

    constexpr int binom(int n, int r) const {
        assert(n >= r);
        return bar.mul(fac[n], bar.mul(ifac[r], ifac[n - r]));
    }
    constexpr int perm(int n, int r) const {
        assert(n >= r);
        return fac[n] * ifac[n - r];
    }
    constexpr int fact(int n) const { return fac[n]; }
};

template <typename mint, int MAX>
class combination {
    mint fac[MAX + 1];
    mint ifac[MAX + 1];

public:
    constexpr explicit combination() {
        fac[0] = 1;
        for (int i = 1; i <= MAX; ++i) {
            fac[i] = fac[i - 1] * i;
        }
        ifac[MAX] = fac[MAX].inv();
        for (int i = MAX; i > 0; --i) {
            ifac[i - 1] = ifac[i] * i;
        }
    }

    constexpr mint binom(int n, int r) const {
        assert(n >= r);
        return fac[n] * ifac[r] * ifac[n - r];
    }
    constexpr mint perm(int n, int r) const {
        assert(n >= r);
        return fac[n] * ifac[n - r];
    }
    constexpr mint fact(int n) { return fac[n]; }
};

};  // namespace kyopro

/// @brief 二項係数