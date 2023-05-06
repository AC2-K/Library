---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: barrett reduction
  - icon: ':heavy_check_mark:'
    path: src/math/combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#line 2 \"src/math/combination.hpp\"\n#include <cassert>\n\
    #line 2 \"src/internal/barrett.hpp\"\nnamespace kyopro {\nnamespace internal {\n\
    /// @brief barrett reduction\n/// @ref https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    class barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64\
    \ m;\n    u64 im;\n\npublic:\n    barrett() = default;\n    explicit barrett(u64\
    \ m_) : m(m_), im(static_cast<u64>(-1) / m_ + 1) {}\n\n    u64 get_mod() const\
    \ { return m; }\n    constexpr u64 reduce(int64_t a) const {\n        if (a <\
    \ 0) return m - reduce(-a);\n        u64 q = ((__uint128_t)a * im) >> 64;\n  \
    \      a -= m * q;\n        if (a >= m) a -= m;\n        return a;\n    }\n  \
    \  constexpr u64 mul(u64 a, u64 b) const {\n        if (a == 0 || b == 0) {\n\
    \            return 0;\n        }\n        u64 z = a;\n        z *= b;\n     \
    \   u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u32 v = (u32)(z - x\
    \ * m);\n\n        if (v >= m) v += m;\n        return v;\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro\n#line 4 \"src/math/combination.hpp\"\nnamespace\
    \ kyopro {\ntemplate <int MAX>\nclass dynamic_combination {\n    int fac[MAX],\
    \ ifac[MAX];\n    int m;\n    constexpr int fast_pow(int a, int p) {\n       \
    \ int ans = 1;\n        while (p) {\n            if (p & 1) ans = bar.mul(ans,\
    \ a);\n            p >>= 1;\n            a = bar.mul(a, a);\n        }\n     \
    \   return ans;\n    }\n\n    internal::barrett bar;\n\npublic:\n    constexpr\
    \ dynamic_combination(int modulo) : m(modulo), bar(modulo) {\n        fac[0] =\
    \ ifac[0] = fac[1] = ifac[1] = 1;\n        int N = std::min(m, MAX);\n       \
    \ for (int i = 2; i < N; ++i) {\n            fac[i] = bar.mul(fac[i - 1], i);\n\
    \        }\n\n        ifac[N - 1] = fast_pow(fac[N - 1], m - 2);\n        for\
    \ (int i = N - 2; i > 1; --i) {\n            ifac[i] = bar.mul(ifac[i + 1], i\
    \ + 1);\n        }\n    }\n\n    constexpr int binom(int n, int r) const {\n \
    \       assert(n >= r);\n        return bar.mul(fac[n], bar.mul(ifac[r], ifac[n\
    \ - r]));\n    }\n    constexpr int perm(int n, int r) const {\n        assert(n\
    \ >= r);\n        return fac[n] * ifac[n - r];\n    }\n    constexpr int fact(int\
    \ n) const { return fac[n]; }\n};\n\ntemplate <typename mint, int MAX>\nclass\
    \ combination {\n    mint fac[MAX + 1];\n    mint ifac[MAX + 1];\n\npublic:\n\
    \    constexpr explicit combination() {\n        fac[0] = 1;\n        for (int\
    \ i = 1; i <= MAX; ++i) {\n            fac[i] = fac[i - 1] * i;\n        }\n \
    \       ifac[MAX] = fac[MAX].inv();\n        for (int i = MAX; i > 0; --i) {\n\
    \            ifac[i - 1] = ifac[i] * i;\n        }\n    }\n\n    constexpr mint\
    \ binom(int n, int r) const {\n        assert(n >= r);\n        return fac[n]\
    \ * ifac[r] * ifac[n - r];\n    }\n    constexpr mint perm(int n, int r) const\
    \ {\n        assert(n >= r);\n        return fac[n] * ifac[n - r];\n    }\n  \
    \  constexpr mint fact(int n) { return fac[n]; }\n};\n\n};  // namespace kyopro\n\
    \n/// @brief \u4E8C\u9805\u4FC2\u6570\n#line 5 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \nint main() {\n    int t, m;\n    scanf(\"%d%d\", &t, &m);\n\n    kyopro::dynamic_combination<(int)1e7>\
    \ solver(m);\n    while (t--) {\n        int n, r;\n        scanf(\"%d%d\", &n,\
    \ &r);\n        if (n < r) {\n            puts(\"0\");\n        } else {\n   \
    \         printf(\"%d\\n\", solver.binom(n, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#include \"../../../src/math/combination.hpp\"\nint main()\
    \ {\n    int t, m;\n    scanf(\"%d%d\", &t, &m);\n\n    kyopro::dynamic_combination<(int)1e7>\
    \ solver(m);\n    while (t--) {\n        int n, r;\n        scanf(\"%d%d\", &n,\
    \ &r);\n        if (n < r) {\n            puts(\"0\");\n        } else {\n   \
    \         printf(\"%d\\n\", solver.binom(n, r));\n        }\n    }\n}"
  dependsOn:
  - src/math/combination.hpp
  - src/internal/barrett.hpp
  isVerificationFile: true
  path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  requiredBy: []
  timestamp: '2023-05-05 14:19:01+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp.html
title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
---
