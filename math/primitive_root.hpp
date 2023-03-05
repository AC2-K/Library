#pragma once
#include"math/large_mod.hpp"
#include"math/fast_fact.hpp"
ll primitive_root(ll p){
    if(p == 2) return 1;
    auto pf = fact(p - 1);
    pf.erase(unique(all(pf)),pf.end());
    for(auto&q:pf){
        q=(p-1)/q;
    }
    using ull = unsigned long long;
    static ull rnd = 7001;
    while(1){
        rnd^=rnd<<13; rnd^=rnd>>7; rnd^=rnd<<17;
        ll g = (ull)rnd%p;
        if(g == 0) continue;
        bool is_ok = true;
        for(ll q : pf){
            if(large_modpow(g,q,p) == 1){ 
                is_ok = false; 
                break; 
            }
        }
        if(is_ok){
            return g;
        }
    }
}

//@brief primitive root(原始根)