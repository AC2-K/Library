---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_D_dual.test.cpp
    title: test/AOJ/DSL/2_D_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_E_dual.test.cpp
    title: test/AOJ/DSL/2_E_dual.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Dual Segment Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\ntemplate <class F, auto composition, auto\
    \ id> class dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\npublic:\n\
    \    dual_segtree() : dual_segtree(0) {}\n    dual_segtree(int _n) : _n(_n) {\n\
    \        sz = 1, lg = 0;\n        while (sz < _n) {\n            ++lg;\n     \
    \       sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\nprivate:\n\
    \    void update(int p, const F& v) { dat[p] = composition(dat[p], v); }\n   \
    \ void push(int p) {\n        if (dat[p] == id()) {\n            return;\n   \
    \     }\n        update(p << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n\
    \        dat[p] = id();\n    }\n\npublic:\n    F operator[](int p) {\n       \
    \ assert(0 <= p && p < _n);\n\n        p += sz;\n        for (int i = lg; i >\
    \ 0; i--) {\n            push(p >> i);\n        }\n        return dat[p];\n  \
    \  }\n\n    void apply(int l, int r, const F& v) {\n        assert(0 <= l && l\
    \ <= r && r <= _n);\n        if (l == r) return;\n        l += sz, r += sz;\n\
    \        for (int i = lg; i > 0; i--) {\n            if (((l >> i) << i) != l)\
    \ {\n                push(l >> i);\n            }\n            if (((r >> i) <<\
    \ i) != r) {\n                push((r - 1) >> i);\n            }\n        }\n\
    \        while (l < r) {\n            if (l & 1) {\n                update(l++,\
    \ v);\n            }\n            if (r & 1) {\n                update(--r, v);\n\
    \            }\n            l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  //\
    \ namespace kyopro\n\n\n/**\n * @brief Dual Segment Tree\n*/\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    template <class F, auto composition, auto id> class dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\npublic:\n    dual_segtree() : dual_segtree(0) {}\n\
    \    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while (sz\
    \ < _n) {\n            ++lg;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\nprivate:\n    void update(int p, const F& v) { dat[p]\
    \ = composition(dat[p], v); }\n    void push(int p) {\n        if (dat[p] == id())\
    \ {\n            return;\n        }\n        update(p << 1 | 0, dat[p]);\n   \
    \     update(p << 1 | 1, dat[p]);\n        dat[p] = id();\n    }\n\npublic:\n\
    \    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\n        p +=\
    \ sz;\n        for (int i = lg; i > 0; i--) {\n            push(p >> i);\n   \
    \     }\n        return dat[p];\n    }\n\n    void apply(int l, int r, const F&\
    \ v) {\n        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n\
    \        l += sz, r += sz;\n        for (int i = lg; i > 0; i--) {\n         \
    \   if (((l >> i) << i) != l) {\n                push(l >> i);\n            }\n\
    \            if (((r >> i) << i) != r) {\n                push((r - 1) >> i);\n\
    \            }\n        }\n        while (l < r) {\n            if (l & 1) {\n\
    \                update(l++, v);\n            }\n            if (r & 1) {\n  \
    \              update(--r, v);\n            }\n            l >>= 1, r >>= 1;\n\
    \        }\n    }\n};\n\n};  // namespace kyopro\n\n\n/**\n * @brief Dual Segment\
    \ Tree\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-11-04 20:49:15+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL/2_D_dual.test.cpp
  - test/AOJ/DSL/2_E_dual.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
documentation_of: src/data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dual_segtree.hpp
- /library/src/data-structure/dual_segtree.hpp.html
title: Dual Segment Tree
---
