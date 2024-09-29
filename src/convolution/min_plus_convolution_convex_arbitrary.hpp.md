---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: (min, +) Convolution (Convex, Arbitrary)
    links: []
  bundledCode: "#line 2 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n#include <limits>\n#line 2 \"src/algorithm/monotone_minima.hpp\"\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\n\n/// @note f must be monotone\n/// @returns\
    \ vector of (idx, minimum)\ntemplate <typename T, typename F>\nstd::vector<std::pair<std::size_t,\
    \ T>> monotone_minima(std::size_t h,\n                                       \
    \                std::size_t w,\n                                            \
    \           const F& f) {\n    using usize = std::size_t;\n    std::vector<std::pair<usize,\
    \ T>> res(h);\n\n    const auto calc = [&](const auto& calc, usize top, usize\
    \ bottom, usize l,\n                          usize r) -> void {\n        if (top\
    \ >= bottom) return;\n\n        usize mid = (top + bottom) / 2;\n\n        T mn\
    \ = f(mid, l);\n        usize idx = l;\n        for (usize i = l + 1; i < r; ++i)\
    \ {\n            T val = f(mid, i);\n            if (mn > val) {\n           \
    \     mn = val;\n                idx = i;\n            }\n        }\n\n      \
    \  res[mid] = std::pair(idx, mn);\n        calc(calc, top, mid, l, idx + 1);\n\
    \        calc(calc, mid + 1, bottom, idx, r);\n    };\n    calc(calc, 0, h, 0,\
    \ w);\n\n    return res;\n}\n};  // namespace kyopro\n\n/**\n * @brief Monotone\
    \ Minima\n*/\n#line 4 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief (min, +) Convolution (Convex, Arbitrary)\n\
    \ * @attention a must be convex\n*/\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a,\n                                                     const\
    \ std::vector<T>& b) {\n    const int n = a.size();\n    const int m = b.size();\n\
    \    \n    const auto f = [&](int i, int j) {\n        if (i - j < 0 || i - j\
    \ >= n) {\n            return std::numeric_limits<T>::max() / 2 + b[j];\n    \
    \    }\n        return a[i - j] + b[j];\n    };\n\n    std::vector res = monotone_minima<T>(n\
    \ + m - 1, m, f);\n    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < (int)c.size();\
    \ ++i) c[i] = res[i].second;\n    return c;\n}\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <limits>\n#include \"../../src/algorithm/monotone_minima.hpp\"\
    \nnamespace kyopro {\n\n/**\n * @brief (min, +) Convolution (Convex, Arbitrary)\n\
    \ * @attention a must be convex\n*/\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a,\n                                                     const\
    \ std::vector<T>& b) {\n    const int n = a.size();\n    const int m = b.size();\n\
    \    \n    const auto f = [&](int i, int j) {\n        if (i - j < 0 || i - j\
    \ >= n) {\n            return std::numeric_limits<T>::max() / 2 + b[j];\n    \
    \    }\n        return a[i - j] + b[j];\n    };\n\n    std::vector res = monotone_minima<T>(n\
    \ + m - 1, m, f);\n    std::vector<T> c(n + m - 1);\n    for (int i = 0; i < (int)c.size();\
    \ ++i) c[i] = res[i].second;\n    return c;\n}\n};  // namespace kyopro"
  dependsOn:
  - src/algorithm/monotone_minima.hpp
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  requiredBy: []
  timestamp: '2024-09-29 11:09:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
documentation_of: src/convolution/min_plus_convolution_convex_arbitrary.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_arbitrary.hpp
- /library/src/convolution/min_plus_convolution_convex_arbitrary.hpp.html
title: (min, +) Convolution (Convex, Arbitrary)
---
