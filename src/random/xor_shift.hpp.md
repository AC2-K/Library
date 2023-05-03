---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/BST/Reversible.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u62BD\u8C61\u5316\u5E73\u8861\u4E8C\u5206\u63A2\
      \u7D22\u6728"
  - icon: ':heavy_check_mark:'
    path: src/BST/Treap.hpp
    title: src/BST/Treap.hpp
  - icon: ':heavy_check_mark:'
    path: src/BST/lazy_reversible_rbst.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD \u5E73\
      \u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - src/BST/lazy_reversible_rbst.hpp
  - src/BST/Treap.hpp
  timestamp: '2023-05-03 00:12:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
documentation_of: src/random/xor_shift.hpp
layout: document
redirect_from:
- /library/src/random/xor_shift.hpp
- /library/src/random/xor_shift.hpp.html
title: src/random/xor_shift.hpp
---
