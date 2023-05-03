#pragma once
#include <algorithm>
#include "../data-structure/dsu.hpp"

namespace kyopro {
/// @brief 最小全域木
class MST {
    dsu uf;
    struct Edge {
        int v1, v2;
        int cost;
        int id;
        Edge(int v1, int v2, int cost, int id)
            : v1(v1), v2(v2), cost(cost), id(id) {}
    };
    std::vector<Edge> E;
    std::vector<int> V1, V2;

public:
    MST(int V) : uf(V) {}
     void add_edge(int a, int b, long long cost) {
        int sz = E.size();
        E.emplace_back(a, b, cost, sz);
        V1.emplace_back(a), V2.emplace_back(b);
    }
    long long result() {
        std::sort(E.begin(), E.end(), [&](const Edge& e1, const Edge& e2) {
            return e1.cost < e2.cost;
        });
        long long ans = 0;
        for (int i = 0; i < (int)E.size(); i++) {
            int id = E[i].id;
            int a = V1[id], b = V2[id];
            if (uf.same(a, b)) continue;
            uf.merge(a, b);
            ans += E[i].cost;
        }
        return ans;
    }
};
}  // namespace kyopro