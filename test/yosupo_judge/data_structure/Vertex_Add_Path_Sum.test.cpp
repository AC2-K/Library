#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
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
    for (int i = 0; i < n; ++i) read(a[i]);

    EulerTour g(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        read(v, u);
        g.add_edge(v, u);
    }
    g.build();

    BIT<long long> seg(2 * n);
    for (int v = 0; v < n; v++) {
        auto [in, out] = g.idx(v);
        seg.add(in, a[v]);
        seg.add(out + 1, -a[v]);
    }

    while (q--) {
        int t;
        read(t);
        if (t == 0) {
            int v, x;
            read(v, x);
            auto [in, out] = g.idx(v);
            seg.add(in, x);
            seg.add(out + 1, -x);
        } else {
            int v, u;
            read(v, u);
            long long ans = 0;
            int p_in = g.idx(g.lca(v, u)).first;
            ans += seg.sum(p_in, g.idx(v).first + 1);
            ans += seg.sum(p_in + 1, g.idx(u).first + 1);
            put(ans);
        }
    }
}