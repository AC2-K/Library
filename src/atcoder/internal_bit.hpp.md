---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/FormalPowerSeries/FPS.hpp
    title: "\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570"
  - icon: ':x:'
    path: src/FormalPowerSeries/taylor-shift.hpp
    title: taylor shift
  - icon: ':x:'
    path: src/atcoder/convolution.hpp
    title: src/atcoder/convolution.hpp
  - icon: ':warning:'
    path: src/atcoder/lazysegtree.hpp
    title: src/atcoder/lazysegtree.hpp
  - icon: ':warning:'
    path: src/atcoder/segtree.hpp
    title: src/atcoder/segtree.hpp
  - icon: ':warning:'
    path: src/string/wildcard_pattern_matching.hpp
    title: "\u30EF\u30A4\u30EB\u30AB\u30FC\u30C9\u30D1\u30BF\u30FC\u30F3\u30DE\u30C3\
      \u30C1\u30F3\u30B0"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n"
  code: "#ifndef ATCODER_INTERNAL_BITOP_HPP\n#define ATCODER_INTERNAL_BITOP_HPP 1\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus\
    \ >= 202002L\n\nusing std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\n\
    unsigned int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x\
    \ < (unsigned int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <=\
    \ n`\n// @return same with std::bit::countr_zero\nint countr_zero(unsigned int\
    \ n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n//\
    \ @param n `1 <= n`\n// @return same with std::bit::countr_zero\nconstexpr int\
    \ countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1\
    \ << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: src/atcoder/internal_bit.hpp
  requiredBy:
  - src/atcoder/convolution.hpp
  - src/atcoder/lazysegtree.hpp
  - src/atcoder/segtree.hpp
  - src/FormalPowerSeries/FPS.hpp
  - src/FormalPowerSeries/taylor-shift.hpp
  - src/string/wildcard_pattern_matching.hpp
  timestamp: '2023-08-02 13:39:21+00:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
documentation_of: src/atcoder/internal_bit.hpp
layout: document
redirect_from:
- /library/src/atcoder/internal_bit.hpp
- /library/src/atcoder/internal_bit.hpp.html
title: src/atcoder/internal_bit.hpp
---
