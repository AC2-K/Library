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
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam id F \u306E\
    \u5358\u4F4D\u5143\n */\ntemplate <class F, F (*composition)(F, F), F (*id)()>\n\
    class dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\npublic:\n\
    \    dual_segtree() {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg\
    \ = 0;\n        while (sz < _n) {\n            ++lg;\n            sz <<= 1;\n\
    \        }\n        dat.assign(sz << 1, id());\n    }\n\nprivate:\n    void update(int\
    \ p, const F& v) { dat[p] = composition(dat[p], v); }\n    void push(int p) {\n\
    \        if (dat[p] == id()) {\n            return;\n        }\n        update(p\
    \ << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n        dat[p] = id();\n\
    \    }\n\npublic:\n    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\
    \n        F res = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--)\
    \ {\n            push(p >> i);\n        }\n        return dat[p];\n    }\n\n \
    \   void apply(int l, int r, const F& v) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n        l += sz, r += sz;\n        for\
    \ (int i = lg; i > 0; i--) {\n            if (((l >> i) << i) != l) {\n      \
    \          push(l >> i);\n            }\n            if (((r >> i) << i) != r)\
    \ {\n                push((r - 1) >> i);\n            }\n        }\n        while\
    \ (l < r) {\n            if (l & 1) {\n                update(l++, v);\n     \
    \       }\n            if (r & 1) {\n                update(--r, v);\n       \
    \     }\n            l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/data-structure/dual_segtree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    /**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam F\
    \ \u4F5C\u7528\u7D20\n * @tparam id F \u306E\u5358\u4F4D\u5143\n */\ntemplate\
    \ <class F, F (*composition)(F, F), F (*id)()>\nclass dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\npublic:\n    dual_segtree() {}\n    dual_segtree(int\
    \ _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while (sz < _n) {\n       \
    \     ++lg;\n            sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n\
    \    }\n\nprivate:\n    void update(int p, const F& v) { dat[p] = composition(dat[p],\
    \ v); }\n    void push(int p) {\n        if (dat[p] == id()) {\n            return;\n\
    \        }\n        update(p << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n\
    \        dat[p] = id();\n    }\n\npublic:\n    F operator[](int p) {\n       \
    \ assert(0 <= p && p < _n);\n\n        F res = id();\n\n        p += sz;\n   \
    \     for (int i = lg; i > 0; i--) {\n            push(p >> i);\n        }\n \
    \       return dat[p];\n    }\n\n    void apply(int l, int r, const F& v) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n \
    \       l += sz, r += sz;\n        for (int i = lg; i > 0; i--) {\n          \
    \  if (((l >> i) << i) != l) {\n                push(l >> i);\n            }\n\
    \            if (((r >> i) << i) != r) {\n                push((r - 1) >> i);\n\
    \            }\n        }\n        while (l < r) {\n            if (l & 1) {\n\
    \                update(l++, v);\n            }\n            if (r & 1) {\n  \
    \              update(--r, v);\n            }\n            l >>= 1, r >>= 1;\n\
    \        }\n    }\n};\n\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/dual_segtree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2_D_dual.test.cpp
  - test/AOJ/DSL/2_E_dual.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
documentation_of: src/data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dual_segtree.hpp
- /library/src/data-structure/dual_segtree.hpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---