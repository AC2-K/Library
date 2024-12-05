#pragma once

#include<complex>
#include<vector>
#include<algorithm>

namespace geometry {

using T = ; // 変更する

constexpr T eps = 0;  // 精度によって変更する
constexpr inline int sgn(T x) noexcept {
    return x < -eps ? -1 : (x > eps ? 1 : 0);
}

using point = complex<T>;
using vec = point;

constexpr inline point rotate_complex(T theta) noexcept {  // 回転行列
    return complex<T>(cos(theta), sin(theta));
}

constexpr inline T dot(point x, point y) noexcept {  // 内積
    return x.real() * y.real() + x.imag() * y.imag();
}

constexpr inline T det(point x, point y) noexcept {  // 外積(のz成分)
    return x.real() * y.imag() - x.imag() * y.real();
}

constexpr inline T arg(point z) noexcept {  // 偏角
    return atan2(z.imag(), z.real());
}

constexpr inline bool operator==(point x, point y) noexcept {   
    return sgn(x.real() - y.real()) == 0 && sgn(x.imag() - y.imag()) == 0;
}
constexpr inline bool operator<(point x, point y) noexcept {
    if (sgn(x.real() - y.real()) != 0) {
        return sgn(x.real() - y.real()) == -1;
    } else {
        return sgn(x.imag() - y.imag()) == -1;
    }
}
constexpr inline bool operator>(point x, point y) noexcept {
    if (sgn(x.real() - y.real()) != 0) {
        return sgn(x.real() - y.real()) == 1;
    } else {
        return sgn(x.imag() - y.imag()) == 1;
    }
}
constexpr inline bool operator<=(point x, point y) noexcept {
    return x == y || x < y;
}
constexpr inline bool operator>=(point x, point y) noexcept {
    return x == y || x > y;
}

void sort_by_arg(vector<point>& points) {   // 偏角ソート(argは(-pi,pi])
    auto where_area = [&](const point& x) {
        if (x.imag() < 0) {
            return -1;
        } else if (x.imag() == 0 && x.real() >= 0) {
            return 0;
        } else {
            return 1;
        }
    };

    auto compare = [&](const point& x, const point& y) {
        if (where_area(x) != where_area(y)) {
            return where_area(x) < where_area(y);
        } else {
            // 反時計回りに x -> yになってたら det(x,y) > 0
            return sgn(det(x, y)) > 0;
        }
    };

    std::sort(points.begin(), points.end(), compare);
}

};  // namespace geometry

/**
 * @brief Geometry(幾何テンプレート)
 */