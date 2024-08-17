#pragma once
#include "../../src/internal/CSR.hpp"

namespace kyopro {
template <typename V, typename OP, typename PUT_EV, typename LEAF>
class Rerooting {
    const V identity;
    const OP op;
    const PUT_EV put_edge_vertex;
    const LEAF leaf;

    const int n;

    std::vector<std::pair<int, std::pair<int, int>>> es;

public:
    Rerooting(int n,
              const V& identity,
              const OP& op,
              const PUT_EV& put_edge_vertex,
              const LEAF& leaf)
        : n(n),
          identity(identity),
          op(op),
          put_edge_vertex(put_edge_vertex),
          leaf(leaf) {
        es.reserve(2 * n - 2);
    }
    void add_edge(int u, int v, int i) {
        es.emplace_back(u, std::pair(v, i));
        es.emplace_back(v, std::pair(u, i));
    }

    std::vector<V> run() {
        assert(es.size() == 2 * n - 2);

        internal::csr g(n, es);

        std::vector<V> dp1(n);
        {
            auto push_up = [&](const auto& push_up, int v, int p = -1) -> V {
                dp1[v] = leaf(v);
                for (auto [nv, e_idx] : g[v]) {
                    if (nv == p) continue;
                    dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),
                                                        e_idx, v));
                    // 頂点, 辺の情報を添加
                }
                return dp1[v];
            };
            push_up(push_up, 0, -1);
        }

        std::vector<V> dp(n);

        {
            // 上から下へ伝搬していく
            
            auto push_down = [&](const auto& push_down, int v, int p,
                                 V agg) -> void {
                dp[v] = agg;
                std::vector<std::pair<int, int>> children;
                std::vector<V> pref, suff;
                for (auto [nv, e_idx] : g[v]) {
                    if (nv == p) continue;
                    children.emplace_back(nv, e_idx);
                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx, v));
                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx, v));
                }

                if (children.empty()) return;
                for (int i = 0; i < (int)pref.size() - 1; ++i) {
                    pref[i + 1] = op(pref[i + 1], pref[i]);
                }
                for (int i = (int)suff.size() - 1; i > 0; --i) {
                    suff[i - 1] = op(suff[i - 1], suff[i]);
                }
                dp[v] = op(dp[v], pref.back());

                for (int i = 0; i < (int)children.size(); ++i) {
                    V next_agg = op(leaf(v), agg);
                    if (i > 0) {
                        next_agg = op(next_agg, pref[i - 1]);
                    }
                    if (i < (int)suff.size() - 1) {
                        next_agg = op(next_agg, suff[i + 1]);
                    }

                    next_agg = put_edge_vertex(next_agg, children[i].second,
                                               children[i].first);

                    push_down(push_down, children[i].first, v, next_agg);
                }
                return;
            };
            push_down(push_down, 0, -1, identity);
        }

        return dp;
    }
};
};  // namespace kyopro

/**
 * @brief Solving DP on tree for all roots(全方位木DP)
 * @docs docs/tree/Rerooting.md
 */