#pragma once
#include <cassert>
#include <vector>
#include "../internal/CSR.hpp"

namespace kyopro {

template <typename Cost, int lg> class doubling {
    struct edge {
        int to;
        Cost cost;

        edge() : to(0), cost(0) {}
        edge(int to, Cost cost) : to(to), cost(cost) {}
    };

    const int n;

    std::vector<std::pair<int, edge>> es;
    std::vector<int> parent[lg];
    std::vector<Cost> _dist;
    std::vector<int> _depth;

public:
    doubling(int n) : n(n), _dist(n, -1), _depth(n) {
        std::fill(parent, parent + lg, std::vector<int>(n));
        es.reserve(2 * (n - 1));
    }

    void add_edge(int a, int b, Cost c = 1) {
        es.emplace_back(a, edge{b, c});
        es.emplace_back(b, edge{a, c});
    }
    
    void build(int root = 0) {
        internal::csr g(n, es);

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

    long long dist(int v) const { return _dist[v]; }
    long long dist(int u, int v) const {
        return dist(u) + dist(v) - 2 * dist(lca(u, v));
    }
    int depth(int v) const { return _depth[v]; }
    int unweighted_dist(int u, int v) const {
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
 *
 * @brief Binary Lifting(木上のダブリング)
 * @docs docs/tree/doubling.md
 */