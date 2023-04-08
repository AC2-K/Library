#pragma once
namespace kyopro {

///@brief mod pow(繰り返しニ乗法)
template <class T, class U = T> constexpr T mod_pow(T base, T exp, T mod) {
    U ans = 1;
    base %= mod;
    while (exp) {
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
};  // namespace kyopro