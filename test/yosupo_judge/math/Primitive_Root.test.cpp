#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "../../../src/math/primitive_root.hpp"
#include <iostream>
#include "../../../src/stream.hpp"
int main() {
    int q;
    kyopro::read(q);
    while (q--) {
        long long p;
        kyopro::read(p);
        kyopro::put(kyopro::primitive_root(p));
    }
}
