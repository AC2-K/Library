#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include"template.hpp"
#include"math/mod_pow.hpp"
#include"math/fast_fact.hpp"
unsigned primitive_root(const unsigned ll p){
    Rho rho;
    if(p == 2) return 1;
    auto pf = rho.fact(p - 1);
    pf.erase(unique(all(pf)),pf.end());
    for(auto&q:pf){
        q=(p-1)/q;
    }
    using ull = unsigned long long;
    static ull rnd = 7001;
    while(1){
        rnd^=rnd<<13; rnd^=rnd>>7; rnd^=rnd<<17;
        ull g = rnd%p;
        if(g == 0) continue;
        bool is_ok = true;
        for(const auto&q : pf){
            if(large_modpow(ll(g),q,p) == 1){ 
                is_ok = false; 
                break; 
            }
        }
        if(is_ok){
            return g;
        }
    }
}
int main(){
    int q;
    cin>>q;
    while (q--){
        ll p;
        cin>>p;
        ll ans=primitive_root(p);
        cout<<ans<<'\n';
    }
}
