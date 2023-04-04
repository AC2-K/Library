#pragma once
#include"math/rho.hpp"
ll phi_func(ll n){
    ll res = n;
    auto pf = prime::rho::factorize(n);
    pf.erase(unique(all(pf)), pf.end());
    for (auto& d : pf) {
        res = res / d * (d - 1);
    }
    return res;
}
///@brief phi function(\phi 関数)