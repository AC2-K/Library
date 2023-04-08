#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"
#include <iostream>
#include "../../../graph/mst.hpp"
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ;
    kyopro::MST g(n);
    for (int i = 0; i < m; i++) {
        int s, t, w;
        scanf("%d%d%d", &s, &t, &w);
        g.add_edge(s, t, w);
    }

    printf("%lld\n", g.result());
}