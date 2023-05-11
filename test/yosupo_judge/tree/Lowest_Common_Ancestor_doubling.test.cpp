#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include"../../../src/tree/tree.hpp"
#include"../../../src/stream.hpp"
using namespace std;
using namespace kyopro;
int main() {
    int n, q;
    readint(n, q);
    Tree g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        readint(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int a, b;
        readint(a, b);
        putint(g.lca(a, b));
    }
}