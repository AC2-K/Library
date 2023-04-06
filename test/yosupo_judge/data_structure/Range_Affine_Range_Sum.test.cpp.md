---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segtree.hpp
    title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N)  for(int\
    \ i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/lazy_segtree.hpp\"\nnamespace library{\n\n/// @brief Segment\
    \ Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\ntemplate<\n    class S, class F,\n    S(*op)(S, S), S(*e)(),\n    F(*comp)(F,\
    \ F), F(*id)(),\n    S(*mapping)(S, F)\n>\nclass lazy_segtree {\n    int sz;\n\
    \    std::vector<S> dat;\n    std::vector<F> lz;\npublic:\n    lazy_segtree(int\
    \ n) :lazy_segtree(std::vector<S>(n, e())) {    }\n    lazy_segtree(const std::vector<S>&\
    \ a) :dat(4 * (int)a.size(), e()), lz(4 * (int)a.size(), id()) {\n        int\
    \ x = 1;\n        while ((int)a.size() > x) {\n            x <<= 1;\n        }\n\
    \        sz = x;\n        for (int i = 0; i < (int)a.size(); i++) {\n        \
    \    set(i, a[i]);\n        }\n        build();\n    }\npublic:\n    void set(int\
    \ pos, S x) {\n        assert(0 <= pos && pos < sz);\n        dat[pos + sz - 1]\
    \ = x;\n    }\n    void build() {\n        for (int i = sz - 2; i >= 0; i--) {\n\
    \            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);\n        }\n    }\n\n\
    private:\n    void eval(int pos) {\n        if (lz[pos] == id()) return;\n   \
    \     if (pos < sz - 1) {\n            lz[2 * pos + 1] = comp(lz[2 * pos + 1],\
    \ lz[pos]);\n            lz[2 * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);\n \
    \       }\n        dat[pos] = mapping(dat[pos], lz[pos]);\n        lz[pos] = id();\n\
    \    }\n\nprivate:\n    void internal_apply(int L, int R, int l, int r, const\
    \ F& x, int k) {\n        eval(k);\n        if (L <= l && r <= R) {\n        \
    \    lz[k] = comp(lz[k], x);\n            eval(k);\n        }\n        else if\
    \ (L < r && l < R) {\n            int mid = (l + r) >> 1;\n            internal_apply(L,\
    \ R, l, mid, x, 2 * k + 1);\n            internal_apply(L, R, mid, r, x, 2 * k\
    \ + 2);\n            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n\
    \    }\npublic:\n    void apply(int l, int r, const F& x) {\n        assert(0\
    \ <= l && l <= r && r <= sz);\n        internal_apply(l, r, 0, sz, x, 0);\n  \
    \  }\n\nprivate:\n    S internal_prod(int L, int R, int l, int r, int k) {\n \
    \       eval(k);\n        if (r <= L || R <= l) {\n            return e();\n \
    \       }\n        else if (L <= l && r <= R) {\n            return dat[k];\n\
    \        }\n        else {\n            int mid = (l + r) >> 1;\n            S\
    \ vl = internal_prod(L, R, l, mid, 2 * k + 1);\n            S vr = internal_prod(L,\
    \ R, mid, r, 2 * k + 2);\n            return op(vl, vr);\n        }\n    }\n\n\
    public:\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= sz);\n\
    \        return internal_prod(l, r, 0, sz, 0);\n    }\n\n    S operator[](int\
    \ pos) {\n        return prod(pos, pos + 1);\n    }\n};\n\n};  // namespace library\n\
    \n\n/// @docs docs/data-structure/lazy_segtree.md\n#line 3 \"math/gcd.hpp\"\n\
    namespace library {\ntemplate <typename T> constexpr inline T _gcd(T a, T b) {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr inline T ext_gcd(T a, T b, T &x,\
    \ T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T\
    \ q = a / b;\n        std::tie(a, b) = std::make_pair(b, a % b);\n        std::tie(x,\
    \ nx) = std::make_pair(nx, x - nx * q);\n        std::tie(y, ny) = std::make_pair(ny,\
    \ y - ny * q);\n    }\n    return a;\n}\n\n};  // namespace library\n#line 4 \"\
    math/static_modint.hpp\"\n\nnamespace library{\n    \n///@brief static modint(\u9759\
    \u7684modint)\ntemplate<__uint64_t mod>\nclass static_modint {\nprivate:\n\tusing\
    \ mint = static_modint<mod>;\n\tusing i64 = long long;\n\tusing u64 = unsigned\
    \ long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\n\tu64\
    \ v;\n\tu64 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\
    \tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr static_modint()\
    \ :v(0) {}\n\tconstexpr static_modint(const i64& v_) :v(normalize(v_)) { }\n\n\
    \t//operator\n\tconstexpr u64 val() const {\n\t\treturn v;\n\t}\n\tconstexpr mint&\
    \ operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\
    \tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint\
    \ operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint\
    \ operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr\
    \ mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr\
    \ bool operator==(const mint& r) const {\n\t\treturn (*this).val() == r.val();\n\
    \t}\n\tconstexpr mint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\t\t\
    while (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *=\
    \ base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n\t\tll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n   \
    \     assert(d == 1);\n        return mint(y);\n\t}\n\n\tconstexpr mint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tconstexpr mint inv(const\
    \ mint&r)const{\n\t\treturn mint(*this) *= r.inv();\n\t}\n\tconstexpr friend mint\
    \ operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t\
    }\n\tconstexpr friend mint operator/(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) /= mint(r);\n\t}\n\n\t//istd::ostream\n\tconstexpr friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn\
    \ os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n\n\
    \n///@brief static modint(32bit ver)\ntemplate<__uint32_t mod>\nclass static_modint32\
    \ {\nprivate:\n\tusing mint = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\
    \tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \n\tu32 v;\n\tinline u32 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_\
    \ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr static_modint32()\
    \ :v(0) {}\n\tconstexpr static_modint32(const i64& v_) :v(normalize(v_)) { }\n\
    \n\t//operator\n\tconstexpr u64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr\
    \ mint& operator+=(const mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\
    \t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs)\
    \ {\n\t\tv = (u64)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\tconstexpr\
    \ mint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\t\
    constexpr mint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const mint& r) const {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\tconstexpr mint& operator+=(const i64& rhs) {\n\t\t(*this) +=\
    \ mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const i64&\
    \ rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr mint&\
    \ operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr friend mint operator+(const i64& l, const mint& r) {\n\t\treturn\
    \ mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tconstexpr mint\
    \ operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint\
    \ operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tconstexpr\
    \ mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tconstexpr\
    \ bool operator==(const mint& r) const {\n\t\treturn (*this).val() == r.val();\n\
    \t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint ans(1), base(*this);\n\t\t\
    while (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *=\
    \ base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n        ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n\tconstexpr mint&\
    \ operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n    constexpr\
    \ mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n   \
    \ constexpr friend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l)\
    \ /= mint(r);\n\t}\n\tconstexpr friend mint operator/(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\n\t//istd::ostream\n\tconstexpr\
    \ friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n\n};\n\n};  // namespace library\n\n///@docs docs/math/static_modint.md\n#line\
    \ 5 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\n\nusing\
    \ namespace std;\nusing namespace library;\nusing mint = static_modint32<MOD2>;\n\
    struct S {\n    mint s;\n    int len;\n};\nS op(S a, S b) { return S{a.s + b.s,\
    \ a.len + b.len}; }\nS e() { return S{0, 0}; }\nusing Affine = pair<mint, mint>;\n\
    Affine composition(Affine g, Affine f) {\n\t//f(g)\n\t//a(cx+d)+b\n\tauto a =\
    \ f.first, b = f.second;\n\tauto c = g.first, d = g.second;\n\treturn Affine(a\
    \ * c, a * d + b);\n}\nAffine id() { return Affine(1, 0); }\nS mapping(S d, Affine\
    \ f) {\n    mint a = f.first, b = f.second;\n    d.s *= a, d.s += b * d.len;\n\
    \    return d;\n};\n\nint main(){\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int n, q;\n    cin >> n >> q;\n    lazy_segtree<S, Affine, op, e, composition,\
    \ id, mapping> sg(n);\n    rep(i,n){\n        mint a;\n        cin >> a;\n   \
    \     sg.set(i, {a, 1});\n    }\n    sg.build();\n    while(q--){\n        int\
    \ t;\n        cin >> t;\n        if (t == 0) {\n            int l, r;\n      \
    \      mint b, c;\n            cin >> l >> r >> b >> c;\n            sg.apply(l,\
    \ r, Affine(b, c));\n        } else {\n            int l, r;\n            cin\
    \ >> l >> r;\n            auto res = sg.prod(l, r);\n            cout << res.s\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include\"template.hpp\"\n#include\"data-structure/lazy_segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\n\nusing namespace std;\nusing namespace library;\nusing\
    \ mint = static_modint32<MOD2>;\nstruct S {\n    mint s;\n    int len;\n};\nS\
    \ op(S a, S b) { return S{a.s + b.s, a.len + b.len}; }\nS e() { return S{0, 0};\
    \ }\nusing Affine = pair<mint, mint>;\nAffine composition(Affine g, Affine f)\
    \ {\n\t//f(g)\n\t//a(cx+d)+b\n\tauto a = f.first, b = f.second;\n\tauto c = g.first,\
    \ d = g.second;\n\treturn Affine(a * c, a * d + b);\n}\nAffine id() { return Affine(1,\
    \ 0); }\nS mapping(S d, Affine f) {\n    mint a = f.first, b = f.second;\n   \
    \ d.s *= a, d.s += b * d.len;\n    return d;\n};\n\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int n, q;\n    cin >> n >> q;\n    lazy_segtree<S,\
    \ Affine, op, e, composition, id, mapping> sg(n);\n    rep(i,n){\n        mint\
    \ a;\n        cin >> a;\n        sg.set(i, {a, 1});\n    }\n    sg.build();\n\
    \    while(q--){\n        int t;\n        cin >> t;\n        if (t == 0) {\n \
    \           int l, r;\n            mint b, c;\n            cin >> l >> r >> b\
    \ >> c;\n            sg.apply(l, r, Affine(b, c));\n        } else {\n       \
    \     int l, r;\n            cin >> l >> r;\n            auto res = sg.prod(l,\
    \ r);\n            cout << res.s << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/lazy_segtree.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 22:29:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
---
