---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int\
    \ i = 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"data-structure/segtree.hpp\"\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n/// @tparam S \u8981\u7D20\u306E\u578B\n/// @tparam op \u4E8C\
    \u9805\u6F14\u7B97\n/// @tparam e \u5358\u4F4D\u5143\n/// @docs docs/data-structure/segtree.md\n\
    template<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\t\
    std::vector<S> dat;\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n\tsegtree(const std::vector<S>& vec) : n((int)vec.size()) {\n\t\t\
    sz = 1, lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\
    \t\tdat = std::vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\
    \t\t\tset(i, vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int\
    \ p, const S& v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor\
    \ (int i = sz - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1)\
    \ ^ 1]);\n\t\t}\n\t}\n\tS operator[](const int p) const { return dat[sz + p];\
    \ }\n\n\tinline void update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\
    \t\twhile (p >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\
    \t}\n\t}\n\n\tinline S prod(int l, int r) const {\n\t\tif (l == 0 && r == n) {\n\
    \t\t\treturn dat[1];\n\t\t}\n\t\tl += sz, r += sz;\n\t\tS sml = e(), smr = e();\n\
    \t\twhile (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\t\t\tif (r &\
    \ 1)smr = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml,\
    \ smr);\n\t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p, op(dat[sz\
    \ + p], v));\n\t}\n};\n#line 4 \"math/gcd.hpp\"\ntemplate <typename T> constexpr\
    \ T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0)\
    \ return a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        }else{\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate<typename T>\nconstexpr T\
    \ ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while(b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,T>{b,\
    \ a % b};\n        std::tie(x, nx) = std::pair<T,T>{nx, x - nx * q};\n       \
    \ std::tie(y, ny) = std::pair<T,T>{ny, y - ny * q};\n    }\n    return a;\n}\n\
    #line 6 \"math/static_modint.hpp\"\ntemplate <__uint64_t mod> class static_modint\
    \ {\n  private:\n    using mint = static_modint<mod>;\n    using i64 = long long;\n\
    \    using u64 = unsigned long long;\n    using u128 = __uint128_t;\n    using\
    \ i128 = __int128_t;\n\n    u64 v;\n    inline u64 normalize(i64 v_) const {\n\
    \        v_ %= mod;\n        if (v_ < 0) {\n            v_ += mod;\n        }\n\
    \        return v_;\n    }\n\n  public:\n    constexpr static_modint() : v(0)\
    \ {}\n    constexpr static_modint(const i64& v_) : v(normalize(v_)) {}\n\n   \
    \ // operator\n    constexpr u64 val() const { return v; }\n    constexpr mint&\
    \ operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v >= mod)\
    \ {\n            v -= mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n       \
    \ if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u128)v\
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
    \ mint& r) const {\n        return (*this).val() == r.val();\n    }\n\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n    constexpr inline mint inv() const {\n        ll\
    \ x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n        assert(d ==\
    \ 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint&\
    \ r) const { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
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
    \ modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n#line 5 \"\
    test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp\"\nusing namespace\
    \ std;\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"Ofast\")\n#pragma\
    \ GCC optimize(\"unroll-loops\")\nusing mint = static_modint32<MOD2>;\n\nstruct\
    \ F\n{\n    mint a,b;\n};\n\nF op(F l,F r){\n    mint na = l.a * r.a;\n    mint\
    \ nb = (l.b * r.a + r.b);\n    return F{na, nb};\n}\nF e(){\n    return F{1,0};\n\
    }\nint main() {\n    int n, q;\n    cin >> n >> q;\n    segtree<F, op, e> seg(n);\n\
    \    rep(i, n){\n        mint a, b;\n        cin >> a >> b;\n        seg.set(i,\
    \ F{a, b});\n    }\n    seg.build();\n    while (q--){\n        int t;\n     \
    \   cin >> t;\n        if (t == 0){\n            int p;\n            mint c, d;\n\
    \            cin >> p >> c >> d;\n            seg.update(p, F{c, d});\n      \
    \  }\n        else{\n            int l, r;\n            mint x;\n            cin\
    \ >> l >> r >> x;\n            F res = seg.prod(l, r);\n            mint ans =\
    \ res.a * x + res.b;\n            cout << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing namespace std;\n#pragma GCC target(\"avx2\")\n\
    #pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\nusing\
    \ mint = static_modint32<MOD2>;\n\nstruct F\n{\n    mint a,b;\n};\n\nF op(F l,F\
    \ r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n    return\
    \ F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    segtree<F, op, e> seg(n);\n    rep(i, n){\n        mint\
    \ a, b;\n        cin >> a >> b;\n        seg.set(i, F{a, b});\n    }\n    seg.build();\n\
    \    while (q--){\n        int t;\n        cin >> t;\n        if (t == 0){\n \
    \           int p;\n            mint c, d;\n            cin >> p >> c >> d;\n\
    \            seg.update(p, F{c, d});\n        }\n        else{\n            int\
    \ l, r;\n            mint x;\n            cin >> l >> r >> x;\n            F res\
    \ = seg.prod(l, r);\n            mint ans = res.a * x + res.b;\n            cout\
    \ << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
---
