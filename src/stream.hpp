#pragma once
#include <stdio.h>
#include <ctype.h>
namespace kyopro {
/// @brief 入出力

template <typename T>
constexpr inline void readint(T& a) {
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
template <typename Head, typename... Tail>
constexpr inline void readint(Head& head, Tail&... tail) {
    readint(head);
    readint(tail...);
}
template <typename T>
constexpr inline void putint(T a) {
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
    putchar_unlocked('\n');
}
template <typename Head, typename... Tail>
constexpr inline void putint(Head& head, Tail&... tail) {
    putint(head);
    putint(tail...);
}

};  // namespace kyopro