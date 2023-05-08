#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../src/math/primitive_root.hpp"
#include "../../../src/stream.hpp"
#include <iostream>
int main() {
    int q;
    kyopro::readint(q);
    while (q--) {
        long long p;
        kyopro::readint(p);
        kyopro::putint(kyopro::primitive_root(p));
    }
}
