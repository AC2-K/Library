---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/FormalPowerSeries/taylor-shift.hpp
    title: Polynomial Taylor Shift
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Combination
    links: []
  bundledCode: "#line 2 \"src/math/combination.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\nusing namespace std;\nnamespace kyopro {\n\ntemplate <typename mint,\
    \ int sz> class combination {\n    const int M;\n    mint fac[sz + 1], ifac[sz\
    \ + 1];\n\npublic:\n    combination() : M(std::min<int>(mint::mod(), sz)) {\n\
    \        assert(mint::mod());\n        fac[0] = mint(1), ifac[0] = mint(1), fac[1]\
    \ = mint(1),\n        ifac[1] = mint(1);\n\n        for (int i = 2; i <= M; ++i)\
    \ {\n            fac[i] = fac[i - 1] * i;\n        }\n\n        ifac[M - 1] =\
    \ mint(1) / fac[M - 1];\n        for (int i = M - 2; i > 1; --i) {\n         \
    \   ifac[i] = ifac[i + 1] * (i + 1);\n        }\n    }\n\n    constexpr mint fact(int\
    \ n) const {\n        assert(0 <= n && n <= sz);\n        return fac[n];\n   \
    \ }\n    constexpr mint ifact(int n) const {\n        assert(0 <= n && n <= sz);\n\
    \        return ifac[n];\n    }\n\n    constexpr mint binom(int n, int r) const\
    \ {\n        assert(n >= r);\n        return fact(n) * ifact(r) * ifact(n - r);\n\
    \    }\n    constexpr mint perm(int n, int r) const {\n        assert(n >= r);\n\
    \        return fact(n) * ifact(n - r);\n    }\n};\n\n};  // namespace kyopro\n\
    \n/**\n * @brief Combination\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    namespace kyopro {\n\ntemplate <typename mint, int sz> class combination {\n \
    \   const int M;\n    mint fac[sz + 1], ifac[sz + 1];\n\npublic:\n    combination()\
    \ : M(std::min<int>(mint::mod(), sz)) {\n        assert(mint::mod());\n      \
    \  fac[0] = mint(1), ifac[0] = mint(1), fac[1] = mint(1),\n        ifac[1] = mint(1);\n\
    \n        for (int i = 2; i <= M; ++i) {\n            fac[i] = fac[i - 1] * i;\n\
    \        }\n\n        ifac[M - 1] = mint(1) / fac[M - 1];\n        for (int i\
    \ = M - 2; i > 1; --i) {\n            ifac[i] = ifac[i + 1] * (i + 1);\n     \
    \   }\n    }\n\n    constexpr mint fact(int n) const {\n        assert(0 <= n\
    \ && n <= sz);\n        return fac[n];\n    }\n    constexpr mint ifact(int n)\
    \ const {\n        assert(0 <= n && n <= sz);\n        return ifac[n];\n    }\n\
    \n    constexpr mint binom(int n, int r) const {\n        assert(n >= r);\n  \
    \      return fact(n) * ifact(r) * ifact(n - r);\n    }\n    constexpr mint perm(int\
    \ n, int r) const {\n        assert(n >= r);\n        return fact(n) * ifact(n\
    \ - r);\n    }\n};\n\n};  // namespace kyopro\n\n/**\n * @brief Combination\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy:
  - src/FormalPowerSeries/taylor-shift.hpp
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/yosupo_judge/math/Binomial_Coeffcient_Prime.test.cpp
documentation_of: src/math/combination.hpp
layout: document
redirect_from:
- /library/src/math/combination.hpp
- /library/src/math/combination.hpp.html
title: Combination
---
