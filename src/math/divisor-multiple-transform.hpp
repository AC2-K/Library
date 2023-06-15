#pragma once
#include <string.h>
#include <vector>
namespace kyopro {

template <typename T> inline void fast_mobius(std::vector<T>& f) {
    int n = f.size();
    bool is_prime[n + 1];
    {
        memset(is_prime, 1, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p <= n; ++p) {
            if (!is_prime[p]) continue;
            for (int q = p * 2; q <= n; q += p) {
                is_prime[q] = false;
            }
        }
    }

    for (int p = 2; p < n; ++p) {
        if (!is_prime[p]) continue;
        for (int i = 1 / p; p * i < n; ++i) {
            f[i] -= f[p * i];
        }
    }
    return;
}
template <typename T> inline void fast_zeta(std::vector<T>& f) {
    int n = f.size();
    bool is_prime[n + 1];
    {
        memset(is_prime, 1, sizeof(is_prime));
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p <= n; ++p) {
            if (!is_prime[p]) continue;
            for (int q = p * 2; q <= n; q += p) {
                is_prime[q] = false;
            }
        }
    }

    for (int p = 2; p < n; ++p) {
        if (!is_prime[p]) continue;
        for (int i = (n - 1) / p; i >= 1; --i) {
            f[i] += f[p * i];
        }
    }
    return;
}
};  // namespace kyopro

/**
 * @brief メビウス変換
 * @docs docs/math/divisor-multiple-transform.md
*/