---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/FormalPowerSeries/fps-sqrt.hpp
    title: Sqrt of FPS
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bbst/Treap.hpp
    title: Treap
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bbst/lazy_reversible_bbst.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\
      \u4E8C\u5206\u6728"
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bbst/reversible_bbst.hpp
    title: "\u53CD\u8EE2\u53EF\u80FD\u5E73\u8861\u4E8C\u5206\u6728"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
  - icon: ':heavy_check_mark:'
    path: src/math/phi_function.hpp
    title: "Euler\u306E $\\varphi$ \u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':warning:'
    path: src/string/wildcard_pattern_matching.hpp
    title: Wildcard Pattern Matching
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Primitive_Root.test.cpp
    title: test/yosupo_judge/math/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Xor Shift
    links: []
  bundledCode: "#line 2 \"src/random/xor_shift.hpp\"\n#include <chrono>\n#include\
    \ <cstdint>\n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n \
    \   uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n"
  code: "#pragma once\n#include <chrono>\n#include <cstdint>\n#include <random>\n\n\
    namespace kyopro {\nstruct xor_shift32 {\n    uint32_t rng;\n    constexpr explicit\
    \ xor_shift32(uint32_t seed) : rng(seed) {}\n    explicit xor_shift32()\n    \
    \    : rng(std::chrono::steady_clock::now().time_since_epoch().count()) {}\n \
    \   constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n        rng\
    \ ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n};\n\n\
    struct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xor_shift.hpp
  requiredBy:
  - src/math/mod_sqrt.hpp
  - src/math/rho.hpp
  - src/math/primitive_root.hpp
  - src/math/phi_function.hpp
  - src/FormalPowerSeries/fps-sqrt.hpp
  - src/string/wildcard_pattern_matching.hpp
  - src/data-structure/bbst/reversible_bbst.hpp
  - src/data-structure/bbst/Treap.hpp
  - src/data-structure/bbst/lazy_reversible_bbst.hpp
  timestamp: '2023-10-22 21:54:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/math/Primitive_Root.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Treap.test.cpp
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/AOJ/NTL/1_D.test.cpp
documentation_of: src/random/xor_shift.hpp
layout: document
redirect_from:
- /library/src/random/xor_shift.hpp
- /library/src/random/xor_shift.hpp.html
title: Xor Shift
---
