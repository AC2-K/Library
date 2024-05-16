#pragma once
#include <algorithm>
#include <limits>
#include <numeric>
#include <utility>
#include <vector>
#include "../../src/internal/type_traits.hpp"

namespace kyopro {

    
/**
 * @brief Min Plus Convolution(Convex, Convex)
 * @note a,b ともに下に凸である必要がある
 * @note オーバーフローしがちなので気を付けよう!
 */
template <typename T>
std::vector<T> min_plus_convolution_convex_convex(const std::vector<T>& a,
                                                  std::vector<T>& b) {
    constexpr T INF = std::numeric_limits<T>::max() / 2;
    const int n = a.size();
    const int m = b.size();
    const T A0 = INF;
    const T B0 = INF;

    std::vector<T> da(n);
    std::vector<T> db(m);
    for (int i = 1; i < n; ++i) da[i] = a[i] - a[i - 1];
    for (int i = 1; i < m; ++i) db[i] = b[i] - b[i - 1];
    da[0] = a[0] - INF, db[0] = b[0] - INF;

    std::vector<T> ds;
    std::merge(da.begin(), da.end(), db.begin(), db.end(),
               std::back_inserter(ds));

    std::vector<T> res(n + m - 1);
    T sum = ds[0];
    for (int k = 1; k < (int)ds.size(); ++k) {
        sum += ds[k];
        res[k - 1] = sum + A0 + B0;
    }
    return res;
}
};  // namespace kyopro
