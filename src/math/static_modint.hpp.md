---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Matrix Product.test.cpp
    title: test/yosupo_judge/matrix/Matrix Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/static_modint.md
    document_title: "\u9759\u7684modint"
    links: []
  bundledCode: "#line 2 \"src/math/static_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace internal {\n/*\n\
    \ * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\ntemplate\
    \ <typename... Args> struct first_enabled {};\n\ntemplate <typename T, typename...\
    \ Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n    using type\
    \ = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,\n               \
    \                  std::enable_if<dgt <= 16, __int16_t>,\n                   \
    \              std::enable_if<dgt <= 32, __int32_t>,\n                       \
    \          std::enable_if<dgt <= 64, __int64_t>,\n                           \
    \      std::enable_if<dgt <= 128, __int128_t> >;\n};\ntemplate <int dgt> struct\
    \ uint_least {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 3 \"src/math/gcd.hpp\"\
    \n#include <tuple>\nnamespace kyopro {\ntemplate <typename T> constexpr T inline\
    \ _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return\
    \ a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n \
    \   a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (!a || !b) {\n            return a + b;\n        }\n        if (a\
    \ >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n      \
    \  } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n    \
    \    }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T ext_gcd(T\
    \ a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while (b)\
    \ {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T, T>{b, a % b};\n\
    \        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n        std::tie(y,\
    \ ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return a;\n}\n};  // namespace\
    \ kyopro\n#line 6 \"src/math/static_modint.hpp\"\nnamespace kyopro {\ntemplate\
    \ <__uint64_t _mod> class static_modint : internal::modint_base {\nprivate:\n\
    \    using mint = static_modint<_mod>;\n    using i64 = long long;\n    using\
    \ u64 = unsigned long long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\
    \n    u64 v;\n    constexpr u64 normalize(i64 v_) const {\n        v_ %= _mod;\n\
    \        if (v_ < 0) {\n            v_ += _mod;\n        }\n        return v_;\n\
    \    }\n\npublic:\n    static constexpr u64 mod() { return _mod; }\n    constexpr\
    \ static_modint() : v(0) {}\n    constexpr static_modint(i64 v_) : v(normalize(v_))\
    \ {}\n\n    static mint raw(u64 a) {\n        mint m;\n        m.v = a;\n    \
    \    return m;\n    }\n    constexpr u64 val() const { return v; }\n    constexpr\
    \ mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v\
    \ >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n   \
    \ }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += _mod - rhs.val();\n\
    \        if (v >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u128)v\
    \ * rhs.val() % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(i64 rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(i64 l, const\
    \ mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend mint operator-(i64\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n\n    constexpr mint operator+(i64 r) { return mint(*this) += r; }\n \
    \   constexpr mint operator-(i64 r) { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(i64\
    \ r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const mint&\
    \ r) const {\n        return (*this).val() == r.val();\n    }\n\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n    constexpr mint inv() const {\n        long long\
    \ x, y;\n        auto d = ext_gcd((long long)_mod, (long long)v, x, y);\n    \
    \    assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint&\
    \ r) const { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, i64 r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(i64 l, const mint& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n\n    // stream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t _mod> class\
    \ static_modint32 : internal::modint_base {\nprivate:\n    using mint = static_modint32<_mod>;\n\
    \    using i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    constexpr u32 normalize(i64 v_)\
    \ const {\n        v_ %= _mod;\n        if (v_ < 0) {\n            v_ += _mod;\n\
    \        }\n        return v_;\n    }\n\npublic:\n    static constexpr u32 mod()\
    \ { return _mod; }\n    constexpr static_modint32() : v(0) {}\n    constexpr static_modint32(i64\
    \ v_) : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n        mint m;\n\
    \        m.v = a;\n        return m;\n    }\n    constexpr u32 val() const { return\
    \ v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n\
    \        if (v >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += _mod -\
    \ rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n        }\n  \
    \      return (*this);\n    }\n    constexpr mint& operator*=(const mint& rhs)\
    \ {\n        v = (u64)v * rhs.val() % _mod;\n        return (*this);\n    }\n\n\
    \    constexpr mint operator+(const mint& r) const { return mint(*this) += r;\
    \ }\n    constexpr mint operator-(const mint& r) const { return mint(*this) -=\
    \ r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(i64 rhs) {\n \
    \       (*this) -= mint(rhs);\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr friend mint operator+(i64 l, const mint& r) {\n        return\
    \ mint(l) += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint\
    \ operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n    template <typename T> constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n\n    constexpr mint inv() const {\n        long long x, y;\n        auto\
    \ d = ext_gcd((long long)_mod, (long long)v, x, y);\n        assert(d == 1);\n\
    \        return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint&\
    \ r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const mint&\
    \ r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr friend\
    \ mint operator/(const mint& l, i64 r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n\n    // stream\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    constexpr\
    \ friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n\
    \        is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <iostream>\n#include \"../internal/type_traits.hpp\"\
    \n#include \"../math/gcd.hpp\"\nnamespace kyopro {\ntemplate <__uint64_t _mod>\
    \ class static_modint : internal::modint_base {\nprivate:\n    using mint = static_modint<_mod>;\n\
    \    using i64 = long long;\n    using u64 = unsigned long long;\n    using u128\
    \ = __uint128_t;\n    using i128 = __int128_t;\n\n    u64 v;\n    constexpr u64\
    \ normalize(i64 v_) const {\n        v_ %= _mod;\n        if (v_ < 0) {\n    \
    \        v_ += _mod;\n        }\n        return v_;\n    }\n\npublic:\n    static\
    \ constexpr u64 mod() { return _mod; }\n    constexpr static_modint() : v(0) {}\n\
    \    constexpr static_modint(i64 v_) : v(normalize(v_)) {}\n\n    static mint\
    \ raw(u64 a) {\n        mint m;\n        m.v = a;\n        return m;\n    }\n\
    \    constexpr u64 val() const { return v; }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        v += rhs.val();\n        if (v >= _mod) {\n          \
    \  v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator-=(const mint& rhs) {\n        v += _mod - rhs.val();\n        if (v\
    \ >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n   \
    \ }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u128)v *\
    \ rhs.val() % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(i64 rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(i64 l, const\
    \ mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend mint operator-(i64\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n\n    constexpr mint operator+(i64 r) { return mint(*this) += r; }\n \
    \   constexpr mint operator-(i64 r) { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(i64\
    \ r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const mint&\
    \ r) const {\n        return (*this).val() == r.val();\n    }\n\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n    constexpr mint inv() const {\n        long long\
    \ x, y;\n        auto d = ext_gcd((long long)_mod, (long long)v, x, y);\n    \
    \    assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint&\
    \ r) const { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, i64 r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(i64 l, const mint& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n\n    // stream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t _mod> class\
    \ static_modint32 : internal::modint_base {\nprivate:\n    using mint = static_modint32<_mod>;\n\
    \    using i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    constexpr u32 normalize(i64 v_)\
    \ const {\n        v_ %= _mod;\n        if (v_ < 0) {\n            v_ += _mod;\n\
    \        }\n        return v_;\n    }\n\npublic:\n    static constexpr u32 mod()\
    \ { return _mod; }\n    constexpr static_modint32() : v(0) {}\n    constexpr static_modint32(i64\
    \ v_) : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n        mint m;\n\
    \        m.v = a;\n        return m;\n    }\n    constexpr u32 val() const { return\
    \ v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n\
    \        if (v >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += _mod -\
    \ rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n        }\n  \
    \      return (*this);\n    }\n    constexpr mint& operator*=(const mint& rhs)\
    \ {\n        v = (u64)v * rhs.val() % _mod;\n        return (*this);\n    }\n\n\
    \    constexpr mint operator+(const mint& r) const { return mint(*this) += r;\
    \ }\n    constexpr mint operator-(const mint& r) const { return mint(*this) -=\
    \ r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(i64 rhs) {\n \
    \       (*this) -= mint(rhs);\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr friend mint operator+(i64 l, const mint& r) {\n        return\
    \ mint(l) += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint\
    \ operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n    template <typename T> constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n\n    constexpr mint inv() const {\n        long long x, y;\n        auto\
    \ d = ext_gcd((long long)_mod, (long long)v, x, y);\n        assert(d == 1);\n\
    \        return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint&\
    \ r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const mint&\
    \ r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr friend\
    \ mint operator/(const mint& l, i64 r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n\n    // stream\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    constexpr\
    \ friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n\
    \        is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */"
  dependsOn:
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  isVerificationFile: false
  path: src/math/static_modint.hpp
  requiredBy: []
  timestamp: '2023-07-30 13:18:23+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  - test/yosupo_judge/matrix/Matrix Product.test.cpp
  - test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
documentation_of: src/math/static_modint.hpp
layout: document
redirect_from:
- /library/src/math/static_modint.hpp
- /library/src/math/static_modint.hpp.html
title: "\u9759\u7684modint"
---
