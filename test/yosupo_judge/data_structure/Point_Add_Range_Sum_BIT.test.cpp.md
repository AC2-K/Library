---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Binary Index Tree\n */\ntemplate <typename T, typename\
    \ SumT = T>\nclass BIT {\n    std::vector<SumT> bit;\n    int n;\n\npublic:\n\
    \    explicit BIT() {}\n    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n \
    \   void add(int p, T w) {\n        p++;\n        for (int x = p; x <= n; x +=\
    \ x & -x) {\n            bit[x] += w;\n        }\n    }\n\n    SumT sum(int p)\
    \ const {\n        T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x) {\n\
    \            s += bit[x];\n        }\n        return s;\n    }\n\n    SumT sum(int\
    \ l, int r) const { return sum(r) - sum(l); }\n\n    int lower_bound(SumT w) const\
    \ {\n        if (w <= 0) return 0;\n\n        int x = 0;\n        int k = 1;\n\
    \        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n          \
    \  if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n   \
    \             x += k;\n            }\n        }\n\n        return x + 1;\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n#line 4 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp\"\
    \nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::BIT<long\
    \ long, long long> seg(n);\n    for (int i = 0; i < n; i++) {\n        int a;\n\
    \        scanf(\"%d\", &a);\n        seg.add(i, a);\n    }\n\n    while (q--)\
    \ {\n        int t;\n        scanf(\"%d\", &t);\n        if (t == 0) {\n     \
    \       int p, x;\n            scanf(\"%d%d\", &p, &x);\n            seg.add(p,\
    \ x);\n        } else {\n            int l, r;\n            scanf(\"%d%d\", &l,\
    \ &r);\n            printf(\"%lld\\n\", seg.sum(l, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../../../src/data-structure/BIT.hpp\"\nint main()\
    \ {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::BIT<long long, long\
    \ long> seg(n);\n    for (int i = 0; i < n; i++) {\n        int a;\n        scanf(\"\
    %d\", &a);\n        seg.add(i, a);\n    }\n\n    while (q--) {\n        int t;\n\
    \        scanf(\"%d\", &t);\n        if (t == 0) {\n            int p, x;\n  \
    \          scanf(\"%d%d\", &p, &x);\n            seg.add(p, x);\n        } else\
    \ {\n            int l, r;\n            scanf(\"%d%d\", &l, &r);\n           \
    \ printf(\"%lld\\n\", seg.sum(l, r));\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
---
