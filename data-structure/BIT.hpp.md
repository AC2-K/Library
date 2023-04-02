---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-789_BIT.test.cpp
    title: test/yuki/No-789_BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/BIT.md
    document_title: Binary Index Tree
    links: []
  bundledCode: "#line 1 \"data-structure/BIT.hpp\"\n/// @brief Binary Index Tree\n\
    /// @tparam T \u8981\u7D20\u306E\u578B\n/// @tparam SumT \"\u548C\u304C\" \u53CE\
    \u307E\u308B\u3088\u3046\u306A\u578B\n/// @docs docs/data-structure/BIT.md\ntemplate<typename\
    \ T,typename SumT = T>\nclass BIT {\n\tvector<SumT> bit;\n\tint n;\npublic:\n\
    \    BIT(int n) :n(n), bit(n + 1, T()) {}\n\tvoid add(int p, const T& w) {\n\t\
    \tp++;\n\t\tfor (int x = p; x <= n; x += x & -x) {\n\t\t\tbit[x] += w;\n\t\t}\n\
    \t}\n\n\tSumT sum(int p)const {\n\t\tT s = 0;\n\n\t\tfor (int x = p; x > 0; x\
    \ -= x & -x) {\n\t\t\ts += bit[x];\n\t\t}\n\t\treturn s;\n\t}\n\n\tSumT sum(int\
    \ l, int r)const {\n\t\treturn sum(r) - sum(l);\n\t}\n\n    \n    int lower_bound(SumT\
    \ w)const {\n        if (w <= 0)return 0;\n\n        int x = 0;\n        int k\
    \ = 1;\n        while (k < n)k <<= 1;\n        for (; k > 0; k >>= 1) {\n    \
    \        if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n\
    \                x += k;\n            }\n        }\n\n        return x + 1;\n\
    \    }\n}; \n"
  code: "/// @brief Binary Index Tree\n/// @tparam T \u8981\u7D20\u306E\u578B\n///\
    \ @tparam SumT \"\u548C\u304C\" \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\n///\
    \ @docs docs/data-structure/BIT.md\ntemplate<typename T,typename SumT = T>\nclass\
    \ BIT {\n\tvector<SumT> bit;\n\tint n;\npublic:\n    BIT(int n) :n(n), bit(n +\
    \ 1, T()) {}\n\tvoid add(int p, const T& w) {\n\t\tp++;\n\t\tfor (int x = p; x\
    \ <= n; x += x & -x) {\n\t\t\tbit[x] += w;\n\t\t}\n\t}\n\n\tSumT sum(int p)const\
    \ {\n\t\tT s = 0;\n\n\t\tfor (int x = p; x > 0; x -= x & -x) {\n\t\t\ts += bit[x];\n\
    \t\t}\n\t\treturn s;\n\t}\n\n\tSumT sum(int l, int r)const {\n\t\treturn sum(r)\
    \ - sum(l);\n\t}\n\n    \n    int lower_bound(SumT w)const {\n        if (w <=\
    \ 0)return 0;\n\n        int x = 0;\n        int k = 1;\n        while (k < n)k\
    \ <<= 1;\n        for (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x\
    \ + k] < w) {\n                w -= bit[x + k];\n                x += k;\n   \
    \         }\n        }\n\n        return x + 1;\n    }\n}; "
  dependsOn: []
  isVerificationFile: false
  path: data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2023-04-02 12:04:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No-789_BIT.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
documentation_of: data-structure/BIT.hpp
layout: document
redirect_from:
- /library/data-structure/BIT.hpp
- /library/data-structure/BIT.hpp.html
title: Binary Index Tree
---
