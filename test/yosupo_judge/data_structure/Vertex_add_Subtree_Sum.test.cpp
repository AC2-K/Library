#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <iostream>
#include "../../../src/data-structure/BIT.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/tree/EulerTour.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, q;
    read(n, q);
    vector<long long> a(n);
    for (auto& aa : a) read(aa);

    EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        read(p);
        g.add_edge(i, p);
    }
    g.build();

    BIT<long long> seg(2 * n);
    for (int v = 0; v < n; v++) {
        int in = g.idx(v).first;
        seg.add(in, a[v]);
    }
    while (q--) {
        int t;
        read(t);
        if (!t) {
            int v, x;
            read(v, x);
            int in = g.idx(v).first;
            seg.add(in, x);
        } else {
            int v;
            read(v);
            auto [in, out] = g.idx(v);
            put(seg.sum(in, out + 1));
        }
    }
}