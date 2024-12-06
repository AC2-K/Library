---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bitvector.hpp
    title: bitvector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
    title: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Gauss Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/math/gauss_jordan.hpp\"\n\n#include <bitset>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/data-structure/bitvector.hpp\"\
    \n\n#line 4 \"src/data-structure/bitvector.hpp\"\n#include <cstdint>\n#include\
    \ <limits>\n#include <numeric>\n#line 8 \"src/data-structure/bitvector.hpp\"\n\
    \nnamespace std {\ntemplate <typename bits = __uint128_t> class bitvec {\n   \
    \ using usize = std::size_t;\n\n    const int dgt = std::numeric_limits<bits>::digits;\n\
    \n    usize size_;\n\n    std::vector<bits> arr;\n\npublic:\n    bitvec(usize\
    \ size_) : size_(size_), arr((size_ + dgt - 1) / dgt) {}\n\n    usize size() const\
    \ { return size_; }\n\n    void resize(usize size_) { this->size_ = size_; }\n\
    \n    bool at(usize p) const {\n        assert(0 <= p && p < size());\n      \
    \  return arr[p / dgt] >> (p % dgt) & 1;\n    }\n\n    bool operator[](usize p)\
    \ const { return at(p); }\n\n    void set(usize p, bool f) {\n        assert(0\
    \ <= p && p < size());\n\n        if (f) {\n            arr[p / dgt] |= (bits(1)\
    \ << (p % dgt));\n        } else {\n            arr[p / dgt] &= ~(bits(1) << (p\
    \ % dgt));\n        }\n    }\n\n    bitvec& operator^=(const bitvec<bits>& rhs)\
    \ {\n        assert((*this).size() == rhs.size());\n        assert((*this).arr.size()\
    \ == rhs.arr.size());\n        for (int i = 0; i < (int)(this->arr).size(); ++i)\
    \ {\n            this->arr[i] ^= rhs.arr[i];\n        }\n        return (*this);\n\
    \    }\n    bitvec& operator&=(const bitvec<bits>& rhs) {\n        assert((*this).size()\
    \ == rhs.size());\n        assert((*this).arr.size() == rhs.arr.size());\n   \
    \     for (int i = 0; i < (int)(this->arr).size(); ++i) {\n            this->arr[i]\
    \ &= rhs.arr[i];\n        }\n        return (*this);\n    }\n    bitvec& operator|=(const\
    \ bitvec<bits>& rhs) {\n        assert((*this).size() == rhs.size());\n      \
    \  assert((*this).arr.size() == rhs.arr.size());\n\n        for (int i = 0; i\
    \ < (int)(this->arr).size(); ++i) {\n            this->arr[i] |= rhs.arr[i];\n\
    \        }\n        return (*this);\n    }\n\n    void swap(bitvec<bits>& rhs)\
    \ {\n        std::swap(this->size_, rhs.size_);\n        std::swap(this->arr,\
    \ rhs.arr);\n    }\n};\n};  // namespace std\n\n/**\n * @brief bitvector\n */\n\
    #line 9 \"src/math/gauss_jordan.hpp\"\n\nnamespace kyopro {\n\n/// @return rank\
    \ of a\ntemplate <typename Container>\nint gauss_jordan(int n, int m, std::vector<Container>&\
    \ a) {\n    int rank = 0;\n\n    for (int j = 0; j < m && rank < n; ++j) {\n \
    \       int pivot = -1;\n\n        for (int i = rank; i < n; ++i) {\n        \
    \    if (a[i][j]) {\n                pivot = i;\n                break;\n    \
    \        }\n        }\n\n        if (pivot == -1) continue;\n\n        a[rank].swap(a[pivot]);\n\
    \n        for (int i = 0; i < n; ++i) {\n            if (i != rank) {\n      \
    \          if (a[i][j]) {\n                    a[i] ^= a[rank];\n            \
    \    }\n            }\n        }\n\n        ++rank;\n    }\n    return rank;\n\
    }\n};  // namespace kyopro\n\n/**\n * @brief Gauss Jordan\u306E\u6383\u304D\u51FA\
    \u3057\u6CD5\n */\n"
  code: "#pragma once\n\n#include <bitset>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../src/data-structure/bitvector.hpp\"\n\nnamespace\
    \ kyopro {\n\n/// @return rank of a\ntemplate <typename Container>\nint gauss_jordan(int\
    \ n, int m, std::vector<Container>& a) {\n    int rank = 0;\n\n    for (int j\
    \ = 0; j < m && rank < n; ++j) {\n        int pivot = -1;\n\n        for (int\
    \ i = rank; i < n; ++i) {\n            if (a[i][j]) {\n                pivot =\
    \ i;\n                break;\n            }\n        }\n\n        if (pivot ==\
    \ -1) continue;\n\n        a[rank].swap(a[pivot]);\n\n        for (int i = 0;\
    \ i < n; ++i) {\n            if (i != rank) {\n                if (a[i][j]) {\n\
    \                    a[i] ^= a[rank];\n                }\n            }\n    \
    \    }\n\n        ++rank;\n    }\n    return rank;\n}\n};  // namespace kyopro\n\
    \n/**\n * @brief Gauss Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5\n */"
  dependsOn:
  - src/data-structure/bitvector.hpp
  isVerificationFile: false
  path: src/math/gauss_jordan.hpp
  requiredBy: []
  timestamp: '2024-12-06 15:11:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
documentation_of: src/math/gauss_jordan.hpp
layout: document
redirect_from:
- /library/src/math/gauss_jordan.hpp
- /library/src/math/gauss_jordan.hpp.html
title: "Gauss Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5"
---
