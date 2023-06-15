---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/divisor-multiple-transform.hpp\"\n#include <string.h>\n\
    #include <vector>\nnamespace kyopro {\n\ntemplate <typename T> inline void fast_mobius(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    bool is_prime[n + 1];\n    {\n        memset(is_prime,\
    \ 1, sizeof(is_prime));\n        is_prime[0] = is_prime[1] = false;\n        for\
    \ (int p = 2; p <= n; ++p) {\n            if (!is_prime[p]) continue;\n      \
    \      for (int q = p * 2; q <= n; q += p) {\n                is_prime[q] = false;\n\
    \            }\n        }\n    }\n\n    for (int p = 2; p < n; ++p) {\n      \
    \  if (!is_prime[p]) continue;\n        for (int i = 1 / p; p * i < n; ++i) {\n\
    \            f[i] -= f[p * i];\n        }\n    }\n    return;\n}\ntemplate <typename\
    \ T> inline void fast_zeta(std::vector<T>& f) {\n    int n = f.size();\n    bool\
    \ is_prime[n + 1];\n    {\n        memset(is_prime, 1, sizeof(is_prime));\n  \
    \      is_prime[0] = is_prime[1] = false;\n        for (int p = 2; p <= n; ++p)\
    \ {\n            if (!is_prime[p]) continue;\n            for (int q = p * 2;\
    \ q <= n; q += p) {\n                is_prime[q] = false;\n            }\n   \
    \     }\n    }\n\n    for (int p = 2; p < n; ++p) {\n        if (!is_prime[p])\
    \ continue;\n        for (int i = (n - 1) / p; i >= 1; --i) {\n            f[i]\
    \ += f[p * i];\n        }\n    }\n    return;\n}\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <string.h>\n#include <vector>\nnamespace kyopro {\n\
    \ntemplate <typename T> inline void fast_mobius(std::vector<T>& f) {\n    int\
    \ n = f.size();\n    bool is_prime[n + 1];\n    {\n        memset(is_prime, 1,\
    \ sizeof(is_prime));\n        is_prime[0] = is_prime[1] = false;\n        for\
    \ (int p = 2; p <= n; ++p) {\n            if (!is_prime[p]) continue;\n      \
    \      for (int q = p * 2; q <= n; q += p) {\n                is_prime[q] = false;\n\
    \            }\n        }\n    }\n\n    for (int p = 2; p < n; ++p) {\n      \
    \  if (!is_prime[p]) continue;\n        for (int i = 1 / p; p * i < n; ++i) {\n\
    \            f[i] -= f[p * i];\n        }\n    }\n    return;\n}\ntemplate <typename\
    \ T> inline void fast_zeta(std::vector<T>& f) {\n    int n = f.size();\n    bool\
    \ is_prime[n + 1];\n    {\n        memset(is_prime, 1, sizeof(is_prime));\n  \
    \      is_prime[0] = is_prime[1] = false;\n        for (int p = 2; p <= n; ++p)\
    \ {\n            if (!is_prime[p]) continue;\n            for (int q = p * 2;\
    \ q <= n; q += p) {\n                is_prime[q] = false;\n            }\n   \
    \     }\n    }\n\n    for (int p = 2; p < n; ++p) {\n        if (!is_prime[p])\
    \ continue;\n        for (int i = (n - 1) / p; i >= 1; --i) {\n            f[i]\
    \ += f[p * i];\n        }\n    }\n    return;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor-multiple-transform.hpp
  requiredBy: []
  timestamp: '2023-06-15 16:07:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/src/math/divisor-multiple-transform.hpp
- /library/src/math/divisor-multiple-transform.hpp.html
title: src/math/divisor-multiple-transform.hpp
---
