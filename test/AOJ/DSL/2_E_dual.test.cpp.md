---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/dual_segtree.hpp
    title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL/2_E_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 4 \"data-structure/dual_segtree.hpp\"\n///\
    \ @brief Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\
    template <class F, F (*comp)(F, F), F (*id)(), bool is_commutative = true>\nclass\
    \ dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\n  public:\n\
    \    dual_segtree() : dual_segtree(0){}\n    dual_segtree(int _n) : _n(_n) {\n\
    \        sz = 1, lg = 0;\n        while (sz < _n) {\n            lg++;\n     \
    \       sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n    }\n\n  private:\n\
    \    void all_apply(int p, const F& v) { dat[p] = comp(dat[p], v); }\n    void\
    \ push(int p) {\n        if (dat[p] == id()) {\n            return;\n        }\n\
    \        all_apply(p << 1 | 0, dat[p]);\n        all_apply(p << 1 | 1, dat[p]);\n\
    \        dat[p] = id();\n    }\n\n  public:\n    F operator[](int p) const {\n\
    \        assert(0 <= p && p < _n);\n\n        F res = id();\n\n        p += sz;\n\
    \        for (int i = lg; i > 0; i--) {\n            push(p >> i);\n        }\n\
    \        return dat[p];\n    }\n\n    void apply(int l, int r, const F& v) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n \
    \       l += sz, r += sz;\n        if (is_commutative) {\n            for (int\
    \ i = lg; i > 0; i--) {\n                if (((l >> i) << i) != l) {\n       \
    \             push(l >> i);\n                }\n                if (((r >> i)\
    \ << i) != r) {\n                    push((r - 1) >> i);\n                }\n\
    \            }\n        }\n        while (l < r) {\n            if (l & 1) {\n\
    \                all_apply(l++, v);\n            }\n            if (r & 1) {\n\
    \                all_apply(--r, v);\n            }\n            l >>= 1, r >>=\
    \ 1;\n        }\n    }\n};\n\n/// @docs docs/data-structure/dual_segtree.md\n\
    #line 5 \"test/AOJ/DSL/2_E_dual.test.cpp\"\nusing ull = unsigned long long;\n\
    ull op(ull x, ull y) {\n\treturn x + y;\n}\null e() {\n\treturn 0;\n}\nint main()\
    \ {\n\tint n, q;\n\tcin >> n >> q;\n\tdual_segtree<ull,op, e> seg(n);\n\twhile\
    \ (q--) {\n\t\tint ty;\n\t\tcin >> ty;\n\t\tif (ty == 0) {\n\t\t\tint l, r;\n\t\
    \t\tull x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tl--, r--;\n\t\t\tseg.apply(l, r +\
    \ 1, x);\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\ti--;\n\t\t\t\
    cout << seg[i] << '\\n';\n\t\t}\n\t\t//seg.print();\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\nusing ull\
    \ = unsigned long long;\null op(ull x, ull y) {\n\treturn x + y;\n}\null e() {\n\
    \treturn 0;\n}\nint main() {\n\tint n, q;\n\tcin >> n >> q;\n\tdual_segtree<ull,op,\
    \ e> seg(n);\n\twhile (q--) {\n\t\tint ty;\n\t\tcin >> ty;\n\t\tif (ty == 0) {\n\
    \t\t\tint l, r;\n\t\t\tull x;\n\t\t\tcin >> l >> r >> x;\n\t\t\tl--, r--;\n\t\t\
    \tseg.apply(l, r + 1, x);\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\
    \t\ti--;\n\t\t\tcout << seg[i] << '\\n';\n\t\t}\n\t\t//seg.print();\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/dual_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_dual.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 17:48:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_dual.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_dual.test.cpp
- /verify/test/AOJ/DSL/2_E_dual.test.cpp.html
title: test/AOJ/DSL/2_E_dual.test.cpp
---
