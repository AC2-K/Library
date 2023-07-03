#include "../../../atcoder/maxflow"

#include <cassert>
#include <vector>

namespace kyopro {

/**
 * @brief 二部マッチング
 */
template <typename Cap> class BipartiteGraph {
    const int L, R;
    const int s, t;  // 超頂点を作る

    atcoder::mf_graph<Cap> g;

    // すでに流したか?
    bool flowed_flag;

public:
    explicit BipartiteGraph(int LV, int RV)
        : g(LV + RV + 2),
          L(LV),
          R(RV),
          s(LV + RV + 1),
          t(LV + RV),
          flowed_flag(false) {
        for (int i = 0; i < LV; ++i) g.add_edge(s, i, 1);
        for (int i = LV; i < LV + RV; ++i) g.add_edge(i, t, 1);
    }
    int add_edge(int from, int to, Cap cap = 1) {
        assert(0 <= from && from < L);
        assert(0 <= to && to < R);
        return g.add_edge(from, to + L, cap);
    }

public:
    // 流量
    Cap flow() {
        flowed_flag = true;
        return g.flow(s, t);
    }

    // 復元
    std::vector<std::pair<int, int>> Matching() {
        if (!flowed_flag) flow();

        auto E = g.edges();

        std::vector<std::pair<int, int>> res;
        for (const auto& e : E) {
            if (e.flow > 0 && e.from != s && e.to != t) {
                res.emplace_back(e.from, e.to - L);
            }
        }
        return res;
    }
};
};  // namespace kyopro

/**
 * @ref
 * https://qiita.com/drken/items/e805e3f514acceb87602
 * https://nyaannyaan.github.io/library/flow/flow-on-bipartite-graph.hpp
 */