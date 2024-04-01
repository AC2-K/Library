---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/subset_mobius.hpp
    title: "Subset M\xF6bius  transform"
  - icon: ':heavy_check_mark:'
    path: src/algorithm/subset_zeta.hpp
    title: Subset Zeta transform
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
  bundledCode: "#line 2 \"src/algorithm/subset_zeta.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Subset Zeta transform\n * @param n v : 2^[n] \u2192\
    \ T, |v| = 2^n\n */\ntemplate <typename T> void zeta(int n, std::vector<T>& v)\
    \ {\n    for (int j = 0; j < n; ++j) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            if (~i >> j & 1) continue;\n            v[i] += v[i & ~(1\
    \ << j)];\n        }\n    }\n}\n}  // namespace kyopro\n#line 3 \"src/algorithm/subset_mobius.hpp\"\
    \nnamespace kyopro {\n/**\n * @brief Subset M\xF6bius  transform\n * @param n\
    \ v : 2^[n] \u2192 T, |v| = 2^n\n */\ntemplate <typename T> void mobius(int n,\
    \ std::vector<T>& v) {\n    for (int j = 0; j < n; ++j) {\n        for (int i\
    \ = 0; i < (int)v.size(); ++i) {\n            if (~i >> j & 1) continue;\n   \
    \         v[i] -= v[i & ~(1 << j)];\n        }\n    }\n}\n};  // namespace kyopro\n\
    #line 4 \"src/convolution/bitwise_or_convolution.hpp\"\n\nnamespace kyopro {\n\
    \n/**\n * @brief Bitwise Or Convolution\n * @param n a,b : 2^[n] \u2192 T, |a|\
    \ = |b| = 2^n\n * @return convolution\n */\ntemplate <typename T>\nstd::vector<T>\
    \ bitwise_or_convolution(int n, std::vector<T> a, std::vector<T> b) {\n    zeta(n,\
    \ a), zeta(n, b);\n    for (int i = 0; i < (int)a.size(); ++i) a[i] *= b[i];\n\
    \    mobius(n, a);\n    return a;\n}\n};\n"
  code: "#pragma once\n#include \"../algorithm/subset_zeta.hpp\"\n#include \"../algorithm/subset_mobius.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief Bitwise Or Convolution\n * @param n a,b\
    \ : 2^[n] \u2192 T, |a| = |b| = 2^n\n * @return convolution\n */\ntemplate <typename\
    \ T>\nstd::vector<T> bitwise_or_convolution(int n, std::vector<T> a, std::vector<T>\
    \ b) {\n    zeta(n, a), zeta(n, b);\n    for (int i = 0; i < (int)a.size(); ++i)\
    \ a[i] *= b[i];\n    mobius(n, a);\n    return a;\n}\n};"
  dependsOn:
  - src/algorithm/subset_zeta.hpp
  - src/algorithm/subset_mobius.hpp
  isVerificationFile: false
  path: src/convolution/bitwise_or_convolution.hpp
  requiredBy: []
  timestamp: '2024-04-01 11:01:24+09:00'
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
