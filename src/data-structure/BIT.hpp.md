---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/BIT.md
    document_title: Binary Index Tree
    links: []
  bundledCode: "#line 1 \"src/data-structure/BIT.hpp\"\n/// @brief Binary Index Tree\n\
    /// @tparam Type \u8981\u7D20\u306E\u578B\n/// @tparam SumType \"\u548C\u304C\"\
    \ \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\n/// @docs docs/data-structure/BIT.md\n\
    template <typename Type, typename SumType = Type>\nclass BIT {\n    int _n;\n\
    \    vector<SumType> _dat;\npublic:\n    explicit BIT(int _n) : _n(_n), _dat(_n,\
    \ SumType()) {}\n\n    inline void add(int p, Type v) {\n        p++;\n      \
    \  for (; p <= _n; p += p & (-p)) {\n            _dat[p - 1] += SumType(v);\n\
    \        }\n    }\n\n    inline SumType sum(int p) {\n        SumType res = 0;\n\
    \        for (; p > 0; p -= p & -p) {\n            res += _dat[p - 1];\n     \
    \   }\n        return res;\n    }\n\n    inline SumType sum(int l, int r) { return\
    \ sum(r) - sum(l); }\n};\n"
  code: "/// @brief Binary Index Tree\n/// @tparam Type \u8981\u7D20\u306E\u578B\n\
    /// @tparam SumType \"\u548C\u304C\" \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\
    \n/// @docs docs/data-structure/BIT.md\ntemplate <typename Type, typename SumType\
    \ = Type>\nclass BIT {\n    int _n;\n    vector<SumType> _dat;\npublic:\n    explicit\
    \ BIT(int _n) : _n(_n), _dat(_n, SumType()) {}\n\n    inline void add(int p, Type\
    \ v) {\n        p++;\n        for (; p <= _n; p += p & (-p)) {\n            _dat[p\
    \ - 1] += SumType(v);\n        }\n    }\n\n    inline SumType sum(int p) {\n \
    \       SumType res = 0;\n        for (; p > 0; p -= p & -p) {\n            res\
    \ += _dat[p - 1];\n        }\n        return res;\n    }\n\n    inline SumType\
    \ sum(int l, int r) { return sum(r) - sum(l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/BIT.hpp
- /library/src/data-structure/BIT.hpp.html
title: Binary Index Tree
---
