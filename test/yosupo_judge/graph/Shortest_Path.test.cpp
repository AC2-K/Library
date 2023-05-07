#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <algorithm>
#include <iostream>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n, m, s, t;
    kyopro::readint(n, m, s, t);

    kyopro::dijkstra g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        kyopro::readint(a, b, c);
        g.add_edge(a, b, c);
    }

    g.build(s);
    auto [dist, path] = g.shortest_path(t);
    if (path.empty()) {
        kyopro::putint(-1);
        exit(0);
    }
    kyopro::putint(dist, path.size() - 1);
    for (int i = 1; i < (int)path.size(); i++) {
        kyopro::putint(path[i - 1], path[i]);
    }
}