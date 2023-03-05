#pragma once
#include"math/fast_fact.hpp"
ll phi_func(ll n){
    ll res=n;
    auto pf=fact(n);
    pf.erase(unique(all(pf)),pf.end());     
    for(auto&d:pf){
        res=res/d*(d-1);
    }
    return res;
}
///@brief phi function(トーシェント関数)