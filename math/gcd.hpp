template<class T>
static constexpr inline T _gcd(T a,T b){
    T s = a, t = b;
    while (s % t != 0) {
        T u = s % t;

        s = t;
        t = u;
    }
    return t;
}
static constexpr inline ll ext_gcd(ll a, ll b, ll &x, ll &y) {
    x = 1, y = 0;
    ll nx = 0, ny = 1;
    while(b) {
        long long q = a / b;
        tie(a, b) = make_pair(b, a % b);
        tie(x, nx) = make_pair(nx, x - nx*q);
        tie(y, ny) = make_pair(ny, y - ny*q);
    }
    return a;
}

/// @brief ext gcd(拡張ユークリッドの互除法)
/// @return ax+by=gcd(a,b)なるx,yを格納する,返り値にgcd(a,b)