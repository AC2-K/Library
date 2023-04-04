---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dual_segtree.hpp
    title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':heavy_check_mark:'
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
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"data-structure/dual_segtree.hpp\"\n\n/// @brief Dual Segmenttree(\u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n/// @tparam F \u8981\u7D20\u306E\u578B\
    \n/// @tparam comp \u4E8C\u9805\u6F14\u7B97\n/// @tparam id \u5358\u4F4D\u5143\
    \n/// @docs docs/data-structure/dual_segtree.md\ntemplate<class F, F(*comp)(F,\
    \ F), F(*id)(), bool is_commutative = true >\nclass dual_segtree {\n\tvector<F>\
    \ dat;\n\tint _n, sz, lg;\n\npublic:\n\tdual_segtree() :dual_segtree(0) {}\n\t\
    dual_segtree(int _n) :_n(_n) {\n\t\tsz = 1, lg = 0;\n\t\twhile (sz < _n) {\n\t\
    \t\tlg++;\n\t\t\tsz <<= 1;\n\t\t}\n\t\tdat.assign(sz << 1, id());\n\t}\n\nprivate:\n\
    \tvoid all_apply(int p, const F& v) {\n\t\tdat[p] = comp(dat[p], v);\n\t}\n\t\
    void push(int p) {\n\t\tif (dat[p] == id()) {\n\t\t\treturn;\n\t\t}\n\t\tall_apply(p\
    \ << 1 | 0, dat[p]);\n\t\tall_apply(p << 1 | 1, dat[p]);\n\t\tdat[p] = id();\n\
    \t}\npublic:\n\tF operator[](int p) {\n\t\tassert(0 <= p && p < _n);\n\n\t\tF\
    \ res = id();\n\n\t\tp += sz;\n\t\tfor (int i = lg; i > 0; i--) {\n\t\t\tpush(p\
    \ >> i);\n\t\t}\n\t\treturn dat[p];\n\t}\npublic:\n\n\tvoid apply(int l, int r,\
    \ const F& v) {\n\t\tassert(0 <= l && l <= r && r <= _n);\n\t\tif (l == r)return;\n\
    \t\tl += sz, r += sz;\n\t\tif (is_commutative) {\n\t\t\tfor (int i = lg; i > 0;\
    \ i--) {\n\t\t\t\tif (((l >> i) << i) != l) {\n\t\t\t\t\tpush(l >> i);\n\t\t\t\
    \t}\n\t\t\t\tif (((r >> i) << i) != r) {\n\t\t\t\t\tpush((r - 1) >> i);\n\t\t\t\
    \t}\n\t\t\t}\n\t\t}\n\n\t\twhile (l < r) {\n\t\t\tif (l & 1) {\n\t\t\t\tall_apply(l++,\
    \ v);\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tall_apply(--r, v);\n\t\t\t}\n\t\t\t\
    l >>= 1, r >>= 1;\n\t\t}\n\t}\n};\n#line 2 \"math/gcd.hpp\"\ntemplate<typename\
    \ T>\nconstexpr inline T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n   \
    \ if (a == 0 || b == 0) return a + b;\n    int d = min(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        }else{\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate<typename T>\nconstexpr inline\
    \ T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while(b) {\n        T q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n\
    \        tie(x, nx) = make_pair(nx, x - nx*q);\n        tie(y, ny) = make_pair(ny,\
    \ y - ny*q);\n    }\n    return a;\n}\n#line 3 \"math/static_modint.hpp\"\ntemplate<__uint64_t\
    \ mod>\nclass static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\t\
    using i64 = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tconstexpr static_modint() :v(0) {}\n\tconstexpr static_modint(const\
    \ i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\tconstexpr u64 val() const\
    \ {\n\t\treturn v;\n\t}\n\tconstexpr mint& operator+=(const mint& rhs) {\n\t\t\
    v += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\t\
    return (*this);\n\t}\n\n\n\tconstexpr mint operator+(const mint& r) const {\n\t\
    \treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const mint& r) const\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n\t\tll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n   \
    \     assert(d == 1);\n        return mint(y);\n\t}\n\n\tconstexpr mint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tconstexpr mint inv(const\
    \ mint&r)const{\n\t\treturn mint(*this) *= r.inv();\n\t}\n\tconstexpr friend mint\
    \ operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t\
    }\n\tconstexpr friend mint operator/(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\tconstexpr friend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr\
    \ friend istream& operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >>\
    \ v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\ntemplate<__uint32_t mod>\nclass\
    \ static_modint32 {\nprivate:\n\tusing mint = static_modint32<mod>;\n\tusing i32\
    \ = __int32_t;\n\tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64\
    \ = __uint64_t;\n\n\tu32 v;\n\tinline u32 normalize(i64 v_) const {\n\t\tv_ %=\
    \ mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\
    \tconstexpr static_modint32() :v(0) {}\n\tconstexpr static_modint32(const i64&\
    \ v_) :v(normalize(v_)) { }\n\n\t//operator\n\tconstexpr u64 val() const {\n\t\
    \treturn (u64)v;\n\t}\n\tconstexpr mint& operator+=(const mint& rhs) {\n\t\tv\
    \ += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator*=(const mint& rhs) {\n\t\tv = (u64)v * rhs.val() % mod;\n\t\t\
    return (*this);\n\t}\n\n\tconstexpr mint operator+(const mint& r) const {\n\t\t\
    return mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const mint& r) const\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n        ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n\tconstexpr mint&\
    \ operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n    constexpr\
    \ mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n   \
    \ constexpr friend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l)\
    \ /= mint(r);\n\t}\n\tconstexpr friend mint operator/(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\n\t//iostream\n\tconstexpr friend\
    \ ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\t\
    return os;\n\t}\n\tconstexpr friend istream& operator>>(istream& is, mint& mt)\
    \ {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n\n};\n///@brief\
    \ static modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n#line\
    \ 6 \"test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp\"\nusing\
    \ mint = static_modint32<MOD2>;\nusing Affine = pair<mint, mint>;\nAffine op(Affine\
    \ g, Affine f) {\n\tauto a = f.first, b = f.second;\n\tauto c = g.first, d = g.second;\n\
    \treturn Affine(a * c, a * d + b);\n}\nAffine e() { return Affine(1, 0); }\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\tint n,\
    \ q;\n\tcin >> n >> q;\n\tdual_segtree<Affine, op, e> sg(n);\n\tvector<mint> a(n);\n\
    \tfor (auto& aa : a) {\n\t\tcin >> aa;\n\t}\n\twhile (q--) {\n\t\tint t;\n\t\t\
    cin >> t;   \n\t\tif (t == 0) {\n\t\t\tint l, r;\n\t\t\tmint b, c;\n\t\t\tcin\
    \ >> l >> r >> b >> c;\n\t\t\tsg.apply(l, r, Affine(b, c));\n\t\t}\n\t\telse {\n\
    \t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tauto f = sg[i];\n\t\t\tmint ans = f.first\
    \ * a[i] + f.second;\n\t\t\tcout << ans << '\\n';\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing mint = static_modint32<MOD2>;\nusing Affine =\
    \ pair<mint, mint>;\nAffine op(Affine g, Affine f) {\n\tauto a = f.first, b =\
    \ f.second;\n\tauto c = g.first, d = g.second;\n\treturn Affine(a * c, a * d +\
    \ b);\n}\nAffine e() { return Affine(1, 0); }\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tdual_segtree<Affine,\
    \ op, e> sg(n);\n\tvector<mint> a(n);\n\tfor (auto& aa : a) {\n\t\tcin >> aa;\n\
    \t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;   \n\t\tif (t == 0) {\n\t\t\t\
    int l, r;\n\t\t\tmint b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsg.apply(l,\
    \ r, Affine(b, c));\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\t\
    auto f = sg[i];\n\t\t\tmint ans = f.first * a[i] + f.second;\n\t\t\tcout << ans\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/dual_segtree.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  requiredBy: []
  timestamp: '2023-04-03 15:29:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
---
