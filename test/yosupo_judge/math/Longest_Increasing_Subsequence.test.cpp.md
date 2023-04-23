---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include<iostream>\n#include<algorithm>\n#include<numeric>\n#line 2 \"src/data-structure/segtree.hpp\"\
    \n#include <vector>\nnamespace kyopro {\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nclass segtree\
    \ {\n    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree() {}\n\
    \    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>&\
    \ vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n)\
    \ {\n            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    inline void set(int p, const S& v)\
    \ { dat[sz + p] = v; }\n    inline void build() {\n        for (int i = sz - 1;\
    \ i > 0; i--) {\n            dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n  \
    \      }\n    }\n    S operator[](int p) const { return dat[sz + p]; }\n\n   \
    \ inline void update(int p, const S& v) {\n        p += sz;\n        dat[p] =\
    \ v;\n        while (p >>= 1) {\n            dat[p] = op(dat[(p << 1)], dat[(p\
    \ << 1) ^ 1]);\n        }\n    }\n\n    inline S prod(int l, int r) const {\n\
    \        if (l == 0 && r == n) {\n            return dat[1];\n        }\n    \
    \    l += sz, r += sz;\n        S sml = e(), smr = e();\n        while (l != r)\
    \ {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr\
    \ = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n    inline void apply(int p, const S& v) { update(p, op(dat[sz\
    \ + p], v)); }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/segtree.md\n\
    #line 6 \"test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp\"\nusing\
    \ S = std::pair<int,int>;\ninline S op(S x, S y) { return max(x,y); }\ninline\
    \ S e() { return S{0,0}; }\n\nusing namespace std;\nint main() {\n    int n;\n\
    \    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for (auto& aa : a) {\n   \
    \     scanf(\"%d\", &aa);\n    }\n    {\n        vector<int> tmp = a;\n      \
    \  std::sort(tmp.begin(),tmp.end());\n        tmp.erase(std::unique(tmp.begin(),tmp.end()),\
    \ tmp.end());\n        for (auto& aa : a) {\n            aa = lower_bound(tmp.begin(),tmp.end(),\
    \ aa) - tmp.begin();\n        }\n    }\n    vector<int> prv(n, -1);\n    std::iota(prv.begin(),prv.end(),\
    \ 0);\n    kyopro::segtree<S, op, e> dp(n + 1);\n    for(int i=0;i<n;i++) {\n\
    \        auto [mx, p] = dp.prod(0, a[i]);\n        if (mx + 1 >= dp[a[i]].first)\
    \ {\n            prv[i] = p;\n            dp.update(a[i], S{mx + 1, i});\n   \
    \     }\n    }\n    auto [res, cur] = dp.prod(0, n + 1);\n    std::vector<int>\
    \ idx;\n    idx.reserve((size_t)res);\n    for(int i=0;i<res;i++) {\n        idx.emplace_back(cur);\n\
    \        cur = prv[cur];\n    }\n    printf(\"%d\\n\", (int)idx.size());\n   \
    \ std::reverse(idx.begin(),idx.end());\n    for (auto& i : idx) {\n        printf(\"\
    %d \", i);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include<iostream>\n#include<algorithm>\n#include<numeric>\n#include\"../../../src/data-structure/segtree.hpp\"\
    \nusing S = std::pair<int,int>;\ninline S op(S x, S y) { return max(x,y); }\n\
    inline S e() { return S{0,0}; }\n\nusing namespace std;\nint main() {\n    int\
    \ n;\n    scanf(\"%d\", &n);\n    vector<int> a(n);\n    for (auto& aa : a) {\n\
    \        scanf(\"%d\", &aa);\n    }\n    {\n        vector<int> tmp = a;\n   \
    \     std::sort(tmp.begin(),tmp.end());\n        tmp.erase(std::unique(tmp.begin(),tmp.end()),\
    \ tmp.end());\n        for (auto& aa : a) {\n            aa = lower_bound(tmp.begin(),tmp.end(),\
    \ aa) - tmp.begin();\n        }\n    }\n    vector<int> prv(n, -1);\n    std::iota(prv.begin(),prv.end(),\
    \ 0);\n    kyopro::segtree<S, op, e> dp(n + 1);\n    for(int i=0;i<n;i++) {\n\
    \        auto [mx, p] = dp.prod(0, a[i]);\n        if (mx + 1 >= dp[a[i]].first)\
    \ {\n            prv[i] = p;\n            dp.update(a[i], S{mx + 1, i});\n   \
    \     }\n    }\n    auto [res, cur] = dp.prod(0, n + 1);\n    std::vector<int>\
    \ idx;\n    idx.reserve((size_t)res);\n    for(int i=0;i<res;i++) {\n        idx.emplace_back(cur);\n\
    \        cur = prv[cur];\n    }\n    printf(\"%d\\n\", (int)idx.size());\n   \
    \ std::reverse(idx.begin(),idx.end());\n    for (auto& i : idx) {\n        printf(\"\
    %d \", i);\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 13:24:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
- /verify/test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp.html
title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
---
