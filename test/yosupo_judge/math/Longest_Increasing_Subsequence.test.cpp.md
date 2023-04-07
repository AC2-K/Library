---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 3 \"data-structure/segtree.hpp\"\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\ntemplate <class S, S (*op)(S, S), S (*e)()> class segtree\
    \ {\n    int lg, sz, n;\n    std::vector<S> dat;\n\n  public:\n    segtree() :\
    \ segtree(0){}\n    segtree(int n) : segtree(std::vector<S>(n, e())){}\n    segtree(const\
    \ std::vector<S>& vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n     \
    \   while (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n \
    \       dat = std::vector<S>(sz << 1, e());\n        \n        for (int i = 0;\
    \ i < n; i++) {\n            set(i, vec[i]);\n        }\n        build();\n  \
    \  }\n    inline void set(int p, const S& v) { dat[sz + p] = v; }\n    inline\
    \ void build() {\n        for (int i = sz - 1; i > 0; i--) {\n            dat[i]\
    \ = op(dat[i << 1 | 0], dat[i << 1 | 1]);\n        }\n    }\n    S operator[](int\
    \ p) const { return dat[sz + p]; }\n    inline void update(int p, const S& v)\
    \ {\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1) {\n      \
    \      dat[p] = op(dat[p << 1 | 0], dat[p << 1 | 1]);\n        }\n    }\n    S\
    \ prod(int l, int r) const {\n        if (l == 0 && r == n) {\n            return\
    \ dat[1];\n        }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n\
    \        while (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n \
    \           if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n        return op(sml, smr);\n    }\n    inline void apply(int p,\
    \ const S& v) { update(p, op(dat[sz + p], v)); }\n};\n\n/// @docs docs/data-structure/segtree.md\n\
    #line 4 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\nusing\
    \ S = P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\nint main()\
    \ {\n    int n;\n    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for (auto&\
    \ aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    {\n        vector<int> tmp\
    \ = a;\n        sort(all(tmp));\n        tmp.erase(unique(all(tmp)), tmp.end());\n\
    \        for (auto& aa : a) {\n            aa = lower_bound(all(tmp), aa) - tmp.begin();\n\
    \        }\n    }\n    vector<int> prv(n, -1);\n    iota(all(prv), 0);\n    segtree<S,\
    \ op, e> dp(n + 1);\n    rep(i, n) {\n        auto [mx, p] = dp.prod(0, a[i]);\n\
    \        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n          \
    \  dp.update(a[i], P(mx + 1, i));\n        }\n    }\n    auto [res, cur] = dp.prod(0,\
    \ n + 1);\n    vector<int> idx;\n    idx.reserve((size_t)res);\n    rep(i, res)\
    \ {\n        idx.emplace_back(cur);\n        cur = prv[cur];\n    }\n    printf(\"\
    %lld\\n\", idx.size());\n    reverse(all(idx));\n    for (auto& i : idx) {\n \
    \       printf(\"%d \", i);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing S =\
    \ P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\nint main()\
    \ {\n    int n;\n    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for (auto&\
    \ aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    {\n        vector<int> tmp\
    \ = a;\n        sort(all(tmp));\n        tmp.erase(unique(all(tmp)), tmp.end());\n\
    \        for (auto& aa : a) {\n            aa = lower_bound(all(tmp), aa) - tmp.begin();\n\
    \        }\n    }\n    vector<int> prv(n, -1);\n    iota(all(prv), 0);\n    segtree<S,\
    \ op, e> dp(n + 1);\n    rep(i, n) {\n        auto [mx, p] = dp.prod(0, a[i]);\n\
    \        if (mx + 1 >= dp[a[i]].first) {\n            prv[i] = p;\n          \
    \  dp.update(a[i], P(mx + 1, i));\n        }\n    }\n    auto [res, cur] = dp.prod(0,\
    \ n + 1);\n    vector<int> idx;\n    idx.reserve((size_t)res);\n    rep(i, res)\
    \ {\n        idx.emplace_back(cur);\n        cur = prv[cur];\n    }\n    printf(\"\
    %lld\\n\", idx.size());\n    reverse(all(idx));\n    for (auto& i : idx) {\n \
    \       printf(\"%d \", i);\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 13:04:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp.html
title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
---
