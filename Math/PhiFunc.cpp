#include"template.hpp"
ll phi_func(ll n){
    ll res=n;
    for(ll d=2;d*d<=n;d++){
        if(n%d==0){
            res=res/d*(d-1);

            for(;n%d==0;n/=d){  }
        }
    }
    if(n!=1)res=res/n*(n-1);
    return res;
}