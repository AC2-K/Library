---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':heavy_check_mark:'
    path: src/math/combination.hpp
    title: "\u4E8C\u9805\u4FC2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
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
    #include <algorithm>\n#line 2 \"src/internal/barrett.hpp\"\n#include <cstdint>\n\
    namespace kyopro {\nnamespace internal {\n\n/**\n * @brief Barrett Reduction\n\
    \ */\nclass barrett {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n\
    \    u32 m;\n    u64 im;\n\npublic:\n    constexpr barrett() : m(0), im(0) {}\n\
    \    constexpr barrett(u32 m_)\n        : m(m_), im((u64) static_cast<u64>(-1)\
    \ / m_ + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(int64_t a) const { return mul(a, 1); }\n    constexpr u32 mul(u32\
    \ a, u32 b) const {\n        if (!a || !b) {\n            return 0;\n        }\n\
    \        u64 z = (u64)a * b;\n        u64 x = (u64)(((__uint128_t)z * im) >> 64);\n\
    \n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n   \
    \ }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @ref\n\
    \ * https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    };\n\n};  // namespace kyopro\n\n/**\n * @brief \u4E8C\u9805\u4FC2\u6570\n */\n\
    #line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    namespace kyopro {\n\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate\
    \ <typename T> constexpr inline void readint(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename Head, typename... Tail>\nconstexpr inline void readint(Head& head,\
    \ Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\n\ntemplate <typename\
    \ T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n  \
    \      putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\nvoid readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\nvoid putstr(const std::string& str) {\n    for (auto c : str) {\n \
    \       putchar_unlocked(c);\n    }\n    putchar_unlocked('\\n');\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 6 \"test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp\"\
    \nint main() {\n    int t, m;\n    kyopro::readint(t, m);\n    kyopro::dynamic_combination<(int)1e7>\
    \ solver(m);\n    while (t--) {\n        int n, r;\n        kyopro::readint(n,\
    \ r);\n        if (n < r) {\n            kyopro::putint(0);\n        } else {\n\
    \            kyopro::putint(solver.binom(n, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <iostream>\n#include \"../../../src/math/combination.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\nint main() {\n    int t, m;\n    kyopro::readint(t,\
    \ m);\n    kyopro::dynamic_combination<(int)1e7> solver(m);\n    while (t--) {\n\
    \        int n, r;\n        kyopro::readint(n, r);\n        if (n < r) {\n   \
    \         kyopro::putint(0);\n        } else {\n            kyopro::putint(solver.binom(n,\
    \ r));\n        }\n    }\n}"
  dependsOn:
  - src/math/combination.hpp
  - src/internal/barrett.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
  requiredBy: []
  timestamp: '2023-06-02 22:21:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
- /verify/test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp.html
title: test/yosupo_judge/new/Binomial_Coeffcient_Prime.test.cpp
---
