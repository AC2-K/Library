#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include "../../../src/stream.hpp"
#include "../../../src/tree/EulerTour.hpp"
int main() {
    int n;
    kyopro::readint(n);
    kyopro::EulerTour g(n);
    for (int v = 0; v < n; v++) {
        int k;
        kyopro::readint(k);
        for (int i = 0; i < k; i++) {
            int c;
            kyopro::readint(c);
            g.add_edge(v, c);
        }
    }

    g.build();
    int q;
    kyopro::readint(q);
    while (q--) {
        int u, v;
        kyopro::readint(u, v);
        kyopro::putint(g.lca(u, v));
    }
}