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
  bundledCode: "#line 2 \"misc/2DSum.hpp\"\n#include <vector>\nnamespace library {\n\
    /// @brief 2\u6B21\u5143\u7D2F\u7A4D\u548C\n/// @tparam T \u91CD\u307F\u306E\u578B\
    \ntemplate<typename T>\nclass Sum2D {\n\tstd::vector<std::vector<T>> dat;\n\t\
    std::vector<std::vector<T>> s;\npublic:\n\tconst int h;\n\tconst int w;\n\t\n\t\
    explicit Sum2D(int h, int w) :h(h), w(w), dat(h, std::vector<T>(w, T())), s(h\
    \ + 1, std::vector<T>(w + 1, T())) {}\n\tinline void build() {\n\t\tfor (int i\
    \ = 0; i < h; ++i) {\n\t\t\tfor (int j = 0; j < w; ++j) {\n\t\t\t\ts[i + 1][j\
    \ + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + dat[i][j];\n\t\t\t}\n\t\t}\n\t\
    }\n\tinline T sum(int i1, int j1, int i2, int j2) {\n\t\treturn s[i2][j2] - s[i1][j2]\
    \ - s[i2][j1] + s[i1][j1];\n\t}\n\n\tinline std::vector<T>& operator[](int i)\
    \ { return dat[i]; }\n};\n\n/// @brief \u4E8C\u6B21\u5143imos\u6CD5\n/// @tparam\
    \ T \u52A0\u7B97\u3059\u308B\u91CD\u307F\u306E\u578B\ntemplate<typename T>\nclass\
    \ Imos2D {\n\tSum2D<T> d;\npublic:\n\tconst int h;\n\tconst int w;\n\n\texplicit\
    \ Imos2D(int h, int w) :h(h), w(w), d(h + 1, w + 1) {}\n\tinline void add(int\
    \ i1, int j1, int i2, int j2, const T& v) {\n\t\td[i1][j1] += v, d[i2][j2] +=\
    \ v;\n\t\td[i1][j2] -= v, d[i2][j1] -= v;\n\t}\n\tinline T at(int i, int j) {\
    \ return d.sum(0, 0, i + 1, j + 1); }\n\n\tinline void build() { d.build(); }\n\
    };\n};  // namespace library\n"
  code: "#pragma once\n#include <vector>\nnamespace library {\n/// @brief 2\u6B21\u5143\
    \u7D2F\u7A4D\u548C\n/// @tparam T \u91CD\u307F\u306E\u578B\ntemplate<typename\
    \ T>\nclass Sum2D {\n\tstd::vector<std::vector<T>> dat;\n\tstd::vector<std::vector<T>>\
    \ s;\npublic:\n\tconst int h;\n\tconst int w;\n\t\n\texplicit Sum2D(int h, int\
    \ w) :h(h), w(w), dat(h, std::vector<T>(w, T())), s(h + 1, std::vector<T>(w +\
    \ 1, T())) {}\n\tinline void build() {\n\t\tfor (int i = 0; i < h; ++i) {\n\t\t\
    \tfor (int j = 0; j < w; ++j) {\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i +\
    \ 1][j] - s[i][j] + dat[i][j];\n\t\t\t}\n\t\t}\n\t}\n\tinline T sum(int i1, int\
    \ j1, int i2, int j2) {\n\t\treturn s[i2][j2] - s[i1][j2] - s[i2][j1] + s[i1][j1];\n\
    \t}\n\n\tinline std::vector<T>& operator[](int i) { return dat[i]; }\n};\n\n///\
    \ @brief \u4E8C\u6B21\u5143imos\u6CD5\n/// @tparam T \u52A0\u7B97\u3059\u308B\u91CD\
    \u307F\u306E\u578B\ntemplate<typename T>\nclass Imos2D {\n\tSum2D<T> d;\npublic:\n\
    \tconst int h;\n\tconst int w;\n\n\texplicit Imos2D(int h, int w) :h(h), w(w),\
    \ d(h + 1, w + 1) {}\n\tinline void add(int i1, int j1, int i2, int j2, const\
    \ T& v) {\n\t\td[i1][j1] += v, d[i2][j2] += v;\n\t\td[i1][j2] -= v, d[i2][j1]\
    \ -= v;\n\t}\n\tinline T at(int i, int j) { return d.sum(0, 0, i + 1, j + 1);\
    \ }\n\n\tinline void build() { d.build(); }\n};\n};  // namespace library"
  dependsOn: []
  isVerificationFile: false
  path: misc/2DSum.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/5_B.test.cpp
documentation_of: misc/2DSum.hpp
layout: document
redirect_from:
- /library/misc/2DSum.hpp
- /library/misc/2DSum.hpp.html
title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
