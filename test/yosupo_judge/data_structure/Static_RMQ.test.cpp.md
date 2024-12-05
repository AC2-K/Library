---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/sparse_table.hpp
    title: Sparse Table
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
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include <iostream>\n\
    #line 2 \"src/data-structure/sparse_table.hpp\"\n#include <cassert>\n#include\
    \ <numeric>\n#include <vector>\n\nnamespace kyopro {\n\ntemplate <class T, auto\
    \ op> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> lg;\n\npublic:\n    constexpr sparse_table(int\
    \ n) : vec(n) {}\n    constexpr sparse_table(const std::vector<T>& vec) : vec(vec)\
    \ { build(); }\n\n    void set(int p, const T& v) { vec[p] = v; }\n    void build()\
    \ {\n        int sz = vec.size();\n        int log = 0;\n        while ((1 <<\
    \ log) <= sz) {\n            log++;\n        }\n        table.assign(log, std::vector<T>(1\
    \ << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] =\
    \ vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ =\n                    op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n        lg.resize(sz + 1);\n        for (int i = 2;\
    \ i < (int)lg.size(); i++) {\n            lg[i] = lg[i >> 1] + 1;\n        }\n\
    \    }\n\n    T fold(int l, int r) const {\n        assert(l <= r);\n        int\
    \ b = lg[r - l];\n        return op(table[b][l], table[b][r - (1 << b)]);\n  \
    \  }\n};\n};  // namespace kyopro\n\n/**\n * @brief Sparse Table\n */\n#line 4\
    \ \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\ninline int op(int\
    \ x, int y) { return std::min(x, y); }\nint main() {\n    int n, q;\n    scanf(\"\
    %d%d\", &n, &q);\n    kyopro::sparse_table<int, op> rmq(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        int ai;\n        scanf(\"%d\", &ai);\n        rmq.set(i,\
    \ ai);\n    }\n    rmq.build();\n    while (q--) {\n        int l, r;\n      \
    \  scanf(\"%d%d\", &l, &r);\n        printf(\"%d\\n\", rmq.fold(l, r));\n    }\n\
    }\n"
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
  timestamp: '2024-12-05 21:26:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
