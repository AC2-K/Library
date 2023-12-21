#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"
#include <iostream>
#include "../../../src/stream.hpp"
#include "../../../src/string/manacher.hpp"

using namespace std;
using namespace kyopro;

int main() {
    std::string s;
    read(s);
    auto res = manacher(s);
    for (auto r : res) put(r);
}