#pragma once
#include <limits>
#include "../../src/algorithm/monotone_minima.hpp"
namespace kyopro {

/**
 * @brief (min, +) Convolution (Convex, Arbitrary)
 * @attention a must be convex
*/
template <typename T>
std::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>& a,
                                                     const std::vector<T>& b) {
    const int n = a.size();
    const int m = b.size();
    
    const auto f = [&](int i, int j) {
        if (i - j < 0 || i - j >= n) {
            return std::numeric_limits<T>::max() / 2 + b[j];
        }
        return a[i - j] + b[j];
    };

    std::vector res = monotone_minima<T>(n + m - 1, m, f);
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < (int)c.size(); ++i) c[i] = res[i].second;
    return c;
}
};  // namespace kyopro