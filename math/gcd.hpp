#pragma once
template<typename T>
constexpr inline T _gcd(T a,T b){
    T s = a, t = b;
    while (s % t != 0) {
        T u = s % t;

        s = t;
        t = u;
    }
    return t;
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
/// @return ax+by=gcd(a,b)なるx,yを格納する,返り値にgcd(a,b)

/// @brief gcd(ユークリッドの互除法など)