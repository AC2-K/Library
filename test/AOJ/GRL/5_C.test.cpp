#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include "../../../src/stream.hpp"
#include "../../../src/tree/EulerTour.hpp"
int main() {
    int n;
    kyopro::read(n);
    kyopro::EulerTour g(n);
    for (int v = 0; v < n; v++) {
        int k;
        kyopro::read(k);
        for (int i = 0; i < k; i++) {
            int c;
            kyopro::read(c);
            g.add_edge(v, c);
        }
    }

    g.build();
    int q;
    kyopro::read(q);
    while (q--) {
        int u, v;
        kyopro::read(u, v);
        kyopro::put(g.lca(u, v));
    }
}