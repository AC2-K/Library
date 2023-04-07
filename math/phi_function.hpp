#pragma once
#include<algorithm>
#include"math/rho.hpp"
inline long long phi_func(long long n){
    long long res = n;
    auto pf = library::rho::factorize(n);
    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());
    for (const auto &d : pf){
        res = res / d * (d - 1);
    }
    return res;
}
///@brief phi function(\phi 関数)