#pragma once
#include <cassert>
#include <utility>
#include <vector>
namespace kyopro {

/**
 * @brief Matrix
 */
template <typename T> class Matrix {
    std::vector<std::vector<T>> dat;
    int h = 0, w = 0;

public:
    constexpr Matrix(const std::vector<std::vector<T>>& dat)
        : dat(dat), h(dat.size()), w(dat.front().size()) {}

    constexpr Matrix(int h_, int w_, T v = T())
        : dat(h_, std::vector<T>(w_, v)) {}

    using mat = Matrix<T>;
    // access
    constexpr std::vector<T>& operator[](int i) { return dat[i]; }

    // operator
    constexpr mat& operator+=(const mat& r) {
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] += r.dat[i][j];
            }
        }
        return (*this);
    }
    constexpr mat& operator-=(const mat& r) {
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] -= r.dat[i][j];
            }
        }
        return (*this);
    }

    constexpr mat& operator*=(const mat& r) {
        int ha = dat.size(), wa = dat.front().size();
        int hb = r.dat.size(), wb = r.dat.front().size();
        assert(wa == hb);

        std::vector<std::vector<T>> res(ha, std::vector<T>(wb));
        for (int i = 0; i < ha; i++) {
            for (int k = 0; k < wa; k++) {
                for (int j = 0; j < wb; j++) {
                    res[i][j] += dat[i][k] * r.dat[k][j];
                }
            }
        }

        std::swap(res, dat);
        return (*this);
    }

    constexpr mat operator+(const mat& r) { return mat(*this) += r; }
    constexpr mat operator-(const mat& r) { return mat(*this) -= r; }
    constexpr mat operator*(const mat& r) { return mat(*this) *= r; }

    template <typename P> constexpr mat pow(P e) const {
        assert(e >= 0);
        int n = dat.size();
        mat res(n, n, 0);
        mat pr(*this);
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (e) {
            if (e & 1) res *= pr;
            pr *= pr;

            e >>= 1;
        }

        return res;
    }
};
};  // namespace kyopro

/**
 *  @docs docs/math/matrix.md
 */