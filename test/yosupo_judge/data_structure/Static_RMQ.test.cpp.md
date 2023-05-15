---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/sparse_table.hpp
    title: SparseTable
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
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief SparseTable\n */\ntemplate <class\
    \ T, auto op> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    constexpr explicit sparse_table(int\
    \ n) : vec(n) {}\n    constexpr explicit sparse_table(const std::vector<T>& vec)\
    \ : vec(vec) {\n        build();\n    }\n    void set(int p, const T& v) { vec[p]\
    \ = v; }\n    void build() {\n        int sz = vec.size();\n        int log =\
    \ 0;\n        while ((1 << log) <= sz) {\n            log++;\n        }\n    \
    \    table.assign(log, std::vector<T>(1 << log));\n        for (int i = 0; i <\
    \ sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << log);\
    \ j++) {\n                table[i][j] =\n                    op(table[i - 1][j],\
    \ table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < (int)look_up.size(); i++) {\n           \
    \ look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T fold(int l, int\
    \ r) const {\n        int b = look_up[r - l];\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/sparse_table.md\n */\n#line 4 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\
    \ninline int op(int x, int y) { return std::min(x, y); }\nint main() {\n    int\
    \ n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::sparse_table<int, op> rmq(n);\n\
    \    for (int i = 0; i < n; i++) {\n        int ai;\n        scanf(\"%d\", &ai);\n\
    \        rmq.set(i, ai);\n    }\n    rmq.build();\n    while (q--) {\n       \
    \ int l, r;\n        scanf(\"%d%d\", &l, &r);\n        printf(\"%d\\n\", rmq.fold(l,\
    \ r));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #include \"../../../src/data-structure/sparse_table.hpp\"\ninline int op(int x,\
    \ int y) { return std::min(x, y); }\nint main() {\n    int n, q;\n    scanf(\"\
    %d%d\", &n, &q);\n    kyopro::sparse_table<int, op> rmq(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        int ai;\n        scanf(\"%d\", &ai);\n        rmq.set(i,\
    \ ai);\n    }\n    rmq.build();\n    while (q--) {\n        int l, r;\n      \
    \  scanf(\"%d%d\", &l, &r);\n        printf(\"%d\\n\", rmq.fold(l, r));\n    }\n\
    }"
  dependsOn:
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
