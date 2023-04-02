#pragma once
template<typename T>
constexpr inline T _gcd(T a, T b) {
    assert(a >= 0 && b >= 0);
    if (a == 0 || b == 0) return a + b;
    int d = min(__builtin_ctzll(a), __builtin_ctzll(b));
    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);
    while (a != b) {
        if (a == 0 || b == 0) {
            return a + b;
        }
        if (a > b) {
            a -= b;
            a >>= __builtin_ctzll(a);
        }else{
            b -= a;
            b >>= __builtin_ctzll(b);
        }
    }

    return a << d;
}
template<typename T>
constexpr inline T ext_gcd(T a, T b, T &x, T &y) {
    x = 1, y = 0;
    T nx = 0, ny = 1;
    while(b) {
        T q = a / b;
        tie(a, b) = make_pair(b, a % b);
        tie(x, nx) = make_pair(nx, x - nx*q);
        tie(y, ny) = make_pair(ny, y - ny*q);
    }
    return a;
}