#pragma once
#include <algorithm>
#include <vector>

namespace kyopro {

/**
 * @brief Topologial Sort
 * @returns (ソート済みの頂点列, 元のグラフがDAGだったか?)
 */
std::pair<std::vector<int>, bool> topological_sort(
    const std::vector<std::vector<int>>& g) {
    int n = g.size();
    std::vector<bool> vis(n, false), finished(n, false);
    std::vector<int> res;

    auto dfs = [&](const auto& f, int v) -> bool {
        vis[v] = true;
        for (auto nex : g[v]) {
            if (vis[nex]) {
                if (!finished[nex]) {
                    return false;
                }
                continue;
            }
            if (!f(f, nex)) {
                return false;
            }
        }

        finished[v] = true;
        res.push_back(v);

        return true;
    };
    for (int v = 0; v < n; v++) {
        if (vis[v]) continue;
        if (!dfs(dfs, v)) {
            return std::pair(std::vector<int>(), false);
        }
    }
    std::reverse(res.begin(), res.end());
    return std::pair(res, true);
}

};  // namespace kyopro

/**
 * @docs docs/graph/TopologialSort.md
 */