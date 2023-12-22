#pragma once
#include <cassert>
#include <tuple>
#include <utility>
namespace kyopro {
template <typename T> constexpr inline T _gcd(T a, T b) noexcept {
    assert(a >= 0 && b >= 0);
    if (a == 0 || b == 0) return a + b;
    int d = std::min(__builtin_ctzll(a), __builtin_ctzll(b));
    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);
    while (a != b) {
        if (!a || !b) {
            return a + b;
        }
        if (a >= b) {
            a -= b;
            a >>= __builtin_ctzll(a);
        } else {
            b -= a;
            b >>= __builtin_ctzll(b);
        }
    }

    return a << d;
}
template <typename T>
constexpr inline T ext_gcd(T a, T b, T& x, T& y) noexcept {
    x = 1, y = 0;
    T nx = 0, ny = 1;
    while (b) {
        T q = a / b;
        std::tie(a, b) = std::pair<T, T>{b, a % b};
        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};
        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};
    }
    return a;
}
};  // namespace kyopro