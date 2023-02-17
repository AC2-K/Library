#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include"template.hpp"
#include"Math/fast_fact.hpp"
#include"Math/mod_pow.hpp"
Rho rho;
ll primitive_root(ll p){
    if(p==2)return 1;
    mt19937_64 mt;
    auto pf=rho.fact(p-1);
    pf.erase(unique(all(pf)),pf.end());
    for(auto&d:pf){
        d=(p-1)/d;
    }
    ll a;
    while(true){
        a=mt()%p;
        if(a==0)continue;
        if(a<0)a+=p;
        bool is_ok=true;
        for(const auto&d:pf){
            if(mod_pow(a,d,p)==1){
                is_ok=false;
                break;
            }
        }
        if(is_ok){
            return a;
        }
    }
}
int main(){
    int q;
    cin>>q;
    while(q--){
        ll p;
        cin>>p;
        cout<<primitive_root(p)<<'\n';
    }
}