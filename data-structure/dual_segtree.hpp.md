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
  bundledCode: "#line 1 \"data-structure/dual_segtree.hpp\"\n#include<vector>\nnamespace\
    \ library{\n\n/// @brief Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728)\n/// @tparam F \u8981\u7D20\u306E\u578B\n/// @tparam comp \u4E8C\
    \u9805\u6F14\u7B97\n/// @tparam id \u5358\u4F4D\u5143\ntemplate<class F, F(*comp)(F,\
    \ F), F(*id)(), bool is_commutative = true >\nclass dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\n  public:\n    dual_segtree() : dual_segtree(0){}\n\
    \    dual_segtree(int _n) : _n(_n){\n        sz = 1, lg = 0;\n        while (sz\
    \ < _n) {\n            lg++;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\nprivate:\n\tvoid all_apply(int p, const F& v) {\n\t\t\
    dat[p] = comp(dat[p], v);\n\t}\n\tvoid push(int p) {\n\t\tif (dat[p] == id())\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tall_apply(p << 1 | 0, dat[p]);\n\t\tall_apply(p\
    \ << 1 | 1, dat[p]);\n\t\tdat[p] = id();\n\t}\npublic:\n\tF operator[](int p)\
    \ {\n\t\tassert(0 <= p && p < _n);\n\n\t\tF res = id();\n\n\t\tp += sz;\n\t\t\
    for (int i = lg; i > 0; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\treturn dat[p];\n\
    \t}\npublic:\n\n\tvoid apply(int l, int r, const F& v) {\n\t\tassert(0 <= l &&\
    \ l <= r && r <= _n);\n\t\tif (l == r)return;\n\t\tl += sz, r += sz;\n\t\tif (is_commutative)\
    \ {\n\t\t\tfor (int i = lg; i > 0; i--) {\n\t\t\t\tif (((l >> i) << i) != l) {\n\
    \t\t\t\t\tpush(l >> i);\n\t\t\t\t}\n\t\t\t\tif (((r >> i) << i) != r) {\n\t\t\t\
    \t\tpush((r - 1) >> i);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\twhile (l < r) {\n\t\t\
    \tif (l & 1) {\n\t\t\t\tall_apply(l++, v);\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\
    \tall_apply(--r, v);\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t}\n};\n};  //\
    \ namespace library\n\n\n\n/// @docs docs/data-structure/dual_segtree.md\n"
  code: "#include<vector>\nnamespace library{\n\n/// @brief Dual Segmenttree(\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n/// @tparam F \u8981\u7D20\u306E\u578B\
    \n/// @tparam comp \u4E8C\u9805\u6F14\u7B97\n/// @tparam id \u5358\u4F4D\u5143\
    \ntemplate<class F, F(*comp)(F, F), F(*id)(), bool is_commutative = true >\nclass\
    \ dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\n  public:\n\
    \    dual_segtree() : dual_segtree(0){}\n    dual_segtree(int _n) : _n(_n){\n\
    \        sz = 1, lg = 0;\n        while (sz < _n) {\n            lg++;\n     \
    \       sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\nprivate:\n\
    \tvoid all_apply(int p, const F& v) {\n\t\tdat[p] = comp(dat[p], v);\n\t}\n\t\
    void push(int p) {\n\t\tif (dat[p] == id()) {\n\t\t\treturn;\n\t\t}\n\t\tall_apply(p\
    \ << 1 | 0, dat[p]);\n\t\tall_apply(p << 1 | 1, dat[p]);\n\t\tdat[p] = id();\n\
    \t}\npublic:\n\tF operator[](int p) {\n\t\tassert(0 <= p && p < _n);\n\n\t\tF\
    \ res = id();\n\n\t\tp += sz;\n\t\tfor (int i = lg; i > 0; i--) {\n\t\t\tpush(p\
    \ >> i);\n\t\t}\n\t\treturn dat[p];\n\t}\npublic:\n\n\tvoid apply(int l, int r,\
    \ const F& v) {\n\t\tassert(0 <= l && l <= r && r <= _n);\n\t\tif (l == r)return;\n\
    \t\tl += sz, r += sz;\n\t\tif (is_commutative) {\n\t\t\tfor (int i = lg; i > 0;\
    \ i--) {\n\t\t\t\tif (((l >> i) << i) != l) {\n\t\t\t\t\tpush(l >> i);\n\t\t\t\
    \t}\n\t\t\t\tif (((r >> i) << i) != r) {\n\t\t\t\t\tpush((r - 1) >> i);\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tall_apply(l++,\
    \ v);\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tall_apply(--r, v);\n\t\t\t}\n\t\t\t\
    l >>= 1, r >>= 1;\n\t\t}\n\t}\n};\n};  // namespace library\n\n\n\n/// @docs docs/data-structure/dual_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2_E_dual.test.cpp
  - test/AOJ/DSL/2_D_dual.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
documentation_of: data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/dual_segtree.hpp
- /library/data-structure/dual_segtree.hpp.html
title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
