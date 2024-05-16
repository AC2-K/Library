#pragma once
#include <queue>
#include <vector>
namespace kyopro {
class Namori {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> root_idx;
    std::vector<int> deg;
    std::vector<bool> is_cycle;

public:
    Namori(int n) : n(n), g(n), deg(n), is_cycle(n, true), root_idx(n, -1) {}

    void add_edge(int s, int t) {
        g[s].emplace_back(t), g[t].emplace_back(s);
        ++deg[s], ++deg[t];
    }

    void build() {
        {
            std::queue<int> q;
            for (int v = 0; v < n; ++v) {
                if (deg[v] == 1) {
                    q.emplace(v);
                }
            }
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                is_cycle[v] = false;

                for (auto nv : g[v]) {
                    if (deg[nv] < 2) continue;
                    deg[nv]--;
                    if (deg[nv] == 1) q.emplace(nv);
                }
            }
        }

        {
            for (int i = 0; i < n; ++i) {
                if (!is_cycle[i]) continue;

                root_idx[i] = i;

                std::vector<std::pair<int, int>> st;
                st.reserve(n);
                for (auto ch : g[i]) {
                    if (is_cycle[ch]) continue;
                    st.emplace_back(ch, i);
                }

                while (!st.empty()) {
                    auto [v, p] = st.back();
                    st.pop_back();

                    root_idx[v] = root_idx[p];

                    for (auto to : g[v]) {
                        if (to != p) {
                            st.emplace_back(to, v);
                        }
                    }
                }
            }
        }
    }

    int root(int v) const { return root_idx[v]; }
    bool is_in_cycle(int v) const { return is_cycle[v]; }
};
};  // namespace kyopro

/**
 * @brief Namori Graph(なもりグラフ)
 */
