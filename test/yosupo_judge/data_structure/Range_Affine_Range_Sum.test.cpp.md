---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include<iostream>\n#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n/// @brief Segment Tree with\
    \ Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\ntemplate <class S,\n          class F,\n          S (*op)(S, S),\n        \
    \  S (*e)(),\n          F (*comp)(F, F),\n          F (*id)(),\n          S (*mapping)(S,\
    \ F)>\nclass lazy_segtree {\n    int sz;\n    std::vector<S> dat;\n    std::vector<F>\
    \ lz;\n\npublic:\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e()))\
    \ {}\n    lazy_segtree(const std::vector<S>& a)\n        : dat(4 * a.size(), e()),\
    \ lz(4 * a.size(), id()) {\n        int x = 1;\n        while (a.size() > x) {\n\
    \            x <<= 1;\n        }\n        sz = x;\n        for (int i = 0; i <\
    \ a.size(); i++) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\n\npublic:\n    inline void set(int pos, S x) {\n        assert(0 <= pos\
    \ && pos < sz);\n        dat[pos + sz - 1] = x;\n    }\n    inline void build()\
    \ {\n        for (int i = sz - 2; i >= 0; i--) {\n            dat[i] = op(dat[2\
    \ * i + 1], dat[2 * i + 2]);\n        }\n    }\n\nprivate:\n    void eval(int\
    \ pos) {\n        if (lz[pos] == id()) return;\n        if (pos < sz - 1) {\n\
    \            lz[2 * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n            lz[2\
    \ * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);\n        }\n        dat[pos] =\
    \ mapping(dat[pos], lz[pos]);\n        lz[pos] = id();\n    }\n\nprivate:\n  \
    \  void internal_apply(int L, int R, int l, int r, const F& x, int k) {\n    \
    \    eval(k);\n        if (L <= l && r <= R) {\n            lz[k] = comp(lz[k],\
    \ x);\n            eval(k);\n        } else if (L < r && l < R) {\n          \
    \  int mid = (l + r) >> 1;\n            internal_apply(L, R, l, mid, x, 2 * k\
    \ + 1);\n            internal_apply(L, R, mid, r, x, 2 * k + 2);\n           \
    \ dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n    }\n\npublic:\n\
    \    inline void apply(int l, int r, const F& x) {\n        assert(0 <= l && l\
    \ <= r && r <= sz);\n        internal_apply(l, r, 0, sz, x, 0);\n    }\n\nprivate:\n\
    \    S internal_prod(int L, int R, int l, int r, int k) {\n        eval(k);\n\
    \        if (r <= L || R <= l) {\n            return e();\n        } else if (L\
    \ <= l && r <= R) {\n            return dat[k];\n        } else {\n          \
    \  int mid = (l + r) >> 1;\n            S vl = internal_prod(L, R, l, mid, 2 *\
    \ k + 1);\n            S vr = internal_prod(L, R, mid, r, 2 * k + 2);\n      \
    \      return op(vl, vr);\n        }\n    }\n\npublic:\n    inline S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= sz);\n        return internal_prod(l,\
    \ r, 0, sz, 0);\n    }\n\n    inline S operator[](int pos) { return prod(pos,\
    \ pos + 1); }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/lazy_segtree.md\n\
    #line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate <typename\
    \ T> constexpr T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a ==\
    \ 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
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
    \    u64 v;\n    constexpr inline u64 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint() : v(0) {}\n    constexpr\
    \ static_modint(const i64& v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr\
    \ u64 val() const { return v; }\n    constexpr mint& operator+=(const mint& rhs)\
    \ {\n        v += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n\
    \        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        v += mod - rhs.val();\n        if (v >= mod) {\n     \
    \       v -= mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n    \
    \    return (*this);\n    }\n\n    constexpr mint operator+(const mint& r) const\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const mint& r) const\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const i64& rhs)\
    \ {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n        return\
    \ (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs) {\n        (*this)\
    \ *= mint(rhs);\n        return (*this);\n    }\n    constexpr friend mint operator+(const\
    \ i64& l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr\
    \ friend mint operator-(const i64& l, const mint& r) {\n        return mint(l)\
    \ -= r;\n    }\n    constexpr friend mint operator*(const i64& l, const mint&\
    \ r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+(const\
    \ i64& r) { return mint(*this) += r; }\n    constexpr mint operator-(const i64&\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(const i64& r)\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator=(const i64& r)\
    \ { return (*this) = mint(r); }\n\n    constexpr bool operator==(const mint& r)\
    \ const {\n        return (*this).val() == r.val();\n    }\n\n    template <typename\
    \ T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n    \
    \    while (e) {\n            if (e & 1) {\n                ans *= base;\n   \
    \         }\n            base *= base;\n            e >>= 1;\n        }\n    \
    \    return ans;\n    }\n    constexpr inline mint inv() const {\n        long\
    \ long x, y;\n        auto d = ext_gcd((long long)mod, (long long)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint&\
    \ operator/=(const mint& r) { return (*this) *= r.inv(); }\n    constexpr mint\
    \ inv(const mint& r) const { return mint(*this) *= r.inv(); }\n    constexpr friend\
    \ mint operator/(const mint& l, const i64& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(const i64& l, const mint& r) {\n \
    \       return mint(l) /= mint(r);\n    }\n\n    // iostream\n    constexpr friend\
    \ std::ostream& operator<<(std::ostream& os,\n                               \
    \               const mint& mt) {\n        os << mt.val();\n        return os;\n\
    \    }\n    constexpr friend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n        return\
    \ is;\n    }\n};\ntemplate <__uint32_t mod> class static_modint32 {\nprivate:\n\
    \    using mint = static_modint32<mod>;\n    using i32 = __int32_t;\n    using\
    \ u32 = __uint32_t;\n    using i64 = __int64_t;\n    using u64 = __uint64_t;\n\
    \n    u32 v;\n    constexpr inline u32 normalize(i64 v_) const {\n        v_ %=\
    \ mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n        return\
    \ v_;\n    }\n\npublic:\n    constexpr static_modint32() : v(0) {}\n    constexpr\
    \ static_modint32(const i64& v_) : v(normalize(v_)) {}\n\n    // operator\n  \
    \  constexpr u64 val() const { return (u64)v; }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        v += rhs.val();\n        if (v >= mod) {\n           \
    \ v -= mod;\n        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        v += mod - rhs.val();\n        if (v >= mod) {\n     \
    \       v -= mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(const mint& rhs) {\n        v = (u64)v * rhs.val() % mod;\n     \
    \   return (*this);\n    }\n\n    constexpr mint operator+(const mint& r) const\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const mint& r) const\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const i64& rhs)\
    \ {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n        return\
    \ (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs) {\n        (*this)\
    \ *= mint(rhs);\n        return (*this);\n    }\n    constexpr friend mint operator+(const\
    \ i64& l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr\
    \ friend mint operator-(const i64& l, const mint& r) {\n        return mint(l)\
    \ -= r;\n    }\n    constexpr friend mint operator*(const i64& l, const mint&\
    \ r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+(const\
    \ i64& r) { return mint(*this) += r; }\n    constexpr mint operator-(const i64&\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(const i64& r)\
    \ { return mint(*this) *= r; }\n\n    constexpr mint& operator=(const i64& r)\
    \ { return (*this) = mint(r); }\n\n    constexpr bool operator==(const mint& r)\
    \ const {\n        return (*this).val() == r.val();\n    }\n    template <typename\
    \ T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n    \
    \    while (e) {\n            if (e & 1) {\n                ans *= base;\n   \
    \         }\n            base *= base;\n            e >>= 1;\n        }\n    \
    \    return ans;\n    }\n\n    constexpr inline mint inv() const {\n        long\
    \ long x, y;\n        auto d = ext_gcd((long long)mod, (long long)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint&\
    \ operator/=(const mint& r) { return (*this) *= r.inv(); }\n    constexpr mint\
    \ operator/(const mint& r) const {\n        return mint(*this) *= r.inv();\n \
    \   }\n    constexpr friend mint operator/(const mint& l, const i64& r) {\n  \
    \      return mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(const\
    \ i64& l, const mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    //\
    \ iostream\n    constexpr friend std::ostream& operator<<(std::ostream& os,\n\
    \                                              const mint& mt) {\n        os <<\
    \ mt.val();\n        return os;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n};\n};  // namespace kyopro\n\n/// @brief static modint(\u9759\
    \u7684modint)\n/// @docs docs/math/static_modint.md\n#line 5 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \nusing mint = kyopro::static_modint32<998244353>;\nstruct S {\n    mint s;\n\
    \    int len;\n};\ninline S op(S a, S b) { return S{a.s + b.s, a.len + b.len};\
    \ }\ninline S e() { return S{0, 0}; }\nusing Affine = std::pair<mint, mint>;\n\
    inline Affine composition(Affine g, Affine f) {\n\t//f(g)\n\t//a(cx+d)+b\n\tauto\
    \ a = f.first, b = f.second;\n\tauto c = g.first, d = g.second;\n\treturn Affine(a\
    \ * c, a * d + b);\n}\ninline Affine id() { return Affine(1, 0); }\ninline S mapping(S\
    \ d, Affine f) {\n    mint a = f.first, b = f.second;\n    d.s *= a, d.s += b\
    \ * d.len;\n    return d;\n};\n\nint main(){\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int n, q;\n    std::cin >> n >> q;\n    kyopro::lazy_segtree<S,\
    \ Affine, op, e, composition, id, mapping> sg(n);\n    for(int i=0;i<n;i++){\n\
    \        mint a;\n        std::cin >> a;\n        sg.set(i, {a, 1});\n    }\n\
    \    sg.build();\n    while(q--){\n        int t;\n        std::cin >> t;\n  \
    \      if (t == 0) {\n            int l, r;\n            mint b, c;\n        \
    \    std::cin >> l >> r >> b >> c;\n            sg.apply(l, r, Affine(b, c));\n\
    \        } else {\n            int l, r;\n            std::cin >> l >> r;\n  \
    \          auto res = sg.prod(l, r);\n            std::cout << res.s << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include<iostream>\n#include\"../../../src/data-structure/lazy_segtree.hpp\"\
    \n#include\"../../../src/math/static_modint.hpp\"\nusing mint = kyopro::static_modint32<998244353>;\n\
    struct S {\n    mint s;\n    int len;\n};\ninline S op(S a, S b) { return S{a.s\
    \ + b.s, a.len + b.len}; }\ninline S e() { return S{0, 0}; }\nusing Affine = std::pair<mint,\
    \ mint>;\ninline Affine composition(Affine g, Affine f) {\n\t//f(g)\n\t//a(cx+d)+b\n\
    \tauto a = f.first, b = f.second;\n\tauto c = g.first, d = g.second;\n\treturn\
    \ Affine(a * c, a * d + b);\n}\ninline Affine id() { return Affine(1, 0); }\n\
    inline S mapping(S d, Affine f) {\n    mint a = f.first, b = f.second;\n    d.s\
    \ *= a, d.s += b * d.len;\n    return d;\n};\n\nint main(){\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int n, q;\n    std::cin >> n >> q;\n    kyopro::lazy_segtree<S,\
    \ Affine, op, e, composition, id, mapping> sg(n);\n    for(int i=0;i<n;i++){\n\
    \        mint a;\n        std::cin >> a;\n        sg.set(i, {a, 1});\n    }\n\
    \    sg.build();\n    while(q--){\n        int t;\n        std::cin >> t;\n  \
    \      if (t == 0) {\n            int l, r;\n            mint b, c;\n        \
    \    std::cin >> l >> r >> b >> c;\n            sg.apply(l, r, Affine(b, c));\n\
    \        } else {\n            int l, r;\n            std::cin >> l >> r;\n  \
    \          auto res = sg.prod(l, r);\n            std::cout << res.s << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 13:24:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
---