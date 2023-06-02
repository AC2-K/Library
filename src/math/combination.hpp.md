---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
    title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "#line 2 \"src/math/combination.hpp\"\n#include <cassert>\n#include\
    \ <algorithm>\n#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace\
    \ kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass\
    \ barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u32 m;\n\
    \    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr\
    \ barrett(u32 m_)\n        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}\n\
    \n    constexpr u32 get_mod() const { return m; }\n    constexpr u32 reduce(int64_t\
    \ a) const { return mul(a, 1); }\n    constexpr u32 mul(u32 a, u32 b) const {\n\
    \        if (!a || !b) {\n            return 0;\n        }\n        u64 z = (u64)a\
    \ * b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u64 y =\
    \ x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 5 \"src/math/combination.hpp\"\nnamespace kyopro {\ntemplate <int\
    \ MAX> class dynamic_combination {\n    int fac[MAX], ifac[MAX];\n    const int\
    \ sz;\n    constexpr int inverse(int a) const {\n        int p = bar.get_mod()\
    \ - 2;\n        int ans = 1;\n        while (p) {\n            if (p & 1) ans\
    \ = bar.mul(ans, a);\n            p >>= 1;\n            a = bar.mul(a, a);\n \
    \       }\n        return ans;\n    }\n\n    const internal::barrett bar;\n\n\
    public:\n    constexpr explicit dynamic_combination(int modulo)\n        : sz(std::min(MAX,\
    \ modulo)), bar(modulo) {\n        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;\n\n\
    \        for (int i = 2; i < sz; ++i) {\n            fac[i] = bar.mul(fac[i -\
    \ 1], i);\n        }\n\n        ifac[sz - 1] = inverse(fac[sz - 1]);\n       \
    \ for (int i = sz - 2; i > 1; --i) {\n            ifac[i] = bar.mul(ifac[i + 1],\
    \ i + 1);\n        }\n    }\n\n    constexpr int binom(int n, int r) const {\n\
    \        assert(n >= r);\n        return bar.mul(fac[n], bar.mul(ifac[r], ifac[n\
    \ - r]));\n    }\n    constexpr int perm(int n, int r) const {\n        assert(n\
    \ >= r);\n        return bar.mul(fac[n], ifac[n - r]);\n    }\n    constexpr int\
    \ fact(int n) const { return fac[n]; }\n};\n\ntemplate <int modulo, int MAX> class\
    \ combination {\n    static constexpr int sz = std::min(modulo, MAX);\n    int\
    \ fac[sz + 1], ifac[sz + 1];\n    constexpr int inverse(int a) const {\n     \
    \   int ans = 1;\n        int p = modulo - 2;\n        while (p) {\n         \
    \   if (p & 1) (ans *= a) %= modulo;\n            p >>= 1;\n            (a *=\
    \ a) %= modulo;\n        }\n        return ans;\n    }\n\npublic:\n    constexpr\
    \ explicit combination() {\n        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;\n\
    \n        for (int i = 2; i < sz; ++i) {\n            fac[i] = fac[i - 1] * i\
    \ % modulo;\n        }\n\n        ifac[sz - 1] = inverse(fac[sz - 1]);\n     \
    \   for (int i = sz - 2; i > 1; --i) {\n            ifac[i] = (long long)ifac[i\
    \ + 1] * (i + 1) % modulo;\n        }\n    }\n\n    constexpr int binom(int n,\
    \ int r) const {\n        assert(n >= r);\n        return (long long)fac[n] *\
    \ ifac[r] % modulo * ifac[n - r] % modulo;\n    }\n    constexpr int perm(int\
    \ n, int r) const {\n        assert(n >= r);\n        return fac[n] * ifac[n -\
    \ r] % modulo;\n    }\n    constexpr int fact(int n) const { return fac[n]; }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <algorithm>\n#include \"../internal/barrett.hpp\"\
    \nnamespace kyopro {\ntemplate <int MAX> class dynamic_combination {\n    int\
    \ fac[MAX], ifac[MAX];\n    const int sz;\n    constexpr int inverse(int a) const\
    \ {\n        int p = bar.get_mod() - 2;\n        int ans = 1;\n        while (p)\
    \ {\n            if (p & 1) ans = bar.mul(ans, a);\n            p >>= 1;\n   \
    \         a = bar.mul(a, a);\n        }\n        return ans;\n    }\n\n    const\
    \ internal::barrett bar;\n\npublic:\n    constexpr explicit dynamic_combination(int\
    \ modulo)\n        : sz(std::min(MAX, modulo)), bar(modulo) {\n        fac[0]\
    \ = ifac[0] = fac[1] = ifac[1] = 1;\n\n        for (int i = 2; i < sz; ++i) {\n\
    \            fac[i] = bar.mul(fac[i - 1], i);\n        }\n\n        ifac[sz -\
    \ 1] = inverse(fac[sz - 1]);\n        for (int i = sz - 2; i > 1; --i) {\n   \
    \         ifac[i] = bar.mul(ifac[i + 1], i + 1);\n        }\n    }\n\n    constexpr\
    \ int binom(int n, int r) const {\n        assert(n >= r);\n        return bar.mul(fac[n],\
    \ bar.mul(ifac[r], ifac[n - r]));\n    }\n    constexpr int perm(int n, int r)\
    \ const {\n        assert(n >= r);\n        return bar.mul(fac[n], ifac[n - r]);\n\
    \    }\n    constexpr int fact(int n) const { return fac[n]; }\n};\n\ntemplate\
    \ <int modulo, int MAX> class combination {\n    static constexpr int sz = std::min(modulo,\
    \ MAX);\n    int fac[sz + 1], ifac[sz + 1];\n    constexpr int inverse(int a)\
    \ const {\n        int ans = 1;\n        int p = modulo - 2;\n        while (p)\
    \ {\n            if (p & 1) (ans *= a) %= modulo;\n            p >>= 1;\n    \
    \        (a *= a) %= modulo;\n        }\n        return ans;\n    }\n\npublic:\n\
    \    constexpr explicit combination() {\n        fac[0] = ifac[0] = fac[1] = ifac[1]\
    \ = 1;\n\n        for (int i = 2; i < sz; ++i) {\n            fac[i] = fac[i -\
    \ 1] * i % modulo;\n        }\n\n        ifac[sz - 1] = inverse(fac[sz - 1]);\n\
    \        for (int i = sz - 2; i > 1; --i) {\n            ifac[i] = (long long)ifac[i\
    \ + 1] * (i + 1) % modulo;\n        }\n    }\n\n    constexpr int binom(int n,\
    \ int r) const {\n        assert(n >= r);\n        return (long long)fac[n] *\
    \ ifac[r] % modulo * ifac[n - r] % modulo;\n    }\n    constexpr int perm(int\
    \ n, int r) const {\n        assert(n >= r);\n        return fac[n] * ifac[n -\
    \ r] % modulo;\n    }\n    constexpr int fact(int n) const { return fac[n]; }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\n */"
  dependsOn:
  - src/internal/barrett.hpp
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy: []
  timestamp: '2023-05-18 18:16:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
documentation_of: src/math/combination.hpp
layout: document
redirect_from:
- /library/src/math/combination.hpp
- /library/src/math/combination.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570"
---
