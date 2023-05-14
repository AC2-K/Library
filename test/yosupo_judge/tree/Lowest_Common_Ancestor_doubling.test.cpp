#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"
using namespace std;
int main() {
    int n, q;
    kyopro::readint(n, q);
    kyopro::doubling_on_tree g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        kyopro::readint(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int a, b;
        kyopro::readint(a, b);
        kyopro::putint(g.lca(a, b));
    }
}