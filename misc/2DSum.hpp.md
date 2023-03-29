---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/5_B.test.cpp
    title: test/AOJ/DSL/5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/2DSum.hpp\"\ntemplate<typename T>\nclass Sum2D {\n\t\
    vector<vector<T>> dat;\n\tvector<vector<T>> s;\npublic:\n\tconst int h;\n\tconst\
    \ int w;\n\t\n\tSum2D(int h, int w) :h(h), w(w), dat(h, vector<T>(w, T())), s(h\
    \ + 1, vector<T>(w + 1, T())) {}\n\tinline void build() {\n\t\tfor (int i = 0;\
    \ i < h; ++i) {\n\t\t\tfor (int j = 0; j < w; ++j) {\n\t\t\t\ts[i + 1][j + 1]\
    \ = s[i][j + 1] + s[i + 1][j] - s[i][j] + dat[i][j];\n\t\t\t}\n\t\t}\n\t}\n\t\
    inline T sum(int i1, int j1, int i2, int j2) {\n\t\treturn s[i2][j2] - s[i1][j2]\
    \ - s[i2][j1] + s[i1][j1];\n\t}\n\n\tinline vector<T>& operator[](int i) { return\
    \ dat[i]; }\n};\n\n\ntemplate<typename T>\nclass Imos2D {\n\tSum2D<T> d;\npublic:\n\
    \tconst int h;\n\tconst int w;\n\n\tImos2D(int h, int w) :h(h), w(w), d(h + 1,\
    \ w + 1) {}\n\tinline void add(int i1, int j1, int i2, int j2, const T& v) {\n\
    \t\td[i1][j1] += v, d[i2][j2] += v;\n\t\td[i1][j2] -= v, d[i2][j1] -= v;\n\t}\n\
    \tinline T at(int i, int j) { return d.sum(0, 0, i + 1, j + 1); }\n\n\tinline\
    \ void build() { d.build(); }\n};\n"
  code: "template<typename T>\nclass Sum2D {\n\tvector<vector<T>> dat;\n\tvector<vector<T>>\
    \ s;\npublic:\n\tconst int h;\n\tconst int w;\n\t\n\tSum2D(int h, int w) :h(h),\
    \ w(w), dat(h, vector<T>(w, T())), s(h + 1, vector<T>(w + 1, T())) {}\n\tinline\
    \ void build() {\n\t\tfor (int i = 0; i < h; ++i) {\n\t\t\tfor (int j = 0; j <\
    \ w; ++j) {\n\t\t\t\ts[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + dat[i][j];\n\
    \t\t\t}\n\t\t}\n\t}\n\tinline T sum(int i1, int j1, int i2, int j2) {\n\t\treturn\
    \ s[i2][j2] - s[i1][j2] - s[i2][j1] + s[i1][j1];\n\t}\n\n\tinline vector<T>& operator[](int\
    \ i) { return dat[i]; }\n};\n\n\ntemplate<typename T>\nclass Imos2D {\n\tSum2D<T>\
    \ d;\npublic:\n\tconst int h;\n\tconst int w;\n\n\tImos2D(int h, int w) :h(h),\
    \ w(w), d(h + 1, w + 1) {}\n\tinline void add(int i1, int j1, int i2, int j2,\
    \ const T& v) {\n\t\td[i1][j1] += v, d[i2][j2] += v;\n\t\td[i1][j2] -= v, d[i2][j1]\
    \ -= v;\n\t}\n\tinline T at(int i, int j) { return d.sum(0, 0, i + 1, j + 1);\
    \ }\n\n\tinline void build() { d.build(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/2DSum.hpp
  requiredBy:
  - main.cpp
  timestamp: '2023-03-29 20:32:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/5_B.test.cpp
documentation_of: misc/2DSum.hpp
layout: document
redirect_from:
- /library/misc/2DSum.hpp
- /library/misc/2DSum.hpp.html
title: misc/2DSum.hpp
---
