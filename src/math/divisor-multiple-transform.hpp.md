---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/divisor-multiple-transform.md
    document_title: "Fast M\xF6bius\u30FBZeta Transform"
    links: []
  bundledCode: "#line 2 \"src/math/divisor-multiple-transform.hpp\"\n#include <string.h>\n\
    #include <vector>\nnamespace kyopro {\n\ntemplate <typename T> void fast_mobius(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    bool is_prime[n + 1];\n    {\n        memset(is_prime,\
    \ 1, sizeof(is_prime));\n        is_prime[0] = is_prime[1] = false;\n        for\
    \ (int p = 2; p <= n; ++p) {\n            if (!is_prime[p]) continue;\n      \
    \      for (int q = p * 2; q <= n; q += p) {\n                is_prime[q] = false;\n\
    \            }\n        }\n    }\n\n    for (int p = 2; p < n; ++p) {\n      \
    \  if (!is_prime[p]) continue;\n        for (int i = 1 / p; p * i < n; ++i) {\n\
    \            f[i] -= f[p * i];\n        }\n    }\n    return;\n}\ntemplate <typename\
    \ T> void fast_zeta(std::vector<T>& f) {\n    int n = f.size();\n    bool is_prime[n\
    \ + 1];\n    {\n        memset(is_prime, 1, sizeof(is_prime));\n        is_prime[0]\
    \ = is_prime[1] = false;\n        for (int p = 2; p <= n; ++p) {\n           \
    \ if (!is_prime[p]) continue;\n            for (int q = p * 2; q <= n; q += p)\
    \ {\n                is_prime[q] = false;\n            }\n        }\n    }\n\n\
    \    for (int p = 2; p < n; ++p) {\n        if (!is_prime[p]) continue;\n    \
    \    for (int i = (n - 1) / p; i >= 1; --i) {\n            f[i] += f[p * i];\n\
    \        }\n    }\n    return;\n}\n};  // namespace kyopro\n\n/**\n * @brief Fast\
    \ M\xF6bius\u30FBZeta Transform\n * @docs docs/math/divisor-multiple-transform.md\n\
    */\n"
  code: "#pragma once\n#include <string.h>\n#include <vector>\nnamespace kyopro {\n\
    \ntemplate <typename T> void fast_mobius(std::vector<T>& f) {\n    int n = f.size();\n\
    \    bool is_prime[n + 1];\n    {\n        memset(is_prime, 1, sizeof(is_prime));\n\
    \        is_prime[0] = is_prime[1] = false;\n        for (int p = 2; p <= n; ++p)\
    \ {\n            if (!is_prime[p]) continue;\n            for (int q = p * 2;\
    \ q <= n; q += p) {\n                is_prime[q] = false;\n            }\n   \
    \     }\n    }\n\n    for (int p = 2; p < n; ++p) {\n        if (!is_prime[p])\
    \ continue;\n        for (int i = 1 / p; p * i < n; ++i) {\n            f[i] -=\
    \ f[p * i];\n        }\n    }\n    return;\n}\ntemplate <typename T> void fast_zeta(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    bool is_prime[n + 1];\n    {\n        memset(is_prime,\
    \ 1, sizeof(is_prime));\n        is_prime[0] = is_prime[1] = false;\n        for\
    \ (int p = 2; p <= n; ++p) {\n            if (!is_prime[p]) continue;\n      \
    \      for (int q = p * 2; q <= n; q += p) {\n                is_prime[q] = false;\n\
    \            }\n        }\n    }\n\n    for (int p = 2; p < n; ++p) {\n      \
    \  if (!is_prime[p]) continue;\n        for (int i = (n - 1) / p; i >= 1; --i)\
    \ {\n            f[i] += f[p * i];\n        }\n    }\n    return;\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Fast M\xF6bius\u30FBZeta Transform\n * @docs docs/math/divisor-multiple-transform.md\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor-multiple-transform.hpp
  requiredBy: []
  timestamp: '2023-10-22 17:06:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/src/math/divisor-multiple-transform.hpp
- /library/src/math/divisor-multiple-transform.hpp.html
title: "Fast M\xF6bius\u30FBZeta Transform"
---
## 概要

整除関係における高速ゼータ変換, 高速メビウス変換を実装したものです.

## fast_zeta

```cpp
void fast_zeta(vector<T>& f)
```

長さ $n$ の数列 $f$ に対し, 以下を満たす長さ $n$ の数列 $F$を求め, $f$ を $F$ で置き換えます.

$$F[n]=\sum_{\mathbb{d} \mid n}{f[d]}$$

### 計算量

- $O(n\log\log n)$

## fast_mobius

```cpp
void fast_zeta(vector<T>& F)
```

上とは逆に, $F$ が与えられたとき条件を満たす $f$ を求めます. そして、$F$ を $f$ で置き換えます.

### 計算量

- $O(n\log\log n)$
