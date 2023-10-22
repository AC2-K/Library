#pragma once
#include "../data-structure-2d/cumulative-sum.hpp"
namespace kyopro {
template <typename T> class imos_2d {
    cumulative_sum_2d<T> d;

public:
    const int h;
    const int w;

    imos_2d(int h, int w) : h(h), w(w), d(h + 1, w + 1) {}
    void add(int i1, int j1, int i2, int j2, T v) {
        d[i1][j1] += v, d[i2][j2] += v;
        d[i1][j2] -= v, d[i2][j1] -= v;
    }
    T at(int i, int j) { return d.sum(0, 0, i + 1, j + 1); }

    void build() { d.build(); }
};
};  // namespace kyopro

/**
 * @brief 二次元imos法
 */