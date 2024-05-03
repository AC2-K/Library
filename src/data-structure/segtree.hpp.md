---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_B.test.cpp
    title: test/AOJ/DSL/2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
    title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
    title: test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/segtree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nnamespace kyopro {\n\n\ntemplate <class S, auto op, auto e> class\
    \ segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree()\
    \ = default;\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const\
    \ std::vector<S>& vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n     \
    \   while (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n\
    \        dat = std::vector<S>(sz << 1, e());\n\n        for (int i = 0; i < n;\
    \ i++) {\n            set(i, vec[i]);\n        }\n        build();\n    }\n\n\
    \    void set(int p, const S& v) {\n        assert(0 <= p && p < sz);\n      \
    \  dat[sz + p] = v;\n    }\n    void build() {\n        for (int i = sz - 1; i\
    \ > 0; i--) {\n            dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);\n  \
    \      }\n    }\n\n    S operator[](int p) const { return dat[sz + p]; }\n\n \
    \   void update(int p, const S& v) {\n        assert(0 <= p && p < sz);\n    \
    \    p += sz;\n        dat[p] = v;\n        while (p >>= 1) {\n            dat[p]\
    \ = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n    }\n\n    S fold(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= sz);\n        if\
    \ (l == 0 && r == n) {\n            return dat[1];\n        }\n        l += sz,\
    \ r += sz;\n        S sml = e(), smr = e();\n        while (l != r) {\n      \
    \      if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr = op(dat[--r],\
    \ smr);\n            l >>= 1, r >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n    void apply(int p, const S& v) {\n        assert(0 <= p && p < sz);\n\
    \        update(p, op(dat[sz + p], v));\n    }\n};\n};  // namespace kyopro\n\n\
    /**\n * @brief Segment Tree\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    \n\ntemplate <class S, auto op, auto e> class segtree {\n    int lg, sz, n;\n\
    \    std::vector<S> dat;\n\npublic:\n    segtree() = default;\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>& vec)\
    \ : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n) {\n\
    \            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    void set(int p, const S& v) {\n   \
    \     assert(0 <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i\
    \ << 1 | 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const\
    \ { return dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>=\
    \ 1) {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n     \
    \   }\n    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n\
    \        }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n     \
    \   while (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n      \
    \      if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n  \
    \      }\n        return op(sml, smr);\n    }\n    void apply(int p, const S&\
    \ v) {\n        assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n\
    \    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Segment Tree\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2_B.test.cpp
  - test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  - test/yosupo_judge/tree/Vertex_Set_Path_Composite.test.cpp
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: Segment Tree
---
