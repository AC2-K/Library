#include"template.hpp"
/// @brief 素因数分解をO(\sqrt n))で行う
/// @param n 素因数分解したいやつ
/// @return 結果を渡す。firstに素因数,secondに指数を突っ込んである。
vector<pair<ll, ll>> fact(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll div = 2; div * div <= n; div++) {
        if (n % div != 0)continue;
        ll exp = 0;
        while (n % div == 0) {
            exp++;
            n /= div;
        }
        ret.push_back(make_pair(div, exp));
    }
    if (n != 1)ret.push_back(make_pair(n, 1));
    return ret;
}
