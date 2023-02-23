---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: sparse table
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C
  bundledCode: "#line 1 \"test/AOJ/GRL/5/C.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"data-structure/sparse_table.hpp\"\ntemplate<class\
    \ T>\nclass sparse_table {\n    vector<vector<T>> table;\n    vector<int> look_up;\n\
    public:\n    sparse_table(const vector<T>& vec = {}) {\n        int sz = vec.size();\n\
    \        int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, vector<T>(1 << log));\n        for (int\
    \ i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n      \
    \  for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << log); j++) {\n                table[i][j] = min(table[i - 1][j], table[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < look_up.size(); i++) {\n            look_up[i]\
    \ = look_up[i >> 1] + 1;\n        }\n    }\n\n    T prod(int l, int r) {\n   \
    \     int b = look_up[r - l];\n        return min(table[b][l], table[b][r - (1\
    \ << b)]);\n    }\n};\n///@brief sparse table\n#line 3 \"graph/lca.hpp\"\nclass\
    \ LCA {\n    using graph = vector<vector<int>>;\n    int n;\n    graph g;\n  \
    \  vector<int> vs, in;\n    sparse_table<pair<int,int>> seg;\npublic:\n    LCA(const\
    \ graph& g) :g(g), n(g.size()),in(n) { }\n    void setup() {\n        int p =\
    \ 0;\n        vector<pair<int,int>> vec(2 * n);\n        function<void(int, int,\
    \ int)> dfs = [&](int v, int par, int now_depth) -> void {\n            in[v]\
    \ = p;\n            vec[p++]={now_depth,v};\n            for (const auto& ch :\
    \ g[v])if (ch != par) {\n                dfs(ch, v, now_depth + 1);\n        \
    \        vec[p++] = { now_depth,v };\n            }\n        };\n        dfs(0,\
    \ -1, 0);\n        seg = sparse_table<pair<int, int>>(vec);\n    }\n\n    int\
    \ query(int u, int v) {\n        if (in[u] >= in[v])swap(u, v);\n        return\
    \ seg.prod(in[u], in[v] + 1).second;\n    }\n};\n///@brief Lowest Common Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n#line 5 \"test/AOJ/GRL/5/C.cpp\"\n\n\nint main(){\n\
    \    int n;\n    cin>>n;\n    graph g(n);\n    rep(v,n){\n        int k;\n   \
    \     cin>>k;\n        rep(i,k){\n            int c;\n            cin>>c;\n  \
    \          g[c].emplace_back(v);\n            g[v].emplace_back(c);\n        }\n\
    \    }\n\n    LCA lca(g);\n    lca.setup();\n\n\n    int q;\n    cin>>q;\n   \
    \ while(q--){\n        int u,v;\n        cin>>u>>v;\n        cout<<lca.query(u,v)<<'\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C\"\
    \n\n#include\"template.hpp\"\n#include\"graph/lca.hpp\"\n\n\nint main(){\n   \
    \ int n;\n    cin>>n;\n    graph g(n);\n    rep(v,n){\n        int k;\n      \
    \  cin>>k;\n        rep(i,k){\n            int c;\n            cin>>c;\n     \
    \       g[c].emplace_back(v);\n            g[v].emplace_back(c);\n        }\n\
    \    }\n\n    LCA lca(g);\n    lca.setup();\n\n\n    int q;\n    cin>>q;\n   \
    \ while(q--){\n        int u,v;\n        cin>>u>>v;\n        cout<<lca.query(u,v)<<'\\\
    n';\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/lca.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: false
  path: test/AOJ/GRL/5/C.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/AOJ/GRL/5/C.cpp
layout: document
redirect_from:
- /library/test/AOJ/GRL/5/C.cpp
- /library/test/AOJ/GRL/5/C.cpp.html
title: test/AOJ/GRL/5/C.cpp
---
