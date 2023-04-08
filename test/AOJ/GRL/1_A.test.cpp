#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"

#include <iostream>
#include "../../../graph/dijkstra.hpp"
int main() {
    int n, m, r;
    scanf("%d%d%d", &n, &m, &r);
    std::vector<std::vector<kyopro::edge>> g(n);
    for (int i = 0; i < m; i++) {
        int s, t, w;
        scanf("%d%d%d", &s, &t, &w);
        g[s].emplace_back(t, w);
    }

    auto res = kyopro::dijkstra(r, g).first;

    for (int v = 0; v < n; v++) {
        if (res[v] >= (long long)1e18)
            puts("INF");
        else
            printf("%lld\n", res[v]);
    }
}