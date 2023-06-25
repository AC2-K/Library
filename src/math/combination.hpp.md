---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 2 \"src/math/combination.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\nusing namespace std;\nnamespace kyopro {\n\ntemplate <typename mint,\
    \ int sz> class combination {\n    const int M;\n    mint fac[sz + 1], ifac[sz\
    \ + 1];\n\npublic:\n    explicit combination() : M(std::min<int>(mint::mod(),\
    \ sz)) {\n        assert(mint::mod());\n        fac[0] = mint(1), ifac[0] = mint(1),\
    \ fac[1] = mint(1),\n        ifac[1] = mint(1);\n\n        for (int i = 2; i <=\
    \ M; ++i) {\n            fac[i] = fac[i - 1] * i;\n        }\n\n        ifac[M\
    \ - 1] = mint(1) / fac[M - 1];\n        for (int i = M - 2; i > 1; --i) {\n  \
    \          ifac[i] = ifac[i + 1] * (i + 1);\n        }\n    }\n\n    constexpr\
    \ mint fact(int n) const {\n        assert(0 <= n && n <= sz);\n        return\
    \ fac[n];\n    }\n    constexpr mint ifact(int n) const {\n        assert(0 <=\
    \ n && n <= sz);\n        return ifac[n];\n    }\n\n    constexpr mint binom(int\
    \ n, int r) const {\n        assert(n >= r);\n        return fact(n) * ifact(r)\
    \ * ifact(n - r);\n    }\n    constexpr mint perm(int n, int r) const {\n    \
    \    assert(n >= r);\n        return fact(n) * ifact(n - r);\n    }\n};\n\n};\
    \  // namespace kyopro\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\n */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\
    namespace kyopro {\n\ntemplate <typename mint, int sz> class combination {\n \
    \   const int M;\n    mint fac[sz + 1], ifac[sz + 1];\n\npublic:\n    explicit\
    \ combination() : M(std::min<int>(mint::mod(), sz)) {\n        assert(mint::mod());\n\
    \        fac[0] = mint(1), ifac[0] = mint(1), fac[1] = mint(1),\n        ifac[1]\
    \ = mint(1);\n\n        for (int i = 2; i <= M; ++i) {\n            fac[i] = fac[i\
    \ - 1] * i;\n        }\n\n        ifac[M - 1] = mint(1) / fac[M - 1];\n      \
    \  for (int i = M - 2; i > 1; --i) {\n            ifac[i] = ifac[i + 1] * (i +\
    \ 1);\n        }\n    }\n\n    constexpr mint fact(int n) const {\n        assert(0\
    \ <= n && n <= sz);\n        return fac[n];\n    }\n    constexpr mint ifact(int\
    \ n) const {\n        assert(0 <= n && n <= sz);\n        return ifac[n];\n  \
    \  }\n\n    constexpr mint binom(int n, int r) const {\n        assert(n >= r);\n\
    \        return fact(n) * ifact(r) * ifact(n - r);\n    }\n    constexpr mint\
    \ perm(int n, int r) const {\n        assert(n >= r);\n        return fact(n)\
    \ * ifact(n - r);\n    }\n};\n\n};  // namespace kyopro\n\n/**\n * @brief \u4E8C\
    \u9805\u4FC2\u6570\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy: []
  timestamp: '2023-06-25 12:32:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
documentation_of: src/math/combination.hpp
layout: document
redirect_from:
- /library/src/math/combination.hpp
- /library/src/math/combination.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570"
---
