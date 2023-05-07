#pragma once
#include <utility>
#include "../data-structure/sparse_table.hpp"
namespace kyopro {
/// @brief EulerTour
class EulerTour {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> tour;
    std::vector<int> in, out, depth;

    struct get_min_pair {
        using value_t = std::pair<int, int>;
        static value_t op(value_t x, value_t y) {
            return std::min(x, y);
        }
    };
    
    sparse_table<get_min_pair::value_t, get_min_pair::op> rmq;

public:
    explicit EulerTour(int n)
        : n(n), g(n), in(n, -1), out(n, -1), depth(n, -1), rmq(2 * n - 1) {
        tour.reserve(2 * n - 1);
    }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::vector<int>> get_graph() { return g; }
    std::vector<int> get_tour() { return tour; }
    int get_depth(int v) const { return depth[v]; }

public:
    void build(int r = 0) {
        auto dfs = [&](const auto& self, int v, int p) -> void {
            in[v] = tour.size();
            tour.emplace_back(v);
            for (auto nv : g[v]) {
                if (nv != p) {
                    depth[nv] = depth[v] + 1;
                    self(self, nv, v);
                    tour.emplace_back(v);
                }
            }
            out[v] = tour.size() - 1;
        };
        dfs(dfs, r, -1);
        for (int i = 0; i < (int)tour.size(); i++) {
            rmq.set(i, {depth[tour[i]], tour[i]});
        }
        rmq.build();
    }

    std::pair<int, int> idx(int v) { return {in[v], out[v]}; }
    int lca(int v, int u) {
        if (in[v] > in[u] + 1) {
            std::swap(u, v);
        }
        return rmq.prod(in[v], in[u] + 1).second;
    }

    int dist(int v, int u) {
        int p = lca(v, u);
        return depth[v] + depth[u] - 2 * depth[p];
    }

    bool is_in_subtree(int par, int v) {
        return (in[par] <= in[v] && out[v] <= out[par]);
    }
};
};  // namespace kyopro