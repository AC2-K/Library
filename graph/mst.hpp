#include"data-structure/dsu.hpp"


///@brief Minimum Spannning Tree(最小全域木)
class MST {
    DSU dsu;
    struct Edge {
        int v1, v2;
        int cost;
        int id;
        Edge(int v1, int v2, int cost, int id) :v1(v1), v2(v2), cost(cost), id(id) {  }
    };
    std::vector<Edge> E;
    std::vector<int> V1, V2;
public:
    MST(int V) :dsu(V) {}
    void add_edge(int a, int b, ll cost) {
        int sz = E.size();
        E.emplace_back(a, b, cost, sz);
        V1.emplace_back(a), V2.emplace_back(b);
    }
    ll result() {
        sort(E.begin(), E.end(), [&](Edge e1, Edge e2) {
            return e1.cost < e2.cost;
            });
        ll ans = 0;
        rep(i, E.size()) {
            int len = E[i].cost;
            int id = E[i].id;
            int a = V1[id], b = V2[id];
            if (dsu.same(a, b))continue;
            dsu.merge(a, b);
            ans += len;
        }
        return ans;
    }
};