---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/tree.md
    document_title: "\u6728(\u8A70\u3081\u5408\u308F\u305B\u30D1\u30C3\u30AF)"
    links: []
  bundledCode: "#line 2 \"src/tree/tree.hpp\"\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief \u6728(\u8A70\u3081\u5408\u308F\u305B\u30D1\u30C3\u30AF)\n*/\n\
    namespace kyopro {\nclass Tree {\n    struct edge {\n        const int to;\n \
    \       const int cost;\n        edge() = default;\n        constexpr explicit\
    \ edge(int to, int cost) : to(to), cost(cost) {}\n    };\n    const int n;\n \
    \   static constexpr int lg = 21;\n    std::vector<std::vector<edge>> g;\n   \
    \ std::vector<int> parent[lg];\n    std::vector<long long> _dist;\n    std::vector<int>\
    \ _depth;\n\npublic:\n    explicit Tree(int n) : n(n), g(n), _dist(n, -1), _depth(n)\
    \ {\n        std::fill(parent, parent + lg, std::vector<int>(n));\n    }\n   \
    \ void add_edge(int a, int b, int c = 1) {\n        g[a].emplace_back(b, 1);\n\
    \        g[b].emplace_back(a, 1);\n    }\n    void build(int root = 0) {\n   \
    \     std::vector<int> st;\n        st.reserve(n);\n\n        st.emplace_back(root);\n\
    \        _dist[root] = 0, _depth[root] = 0, parent[0][root] = root;\n        while\
    \ (!st.empty()) {\n            int v = st.back();\n            st.pop_back();\n\
    \n            for (auto [nv, c] : g[v]) {\n                if (_dist[nv] != -1)\
    \ continue;\n                _dist[nv] = _dist[v] + c;\n                _depth[nv]\
    \ = _depth[v] + 1;\n                parent[0][nv] = v;\n\n                st.emplace_back(nv);\n\
    \            }\n        }\n\n        for (int i = 0; i < lg; ++i) {\n        \
    \    for (int v = 0; v < n; ++v) {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \            }\n        }\n    }\n\n    int level_ancestor(const int v, const\
    \ int k) const {\n        assert(_depth[v] >= k);\n        int cur = v;\n\n  \
    \      for (int i = 0; i < lg; ++i) {\n            if (k >> i & 1) {\n       \
    \         cur = parent[i][cur];\n            }\n        }\n        return cur;\n\
    \    }\n\n    int dist(int v) const { return _dist[v]; }\n    int depth(int v)\
    \ const { return _depth[v]; }\n\n    int lca(int a, int b) const {\n        if\
    \ (_depth[a] > _depth[b]) {\n            std::swap(a, b);\n        }\n       \
    \ if (_depth[a] != _depth[b]) {\n            b = level_ancestor(b, _depth[b] -\
    \ _depth[a]);\n        }\n        if (a == b) return a;\n        for (int k =\
    \ lg - 1; k >= 0; --k) {\n            if (parent[k][a] != parent[k][b]) {\n  \
    \              a = parent[k][a];\n                b = parent[k][b];\n        \
    \    }\n        }\n        return parent[0][a];\n    }\n};\n};  // namespace kyopro\n\
    \n\n\n/**\n * @docs docs/tree/tree.md\n*/\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u6728\
    (\u8A70\u3081\u5408\u308F\u305B\u30D1\u30C3\u30AF)\n*/\nnamespace kyopro {\nclass\
    \ Tree {\n    struct edge {\n        const int to;\n        const int cost;\n\
    \        edge() = default;\n        constexpr explicit edge(int to, int cost)\
    \ : to(to), cost(cost) {}\n    };\n    const int n;\n    static constexpr int\
    \ lg = 21;\n    std::vector<std::vector<edge>> g;\n    std::vector<int> parent[lg];\n\
    \    std::vector<long long> _dist;\n    std::vector<int> _depth;\n\npublic:\n\
    \    explicit Tree(int n) : n(n), g(n), _dist(n, -1), _depth(n) {\n        std::fill(parent,\
    \ parent + lg, std::vector<int>(n));\n    }\n    void add_edge(int a, int b, int\
    \ c = 1) {\n        g[a].emplace_back(b, 1);\n        g[b].emplace_back(a, 1);\n\
    \    }\n    void build(int root = 0) {\n        std::vector<int> st;\n       \
    \ st.reserve(n);\n\n        st.emplace_back(root);\n        _dist[root] = 0, _depth[root]\
    \ = 0, parent[0][root] = root;\n        while (!st.empty()) {\n            int\
    \ v = st.back();\n            st.pop_back();\n\n            for (auto [nv, c]\
    \ : g[v]) {\n                if (_dist[nv] != -1) continue;\n                _dist[nv]\
    \ = _dist[v] + c;\n                _depth[nv] = _depth[v] + 1;\n             \
    \   parent[0][nv] = v;\n\n                st.emplace_back(nv);\n            }\n\
    \        }\n\n        for (int i = 0; i < lg; ++i) {\n            for (int v =\
    \ 0; v < n; ++v) {\n                parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \            }\n        }\n    }\n\n    int level_ancestor(const int v, const\
    \ int k) const {\n        assert(_depth[v] >= k);\n        int cur = v;\n\n  \
    \      for (int i = 0; i < lg; ++i) {\n            if (k >> i & 1) {\n       \
    \         cur = parent[i][cur];\n            }\n        }\n        return cur;\n\
    \    }\n\n    int dist(int v) const { return _dist[v]; }\n    int depth(int v)\
    \ const { return _depth[v]; }\n\n    int lca(int a, int b) const {\n        if\
    \ (_depth[a] > _depth[b]) {\n            std::swap(a, b);\n        }\n       \
    \ if (_depth[a] != _depth[b]) {\n            b = level_ancestor(b, _depth[b] -\
    \ _depth[a]);\n        }\n        if (a == b) return a;\n        for (int k =\
    \ lg - 1; k >= 0; --k) {\n            if (parent[k][a] != parent[k][b]) {\n  \
    \              a = parent[k][a];\n                b = parent[k][b];\n        \
    \    }\n        }\n        return parent[0][a];\n    }\n};\n};  // namespace kyopro\n\
    \n\n\n/**\n * @docs docs/tree/tree.md\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/tree.hpp
  requiredBy: []
  timestamp: '2023-05-11 22:41:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
documentation_of: src/tree/tree.hpp
layout: document
redirect_from:
- /library/src/tree/tree.hpp
- /library/src/tree/tree.hpp.html
title: "\u6728(\u8A70\u3081\u5408\u308F\u305B\u30D1\u30C3\u30AF)"
---
