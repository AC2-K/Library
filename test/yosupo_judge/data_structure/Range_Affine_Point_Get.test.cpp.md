---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dual_segtree.hpp
    title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  - icon: ':question:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int\
    \ i = 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 4 \"data-structure/dual_segtree.hpp\"\n/// @brief Dual Segmenttree(\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\ntemplate <class F, F (*comp)(F, F),\
    \ F (*id)(), bool is_commutative = true>\nclass dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\n  public:\n    dual_segtree() : dual_segtree(0)\
    \ {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while\
    \ (sz < _n) {\n            lg++;\n            sz <<= 1;\n        }\n        dat.assign(sz\
    \ << 1, id());\n    }\n\n  private:\n    void all_apply(int p, const F& v) { dat[p]\
    \ = comp(dat[p], v); }\n    void push(int p) {\n        if (dat[p] == id()) {\n\
    \            return;\n        }\n        all_apply(p << 1 | 0, dat[p]);\n    \
    \    all_apply(p << 1 | 1, dat[p]);\n        dat[p] = id();\n    }\n\n  public:\n\
    \    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\n        F res\
    \ = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--) {\n      \
    \      push(p >> i);\n        }\n        return dat[p];\n    }\n\n    void apply(int\
    \ l, int r, const F& v) {\n        assert(0 <= l && l <= r && r <= _n);\n    \
    \    if (l == r) return;\n        l += sz, r += sz;\n        if (is_commutative)\
    \ {\n            for (int i = lg; i > 0; i--) {\n                if (((l >> i)\
    \ << i) != l) {\n                    push(l >> i);\n                }\n      \
    \          if (((r >> i) << i) != r) {\n                    push((r - 1) >> i);\n\
    \                }\n            }\n        }\n        while (l < r) {\n      \
    \      if (l & 1) {\n                all_apply(l++, v);\n            }\n     \
    \       if (r & 1) {\n                all_apply(--r, v);\n            }\n    \
    \        l >>= 1, r >>= 1;\n        }\n    }\n};\n\n/// @docs docs/data-structure/dual_segtree.md\n\
    #line 4 \"math/gcd.hpp\"\ntemplate <typename T> constexpr T _gcd(T a, T b) {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr T ext_gcd(T a, T b, T &x, T &y)\
    \ {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T q = a\
    \ / b;\n        std::tie(a, b) = std::pair<T,T>{b, a % b};\n        std::tie(x,\
    \ nx) = std::pair<T,T>{nx, x - nx * q};\n        std::tie(y, ny) = std::pair<T,T>{ny,\
    \ y - ny * q};\n    }\n    return a;\n}\n#line 6 \"math/static_modint.hpp\"\n\
    template <__uint64_t mod> class static_modint {\n  private:\n    using mint =\
    \ static_modint<mod>;\n    using i64 = long long;\n    using u64 = unsigned long\
    \ long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\n    u64\
    \ v;\n    inline u64 normalize(i64 v_) const {\n        v_ %= mod;\n        if\
    \ (v_ < 0) {\n            v_ += mod;\n        }\n        return v_;\n    }\n\n\
    \  public:\n    constexpr static_modint() : v(0) {}\n    constexpr static_modint(const\
    \ i64& v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr u64 val() const\
    \ { return v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v\
    \ += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n        }\n \
    \       return (*this);\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        v += mod - rhs.val();\n        if (v >= mod) {\n            v -=\
    \ mod;\n        }\n        return (*this);\n    }\n    constexpr mint& operator*=(const\
    \ mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n        return (*this);\n\
    \    }\n\n    constexpr mint operator+(const mint& r) const { return mint(*this)\
    \ += r; }\n    constexpr mint operator-(const mint& r) const { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(const i64& rhs) {\n        (*this)\
    \ += mint(rhs);\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ i64& rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator*=(const i64& rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(const i64&\
    \ l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend\
    \ mint operator-(const i64& l, const mint& r) {\n        return mint(l) -= r;\n\
    \    }\n    constexpr friend mint operator*(const i64& l, const mint& r) {\n \
    \       return mint(l) *= r;\n    }\n\n    constexpr mint operator+(const i64&\
    \ r) { return mint(*this) += r; }\n    constexpr mint operator-(const i64& r)\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const i64& r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(const i64& r) { return\
    \ (*this) = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n\
    \        return (*this).val() == r.val();\n    }\n\n    template <typename T>\
    \ constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n       \
    \ while (e) {\n            if (e & 1) {\n                ans *= base;\n      \
    \      }\n            base *= base;\n            e >>= 1;\n        }\n       \
    \ return ans;\n    }\n    constexpr inline mint inv() const {\n        ll x, y;\n\
    \        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n        assert(d == 1);\n  \
    \      return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint& r)\
    \ { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint& r) const\
    \ { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, const i64& r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(const i64& l, const mint& r) {\n        return mint(l)\
    \ /= mint(r);\n    }\n\n    // iostream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t mod> class\
    \ static_modint32 {\n  private:\n    using mint = static_modint32<mod>;\n    using\
    \ i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    inline u32 normalize(i64 v_) const\
    \ {\n        v_ %= mod;\n        if (v_ < 0) {\n            v_ += mod;\n     \
    \   }\n        return v_;\n    }\n\n  public:\n    constexpr static_modint32()\
    \ : v(0) {}\n    constexpr static_modint32(const i64& v_) : v(normalize(v_)) {}\n\
    \n    // operator\n    constexpr u64 val() const { return (u64)v; }\n    constexpr\
    \ mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v\
    \ >= mod) {\n            v -= mod;\n        }\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u64)v\
    \ * rhs.val() % mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const\
    \ i64& rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs)\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(const i64& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(const i64& r) { return mint(*this) += r; }\n    constexpr mint\
    \ operator-(const i64& r) { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ i64& r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(const\
    \ i64& r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const\
    \ mint& r) const {\n        return (*this).val() == r.val();\n    }\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n\n    constexpr inline mint inv() const {\n      \
    \  ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n        assert(d\
    \ == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const\
    \ mint& r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, const i64& r) {\n        return mint(l)\
    \ /= mint(r);\n    }\n    constexpr friend mint operator/(const i64& l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // iostream\n \
    \   constexpr friend std::ostream& operator<<(std::ostream& os, const mint& mt)\
    \ {\n        os << mt.val();\n        return os;\n    }\n    constexpr friend\
    \ std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n  \
    \      is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n#line 6 \"\
    test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp\"\n\nusing namespace\
    \ std;\nusing mint = static_modint32<MOD2>;\nusing Affine = pair<mint, mint>;\n\
    Affine op(Affine g, Affine f) {\n\tauto a = f.first, b = f.second;\n\tauto c =\
    \ g.first, d = g.second;\n\treturn Affine(a * c, a * d + b);\n}\nAffine e() {\
    \ return Affine(1, 0); }\nint main() {\n    ios::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tdual_segtree<Affine, op,\
    \ e> sg(n);\n\tvector<mint> a(n);\n\tfor (auto& aa : a) {\n\t\tcin >> aa;\n\t\
    }\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;   \n\t\tif (t == 0) {\n\t\t\tint\
    \ l, r;\n\t\t\tmint b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsg.apply(l, r,\
    \ Affine(b, c));\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tauto\
    \ f = sg[i];\n\t\t\tmint ans = f.first * a[i] + f.second;\n\t\t\tcout << ans <<\
    \ '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\n\nusing namespace std;\nusing mint = static_modint32<MOD2>;\n\
    using Affine = pair<mint, mint>;\nAffine op(Affine g, Affine f) {\n\tauto a =\
    \ f.first, b = f.second;\n\tauto c = g.first, d = g.second;\n\treturn Affine(a\
    \ * c, a * d + b);\n}\nAffine e() { return Affine(1, 0); }\nint main() {\n   \
    \ ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\tint n, q;\n\tcin >> n\
    \ >> q;\n\tdual_segtree<Affine, op, e> sg(n);\n\tvector<mint> a(n);\n\tfor (auto&\
    \ aa : a) {\n\t\tcin >> aa;\n\t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t; \
    \  \n\t\tif (t == 0) {\n\t\t\tint l, r;\n\t\t\tmint b, c;\n\t\t\tcin >> l >> r\
    \ >> b >> c;\n\t\t\tsg.apply(l, r, Affine(b, c));\n\t\t}\n\t\telse {\n\t\t\tint\
    \ i;\n\t\t\tcin >> i;\n\t\t\tauto f = sg[i];\n\t\t\tmint ans = f.first * a[i]\
    \ + f.second;\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/dual_segtree.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
---
