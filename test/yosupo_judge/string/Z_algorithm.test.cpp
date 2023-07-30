#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <iostream>
#include <string>

#include "../../../src/stream.hpp"
#include "../../../src/string/Z.hpp"

int main() {
    std::string s;
    {
        char c;
        while (!isspace(c = getchar_unlocked())) s += c;
    }
    auto res = kyopro::Z(s);
    for (auto r : res) {
        kyopro::put(r);
    }
}