---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse_table.hpp
    title: sparse table
  - icon: ':x:'
    path: graph/lca.hpp
    title: "Lowest Common Ancestor(\u6700\u5C0F\u5171\u901A\u7956\u5148)"
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo judge/tree/Lowest Common Ancestor.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconst int inf = 1e9;\n\
    const ll infl = 1e18;\nconst ld eps = 1e-6;\nconst long double pi = acos(-1);\n\
    const ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0\
    \ };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"data-structure/sparse_table.hpp\"\ntemplate<class T>\nclass sparse_table\
    \ {\n    vector<vector<T>> table;\n    vector<int> look_up;\npublic:\n    sparse_table(const\
    \ vector<T>& vec = {}) {\n        int sz = vec.size();\n        int log = 0;\n\
    \        while ((1 << log) <= sz) {\n            log++;\n        }\n        table.assign(log,\
    \ vector<T>(1 << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i]\
    \ = vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n \
    \       }\n        look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size();\
    \ i++) {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n\
    \    T prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n///@brief sparse table\n#line 3 \"graph/lca.hpp\"\
    \nclass LCA {\n    using graph = vector<vector<int>>;\n    int n;\n    graph g;\n\
    \    vector<int> vs, in;\n    sparse_table<pair<int,int>> seg;\npublic:\n    LCA(const\
    \ graph& g) :g(g), n(g.size()),in(n) { }\n    void setup() {\n        int p =\
    \ 0;\n        vector<pair<int,int>> vec(2 * n);\n        function<void(int, int,\
    \ int)> dfs = [&](int v, int par, int now_depth) -> void {\n            in[v]\
    \ = p;\n            vec[p++]={now_depth,v};\n            for (const auto& ch :\
    \ g[v])if (ch != par) {\n                dfs(ch, v, now_depth + 1);\n        \
    \        vec[p++] = { now_depth,v };\n            }\n        };\n        dfs(0,\
    \ -1, 0);\n        seg = sparse_table<pair<int, int>>(vec);\n    }\n\n    int\
    \ query(int u, int v) {\n        if (in[u] >= in[v])swap(u, v);\n        return\
    \ seg.prod(in[u], in[v] + 1).second;\n    }\n};\n///@brief Lowest Common Ancestor(\u6700\
    \u5C0F\u5171\u901A\u7956\u5148)\n#line 5 \"test/yosupo judge/tree/Lowest Common\
    \ Ancestor.test.cpp\"\nint main(){\n    int n, q;\n    cin >> n >> q;\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].emplace_back(i);\n        g[i].emplace_back(p);\n    }\n    LCA\
    \ lca(g);\n    lca.setup();\n    while (q--) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        cout << lca.query(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include\"template.hpp\"\
    \n#include\"graph/lca.hpp\"\nint main(){\n    int n, q;\n    cin >> n >> q;\n\
    \    vector<vector<int>> g(n);\n    for (int i = 1; i < n; i++) {\n        int\
    \ p;\n        cin >> p;\n        g[p].emplace_back(i);\n        g[i].emplace_back(p);\n\
    \    }\n    LCA lca(g);\n    lca.setup();\n    while (q--) {\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template.hpp
  - graph/lca.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 20:50:59+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
- /verify/test/yosupo judge/tree/Lowest Common Ancestor.test.cpp.html
title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
---
