#pragma once
#include"math/fast_fact.hpp"
ll phi_func(ll n){
    ll res=n;
    Rho rho;
    auto pf=rho.fact(n);
    pf.erase(unique(all(pf)),pf.end());     
    for(auto&d:pf){
        res=res/d*(d-1);
    }
    return res;
}