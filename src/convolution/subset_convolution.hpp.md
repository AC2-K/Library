---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/convolution/subset_convolution.hpp\"\n#include <vector>\n\
    \nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename T> void add(std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    if (a.size() < b.size()) a.resize(b.size());\n\
    \    for (int i = 0; i < (int)b.size(); ++i) a[i] += b[i];\n}\ntemplate <typename\
    \ T> void sub(std::vector<T>& a, const std::vector<T>& b) {\n    if (a.size()\
    \ < b.size()) a.resize(b.size());\n    for (int i = 0; i < (int)b.size(); ++i)\
    \ a[i] -= b[i];\n}\n\ntemplate <typename T> void ranked_zeta(int n, std::vector<std::vector<T>>&\
    \ a) {\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size();\
    \ ++j) {\n            if (j >> i & 1) add(a[j], a[j & ~(1 << i)]);\n        }\n\
    \    }\n}\ntemplate <typename T>\nvoid ranked_mobius(int n, std::vector<std::vector<T>>&\
    \ a) {\n    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size();\
    \ ++j) {\n            if (j >> i & 1) sub(a[j], a[j & ~(1 << i)]);\n        }\n\
    \    }\n}\n};  // namespace internal\n\ntemplate <typename T>\nstd::vector<T>\
    \ subset_convolution(int n, std::vector<T> a, std::vector<T> b) {\n    std::vector<std::vector<T>>\
    \ ranked_a(a.size()), ranked_b(b.size());\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        ranked_a[i].resize(__builtin_popcount(i) + 1);\n        ranked_b[i].resize(__builtin_popcount(i)\
    \ + 1);\n\n        ranked_a[i][__builtin_popcount(i)] = a[i];\n        ranked_b[i][__builtin_popcount(i)]\
    \ = b[i];\n    }\n\n    internal::ranked_zeta(n, ranked_a), internal::ranked_zeta(n,\
    \ ranked_b);\n    for (int i = 0; i < (1 << n); ++i) {\n        std::vector<T>\
    \ c(ranked_a[i].size() + ranked_b[i].size());\n        for (int j = 0; j < (int)ranked_b[i].size();\
    \ ++j) {\n            for (int k = 0; k < (int)ranked_b[i].size(); ++k) {\n  \
    \              c[j + k] += ranked_a[i][j] * ranked_b[i][k];\n            }\n \
    \       }\n        swap(ranked_a[i], c);\n    }\n\n    internal::ranked_mobius(n,\
    \ ranked_a);\n    std::vector<T> answer(a.size());\n    for (int i = 0; i < (int)a.size();\
    \ ++i) {\n        answer[i] = ranked_a[i][__builtin_popcount(i)];\n    }\n   \
    \ return answer;\n}\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\n\nnamespace kyopro {\nnamespace internal\
    \ {\n\ntemplate <typename T> void add(std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    if (a.size() < b.size()) a.resize(b.size());\n    for (int i = 0;\
    \ i < (int)b.size(); ++i) a[i] += b[i];\n}\ntemplate <typename T> void sub(std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    if (a.size() < b.size()) a.resize(b.size());\n\
    \    for (int i = 0; i < (int)b.size(); ++i) a[i] -= b[i];\n}\n\ntemplate <typename\
    \ T> void ranked_zeta(int n, std::vector<std::vector<T>>& a) {\n    for (int i\
    \ = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size(); ++j) {\n    \
    \        if (j >> i & 1) add(a[j], a[j & ~(1 << i)]);\n        }\n    }\n}\ntemplate\
    \ <typename T>\nvoid ranked_mobius(int n, std::vector<std::vector<T>>& a) {\n\
    \    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < (int)a.size();\
    \ ++j) {\n            if (j >> i & 1) sub(a[j], a[j & ~(1 << i)]);\n        }\n\
    \    }\n}\n};  // namespace internal\n\ntemplate <typename T>\nstd::vector<T>\
    \ subset_convolution(int n, std::vector<T> a, std::vector<T> b) {\n    std::vector<std::vector<T>>\
    \ ranked_a(a.size()), ranked_b(b.size());\n    for (int i = 0; i < (1 << n); ++i)\
    \ {\n        ranked_a[i].resize(__builtin_popcount(i) + 1);\n        ranked_b[i].resize(__builtin_popcount(i)\
    \ + 1);\n\n        ranked_a[i][__builtin_popcount(i)] = a[i];\n        ranked_b[i][__builtin_popcount(i)]\
    \ = b[i];\n    }\n\n    internal::ranked_zeta(n, ranked_a), internal::ranked_zeta(n,\
    \ ranked_b);\n    for (int i = 0; i < (1 << n); ++i) {\n        std::vector<T>\
    \ c(ranked_a[i].size() + ranked_b[i].size());\n        for (int j = 0; j < (int)ranked_b[i].size();\
    \ ++j) {\n            for (int k = 0; k < (int)ranked_b[i].size(); ++k) {\n  \
    \              c[j + k] += ranked_a[i][j] * ranked_b[i][k];\n            }\n \
    \       }\n        swap(ranked_a[i], c);\n    }\n\n    internal::ranked_mobius(n,\
    \ ranked_a);\n    std::vector<T> answer(a.size());\n    for (int i = 0; i < (int)a.size();\
    \ ++i) {\n        answer[i] = ranked_a[i][__builtin_popcount(i)];\n    }\n   \
    \ return answer;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/subset_convolution.hpp
  requiredBy: []
  timestamp: '2024-04-01 10:43:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Subset_Convolution.test.cpp
documentation_of: src/convolution/subset_convolution.hpp
layout: document
redirect_from:
- /library/src/convolution/subset_convolution.hpp
- /library/src/convolution/subset_convolution.hpp.html
title: src/convolution/subset_convolution.hpp
---
