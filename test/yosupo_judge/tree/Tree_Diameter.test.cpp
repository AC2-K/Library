#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include <algorithm>
#include <iostream>
#include <vector>
#include "../../../src/graph/dijkstra.hpp"
#include "../../../src/stream.hpp"
#include"../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n;
    read(n);
    dijkstra<long long> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        read(a, b, c);
        g.add_edge(a, b, c);
        g.add_edge(b, a, c);
    }
    // put("-----");
    g.build(0);
    int v = -1;
    {
        int ma = 0;
        rep(i, n) {
            if (chmax(ma, g.dist(i))) v = i;
            // cout << g.dist(i) << " \n"[i == n - 1];
        }
    }
    // cout << v << '\n';
    g.build(v);
    int u = -1;
    {
        int ma = 0;
        rep(i, n) {
            if (chmax(ma, g.dist(i))) u = i;
            // cout << g.dist(i) << " \n"[i == n - 1];
        }
    }
    // cout << u << '\n';

    vector path = g.shortest_path(u);
    put(g.dist(u), path.size());
    for (auto ui : path) put(ui);
}