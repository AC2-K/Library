#include"template.hpp"
/// @brief 繰り返しニ乗法を用いて、O(log exp)でbase^exp mod Mを計算する
/// @param base 底
/// @param exp 指数
/// @param M mod
/// @return base^exp
ll mod_pow(ll base, ll exp, ll M) {
    ll ans = 1;
    base %= M;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= M;
        }
        base *= base;
        base %= M;
        exp >>= 1;
    }
    return ans;
}