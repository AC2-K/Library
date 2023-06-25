#pragma once
#include <algorithm>
#include <cassert>
using namespace std;
namespace kyopro {

template <typename mint, int sz> class combination {
    const int M;
    mint fac[sz + 1], ifac[sz + 1];

public:
    explicit combination() : M(std::min<int>(mint::mod(), sz)) {
        assert(mint::mod());
        fac[0] = mint(1), ifac[0] = mint(1), fac[1] = mint(1),
        ifac[1] = mint(1);

        for (int i = 2; i <= M; ++i) {
            fac[i] = fac[i - 1] * i;
        }

        ifac[M - 1] = mint(1) / fac[M - 1];
        for (int i = M - 2; i > 1; --i) {
            ifac[i] = ifac[i + 1] * (i + 1);
        }
    }

    constexpr mint fact(int n) const {
        assert(0 <= n && n <= sz);
        return fac[n];
    }
    constexpr mint ifact(int n) const {
        assert(0 <= n && n <= sz);
        return ifac[n];
    }

    constexpr mint binom(int n, int r) const {
        assert(n >= r);
        return fact(n) * ifact(r) * ifact(n - r);
    }
    constexpr mint perm(int n, int r) const {
        assert(n >= r);
        return fact(n) * ifact(n - r);
    }
};

};  // namespace kyopro

/**
 * @brief 二項係数
 */