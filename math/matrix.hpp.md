---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo judge/matrix/Matrix Product.test.cpp
    title: test/yosupo judge/matrix/Matrix Product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\ntemplate<typename T>\nclass Matrix {\n\
    \    vector<vector<T>> dat;\n    int h, w;\npublic:\n    Matrix(const vector<vector<T>>&\
    \ dat)\n        : dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    Matrix(int\
    \ h_, int w_, const T& v = T())\n        : dat(h_, vector<T>(w_, v)){}\n    static\
    \ Matrix<T> I(int sz) {\n        Matrix<T> ans(sz);\n        rep(i, sz) { ans[i][i]\
    \ = 1; }\n        return ans;\n    }\n    using mat = Matrix<T>;\n    //access\n\
    \    vector<T>& operator[](int i) { return dat[i]; }\n\n    //operator\n    mat&\
    \ operator+=(const mat& r) {\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    mat& operator-=(const mat&r){\n\
    \        assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] -= r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n    mat& operator*=(const mat& r) {\n        int ha = dat.size(),\
    \ wa = dat.front().size();\n        int hb = r.dat.size(), wb = r.dat.front().size();\n\
    \        assert(wa == hb);\n\n        vector<vector<T>> res(ha, vector<T>(wb));\n\
    \        rep(i, ha) rep(j, wb) rep(k, wa) {\n            res[i][j] += dat[i][k]\
    \ * r.dat[k][j];\n        }\n        swap(res, dat);\n        return (*this);\n\
    \    }\n\n    mat operator+(const mat& r) { return mat(*this) += r; }\n    mat\
    \ operator-(const mat& r) { return mat(*this) -= r; }\n    mat operator*(const\
    \ mat& r) { return mat(*this) *= r; }\n\n    mat pow(__uint64_t e) const {\n \
    \       mat pr=I(this->h);\n        mat pw(*this);\n\n        while(e){\n    \
    \        if(e&1){\n                pw *= pw;\n            }\n            pw *=\
    \ pw;\n            e >>= 1;\n        }\n        return pr;\n    }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nclass Matrix {\n    vector<vector<T>>\
    \ dat;\n    int h, w;\npublic:\n    Matrix(const vector<vector<T>>& dat)\n   \
    \     : dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    Matrix(int h_,\
    \ int w_, const T& v = T())\n        : dat(h_, vector<T>(w_, v)){}\n    static\
    \ Matrix<T> I(int sz) {\n        Matrix<T> ans(sz);\n        rep(i, sz) { ans[i][i]\
    \ = 1; }\n        return ans;\n    }\n    using mat = Matrix<T>;\n    //access\n\
    \    vector<T>& operator[](int i) { return dat[i]; }\n\n    //operator\n    mat&\
    \ operator+=(const mat& r) {\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    mat& operator-=(const mat&r){\n\
    \        assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] -= r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n    mat& operator*=(const mat& r) {\n        int ha = dat.size(),\
    \ wa = dat.front().size();\n        int hb = r.dat.size(), wb = r.dat.front().size();\n\
    \        assert(wa == hb);\n\n        vector<vector<T>> res(ha, vector<T>(wb));\n\
    \        rep(i, ha) rep(j, wb) rep(k, wa) {\n            res[i][j] += dat[i][k]\
    \ * r.dat[k][j];\n        }\n        swap(res, dat);\n        return (*this);\n\
    \    }\n\n    mat operator+(const mat& r) { return mat(*this) += r; }\n    mat\
    \ operator-(const mat& r) { return mat(*this) -= r; }\n    mat operator*(const\
    \ mat& r) { return mat(*this) *= r; }\n\n    mat pow(__uint64_t e) const {\n \
    \       mat pr=I(this->h);\n        mat pw(*this);\n\n        while(e){\n    \
    \        if(e&1){\n                pw *= pw;\n            }\n            pw *=\
    \ pw;\n            e >>= 1;\n        }\n        return pr;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2023-03-12 14:55:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo judge/matrix/Matrix Product.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
