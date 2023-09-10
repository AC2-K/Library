#pragma once
#include "../../src/atcoder/convolution.hpp"
#include "../../src/math/combination.hpp"

namespace kyopro {

/**
 * @brief taylor shift
 * @tparam mint 係数の型
 * @tparam deg_f fの次数の最大値
 * @param table 内部で使う二項係数のテーブル.(省略可能)
 */

template <typename mint, int deg_f>
std::vector<mint> taylor_shift(
    const std::vector<mint>& f,
    const mint& c,
    const combination<mint, deg_f>& table = combination<mint, deg_f>()) {
    const int n = f.size();
    std::vector<mint> a(f.size()), b(f.size());
    for (int i = 0; i < n; ++i) {
        a[i] = f[i] * table.fact(i);
        b[i] = c.pow(i) * table.ifact(i);
    }
    std::reverse(b.begin(), b.end());

    std::vector res = atcoder::convolution(a, b);
    for (int i = 0; i < n; ++i) {
        res[i] = res[i + n - 1] * table.ifact(i);
    }
    res.resize(f.size());
    return res;
}
};  // namespace kyopro