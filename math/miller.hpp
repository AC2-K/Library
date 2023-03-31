#pragma once
#include"math/mod_pow.hpp"
namespace prime {
    namespace miller {
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = uint64_t;
        using u32 = uint32_t;

        bool miller_rabin(u64 n, const u64 bases[], int length) {
            u64 d = n - 1;

            while (~d & 1) {
                d >>= 1;
            }

            u64 rev = n - 1;

            for (int i = 0; i < length; i++) {
                u64 a = bases[i];

                if (n <= a) {
                    return true;
                }
                u64 t = d;
                u128 y = mod_pow<u128>(a, t, n);
                while (t != n - 1 && y != 1 && y != rev) {
                    (y *= y) %= n;
                    t <<= 1;
                }

                if (y != rev && (~t & 1))return false;
            }
            return true;
        }


        constexpr u64 bases_int[3] = { 2, 7, 61 };  // intだと、2,7,61で十分
        constexpr u64 bases_ll[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
        bool is_prime(u64 n) {
            if (n < 2) {
                return false;
            }
            else if (n == 2) {
                return true;
            }
            else if (~n & 1) {
                return false;
            }
            if (n < (1ul << 31)) {
                return miller_rabin(n, bases_int, 3);
            }
            else {
                return miller_rabin(n, bases_ll, 7);
            }
        }
    };
};
///@brief MillerRabinの素数判定