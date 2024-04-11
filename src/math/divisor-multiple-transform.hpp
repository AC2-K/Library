#pragma once
#include <vector>
namespace kyopro {

namespace internal {
std::vector<int> enumerate_primes(int n) {
    std::vector<int> primes;
    {
        std::vector<bool> f(n + 1);
        for (int i = 2; i <= n; ++i) {
            if (f[i]) continue;

            primes.emplace_back(i);
            for (int j = 2 * i; j <= n; j += i) f[j] = 1;
        }
    }
    return primes;
}
};  // namespace internal

namespace multiple {
template <typename T> void zeta(std::vector<T>& f) {
    std::vector primes = internal::enumerate_primes(f.size());
    for (auto p : primes) {
        for (int i = ((int)f.size() - 1) / p; i >= 1; --i) {
            f[i] += f[p * i];
        }
    }
    return;
}

template <typename T> void mobius(std::vector<T>& f) {
    std::vector primes = internal::enumerate_primes(f.size());

    for (auto p : primes) {
        for (int i = 1 / p; p * i < (int)f.size(); ++i) {
            f[i] -= f[p * i];
        }
    }
    return;
}
};  // namespace multiple

namespace divisor {
template <typename T> void zeta(std::vector<T>& f) {
    std::vector primes = internal::enumerate_primes(f.size());

    for (auto p : primes) {
        for (int i = 1; i * p < (int)f.size(); ++i) {
            f[i * p] += f[i];
        }
    }
};
template <typename T> void mobius(std::vector<T>& f) {
    std::vector primes = internal::enumerate_primes(f.size());
    for (auto p : primes) {
        for (int i = (int)(f.size() - 1) / p * p; i >= 1; i -= p) {
            f[i] -= f[i / p];
        }
    }
};
};  // namespace divisor

};  // namespace kyopro

/**
 * @brief Divisor Möbius・Zeta  Transform
 * @docs docs/math/divisor-multiple-transform.md
 */