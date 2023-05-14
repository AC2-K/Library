#pragma once
#include <iostream>
#include <limits>
#include <numeric>
#include <typeinfo>
namespace kyopro {
namespace internal {
/*
 * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8
 */
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

template <int dgt> struct int_least {
    static_assert(dgt <= 128);
    using type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,
                                 std::enable_if<dgt <= 16, __int16_t>,
                                 std::enable_if<dgt <= 32, __int32_t>,
                                 std::enable_if<dgt <= 64, __int64_t>,
                                 std::enable_if<dgt <= 128, __int128_t> >;
};
template <int dgt> struct uint_least {
    static_assert(dgt <= 128);
    using type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,
                                 std::enable_if<dgt <= 16, __uint16_t>,
                                 std::enable_if<dgt <= 32, __uint32_t>,
                                 std::enable_if<dgt <= 64, __uint64_t>,
                                 std::enable_if<dgt <= 128, __uint128_t> >;
};

template <int dgt> using int_least_t = typename int_least<dgt>::type;
template <int dgt> using uint_least_t = typename uint_least<dgt>::type;

template <typename T>
using double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;

template <typename T>
using double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;
};  // namespace internal
};  // namespace kyopro