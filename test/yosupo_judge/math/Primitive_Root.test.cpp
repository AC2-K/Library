#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../src/math/primitive_root.hpp"
#include <iostream>
#include "../../../src/stream.hpp"
int main() {
    int q;
    kyopro::readint(q);
    while (q--) {
        long long p;
        kyopro::readint(p);
        kyopro::putint(kyopro::primitive_root(p));
    }
}
