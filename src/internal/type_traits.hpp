#pragma once
#include <iostream>
#include <limits>
#include <numeric>
#include <typeinfo>
#include <cstdint>

namespace kyopro {
namespace internal {
template <typename... Args> struct first_enabled {};

template <typename T, typename... Args>
struct first_enabled<std::enable_if<true, T>, Args...> {
    using type = T;
};
template <typename T, typename... Args>
struct first_enabled<std::enable_if<false, T>, Args...>
    : first_enabled<Args...> {};
template <typename T, typename... Args> struct first_enabled<T, Args...> {
    using type = T;
};

template <typename... Args>
using first_enabled_t = typename first_enabled<Args...>::type;

template <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct int_least {
    using type = first_enabled_t<std::enable_if<dgt <= 8, std::int8_t>,
                                 std::enable_if<dgt <= 16, std::int16_t>,
                                 std::enable_if<dgt <= 32, std::int32_t>,
                                 std::enable_if<dgt <= 64, std::int64_t>,
                                 std::enable_if<dgt <= 128, __int128_t>>;
};

template <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least {
    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,
                                 std::enable_if<dgt <= 16, std::uint16_t>,
                                 std::enable_if<dgt <= 32, std::uint32_t>,
                                 std::enable_if<dgt <= 64, std::uint64_t>,
                                 std::enable_if<dgt <= 128, __uint128_t>>;
};

template <int dgt> using int_least_t = typename int_least<dgt>::type;
template <int dgt> using uint_least_t = typename uint_least<dgt>::type;

template <typename T>
using double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;

template <typename T>
using double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;

struct modint_base {};
template <typename T> using is_modint = std::is_base_of<modint_base, T>;
template <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;


// is_integral
template <typename T>
using is_integral_t =
    std::enable_if_t<std::is_integral_v<T> || std::is_same_v<T, __int128_t> ||
                   std::is_same_v<T, __uint128_t>>;
};  // namespace internal
};  // namespace kyopro

/**
 * @brief Type Traits
 * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8
 */