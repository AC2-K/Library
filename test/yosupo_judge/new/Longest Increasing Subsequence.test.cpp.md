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
  bundledCode: "#line 1 \"test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\
    \n/// @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n/// @tparam S\
    \ \u8981\u7D20\u306E\u578B\n/// @tparam op \u4E8C\u9805\u6F14\u7B97\n/// @tparam\
    \ e \u5358\u4F4D\u5143\n/// @docs /home/ac2000/main/library/docs/data-structure/segtree.md\n\
    template<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\t\
    vector<S> dat;\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(vector<S>(n,\
    \ e())) {}\n\tsegtree(const vector<S>& vec) : n((int)vec.size()) {\n\t\tsz = 1,\
    \ lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\t\
    dat = vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tset(i,\
    \ vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const S&\
    \ v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i = sz\
    \ - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\t\t\
    }\n\t}\n\tS operator[](const int p) const { return dat[sz + p]; }\n\n\tinline\
    \ void update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p\
    \ >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\
    \n\tinline S prod(int l, int r) const {\n\t\tif (l == 0 && r == n) {\n\t\t\treturn\
    \ dat[1];\n\t\t}\n\t\tl += sz, r += sz;\n\t\tS sml = e(), smr = e();\n\t\twhile\
    \ (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\t\t\tif (r & 1)smr =\
    \ op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\
    \t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p, op(dat[sz + p], v));\n\
    \t}\n};\n#line 4 \"test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp\"\
    \nusing S = P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\n\
    int main() {\n    int n;\n    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for\
    \ (auto& aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    {\n        vector<int>\
    \ tmp = a;\n        sort(all(tmp));\n        tmp.erase(unique(all(tmp)), tmp.end());\n\
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
  path: test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-03-26 20:22:21+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp
- /verify/test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp.html
title: test/yosupo_judge/new/Longest Increasing Subsequence.test.cpp
---
