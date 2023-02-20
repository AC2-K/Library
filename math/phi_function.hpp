#pragma once
#include"math/fast_fact.hpp"
ll phi_func(ll n){
    ll res=n;
    Rho rho;
    auto pf=rho.fact(n);
    pf.erase(unique(all(pf)),pf.end());
    for(auto&p:pf){
        res=res/p*(p-1);
    }
    if(n!=1)res=res/n*(n-1);
    return res;
}