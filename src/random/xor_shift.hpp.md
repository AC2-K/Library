---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/BST/Reversible.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\u8861\u4E8C\u5206\u63A2\
      \u7D22\u6728"
  - icon: ':warning:'
    path: src/BST/Treap.hpp
    title: src/BST/Treap.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include\
    \ <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n  \
    \  xor_shift32() : rng(std::rand()) {}\n    uint32_t operator()() {\n        rng\
    \ ^= rng << 13;\n        rng ^= rng >> 17;\n        rng ^= rng << 5;\n       \
    \ return rng;\n    }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <cstdint>\n#include <random>\n\nnamespace kyopro {\n\
    struct xor_shift32 {\n    uint32_t rng;\n    xor_shift32() : rng(std::rand())\
    \ {}\n    uint32_t operator()() {\n        rng ^= rng << 13;\n        rng ^= rng\
    \ >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n};  // namespace\
    \ kyopro\n"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xor_shift.hpp
  requiredBy:
  - src/BST/Reversible.hpp
  - src/BST/Treap.hpp
  timestamp: '2023-05-03 00:12:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/xor_shift.hpp
layout: document
redirect_from:
- /library/src/random/xor_shift.hpp
- /library/src/random/xor_shift.hpp.html
title: src/random/xor_shift.hpp
---
