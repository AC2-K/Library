#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"
int main() {
    int n;
    kyopro::read(n);
    kyopro::dijkstra g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        kyopro::read(a, b, c);
        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }
    g.build(0);
    std::vector<long long> dist = g.get_dist();
    int v = std::max_element(dist.begin(), dist.end()) - dist.begin();
    g.build(v);
    dist = g.get_dist();

    auto it = std::max_element(dist.begin(), dist.end());
    int u = it - dist.begin();
    kyopro::put(*it);
    auto path = g.shortest_path(u).second;
    kyopro::put(path.size());
    for (auto v : path) kyopro::put(v);
}