---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/dual_segtree.hpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    #line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nnamespace kyopro {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam id F \u306E\u5358\u4F4D\
    \u5143\n */\ntemplate <class F, F (*composition)(F, F), F (*id)()> class dual_segtree\
    \ {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\npublic:\n    dual_segtree()\
    \ {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while\
    \ (sz < _n) {\n            ++lg;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\nprivate:\n    void update(int p, const F& v) { dat[p]\
    \ = composition(dat[p], v); }\n    void push(int p) {\n        if (dat[p] == id())\
    \ {\n            return;\n        }\n        update(p << 1 | 0, dat[p]);\n   \
    \     update(p << 1 | 1, dat[p]);\n        dat[p] = id();\n    }\n\npublic:\n\
    \    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\n        F res\
    \ = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--) {\n      \
    \      push(p >> i);\n        }\n        return dat[p];\n    }\n\n    void apply(int\
    \ l, int r, const F& v) {\n        assert(0 <= l && l <= r && r <= _n);\n    \
    \    if (l == r) return;\n        l += sz, r += sz;\n        for (int i = lg;\
    \ i > 0; i--) {\n            if (((l >> i) << i) != l) {\n                push(l\
    \ >> i);\n            }\n            if (((r >> i) << i) != r) {\n           \
    \     push((r - 1) >> i);\n            }\n        }\n        while (l < r) {\n\
    \            if (l & 1) {\n                update(l++, v);\n            }\n  \
    \          if (r & 1) {\n                update(--r, v);\n            }\n    \
    \        l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  // namespace kyopro\n\n\
    /**\n * @docs docs/data-structure/dual_segtree.md\n */\n#line 3 \"src/math/static_modint.hpp\"\
    \n#include <iostream>\n#line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace\
    \ kyopro {\ntemplate <typename T> constexpr T inline _gcd(T a, T b) {\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 5 \"src/math/static_modint.hpp\"\nnamespace\
    \ kyopro {\ntemplate <__uint64_t mod> class static_modint {\nprivate:\n    using\
    \ mint = static_modint<mod>;\n    using i64 = long long;\n    using u64 = unsigned\
    \ long long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\n\
    \    u64 v;\n    constexpr u64 normalize(i64 v_) const {\n        v_ %= mod;\n\
    \        if (v_ < 0) {\n            v_ += mod;\n        }\n        return v_;\n\
    \    }\n\npublic:\n    constexpr static_modint() : v(0) {}\n    constexpr static_modint(i64\
    \ v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr u64 val() const\
    \ { return v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v\
    \ += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n        }\n \
    \       return (*this);\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        v += mod - rhs.val();\n        if (v >= mod) {\n            v -=\
    \ mod;\n        }\n        return (*this);\n    }\n    constexpr mint& operator*=(const\
    \ mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n        return (*this);\n\
    \    }\n\n    constexpr mint operator+(const mint& r) const { return mint(*this)\
    \ += r; }\n    constexpr mint operator-(const mint& r) const { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(i64 rhs) {\n \
    \       (*this) -= mint(rhs);\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr friend mint operator+(i64 l, const mint& r) {\n        return\
    \ mint(l) += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n\n    template <typename T> constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n    constexpr mint inv() const {\n        long long x, y;\n        auto\
    \ d = ext_gcd((long long)mod, (long long)v, x, y);\n        assert(d == 1);\n\
    \        return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint&\
    \ r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint& r) const\
    \ { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, i64 r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(i64 l, const mint& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n\n    // stream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t mod> class\
    \ static_modint32 {\nprivate:\n    using mint = static_modint32<mod>;\n    using\
    \ i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    constexpr u32 normalize(i64 v_)\
    \ const {\n        v_ %= mod;\n        if (v_ < 0) {\n            v_ += mod;\n\
    \        }\n        return v_;\n    }\n\npublic:\n    constexpr static_modint32()\
    \ : v(0) {}\n    constexpr static_modint32(i64 v_) : v(normalize(v_)) {}\n\n \
    \   // operator\n    static mint raw(u32 a) {\n        mint m;\n        m.v =\
    \ a;\n        return m;\n    }\n    constexpr u32 val() const { return v; }\n\
    \    constexpr mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += mod -\
    \ rhs.val();\n        if (v >= mod) {\n            v -= mod;\n        }\n    \
    \    return (*this);\n    }\n    constexpr mint& operator*=(const mint& rhs) {\n\
    \        v = (u64)v * rhs.val() % mod;\n        return (*this);\n    }\n\n   \
    \ constexpr mint operator+(const mint& r) const { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const { return mint(*this) -= r;\
    \ }\n    constexpr mint operator*(const mint& r) const { return mint(*this) *=\
    \ r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
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
    \ d = ext_gcd((long long)mod, (long long)v, x, y);\n        assert(d == 1);\n\
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
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\nnamespace\
    \ kyopro {\ntemplate <typename T> constexpr inline void readint(T& a) {\n    a\
    \ = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n    while\
    \ (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c == '-') is_negative\
    \ = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 *\
    \ a + (c - '0');\n        c = getchar_unlocked();\n    }\n    if (is_negative)\
    \ a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void\
    \ readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line 5 \"test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp\"\
    \n\nusing mint = kyopro::static_modint32<998244353>;\nusing Affine = std::pair<mint,\
    \ mint>;\ninline Affine op(Affine g, Affine f) {\n    auto a = f.first, b = f.second;\n\
    \    auto c = g.first, d = g.second;\n    return Affine(a * c, a * d + b);\n}\n\
    inline Affine e() { return Affine(1, 0); }\nint main() {\n    int n, q;\n    kyopro::readint(n,\
    \ q);\n    kyopro::dual_segtree<Affine, op, e> sg(n);\n    std::vector<mint> a(n);\n\
    \    for (auto& aa : a) {\n        kyopro::readint(aa);\n    }\n    while (q--)\
    \ {\n        int t;\n        kyopro::readint(t);\n\n        if (!t) {\n      \
    \      int l, r;\n            mint b, c;\n            kyopro::readint(l, r, b,\
    \ c);\n            sg.apply(l, r, std::pair<mint, mint>(b, c));\n        } else\
    \ {\n            int i;\n            kyopro::readint(i);\n            auto f =\
    \ sg[i];\n            mint ans = f.first * a[i] + f.second;\n            kyopro::putint(ans.val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include \"../../../src/data-structure/dual_segtree.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n\nusing mint = kyopro::static_modint32<998244353>;\n\
    using Affine = std::pair<mint, mint>;\ninline Affine op(Affine g, Affine f) {\n\
    \    auto a = f.first, b = f.second;\n    auto c = g.first, d = g.second;\n  \
    \  return Affine(a * c, a * d + b);\n}\ninline Affine e() { return Affine(1, 0);\
    \ }\nint main() {\n    int n, q;\n    kyopro::readint(n, q);\n    kyopro::dual_segtree<Affine,\
    \ op, e> sg(n);\n    std::vector<mint> a(n);\n    for (auto& aa : a) {\n     \
    \   kyopro::readint(aa);\n    }\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n\
    \n        if (!t) {\n            int l, r;\n            mint b, c;\n         \
    \   kyopro::readint(l, r, b, c);\n            sg.apply(l, r, std::pair<mint, mint>(b,\
    \ c));\n        } else {\n            int i;\n            kyopro::readint(i);\n\
    \            auto f = sg[i];\n            mint ans = f.first * a[i] + f.second;\n\
    \            kyopro::putint(ans.val());\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/dual_segtree.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 10:09:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
---
