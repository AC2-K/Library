---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int i =\
    \ 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 3 \"data-structure/segtree.hpp\"\nnamespace kyopro {\n/// @brief Segment\
    \ Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> class segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n\
    \n  public:\n    segtree() : segtree(0) {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& vec) : n((int)vec.size()) {\n  \
    \      sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n   \
    \         lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n\n\
    \        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n        }\n\
    \        build();\n    }\n\n    inline void set(const int p, const S& v) { dat[sz\
    \ + p] = v; }\n    inline void build() {\n        for (int i = sz - 1; i > 0;\
    \ i--) {\n            dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n        }\n\
    \    }\n    S operator[](const int p) const { return dat[sz + p]; }\n\n    inline\
    \ void update(int p, const S& v) {\n        p += sz;\n        dat[p] = v;\n  \
    \      while (p >>= 1) {\n            dat[p] = op(dat[(p << 1)], dat[(p << 1)\
    \ ^ 1]);\n        }\n    }\n\n    inline S prod(int l, int r) const {\n      \
    \  if (l == 0 && r == n) {\n            return dat[1];\n        }\n        l +=\
    \ sz, r += sz;\n        S sml = e(), smr = e();\n        while (l != r) {\n  \
    \          if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr = op(dat[--r],\
    \ smr);\n            l >>= 1, r >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n    inline void apply(int p, const S& v) { update(p, op(dat[sz + p], v));\
    \ }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/segtree.md\n\
    #line 4 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\
    \n\nlong long op(long long x, long long y) { return x + y; }\nlong long e() {\
    \ return 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\",&n,&q);\n    std::vector<long\
    \ long> a(n);\n    for (auto& aa : a) {\n        scanf(\"%lld\",&aa);\n    }\n\
    \n    kyopro::segtree<long long, op, e> seg(a);\n    while (q--) {\n        int\
    \ t;\n        scanf(\"%d\",&t);\n        if (!t) {\n            int p, x;\n  \
    \          scanf(\"%d%d\",&p,&x);\n            seg.apply(p, x);\n        }\n \
    \       else {\n            int l, r;\n            scanf(\"%d%d\",&l,&r);\n  \
    \          printf(\"%lld\\n\",seg.prod(l, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"template.hpp\"\n#include\"../../../data-structure/segtree.hpp\"\n\n\
    long long op(long long x, long long y) { return x + y; }\nlong long e() { return\
    \ 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\",&n,&q);\n    std::vector<long\
    \ long> a(n);\n    for (auto& aa : a) {\n        scanf(\"%lld\",&aa);\n    }\n\
    \n    kyopro::segtree<long long, op, e> seg(a);\n    while (q--) {\n        int\
    \ t;\n        scanf(\"%d\",&t);\n        if (!t) {\n            int p, x;\n  \
    \          scanf(\"%d%d\",&p,&x);\n            seg.apply(p, x);\n        }\n \
    \       else {\n            int l, r;\n            scanf(\"%d%d\",&l,&r);\n  \
    \          printf(\"%lld\\n\",seg.prod(l, r));\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 03:34:55+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
---
