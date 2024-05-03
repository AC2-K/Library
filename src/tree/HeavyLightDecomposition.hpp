#pragma once
#include <vector>
#include "../../src/internal/CSR.hpp"

namespace kyopro {

class HeavyLightDecomposition {
    int root, id;
    int n;

    std::vector<std::pair<int, int>> es;
    std::vector<int> sz, dep, in, out, nxt, par;

public:
    HeavyLightDecomposition(int n)
        : n(n),
          es(),
          sz(n),
          dep(n),
          in(n, -1),
          out(n, -1),
          nxt(n, root),
          par(n, root) {
        es.reserve(2 * (n - 1));
    }

    void add_edge(int u, int v) {
        es.emplace_back(u, v);
        es.emplace_back(v, u);
    }

    std::pair<int, int> idx(int i) const { return std::pair(in[i], out[i]); }

    void build(int root) {
        internal::csr g(n, es);
        {
            auto dfs_sz = [&](auto f, int cur) -> void {
                sz[cur] = 1;

                for (auto& dst : g[cur]) {
                    if (dst == par[cur]) {
                        if (g[cur].size() >= 2 && dst == g[cur][0]) {
                            std::swap(g[cur][0], g[cur][1]);
                        } else {
                            continue;
                        }
                    }

                    dep[dst] = dep[cur] + 1;
                    par[dst] = cur;
                    f(f, dst);
                    sz[cur] += sz[dst];

                    if (sz[dst] > sz[g[cur][0]]) {
                        std::swap(dst, g[cur][0]);
                    }
                }
            };
            dfs_sz(dfs_sz, root);
        }
        {
            auto dfs_hld = [&](auto f, int cur) -> void {
                in[cur] = id++;
                for (auto dst : g[cur]) {
                    if (dst == par[cur]) continue;

                    nxt[dst] = (dst == g[cur][0] ? nxt[cur] : dst);
                    f(f, dst);
                }
                out[cur] = id;
            };
            dfs_hld(dfs_hld, root);
        }
    }

private:
    std::vector<std::pair<int, int>> ascend(int u, int v) const {
        std::vector<std::pair<int, int>> res;
        while (nxt[u] != nxt[v]) {
            res.emplace_back(in[u], in[nxt[u]]);
            u = par[nxt[u]];
        }

        if (u != v) res.emplace_back(in[u], in[v] + 1);
        return res;
    }

    std::vector<std::pair<int, int>> descend(int u, int v) const {
        if (u == v) return {};
        if (nxt[u] == nxt[v]) return {{in[u] + 1, in[v]}};
        std::vector res = descend(u, par[nxt[v]]);
        res.emplace_back(in[nxt[v]], in[v]);
        return res;
    }

public:
    int lca(int a, int b) const {
        while (nxt[a] != nxt[b]) {
            if (in[a] < in[b]) std::swap(a, b);
            a = par[nxt[a]];
        }
        return dep[a] < dep[b] ? a : b;
    }

    int dist(int a, int b) const {
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    }

    template <typename F> void path_query(int u, int v, const F& f) {
        int l = lca(u, v);

        for (const auto&& [a, b] : ascend(u, l)) {
            int s = a + 1, t = b;
            if (s < t) {
                f(s, t);
            } else {
                f(t, s);
            }
        }
        f(in[l], in[l] + 1);
        for (const auto&& [a, b] : descend(l, v)) {
            int s = a, t = b + 1;
            if (s < t) {
                f(s, t);
            } else {
                f(t, s);
            }
        }
    }

    template <typename F>
    void path_noncommutative_query(int u, int v, const F& f) {
        int l = lca(u, v);
        for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);
        f(in[l], in[l] + 1);
        for (auto&& [a, b] : descend(l, v)) f(a, b + 1);
    }

    template <typename F> void subtree_query(int u, const F& f) {
        f(in[u], out[u]);
    }
};
};  // namespace kyopro

/**
 * @brief Heavy Light Decomposition
 * @see https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp
 */