---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.hpp
    title: Sparse Table(Range Min)
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define\
    \ all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing\
    \ i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing graph\
    \ = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/sparse_table.hpp\"\nnamespace library{\n\n/// @brief Sparse\
    \ Table(Range Min)\n/// @tparam T \u8981\u7D20\u306E\u578B\n/// @docs docs/data-structure/sparse_table.md\n\
    template<class T>\nclass sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\npublic:\n    sparse_table(int n) : vec(n)\
    \ {}\n    sparse_table(const std::vector<T>& vec) : vec(vec) { build(); }\n  \
    \  void set(int p, const T& v) { vec[p] = v; }\n    void build() {\n        int\
    \ sz = vec.size();\n        int log = 0;\n        while ((1 << log) <= sz) {\n\
    \            log++;\n        }\n        table.assign(log, std::vector<T>(1 <<\
    \ log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] = vec[i];\n\
    \        }\n        for (int i = 1; i < log; i++) {\n            for (int j =\
    \ 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j] =\n     \
    \               std::min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n        look_up.resize(sz + 1);\n        for (int i\
    \ = 2; i < (int)look_up.size(); i++) {\n            look_up[i] = look_up[i >>\
    \ 1] + 1;\n        }\n    }\n\n    T prod(int l, int r) {\n        int b = look_up[r\
    \ - l];\n        return std::min(table[b][l], table[b][r - (1 << b)]);\n    }\n\
    };\n};  // namespace library\n#line 4 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\
    \n\nusing namespace std;\nusing namespace library;\nint main() {\n    int n, q;\n\
    \    scanf(\"%d%d\", &n, &q);\n    sparse_table<int> rmq(n);\n    rep(i, n) {\n\
    \        int ai;\n        scanf(\"%d\", &ai);\n        rmq.set(i, ai);\n    }\n\
    \    rmq.build();\n    while (q--) {\n        int l, r;\n        scanf(\"%d%d\"\
    , &l, &r);\n        printf(\"%d\\n\", rmq.prod(l, r));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include\"\
    template.hpp\"\n#include\"data-structure/sparse_table.hpp\"\n\nusing namespace\
    \ std;\nusing namespace library;\nint main() {\n    int n, q;\n    scanf(\"%d%d\"\
    , &n, &q);\n    sparse_table<int> rmq(n);\n    rep(i, n) {\n        int ai;\n\
    \        scanf(\"%d\", &ai);\n        rmq.set(i, ai);\n    }\n    rmq.build();\n\
    \    while (q--) {\n        int l, r;\n        scanf(\"%d%d\", &l, &r);\n    \
    \    printf(\"%d\\n\", rmq.prod(l, r));\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 20:41:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
