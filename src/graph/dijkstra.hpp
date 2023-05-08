#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>
namespace kyopro {

/**
 * @brief ダイクストラ法
*/
class dijkstra {
    std::vector<long long> dist;
    std::vector<int> trace;
    const int n;
    int s;
    struct edge {
        const int to;
        const long long cost;
        constexpr edge(int to, long long cost) : to(to), cost(cost) {}
    };

public:
    using graph = std::vector<std::vector<edge>>;

private:
    graph g;

public:
    dijkstra(int n) : n(n), g(n) {}
    dijkstra(const graph& g) : n(g.size()), g(g) {}
    void add_edge(int from, int to, long long cost) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(cost >= 0);
        g[from].emplace_back(to, cost);
    }
    void build(int _s) {
        assert(0 <= _s && _s < n);
        std::swap(s, _s);

        trace.assign(n, -1), dist.assign(n, (long long)1e18);
        std::priority_queue<std::pair<long long, int>,
                            std::vector<std::pair<long long, int>>,
                            std::greater<std::pair<long long, int>>>
            que;
        que.emplace(0, s);
        dist[s] = 0;
        trace[s] = s;
        while (!que.empty()) {
            auto [d, v] = que.top();
            que.pop();
            if (dist[v] != d) {
                continue;
            }

            for (auto [nv, c] : g[v]) {
                if (dist[v] + c < dist[nv]) {
                    dist[nv] = dist[v] + c;
                    trace[nv] = v;
                    que.emplace(dist[nv], nv);
                }
            }
        }
    }
    
    const std::vector<long long>& get_dist() const { return dist; }
    
    std::pair<long long, std::vector<int>> shortest_path(int to) {
        assert(0 <= to && to < n);
        if (dist[to] >= (long long)1e18) return {};
        int cur = to;
        std::vector<int> path;
        while (cur != trace[cur]) {
            path.emplace_back(cur);
            cur = trace[cur];
        }
        path.emplace_back(s);
        std::reverse(path.begin(), path.end());
        return {dist[to], path};
    }
};
};  // namespace kyopro

/**
 * @docs docs/graph/dijkstra.md
*/