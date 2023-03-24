#pragma once
#include"math/mod_pow.hpp"
namespace prime {
    namespace miller{
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = __uint64_t;
        bool miller_rabin(u64 n,const u64 bases[],int siz) {
            u64 d = n - 1;
            u64 q = __builtin_ctz(d);
            d >>= q;

            for (int i = 0; i < siz; i++) {
                u64 a = bases[i];
                if (a == n) {
                    return true;
                } else if (n % a == 0) {
                    return false;
                }
                if (mod_pow<u128>(a, d, n) != 1) {
                    bool flag = true;
                    for (u64 r = 0; r < q; r++) {
                        u64 pow = mod_pow<u128>(a, d * (1ll << r), n);
                        if (pow == n - 1) {
                            flag = false;
                            break;
                        }
                    }

                    if (flag) {
                        return false;
                    }
                }
            }
            return true;
        }


        bool is_prime(u64 n){
            static constexpr u64 bases_int[3] = {2, 7, 61};  // intだと、2,7,61で十分
            static constexpr u64 bases_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
            if (n < 2) {
                return false;
            } else if (n == 2) {
                return true;
            } else if (~n & 1) {
                return false;
            }
            if (n < (1ul << 31)) {
                return miller_rabin(n, bases_int, 3);
            } else {
                return miller_rabin(n, bases_ll, 7);
            }
        }
    };
};
///@brief fast prime check(MillerRabinの素数判定)