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

    template <typename T,typename mint> static constexpr T find_factor(T n) {
        xor_shift32 rng(2023);

        if (~n & 1uL) {
            return 2;
        }
        if (kyopro::miller::is_prime(n)) {
            return n;
        }

        if (mint::mod() != n) {
            mint::set_mod(n);
        }
        while (1) {
            T c = rng();
            const auto f = [&](mint x) -> mint { return x * x + c; };
            mint x = rng();
            mint y = f(x);
            T d = 1;
            while (d == 1) {
                d = _gcd<std::make_signed_t<T>>(
                    std::abs((std::make_signed_t<T>)x.val() - (std::make_signed_t<T>)y.val()), n);
                x = f(x);
                y = f(f(y));
            }
            if (1 < d && d < n) {
                return d;
            }
        }
        exit(-1);
    }
    template <typename T,typename mint> static std::vector<T> rho_fact(T n) {
        if (n < 2) {
            return {};
        }
        if (kyopro::miller::is_prime(n)) {
            return {n};
        }
        std::vector<T> v;
        std::vector<T> st{n};
        while (!st.empty()) {
            u64 m = st.back();
            if (kyopro::miller::is_prime(m)) {
                v.emplace_back(m);
                st.pop_back();
            } else {
                T d = find_factor<T, mint>(m);
                st.back() /= d;
                st.emplace_back(d);
            }
        }
        return v;
    }

public:
    template <typename T> static std::vector<T> factorize(T n) {
        if (n < 2) {
            return {};
        }

        if constexpr (std::numeric_limits<T>::digits < 32) {
            std::vector v = rho_fact<T, montgomery_modint<u32>>(n);
            std::sort(v.begin(), v.end());
            return v;
        } else {
            std::vector v = rho_fact<T, montgomery_modint<u64>>(n);
            std::sort(v.begin(), v.end());
            return v;
        }
    }
    template<typename T>
    static std::vector<std::pair<T, int>> exp_factorize(T n) {
        std::vector pf = factorize(n);
        if (pf.empty()) {
            return {};
        }
        std::vector<std::pair<T, int>> res;
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
    template<typename T>
    static std::vector<T> enumerate_divisor(T n) {
        std::vector<std::pair<T, int>> pf = rho::exp_factorize(n);
        std::vector<T> divisor{1};
        for (auto [p, e] : pf) {
            u64 pow = p;
            int sz = divisor.size();
            for (int i = 0; i < e; ++i) {
                for (int j = 0; j < sz; ++j)
                    divisor.emplace_back(divisor[j] * pow);
                pow *= p;
            }
        }

        return divisor;
    }
};
};  // namespace kyopro

/**
 * @docs docs/math/rho.md
 */