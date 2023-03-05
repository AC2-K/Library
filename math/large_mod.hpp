#pragma once
inline long long safe_mod(long long a, long long m){
    return (a % m + m) % m;
}
long long mul(long long a, long long b, long long m) {
    a = safe_mod(a, m);
    b = safe_mod(b, m);
    if (b == 0) return 0;
    long long res = mul(safe_mod(a + a, m), b >> 1, m);
    if (b & 1){
        res = safe_mod(res + a, m);
    }
    return res;
}
template<typename T>
T large_modpow(T base,T exp,T mod){
    T ans = 1 % mod;
    base %= mod;
    while (exp) {
        if (exp & 1) {
            ans = mul(ans, base, mod);
        }
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return ans;
}
