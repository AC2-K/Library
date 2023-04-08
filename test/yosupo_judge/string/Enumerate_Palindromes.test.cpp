#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include <iostream>
#include "../../../src/string/manacher.hpp"
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    auto res = kyopro::manacher(s);
    for (const auto& r : res) {
        std::cout << r << ' ';
    }
    std::cout << '\n';
}