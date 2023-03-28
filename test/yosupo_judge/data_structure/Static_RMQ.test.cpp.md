---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 =\
    \ 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1\
    \ };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 1 \"data-structure/sparse_table.hpp\"\n/// @brief Sparse Table\n/// @tparam\
    \ T \u8981\u7D20\u306E\u578B\n/// @docs docs/data-structure/sparse_table.md\n\n\
    template<class T>\nclass sparse_table {\n    vector<T> vec;\n    vector<vector<T>>\
    \ table;\n    vector<int> look_up;\npublic:\n    sparse_table(int n) : vec(n)\
    \ {}\n    sparse_table(const vector<T>& vec) : vec(vec) {}\n    void set(int p,\
    \ const T& v) { vec[p] = v; }\n    void build() {\n        int sz = vec.size();\n\
    \        int log = 0;\n        while ((1 << log) <= sz) {\n            log++;\n\
    \        }\n        table.assign(log, vector<T>(1 << log));\n        for (int\
    \ i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n        }\n      \
    \  for (int i = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ (1 << log); j++) {\n                table[i][j] =\n                    min(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    \
    \    look_up.resize(sz + 1);\n        for (int i = 2; i < look_up.size(); i++)\
    \ {\n            look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T\
    \ prod(int l, int r) {\n        int b = look_up[r - l];\n        return min(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n#line 4 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\
    \nint main() {\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tsparse_table<int> rmq(n);\n\
    \trep(i, n) {\n\t\tint ai;\n\t\tscanf(\"%d\", &ai);\n\t\trmq.set(i, ai);\n\t}\n\
    \trmq.build();\n\twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\", &l, &r);\n\
    \t\tprintf(\"%d\\n\", &rmq);\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include\"\
    template.hpp\"\n#include\"data-structure/sparse_table.hpp\"\nint main() {\n\t\
    int n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tsparse_table<int> rmq(n);\n\trep(i, n)\
    \ {\n\t\tint ai;\n\t\tscanf(\"%d\", &ai);\n\t\trmq.set(i, ai);\n\t}\n\trmq.build();\n\
    \twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\", &l, &r);\n\t\tprintf(\"%d\\\
    n\", &rmq);\n\t}\n}"
  dependsOn:
  - template.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-03-28 11:00:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
