---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':x:'
    path: src/math/combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570\u306A\u3069"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#line 2 \"src/math/combination.hpp\"\n#include <cassert>\n\
    #line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\nnamespace kyopro {\n\
    namespace internal {\n\n/**\n * @brief Barrett Reduction\n */\nclass barrett {\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u32 m;\n    u64 im;\n\
    \npublic:\n    constexpr barrett() : m(0), im(0) {}\n    constexpr barrett(u32\
    \ m_)\n        : m(m_), im((u64) static_cast<u64>(-1) / m_ + 1) {}\n\n    constexpr\
    \ u32 get_mod() const { return m; }\n    constexpr u32 reduce(int64_t a) const\
    \ { return mul(a, 1); }\n    constexpr u32 mul(u32 a, u32 b) const {\n       \
    \ if (!a || !b) {\n            return 0;\n        }\n        u64 z = (u64)a *\
    \ b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\n        u64 y = x\
    \ * m;\n        return (u32)(z - y + (z < y ? m : 0));\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace kyopro\n\n/**\n * @ref\n * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 4 \"src/math/combination.hpp\"\nnamespace kyopro {\ntemplate <int\
    \ MAX>\nclass dynamic_combination {\n    int fac[MAX], ifac[MAX];\n    const int\
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
    \ fact(int n) const { return fac[n]; }\n};\n\ntemplate <int modulo, int MAX>\n\
    class combination {\n    static constexpr int sz = std::min(modulo, MAX);\n  \
    \  int fac[sz + 1], ifac[sz + 1];\n    constexpr int inverse(int a) const {\n\
    \        int ans = 1;\n        int p = modulo - 2;\n        while (p) {\n    \
    \        if (p & 1) (ans *= a) %= modulo;\n            p >>= 1;\n            (a\
    \ *= a) %= modulo;\n        }\n        return ans;\n    }\n\npublic:\n    constexpr\
    \ explicit combination() {\n        fac[0] = ifac[0] = fac[1] = ifac[1] = 1;\n\
    \n        for (int i = 2; i < sz; ++i) {\n            fac[i] = fac[i - 1] * i\
    \ % modulo;\n        }\n\n        ifac[sz - 1] = inverse(fac[sz - 1]);\n     \
    \   for (int i = sz - 2; i > 1; --i) {\n            ifac[i] = (long long)ifac[i\
    \ + 1] * (i + 1) % modulo;\n        }\n    }\n\n    constexpr int binom(int n,\
    \ int r) const {\n        assert(n >= r);\n        return (long long)fac[n] *\
    \ ifac[r] % modulo * ifac[n - r] % modulo;\n    }\n    constexpr int perm(int\
    \ n, int r) const {\n        assert(n >= r);\n        return fac[n] * ifac[n -\
    \ r] % modulo;\n    }\n    constexpr int fact(int n) const { return fac[n]; }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\u306A\
    \u3069\n */\n#line 5 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
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
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp.html
title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
---
