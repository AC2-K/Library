---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL/2_D_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/dual_segtree.hpp\"\n\n\
    /// @brief Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\
    /// @tparam F \u8981\u7D20\u306E\u578B\n/// @tparam comp \u4E8C\u9805\u6F14\u7B97\
    \n/// @tparam id \u5358\u4F4D\u5143\n/// @docs docs/data-structure/dual_segtree.md\n\
    template<class F, F(*comp)(F, F), F(*id)(), bool is_commutative = true >\nclass\
    \ dual_segtree {\n\tvector<F> dat;\n\tint _n, sz, lg;\n\npublic:\n\tdual_segtree()\
    \ :dual_segtree(0) {}\n\tdual_segtree(int _n) :_n(_n) {\n\t\tsz = 1, lg = 0;\n\
    \t\twhile (sz < _n) {\n\t\t\tlg++;\n\t\t\tsz <<= 1;\n\t\t}\n\t\tdat.assign(sz\
    \ << 1, id());\n\t}\n\nprivate:\n\tvoid all_apply(int p, const F& v) {\n\t\tdat[p]\
    \ = comp(dat[p], v);\n\t}\n\tvoid push(int p) {\n\t\tif (dat[p] == id()) {\n\t\
    \t\treturn;\n\t\t}\n\t\tall_apply(p << 1 | 0, dat[p]);\n\t\tall_apply(p << 1 |\
    \ 1, dat[p]);\n\t\tdat[p] = id();\n\t}\npublic:\n\tF operator[](int p) {\n\t\t\
    assert(0 <= p && p < _n);\n\n\t\tF res = id();\n\n\t\tp += sz;\n\t\tfor (int i\
    \ = lg; i > 0; i--) {\n\t\t\tpush(p >> i);\n\t\t}\n\t\treturn dat[p];\n\t}\npublic:\n\
    \n\tvoid apply(int l, int r, const F& v) {\n\t\tif (l == r)return;\n\t\tl += sz,\
    \ r += sz;\n\t\tif (is_commutative) {\n\t\t\tfor (int i = lg; i > 0; i--) {\n\t\
    \t\t\tif (((l >> i) << i) != l) {\n\t\t\t\t\tpush(l >> i);\n\t\t\t\t}\n\t\t\t\t\
    if (((r >> i) << i) != r) {\n\t\t\t\t\tpush((r - 1) >> i);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tall_apply(l++, v);\n\
    \t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tall_apply(--r, v);\n\t\t\t}\n\t\t\tl >>=\
    \ 1, r >>= 1;\n\t\t}\n\t}\n};\n#line 5 \"test/AOJ/DSL/2_D_dual.test.cpp\"\n\n\
    using ull = unsigned long long;\null op(ull x, ull y) {\n\treturn y;\t\n}\null\
    \ e() {\n\treturn (1ll << 31) - 1;\n}\nint main() {\n\tint n, q;\n\tcin >> n >>\
    \ q;\n\tdual_segtree<ull,op, e> seg(n);\n\twhile (q--) {\n\t\tint ty;\n\t\tcin\
    \ >> ty;\n\t\tif (ty == 0) {\n\t\t\tint l, r;\n\t\t\tull x;\n\t\t\tcin >> l >>\
    \ r >> x;\n\t\t\tseg.apply(l, r + 1, x);\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\
    \tcin >> i;\n\t\t\tcout << seg[i] << '\\n';\n\t\t}\n\t\t//seg.print();\n\t}\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\n\nusing\
    \ ull = unsigned long long;\null op(ull x, ull y) {\n\treturn y;\t\n}\null e()\
    \ {\n\treturn (1ll << 31) - 1;\n}\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\
    \tdual_segtree<ull,op, e> seg(n);\n\twhile (q--) {\n\t\tint ty;\n\t\tcin >> ty;\n\
    \t\tif (ty == 0) {\n\t\t\tint l, r;\n\t\t\tull x;\n\t\t\tcin >> l >> r >> x;\n\
    \t\t\tseg.apply(l, r + 1, x);\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\
    \t\t\tcout << seg[i] << '\\n';\n\t\t}\n\t\t//seg.print();\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_D_dual.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 14:34:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_D_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_D_dual.test.cpp
- /verify/test/AOJ/DSL/2_D_dual.test.cpp.html
title: test/AOJ/DSL/2_D_dual.test.cpp
---
