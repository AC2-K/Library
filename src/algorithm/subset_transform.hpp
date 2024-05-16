#pragma once
#include <vector>


/**
 * @brief Subset Transform
*/

namespace kyopro {
/**
 * @param n v : 2^[n] → T, |v| = 2^n
 */
template <typename T> void zeta(int n, std::vector<T>& v) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < (int)v.size(); ++i) {
            if (~i >> j & 1) continue;
            v[i] += v[i & ~(1 << j)];
        }
    }
}

/**
 * @param n v : 2^[n] → T, |v| = 2^n
 */
template <typename T> void mobius(int n, std::vector<T>& v) {
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < (int)v.size(); ++i) {
            if (~i >> j & 1) continue;
            v[i] -= v[i & ~(1 << j)];
        }
    }
}

};  // namespace kyopro