#pragma once
#include"Math/fast_prime_check.hpp"
class Rho{
    using i128=__int128_t;
    mt19937 mt;
    MillerRabin mr;
    long long c;
    ll f(i128 x,ll n){
        x%=n;
        return (x*x%n+c)%n;
    }
public:
    Rho(){
        mt.seed(clock());
    }

    ll find_factor(ll n){
        if(n==4){
            return 2;
        }
        c=mt()%n;
        ll x=mt()%n;
        ll y=x;
        ll d=1;

        while(d==1){
            x=f(x,n);
            y=f(f(y,n),n);
            d=__gcd(abs(x-y),n);
        }

        if(d==n){
            return -1;
        }
        return d;
    }


    vector<ll> fact(const ll n,bool sorting=true){
        if(n<2){
            return {};
        }
        if(mr.is_prime(n)){
            return{n};
        }
        ll res=-1;
        while(res==-1){
            res=find_factor(n);
        }
        vector<ll> V1=fact(res,false);
        vector<ll> V2=fact(n/res,false);
        V1.insert(V1.end(),V2.begin(),V2.end());
        if(sorting)sort(V1.begin(),V1.end());
        return V1;
    }
};