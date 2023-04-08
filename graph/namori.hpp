#pragma once
#include <queue>
#include <vector>
namespace kyopro {
class namori {
    int n;
    std::vector<std::vector<int>> g;
    std::vector<int> root_idx;
    std::vector<int> deg;
    std::vector<bool> is_cycle;
    std::vector<int> cycle;

  public:
    namori(int n) : n(n), g(n), deg(n), is_cycle(n, true), root_idx(n, -1) {
        cycle.reserve(n);
    }

    inline void add_edge(int s, int t) {
        g[s].emplace_back(t), g[t].emplace_back(s);
        deg[s]++, deg[t]++;
    }

    void build() {
        // deg=1の頂点を突っ込んでBFS
        {
            std::queue<int> q;
            for (int v = 0; v < n; v++) {
                if (deg[v] == 1) {
                    q.emplace(v);
                }
            }
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                is_cycle[v] = false;

                for (const auto& nv : g[v]) {
                    if (deg[nv] < 2) continue;
                    deg[nv]--;
                    if (deg[nv] == 1) q.emplace(nv);
                }
            }
        }

        // DFSしてIDを振り分ける
        {
            for (int i = 0; i < n; i++) {
                if (!is_cycle[i]) continue;

                root_idx[i] = i;

                std::vector<std::pair<int, int>> st;
                st.reserve(n);
                for (const auto& ch : g[i]) {
                    if (is_cycle[ch]) continue;
                    st.emplace_back(ch, i);
                }

                while (!st.empty()) {
                    auto [v, p] = st.back();
                    st.pop_back();

                    root_idx[v] = root_idx[p];

                    for (const auto& to : g[v]) {
                        if (to != p) {
                            st.emplace_back(to, v);
                        }
                    }
                }
            }
        }
    }

    inline int root(int v) const { return root_idx[v]; }
    inline bool is_in_cycle(int v) const { return is_cycle[v]; }
    inline std::vector<int> get_cycle() const { return cycle; }
};
};  // namespace kyopro