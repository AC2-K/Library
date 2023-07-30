#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <iostream>
#include "../../../src/math/rho.hpp"
#include "../../../src/stream.hpp"
int main() {
    int q;
    kyopro::read(q);
    while (q--) {
        uint64_t x;
        kyopro::read(x);
        const auto pf = kyopro::rho::factorize(x);
        kyopro::put(pf.size());
        for (auto p : pf) {
            kyopro::put(p);
        }
    }
}