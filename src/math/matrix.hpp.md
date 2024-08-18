---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
    title: test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Matrix(\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"src/math/matrix.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\n\ntemplate <typename T> class Matrix {\n\
    \    std::vector<std::vector<T>> dat;\n\npublic:\n    \n    int h;\n    int w;\n\
    \n    constexpr Matrix(const std::vector<std::vector<T>>& dat)\n        : dat(dat),\
    \ h(dat.size()), w(dat.front().size()) {}\n        \n    constexpr Matrix(int\
    \ h_, int w_, T v = T())\n        : dat(h_, std::vector<T>(w_, v)), h(h_), w(w_)\
    \ {}\n    \n    using mat = Matrix<T>;\n    // access\n    constexpr std::vector<T>&\
    \ operator[](int i) { return dat[i]; }\n\n    constexpr mat& operator=(const mat&\
    \ r) {\n        this->dat = r.dat;\n        this->h = r.h, this->w = r.w;\n  \
    \      return (*this);\n    }\n\n    // operator\n    constexpr mat& operator+=(const\
    \ mat& r) {\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n\
    \n        for (int i = 0; i < (this->h); i++) {\n            for (int j = 0; j\
    \ < (this->w); j++) {\n                this->dat[i][j] += r.dat[i][j];\n     \
    \       }\n        }\n        return (*this);\n    }\n\n    constexpr mat& operator-=(const\
    \ mat& r) {\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n\
    \        for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++)\
    \ {\n                dat[i][j] -= r.dat[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    constexpr mat& operator*=(const mat& r) {\n\
    \        int ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(),\
    \ wb = r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++) {\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    constexpr mat operator+(const mat& r) { return\
    \ mat(*this) += r; }\n    constexpr mat operator-(const mat& r) { return mat(*this)\
    \ -= r; }\n    constexpr mat operator*(const mat& r) { return mat(*this) *= r;\
    \ }\n\n    static mat E(int n) {\n        mat res(n, n, 0);\n        for (int\
    \ i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n    template\
    \ <typename P> constexpr mat pow(P e) const {\n        assert(e >= 0);\n     \
    \   int n = dat.size();\n        mat res = mat::E(n);\n        mat pr(*this);\n\
    \n        while (e) {\n            if (e & 1) res *= pr;\n            pr *= pr;\n\
    \n            e >>= 1;\n        }\n\n        return res;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Matrix(\u884C\u5217)\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    namespace kyopro {\n\ntemplate <typename T> class Matrix {\n    std::vector<std::vector<T>>\
    \ dat;\n\npublic:\n    \n    int h;\n    int w;\n\n    constexpr Matrix(const\
    \ std::vector<std::vector<T>>& dat)\n        : dat(dat), h(dat.size()), w(dat.front().size())\
    \ {}\n        \n    constexpr Matrix(int h_, int w_, T v = T())\n        : dat(h_,\
    \ std::vector<T>(w_, v)), h(h_), w(w_) {}\n    \n    using mat = Matrix<T>;\n\
    \    // access\n    constexpr std::vector<T>& operator[](int i) { return dat[i];\
    \ }\n\n    constexpr mat& operator=(const mat& r) {\n        this->dat = r.dat;\n\
    \        this->h = r.h, this->w = r.w;\n        return (*this);\n    }\n\n   \
    \ // operator\n    constexpr mat& operator+=(const mat& r) {\n        assert(r.h\
    \ == this->h);\n        assert(r.w == this->w);\n\n        for (int i = 0; i <\
    \ (this->h); i++) {\n            for (int j = 0; j < (this->w); j++) {\n     \
    \           this->dat[i][j] += r.dat[i][j];\n            }\n        }\n      \
    \  return (*this);\n    }\n\n    constexpr mat& operator-=(const mat& r) {\n \
    \       assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] -= r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n\n    constexpr mat& operator*=(const mat& r) {\n        int\
    \ ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(), wb\
    \ = r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++) {\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    constexpr mat operator+(const mat& r) { return\
    \ mat(*this) += r; }\n    constexpr mat operator-(const mat& r) { return mat(*this)\
    \ -= r; }\n    constexpr mat operator*(const mat& r) { return mat(*this) *= r;\
    \ }\n\n    static mat E(int n) {\n        mat res(n, n, 0);\n        for (int\
    \ i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n    template\
    \ <typename P> constexpr mat pow(P e) const {\n        assert(e >= 0);\n     \
    \   int n = dat.size();\n        mat res = mat::E(n);\n        mat pr(*this);\n\
    \n        while (e) {\n            if (e & 1) res *= pr;\n            pr *= pr;\n\
    \n            e >>= 1;\n        }\n\n        return res;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Matrix(\u884C\u5217)\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2024-08-18 16:42:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
redirect_from:
- /library/src/math/matrix.hpp
- /library/src/math/matrix.hpp.html
title: "Matrix(\u884C\u5217)"
---
