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
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
    title: test/yosupo_judge/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/FormalPowerSeries/BostanMori.md
    document_title: "Bostan-Mori\u6CD5(\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\
      \u8A08\u7B97)"
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
    \ Power Series(\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570)\n*/\n#line 2 \"src/internal/type_traits.hpp\"\
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
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 4\
    \ \"src/FormalPowerSeries/BostanMori.hpp\"\n\nnamespace kyopro {\n\ntemplate <typename\
    \ T,\n          internal::is_integral_t<T>* = nullptr,\n          typename mint,\n\
    \          atcoder::internal::is_modint_t<mint>* = nullptr>\nmint BostanMori(T\
    \ n,\n                const FormalPowerSeries<mint>& P,\n                const\
    \ FormalPowerSeries<mint>& Q) {\n    assert(n >= 0);\n    assert(!P.empty() &&\
    \ !Q.empty());\n\n    if (n == 0) return P[0] / Q[0];\n\n    FormalPowerSeries\
    \ Q2(Q);\n    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];\n\n\
    \    FormalPowerSeries V = Q * Q2;\n    for (int i = 0; 2 * i < (int)V.size();\
    \ ++i) {\n        V[i] = V[2 * i];\n    }\n    V.resize(V.size() / 2 + 1);\n\n\
    \    FormalPowerSeries PQ = P * Q2;\n\n    if (n % 2 == 0) {\n        FormalPowerSeries<mint>\
    \ E((PQ.size() + 1) / 2);\n        \n        for (int i = 0; i < (int)E.size();\
    \ ++i) {\n            E[i] = PQ[2 * i];\n        }\n\n        if(E.empty()) return\
    \ mint();\n\n        return BostanMori(n / 2, E, V);\n    } else {\n        FormalPowerSeries<mint>\
    \ O(PQ.size() / 2);\n\n        for (int i = 0; i < (int)O.size(); ++i) {\n   \
    \         O[i] = PQ[2 * i + 1];\n        }\n        \n        if(O.empty()) return\
    \ mint();\n\n        return BostanMori(n / 2, O, V);\n    }\n}\n\ntemplate <typename\
    \ T,\n          internal::is_integral_t<T>* = nullptr,\n          typename mint,\n\
    \          atcoder::internal::is_modint_t<mint>* = nullptr>\nmint NthTermOfLinearlyRecurrentSequence(T\
    \ n,\n                                const std::vector<mint>& ainit,\n      \
    \                          const std::vector<mint>& c) {\n    FormalPowerSeries<mint>\
    \ a =\n        FormalPowerSeries<mint>(ainit) * FormalPowerSeries<mint>(c);\n\
    \    \n    a.resize(ainit.size());\n    return BostanMori(n, a, FormalPowerSeries<mint>(c));\n\
    }\n};\n\n/**\n * @brief Bostan-Mori\u6CD5(\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\
    \u9AD8\u901F\u8A08\u7B97)\n * @docs docs/FormalPowerSeries/BostanMori.md\n */\n"
  code: "#pragma once\n#include\"../../src/FormalPowerSeries/FPS.hpp\"\n#include\"\
    ../../src/internal/type_traits.hpp\"\n\nnamespace kyopro {\n\ntemplate <typename\
    \ T,\n          internal::is_integral_t<T>* = nullptr,\n          typename mint,\n\
    \          atcoder::internal::is_modint_t<mint>* = nullptr>\nmint BostanMori(T\
    \ n,\n                const FormalPowerSeries<mint>& P,\n                const\
    \ FormalPowerSeries<mint>& Q) {\n    assert(n >= 0);\n    assert(!P.empty() &&\
    \ !Q.empty());\n\n    if (n == 0) return P[0] / Q[0];\n\n    FormalPowerSeries\
    \ Q2(Q);\n    for (int i = 1; i < (int)Q2.size(); i += 2) Q2[i] = -Q2[i];\n\n\
    \    FormalPowerSeries V = Q * Q2;\n    for (int i = 0; 2 * i < (int)V.size();\
    \ ++i) {\n        V[i] = V[2 * i];\n    }\n    V.resize(V.size() / 2 + 1);\n\n\
    \    FormalPowerSeries PQ = P * Q2;\n\n    if (n % 2 == 0) {\n        FormalPowerSeries<mint>\
    \ E((PQ.size() + 1) / 2);\n        \n        for (int i = 0; i < (int)E.size();\
    \ ++i) {\n            E[i] = PQ[2 * i];\n        }\n\n        if(E.empty()) return\
    \ mint();\n\n        return BostanMori(n / 2, E, V);\n    } else {\n        FormalPowerSeries<mint>\
    \ O(PQ.size() / 2);\n\n        for (int i = 0; i < (int)O.size(); ++i) {\n   \
    \         O[i] = PQ[2 * i + 1];\n        }\n        \n        if(O.empty()) return\
    \ mint();\n\n        return BostanMori(n / 2, O, V);\n    }\n}\n\ntemplate <typename\
    \ T,\n          internal::is_integral_t<T>* = nullptr,\n          typename mint,\n\
    \          atcoder::internal::is_modint_t<mint>* = nullptr>\nmint NthTermOfLinearlyRecurrentSequence(T\
    \ n,\n                                const std::vector<mint>& ainit,\n      \
    \                          const std::vector<mint>& c) {\n    FormalPowerSeries<mint>\
    \ a =\n        FormalPowerSeries<mint>(ainit) * FormalPowerSeries<mint>(c);\n\
    \    \n    a.resize(ainit.size());\n    return BostanMori(n, a, FormalPowerSeries<mint>(c));\n\
    }\n};\n\n/**\n * @brief Bostan-Mori\u6CD5(\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\
    \u9AD8\u901F\u8A08\u7B97)\n * @docs docs/FormalPowerSeries/BostanMori.md\n */"
  dependsOn:
  - src/FormalPowerSeries/FPS.hpp
  - src/atcoder/convolution.hpp
  - src/atcoder/internal_bit.hpp
  - src/atcoder/modint.hpp
  - src/atcoder/internal_math.hpp
  - src/atcoder/internal_type_traits.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: false
  path: src/FormalPowerSeries/BostanMori.hpp
  requiredBy: []
  timestamp: '2024-06-18 21:26:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Kth_term_of_Linearly_Recurrent_Sequence.test.cpp
documentation_of: src/FormalPowerSeries/BostanMori.hpp
layout: document
redirect_from:
- /library/src/FormalPowerSeries/BostanMori.hpp
- /library/src/FormalPowerSeries/BostanMori.hpp.html
title: "Bostan-Mori\u6CD5(\u7DDA\u5F62\u6F38\u5316\u5F0F\u306E\u9AD8\u901F\u8A08\u7B97\
  )"
---

## 概要

- <https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a>
- <https://hitonanode.github.io/cplib-cpp/formal_power_series/coeff_of_rational_function.hpp.html>

全てこちらを元にしています.

数列 $a_0,a_1,a_2\dots$ に対し, 以下の条件を満たす定数 $c_0,c_1,c_2,\cdots,c_d$ が存在するならば, $(a_i)$ は **線形漸化的** であるといいます.

$$\forall n\geq d : c_0a_n+c_1a_{n-1}+\cdots+a_{n-k}c_k=0$$

線形漸化的な数列 $(a_i)$ に対して

- $a_0,a_1,\dots,a_{d-1}$
- $c_0,c_1,\dots,c_d$

が与えられたとき, このライブラリでは $a_N$ の値を $O(d\log d\log N)$ 時間で求めます.

## BostanMori

```cpp
BostanMori(n, P, Q)
```

高々 $d$ 次の多項式 $P(x),Q(x)$ に対して, [Bostan-Mori法](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a) を用いて $\displaystyle[x^N]\frac{P(x)}{Q(x)}$ を計算します.

$P,Q$ は[FormalPowerSeries](https://ac2-k.github.io/Library/src/FormalPowerSeries/FPS.hpp)として渡してください.

### 計算量

- $O(d\log d\log N)$
- ただし $\deg P,\deg Q\leq d$

### 制約

- $N\geq 0$

## NthTermOfLinearlyRecurrentSequence

```cpp
NthTermOfLinearlyRecurrentSequence(n, ainit, c)
```

線形漸化的な数列 $(a_i)$ に対して

- 非負整数 $N$(=`n`)
- $a$ の先頭 $d$ 項(=`ainit`)
- $c_0,c_1,\dots,c_d$=(`c`)

が与えられたとき, $a_N$ の値を返します.

`a`, `c` は`std::vector<atcodr::modint>`として渡してください.

### 計算量

- $O(d\log d\log N)$

### 制約

- $N\geq 0$
- $\forall n\geq d:\displaystyle \sum_{i=0}^{k}{c_ia_{n-i}}=0$

## 線形漸化的数列の第 $N$ 項の計算

備忘録として残しておく.

$(a_i)$ と定数 $c_0,c_1,c_2\dots,c_d$ について以下が成り立っているとする.

$$ \forall n\geq d:\sum_{i=0}^{d}{c_ia_{n-i}}=0$$

ここで, 数列 $(a_i)$ の母関数 $\displaystyle A(x)=\sum_{i=0}^{\infty}{a_ix^i}$ を考える. すると $a_{n-i}=[x^{n-i}]A(x)=[x^n]\left(x^iA(x)\right)$ となる. したがって上の式は以下のようになる.

$$
\begin{aligned}
\forall n\geq d&:\sum_{i=0}^{d}{c_ia_{n-i}}&=0\\
\iff \forall n\geq d&:\sum_{i=0}^{d}{c_i[x^n]\left(x^iA(x)\right)}&=0\\
\iff \forall n\geq d&:[x^n]\left(A(x)\sum_{i=0}^{d}{c_ix^i}\right)&=0
\end{aligned}
$$

これはすなわち形式的べき級数 $\displaystyle \left(A(x)\sum_{i=0}^{d}{c_ix^i}\right)$ が $d$ 次未満の多項式として表せるということ. よってこの多項式を $P(x)$ とすると以下が成り立つ.

$$
A(x)\sum_{i=0}^{d}{c_ix^i}=P(x)
$$

よって $\displaystyle Q(x)=\sum_{i=0}^{d}{c_ix^i}$ とすると $A(x)Q(x)=P(x)$ が成り立ち $\displaystyle A(x)=\frac{P(x)}{Q(x)}$ と表すことができた.

$$a_N=[x^N]A(x)=[x^N]\frac{P(x)}{Q(x)}$$

であり $\displaystyle [x^N]\frac{P(x)}{Q(x)}$ について

- $Q(x)$ :\
    与えられる $c_0,c_1,c_2\dots,c_d$ から $O(d)$ 時間で容易に得られる.

- $P(x)$ :\
    $P$ は $d$ 次未満の多項式であるから, $\displaystyle \sum_{i=0}^{d-1}{a_ix^i}$ と $Q(x)$ を畳み込むことにより $O(\mathrm{M}(d))$ 時間で求まる.

- $\displaystyle [x^N]\frac{P(x)}{Q(x)}$ :\
    $P,Q$ からBostan-Mori法 により$O(\mathrm{M}(d)\log N)$ 時間で計算可能.

ただし, $\mathrm{M}(d)$ は $d$ 次未満の多項式を畳み込むのにかかる時間計算量.

以上により, $a_N$ の値を $O(\mathrm{M}(d)\log N)$ 時間で求めることができる.

このライブラリでは畳み込みの計算に`atcoder::convolution`を用いているので $M(d)=O(d\log d)$ である.

### 変形

実装の簡単のため $\displaystyle \sum_{i=0}^{d}{c_ia_{n-i}}=0$ という定義を用いたが, 移項して整理することで, よく用いられる $\displaystyle a_n=\sum_{i=1}^{d}{{c_{d}}{a_{n-d}}}$ という形にも帰着することができる.