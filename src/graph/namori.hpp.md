---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3"
    links: []
  bundledCode: "#line 2 \"src/graph/namori.hpp\"\n#include <queue>\n#include <vector>\n\
    namespace kyopro {\n\n/// @brief \u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\
    \u89E3\nclass namori {\n    int n;\n    std::vector<std::vector<int>> g;\n   \
    \ std::vector<int> root_idx;\n    std::vector<int> deg;\n    std::vector<bool>\
    \ is_cycle;\n    std::vector<int> cycle;\n\npublic:\n    namori(int n) : n(n),\
    \ g(n), deg(n), is_cycle(n, true), root_idx(n, -1) {\n        cycle.reserve(n);\n\
    \    }\n\n    inline void add_edge(int s, int t) {\n        g[s].emplace_back(t),\
    \ g[t].emplace_back(s);\n        deg[s]++, deg[t]++;\n    }\n\n    void build()\
    \ {\n        // deg=1\u306E\u9802\u70B9\u3092\u7A81\u3063\u8FBC\u3093\u3067BFS\n\
    \        {\n            std::queue<int> q;\n            for (int v = 0; v < n;\
    \ v++) {\n                if (deg[v] == 1) {\n                    q.emplace(v);\n\
    \                }\n            }\n            while (!q.empty()) {\n        \
    \        int v = q.front();\n                q.pop();\n                is_cycle[v]\
    \ = false;\n\n                for (const auto& nv : g[v]) {\n                \
    \    if (deg[nv] < 2) continue;\n                    deg[nv]--;\n            \
    \        if (deg[nv] == 1) q.emplace(nv);\n                }\n            }\n\
    \        }\n\n        // DFS\u3057\u3066ID\u3092\u632F\u308A\u5206\u3051\u308B\
    \n        {\n            for (int i = 0; i < n; i++) {\n                if (!is_cycle[i])\
    \ continue;\n\n                root_idx[i] = i;\n\n                std::vector<std::pair<int,\
    \ int>> st;\n                st.reserve(n);\n                for (const auto&\
    \ ch : g[i]) {\n                    if (is_cycle[ch]) continue;\n            \
    \        st.emplace_back(ch, i);\n                }\n\n                while (!st.empty())\
    \ {\n                    auto [v, p] = st.back();\n                    st.pop_back();\n\
    \n                    root_idx[v] = root_idx[p];\n\n                    for (const\
    \ auto& to : g[v]) {\n                        if (to != p) {\n               \
    \             st.emplace_back(to, v);\n                        }\n           \
    \         }\n                }\n            }\n        }\n    }\n\n    inline\
    \ int root(int v) const { return root_idx[v]; }\n    inline bool is_in_cycle(int\
    \ v) const { return is_cycle[v]; }\n    inline std::vector<int> get_cycle() const\
    \ { return cycle; }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <queue>\n#include <vector>\nnamespace kyopro {\n\n\
    /// @brief \u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3\nclass namori\
    \ {\n    int n;\n    std::vector<std::vector<int>> g;\n    std::vector<int> root_idx;\n\
    \    std::vector<int> deg;\n    std::vector<bool> is_cycle;\n    std::vector<int>\
    \ cycle;\n\npublic:\n    namori(int n) : n(n), g(n), deg(n), is_cycle(n, true),\
    \ root_idx(n, -1) {\n        cycle.reserve(n);\n    }\n\n    inline void add_edge(int\
    \ s, int t) {\n        g[s].emplace_back(t), g[t].emplace_back(s);\n        deg[s]++,\
    \ deg[t]++;\n    }\n\n    void build() {\n        // deg=1\u306E\u9802\u70B9\u3092\
    \u7A81\u3063\u8FBC\u3093\u3067BFS\n        {\n            std::queue<int> q;\n\
    \            for (int v = 0; v < n; v++) {\n                if (deg[v] == 1) {\n\
    \                    q.emplace(v);\n                }\n            }\n       \
    \     while (!q.empty()) {\n                int v = q.front();\n             \
    \   q.pop();\n                is_cycle[v] = false;\n\n                for (const\
    \ auto& nv : g[v]) {\n                    if (deg[nv] < 2) continue;\n       \
    \             deg[nv]--;\n                    if (deg[nv] == 1) q.emplace(nv);\n\
    \                }\n            }\n        }\n\n        // DFS\u3057\u3066ID\u3092\
    \u632F\u308A\u5206\u3051\u308B\n        {\n            for (int i = 0; i < n;\
    \ i++) {\n                if (!is_cycle[i]) continue;\n\n                root_idx[i]\
    \ = i;\n\n                std::vector<std::pair<int, int>> st;\n             \
    \   st.reserve(n);\n                for (const auto& ch : g[i]) {\n          \
    \          if (is_cycle[ch]) continue;\n                    st.emplace_back(ch,\
    \ i);\n                }\n\n                while (!st.empty()) {\n          \
    \          auto [v, p] = st.back();\n                    st.pop_back();\n\n  \
    \                  root_idx[v] = root_idx[p];\n\n                    for (const\
    \ auto& to : g[v]) {\n                        if (to != p) {\n               \
    \             st.emplace_back(to, v);\n                        }\n           \
    \         }\n                }\n            }\n        }\n    }\n\n    inline\
    \ int root(int v) const { return root_idx[v]; }\n    inline bool is_in_cycle(int\
    \ v) const { return is_cycle[v]; }\n    inline std::vector<int> get_cycle() const\
    \ { return cycle; }\n};\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/namori.hpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/namori.hpp
layout: document
redirect_from:
- /library/src/graph/namori.hpp
- /library/src/graph/namori.hpp.html
title: "\u306A\u3082\u308A\u30B0\u30E9\u30D5\u306E\u5206\u89E3"
---
