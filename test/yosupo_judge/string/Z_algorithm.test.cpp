#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include <iostream>
#include <string>

#include "../../../src/stream.hpp"
#include "../../../src/string/Z.hpp"

using namespace std;
using namespace kyopro;
int main() {
    string s;
    read(s);
    auto res = Z(s);
    for (auto r : res) put(r);
}