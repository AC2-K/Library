---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/BIT.hpp
    title: Binary Index Tree
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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yuki/No-789_BIT.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/BIT.hpp\"\n/// @brief\
    \ Binary Index Tree\n/// @tparam Type \u8981\u7D20\u306E\u578B\n/// @tparam SumType\
    \ \"\u548C\u304C\" \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\n/// @docs docs/data-structure/BIT.md\n\
    template <typename Type, typename SumType = Type>\nclass BIT {\n    int _n;\n\
    \    vector<SumType> _dat;\npublic:\n    explicit BIT(int _n) : _n(_n), _dat(_n,\
    \ SumType()) {}\n\n    inline void add(int p, Type v) {\n        p++;\n      \
    \  for (; p <= _n; p += p & (-p)) {\n            _dat[p - 1] += SumType(v);\n\
    \        }\n    }\n\n    inline SumType sum(int p) {\n        SumType res = 0;\n\
    \        for (; p > 0; p -= p & -p) {\n            res += _dat[p - 1];\n     \
    \   }\n        return res;\n    }\n\n    inline SumType sum(int l, int r) { return\
    \ sum(r) - sum(l); }\n};\n#line 5 \"test/yuki/No-789_BIT.test.cpp\"\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int n;\n   \
    \ cin >> n;\n    ll s = 0;\n    vector<int> idx;\n    idx.reserve(2 * n);\n  \
    \  vector<tuple<int, int, int>> query(n);\n    for (auto& [t, a, b] : query) {\n\
    \        cin >> t >> a >> b;\n        idx.emplace_back(a);\n        if (t == 1)\
    \ idx.emplace_back(b);\n    }\n    sort(all(idx));\n    idx.erase(unique(all(idx)),\
    \ idx.end());\n    BIT<ll> sg(2 * n + 1);\n    for (auto& [t, a, b] : query) {\n\
    \        if (t == 0) {\n            a = lower_bound(all(idx), a) - idx.begin();\n\
    \            sg.add(a, b);\n        } else {\n            a = lower_bound(all(idx),\
    \ a) - idx.begin();\n            b = lower_bound(all(idx), b) - idx.begin();\n\
    \            s += sg.sum(a, b + 1);\n        }\n    }\n    cout << s << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include\"template.hpp\"\
    \n#include\"data-structure/BIT.hpp\"\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int n;\n    cin >> n;\n    ll s = 0;\n    vector<int>\
    \ idx;\n    idx.reserve(2 * n);\n    vector<tuple<int, int, int>> query(n);\n\
    \    for (auto& [t, a, b] : query) {\n        cin >> t >> a >> b;\n        idx.emplace_back(a);\n\
    \        if (t == 1) idx.emplace_back(b);\n    }\n    sort(all(idx));\n    idx.erase(unique(all(idx)),\
    \ idx.end());\n    BIT<ll> sg(2 * n + 1);\n    for (auto& [t, a, b] : query) {\n\
    \        if (t == 0) {\n            a = lower_bound(all(idx), a) - idx.begin();\n\
    \            sg.add(a, b);\n        } else {\n            a = lower_bound(all(idx),\
    \ a) - idx.begin();\n            b = lower_bound(all(idx), b) - idx.begin();\n\
    \            s += sg.sum(a, b + 1);\n        }\n    }\n    cout << s << '\\n';\n\
    }\n"
  dependsOn:
  - template.hpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yuki/No-789_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-03-28 10:54:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki/No-789_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/No-789_BIT.test.cpp
- /verify/test/yuki/No-789_BIT.test.cpp.html
title: test/yuki/No-789_BIT.test.cpp
---
