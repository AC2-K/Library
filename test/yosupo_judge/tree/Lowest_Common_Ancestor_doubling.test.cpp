#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"
using namespace std;
int main() {
    int n, q;
    kyopro::read(n, q);
    kyopro::doubling g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        kyopro::read(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int a, b;
        kyopro::read(a, b);
        kyopro::put(g.lca(a, b));
    }
}