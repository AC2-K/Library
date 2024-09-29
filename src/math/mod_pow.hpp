#pragma once
#include "../internal/type_traits.hpp"
namespace kyopro {

template <typename T, typename E, typename M>
constexpr inline T mod_pow(T base, E exp, M mod) noexcept {
    internal::double_size_uint_t<M> ans = (mod == 1 ? 0 : 1);
    base %= mod;
    while (exp) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
};  // namespace kyopro

/**
 * @brief Modulo Power(繰り返し二乗法)
 */