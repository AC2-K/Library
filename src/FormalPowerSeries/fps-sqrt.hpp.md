---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/FormalPowerSeries/FPS.hpp
    title: "Formal Power Series(\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/atcoder/convolution.hpp
    title: src/atcoder/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: src/atcoder/internal_bit.hpp
    title: src/atcoder/internal_bit.hpp
  - icon: ':heavy_check_mark:'
    path: src/atcoder/internal_math.hpp
    title: src/atcoder/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: src/atcoder/internal_type_traits.hpp
    title: src/atcoder/internal_type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/atcoder/modint.hpp
    title: src/atcoder/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/hash_map.hpp
    title: Hash Map
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: Barrett Reduction
  - icon: ':heavy_check_mark:'
    path: src/internal/montgomery.hpp
    title: Montgomery Reduction
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: Dynamic modint
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: gcd
  - icon: ':heavy_check_mark:'
    path: src/math/miller.hpp
    title: "Primality Test(MillerRabin\u7D20\u6570\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_sqrt.hpp
    title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
  - icon: ':heavy_check_mark:'
    path: src/math/primitive_root.hpp
    title: "Primitive Root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/rho.hpp
    title: "PollardRho\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Sqrt of FPS
    links: []
  bundledCode: "#line 2 \"src/FormalPowerSeries/FPS.hpp\"\n#include <vector>\n#line\
    \ 1 \"src/atcoder/convolution.hpp\"\n\n\n\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <type_traits>\n#line 9 \"src/atcoder/convolution.hpp\"\
    \n\n#line 1 \"src/atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include\
    \ <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\n\
    namespace atcoder {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\n\
    using std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\nunsigned\
    \ int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x < (unsigned\
    \ int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nint countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n\
    \    unsigned long index;\n    _BitScanForward(&index, n);\n    return index;\n\
    #else\n    return __builtin_ctz(n);\n#endif\n}\n\n// @param n `1 <= n`\n// @return\
    \ same with std::bit::countr_zero\nconstexpr int countr_zero_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"src/atcoder/modint.hpp\"\
    \n\n\n\n#line 5 \"src/atcoder/modint.hpp\"\n#include <numeric>\n#line 7 \"src/atcoder/modint.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#line 1 \"src/atcoder/internal_math.hpp\"\
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
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"src/atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"src/atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder\
    \ {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"src/atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 12 \"src/atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n   \
    \       int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = countr_zero_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len < h) {\n        if (h - len == 1) {\n            int p = 1 <<\
    \ (h - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1\
    \ << len); s++) {\n                int offset = s << (h - len);\n            \
    \    for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len))\n                    rot\
    \ *= info.rate2[countr_zero(~(unsigned int)(s))];\n            }\n           \
    \ len++;\n        } else {\n            // 4-base\n            int p = 1 << (h\
    \ - len - 2);\n            mint rot = 1, imag = info.root[2];\n            for\
    \ (int s = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n\
    \                mint rot3 = rot2 * rot;\n                int offset = s << (h\
    \ - len);\n                for (int i = 0; i < p; i++) {\n                   \
    \ auto mod2 = 1ULL * mint::mod() * mint::mod();\n                    auto a0 =\
    \ 1ULL * a[i + offset].val();\n                    auto a1 = 1ULL * a[i + offset\
    \ + p].val() * rot.val();\n                    auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val() * rot2.val();\n                    auto a3 = 1ULL * a[i + offset\
    \ + 3 * p].val() * rot3.val();\n                    auto a1na3imag =\n       \
    \                 1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n          \
    \          auto na2 = mod2 - a2;\n                    a[i + offset] = a0 + a2\
    \ + a1 + a3;\n                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n\
    \                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n\
    \                }\n                if (s + 1 != (1 << len))\n               \
    \     rot *= info.rate3[countr_zero(~(unsigned int)(s))];\n            }\n   \
    \         len += 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    int n = int(a.size());\n\
    \    int h = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len) {\n        if (len == 1) {\n            int p = 1 << (h - len);\n\
    \            mint irot = 1;\n            for (int s = 0; s < (1 << (len - 1));\
    \ s++) {\n                int offset = s << (h - len + 1);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n   \
    \                 auto r = a[i + offset + p];\n                    a[i + offset]\
    \ = l + r;\n                    a[i + offset + p] =\n                        (unsigned\
    \ long long)(mint::mod() + l.val() - r.val()) *\n                        irot.val();\n\
    \                    ;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= info.irate2[countr_zero(~(unsigned\
    \ int)(s))];\n            }\n            len--;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len);\n            mint irot = 1,\
    \ iimag = info.iroot[2];\n            for (int s = 0; s < (1 << (len - 2)); s++)\
    \ {\n                mint irot2 = irot * irot;\n                mint irot3 = irot2\
    \ * irot;\n                int offset = s << (h - len + 2);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto a0 = 1ULL * a[i + offset\
    \ + 0 * p].val();\n                    auto a1 = 1ULL * a[i + offset + 1 * p].val();\n\
    \                    auto a2 = 1ULL * a[i + offset + 2 * p].val();\n         \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                \
    \    auto a2na3iimag =\n                        1ULL *\n                     \
    \   mint((mint::mod() + a2 - a3) * iimag.val()).val();\n\n                   \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + 1 * p]\
    \ =\n                        (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n\
    \                    a[i + offset + 2 * p] =\n                        (a0 + a1\
    \ + (mint::mod() - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n\
    \                    a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[countr_zero(~(unsigned int)(s))];\n          \
    \  }\n            len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = (int)internal::bit_ceil((unsigned int)(n + m - 1));\n    a.resize(z);\n\
    \    internal::butterfly(a);\n    b.resize(z);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < z; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\
    \ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution(std::vector<mint>&& a, std::vector<mint>&& b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    std::vector<mint> convolution(const std::vector<mint>& a,\n                  \
    \            const std::vector<mint>& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <unsigned int mod = 998244353,\n          class T,\n    \
    \      std::enable_if_t<internal::is_integral<T>::value>* = nullptr>\nstd::vector<T>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\n    using\
    \ mint = static_modint<mod>;\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    std::vector<mint>\
    \ a2(n), b2(m);\n    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n\
    \    auto c2 = convolution(std::move(a2), std::move(b2));\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n\
    \    }\n    return c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long\
    \ long>& a,\n                                      const std::vector<long long>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n\
    \    static constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static\
    \ constexpr unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n        \n    static constexpr\
    \ int MAX_AB_BIT = 24;\n    static_assert(MOD1 % (1ull << MAX_AB_BIT) == 1, \"\
    MOD1 isn't enough to support an array length of 2^24.\");\n    static_assert(MOD2\
    \ % (1ull << MAX_AB_BIT) == 1, \"MOD2 isn't enough to support an array length\
    \ of 2^24.\");\n    static_assert(MOD3 % (1ull << MAX_AB_BIT) == 1, \"MOD3 isn't\
    \ enough to support an array length of 2^24.\");\n    assert(n + m - 1 <= (1 <<\
    \ MAX_AB_BIT));\n\n    auto c1 = convolution<MOD1>(a, b);\n    auto c2 = convolution<MOD2>(a,\
    \ b);\n    auto c3 = convolution<MOD3>(a, b);\n\n    std::vector<long long> c(n\
    \ + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        unsigned long\
    \ long x = 0;\n        x += (c1[i] * i1) % MOD1 * M2M3;\n        x += (c2[i] *\
    \ i2) % MOD2 * M1M3;\n        x += (c3[i] * i3) % MOD3 * M1M2;\n        // B =\
    \ 2^63, -B <= x, r(real value) < B\n        // (x, x - M, x - 2M, or x - 3M) =\
    \ r (mod 2B)\n        // r = c1[i] (mod MOD1)\n        // focus on MOD1\n    \
    \    // r = x, x - M', x - 2M', x - 3M' (M' = M % 2^64) (mod 2B)\n        // r\
    \ = x,\n        //     x - M' + (0 or 2B),\n        //     x - 2M' + (0, 2B or\
    \ 4B),\n        //     x - 3M' + (0, 2B, 4B or 6B) (without mod!)\n        //\
    \ (r - x) = 0, (0)\n        //           - M' + (0 or 2B), (1)\n        //   \
    \        -2M' + (0 or 2B or 4B), (2)\n        //           -3M' + (0 or 2B or\
    \ 4B or 6B) (3) (mod MOD1)\n        // we checked that\n        //   ((1) mod\
    \ MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod 5 = 3\n        //   ((3) mod\
    \ MOD1) mod 5 = 4\n        long long diff =\n            c1[i] - internal::safe_mod((long\
    \ long)(x), (long long)(MOD1));\n        if (diff < 0) diff += MOD1;\n       \
    \ static constexpr unsigned long long offset[5] = {\n            0, 0, M1M2M3,\
    \ 2 * M1M2M3, 3 * M1M2M3};\n        x -= offset[diff % 5];\n        c[i] = x;\n\
    \    }\n\n    return c;\n}\n\n}  // namespace atcoder\n\n\n#line 4 \"src/FormalPowerSeries/FPS.hpp\"\
    \nnamespace kyopro{\n\ntemplate <typename mint, atcoder::internal::is_modint_t<mint>*\
    \ = nullptr>\nstruct FormalPowerSeries : public std::vector<mint> {\n    using\
    \ std::vector<mint>::vector;\n    using FPS = FormalPowerSeries<mint>;\n\n   \
    \ void expand(size_t sz) {\n        if (this->size() < sz) this->resize(sz);\n\
    \    }\n\n    void shrink() {\n        while (!(*this).empty() && (*this).back().val()\
    \ == 0) (*this).pop_back();\n    }\n\n    FPS pref(size_t sz) const {\n      \
    \  FPS g((*this).begin(), (*this).begin() + std::min(sz, this->size()));\n   \
    \     g.expand(sz);\n        return g;\n    }\n\n    FPS& operator+=(const FPS&\
    \ rhs) {\n        expand(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) (*this)[i] += rhs[i];\n        return (*this);\n    }\n    \n    FPS& operator-=(const\
    \ FPS& rhs) {\n        expand(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) (*this)[i] -= rhs[i];\n        return (*this);\n    }\n    FPS& operator*=(const\
    \ FPS& rhs) {\n        shrink();\n        std::vector res = atcoder::convolution<mint>(*this,\
    \ rhs);\n        (*this) = {res.begin(), res.end()};\n        return (*this);\n\
    \    }\n\n    FPS& operator+=(const mint& rhs) {\n        expand(1);\n       \
    \ (*this)[0] += rhs;\n        return (*this);\n    }\n    FPS& operator-=(const\
    \ mint& rhs) {\n        expand(1);\n        (*this)[0] -= rhs;\n        return\
    \ (*this);\n    }\n    FPS& operator*=(const mint& rhs) {\n        for (int i\
    \ = 0; i < (int)this->size(); ++i) {\n            (*this)[i] *= rhs;\n       \
    \ }\n        return (*this);\n    }\n    FPS& operator/=(const mint& rhs) {\n\
    \        const mint invr = rhs.inv();\n        for (int i = 0; i < (int)this->size();\
    \ ++i) {\n            (*this)[i] *= invr;\n        }\n        return (*this);\n\
    \    }\n\n    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs;\
    \ }\n    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }\n \
    \   FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }\n    FPS\
    \ operator+(const mint& rhs) const { return FPS(*this) += rhs; }\n    FPS operator-(const\
    \ mint& rhs) const { return FPS(*this) -= rhs; }\n    FPS operator*(const mint&\
    \ rhs) const { return FPS(*this) *= rhs; }\n    FPS operator/(const mint& rhs)\
    \ const { return FPS(*this) /= rhs; }\n    FPS operator>>(int sz) const {\n  \
    \      if ((int)this->size() <= sz) return {};\n        FPS ret(*this);\n    \
    \    ret.erase(ret.begin(), ret.begin() + sz);\n        return ret;\n    }\n \
    \   FPS operator<<(int sz) const {\n        FPS ret(*this);\n        ret.insert(ret.begin(),\
    \ sz, mint(0));\n        return ret;\n    }\n\n    // \u7A4D\u5206\n    FPS integral()\
    \ const {\n        FPS res(this->size() + 1);\n        for (int i = 0; i < (int)this->size();\
    \ ++i) {\n            res[i + 1] = (*this)[i] * mint(i + 1).inv();\n        }\n\
    \        return res;\n    }\n\n    // \u5FAE\u5206\n    FPS prime() const {\n\
    \        FPS res(this->size() - 1);\n        for (int i = 1; i < (int)this->size();\
    \ ++i) {\n            res[i - 1] = (*this)[i] * mint::raw(i);\n        }\n   \
    \     return res;\n    }\n\n    // \u9006\u5143\n    FPS inv(size_t sz = -1) const\
    \ {\n        assert(!(*this).empty() && (*this)[0] != mint());\n        if (sz\
    \ == -1) sz = this->size();\n\n        FPS g{mint(1) / (*this)[0]};\n        for\
    \ (int d = 1; d < sz; d <<= 1) {\n            g = (g * 2 - g * g * (*this).pref(2\
    \ * d)).pref(2 * d);\n        }\n\n        return g.pref(sz);\n    }\n\n    FPS&\
    \ operator/=(const FPS& rhs) { return (*this) *= rhs.inv(); }\n    FPS operator/(const\
    \ FPS& rhs) const { return FPS(*this) *= rhs.inv(); }\n\n    FPS log(size_t sz\
    \ = -1) const {\n        assert(!(this->empty()) && (*this)[0].val() == 1);\n\
    \        if (sz == -1) sz = this->size();\n        return ((*this).prime() * (*this).inv(sz\
    \ - 1)).pref(sz - 1).integral();\n    };\n\n    FPS exp(size_t sz = -1) const\
    \ {\n        assert(!(this->empty()) && (*this)[0].val() == 0);\n        if (sz\
    \ == -1) sz = this->size();\n\n        FPS g{mint::raw(1)};\n        for (int\
    \ d = 1; d < sz; d <<= 1) {\n            g = (g * (FPS{mint::raw(1)} - g.log(2\
    \ * d) + (*this).pref(2 * d)))\n                    .pref(2 * d);\n        }\n\
    \        return g;\n    }\n\n    FPS pow(long long e, size_t sz = -1) const {\n\
    \        if (sz == -1) sz = this->size();\n        if (e == 0) {\n           \
    \ FPS res(sz);\n            if (sz) res[0] = mint::raw(1);\n            return\
    \ res;\n        }\n\n        int p = 0;\n        while (p < (int)this->size()\
    \ && (*this)[p].val() == 0) ++p;\n\n        if (__int128_t(p) * e >= sz) {\n \
    \           return FPS(sz);\n        }\n\n        mint vp = (*this)[p];\n    \
    \    FPS f = (*this >> p);\n        f /= vp;\n        f = (f.log(sz) * e).exp(sz);\n\
    \        f *= vp.pow(e);\n        f = (f << (p * e)).pref(sz);\n        f.expand(sz);\n\
    \        return f;\n    }\n};\n\n};  // namespace kyopro\n\n/**\n * @brief Formal\
    \ Power Series(\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)\n*/\n#line 2 \"src/math/mod_log.hpp\"\
    \n#include <cmath>\n#line 2 \"src/data-structure/hash_map.hpp\"\n#include <chrono>\n\
    #line 5 \"src/data-structure/hash_map.hpp\"\n#include <bits/stl_algobase.h>\n\n\
    namespace kyopro {\ntemplate <typename Key,\n          typename Val,\n       \
    \   std::size_t n = 1 << 20,\n          Val default_val = Val()>\nclass hash_map\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64* flag = new\
    \ u64[n / 64];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\n \
    \   static constexpr u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    u32 get_hash(Key\
    \ k) const { return ((u64)k * r) >> shift; }\n\n    static constexpr int block\
    \ = 64;\n\npublic:\n    explicit hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](Key\
    \ k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if\
    \ (~flag[hash / block] >> (hash % block) & static_cast<u64>(1)) {\n          \
    \      keys[hash] = k;\n                flag[hash / block] |= (static_cast<u64>(1)\
    \ << (hash % block));\n                return vals[hash] = default_val;\n    \
    \        }\n\n            if (keys[hash] == k) return vals[hash];\n          \
    \  hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    Val* find(Key k) const\
    \ {\n        u32 hash = get_hash(k);\n        while (1) {\n            if (~flag[hash\
    \ / block] >> (hash % block) & static_cast<u64>(1)) {\n                return\
    \ nullptr;\n            }\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Hash Map\n */\n#line 4 \"src/math/gcd.hpp\"\n#include\
    \ <tuple>\nnamespace kyopro {\ntemplate <typename T> constexpr inline T _gcd(T\
    \ a, T b) noexcept {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0)\
    \ return a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (!a || !b) {\n            return a + b;\n        }\n        if (a\
    \ >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n      \
    \  } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n    \
    \    }\n    }\n\n    return a << d;\n}\n\ntemplate <typename T>\nconstexpr inline\
    \ T ext_gcd(T a, T b, T& x, T& y) noexcept {\n    x = 1, y = 0;\n    T nx = 0,\
    \ ny = 1;\n    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n\n/**\n * @brief gcd\n*/\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#line 5 \"src/internal/type_traits.hpp\"\
    \n#include <typeinfo>\n#include <cstdint>\n\nnamespace kyopro {\nnamespace internal\
    \ {\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 3\
    \ \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\ntemplate <typename T>\nconstexpr\
    \ T mod_pow(internal::double_size_uint_t<T> base, T exp, T mod) {\n    internal::double_size_uint_t<T>\
    \ ans = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n};  // namespace kyopro\n\n/**\n * @brief Modulo Power(\u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\n#line 6 \"src/math/mod_log.hpp\"\nnamespace\
    \ kyopro {\n\ntemplate <typename T> constexpr inline T mod_log(T x, T y, T p)\
    \ {\n    if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n\
    \        if (y == 0) {\n            return 1;\n        } else {\n            return\
    \ -1;\n        }\n    }\n    int m = (int)sqrt(p) + 1;\n    hash_map<T, T> mp;\n\
    \    T xm = mod_pow<T>(x, m, p);\n    internal::double_size_uint_t<T> add = 0,\
    \ g, k = (p == 1 ? 0 : 1);\n    while ((g = _gcd(x, p)) > 1) {\n        if (y\
    \ == k) return add;\n        if (y % g) return -1;\n        y /= g, p /= g, add++;\n\
    \        k = (k * (x / g)) % p;\n    }\n\n    T pr = y;\n    for (int j = 0; j\
    \ <= m; ++j) {\n        mp[pr] = j;\n        pr = (internal::double_size_uint_t<T>)pr\
    \ * x % p;\n    }\n    pr = k;\n    for (int i = 1; i <= m; ++i) {\n        pr\
    \ = (internal::double_size_uint_t<T>)pr * xm % p;\n        auto ptr = mp.find(pr);\n\
    \        if (ptr) {\n            int j = *ptr;\n            return m * i - j +\
    \ add;\n        }\n    }\n    return -1;\n}\n\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)\n * @docs docs/math/mod_log.md\n\
    \ */\n#line 3 \"src/internal/barrett.hpp\"\nnamespace kyopro {\nnamespace internal\
    \ {\nclass barrett {\n    using u32 = std::uint32_t;\n    using u64 = std::uint64_t;\n\
    \    using u128 = __uint128_t;\n\n    u32 m;\n    u64 im;\n\npublic:\n    constexpr\
    \ barrett() : m(0), im(0) {}\n    constexpr barrett(u32 m)\n        : m(m), im(static_cast<u64>(-1)\
    \ / m + 1) {}\n\n    constexpr u32 get_mod() const { return m; }\n    constexpr\
    \ u32 reduce(u32 a) const { return mul(1, a); }\n    constexpr u32 mul(u32 a,\
    \ u32 b) const {\n        u64 z = (u64)a * b;\n        u64 x = (u64)(((u128)(z)*im)\
    \ >> 64);\n        u64 y = x * m;\n        return (u32)(z - y + (z < y ? m : 0));\n\
    \    }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief\
    \ Barrett Reduction\n * @see https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    \ */\n#line 6 \"src/internal/montgomery.hpp\"\nnamespace kyopro {\nnamespace internal\
    \ {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i32 = int32_t;\nusing\
    \ i64 = int64_t;\nusing u128 = __uint128_t;\nusing i128 = __int128_t;\n\ntemplate\
    \ <typename T> class Montgomery {\n    static constexpr int lg = std::numeric_limits<T>::digits;\n\
    \    using LargeT = internal::double_size_uint_t<T>;\n    T mod, r, r2, minv;\n\
    \    T inv() {\n        T t = 0, res = 0;\n        for (int i = 0; i < lg; ++i)\
    \ {\n            if (~t & 1) {\n                t += mod;\n                res\
    \ += static_cast<T>(1) << i;\n            }\n            t >>= 1;\n        }\n\
    \        return res;\n    }\n\npublic:\n    Montgomery() = default;\n    constexpr\
    \ T get_mod() { return mod; }\n\n    void set_mod(T m) {\n        assert(m);\n\
    \        assert(m & 1);\n\n        mod = m;\n\n        r = (-static_cast<T>(mod))\
    \ % mod;\n        r2 = (-static_cast<LargeT>(mod)) % mod;\n        minv = inv();\n\
    \    }\n\n    T reduce(LargeT x) const {\n        u64 res =\n            (x +\
    \ static_cast<LargeT>(static_cast<T>(x) * minv) * mod) >> lg;\n\n        if (res\
    \ >= mod) res -= mod;\n        return res;\n    }\n\n    T generate(LargeT x)\
    \ { return reduce(x * r2); }\n\n    T mul(T x, T y) { return reduce((LargeT)x\
    \ * y); }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n\n/**\n *\
    \ @brief Montgomery Reduction\n */\n#line 6 \"src/math/dynamic_modint.hpp\"\n\
    namespace kyopro {\ntemplate <int id = -1> class barrett_modint : internal::modint_base\
    \ {\n    using mint = barrett_modint<id>;\n    using u32 = std::uint32_t;\n  \
    \  using u64 = std::uint64_t;\n\n    using i32 = std::int32_t;\n    using i64\
    \ = std::int64_t;\n    using br = internal::barrett;\n\n    static br brt;\n \
    \   u32 v;\n\npublic:\n    static void set_mod(u32 mod_) { brt = br(mod_); }\n\
    \npublic:\n    explicit constexpr barrett_modint() noexcept : v(0) { assert(mod());\
    \ }\n    explicit constexpr barrett_modint(i64 v_) noexcept : v() {\n        assert(mod());\n\
    \        if (v_ < 0) v_ = (i64)mod() - v_;\n        v = brt.reduce(v_);\n    }\n\
    \n    u32 val() const noexcept { return v; }\n    static u32 mod() { return brt.get_mod();\
    \ }\n    static mint raw(u32 v) {\n        mint x;\n        x.v = v;\n       \
    \ return x;\n    }\n\n    constexpr mint& operator++() noexcept {\n        ++v;\n\
    \        if (v == mod()) v = 0;\n        return (*this);\n    }\n    constexpr\
    \ mint& operator--() noexcept {\n        if (v == 0) v = mod();\n        --v;\n\
    \        return (*this);\n    }\n    constexpr mint operator++(int) noexcept {\n\
    \        mint res(*this);\n        ++(*this);\n        return res;\n    }\n  \
    \  constexpr mint operator--(int) noexcept {\n        mint res(*this);\n     \
    \   --(*this);\n        return res;\n    }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept {\n        v += r.v;\n        if (v >= mod()) v -= mod();\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(const mint& r)\
    \ noexcept {\n        v += mod() - r.v;\n        if (v >= mod()) {\n         \
    \   v -= mod();\n        }\n\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& r) noexcept {\n        v = brt.mul(v, r.v);\n       \
    \ return (*this);\n    }\n    constexpr mint& operator/=(const mint& r) noexcept\
    \ {\n        return (*this) *= r.inv();\n    }\n\n    friend mint operator+(const\
    \ mint& lhs, const mint& rhs) noexcept {\n        return mint(lhs) += rhs;\n \
    \   }\n    friend mint operator-(const mint& lhs, const mint& rhs) noexcept {\n\
    \        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const mint&\
    \ lhs, const mint& rhs) noexcept {\n        return mint(lhs) *= rhs;\n    }\n\
    \    friend mint operator/(const mint& lhs, const mint& rhs) noexcept {\n    \
    \    return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) noexcept {\n        return lhs.v == rhs.v;\n    }\n    friend\
    \ bool operator!=(const mint& lhs, const mint& rhs) noexcept {\n        return\
    \ lhs.v != rhs.v;\n    }\n\n    constexpr mint& operator+=(i64 r) noexcept { return\
    \ (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) noexcept { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) noexcept { return\
    \ (*this) *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) noexcept\
    \ {\n        return mint(l) += r;\n    }\n    friend mint operator+(const mint&\
    \ l, i64 r) noexcept {\n        return mint(l) += r;\n    }\n    friend mint operator-(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) -= r;\n    }\n    friend\
    \ mint operator-(const mint& l, i64 r) noexcept {\n        return mint(l) -= r;\n\
    \    }\n    friend mint operator*(i64 l, const mint& r) noexcept {\n        return\
    \ mint(l) *= r;\n    }\n    friend mint operator*(const mint& l, i64 r) noexcept\
    \ {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+() const\
    \ noexcept { return *this; }\n    constexpr mint operator-() const noexcept {\
    \ return mint() - *this; }\n\n    template <typename T> mint pow(T e) const noexcept\
    \ {\n        mint res(1), base(*this);\n\n        while (e) {\n            if\
    \ (e & 1) {\n                res *= base;\n            }\n            e >>= 1;\n\
    \            base *= base;\n        }\n        return res;\n    }\n    constexpr\
    \ mint inv() const noexcept { return pow(mod() - 2); }\n};\n};  // namespace kyopro\n\
    template <int id>\ntypename kyopro::barrett_modint<id>::br kyopro::barrett_modint<id>::brt;\n\
    \nnamespace kyopro {\ntemplate <typename T, int id = -1>\nclass montgomery_modint\
    \ : internal::modint_base {\n    using LargeT = internal::double_size_uint_t<T>;\n\
    \    static T _mod;\n    static internal::Montgomery<T> mr;\n\npublic:\n    static\
    \ void set_mod(T mod_) {\n        mr.set_mod(mod_);\n        _mod = mod_;\n  \
    \  }\n\n    static T mod() { return _mod; }\n\nprivate:\n    T v;\n\npublic:\n\
    \    montgomery_modint(T v_ = 0) {\n        assert(_mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n\n    using mint = montgomery_modint<T,\
    \ id>;\n    mint& operator+=(const mint& r) {\n        v += r.v;\n        if (v\
    \ >= mr.get_mod()) {\n            v -= mr.get_mod();\n        }\n\n        return\
    \ (*this);\n    }\n\n    mint& operator-=(const mint& r) {\n        v += mr.get_mod()\
    \ - r.v;\n        if (v >= mr.get_mod) {\n            v -= mr.get_mod();\n   \
    \     }\n\n        return (*this);\n    }\n\n    mint& operator*=(const mint&\
    \ r) {\n        v = mr.mul(v, r.v);\n        return (*this);\n    }\n\n    mint\
    \ operator+(const mint& r) { return mint(*this) += r; }\n    mint operator-(const\
    \ mint& r) { return mint(*this) -= r; }\n    mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n    mint& operator=(const T& v_) {\n        (*this) =\
    \ mint(v_);\n        return (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n\
    \    friend std::istream& operator>>(std::istream& is, mint& mt) {\n        T\
    \ v_;\n        is >> v_;\n        mt = v_;\n        return is;\n    }\n    template\
    \ <typename P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod()\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\n};  // namespace kyopro\ntemplate\
    \ <typename T, int id> T kyopro::montgomery_modint<T, id>::_mod;\ntemplate <typename\
    \ T, int id>\nkyopro::internal::Montgomery<T> kyopro::montgomery_modint<T, id>::mr;\n\
    \n/**\n * @brief Dynamic modint\n */\n#line 3 \"src/math/miller.hpp\"\nnamespace\
    \ kyopro {\n\n\nclass miller {\n    using i128 = __int128_t;\n    using u128 =\
    \ __uint128_t;\n    using u64 = std::uint64_t;\n    using u32 = std::uint32_t;\n\
    \n    template <typename T, typename mint, const int bases[], int length>\n  \
    \  static constexpr bool miller_rabin(T n) {\n        T d = n - 1;\n\n       \
    \ while (~d & 1) {\n            d >>= 1;\n        }\n\n        const T rev = n\
    \ - 1;\n        if (mint::mod() != n) {\n            mint::set_mod(n);\n     \
    \   }\n        for (int i = 0; i < length; ++i) {\n            if (n <= bases[i])\
    \ {\n                return true;\n            }\n            T t = d;\n     \
    \       mint y = mint(bases[i]).pow(t);\n\n            while (t != n - 1 && y.val()\
    \ != 1 && y.val() != rev) {\n                y *= y;\n                t <<= 1;\n\
    \            }\n\n            if (y.val() != rev && (~t & 1)) return false;\n\
    \        }\n        return true;\n    }\n    // \u5E95\n    static constexpr int\
    \ bases_int[3] = {2, 7, 61};\n    static constexpr int bases_ll[7] = {2,     \
    \ 325,     9375,      28178,\n                                        450775,\
    \ 9780504, 1795265022};\n\npublic:\n    template <typename T> static constexpr\
    \ bool is_prime(T n) {\n        if (n < 2) {\n            return false;\n    \
    \    } else if (n == 2) {\n            return true;\n        } else if (~n & 1)\
    \ {\n            return false;\n        };\n        if constexpr (std::numeric_limits<T>::digits\
    \ < 32) {\n            return miller_rabin<T, montgomery_modint<std::make_unsigned_t<T>>,\n\
    \                                bases_int, 3>(n);\n\n        } else {\n     \
    \       if (n <= 1 << 30)\n                return miller_rabin<T,\n          \
    \                          montgomery_modint<std::make_unsigned_t<T>>,\n     \
    \                               bases_int, 3>(n);\n            else\n        \
    \        return miller_rabin<\n                    T, montgomery_modint<std::make_unsigned_t<T>>,\
    \ bases_ll, 7>(\n                    n);\n        }\n        return false;\n \
    \   }\n};\n};  // namespace kyopro\n\n/**\n * @brief Primality Test(MillerRabin\u7D20\
    \u6570\u5224\u5B9A)\n * @docs docs/math/miller.md\n */\n#line 4 \"src/random/xor_shift.hpp\"\
    \n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n    uint32_t\
    \ rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed) {}\n   \
    \ explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr explicit xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief Xor Shift\n */\n#line 7 \"src/math/rho.hpp\"\
    \nnamespace kyopro {\n\n\nclass rho {\n    using i128 = __int128_t;\n    using\
    \ u128 = __uint128_t;\n    using u64 = uint64_t;\n    using u32 = uint32_t;\n\n\
    \    template <typename T,typename mint> static constexpr T find_factor(T n) {\n\
    \        xor_shift32 rng(2023);\n\n        if (~n & 1uL) {\n            return\
    \ 2;\n        }\n        if (kyopro::miller::is_prime(n)) {\n            return\
    \ n;\n        }\n\n        if (mint::mod() != n) {\n            mint::set_mod(n);\n\
    \        }\n        while (1) {\n            T c = rng();\n            const auto\
    \ f = [&](mint x) -> mint { return x * x + c; };\n            mint x = rng();\n\
    \            mint y = f(x);\n            T d = 1;\n            while (d == 1)\
    \ {\n                d = _gcd<std::make_signed_t<T>>(\n                    std::abs((std::make_signed_t<T>)x.val()\
    \ - (std::make_signed_t<T>)y.val()), n);\n                x = f(x);\n        \
    \        y = f(f(y));\n            }\n            if (1 < d && d < n) {\n    \
    \            return d;\n            }\n        }\n        exit(-1);\n    }\n \
    \   template <typename T,typename mint> static std::vector<T> rho_fact(T n) {\n\
    \        if (n < 2) {\n            return {};\n        }\n        if (kyopro::miller::is_prime(n))\
    \ {\n            return {n};\n        }\n        std::vector<T> v;\n        std::vector<T>\
    \ st{n};\n        while (!st.empty()) {\n            u64 m = st.back();\n    \
    \        if (kyopro::miller::is_prime(m)) {\n                v.emplace_back(m);\n\
    \                st.pop_back();\n            } else {\n                T d = find_factor<T,\
    \ mint>(m);\n                st.back() /= d;\n                st.emplace_back(d);\n\
    \            }\n        }\n        return v;\n    }\n\npublic:\n    template <typename\
    \ T> static std::vector<T> factorize(T n) {\n        if (n < 2) {\n          \
    \  return {};\n        }\n\n        if constexpr (std::numeric_limits<T>::digits\
    \ < 32) {\n            std::vector v = rho_fact<T, montgomery_modint<u32>>(n);\n\
    \            std::sort(v.begin(), v.end());\n            return v;\n        }\
    \ else {\n            std::vector v = rho_fact<T, montgomery_modint<u64>>(n);\n\
    \            std::sort(v.begin(), v.end());\n            return v;\n        }\n\
    \    }\n    template<typename T>\n    static std::vector<std::pair<T, int>> exp_factorize(T\
    \ n) {\n        std::vector pf = factorize(n);\n        if (pf.empty()) {\n  \
    \          return {};\n        }\n        std::vector<std::pair<T, int>> res;\n\
    \        res.emplace_back(pf.front(), 1);\n        for (int i = 1; i < (int)pf.size();\
    \ i++) {\n            if (res.back().first == pf[i]) {\n                res.back().second++;\n\
    \            } else {\n                res.emplace_back(pf[i], 1);\n         \
    \   }\n        }\n\n        return res;\n    }\n    template<typename T>\n   \
    \ static std::vector<T> enumerate_divisor(T n) {\n        std::vector<std::pair<T,\
    \ int>> pf = rho::exp_factorize(n);\n        std::vector<T> divisor{1};\n    \
    \    for (auto [p, e] : pf) {\n            u64 pow = p;\n            int sz =\
    \ divisor.size();\n            for (int i = 0; i < e; ++i) {\n               \
    \ for (int j = 0; j < sz; ++j)\n                    divisor.emplace_back(divisor[j]\
    \ * pow);\n                pow *= p;\n            }\n        }\n\n        return\
    \ divisor;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief PollardRho\u7D20\
    \u56E0\u6570\u5206\u89E3\n * @docs docs/math/rho.md\n */\n#line 4 \"src/math/primitive_root.hpp\"\
    \nnamespace kyopro {\n\ntemplate <typename T> constexpr T primitive_root(T p)\
    \ noexcept {\n    if (p == 2) return 1;\n\n    auto pf = kyopro::rho::factorize(p\
    \ - 1);\n    pf.erase(std::unique(pf.begin(), pf.end()), pf.end());\n    for (auto&\
    \ q : pf) {\n        q = (p - 1) / q;\n    }\n\n    using mint =\n        std::conditional_t<std::numeric_limits<T>::digits\
    \ <= 32,\n                           barrett_modint<-1>, montgomery_modint<uint64_t>>;\n\
    \    if (mint::mod() != p) {\n        mint::set_mod(p);\n    }\n\n    for (int\
    \ _g = 1;; ++_g) {\n        mint g(_g);\n        if (g.val() == 0) continue;\n\
    \        bool is_ok = true;\n\n        for (auto q : pf) {\n            if (g.pow(q).val()\
    \ == 1) {\n                is_ok = false;\n                break;\n          \
    \  }\n        }\n\n        if (is_ok) {\n            return g.val();\n       \
    \ }\n    }\n    return -1;\n}\n};  // namespace kyopro\n\n/**\n * @brief Primitive\
    \ Root(\u539F\u59CB\u6839)\n */\n#line 4 \"src/math/mod_sqrt.hpp\"\n\nnamespace\
    \ kyopro {\n/**\n * @brief \u5E73\u65B9\u5270\u4F59(O(\u221Ap))\n * @note \u9045\
    \u3044\n */\nconstexpr int mod_sqrt_lazy(int x, int p) {\n    if (x == 0) return\
    \ 0;\n    if (p == 2) return x;\n    int g = primitive_root(p);\n    int e = mod_log(g,\
    \ x, p);\n    if (e % 2 != 0) {\n        return -1;\n    } else {\n        return\
    \ mod_pow(g, e / 2, p);\n    }\n}\n};  // namespace kyopro\n#line 4 \"src/FormalPowerSeries/fps-sqrt.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief Sqrt of FPS\n */\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> fps_sqrt(const FormalPowerSeries<mint>& f,\n         \
    \                        int deg = -1LL) {\n    if (f.empty()) return FormalPowerSeries<mint>{};\n\
    \n    if (deg == -1) deg = f.size();\n\n    int g0 = mod_sqrt_lazy(f[0].val(),\
    \ mint::mod());\n\n    if (g0 == 0) {\n        for (int i = 1; i < (int)f.size();\
    \ ++i) {\n            if (f[i] == mint()) continue;\n\n            if (i & 1)\
    \ return FormalPowerSeries<mint>{};\n\n            FormalPowerSeries<mint> g =\
    \ fps_sqrt(\n                FormalPowerSeries<mint>{f.begin() + i, f.end()},\
    \ deg - i / 2);\n            if (g.empty()) return FormalPowerSeries<mint>{};\n\
    \            g.resize(g.size() + i / 2);\n            for (int j = g.size() -\
    \ 1; j >= i / 2; --j) g[j] = g[j - i / 2];\n            for (int j = 0; j < i\
    \ / 2; ++j) g[j] = 0;\n            if (g.size() < deg) g.resize(deg);\n\n    \
    \        return g;\n        }\n        return f;\n    }\n    if (g0 == -1) return\
    \ FormalPowerSeries<mint>{};\n\n    const mint inv2 = mint::raw(2).inv();\n\n\
    \    FormalPowerSeries<mint> g{mint::raw(g0)};\n\n    for (long long n = 1; n\
    \ < deg; n <<= 1) {\n        g = g + f.pref(2 * n) * g.inv(2 * n);\n        for\
    \ (int j = 0; j < (int)g.size(); ++j) g[j] *= inv2;\n    }\n\n    return g.pref(deg);\n\
    }\n};  // namespace kyopro\n"
  code: "#pragma once\n#include \"../FormalPowerSeries/FPS.hpp\"\n#include \"../math/mod_sqrt.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief Sqrt of FPS\n */\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> fps_sqrt(const FormalPowerSeries<mint>& f,\n         \
    \                        int deg = -1LL) {\n    if (f.empty()) return FormalPowerSeries<mint>{};\n\
    \n    if (deg == -1) deg = f.size();\n\n    int g0 = mod_sqrt_lazy(f[0].val(),\
    \ mint::mod());\n\n    if (g0 == 0) {\n        for (int i = 1; i < (int)f.size();\
    \ ++i) {\n            if (f[i] == mint()) continue;\n\n            if (i & 1)\
    \ return FormalPowerSeries<mint>{};\n\n            FormalPowerSeries<mint> g =\
    \ fps_sqrt(\n                FormalPowerSeries<mint>{f.begin() + i, f.end()},\
    \ deg - i / 2);\n            if (g.empty()) return FormalPowerSeries<mint>{};\n\
    \            g.resize(g.size() + i / 2);\n            for (int j = g.size() -\
    \ 1; j >= i / 2; --j) g[j] = g[j - i / 2];\n            for (int j = 0; j < i\
    \ / 2; ++j) g[j] = 0;\n            if (g.size() < deg) g.resize(deg);\n\n    \
    \        return g;\n        }\n        return f;\n    }\n    if (g0 == -1) return\
    \ FormalPowerSeries<mint>{};\n\n    const mint inv2 = mint::raw(2).inv();\n\n\
    \    FormalPowerSeries<mint> g{mint::raw(g0)};\n\n    for (long long n = 1; n\
    \ < deg; n <<= 1) {\n        g = g + f.pref(2 * n) * g.inv(2 * n);\n        for\
    \ (int j = 0; j < (int)g.size(); ++j) g[j] *= inv2;\n    }\n\n    return g.pref(deg);\n\
    }\n};  // namespace kyopro"
  dependsOn:
  - src/FormalPowerSeries/FPS.hpp
  - src/atcoder/convolution.hpp
  - src/atcoder/internal_bit.hpp
  - src/atcoder/modint.hpp
  - src/atcoder/internal_math.hpp
  - src/atcoder/internal_type_traits.hpp
  - src/math/mod_sqrt.hpp
  - src/math/mod_log.hpp
  - src/data-structure/hash_map.hpp
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  - src/internal/type_traits.hpp
  - src/math/primitive_root.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/math/rho.hpp
  - src/math/miller.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/FormalPowerSeries/fps-sqrt.hpp
  requiredBy: []
  timestamp: '2024-05-16 21:11:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
documentation_of: src/FormalPowerSeries/fps-sqrt.hpp
layout: document
redirect_from:
- /library/src/FormalPowerSeries/fps-sqrt.hpp
- /library/src/FormalPowerSeries/fps-sqrt.hpp.html
title: Sqrt of FPS
---
