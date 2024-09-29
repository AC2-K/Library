#pragma once
#include <algorithm>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>
#include "../../src/internal/type_traits.hpp"

namespace kyopro {

/**
 * @brief (min, +) Convolution(Convex, Convex)
 * @attention Both a, b must be convex
 */
template <typename T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T>& a,
                                                  std::vector<T>& b) {
    const int n = a.size();
    const int m = b.size();

    std::vector<T> da(n - 1);
    std::vector<T> db(m - 1);
    for (int i = 0; i < n - 1; ++i) da[i] = a[i + 1] - a[i];
    for (int i = 0; i < m - 1; ++i) db[i] = b[i + 1] - b[i];

    std::vector<T> ds;
    std::merge(da.begin(), da.end(), db.begin(), db.end(),
               std::back_inserter(ds));

    std::vector<T> res(n + m - 1);
    res[0] = a[0] + b[0];
    T sum = 0;

    for (int k = 0; k < (int)ds.size(); ++k) {
        sum += ds[k];
        res[k + 1] = sum + a[0] + b[0];
    }

    return res;
}

};  // namespace kyopro
