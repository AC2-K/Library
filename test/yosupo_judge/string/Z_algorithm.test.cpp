#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include<iostream>
#include<string>

#include"../../../src/string/Z.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;
    auto res = kyopro::Z(s);
    for(const auto&r:res){
        std::cout << r << ' ';
    }
    std::cout << '\n';
}