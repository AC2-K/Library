#pragma once
#include <vector>
namespace kyopro {
/// @brief 2次元累積和
/// @tparam T 重みの型
template <typename T>
class cumulative_sum_2d {
    std::vector<std::vector<T>> dat;
    std::vector<std::vector<T>> s;

public:
    const int h;
    const int w;

    cumulative_sum_2d(int h, int w)
        : h(h),
          w(w),
          dat(h, std::vector<T>(w, T())),
          s(h + 1, std::vector<T>(w + 1, T())) {}
    void build() {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                s[i + 1][j + 1] =
                    s[i][j + 1] + s[i + 1][j] - s[i][j] + dat[i][j];
            }
        }
    }
    T sum(int i1, int j1, int i2, int j2) {
        return s[i2][j2] - s[i1][j2] - s[i2][j1] + s[i1][j1];
    }

    std::vector<T>& operator[](int i) { return dat[i]; }
};

/// @brief 二次元imos法
/// @tparam T 重みの型
template <typename T>
class imos_2d {
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