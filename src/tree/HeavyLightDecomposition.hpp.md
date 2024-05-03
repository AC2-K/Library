---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
    title: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Heavy Light Decomposition
    links:
    - https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp
  bundledCode: "#line 2 \"src/tree/HeavyLightDecomposition.hpp\"\n#include <vector>\n\
    #line 2 \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <iterator>\n\
    #include <utility>\n#line 7 \"src/internal/CSR.hpp\"\n\nnamespace kyopro {\nnamespace\
    \ internal {\n\ntemplate <typename T, typename _size_t> class csr {\n    _size_t\
    \ n;\n    std::vector<T> d;\n    std::vector<_size_t> ssum;\n\npublic:\n    csr()\
    \ = default;\n    csr(_size_t n, const std::vector<std::pair<_size_t, T>>& v)\n\
    \        : n(n), ssum(n + 1), d(v.size()) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            ++ssum[v[i].first + 1];\n        }\n        for (int i =\
    \ 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i];\n        }\n\n       \
    \ std::vector cnt = ssum;\n        for (auto e : v) d[cnt[e.first]++] = e.second;\n\
    \    }\n\n    struct vector_range {\n        using iterator = typename std::vector<T>::iterator;\n\
    \        iterator l, r;\n\n        iterator begin() const { return l; }\n    \
    \    iterator end() const { return r; }\n        _size_t size() { return std::distance(l,\
    \ r); }\n        T& operator[](_size_t i) const { return l[i]; }\n    };\n   \
    \ struct const_vector_range {\n        using const_iterator = typename std::vector<T>::const_iterator;\n\
    \        const_iterator l, r;\n\n        const_iterator begin() const { return\
    \ l; }\n        const_iterator end() const { return r; }\n        _size_t size()\
    \ { return (_size_t)std::distance(l, r); }\n        const T& operator[](_size_t\
    \ i) const { return l[i]; }\n    };\n\n    vector_range operator[](_size_t i)\
    \ {\n        return vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};\n\
    \    }\n    const_vector_range operator[](_size_t i) const {\n        return const_vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n\n    _size_t size() const { return\
    \ (_size_t)n; }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n\
    \ * @brief CSR\u5F62\u5F0F\n */\n#line 4 \"src/tree/HeavyLightDecomposition.hpp\"\
    \n\nnamespace kyopro {\n\nclass HeavyLightDecomposition {\n    int root, id;\n\
    \    int n;\n\n    std::vector<std::pair<int, int>> es;\n    std::vector<int>\
    \ sz, dep, in, out, nxt, par;\n\npublic:\n    HeavyLightDecomposition(int n)\n\
    \        : n(n),\n          es(),\n          sz(n),\n          dep(n),\n     \
    \     in(n, -1),\n          out(n, -1),\n          nxt(n, root),\n          par(n,\
    \ root) {\n        es.reserve(2 * (n - 1));\n    }\n\n    void add_edge(int u,\
    \ int v) {\n        es.emplace_back(u, v);\n        es.emplace_back(v, u);\n \
    \   }\n\n    std::pair<int, int> idx(int i) const { return std::pair(in[i], out[i]);\
    \ }\n\n    void build(int root) {\n        internal::csr g(n, es);\n        {\n\
    \            auto dfs_sz = [&](const auto& f, int cur) -> void {\n           \
    \     sz[cur] = 1;\n\n                for (auto& dst : g[cur]) {\n           \
    \         if (dst == par[cur]) {\n                        if (g[cur].size() >=\
    \ 2 && dst == g[cur][0]) {\n                            std::swap(g[cur][0], g[cur][1]);\n\
    \                        } else {\n                            continue;\n   \
    \                     }\n                    }\n\n                    dep[dst]\
    \ = dep[cur] + 1;\n                    par[dst] = cur;\n                    f(f,\
    \ dst);\n                    sz[cur] += sz[dst];\n\n                    if (sz[dst]\
    \ > sz[g[cur][0]]) {\n                        std::swap(dst, g[cur][0]);\n   \
    \                 }\n                }\n            };\n            dfs_sz(dfs_sz,\
    \ root);\n        }\n        {\n            auto dfs_hld = [&](const auto& f,\
    \ int cur) -> void {\n                in[cur] = id++;\n                for (auto\
    \ dst : g[cur]) {\n                    if (dst == par[cur]) continue;\n\n    \
    \                nxt[dst] = (dst == g[cur][0] ? nxt[cur] : dst);\n           \
    \         f(f, dst);\n                }\n                out[cur] = id;\n    \
    \        };\n            dfs_hld(dfs_hld, root);\n        }\n    }\n\nprivate:\n\
    \    std::vector<std::pair<int, int>> ascend(int u, int v) const {\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n\n        if (u != v)\
    \ res.emplace_back(in[u], in[v] + 1);\n        return res;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (nxt[u] == nxt[v]) return {{in[u] + 1, in[v]}};\n        std::vector res\
    \ = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]], in[v]);\n \
    \       return res;\n    }\n\npublic:\n    int lca(int a, int b) const {\n   \
    \     while (nxt[a] != nxt[b]) {\n            if (in[a] < in[b]) std::swap(a,\
    \ b);\n            a = par[nxt[a]];\n        }\n        return dep[a] < dep[b]\
    \ ? a : b;\n    }\n\n    int dist(int a, int b) const {\n        return dep[a]\
    \ + dep[b] - 2 * dep[lca(a, b)];\n    }\n\n    template <typename F> void path_query(int\
    \ u, int v, const F& f) {\n        int l = lca(u, v);\n\n        for (const auto&&\
    \ [a, b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n            if\
    \ (s < t) {\n                f(s, t);\n            } else {\n                f(t,\
    \ s);\n            }\n        }\n        f(in[l], in[l] + 1);\n        for (const\
    \ auto&& [a, b] : descend(l, v)) {\n            int s = a, t = b + 1;\n      \
    \      if (s < t) {\n                f(s, t);\n            } else {\n        \
    \        f(t, s);\n            }\n        }\n    }\n\n    template <typename F>\n\
    \    void path_noncommutative_query(int u, int v, const F& f) {\n        int l\
    \ = lca(u, v);\n        for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    f(in[l], in[l] + 1);\n        for (auto&& [a, b] : descend(l, v)) f(a, b\
    \ + 1);\n    }\n\n    template <typename F> void subtree_query(int u, const F&\
    \ f) {\n        f(in[u], out[u]);\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Heavy Light Decomposition\n * @see https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp\n\
    \ */\n"
  code: "#pragma once\n#include <vector>\n#include \"../../src/internal/CSR.hpp\"\n\
    \nnamespace kyopro {\n\nclass HeavyLightDecomposition {\n    int root, id;\n \
    \   int n;\n\n    std::vector<std::pair<int, int>> es;\n    std::vector<int> sz,\
    \ dep, in, out, nxt, par;\n\npublic:\n    HeavyLightDecomposition(int n)\n   \
    \     : n(n),\n          es(),\n          sz(n),\n          dep(n),\n        \
    \  in(n, -1),\n          out(n, -1),\n          nxt(n, root),\n          par(n,\
    \ root) {\n        es.reserve(2 * (n - 1));\n    }\n\n    void add_edge(int u,\
    \ int v) {\n        es.emplace_back(u, v);\n        es.emplace_back(v, u);\n \
    \   }\n\n    std::pair<int, int> idx(int i) const { return std::pair(in[i], out[i]);\
    \ }\n\n    void build(int root) {\n        internal::csr g(n, es);\n        {\n\
    \            auto dfs_sz = [&](const auto& f, int cur) -> void {\n           \
    \     sz[cur] = 1;\n\n                for (auto& dst : g[cur]) {\n           \
    \         if (dst == par[cur]) {\n                        if (g[cur].size() >=\
    \ 2 && dst == g[cur][0]) {\n                            std::swap(g[cur][0], g[cur][1]);\n\
    \                        } else {\n                            continue;\n   \
    \                     }\n                    }\n\n                    dep[dst]\
    \ = dep[cur] + 1;\n                    par[dst] = cur;\n                    f(f,\
    \ dst);\n                    sz[cur] += sz[dst];\n\n                    if (sz[dst]\
    \ > sz[g[cur][0]]) {\n                        std::swap(dst, g[cur][0]);\n   \
    \                 }\n                }\n            };\n            dfs_sz(dfs_sz,\
    \ root);\n        }\n        {\n            auto dfs_hld = [&](const auto& f,\
    \ int cur) -> void {\n                in[cur] = id++;\n                for (auto\
    \ dst : g[cur]) {\n                    if (dst == par[cur]) continue;\n\n    \
    \                nxt[dst] = (dst == g[cur][0] ? nxt[cur] : dst);\n           \
    \         f(f, dst);\n                }\n                out[cur] = id;\n    \
    \        };\n            dfs_hld(dfs_hld, root);\n        }\n    }\n\nprivate:\n\
    \    std::vector<std::pair<int, int>> ascend(int u, int v) const {\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (nxt[u] != nxt[v]) {\n            res.emplace_back(in[u],\
    \ in[nxt[u]]);\n            u = par[nxt[u]];\n        }\n\n        if (u != v)\
    \ res.emplace_back(in[u], in[v] + 1);\n        return res;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {\n        if (u == v) return {};\n      \
    \  if (nxt[u] == nxt[v]) return {{in[u] + 1, in[v]}};\n        std::vector res\
    \ = descend(u, par[nxt[v]]);\n        res.emplace_back(in[nxt[v]], in[v]);\n \
    \       return res;\n    }\n\npublic:\n    int lca(int a, int b) const {\n   \
    \     while (nxt[a] != nxt[b]) {\n            if (in[a] < in[b]) std::swap(a,\
    \ b);\n            a = par[nxt[a]];\n        }\n        return dep[a] < dep[b]\
    \ ? a : b;\n    }\n\n    int dist(int a, int b) const {\n        return dep[a]\
    \ + dep[b] - 2 * dep[lca(a, b)];\n    }\n\n    template <typename F> void path_query(int\
    \ u, int v, const F& f) {\n        int l = lca(u, v);\n\n        for (const auto&&\
    \ [a, b] : ascend(u, l)) {\n            int s = a + 1, t = b;\n            if\
    \ (s < t) {\n                f(s, t);\n            } else {\n                f(t,\
    \ s);\n            }\n        }\n        f(in[l], in[l] + 1);\n        for (const\
    \ auto&& [a, b] : descend(l, v)) {\n            int s = a, t = b + 1;\n      \
    \      if (s < t) {\n                f(s, t);\n            } else {\n        \
    \        f(t, s);\n            }\n        }\n    }\n\n    template <typename F>\n\
    \    void path_noncommutative_query(int u, int v, const F& f) {\n        int l\
    \ = lca(u, v);\n        for (auto&& [a, b] : ascend(u, l)) f(a + 1, b);\n    \
    \    f(in[l], in[l] + 1);\n        for (auto&& [a, b] : descend(l, v)) f(a, b\
    \ + 1);\n    }\n\n    template <typename F> void subtree_query(int u, const F&\
    \ f) {\n        f(in[u], out[u]);\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Heavy Light Decomposition\n * @see https://nyaannyaan.github.io/library/tree/heavy-light-decomposition.hpp\n\
    \ */"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-05-03 17:05:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
documentation_of: src/tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/src/tree/HeavyLightDecomposition.hpp
- /library/src/tree/HeavyLightDecomposition.hpp.html
title: Heavy Light Decomposition
---
