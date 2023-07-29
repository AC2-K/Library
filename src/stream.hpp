#pragma once
#include <ctype.h>
#include <stdio.h>
#include <string>
#include "../src/internal/type_traits.hpp"

namespace kyopro {
// read
void single_read(char& c) {
    c = getchar_unlocked();
    while (isspace(c)) c = getchar_unlocked();
}
template <typename T,
          std::enable_if_t<std::is_integral<T>::value ||
                           std::is_same<T, __int128_t>::value |
                               std::is_same<T, __uint128_t>::value>* = nullptr,
          internal::is_modint_t<T>* = nullptr>
void single_read(T& a) {
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
void single_read(std::string& str) {
    char c = getchar_unlocked();
    while (isspace(c)) c = getchar_unlocked();
    while (!isspace(c)) {
        str += c;
        c = getchar_unlocked();
    }
}

void read() {}
template <typename Head, typename... Tail>
void read(Head& head, Tail&... tail) {
    single_read(head), read(tail...);
}

// write
void single_write(char c) { putchar_unlocked(c); }
template <typename T,
          std::enable_if_t<std::is_integral<T>::value ||
                           std::is_same<T, __int128_t>::value ||
                           std::is_same<T, __uint128_t>::value>* = nullptr>
void single_write(T a) {
    if (!a) {
        putchar_unlocked('0');
        putchar_unlocked('\n');
        return;
    }
    if (a < 0) putchar_unlocked('-'), a *= -1;
    char s[37];
    int now = 37;
    while (a) {
        s[--now] = (char)'0' + a % 10;
        a /= 10;
    }
    while (now < 37) putchar_unlocked(s[now++]);
}
template <typename T, internal::is_modint_t<T>* = nullptr>
void single_write(T a) {
    single_write(a.val());
}

void single_write(const std::string& str) {
    for (auto c : str) {
        putchar_unlocked(c);
    }
}
void write() {}
template <typename Head, typename... Tail> void write(Head head, Tail... tail) {
    single_write(head);
    putchar_unlocked(' ');
    write(tail...);
}
template <typename... Args> void put(Args... x) {
    write(x...);
    putchar_unlocked('\n');
}
};  // namespace kyopro

/**
 * @brief fastIO
 */