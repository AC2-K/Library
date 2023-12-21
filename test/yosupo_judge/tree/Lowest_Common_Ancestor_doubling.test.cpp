#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "../../../src/stream.hpp"
#include "../../../src/tree/doubling.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    doubling g(n);
    for (int i = 1; i < n; ++i) {
        int p;
        read(p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int a, b;
        read(a, b);
        put(g.lca(a, b));
    }
}