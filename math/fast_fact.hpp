#pragma once
#include"math/fast_prime_check.hpp"
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
private:
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


    vector<ll> rho_fact(const ll&n){
        if(n<2){
            return {};
        }
        if(mr.is_prime(n)){
            return{n};
        }
        ll d=-1;
        while(d==-1){
            d=find_factor(n);
        }
        vector<ll> v1=fact(d);
        vector<ll> v2=fact(n/d);
        v1.insert(v1.end(),v2.begin(),v2.end());
        return v1;
    }
    vector<ll> naive_fact(ll n){
        vector<ll> ret;
        for (ll div = 2; div * div <= n; div++) {
            if (n % div != 0)continue;
            ll exp = 0;
            while (n % div == 0) {
                ret.push_back(div);
                n /= div;
            }
        }
        if (n != 1)ret.push_back(n);
        return ret;
    }

public:
    vector<ll> fact(const ll n){
        vector<ll> res;
        if(n<=1000){
            res=naive_fact(n);
        }else{
            res=rho_fact(n);
        }
        sort(all(res));
        return res;
    }
};
///@brief Rho法による高速素因数分解