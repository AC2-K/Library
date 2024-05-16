#pragma once
#include <ctype.h>
#include <stdio.h>
#include <string>
#include "../src/internal/type_traits.hpp"

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
 * @brief Fast IO(高速入出力)
 */