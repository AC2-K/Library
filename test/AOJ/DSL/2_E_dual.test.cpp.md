---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/dual_segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
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
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n/**\n * @brief \u53CC\u5BFE\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam\
    \ id F \u306E\u5358\u4F4D\u5143\n */\ntemplate <class F, F (*composition)(F, F),\
    \ F (*id)()>\nclass dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\
    \npublic:\n    dual_segtree() {}\n    dual_segtree(int _n) : _n(_n) {\n      \
    \  sz = 1, lg = 0;\n        while (sz < _n) {\n            ++lg;\n           \
    \ sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\nprivate:\n\
    \    void update(int p, const F& v) { dat[p] = composition(dat[p], v); }\n   \
    \ void push(int p) {\n        if (dat[p] == id()) {\n            return;\n   \
    \     }\n        update(p << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n\
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
    \ */\n#line 5 \"test/AOJ/DSL/2_E_dual.test.cpp\"\n\nusing ull = unsigned long\
    \ long;\ninline ull op(ull x, ull y) { return x + y; }\ninline ull e() { return\
    \ 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::dual_segtree<ull,\
    \ op, e> seg(n);\n    while (q--) {\n        int ty;\n        scanf(\"%d\", &ty);\n\
    \        if (ty == 0) {\n            int l, r;\n            ull x;\n         \
    \   scanf(\"%d%d%d\", &l, &r, &x);\n            l--, r--;\n            seg.apply(l,\
    \ r + 1, x);\n        } else {\n            int i;\n            scanf(\"%d\",\
    \ &i);\n            i--;\n            printf(\"%lld\\n\", seg[i]);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n\n\
    #include <iostream>\n#include \"../../../src/data-structure/dual_segtree.hpp\"\
    \n\nusing ull = unsigned long long;\ninline ull op(ull x, ull y) { return x +\
    \ y; }\ninline ull e() { return 0; }\nint main() {\n    int n, q;\n    scanf(\"\
    %d%d\", &n, &q);\n    kyopro::dual_segtree<ull, op, e> seg(n);\n    while (q--)\
    \ {\n        int ty;\n        scanf(\"%d\", &ty);\n        if (ty == 0) {\n  \
    \          int l, r;\n            ull x;\n            scanf(\"%d%d%d\", &l, &r,\
    \ &x);\n            l--, r--;\n            seg.apply(l, r + 1, x);\n        }\
    \ else {\n            int i;\n            scanf(\"%d\", &i);\n            i--;\n\
    \            printf(\"%lld\\n\", seg[i]);\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_dual.test.cpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_dual.test.cpp
- /verify/test/AOJ/DSL/2_E_dual.test.cpp.html
title: test/AOJ/DSL/2_E_dual.test.cpp
---
