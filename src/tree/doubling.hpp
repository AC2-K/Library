#pragma once
#include <cassert>
#include <vector>

/**
 * @brief doubling on tree
 */
namespace kyopro {
class doubling_on_tree {
    struct edge {
        const int to;
        const int cost;
        edge() = default;
        constexpr explicit edge(int to, int cost) : to(to), cost(cost) {}
    };
    const int n;
    static constexpr int lg = 21;
    std::vector<std::vector<edge>> g;
    std::vector<int> parent[lg];
    std::vector<long long> _dist;
    std::vector<int> _depth;

public:
    explicit doubling_on_tree(int n) : n(n), g(n), _dist(n, -1), _depth(n) {
        std::fill(parent, parent + lg, std::vector<int>(n));
    }
    void add_edge(int a, int b, int c = 1) {
        g[a].emplace_back(b, 1);
        g[b].emplace_back(a, 1);
    }
    void build(int root = 0) {
        std::vector<int> st;
        st.reserve(n);

        st.emplace_back(root);
        _dist[root] = 0, _depth[root] = 0, parent[0][root] = root;
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();

            for (auto [nv, c] : g[v]) {
                if (_dist[nv] != -1) continue;
                _dist[nv] = _dist[v] + c;
                _depth[nv] = _depth[v] + 1;
                parent[0][nv] = v;

                st.emplace_back(nv);
            }
        }

        for (int i = 0; i < lg; ++i) {
            for (int v = 0; v < n; ++v) {
                parent[i + 1][v] = parent[i][parent[i][v]];
            }
        }
    }

    int level_ancestor(int v, const int k) const {
        if (_depth[v] < k) return -1;

        for (int i = 0; i < lg; ++i) {
            if (k >> i & 1) {
                v = parent[i][v];
            }
        }
        return v;
    }

    int dist(int v) const { return _dist[v]; }
    int dist(int u, int v) const {
        return _dist[u] + _dist[v] - 2 * _dist[lca(u, v)];
    }
    int depth(int v) const { return _depth[v]; }
    int diff_depth(int u, int v) {
        return _depth[u] + _depth[v] - 2 * _depth[lca(u, v)];
    }
    int lca(int a, int b) const {
        if (_depth[a] > _depth[b]) {
            std::swap(a, b);
        }
        if (_depth[a] != _depth[b]) {
            b = level_ancestor(b, _depth[b] - _depth[a]);
        }
        if (a == b) return a;
        for (int k = lg - 1; k >= 0; --k) {
            if (parent[k][a] != parent[k][b]) {
                a = parent[k][a];
                b = parent[k][b];
            }
        }
        return parent[0][a];
    }

    int jump(const int from, const int to, const int k) const {
        int p = lca(from, to);
        int d1 = _depth[from] - _depth[p];
        int d2 = _depth[to] - _depth[p];

        if (d1 + d2 < k) {
            return -1;
        }

        if (d1 >= k) {
            return level_ancestor(from, k);
        } else {
            return level_ancestor(to, d1 + d2 - k);
        }
    }
};
};  // namespace kyopro

/**
 * @docs docs/tree/doubling.md
 */
