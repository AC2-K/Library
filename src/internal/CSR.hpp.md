---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/tree/EulerTour.hpp
    title: Euler Tour
  - icon: ':heavy_check_mark:'
    path: src/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: src/tree/doubling.hpp
    title: "\u6728\u4E0A\u306E\u30C0\u30D6\u30EA\u30F3\u30B0"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5_C.test.cpp
    title: test/AOJ/GRL/5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
    title: test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "CSR\u5F62\u5F0F"
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
    \ * @brief CSR\u5F62\u5F0F\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <iterator>\n#include <utility>\n\
    #include <vector>\n\nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename\
    \ T, typename _size_t> class csr {\n    _size_t n;\n    std::vector<T> d;\n  \
    \  std::vector<_size_t> ssum;\n\npublic:\n    csr() = default;\n    csr(_size_t\
    \ n, const std::vector<std::pair<_size_t, T>>& v)\n        : n(n), ssum(n + 1),\
    \ d(v.size()) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n         \
    \   ++ssum[v[i].first + 1];\n        }\n        for (int i = 0; i < n; ++i) {\n\
    \            ssum[i + 1] += ssum[i];\n        }\n\n        std::vector cnt = ssum;\n\
    \        for (auto e : v) d[cnt[e.first]++] = e.second;\n    }\n\n    struct vector_range\
    \ {\n        using iterator = typename std::vector<T>::iterator;\n        iterator\
    \ l, r;\n\n        iterator begin() const { return l; }\n        iterator end()\
    \ const { return r; }\n        _size_t size() { return std::distance(l, r); }\n\
    \        T& operator[](_size_t i) const { return l[i]; }\n    };\n    struct const_vector_range\
    \ {\n        using const_iterator = typename std::vector<T>::const_iterator;\n\
    \        const_iterator l, r;\n\n        const_iterator begin() const { return\
    \ l; }\n        const_iterator end() const { return r; }\n        _size_t size()\
    \ { return (_size_t)std::distance(l, r); }\n        const T& operator[](_size_t\
    \ i) const { return l[i]; }\n    };\n\n    vector_range operator[](_size_t i)\
    \ {\n        return vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};\n\
    \    }\n    const_vector_range operator[](_size_t i) const {\n        return const_vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n\n    _size_t size() const { return\
    \ (_size_t)n; }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n\
    \ * @brief CSR\u5F62\u5F0F\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/CSR.hpp
  requiredBy:
  - src/tree/EulerTour.hpp
  - src/tree/HeavyLightDecomposition.hpp
  - src/tree/doubling.hpp
  timestamp: '2024-05-03 15:25:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL/5_C.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
  - test/yosupo_judge/tree/Jump_on_Tree.test.cpp
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_doubling.test.cpp
documentation_of: src/internal/CSR.hpp
layout: document
redirect_from:
- /library/src/internal/CSR.hpp
- /library/src/internal/CSR.hpp.html
title: "CSR\u5F62\u5F0F"
---
