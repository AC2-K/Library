---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/bitwise_or_convolution.hpp
    title: Bitwise Or Convolution
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Subset Transform
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
    \ << j)];\n        }\n    }\n}\n\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\n\n\n/**\n * @brief Subset Transform\n*/\n\
    \nnamespace kyopro {\n/**\n * @param n v : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate\
    \ <typename T> void zeta(int n, std::vector<T>& v) {\n    for (int j = 0; j <\
    \ n; ++j) {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if\
    \ (~i >> j & 1) continue;\n            v[i] += v[i & ~(1 << j)];\n        }\n\
    \    }\n}\n\n/**\n * @param n v : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate <typename\
    \ T> void mobius(int n, std::vector<T>& v) {\n    for (int j = 0; j < n; ++j)\
    \ {\n        for (int i = 0; i < (int)v.size(); ++i) {\n            if (~i >>\
    \ j & 1) continue;\n            v[i] -= v[i & ~(1 << j)];\n        }\n    }\n\
    }\n\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/subset_transform.hpp
  requiredBy:
  - src/convolution/bitwise_or_convolution.hpp
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
documentation_of: src/algorithm/subset_transform.hpp
layout: document
redirect_from:
- /library/src/algorithm/subset_transform.hpp
- /library/src/algorithm/subset_transform.hpp.html
title: Subset Transform
---
