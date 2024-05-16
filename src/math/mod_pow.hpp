#pragma once
#include "../internal/type_traits.hpp"
namespace kyopro {

template <typename T>
constexpr T mod_pow(internal::double_size_uint_t<T> base, T exp, T mod) {
    internal::double_size_uint_t<T> ans = (mod == 1 ? 0 : 1);
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