#pragma once
#include"math/fast_prime_check.hpp"
namespace prime{
    namespace pollard{
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = __uint64_t;

        template<typename T>
        T gcd(T x, T y) {
            while (y != 0) {
                T ny = x % y;
                T nx = y;
                x = nx, y = ny;
            }
            return x;
        }
        u64 find_factor(u64 n){
            static u64 v = 7001;

            if (~n & 1uL){
                return 2;
            }
            if(is_prime(n)){
                return n;
            }
            while (1) {
                v ^= v << 13, v ^= v >> 7, v ^= v << 17;
                u64 c = v;
                auto f = [&](u128 x) -> u128 {
                    x %= n;
                    return (x * x + c) % n;
                };
                v ^= v << 13, v ^= v >> 7, v ^= v << 17;
                ll x = v % n;
                ll y = f(x);
                u64 d = 1;
                while (d == 1){
                    d = gcd((u64)abs(x - y), n);
                    x = f(x);
                    y = f(f(y));
                }
                if (1 < d && d < n) {
                    return d;
                }
            }
            exit(0);
        }

        vector<u64> rho_fact(u64 n){
            if (n < 2) {
                return {};
            }
            if(is_prime(n)){
                return {n};
            }
            vector<u64> v;
            vector<u64> st{n};
            while (st.size()){
                u64 &m = st.back();
                if (is_prime(m)){
                    v.emplace_back(m);
                    st.pop_back();
                }else{
                    u64 d = find_factor(m);
                    m /= d;
                    st.emplace_back(d);
                }
            }
            return v;
        }
        vector<u64> naive(u64&n){
            static constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353};
            vector<u64> res;
            for (const auto& p : basic_prime) {
                while (n % p == 0) {
                    n /= p;
                    res.emplace_back(p);
                }
            }

            return res;
        }
        vector<u64> fact(u64 n){
            if (n < 2) {
                return {};
            }
            vector<u64> v = naive(n);
            if(n!=1){
                vector<u64> v2 = rho_fact(n);
                v.insert(v.end(), all(v2));
            }
            sort(all(v));
            return v;
        }

        vector<pair<u64,int>> exp_fact(u64 n){
            auto pf = fact(n);
            vector<pair<u64, int>> res;
            res.emplace_back(pf.front(), 1);
            //rle
            for (int i = 1; i < pf.size(); i++){
                if(res.back().first==pf[i]){
                    res.back().second++;
                }else{
                    res.emplace_back(pf[i], 1);
                }
            }

            return res;
        }
    };  // namespace pollard
};  // namespace prime
using prime::pollard::fact;

///@brief 高速素因数分解(Pollard Rho法)