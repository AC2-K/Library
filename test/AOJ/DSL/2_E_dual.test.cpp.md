---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dual_segtree.hpp
    title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL/2_E_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\
    \n\n#include <iostream>\n#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n\n/// @brief Dual Segmenttree(\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\ntemplate <class F, F (*comp)(F, F),\
    \ F (*id)(), bool is_commutative = true>\nclass dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\n  public:\n    dual_segtree() : dual_segtree(0)\
    \ {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while\
    \ (sz < _n) {\n            lg++;\n            sz <<= 1;\n        }\n        dat.assign(sz\
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
    /// @docs docs/data-structure/dual_segtree.md\n#line 5 \"test/AOJ/DSL/2_E_dual.test.cpp\"\
    \n\nusing ull = unsigned long long;\null op(ull x, ull y) { return x + y; }\n\
    ull e() { return 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\
    \    kyopro::dual_segtree<ull, op, e> seg(n);\n    while (q--) {\n        int\
    \ ty;\n        scanf(\"%d\", &ty);\n        if (ty == 0) {\n            int l,\
    \ r;\n            ull x;\n            scanf(\"%d%d%d\", &l, &r, &x);\n       \
    \     l--, r--;\n            seg.apply(l, r + 1, x);\n        } else {\n     \
    \       int i;\n            scanf(\"%d\", &i);\n            i--;\n           \
    \ printf(\"%lld\\n\", seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n\n\
    #include <iostream>\n#include \"../../../src/data-structure/dual_segtree.hpp\"\
    \n\nusing ull = unsigned long long;\null op(ull x, ull y) { return x + y; }\n\
    ull e() { return 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\
    \    kyopro::dual_segtree<ull, op, e> seg(n);\n    while (q--) {\n        int\
    \ ty;\n        scanf(\"%d\", &ty);\n        if (ty == 0) {\n            int l,\
    \ r;\n            ull x;\n            scanf(\"%d%d%d\", &l, &r, &x);\n       \
    \     l--, r--;\n            seg.apply(l, r + 1, x);\n        } else {\n     \
    \       int i;\n            scanf(\"%d\", &i);\n            i--;\n           \
    \ printf(\"%lld\\n\", seg[i]);\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_dual.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_dual.test.cpp
- /verify/test/AOJ/DSL/2_E_dual.test.cpp.html
title: test/AOJ/DSL/2_E_dual.test.cpp
---
