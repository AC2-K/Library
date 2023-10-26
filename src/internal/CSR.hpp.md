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
    \   const usize _size;\n    std::vector<T> csr;\n    std::vector<usize> ssum;\n\
    \npublic:\n    class range {\n        const typename std::vector<T>::iterator\
    \ l, r;\n\n    public:\n        range(const typename std::vector<T>::iterator&\
    \ l,\n              const typename std::vector<T>::iterator& r)\n            :\
    \ l(l), r(r){}\n        typename std::vector<T>::iterator begin() const noexcept\
    \ { return l; }\n        typename std::vector<T>::iterator end() const noexcept\
    \ { return r; }\n    };\n    \n    CSR(const std::vector<std::vector<T>>& mat)\
    \ : _size(mat.size()) {\n        for (int i = 0; i < _size; ++i) ssum[i + 1] =\
    \ ssum[i] + mat[i].size();\n        csr.reserve(ssum.back());\n        for (int\
    \ i = 0; i < (int)_size; ++i) {\n            for (int j = 0; j < (int)mat[i].size();\
    \ ++j) {\n                csr.emplace_back(std::move(mat[i][j]));\n          \
    \  }\n        }\n        mat.clear();\n    }\n    usize size() const noexcept\
    \ { return _size; }\n\n    range operator[](usize x) {\n        assert(0 <= x\
    \ && x < _size);\n        return range(csr.begin() + ssum[x], csr.begin() + ssum[x\
    \ + 1]);\n    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n\n\
    /**\n * @brief CSR\u5F62\u5F0F\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    #include <iterator>\n\nnamespace kyopro {\nnamespace internal {\n\ntemplate <typename\
    \ T> class CSR {\n    using usize = std::size_t;\n\n    const usize _size;\n \
    \   std::vector<T> csr;\n    std::vector<usize> ssum;\n\npublic:\n    class range\
    \ {\n        const typename std::vector<T>::iterator l, r;\n\n    public:\n  \
    \      range(const typename std::vector<T>::iterator& l,\n              const\
    \ typename std::vector<T>::iterator& r)\n            : l(l), r(r){}\n        typename\
    \ std::vector<T>::iterator begin() const noexcept { return l; }\n        typename\
    \ std::vector<T>::iterator end() const noexcept { return r; }\n    };\n    \n\
    \    CSR(const std::vector<std::vector<T>>& mat) : _size(mat.size()) {\n     \
    \   for (int i = 0; i < _size; ++i) ssum[i + 1] = ssum[i] + mat[i].size();\n \
    \       csr.reserve(ssum.back());\n        for (int i = 0; i < (int)_size; ++i)\
    \ {\n            for (int j = 0; j < (int)mat[i].size(); ++j) {\n            \
    \    csr.emplace_back(std::move(mat[i][j]));\n            }\n        }\n     \
    \   mat.clear();\n    }\n    usize size() const noexcept { return _size; }\n\n\
    \    range operator[](usize x) {\n        assert(0 <= x && x < _size);\n     \
    \   return range(csr.begin() + ssum[x], csr.begin() + ssum[x + 1]);\n    }\n};\n\
    };  // namespace internal\n};  // namespace kyopro\n\n\n/**\n * @brief CSR\u5F62\
    \u5F0F\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/internal/CSR.hpp
  requiredBy: []
  timestamp: '2023-10-26 14:56:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/internal/CSR.hpp
layout: document
redirect_from:
- /library/src/internal/CSR.hpp
- /library/src/internal/CSR.hpp.html
title: "CSR\u5F62\u5F0F"
---
