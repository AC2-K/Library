ll mod_pow(ll base, ll exp, ll mod) {
    if(base==0)return 0;
    ll ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
template<typename T>
__int128_t large_modpow(T base,T exp,T mod){
    if(base==0)return 0;
    __int128_t ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
///@brief mod pow(バイナリ法)