---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/BIT.hpp
    title: Binary Index Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/BIT.hpp\"\
    \n/// @brief Binary Index Tree\n/// @tparam Type \u8981\u7D20\u306E\u578B\n///\
    \ @tparam SumType \"\u548C\u304C\" \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\n\
    /// @docs docs/data-structure/BIT.md\ntemplate <typename Type, typename SumType\
    \ = Type>\nclass BIT {\n    int _n;\n    vector<SumType> _dat;\npublic:\n    explicit\
    \ BIT(int _n) : _n(_n), _dat(_n, SumType()) {}\n\n    inline void add(int p, Type\
    \ v) {\n        p++;\n        for (; p <= _n; p += p & (-p)) {\n            _dat[p\
    \ - 1] += SumType(v);\n        }\n    }\n\n    inline SumType sum(int p) {\n \
    \       SumType res = 0;\n        for (; p > 0; p -= p & -p) {\n            res\
    \ += _dat[p - 1];\n        }\n        return res;\n    }\n\n    inline SumType\
    \ sum(int l, int r) { return sum(r) - sum(l); }\n};\n#line 4 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    BIT<ll, ll> seg(n);\n \
    \   rep(i,n){\n        int a;\n        scanf(\"%d\", &a);\n        seg.add(i,\
    \ a);\n    }\n\n    while (q--) {\n        int t;\n        scanf(\"%d\", &t);\n\
    \        if (t == 0) {\n            int p, x;\n            scanf(\"%d%d\", &p,\
    \ &x);\n            seg.add(p, x);\n        } else {\n            int l, r;\n\
    \            scanf(\"%d%d\", &l, &r);\n            printf(\"%lld\\n\", seg.sum(l,\
    \ r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/BIT.hpp\"\nint main() {\n \
    \   int n, q;\n    cin >> n >> q;\n    BIT<ll, ll> seg(n);\n    rep(i,n){\n  \
    \      int a;\n        scanf(\"%d\", &a);\n        seg.add(i, a);\n    }\n\n \
    \   while (q--) {\n        int t;\n        scanf(\"%d\", &t);\n        if (t ==\
    \ 0) {\n            int p, x;\n            scanf(\"%d%d\", &p, &x);\n        \
    \    seg.add(p, x);\n        } else {\n            int l, r;\n            scanf(\"\
    %d%d\", &l, &r);\n            printf(\"%lld\\n\", seg.sum(l, r));\n        }\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-03-26 20:22:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
---
