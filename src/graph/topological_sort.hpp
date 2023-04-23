#pragma once
#include <algorithm>
#include <vector>

namespace kyopro {
/// @brief トポロジカルソート
/// @param g ソートしたいグラフ(隣接リスト形式)
/// @param res 結果を格納するvector
/// @param has_cycle サイクルを含んでいたら、trueにして終了する
void topological_sort(const std::vector<std::vector<int>>& g,
                      std::vector<int>& res,
                      bool& has_cycle) {
    has_cycle = false;
    int n = g.size();
    std::vector<bool> vis(n, false), finished(n, false);

    auto dfs = [&](auto f, int v) -> bool {
        vis[v] = true;
        for (const auto& nex : g[v]) {
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
            has_cycle = true;
            return;
        }
    }
    std::reverse(res.begin(), res.end());
}

};  // namespace kyopro