#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <algorithm>
#include <iostream>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, m, s, t;
    read(n, m, s, t);
    dijkstra<long long> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        read(a, b, c);
        g.add_edge(a, b, c);
    }

    g.build(s);

    if (g.dist(s) >= dijkstra<long long>::COST_INF) {
        put(-1);
        return 0;
    }

    vector path = g.shortest_path(t);
    kyopro::put(g.dist(t), path.size() - 1);
    for (int i = 1; i < (int)path.size(); i++)
        kyopro::put(path[i - 1], path[i]);
}