---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
    title: Min Plus Convolution (Convex, Arbitrary)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Monotone Minima
    links: []
  bundledCode: "#line 2 \"src/algorithm/monotone_minima.hpp\"\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\n\n/// @note f must be monotone\ntemplate\
    \ <typename T, typename F>\nstd::vector<std::pair<std::size_t, T>> MonotoneMinima(std::size_t\
    \ h,\n                                                       std::size_t w,\n\
    \                                                       const F& f) {\n    using\
    \ usize = std::size_t;\n    std::vector<std::pair<usize, T>> res(h);\n\n    const\
    \ auto calc = [&](const auto& calc, usize top, usize bottom, usize l,\n      \
    \                    usize r) -> void {\n        if (top >= bottom) return;\n\n\
    \        usize mid = (top + bottom) / 2;\n\n        T mn = f(mid, l);\n      \
    \  usize idx = l;\n        for (usize i = l + 1; i < r; ++i) {\n            T\
    \ val = f(mid, i);\n            if (mn > val) {\n                mn = val;\n \
    \               idx = i;\n            }\n        }\n\n        res[mid] = std::pair(idx,\
    \ mn);\n        calc(calc, top, mid, l, idx + 1);\n        calc(calc, mid + 1,\
    \ bottom, idx, r);\n    };\n    calc(calc, 0, h, 0, w);\n\n    return res;\n}\n\
    };  // namespace kyopro\n\n/**\n * @brief Monotone Minima\n*/\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    \n/// @note f must be monotone\ntemplate <typename T, typename F>\nstd::vector<std::pair<std::size_t,\
    \ T>> MonotoneMinima(std::size_t h,\n                                        \
    \               std::size_t w,\n                                             \
    \          const F& f) {\n    using usize = std::size_t;\n    std::vector<std::pair<usize,\
    \ T>> res(h);\n\n    const auto calc = [&](const auto& calc, usize top, usize\
    \ bottom, usize l,\n                          usize r) -> void {\n        if (top\
    \ >= bottom) return;\n\n        usize mid = (top + bottom) / 2;\n\n        T mn\
    \ = f(mid, l);\n        usize idx = l;\n        for (usize i = l + 1; i < r; ++i)\
    \ {\n            T val = f(mid, i);\n            if (mn > val) {\n           \
    \     mn = val;\n                idx = i;\n            }\n        }\n\n      \
    \  res[mid] = std::pair(idx, mn);\n        calc(calc, top, mid, l, idx + 1);\n\
    \        calc(calc, mid + 1, bottom, idx, r);\n    };\n    calc(calc, 0, h, 0,\
    \ w);\n\n    return res;\n}\n};  // namespace kyopro\n\n/**\n * @brief Monotone\
    \ Minima\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/monotone_minima.hpp
  requiredBy:
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  timestamp: '2024-06-23 18:35:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
documentation_of: src/algorithm/monotone_minima.hpp
layout: document
redirect_from:
- /library/src/algorithm/monotone_minima.hpp
- /library/src/algorithm/monotone_minima.hpp.html
title: Monotone Minima
---
