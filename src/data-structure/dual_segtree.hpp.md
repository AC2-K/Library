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
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dual_segtree.md
    document_title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n\n/// @brief Dual Segmenttree(\u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\ntemplate <class F, F (*comp)(F, F), F (*id)(),\
    \ bool is_commutative = true>\nclass dual_segtree {\n    std::vector<F> dat;\n\
    \    int _n, sz, lg;\n\n  public:\n    dual_segtree() : dual_segtree(0) {}\n \
    \   dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while (sz\
    \ < _n) {\n            lg++;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\n  private:\n    void all_apply(int p, const F& v) { dat[p]\
    \ = comp(dat[p], v); }\n    void push(int p) {\n        if (dat[p] == id()) {\n\
    \            return;\n        }\n        all_apply(p << 1 | 0, dat[p]);\n    \
    \    all_apply(p << 1 | 1, dat[p]);\n        dat[p] = id();\n    }\n\n  public:\n\
    \    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\n        F res\
    \ = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--) {\n      \
    \      push(p >> i);\n        }\n        return dat[p];\n    }\n\n    void apply(int\
    \ l, int r, const F& v) {\n        assert(0 <= l && l <= r && r <= _n);\n    \
    \    if (l == r) return;\n        l += sz, r += sz;\n        if (is_commutative)\
    \ {\n            for (int i = lg; i > 0; i--) {\n                if (((l >> i)\
    \ << i) != l) {\n                    push(l >> i);\n                }\n      \
    \          if (((r >> i) << i) != r) {\n                    push((r - 1) >> i);\n\
    \                }\n            }\n        }\n        while (l < r) {\n      \
    \      if (l & 1) {\n                all_apply(l++, v);\n            }\n     \
    \       if (r & 1) {\n                all_apply(--r, v);\n            }\n    \
    \        l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  // namespace kyopro\n\n\
    /// @docs docs/data-structure/dual_segtree.md\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    \n/// @brief Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\ntemplate <class F, F (*comp)(F, F), F (*id)(), bool is_commutative = true>\n\
    class dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\n  public:\n\
    \    dual_segtree() : dual_segtree(0) {}\n    dual_segtree(int _n) : _n(_n) {\n\
    \        sz = 1, lg = 0;\n        while (sz < _n) {\n            lg++;\n     \
    \       sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\n  private:\n\
    \    void all_apply(int p, const F& v) { dat[p] = comp(dat[p], v); }\n    void\
    \ push(int p) {\n        if (dat[p] == id()) {\n            return;\n        }\n\
    \        all_apply(p << 1 | 0, dat[p]);\n        all_apply(p << 1 | 1, dat[p]);\n\
    \        dat[p] = id();\n    }\n\n  public:\n    F operator[](int p) {\n     \
    \   assert(0 <= p && p < _n);\n\n        F res = id();\n\n        p += sz;\n \
    \       for (int i = lg; i > 0; i--) {\n            push(p >> i);\n        }\n\
    \        return dat[p];\n    }\n\n    void apply(int l, int r, const F& v) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n \
    \       l += sz, r += sz;\n        if (is_commutative) {\n            for (int\
    \ i = lg; i > 0; i--) {\n                if (((l >> i) << i) != l) {\n       \
    \             push(l >> i);\n                }\n                if (((r >> i)\
    \ << i) != r) {\n                    push((r - 1) >> i);\n                }\n\
    \            }\n        }\n        while (l < r) {\n            if (l & 1) {\n\
    \                all_apply(l++, v);\n            }\n            if (r & 1) {\n\
    \                all_apply(--r, v);\n            }\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n};\n\n};  // namespace kyopro\n\n/// @docs docs/data-structure/dual_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/AOJ/DSL/2_E_dual.test.cpp
  - test/AOJ/DSL/2_D_dual.test.cpp
documentation_of: src/data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dual_segtree.hpp
- /library/src/data-structure/dual_segtree.hpp.html
title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
