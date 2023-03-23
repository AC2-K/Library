---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/other/mo.md
    document_title: mo's algorithm
    links: []
  bundledCode: "#line 1 \"out.cpp\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x)\
    \ (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\n\
    using ll = long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\n\
    using P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\n\
    constexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t\
    \ MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = {\
    \ 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void\
    \ chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"other/mo.hpp\"\nclass Mo {\n    int n;\n    vector<pair<int, int>> lr;\n\
    \    vector<int> ord;\npublic:\n  explicit Mo(int n) : n(n) { lr.reserve(n); }\n\
    \  void add(int l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    inline void\
    \ line_up() {\n        int q = lr.size();\n        int bs = n / min<int>(n, (int)sqrt(q));\n\
    \        ord.resize(q);\n        iota(begin(ord), end(ord), 0);\n        sort(begin(ord),\
    \ end(ord), [&](int a, int b) {\n            int ablock = lr[a].first / bs, bblock\
    \ = lr[b].first / bs;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second\
    \ < lr[b].second;\n            });\n    }\npublic:\n    template< typename AL,\
    \ typename AR, typename EL, typename ER, typename O >\n    void build(const AL&\
    \ add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm\n\
    /// @docs docs/other/mo.md\n#line 3 \"main.cpp\"\n#include<atcoder/all>\nint op(int\
    \ x,int y) { return x + y; }\nint e() { return 0; }\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n    vector<int> a(n);\n    for (auto& aa :\
    \ a) {\n        scanf(\"%d\", &aa);\n    }\n    auto press = a;\n    sort(all(press));\n\
    \    press.erase(unique(all(press)), press.end());\n    for(auto&aa:a){\n    \
    \    aa = lower_bound(all(press), aa) - press.begin();\n    }\n    Mo mo(q);\n\
    \    vector<int> k(q);\n    rep(i, q) {\n        int l, r;\n        scanf(\"%d%d%d\"\
    , &l, &r, &k[i]);\n        mo.add(l, r);\n    }\n\n    atcoder::segtree<int, op,\
    \ e> sg(n);\n    auto add = [&](int x) -> void { sg.add(a[x], 1); };\n    auto\
    \ del = [&](int x) -> void { sg.add(a[x], -1); };\n    vector<int> ans(q);\n \
    \   auto out = [&](int x) -> void {\n        auto is_ok = [&](int sum) -> bool\
    \ { return sum <= k[x]; };\n        ans[x] = sg.max_left(0, is_ok);\n    };\n\
    \    mo.build(add, del, out);\n    for(auto&ai:ans){\n        printf(\"%d\\n\"\
    , ai);\n    }\n}\n"
  code: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"other/mo.hpp\"\nclass Mo {\n    int n;\n    vector<pair<int, int>> lr;\n\
    \    vector<int> ord;\npublic:\n  explicit Mo(int n) : n(n) { lr.reserve(n); }\n\
    \  void add(int l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    inline void\
    \ line_up() {\n        int q = lr.size();\n        int bs = n / min<int>(n, (int)sqrt(q));\n\
    \        ord.resize(q);\n        iota(begin(ord), end(ord), 0);\n        sort(begin(ord),\
    \ end(ord), [&](int a, int b) {\n            int ablock = lr[a].first / bs, bblock\
    \ = lr[b].first / bs;\n            if (ablock != bblock) return ablock < bblock;\n\
    \            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second\
    \ < lr[b].second;\n            });\n    }\npublic:\n    template< typename AL,\
    \ typename AR, typename EL, typename ER, typename O >\n    void build(const AL&\
    \ add_left, const AR& add_right, const EL& erase_left, const ER& erase_right,\
    \ const O& out) {\n        line_up();\n        int l = 0, r = 0;\n        for\
    \ (const auto& idx : ord) {\n            while (l > lr[idx].first) add_left(--l);\n\
    \            while (r < lr[idx].second) add_right(r++);\n            while (l\
    \ < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template< typename A, typename\
    \ E, typename O >\n    void build(const A& add, const E& erase, const O& out)\
    \ {\n        build(add, add, erase, erase, out);\n    }\n};\n/// @brief mo's algorithm\n\
    /// @docs docs/other/mo.md\n#line 3 \"main.cpp\"\n#include<atcoder/all>\nint op(int\
    \ x,int y) { return x + y; }\nint e() { return 0; }\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n    vector<int> a(n);\n    for (auto& aa :\
    \ a) {\n        scanf(\"%d\", &aa);\n    }\n    auto press = a;\n    sort(all(press));\n\
    \    press.erase(unique(all(press)), press.end());\n    for(auto&aa:a){\n    \
    \    aa = lower_bound(all(press), aa) - press.begin();\n    }\n    Mo mo(q);\n\
    \    vector<int> k(q);\n    rep(i, q) {\n        int l, r;\n        scanf(\"%d%d%d\"\
    , &l, &r, &k[i]);\n        mo.add(l, r);\n    }\n\n    atcoder::segtree<int, op,\
    \ e> sg(n);\n    auto add = [&](int x) -> void { sg.add(a[x], 1); };\n    auto\
    \ del = [&](int x) -> void { sg.add(a[x], -1); };\n    vector<int> ans(q);\n \
    \   auto out = [&](int x) -> void {\n        auto is_ok = [&](int sum) -> bool\
    \ { return sum <= k[x]; };\n        ans[x] = sg.max_left(0, is_ok);\n    };\n\
    \    mo.build(add, del, out);\n    for(auto&ai:ans){\n        printf(\"%d\\n\"\
    , ai);\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2023-03-23 15:53:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: mo's algorithm
---
