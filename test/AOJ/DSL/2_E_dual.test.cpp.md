---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/dual_segtree.hpp
    title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N)  for(int\
    \ i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/dual_segtree.hpp\"\nnamespace library{\n\n/// @brief Dual\
    \ Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n/// @tparam F\
    \ \u8981\u7D20\u306E\u578B\n/// @tparam comp \u4E8C\u9805\u6F14\u7B97\n/// @tparam\
    \ id \u5358\u4F4D\u5143\ntemplate<class F, F(*comp)(F, F), F(*id)(), bool is_commutative\
    \ = true >\nclass dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\
    \n  public:\n    dual_segtree() : dual_segtree(0){}\n    dual_segtree(int _n)\
    \ : _n(_n){\n        sz = 1, lg = 0;\n        while (sz < _n) {\n            lg++;\n\
    \            sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\
    \nprivate:\n\tvoid all_apply(int p, const F& v) {\n\t\tdat[p] = comp(dat[p], v);\n\
    \t}\n\tvoid push(int p) {\n\t\tif (dat[p] == id()) {\n\t\t\treturn;\n\t\t}\n\t\
    \tall_apply(p << 1 | 0, dat[p]);\n\t\tall_apply(p << 1 | 1, dat[p]);\n\t\tdat[p]\
    \ = id();\n\t}\npublic:\n\tF operator[](int p) {\n\t\tassert(0 <= p && p < _n);\n\
    \n\t\tF res = id();\n\n\t\tp += sz;\n\t\tfor (int i = lg; i > 0; i--) {\n\t\t\t\
    push(p >> i);\n\t\t}\n\t\treturn dat[p];\n\t}\npublic:\n\n\tvoid apply(int l,\
    \ int r, const F& v) {\n\t\tassert(0 <= l && l <= r && r <= _n);\n\t\tif (l ==\
    \ r)return;\n\t\tl += sz, r += sz;\n\t\tif (is_commutative) {\n\t\t\tfor (int\
    \ i = lg; i > 0; i--) {\n\t\t\t\tif (((l >> i) << i) != l) {\n\t\t\t\t\tpush(l\
    \ >> i);\n\t\t\t\t}\n\t\t\t\tif (((r >> i) << i) != r) {\n\t\t\t\t\tpush((r -\
    \ 1) >> i);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1)\
    \ {\n\t\t\t\tall_apply(l++, v);\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tall_apply(--r,\
    \ v);\n\t\t\t}\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t}\n};\n};  // namespace library\n\
    \n\n\n/// @docs docs/data-structure/dual_segtree.md\n#line 5 \"test/AOJ/DSL/2_E_dual.test.cpp\"\
    \nusing namespace std;\nusing namespace library;\nusing ull = unsigned long long;\n\
    ull op(ull x, ull y) { return x + y; }\null e() { return 0; }\nint main() {\n\
    \    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    dual_segtree<ull, op, e> seg(n);\n\
    \    while (q--) {\n        int ty;\n        scanf(\"%d\", &ty);\n        if (!ty)\
    \ {\n            int l, r;\n            ull x;\n            scanf(\"%d%d%lld\"\
    , &l, &r, &x);\n            l--, r--;\n            seg.apply(l, r + 1, x);\n \
    \       } else {\n            int i;\n            scanf(\"%d\", &i);\n       \
    \     i--;\n            printf(\"%lld\\n\", seg[i]);\n        }\n        // seg.print();\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\nusing namespace\
    \ std;\nusing namespace library;\nusing ull = unsigned long long;\null op(ull\
    \ x, ull y) { return x + y; }\null e() { return 0; }\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n    dual_segtree<ull, op, e> seg(n);\n   \
    \ while (q--) {\n        int ty;\n        scanf(\"%d\", &ty);\n        if (!ty)\
    \ {\n            int l, r;\n            ull x;\n            scanf(\"%d%d%lld\"\
    , &l, &r, &x);\n            l--, r--;\n            seg.apply(l, r + 1, x);\n \
    \       } else {\n            int i;\n            scanf(\"%d\", &i);\n       \
    \     i--;\n            printf(\"%lld\\n\", seg[i]);\n        }\n        // seg.print();\n\
    \    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_dual.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_dual.test.cpp
- /verify/test/AOJ/DSL/2_E_dual.test.cpp.html
title: test/AOJ/DSL/2_E_dual.test.cpp
---
