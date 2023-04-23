---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/5_B.test.cpp
    title: test/AOJ/DSL/5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 2 \"src/data-structure-2d/cumulative-sum.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/// @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n/// @tparam T\
    \ \u91CD\u307F\u306E\u578B\ntemplate <typename T>\nclass cumulative_sum_2d {\n\
    \    std::vector<std::vector<T>> dat;\n    std::vector<std::vector<T>> s;\n\n\
    public:\n    const int h;\n    const int w;\n\n    cumulative_sum_2d(int h, int\
    \ w)\n        : h(h),\n          w(w),\n          dat(h, std::vector<T>(w, T())),\n\
    \          s(h + 1, std::vector<T>(w + 1, T())) {}\n    inline void build() {\n\
    \        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j)\
    \ {\n                s[i + 1][j + 1] =\n                    s[i][j + 1] + s[i\
    \ + 1][j] - s[i][j] + dat[i][j];\n            }\n        }\n    }\n    inline\
    \ T sum(int i1, int j1, int i2, int j2) {\n        return s[i2][j2] - s[i1][j2]\
    \ - s[i2][j1] + s[i1][j1];\n    }\n\n    inline std::vector<T>& operator[](int\
    \ i) { return dat[i]; }\n};\n\n/// @brief \u4E8C\u6B21\u5143imos\u6CD5\n/// @tparam\
    \ T \u91CD\u307F\u306E\u578B\ntemplate <typename T>\nclass imos_2d {\n    cumulative_sum_2d<T>\
    \ d;\n\npublic:\n    const int h;\n    const int w;\n\n    imos_2d(int h, int\
    \ w) : h(h), w(w), d(h + 1, w + 1) {}\n    inline void add(int i1, int j1, int\
    \ i2, int j2, const T& v) {\n        d[i1][j1] += v, d[i2][j2] += v;\n       \
    \ d[i1][j2] -= v, d[i2][j1] -= v;\n    }\n    inline T at(int i, int j) { return\
    \ d.sum(0, 0, i + 1, j + 1); }\n\n    inline void build() { d.build(); }\n};\n\
    };  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/// @brief 2\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n/// @tparam T \u91CD\u307F\u306E\u578B\ntemplate <typename\
    \ T>\nclass cumulative_sum_2d {\n    std::vector<std::vector<T>> dat;\n    std::vector<std::vector<T>>\
    \ s;\n\npublic:\n    const int h;\n    const int w;\n\n    cumulative_sum_2d(int\
    \ h, int w)\n        : h(h),\n          w(w),\n          dat(h, std::vector<T>(w,\
    \ T())),\n          s(h + 1, std::vector<T>(w + 1, T())) {}\n    inline void build()\
    \ {\n        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w;\
    \ ++j) {\n                s[i + 1][j + 1] =\n                    s[i][j + 1] +\
    \ s[i + 1][j] - s[i][j] + dat[i][j];\n            }\n        }\n    }\n    inline\
    \ T sum(int i1, int j1, int i2, int j2) {\n        return s[i2][j2] - s[i1][j2]\
    \ - s[i2][j1] + s[i1][j1];\n    }\n\n    inline std::vector<T>& operator[](int\
    \ i) { return dat[i]; }\n};\n\n/// @brief \u4E8C\u6B21\u5143imos\u6CD5\n/// @tparam\
    \ T \u91CD\u307F\u306E\u578B\ntemplate <typename T>\nclass imos_2d {\n    cumulative_sum_2d<T>\
    \ d;\n\npublic:\n    const int h;\n    const int w;\n\n    imos_2d(int h, int\
    \ w) : h(h), w(w), d(h + 1, w + 1) {}\n    inline void add(int i1, int j1, int\
    \ i2, int j2, const T& v) {\n        d[i1][j1] += v, d[i2][j2] += v;\n       \
    \ d[i1][j2] -= v, d[i2][j1] -= v;\n    }\n    inline T at(int i, int j) { return\
    \ d.sum(0, 0, i + 1, j + 1); }\n\n    inline void build() { d.build(); }\n};\n\
    };  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure-2d/cumulative-sum.hpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/5_B.test.cpp
documentation_of: src/data-structure-2d/cumulative-sum.hpp
layout: document
redirect_from:
- /library/src/data-structure-2d/cumulative-sum.hpp
- /library/src/data-structure-2d/cumulative-sum.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---