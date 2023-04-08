#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include<iostream>
#include"../../../src/data-structure/BIT.hpp"
#include"../../../src/graph/euler_tour.hpp"

int main() {
    int n, q;
    scanf("%d%d",&n,&q);
    std::vector<long long> a(n);
    for (auto& aa : a) {
        scanf("%lld",&aa);
    }

    kyopro::EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d",&p);
        g.add_edge(i, p);
    }
    g.build();

    kyopro::BIT<long long> seg(2 * n);
    for (int v = 0; v < n; v++) {
        int in = g.idx(v).first;
        seg.add(in, a[v]);
    }
    while (q--) {
        int t;
        scanf("%d",&t);
        if (!t) {
            int v,x;
            scanf("%d%d",&v,&x);
            int in = g.idx(v).first;
            seg.add(in, x);
        }
        else {
            int v;
            scanf("%d",&v);
            auto [in, out] = g.idx(v);
            printf("%lld\n",seg.sum(in,out + 1));
        }
    }
}