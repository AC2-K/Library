#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"

#include <iostream>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n, m, r;
    kyopro::readint(n, m, r);
    kyopro::dijkstra g(n);
    for (int i = 0; i < m; i++) {
        int s, t, w;
        kyopro::readint(s, t, w);
        g.add_edge(s, t, w);
    }
    g.build(r);
    auto res = g.get_dist();

    for (int v = 0; v < n; v++) {
        if (res[v] >= (long long)1e18)
            puts("INF");
        else
            kyopro::putint(res[v]);
    }
}