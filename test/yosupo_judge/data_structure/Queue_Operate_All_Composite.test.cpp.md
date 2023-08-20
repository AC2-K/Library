---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/SWAG.hpp
    title: Slide Window Aggrigation
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#line 2 \"src/data-structure/SWAG.hpp\"\n#include <algorithm>\n#include <vector>\n\
    namespace kyopro {\n/**\n * @brief Slide Window Aggrigation\n */\ntemplate <class\
    \ S, auto op, auto e> class SWAG {\n    std::vector<S> front_stack, back_stack;\n\
    \    std::vector<S> front_prod, back_prod;\n\npublic:\n    constexpr explicit\
    \ SWAG() {\n        front_prod.emplace_back(e()), back_prod.emplace_back(e());\n\
    \    }\n    void reserve(size_t sz) {\n        back_stack.reserve(sz), back_prod.reserve(sz\
    \ + 1);\n    }\n    void push(const S& x) {\n        back_stack.emplace_back(x);\n\
    \        back_prod.emplace_back(op(back_prod.back(), x));\n    }\n    void pop_back()\
    \ { back_stack.pop_back(), back_prod.pop_back(); }\n    void pop_front() {\n \
    \       if (front_stack.empty()) {\n            std::reverse(back_stack.begin(),\
    \ back_stack.end());\n            std::swap(front_stack, back_stack);\n      \
    \      back_prod.clear(), front_prod.clear();\n            back_prod.emplace_back(e());\n\
    \            front_prod.resize(front_stack.size() + 1);\n            front_prod[0]\
    \ = e();\n            for (int i = 0; i < (int)front_stack.size(); ++i) {\n  \
    \              front_prod[i + 1] = op(front_stack[i], front_prod[i]);\n      \
    \      }\n        }\n        front_prod.pop_back(), front_stack.pop_back();\n\
    \    }\n\n    S fold() const { return op(front_prod.back(), back_prod.back());\
    \ }\n    int size() { return front_stack.size() + back_stack.size(); }\n};\n};\
    \  // namespace kyopro\n\n/**\n * @docs docs/data-structure/SWAG.md\n*/\n#line\
    \ 2 \"src/math/static_modint.hpp\"\n#include <cassert>\n#include <iostream>\n\
    #line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include <numeric>\n\
    #include <typeinfo>\nnamespace kyopro {\nnamespace internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\
    \ using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt> using\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
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
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n// read\nvoid single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\n#define rep(i, N) for (int i = 0; i < (N); i++)\n\
    #define all(x) std::begin(x), std::end(x)\n#define popcount(x) __builtin_popcountll(x)\n\
    using i128 = __int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max()\
    \ / 2;\nconstexpr ld eps = 1e-12;\nconst long double pi = acosl(-1);\nconstexpr\
    \ uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int\
    \ dx[] = {1, 0, -1, 0, 1, -1, -1, 1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1,\
    \ -1, -1};\ntemplate <typename T1, typename T2> constexpr inline bool chmax(T1&\
    \ a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename T1, typename\
    \ T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a > b && (a = b,\
    \ true);\n}\n#line 7 \"test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp\"\
    \nusing mint = kyopro::static_modint32<MOD2>;\nusing Affine = std::pair<mint,\
    \ mint>;\nconstexpr inline Affine op(const Affine& g, const Affine& f) {\n   \
    \ auto a = f.first, b = f.second;\n    auto c = g.first, d = g.second;\n    return\
    \ Affine(a * c, a * d + b);\n}\nconstexpr inline Affine e() { return Affine(1,\
    \ 0); }\nint main() {\n    kyopro::SWAG<Affine, op, e> que;\n    int q;\n    kyopro::read(q);\n\
    \    while (q--) {\n        int t;\n        kyopro::read(t);\n\n        if (t\
    \ == 0) {\n            mint a, b;\n            kyopro::read(a, b);\n         \
    \   que.push(Affine(a, b));\n        } else if (t == 1) {\n            que.pop_front();\n\
    \        } else {\n            mint x;\n            kyopro::read(x);\n       \
    \     Affine res = que.fold();\n            kyopro::put((res.first * x + res.second).val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../../src/data-structure/SWAG.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\
    \nusing mint = kyopro::static_modint32<MOD2>;\nusing Affine = std::pair<mint,\
    \ mint>;\nconstexpr inline Affine op(const Affine& g, const Affine& f) {\n   \
    \ auto a = f.first, b = f.second;\n    auto c = g.first, d = g.second;\n    return\
    \ Affine(a * c, a * d + b);\n}\nconstexpr inline Affine e() { return Affine(1,\
    \ 0); }\nint main() {\n    kyopro::SWAG<Affine, op, e> que;\n    int q;\n    kyopro::read(q);\n\
    \    while (q--) {\n        int t;\n        kyopro::read(t);\n\n        if (t\
    \ == 0) {\n            mint a, b;\n            kyopro::read(a, b);\n         \
    \   que.push(Affine(a, b));\n        } else if (t == 1) {\n            que.pop_front();\n\
    \        } else {\n            mint x;\n            kyopro::read(x);\n       \
    \     Affine res = que.fold();\n            kyopro::put((res.first * x + res.second).val());\n\
    \        }\n    }\n}"
  dependsOn:
  - src/data-structure/SWAG.hpp
  - src/math/static_modint.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-08-18 11:55:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
- /verify/test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp.html
title: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
---