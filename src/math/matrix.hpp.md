---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/math/matrix.md
    document_title: "\u884C\u5217"
    links: []
  bundledCode: "#line 2 \"src/math/matrix.hpp\"\n#include <utility>\n#include <vector>\n\
    #include <cassert>\nnamespace kyopro {\n/// @brief \u884C\u5217\ntemplate <typename\
    \ T>\nclass Matrix {\n    std::vector<std::vector<T>> dat;\n    int h = 0, w =\
    \ 0;\n\npublic:\n    Matrix(const std::vector<std::vector<T>>& dat)\n        :\
    \ dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    Matrix(int h_, int\
    \ w_, T v = T()) : dat(h_, std::vector<T>(w_, v)) {}\n\n    using mat = Matrix<T>;\n\
    \    // access\n    std::vector<T>& operator[](int i) { return dat[i]; }\n\n \
    \   // operator\n    mat& operator+=(const mat& r) {\n        assert(r.h == this->h);\n\
    \        assert(r.w == this->w);\n        for (int i = 0; i < h; i++) {\n    \
    \        for (int j = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    mat& operator-=(const\
    \ mat& r) {\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n\
    \        for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++)\
    \ {\n                dat[i][j] -= r.dat[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    mat& operator*=(const mat& r) {\n        int\
    \ ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(), wb\
    \ = r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++) {\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    template <typename\
    \ P>\n    mat pow(P e) const {\n        assert(e >= 0);\n        int n = dat.size();\n\
    \        mat res(n, n, 0);\n        mat pr(*this);\n        for (int i = 0; i\
    \ < n; i++) res[i][i] = 1;\n\n        while (e) {\n            if (e & 1) res\
    \ *= pr;\n            pr *= pr;\n\n            e >>= 1;\n        }\n\n       \
    \ return res;\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/math/matrix.md\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include <cassert>\n\
    namespace kyopro {\n/// @brief \u884C\u5217\ntemplate <typename T>\nclass Matrix\
    \ {\n    std::vector<std::vector<T>> dat;\n    int h = 0, w = 0;\n\npublic:\n\
    \    Matrix(const std::vector<std::vector<T>>& dat)\n        : dat(dat), h(dat.size()),\
    \ w(dat.front().size()) {}\n\n    Matrix(int h_, int w_, T v = T()) : dat(h_,\
    \ std::vector<T>(w_, v)) {}\n\n    using mat = Matrix<T>;\n    // access\n   \
    \ std::vector<T>& operator[](int i) { return dat[i]; }\n\n    // operator\n  \
    \  mat& operator+=(const mat& r) {\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    mat& operator-=(const mat& r)\
    \ {\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n      \
    \  for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n\
    \                dat[i][j] -= r.dat[i][j];\n            }\n        }\n       \
    \ return (*this);\n    }\n\n    mat& operator*=(const mat& r) {\n        int ha\
    \ = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(), wb =\
    \ r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++) {\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    template <typename\
    \ P>\n    mat pow(P e) const {\n        assert(e >= 0);\n        int n = dat.size();\n\
    \        mat res(n, n, 0);\n        mat pr(*this);\n        for (int i = 0; i\
    \ < n; i++) res[i][i] = 1;\n\n        while (e) {\n            if (e & 1) res\
    \ *= pr;\n            pr *= pr;\n\n            e >>= 1;\n        }\n\n       \
    \ return res;\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/math/matrix.md"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
redirect_from:
- /library/src/math/matrix.hpp
- /library/src/math/matrix.hpp.html
title: "\u884C\u5217"
---
