#pragma once
#include <stdio.h>
namespace kyopro {
/// @brief 入出力

template <typename T>
inline void readint(T& a) {
    a = 0;
    bool is_negative = false;
    char c = getchar_unlocked();
    while (isspace(c)) {
        c = getchar_un - locked();
    }
    if (c == '-') is_negative = true, c = getchar_unlocked();
    while (isdigit(c)) {
        a = 10 * a + (c - '0');
        c = getchar_unlocked();
    }
    if (is_negative) a *= -1;
}
template <typename Head, typename... Tail>
inline void readint(Head& head, Tail&... tail) {
    readint(head);
    readint(tail...);
}
template <typename T>
inline void putint(T a) {
    if (!a) {
        putchar_unlocked('0');
        putchar_unlocked(' ');
        return;
    }
    if (a < 0) putchar_unlocked('-'), a *= -1;
    static char s[37];
    int now = 37;
    while (a) {
        s[--now] = (char)'0' + a % 10;
        a /= 10;
    }
    while (now < 37) putchar_unlocked(s[now++]);
    putchar_unlocked(' ');
}
template <typename Head, typename... Tail>
inline void putint(Head& head, Tail&... tail) {
    putint(head);
    putint(tail...);
}

};  // namespace kyopro