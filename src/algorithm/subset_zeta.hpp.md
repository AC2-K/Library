---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/or_plus_convolution.hpp
    title: or plus convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: subset zeta transform
    links: []
  bundledCode: "#line 2 \"src/algorithm/subset_zeta.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief subset zeta transform\n * @param n v : 2^[n] \u2192\
    \ T, |v| = 2^n\n */\ntemplate <typename T> void zeta(int n, std::vector<T>& v)\
    \ {\n    for (int j = 0; j < n; ++j) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            if (~i >> j & 1) continue;\n            v[i] += v[i & ~(1\
    \ << j)];\n        }\n    }\n}\n}  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/**\n * @brief subset\
    \ zeta transform\n * @param n v : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate <typename\
    \ T> void zeta(int n, std::vector<T>& v) {\n    for (int j = 0; j < n; ++j) {\n\
    \        for (int i = 0; i < (int)v.size(); ++i) {\n            if (~i >> j &\
    \ 1) continue;\n            v[i] += v[i & ~(1 << j)];\n        }\n    }\n}\n}\
    \  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/subset_zeta.hpp
  requiredBy:
  - src/convolution/or_plus_convolution.hpp
  timestamp: '2024-03-22 14:26:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
documentation_of: src/algorithm/subset_zeta.hpp
layout: document
redirect_from:
- /library/src/algorithm/subset_zeta.hpp
- /library/src/algorithm/subset_zeta.hpp.html
title: subset zeta transform
---
