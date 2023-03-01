#pragma once
#include "large_mod.hpp"

namespace prime
{
    using ull = unsigned long long;
    // MillerRabin
    bool is_prime_long(ull n){
        static const vector<ull> bases 
            = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};

        ull d = n ^ 1uL;
        ull q = __builtin_ctz(d);
        d >>= q;

        for (const auto &a : bases){
            if (a == n){
                return true;
            }
            else if (a % n == 0){
                return false;
            }

            if (i128_modpow(a, d, n) != 1){
                bool is_prime_flag = true;
                for (ull r = 0; r < q;r++){
                    ull pw = i128_modpow(a, d * (1uL << r), n);

                    if(pw==n-1){
                        is_prime_flag = false;
                        break;
                    }
                }

                if(is_prime_flag){
                    return false;
                }
            }
        }
        return true;
    }

    bool is_prime_int(ull n){
        static const vector<ull> bases 
            = {2ull, 7ull, 61ull};

        ull d = n ^ 1uL;
        ull q = __builtin_ctzll(d);
        d >>= q;
        for (const auto &a : bases){
            if (a == n){
                return true;
            }
            else if (a % n == 0){
                return false;
            }

            if (i128_modpow(a, d, n) != 1){
                bool is_prime_flag = true;
                for (ull r = 0; r < q;r++){
                    ull pw = i128_modpow(a, d * (1uL << r), n);

                    if(pw==n-1){
                        is_prime_flag = false;
                        break;
                    }
                }

                if(is_prime_flag){
                    return false;
                }
            }
        }
        return true;
    }

    inline bool is_prime(ull n){
        if (n < 2){
            return false;
        }
        if(n == 2){
            return true;
        }
        if (~n & 1uL){
            return false;
        }

        
        if (n <= (1uL << 31)){
            return is_prime_int(n);
        }
        else{
            return is_prime_long(n);
        }
    }
};
///@brief fast prime check(MillerRabinの素数判定法)