---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':x:'
    path: test/yuki/No.891.test.cpp
    title: test/yuki/No.891.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/math/matrix.md
    document_title: "maxtirx(\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\ntemplate<typename T>\nclass Matrix {\n\
    \    vector<vector<T>> dat;\n    int h = 0, w = 0;\n\n  public:\n    Matrix(const\
    \ vector<vector<T>>& dat)\n        : dat(dat), h(dat.size()), w(dat.front().size())\
    \ {}\n\n    Matrix(int h_, int w_, const T& v = T())\n        : dat(h_, vector<T>(w_,\
    \ v)){}\n        \n    using mat = Matrix<T>;\n    //access\n    vector<T>& operator[](int\
    \ i) { return dat[i]; }\n\n    //operator\n    mat& operator+=(const mat& r) {\n\
    \        assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] += r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n\
    \        assert(r.w == this->w);\n        for (int i = 0; i < h; i++) {\n    \
    \        for (int j = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    \n    mat& operator*=(const\
    \ mat& r) {\n        int ha = dat.size(), wa = dat.front().size();\n        int\
    \ hb = r.dat.size(), wb = r.dat.front().size();\n        assert(wa == hb);\n \
    \    \n        vector<vector<T>> res(ha, vector<T>(wb));\n        rep(i, ha) rep(k,\
    \ wa) rep(j, wb) { res[i][j] += dat[i][k] * r.dat[k][j]; }\n     \n        swap(res,\
    \ dat);\n        return (*this);\n    }\n\n    mat operator+(const mat& r) { return\
    \ mat(*this) += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r;\
    \ }\n    mat operator*(const mat& r) { return mat(*this) *= r; }\n\n    mat pow(__int64_t\
    \ e) const {\n        assert(e >= 0);\n        int n = dat.size();\n        mat\
    \ res(n, n, 0);\n        mat pr(*this);\n        for (int i = 0; i < n; i++) res[i][i]\
    \ = 1;\n\n        while (e) {\n            if (e & 1) res *= pr;\n           \
    \ pr *= pr;\n            \n            e >>= 1;\n        }\n        \n       \
    \ return res;\n    }\n};\n/// @brief maxtirx(\u884C\u5217)\n/// @docs docs/math/matrix.md\n"
  code: "#pragma once\ntemplate<typename T>\nclass Matrix {\n    vector<vector<T>>\
    \ dat;\n    int h = 0, w = 0;\n\n  public:\n    Matrix(const vector<vector<T>>&\
    \ dat)\n        : dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    Matrix(int\
    \ h_, int w_, const T& v = T())\n        : dat(h_, vector<T>(w_, v)){}\n     \
    \   \n    using mat = Matrix<T>;\n    //access\n    vector<T>& operator[](int\
    \ i) { return dat[i]; }\n\n    //operator\n    mat& operator+=(const mat& r) {\n\
    \        assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] += r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n\
    \        assert(r.w == this->w);\n        for (int i = 0; i < h; i++) {\n    \
    \        for (int j = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    \n    mat& operator*=(const\
    \ mat& r) {\n        int ha = dat.size(), wa = dat.front().size();\n        int\
    \ hb = r.dat.size(), wb = r.dat.front().size();\n        assert(wa == hb);\n \
    \    \n        vector<vector<T>> res(ha, vector<T>(wb));\n        rep(i, ha) rep(k,\
    \ wa) rep(j, wb) { res[i][j] += dat[i][k] * r.dat[k][j]; }\n     \n        swap(res,\
    \ dat);\n        return (*this);\n    }\n\n    mat operator+(const mat& r) { return\
    \ mat(*this) += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r;\
    \ }\n    mat operator*(const mat& r) { return mat(*this) *= r; }\n\n    mat pow(__int64_t\
    \ e) const {\n        assert(e >= 0);\n        int n = dat.size();\n        mat\
    \ res(n, n, 0);\n        mat pr(*this);\n        for (int i = 0; i < n; i++) res[i][i]\
    \ = 1;\n\n        while (e) {\n            if (e & 1) res *= pr;\n           \
    \ pr *= pr;\n            \n            e >>= 1;\n        }\n        \n       \
    \ return res;\n    }\n};\n/// @brief maxtirx(\u884C\u5217)\n/// @docs docs/math/matrix.md"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy:
  - main.cpp
  timestamp: '2023-03-27 20:50:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yuki/No.891.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: "maxtirx(\u884C\u5217)"
---
