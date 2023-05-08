#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include <iostream>
#include "../../../src/string/manacher.hpp"
#include "../../../src/stream.hpp"
int main() {
    std::string s;
    {
        char c;
        while (!isspace(c = getchar_unlocked())) s += c;
    }
    auto res = kyopro::manacher(s);
    for (auto r : res) {
        kyopro::putint(r);
    }
}