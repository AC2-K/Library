#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <iostream>
#include "../../../src/data-structure/BIT.hpp"
#include "../../../src/tree/EulerTour.hpp"

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    std::vector<long long> a(n);
    for (auto& aa : a) {
        scanf("%lld", &aa);
    }

    kyopro::EulerTour g(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        scanf("%d%d", &v, &u);
        g.add_edge(v, u);
    }
    g.build();

    kyopro::BIT<long long> seg(2 * n);
    for (int v = 0; v < n; v++) {
        auto [in, out] = g.idx(v);
        seg.add(in, a[v]);
        seg.add(out + 1, -a[v]);
    }
    while (q--) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int v, x;
            scanf("%d%d", &v, &x);
            auto [in, out] = g.idx(v);
            seg.add(in, x);
            seg.add(out + 1, -x);
        } else {
            int v, u;
            scanf("%d%d", &v, &u);
            long long ans = 0;
            int p_in = g.idx(g.lca(v, u)).first;
            { ans += seg.sum(p_in, g.idx(v).first + 1); }
            { ans += seg.sum(p_in + 1, g.idx(u).first + 1); }

            printf("%lld\n", ans);
        }
    }
}