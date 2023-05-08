#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "../../../src/stream.hpp"
#include "../../../src/tree/EulerTour.hpp"
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        kyopro::readint(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int u, v;
        kyopro::readint(u, v);
        kyopro::putint(g.lca(u, v));
    }
}