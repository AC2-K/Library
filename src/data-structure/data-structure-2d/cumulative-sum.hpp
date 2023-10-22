#pragma once
#include <vector>
namespace kyopro {
template <typename T> class cumulative_sum_2d {
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
};  // namespace kyopro

/**
 * @brief 二次元累積和
 */