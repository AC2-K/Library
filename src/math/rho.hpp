#pragma once
#include <algorithm>
#include <vector>
#include "../math/gcd.hpp"
#include "../math/miller.hpp"
#include "../random/xor_shift.hpp"
namespace kyopro {

/**
 * @brief Pollard Rho 素因数分解法
 */
class rho {
    using i128 = __int128_t;
    using u128 = __uint128_t;
    using u64 = uint64_t;
    using u32 = uint32_t;

    template <typename mint>
    static u64 find_factor(u64 n) {
        xor_shift32 rng(2023);

        if (~n & 1uL) {
            return 2;
        }
        if (kyopro::miller::is_prime(n)) {
            return n;
        }

        if (mint::get_mod() != n) {
            mint::set_mod(n);
        }
        while (1) {
            u64 c = rng();
            const auto f = [&](mint x) -> mint { return x * x + c; };
            mint x = rng();
            mint y = f(x);
            u64 d = 1;
            while (d == 1) {
                d = _gcd<long long>(
                    std::abs((long long)x.val() - (long long)y.val()), n);
                x = f(x);
                y = f(f(y));
            }
            if (1 < d && d < n) {
                return d;
            }
        }
        exit(0);
    }
    template <typename mint>
    static std::vector<u64> rho_fact(u64 n) {
        if (n < 2) {
            return {};
        }
        if (kyopro::miller::is_prime(n)) {
            return {n};
        }
        std::vector<u64> v;
        std::vector<u64> st{n};
        while (st.size()) {
            u64& m = st.back();
            if (kyopro::miller::is_prime(m)) {
                v.emplace_back(m);
                st.pop_back();
            } else {
                u64 d = find_factor<mint>(m);
                m /= d;
                st.emplace_back(d);
            }
        }
        return v;
    }

public:
    static inline std::vector<u64> factorize(u64 n) {
        if (n < 2) {
            return {};
        }
        auto v = (n < (1uL << 31) ? rho_fact<dynamic_modint<u32>>(n)
                                  : rho_fact<dynamic_modint<u64>>(n));
        std::sort(v.begin(), v.end());
        return v;
    }

    static inline std::vector<std::pair<u64, int>> exp_factorize(u64 n) {
        std::vector<u64> pf = factorize(n);
        if (pf.empty()) {
            return {};
        }
        std::vector<std::pair<u64, int>> res;
        res.emplace_back(pf.front(), 1);
        for (int i = 1; i < (int)pf.size(); i++) {
            if (res.back().first == pf[i]) {
                res.back().second++;
            } else {
                res.emplace_back(pf[i], 1);
            }
        }

        return res;
    }
};  // namespace rho
};  // namespace kyopro