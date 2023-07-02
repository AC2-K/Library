---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_math.hpp
    title: atcoder/internal_math.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"atcoder/math.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <tuple>\n#include <vector>\n\n#line 1 \"atcoder/internal_math.hpp\"\
    \n\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n// @param m `1 <= m`\n// @return\
    \ x mod m\nconstexpr long long safe_mod(long long x, long long m) {\n    x %=\
    \ m;\n    if (x < 0) x += m;\n    return x;\n}\n\n// Fast modular multiplication\
    \ by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned long long y = x * _m;\n        return (unsigned int)(z\
    \ - y + (z < y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1\
    \ <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 10 \"atcoder/math.hpp\"\
    \n\nnamespace atcoder {\n\nlong long pow_mod(long long x, long long n, int m)\
    \ {\n    assert(0 <= n && 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett\
    \ bt((unsigned int)(m));\n    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n    while (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y,\
    \ y);\n        n >>= 1;\n    }\n    return r;\n}\n\nlong long inv_mod(long long\
    \ x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n\
    \    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\nstd::pair<long\
    \ long, long long> crt(const std::vector<long long>& r,\n                    \
    \                const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    int n = int(r.size());\n    // Contracts: 0 <= r0 < m0\n    long long r0\
    \ = 0, m0 = 1;\n    for (int i = 0; i < n; i++) {\n        assert(1 <= m[i]);\n\
    \        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];\n        if\
    \ (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1) return\
    \ {0, 0};\n            continue;\n        }\n        // assume: m0 > m1, lcm(m0,\
    \ m1) >= 2 * max(m0, m1)\n\n        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0,\
    \ m1));\n        // r2 % m0 = r0\n        // r2 % m1 = r1\n        // -> (r0 +\
    \ x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g =\
    \ m1)\n        // -> x = (r1 - r0) / g * inv(u0) (mod u1)\n\n        // im = inv(u0)\
    \ (mod u1) (0 <= im < u1)\n        long long g, im;\n        std::tie(g, im) =\
    \ internal::inv_gcd(m0, m1);\n\n        long long u1 = (m1 / g);\n        // |r1\
    \ - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1 - r0) % g) return {0, 0};\n\
    \n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n       \
    \ long long x = (r1 - r0) / g % u1 * im % u1;\n\n        // |r0| + |m0 * x|\n\
    \        // < m0 + m0 * (u1 - 1)\n        // = m0 + m0 * m1 / g - m0\n       \
    \ // = lcm(m0, m1)\n        r0 += x * m0;\n        m0 *= u1;  // -> lcm(m0, m1)\n\
    \        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}\n\nlong long floor_sum(long\
    \ long n, long long m, long long a, long long b) {\n    assert(0 <= n && n < (1LL\
    \ << 32));\n    assert(1 <= m && m < (1LL << 32));\n    unsigned long long ans\
    \ = 0;\n    if (a < 0) {\n        unsigned long long a2 = internal::safe_mod(a,\
    \ m);\n        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n\
    \    }\n    if (b < 0) {\n        unsigned long long b2 = internal::safe_mod(b,\
    \ m);\n        ans -= 1ULL * n * ((b2 - b) / m);\n        b = b2;\n    }\n   \
    \ return ans + internal::floor_sum_unsigned(n, m, a, b);\n}\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_MATH_HPP\n#define ATCODER_MATH_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\n#include \"atcoder/internal_math\"\
    \n\nnamespace atcoder {\n\nlong long pow_mod(long long x, long long n, int m)\
    \ {\n    assert(0 <= n && 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett\
    \ bt((unsigned int)(m));\n    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n    while (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y,\
    \ y);\n        n >>= 1;\n    }\n    return r;\n}\n\nlong long inv_mod(long long\
    \ x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n\
    \    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\nstd::pair<long\
    \ long, long long> crt(const std::vector<long long>& r,\n                    \
    \                const std::vector<long long>& m) {\n    assert(r.size() == m.size());\n\
    \    int n = int(r.size());\n    // Contracts: 0 <= r0 < m0\n    long long r0\
    \ = 0, m0 = 1;\n    for (int i = 0; i < n; i++) {\n        assert(1 <= m[i]);\n\
    \        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];\n        if\
    \ (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0, m1);\n\
    \        }\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1) return\
    \ {0, 0};\n            continue;\n        }\n        // assume: m0 > m1, lcm(m0,\
    \ m1) >= 2 * max(m0, m1)\n\n        // (r0, m0), (r1, m1) -> (r2, m2 = lcm(m0,\
    \ m1));\n        // r2 % m0 = r0\n        // r2 % m1 = r1\n        // -> (r0 +\
    \ x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0, u1*g =\
    \ m1)\n        // -> x = (r1 - r0) / g * inv(u0) (mod u1)\n\n        // im = inv(u0)\
    \ (mod u1) (0 <= im < u1)\n        long long g, im;\n        std::tie(g, im) =\
    \ internal::inv_gcd(m0, m1);\n\n        long long u1 = (m1 / g);\n        // |r1\
    \ - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1 - r0) % g) return {0, 0};\n\
    \n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n       \
    \ long long x = (r1 - r0) / g % u1 * im % u1;\n\n        // |r0| + |m0 * x|\n\
    \        // < m0 + m0 * (u1 - 1)\n        // = m0 + m0 * m1 / g - m0\n       \
    \ // = lcm(m0, m1)\n        r0 += x * m0;\n        m0 *= u1;  // -> lcm(m0, m1)\n\
    \        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}\n\nlong long floor_sum(long\
    \ long n, long long m, long long a, long long b) {\n    assert(0 <= n && n < (1LL\
    \ << 32));\n    assert(1 <= m && m < (1LL << 32));\n    unsigned long long ans\
    \ = 0;\n    if (a < 0) {\n        unsigned long long a2 = internal::safe_mod(a,\
    \ m);\n        ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n\
    \    }\n    if (b < 0) {\n        unsigned long long b2 = internal::safe_mod(b,\
    \ m);\n        ans -= 1ULL * n * ((b2 - b) / m);\n        b = b2;\n    }\n   \
    \ return ans + internal::floor_sum_unsigned(n, m, a, b);\n}\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_MATH_HPP\n"
  dependsOn:
  - atcoder/internal_math.hpp
  isVerificationFile: false
  path: atcoder/math.hpp
  requiredBy: []
  timestamp: '2023-07-02 15:52:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/math.hpp
layout: document
redirect_from:
- /library/atcoder/math.hpp
- /library/atcoder/math.hpp.html
title: atcoder/math.hpp
---
