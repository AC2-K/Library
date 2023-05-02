---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<iostream>\n#line 2 \"src/data-structure/segtree.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nclass segtree {\n    int lg,\
    \ sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree() {}\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>& vec)\
    \ : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n) {\n\
    \            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    void set(int p, const S& v) { dat[sz\
    \ + p] = v; }\n    void build() {\n        for (int i = sz - 1; i > 0; i--) {\n\
    \            dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n        }\n    }\n\
    \    S operator[](int p) const { return dat[sz + p]; }\n\n    void update(int\
    \ p, const S& v) {\n        p += sz;\n        dat[p] = v;\n        while (p >>=\
    \ 1) {\n            dat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n        }\n\
    \    }\n\n    S prod(int l, int r) const {\n        if (l == 0 && r == n) {\n\
    \            return dat[1];\n        }\n        l += sz, r += sz;\n        S sml\
    \ = e(), smr = e();\n        while (l != r) {\n            if (l & 1) sml = op(sml,\
    \ dat[l++]);\n            if (r & 1) smr = op(dat[--r], smr);\n            l >>=\
    \ 1, r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    void apply(int\
    \ p, const S& v) { update(p, op(dat[sz + p], v)); }\n};\n};  // namespace kyopro\n\
    \n/// @docs docs/data-structure/segtree.md\n#line 2 \"src/math/static_modint.hpp\"\
    \n#include <cassert>\n#line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace\
    \ kyopro {\ntemplate <typename T>\nconstexpr T inline _gcd(T a, T b) {\n    assert(a\
    \ >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a||!b) {\n            return a + b;\n    \
    \    }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T>\nconstexpr T\
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
    \ static_modint(i64 v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr\
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
    \ r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint operator+(i64\
    \ r) { return mint(*this) += r; }\n    constexpr mint operator-(i64 r) { return\
    \ mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this) = mint(r);\
    \ }\n\n    constexpr bool operator==(const mint& r) const {\n        return (*this).val()\
    \ == r.val();\n    }\n\n    template <typename T> constexpr mint pow(T e) const\
    \ {\n        mint ans(1), base(*this);\n        while (e) {\n            if (e\
    \ & 1) {\n                ans *= base;\n            }\n            base *= base;\n\
    \            e >>= 1;\n        }\n        return ans;\n    }\n    constexpr inline\
    \ mint inv() const {\n        long long x, y;\n        auto d = ext_gcd((long\
    \ long)mod, (long long)v, x, y);\n        assert(d == 1);\n        return mint(y);\n\
    \    }\n\n    constexpr mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    constexpr mint inv(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    constexpr friend mint operator/(const mint& l, i64 r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(i64 l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // iostream\n \
    \   constexpr friend std::ostream& operator<<(std::ostream& os,\n            \
    \                                  const mint& mt) {\n        os << mt.val();\n\
    \        return os;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n};\ntemplate <__uint32_t mod> class static_modint32 {\n\
    private:\n    using mint = static_modint32<mod>;\n    using i32 = __int32_t;\n\
    \    using u32 = __uint32_t;\n    using i64 = __int64_t;\n    using u64 = __uint64_t;\n\
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
    \ friend mint operator-(i64 l, const mint& r) {\n        return mint(l) -= r;\n\
    \    }\n    constexpr friend mint operator*(i64 l, const mint& r) {\n        return\
    \ mint(l) *= r;\n    }\n\n    constexpr mint operator+(i64 r) { return mint(*this)\
    \ += r; }\n    constexpr mint operator-(i64 r) { return mint(*this) -= r; }\n\
    \    constexpr mint operator*(i64 r) { return mint(*this) *= r; }\n\n    constexpr\
    \ mint& operator=(i64 r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const\
    \ mint& r) const {\n        return (*this).val() == r.val();\n    }\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n\n    constexpr inline mint inv() const {\n      \
    \  long long x, y;\n        auto d = ext_gcd((long long)mod, (long long)v, x,\
    \ y);\n        assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr\
    \ mint& operator/=(const mint& r) { return (*this) *= r.inv(); }\n    constexpr\
    \ mint operator/(const mint& r) const {\n        return mint(*this) *= r.inv();\n\
    \    }\n    constexpr friend mint operator/(const mint& l, i64 r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(i64 l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // iostream\n \
    \   constexpr friend std::ostream& operator<<(std::ostream& os,\n            \
    \                                  const mint& mt) {\n        os << mt.val();\n\
    \        return os;\n    }\n    constexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n};\n};  // namespace kyopro\n\n/// @brief static modint(\u9759\
    \u7684modint)\n/// @docs docs/math/static_modint.md\n#line 5 \"test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n\nusing mint = kyopro::static_modint32<998244353>;\n\nstruct F{\n    mint a,b;\n\
    };\n\ninline F op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a\
    \ + r.b);\n    return F{na, nb};\n}\ninline F e(){\n    return F{1,0};\n}\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    kyopro::segtree<F, op, e> seg(n);\n\
    \    for(int i = 0; i < n;i++){\n        mint a, b;\n        std::cin >> a >>\
    \ b;\n        seg.set(i, F{a, b});\n    }\n    seg.build();\n    while (q--){\n\
    \        int t;\n        std::cin >> t;\n        if (!t){\n            int p;\n\
    \            mint c, d;\n            std::cin >> p >> c >> d;\n            seg.update(p,\
    \ F{c, d});\n        }\n        else{\n            int l, r;\n            mint\
    \ x;\n            std::cin >> l >> r >> x;\n            F res = seg.prod(l, r);\n\
    \            mint ans = res.a * x + res.b;\n            std::cout << ans << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<iostream>\n#include\"../../../src/data-structure/segtree.hpp\"\n#include\"\
    ../../../src/math/static_modint.hpp\"\n\nusing mint = kyopro::static_modint32<998244353>;\n\
    \nstruct F{\n    mint a,b;\n};\n\ninline F op(F l,F r){\n    mint na = l.a * r.a;\n\
    \    mint nb = (l.b * r.a + r.b);\n    return F{na, nb};\n}\ninline F e(){\n \
    \   return F{1,0};\n}\nint main() {\n    std::ios::sync_with_stdio(false);\n \
    \   std::cin.tie(nullptr);\n    int n, q;\n    std::cin >> n >> q;\n    kyopro::segtree<F,\
    \ op, e> seg(n);\n    for(int i = 0; i < n;i++){\n        mint a, b;\n       \
    \ std::cin >> a >> b;\n        seg.set(i, F{a, b});\n    }\n    seg.build();\n\
    \    while (q--){\n        int t;\n        std::cin >> t;\n        if (!t){\n\
    \            int p;\n            mint c, d;\n            std::cin >> p >> c >>\
    \ d;\n            seg.update(p, F{c, d});\n        }\n        else{\n        \
    \    int l, r;\n            mint x;\n            std::cin >> l >> r >> x;\n  \
    \          F res = seg.prod(l, r);\n            mint ans = res.a * x + res.b;\n\
    \            std::cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-05-02 00:07:28+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
---
