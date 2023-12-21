#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include <iostream>
#include "../../../src/math/rho.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int q;
    read(q);
    while (q--) {
        uint64_t x;
        read(x);
        const auto pf = rho::factorize(x);
        put(pf.size());
        for (auto p : pf) {
            put(p);
        }
    }
}