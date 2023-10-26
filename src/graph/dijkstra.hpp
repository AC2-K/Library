#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>

namespace kyopro {

template<typename Cost>
class dijkstra {
    std::vector<Cost> _dist;
    std::vector<int> _trace;
    const int n;
    int s;

    struct edge {
        const int to;
        const Cost cost;
        constexpr edge(int to, Cost cost) noexcept : to(to), cost(cost) {}
    };

    std::vector<std::vector<edge>> g;

public:
    static constexpr Cost COST_INF = std::numeric_limits<Cost>::max() / 2;

    dijkstra(int n) : n(n), g(n), _trace(n, -1), _dist(n, COST_INF) {}
    dijkstra(const std::vector<std::vector<edge>>& g)
        : n(g.size()), g(g), _trace(g.size(), -1), _dist(g.size(), COST_INF){}

    void add_edge(int from, int to, Cost cost) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(cost >= 0);
        g[from].emplace_back(to, cost);
    }

    void build(int _s) {
        s = _s;
        std::priority_queue<std::pair<Cost, int>,
                            std::vector<std::pair<Cost, int>>,
                            std::greater<std::pair<Cost, int>>>
            q;
        q.emplace(0, s);
        _dist[s] = 0;
        _trace[s] = s;
        while (!q.empty()) {
            auto [d, v] = q.top();
            q.pop();
            if (_dist[v] != d) {
                continue;
            }
            for (auto [nv, c] : g[v]) {
                if (_dist[v] + c < _dist[nv]) {
                    _dist[nv] = _dist[v] + c;
                    _trace[nv] = v;
                    q.emplace(_dist[nv], nv);
                }
            }
        }
    }

    const Cost dist(int u) const { return _dist[u]; }
    std::vector<Cost> dists() const { return _dist; }
    std::vector<int> traces() const { return _trace; }

    std::vector<int> shortest_path(int to) const {
        assert(0 <= to && to < n);
        assert(_dist[to] < COST_INF);

        int cur = to;
        std::vector<int> path;
        while (cur != _trace[cur]) {
            path.emplace_back(cur);
            cur = _trace[cur];
        }
        path.emplace_back(s);
        std::reverse(path.begin(), path.end());

        return path;
    }
};
};  // namespace kyopro

/**
 * @brief ダイクストラ法
 * @bug 最短距離が10^18を超えたりする場合はバグる
 * @todo 上のやつを直す
 */