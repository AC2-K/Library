---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/gauss_jordan.hpp
    title: "Gauss Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
    title: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: bitvector
    links: []
  bundledCode: "#line 2 \"src/data-structure/bitvector.hpp\"\n\n#include <cassert>\n\
    #include <cstdint>\n#include <limits>\n#include <numeric>\n#include <vector>\n\
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
    \ rhs.arr);\n    }\n};\n};  // namespace std\n\n/**\n * @brief bitvector\n */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <cstdint>\n#include <limits>\n\
    #include <numeric>\n#include <vector>\n\nnamespace std {\ntemplate <typename bits\
    \ = __uint128_t> class bitvec {\n    using usize = std::size_t;\n\n    const int\
    \ dgt = std::numeric_limits<bits>::digits;\n\n    usize size_;\n\n    std::vector<bits>\
    \ arr;\n\npublic:\n    bitvec(usize size_) : size_(size_), arr((size_ + dgt -\
    \ 1) / dgt) {}\n\n    usize size() const { return size_; }\n\n    void resize(usize\
    \ size_) { this->size_ = size_; }\n\n    bool at(usize p) const {\n        assert(0\
    \ <= p && p < size());\n        return arr[p / dgt] >> (p % dgt) & 1;\n    }\n\
    \n    bool operator[](usize p) const { return at(p); }\n\n    void set(usize p,\
    \ bool f) {\n        assert(0 <= p && p < size());\n\n        if (f) {\n     \
    \       arr[p / dgt] |= (bits(1) << (p % dgt));\n        } else {\n          \
    \  arr[p / dgt] &= ~(bits(1) << (p % dgt));\n        }\n    }\n\n    bitvec& operator^=(const\
    \ bitvec<bits>& rhs) {\n        assert((*this).size() == rhs.size());\n      \
    \  assert((*this).arr.size() == rhs.arr.size());\n        for (int i = 0; i <\
    \ (int)(this->arr).size(); ++i) {\n            this->arr[i] ^= rhs.arr[i];\n \
    \       }\n        return (*this);\n    }\n    bitvec& operator&=(const bitvec<bits>&\
    \ rhs) {\n        assert((*this).size() == rhs.size());\n        assert((*this).arr.size()\
    \ == rhs.arr.size());\n        for (int i = 0; i < (int)(this->arr).size(); ++i)\
    \ {\n            this->arr[i] &= rhs.arr[i];\n        }\n        return (*this);\n\
    \    }\n    bitvec& operator|=(const bitvec<bits>& rhs) {\n        assert((*this).size()\
    \ == rhs.size());\n        assert((*this).arr.size() == rhs.arr.size());\n\n \
    \       for (int i = 0; i < (int)(this->arr).size(); ++i) {\n            this->arr[i]\
    \ |= rhs.arr[i];\n        }\n        return (*this);\n    }\n\n    void swap(bitvec<bits>&\
    \ rhs) {\n        std::swap(this->size_, rhs.size_);\n        std::swap(this->arr,\
    \ rhs.arr);\n    }\n};\n};  // namespace std\n\n/**\n * @brief bitvector\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/bitvector.hpp
  requiredBy:
  - src/math/gauss_jordan.hpp
  timestamp: '2024-12-06 15:11:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
documentation_of: src/data-structure/bitvector.hpp
layout: document
redirect_from:
- /library/src/data-structure/bitvector.hpp
- /library/src/data-structure/bitvector.hpp.html
title: bitvector
---
