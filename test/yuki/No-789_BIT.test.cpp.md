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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yuki/No-789_BIT.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N)  for(int\
    \ i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/BIT.hpp\"\nnamespace library{\n/// @brief Binary Index Tree\n\
    /// @tparam T \u8981\u7D20\u306E\u578B\n/// @tparam SumT \"\u548C\u304C\" \u53CE\
    \u307E\u308B\u3088\u3046\u306A\u578B\ntemplate<typename T,typename SumT = T>\n\
    class BIT {\n\tstd::vector<SumT> bit;\n\tint n;\npublic:\n    BIT(int n) :n(n),\
    \ bit(n + 1, T()) {}\n\tvoid add(int p, const T& w) {\n\t\tp++;\n\t\tfor (int\
    \ x = p; x <= n; x += x & -x) {\n\t\t\tbit[x] += w;\n\t\t}\n\t}\n\n\tSumT sum(int\
    \ p)const {\n\t\tT s = 0;\n\n\t\tfor (int x = p; x > 0; x -= x & -x) {\n\t\t\t\
    s += bit[x];\n\t\t}\n\t\treturn s;\n\t}\n\n\tSumT sum(int l, int r)const {\n\t\
    \treturn sum(r) - sum(l);\n\t}\n\n    \n    int lower_bound(SumT w)const {\n \
    \       if (w <= 0)return 0;\n\n        int x = 0;\n        int k = 1;\n     \
    \   while (k < n)k <<= 1;\n        for (; k > 0; k >>= 1) {\n            if (x\
    \ + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n          \
    \      x += k;\n            }\n        }\n\n        return x + 1;\n    }\n};\n\
    };  // namespace library\n\n\n\n/// @docs docs/data-structure/BIT.md\n#line 5\
    \ \"test/yuki/No-789_BIT.test.cpp\"\n\nusing namespace std;\nusing namespace library;\n\
    int main() {\n    int n;\n    scanf(\"%d\", &n);\n    ll s = 0;\n    vector<int>\
    \ idx;\n    idx.reserve(2 * n);\n    vector<tuple<int, int, int>> query(n);\n\
    \    for (auto& [t, a, b] : query) {\n        scanf(\"%d%d%d\", &t, &a, &b);\n\
    \        idx.emplace_back(a);\n        if (t == 1) idx.emplace_back(b);\n    }\n\
    \    sort(all(idx));\n    idx.erase(unique(all(idx)), idx.end());\n    BIT<ll>\
    \ sg(2 * n + 1);\n    for (auto& [t, a, b] : query) {\n        if (t == 0) {\n\
    \            a = lower_bound(all(idx), a) - idx.begin();\n            sg.add(a,\
    \ b);\n        } else {\n            a = lower_bound(all(idx), a) - idx.begin();\n\
    \            b = lower_bound(all(idx), b) - idx.begin();\n            s += sg.sum(a,\
    \ b + 1);\n        }\n    }\n    printf(\"%lld\\n\", s);\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include\"template.hpp\"\
    \n#include\"data-structure/BIT.hpp\"\n\nusing namespace std;\nusing namespace\
    \ library;\nint main() {\n    int n;\n    scanf(\"%d\", &n);\n    ll s = 0;\n\
    \    vector<int> idx;\n    idx.reserve(2 * n);\n    vector<tuple<int, int, int>>\
    \ query(n);\n    for (auto& [t, a, b] : query) {\n        scanf(\"%d%d%d\", &t,\
    \ &a, &b);\n        idx.emplace_back(a);\n        if (t == 1) idx.emplace_back(b);\n\
    \    }\n    sort(all(idx));\n    idx.erase(unique(all(idx)), idx.end());\n   \
    \ BIT<ll> sg(2 * n + 1);\n    for (auto& [t, a, b] : query) {\n        if (t ==\
    \ 0) {\n            a = lower_bound(all(idx), a) - idx.begin();\n            sg.add(a,\
    \ b);\n        } else {\n            a = lower_bound(all(idx), a) - idx.begin();\n\
    \            b = lower_bound(all(idx), b) - idx.begin();\n            s += sg.sum(a,\
    \ b + 1);\n        }\n    }\n    printf(\"%lld\\n\", s);\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yuki/No-789_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yuki/No-789_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/No-789_BIT.test.cpp
- /verify/test/yuki/No-789_BIT.test.cpp.html
title: test/yuki/No-789_BIT.test.cpp
---
