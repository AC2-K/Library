#pragma once
#include "../../src/internal/CSR.hpp"

namespace kyopro {
template <typename M,
          typename OP,
          typename PUT_V,
          typename PUT_E,
          typename LEAF>
class Rerooting {
    const M identity;
    const OP op;
    const PUT_V put_vertex;
    const PUT_E put_edge;
    const LEAF leaf;

    const int n;

    std::vector<std::pair<int, std::pair<int, int>>> es;

public:
    Rerooting(int n,
              const M& identity,
              const OP& op,
              const PUT_V& put_vertex,
              const PUT_E& put_edge,
              const LEAF& leaf)
        : n(n),
          identity(identity),
          op(op),
          put_vertex(put_vertex),
          put_edge(put_edge),
          leaf(leaf) {
        es.reserve(2 * n - 2);
    }

    void add_edge(int u, int v, int i) {
        es.emplace_back(u, std::pair(v, i));
        es.emplace_back(v, std::pair(u, i));
    }

    std::vector<M> run() {
        assert(es.size() == 2 * n - 2);

        internal::csr g(n, es);

        std::vector<M> dp1(n);
        {
            auto push_up = [&](const auto& push_up, int v, int p = -1) -> M {
                dp1[v] = identity;

                for (auto [nv, e] : g[v]) {
                    if (nv == p) continue;
                    dp1[v] = op(dp1[v], put_edge(push_up(push_up, nv, v), e));
                }

                dp1[v] = put_vertex(dp1[v], v);

                dp1[v] = op(dp1[v], leaf(v));

                return dp1[v];
            };
            push_up(push_up, 0, -1);
        }

        std::vector<M> dp(n);

        {
            // 上から下へ伝搬していく

            auto push_down = [&](const auto& push_down, int v, int p,
                                 M agg) -> void {
                dp[v] = agg;

                std::vector<std::pair<int, int>> children;
                std::vector<M> pref, suff;

                for (auto [nv, e] : g[v]) {
                    if (nv == p) continue;

                    children.emplace_back(nv, e);
                    pref.emplace_back(put_edge(dp1[nv], e));
                    suff.emplace_back(put_edge(dp1[nv], e));
                }

                if (children.empty()) return;

                for (int i = 0; i < (int)pref.size() - 1; ++i) {
                    pref[i + 1] = op(pref[i + 1], pref[i]);
                }

                for (int i = (int)suff.size() - 1; i > 0; --i) {
                    suff[i - 1] = op(suff[i - 1], suff[i]);
                }

                dp[v] = op(dp[v], put_vertex(pref.back(), v));

                for (int i = 0; i < (int)children.size(); ++i) {
                    M next_agg = op(leaf(v), agg);

                    if (i > 0) {
                        next_agg = op(next_agg, pref[i - 1]);
                    }

                    if (i < (int)suff.size() - 1) {
                        next_agg = op(next_agg, suff[i + 1]);
                    }
                    
                    next_agg = put_vertex(
                        put_edge(put_vertex(next_agg, v), children[i].second),
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