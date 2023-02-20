#pragma once
#include"data-structure/sparse_table.hpp"
class LCA {
    using graph = vector<vector<int>>;
    int n;
    graph g;
    vector<int> vs, in;
    SparseTable<pair<int,int>> seg;
public:
    LCA(const graph& g) :g(g), n(g.size()),in(n) { }
    void setup() {
        int p = 0;
        vector<pair<int,int>> vec(2 * n);
        function<void(int, int, int)> dfs = [&](int v, int par, int now_depth) -> void {
            in[v] = p;
            vec[p++]={now_depth,v};
            for (const auto& ch : g[v])if (ch != par) {
                dfs(ch, v, now_depth + 1);
                vec[p++] = { now_depth,v };
            }
        };
        dfs(0, -1, 0);
        seg = SparseTable<pair<int, int>>(vec);
    }

    int query(int u, int v) {
        if (in[u] >= in[v])swap(u, v);
        return seg.prod(in[u], in[v] + 1).second;
    }
};