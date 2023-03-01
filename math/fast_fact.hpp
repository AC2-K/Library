#pragma once
#include"math/fast_prime_check.hpp"
#include"math/prime_list.hpp"
namespace prime
{
    using ull = unsigned long long;
    // Rho factorize
    
    ll find_factor(ll n){
        static ull v = 7001;
        v ^= v << 13, v ^= v >> 7, v ^= v << 17;
        /*
        if (n == 4){
            return 2;
        }
        */

        if (~n & 1uL){
            return 2;
        }
        static ull c=v;
        auto f = [&](i128 x) -> ll {
            x %= n;
            return (x * x % n + c) % n;
        };
        ll x = v % n;
        ll y=x;
        ll d=1;

        while (d == 1){
            x = f(x);
            y = f(f(y));
            d = __gcd(abs(x - y), n);
        }

        if (d == n){
            return -1;
        }
        return d;
    }
    vector<ll> rho_fact(ll&n){
        if (n < 2){
            return {};
        }
        if(is_prime(n)){
            return {n};
        }
        ll d=-1;
        while (d == -1){
            d=find_factor(n);
        }
        n /= d;
        vector<ll> v1 = rho_fact(n);
        vector<ll> v2 = rho_fact(d);
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }

    vector<ll> naive_fact(ll&n){
        vector<ll> res;
        
        for (const ll d :prime_list1000){
            while (n % d == 0){
                res.push_back(d);
                n /= d;
            }
        }
        return res;
    }

    vector<ll> fact(ll n){
        vector<ll> res = naive_fact(n);
        vector<ll> res2=rho_fact(n);
        res.insert(res.end(), all(res2));
        sort(all(res));
        return res;
    }
};
///@brief fast factorize(Pollard Rhoの素因数分解)