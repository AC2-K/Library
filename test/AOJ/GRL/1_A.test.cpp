#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"

#include <iostream>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, m, r;
    read(n, m, r);
    dijkstra<long long> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, w;
        read(s, t, w);
        g.add_edge(s, t, w);
    }
    g.build(r);
    vector res = g.dists();

    for (int v = 0; v < n; v++) {
        if (res[v] >= g.COST_INF)
            puts("INF");
        else
            kyopro::put(res[v]);
    }
}