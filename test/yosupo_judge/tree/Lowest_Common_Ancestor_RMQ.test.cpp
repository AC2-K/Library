#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include "../../../src/stream.hpp"
#include "../../../src/tree/EulerTour.hpp"

using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        read(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int u, v;
        read(u, v);
        put(g.lca(u, v));
    }
}