#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"
#include <iostream>
#include "../../../src/graph/euler_tour.hpp"
int main() {
    int n;
    scanf("%d", &n);
    kyopro::EulerTour g(n);
    for (int v = 0; v < n; v++) {
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            int c;
            scanf("%d", &c);
            g.add_edge(v, c);
        }
    }

    g.build();
    int q;
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", g.lca(u, v));
    }
}