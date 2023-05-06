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
    title: Treap
  - icon: ':heavy_check_mark:'
    path: src/BST/lazy_reversible_bst.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD \u5E73\
      \u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "phi function($\\phi$ \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "\u539F\u59CB\u6839"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n#include\
    \ <random>\n#include <chrono>\n\nnamespace kyopro {\nstruct xor_shift32 {\n  \
    \  uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n\n\
    struct xor_shift{\n    uint64_t rng;\n    constexpr xor_shift(uint64_t seed):rng(seed){}\n\
    \    explicit xor_shift():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n};\n\n\
    };  // namespace kyopro\n"
  code: "#pragma once\n#include <cstdint>\n#include <random>\n#include <chrono>\n\n\
    namespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit\
    \ xor_shift32(uint32_t seed) : rng(seed) {}\n    explicit xor_shift32():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n\n\
    struct xor_shift{\n    uint64_t rng;\n    constexpr xor_shift(uint64_t seed):rng(seed){}\n\
    \    explicit xor_shift():rng(std::chrono::steady_clock::now().time_since_epoch().count()){}\n\
    \    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n};\n\n\
    };  // namespace kyopro\n"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xor_shift.hpp
  requiredBy:
  - src/BST/Reversible.hpp
  - src/BST/lazy_reversible_bst.hpp
  - src/BST/Treap.hpp
  - src/math/primitive_root.hpp
  - src/math/rho.hpp
  - src/math/phi_function.hpp
  timestamp: '2023-05-03 12:18:30+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
documentation_of: src/random/xor_shift.hpp
layout: document
redirect_from:
- /library/src/random/xor_shift.hpp
- /library/src/random/xor_shift.hpp.html
title: src/random/xor_shift.hpp
---
