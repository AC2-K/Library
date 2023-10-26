---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "CSR\u5F62\u5F0F"
    links: []
  bundledCode: "#line 2 \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include <iterator>\n\nnamespace kyopro {\nnamespace internal\
    \ {\n\ntemplate <typename T> class CSR {\n    using usize = std::size_t;\n\n \
    \   const usize n;\n    std::vector<std::vector<T>> mat;\n    std::vector<T> csr;\n\
    \    std::vector<usize> ssum;\n\npublic:\n    class range {\n        const typename\
    \ std::vector<T>::iterator l, r;\n\n    public:\n        range(const typename\
    \ std::vector<T>::iterator& l,\n              const typename std::vector<T>::iterator&\
    \ r)\n            : l(l), r(r){}\n        typename std::vector<T>::iterator begin()\
    \ { return l; }\n        typename std::vector<T>::iterator end() { return r; }\n\
    \    };\n\n    CSR(usize n) : n(n), mat(n), csr(), ssum(n + 1) {}\n    CSR(const\
    \ std::vector<std::vector<T>>& mat) : mat(mat) {}\n    \n    void add(usize a,\
    \ T b) {\n        assert(0 <= a && a < n);\n        mat[a].emplace_back(b);\n\
    \    }\n    void build() {\n        for (int i = 0; i < n; ++i) ssum[i + 1] +=\
    \ ssum[i] + mat[i].size();\n        csr.reserve(ssum.back());\n        for (int\
    \ i = 0; i < n; ++i) {\n            for (int j = 0; j < (int)mat[i].size(); ++j)\
    \ {\n                csr.emplace_back(mat[i][j]);\n            }\n        }\n\
    \        mat.clear();\n    }\n\n    const range operator[](usize x) const {\n\
    \        assert(0 <= x && x < n);\n        return range(csr.begin() + ssum[x],\
    \ csr.begin() + ssum[x + 1]);\n    }\n};\n};  // namespace internal\n};  // namespace\
    \ kyopro\n\n\n/**\n * @brief CSR\u5F62\u5F0F\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include <iterator>\n\nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename\
    \ T> class CSR {\n    using usize = std::size_t;\n\n    const usize n;\n    std::vector<std::vector<T>>\
    \ mat;\n    std::vector<T> csr;\n    std::vector<usize> ssum;\n\npublic:\n   \
    \ class range {\n        const typename std::vector<T>::iterator l, r;\n\n   \
    \ public:\n        range(const typename std::vector<T>::iterator& l,\n       \
    \       const typename std::vector<T>::iterator& r)\n            : l(l), r(r){}\n\
    \        typename std::vector<T>::iterator begin() { return l; }\n        typename\
    \ std::vector<T>::iterator end() { return r; }\n    };\n\n    CSR(usize n) : n(n),\
    \ mat(n), csr(), ssum(n + 1) {}\n    CSR(const std::vector<std::vector<T>>& mat)\
    \ : mat(mat) {}\n    \n    void add(usize a, T b) {\n        assert(0 <= a &&\
    \ a < n);\n        mat[a].emplace_back(b);\n    }\n    void build() {\n      \
    \  for (int i = 0; i < n; ++i) ssum[i + 1] += ssum[i] + mat[i].size();\n     \
    \   csr.reserve(ssum.back());\n        for (int i = 0; i < n; ++i) {\n       \
    \     for (int j = 0; j < (int)mat[i].size(); ++j) {\n                csr.emplace_back(mat[i][j]);\n\
    \            }\n        }\n        mat.clear();\n    }\n\n    const range operator[](usize\
    \ x) const {\n        assert(0 <= x && x < n);\n        return range(csr.begin()\
    \ + ssum[x], csr.begin() + ssum[x + 1]);\n    }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n\n\n/**\n * @brief CSR\u5F62\u5F0F\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/CSR.hpp
  requiredBy: []
  timestamp: '2023-10-26 13:48:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/internal/CSR.hpp
layout: document
redirect_from:
- /library/src/internal/CSR.hpp
- /library/src/internal/CSR.hpp.html
title: "CSR\u5F62\u5F0F"
---
