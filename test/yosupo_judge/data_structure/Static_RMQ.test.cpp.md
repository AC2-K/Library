---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/sparse_table.hpp
    title: Sparse Table(RangeMin)
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
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include<iostream>\n\
    #line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n#include\
    \ <vector>\nnamespace kyopro {\n/// @brief Sparse Table(RangeMin)\ntemplate <class\
    \ T>\nclass sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    sparse_table(int n) :\
    \ vec(n) {}\n    sparse_table(const std::vector<T>& vec) : vec(vec) { build();\
    \ }\n    inline void set(int p, const T& v) { vec[p] = v; }\n    void build()\
    \ {\n        int sz = vec.size();\n        int log = 0;\n        while ((1 <<\
    \ log) <= sz) {\n            log++;\n        }\n        table.assign(log, std::vector<T>(1\
    \ << log));\n        for (int i = 0; i < sz; i++) {\n            table[0][i] =\
    \ vec[i];\n        }\n        for (int i = 1; i < log; i++) {\n            for\
    \ (int j = 0; j + (1 << i) <= (1 << log); j++) {\n                table[i][j]\
    \ =\n                    std::min(table[i - 1][j], table[i - 1][j + (1 << (i -\
    \ 1))]);\n            }\n        }\n        look_up.resize(sz + 1);\n        for\
    \ (int i = 2; i < (int)look_up.size(); i++) {\n            look_up[i] = look_up[i\
    \ >> 1] + 1;\n        }\n    }\n\n    inline T prod(int l, int r) {\n        int\
    \ b = look_up[r - l];\n        return std::min(table[b][l], table[b][r - (1 <<\
    \ b)]);\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/sparse_table.md\n\
    #line 4 \"test/yosupo_judge/data_structure/Static_RMQ.test.cpp\"\n\nint main()\
    \ {\n\tint n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tkyopro::sparse_table<int> rmq(n);\n\
    \tfor(int i=0;i<n;i++) {\n\t\tint ai;\n\t\tscanf(\"%d\", &ai);\n\t\trmq.set(i,\
    \ ai);\n\t}\n\trmq.build();\n\twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\"\
    , &l, &r);\n        printf(\"%d\\n\", rmq.prod(l, r));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include<iostream>\n\
    #include\"../../../src/data-structure/sparse_table.hpp\"\n\nint main() {\n\tint\
    \ n, q;\n\tscanf(\"%d%d\", &n, &q);\n\tkyopro::sparse_table<int> rmq(n);\n\tfor(int\
    \ i=0;i<n;i++) {\n\t\tint ai;\n\t\tscanf(\"%d\", &ai);\n\t\trmq.set(i, ai);\n\t\
    }\n\trmq.build();\n\twhile (q--) {\n\t\tint l, r;\n\t\tscanf(\"%d%d\", &l, &r);\n\
    \        printf(\"%d\\n\", rmq.prod(l, r));\n    }\n}"
  dependsOn:
  - src/data-structure/sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_RMQ.test.cpp.html
title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
---
