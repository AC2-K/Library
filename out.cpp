#line 1 "src/debug.hpp"
#ifdef ONLINE_JUDGE
#define debug(x) void(0)
#else
#define _GLIBCXX_DEBUG
#define debug(x) std::cerr << __LINE__ << " : " << #x << " = " << (x) << std::endl
#endif
#line 2 "src/stream.hpp"
#include <ctype.h>
#include <stdio.h>
#include <string>
#line 2 "src/internal/type_traits.hpp"
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

/*
 * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8
 */
#line 6 "src/stream.hpp"

namespace kyopro {

inline void single_read(char& c) {
    c = getchar_unlocked();
    while (isspace(c)) c = getchar_unlocked();
}
template <typename T, internal::is_integral_t<T>* = nullptr>
inline void single_read(T& a) {
    a = 0;
    bool is_negative = false;
    char c = getchar_unlocked();
    while (isspace(c)) {
        c = getchar_unlocked();
    }
    if (c == '-') is_negative = true, c = getchar_unlocked();
    while (isdigit(c)) {
        a = 10 * a + (c - '0');
        c = getchar_unlocked();
    }
    if (is_negative) a *= -1;
}
template <typename T, internal::is_modint_t<T>* = nullptr>
inline void single_read(T& a) {
    long long x;
    single_read(x);
    a = T(x);
}
inline void single_read(std::string& str) noexcept {
    char c = getchar_unlocked();
    while (isspace(c)) c = getchar_unlocked();
    while (!isspace(c)) {
        str += c;
        c = getchar_unlocked();
    }
}
template<typename T>
inline void read(T& x) noexcept {single_read(x);}
template <typename Head, typename... Tail>
inline void read(Head& head, Tail&... tail) noexcept {
    single_read(head), read(tail...);
}

inline void single_write(char c) noexcept { putchar_unlocked(c); }
template <typename T, internal::is_integral_t<T>* = nullptr>
inline void single_write(T a) noexcept {
    if (!a) {
        putchar_unlocked('0');
        return;
    }
    if constexpr (std::is_signed_v<T>) {
        if (a < 0) putchar_unlocked('-'), a *= -1;
    }
    constexpr int d = std::numeric_limits<T>::digits10;
    char s[d + 1];
    int now = d + 1;
    while (a) {
        s[--now] = (char)'0' + a % 10;
        a /= 10;
    }
    while (now <= d) putchar_unlocked(s[now++]);
}
template <typename T, internal::is_modint_t<T>* = nullptr>
inline void single_write(T a) noexcept {
    single_write(a.val());
}
inline void single_write(const std::string& str) noexcept {
    for (auto c : str) {
        putchar_unlocked(c);
    }
}
template <typename T> inline void write(T x) noexcept { single_write(x); }
template <typename Head, typename... Tail>
inline void write(Head head, Tail... tail) noexcept {
    single_write(head);
    putchar_unlocked(' ');
    write(tail...);
}
template <typename... Args> inline void put(Args... x) noexcept {
    write(x...);
    putchar_unlocked('\n');
}
};  // namespace kyopro

/**
 * @brief 高速入出力
 */
#line 2 "src/template.hpp"
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) std::begin(x), std::end(x)
#define popcount(x) __builtin_popcountll(x)
using i128 = __int128_t;
using ll = long long;
using ld = long double;
using graph = std::vector<std::vector<int>>;
using P = std::pair<int, int>;
constexpr int inf = std::numeric_limits<int>::max() / 2;
constexpr ll infl = std::numeric_limits<ll>::max() / 2;
const long double pi = acosl(-1);
constexpr uint64_t MOD = 1e9 + 7;
constexpr uint64_t MOD2 = 998244353;
constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
template <typename T1, typename T2> constexpr inline bool chmax(T1& a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {
    return a > b && (a = b, true);
}
#line 4 "main.cpp"
using namespace std;
using namespace kyopro;

int main() {
	
}
