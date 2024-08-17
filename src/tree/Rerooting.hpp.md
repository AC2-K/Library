---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
      \u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/tree/Rerooting.md
    document_title: "Rerooting(\u5168\u65B9\u4F4D\u6728DP)"
    links: []
  bundledCode: "#line 2 \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <iterator>\n\
    #include <utility>\n#include <vector>\n\nnamespace kyopro {\nnamespace internal\
    \ {\n\ntemplate <typename T, typename _size_t> class csr {\n    _size_t n;\n \
    \   std::vector<T> d;\n    std::vector<_size_t> ssum;\n\npublic:\n    csr() =\
    \ default;\n    csr(_size_t n, const std::vector<std::pair<_size_t, T>>& v)\n\
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
    \ * @brief CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
    \u7E2E)\n */\n#line 3 \"src/tree/Rerooting.hpp\"\n\nnamespace kyopro {\ntemplate\
    \ <typename V, typename OP, typename PUT_EV, typename LEAF>\nclass Rerooting {\n\
    \    const V identity;\n    const OP op;\n    const PUT_EV put_edge_vertex;\n\
    \    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const V& identity,\n\
    \              const OP& op,\n              const PUT_EV& put_edge_vertex,\n \
    \             const LEAF& leaf)\n        : n(n),\n          identity(identity),\n\
    \          op(op),\n          put_edge_vertex(put_edge_vertex),\n          leaf(leaf)\
    \ {\n        es.reserve(2 * n - 2);\n    }\n    void add_edge(int u, int v, int\
    \ i) {\n        es.emplace_back(u, std::pair(v, i));\n        es.emplace_back(v,\
    \ std::pair(u, i));\n    }\n\n    std::vector<V> run() {\n        assert(es.size()\
    \ == 2 * n - 2);\n\n        internal::csr g(n, es);\n\n        std::vector<V>\
    \ dp1(n);\n        {\n            auto push_up = [&](const auto& push_up, int\
    \ v, int p = -1) -> V {\n                dp1[v] = leaf(v);\n                for\
    \ (auto [nv, e_idx] : g[v]) {\n                    if (nv == p) continue;\n  \
    \                  dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),\n\
    \                                                        e_idx, v));\n       \
    \             // \u9802\u70B9, \u8FBA\u306E\u60C5\u5831\u3092\u6DFB\u52A0\n  \
    \              }\n                return dp1[v];\n            };\n           \
    \ push_up(push_up, 0, -1);\n        }\n\n        std::vector<V> dp(n);\n\n   \
    \     {\n            // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\
    \u3044\u304F\n            auto push_down = [&](const auto& push_down, int v, int\
    \ p = -1,\n                                 V agg) -> void {\n               \
    \ dp[v] = agg;\n                std::vector<std::pair<int, int>> children;\n \
    \               std::vector<V> pref, suff;\n                for (auto [nv, e_idx]\
    \ : g[v]) {\n                    if (nv == p) continue;\n                    children.emplace_back(nv,\
    \ e_idx);\n                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                }\n\n                if (children.empty()) return;\n \
    \               for (int i = 0; i < (int)pref.size() - 1; ++i) {\n           \
    \         pref[i + 1] = op(pref[i + 1], pref[i]);\n                }\n       \
    \         for (int i = (int)suff.size() - 1; i > 0; --i) {\n                 \
    \   suff[i - 1] = op(suff[i - 1], suff[i]);\n                }\n             \
    \   dp[v] = op(dp[v], pref.back());\n\n                for (int i = 0; i < (int)children.size();\
    \ ++i) {\n                    V next_agg = op(leaf(v), agg);\n               \
    \     if (i > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n\
    \                    }\n                    if (i < (int)suff.size() - 1) {\n\
    \                        next_agg = op(next_agg, suff[i + 1]);\n             \
    \       }\n\n                    next_agg = put_edge_vertex(next_agg, children[i].second,\n\
    \                                               children[i].first);\n\n      \
    \              push_down(push_down, children[i].first, v, next_agg);\n       \
    \         }\n                return;\n            };\n            push_down(push_down,\
    \ 0, -1, identity);\n        }\n\n        return dp;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Rerooting(\u5168\u65B9\u4F4D\u6728DP)\n * @docs docs/tree/Rerooting.md\n\
    \ */\n"
  code: "#pragma once\n#include \"../../src/internal/CSR.hpp\"\n\nnamespace kyopro\
    \ {\ntemplate <typename V, typename OP, typename PUT_EV, typename LEAF>\nclass\
    \ Rerooting {\n    const V identity;\n    const OP op;\n    const PUT_EV put_edge_vertex;\n\
    \    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const V& identity,\n\
    \              const OP& op,\n              const PUT_EV& put_edge_vertex,\n \
    \             const LEAF& leaf)\n        : n(n),\n          identity(identity),\n\
    \          op(op),\n          put_edge_vertex(put_edge_vertex),\n          leaf(leaf)\
    \ {\n        es.reserve(2 * n - 2);\n    }\n    void add_edge(int u, int v, int\
    \ i) {\n        es.emplace_back(u, std::pair(v, i));\n        es.emplace_back(v,\
    \ std::pair(u, i));\n    }\n\n    std::vector<V> run() {\n        assert(es.size()\
    \ == 2 * n - 2);\n\n        internal::csr g(n, es);\n\n        std::vector<V>\
    \ dp1(n);\n        {\n            auto push_up = [&](const auto& push_up, int\
    \ v, int p = -1) -> V {\n                dp1[v] = leaf(v);\n                for\
    \ (auto [nv, e_idx] : g[v]) {\n                    if (nv == p) continue;\n  \
    \                  dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),\n\
    \                                                        e_idx, v));\n       \
    \             // \u9802\u70B9, \u8FBA\u306E\u60C5\u5831\u3092\u6DFB\u52A0\n  \
    \              }\n                return dp1[v];\n            };\n           \
    \ push_up(push_up, 0, -1);\n        }\n\n        std::vector<V> dp(n);\n\n   \
    \     {\n            // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\
    \u3044\u304F\n            auto push_down = [&](const auto& push_down, int v, int\
    \ p = -1,\n                                 V agg) -> void {\n               \
    \ dp[v] = agg;\n                std::vector<std::pair<int, int>> children;\n \
    \               std::vector<V> pref, suff;\n                for (auto [nv, e_idx]\
    \ : g[v]) {\n                    if (nv == p) continue;\n                    children.emplace_back(nv,\
    \ e_idx);\n                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                }\n\n                if (children.empty()) return;\n \
    \               for (int i = 0; i < (int)pref.size() - 1; ++i) {\n           \
    \         pref[i + 1] = op(pref[i + 1], pref[i]);\n                }\n       \
    \         for (int i = (int)suff.size() - 1; i > 0; --i) {\n                 \
    \   suff[i - 1] = op(suff[i - 1], suff[i]);\n                }\n             \
    \   dp[v] = op(dp[v], pref.back());\n\n                for (int i = 0; i < (int)children.size();\
    \ ++i) {\n                    V next_agg = op(leaf(v), agg);\n               \
    \     if (i > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n\
    \                    }\n                    if (i < (int)suff.size() - 1) {\n\
    \                        next_agg = op(next_agg, suff[i + 1]);\n             \
    \       }\n\n                    next_agg = put_edge_vertex(next_agg, children[i].second,\n\
    \                                               children[i].first);\n\n      \
    \              push_down(push_down, children[i].first, v, next_agg);\n       \
    \         }\n                return;\n            };\n            push_down(push_down,\
    \ 0, -1, identity);\n        }\n\n        return dp;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Rerooting(\u5168\u65B9\u4F4D\u6728DP)\n * @docs docs/tree/Rerooting.md\n\
    \ */"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-08-17 18:56:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
documentation_of: src/tree/Rerooting.hpp
layout: document
redirect_from:
- /library/src/tree/Rerooting.hpp
- /library/src/tree/Rerooting.hpp.html
title: "Rerooting(\u5168\u65B9\u4F4D\u6728DP)"
---
