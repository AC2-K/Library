---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/subset_transform.hpp
    title: Subset Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bitwise Or Convolution
    links: []
  bundledCode: "#line 2 \"src/algorithm/subset_transform.hpp\"\n#include <vector>\n\
    \n\n/**\n * @brief Subset Transform\n*/\n\nnamespace kyopro {\n/**\n * @param\
    \ n v : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate <typename T> void zeta(int n,\
    \ std::vector<T>& v) {\n    for (int j = 0; j < n; ++j) {\n        for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n            if (~i >> j & 1) continue;\n   \
    \         v[i] += v[i & ~(1 << j)];\n        }\n    }\n}\n\n/**\n * @param n v\
    \ : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate <typename T> void mobius(int n, std::vector<T>&\
    \ v) {\n    for (int j = 0; j < n; ++j) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            if (~i >> j & 1) continue;\n            v[i] -= v[i & ~(1\
    \ << j)];\n        }\n    }\n}\n\n};  // namespace kyopro\n#line 3 \"src/convolution/bitwise_or_convolution.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief Bitwise Or Convolution\n */\ntemplate\
    \ <typename T>\nstd::vector<T> bitwise_or_convolution(int n, std::vector<T> a,\
    \ std::vector<T> b) {\n    zeta(n, a), zeta(n, b);\n    for (int i = 0; i < (int)a.size();\
    \ ++i) a[i] *= b[i];\n    mobius(n, a);\n    return a;\n}\n\n};\n"
  code: "#pragma once\n#include \"../algorithm/subset_transform.hpp\"\n\nnamespace\
    \ kyopro {\n\n/**\n * @brief Bitwise Or Convolution\n */\ntemplate <typename T>\n\
    std::vector<T> bitwise_or_convolution(int n, std::vector<T> a, std::vector<T>\
    \ b) {\n    zeta(n, a), zeta(n, b);\n    for (int i = 0; i < (int)a.size(); ++i)\
    \ a[i] *= b[i];\n    mobius(n, a);\n    return a;\n}\n\n};"
  dependsOn:
  - src/algorithm/subset_transform.hpp
  isVerificationFile: false
  path: src/convolution/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
documentation_of: src/convolution/bitwise_or_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/bitwise_or_convolution.hpp
- /library/src/convolution/bitwise_or_convolution.hpp.html
title: Bitwise Or Convolution
---
