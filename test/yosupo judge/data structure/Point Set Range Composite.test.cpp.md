---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo judge/data structure/Point Set Range Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\
    \ntemplate<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n    int n;\n    vector<S>\
    \ dat;\n    void Init(int n_) {\n        int x = 1;\n        while (n_ > x) {\n\
    \            x <<= 1;\n        }\n        n = x;\n    }\npublic:\n    segtree(int\
    \ n_) : segtree(vector<S>(n_, e())) {   }\n    segtree(const vector<S>& v) :dat(4\
    \ * v.size()) {\n        Init(v.size());\n        for (int i = 0; i < v.size();\
    \ i++) {\n            set(i, v[i]);\n        }\n        build();\n    }\n    inline\
    \ void set(int pos, S val) {\n        assert(0 <= pos && pos < n);\n        dat[pos\
    \ + n - 1] = val;\n    }\n    void build() {\n        for (int k = n - 2; k >=\
    \ 0; k--) {\n            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);\n\
    \        }\n    }\n\n    void update(int pos, S val) {\n        assert(0 <= pos\
    \ && pos < n);\n        pos += n - 1;\n        dat[pos] = val;\n        while\
    \ (pos > 0) {\n            pos = (pos - 1) >> 1;\n            dat[pos] = op(dat[(pos\
    \ << 1) + 1], dat[(pos << 1) + 2]);\n        }\n    }\n    inline S prod(int a,\
    \ int b) {\n        assert(0 <= a && b <= n);\n        assert(a <= b);\n     \
    \   if (a == 0 && b == n)return dat[0];\n        return prod(a, b, 0, 0, n);\n\
    \    }\n\nprivate:\n    S prod(int a, int b, int id, int l, int r) {\n       \
    \ if (r <= a || b <= l) {\n            return e();\n        }\n        else if\
    \ (a <= l && r <= b) {\n            return dat[id];\n        }\n        else {\n\
    \            int mid = (l + r) >> 1;\n            S vl = prod(a, b, (id << 1)\
    \ + 1, l, mid);\n            S vr = prod(a, b, (id << 1) + 2, mid, r);\n     \
    \       return op(vl, vr);\n        }\n    }\n\npublic:\n    //a[pos] <- a[pos]\u30FB\
    x\n    void add(int pos, S x) {\n        update(pos, op(dat[n + pos - 1], x));\n\
    \    }\n\n    S operator [](int pos) {\n        return dat[n + pos - 1];\n   \
    \ }\n};\n/// @brief segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n///@docs\
    \ docs/data-structure/segtree.md\n#line 2 \"math/static_modint.hpp\"\ntemplate<__uint64_t\
    \ mod>\nclass static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\t\
    using i64 = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tstatic_modint() :v(0) {}\n\tstatic_modint(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\
    \t\treturn (*this);\n\t}\n\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u128 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\ntemplate<__uint32_t\
    \ mod>\nclass static_modint32 {\nprivate:\n\tusing mint = static_modint32<mod>;\n\
    \tusing i32 = __int32_t;\n\tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\
    \tusing u64 = unsigned long long;\n\n\tu32 v;\n\tu32 normalize(i64 v_) const {\n\
    \t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t\
    }\npublic:\n\tstatic_modint32() :v(0) {}\n\tstatic_modint32(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv = (u64)v * rhs.val() % mod;\n\
    \t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u64 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n#line 5 \"\
    test/yosupo judge/data structure/Point Set Range Composite.test.cpp\"\nusing mint\
    \ = static_modint32<MOD2>;\n\nstruct F\n{\n    mint a,b;\n};\n\nF op(F l,F r){\n\
    \    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n    return F{na,\
    \ nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int n, q;\n    cin\
    \ >> n >> q;\n    segtree<F, op, e> seg(n);\n    rep(i, n){\n        mint a, b;\n\
    \        cin >> a >> b;\n        seg.set(i, F{a, b});\n    }\n    seg.build();\n\
    \    while (q--){\n        int t;\n        cin >> t;\n        if (t == 0){\n \
    \           int p;\n            mint c, d;\n            cin >> p >> c >> d;\n\
    \            seg.update(p, F{c, d});\n        }\n        else{\n            int\
    \ l, r;\n            mint x;\n            cin >> l >> r >> x;\n            F res\
    \ = seg.prod(l, r);\n            mint ans = res.a * x + res.b;\n            cout\
    \ << ans << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing mint = static_modint32<MOD2>;\n\nstruct F\n{\n\
    \    mint a,b;\n};\n\nF op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb =\
    \ (l.b * r.a + r.b);\n    return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    segtree<F, op, e> seg(n);\n\
    \    rep(i, n){\n        mint a, b;\n        cin >> a >> b;\n        seg.set(i,\
    \ F{a, b});\n    }\n    seg.build();\n    while (q--){\n        int t;\n     \
    \   cin >> t;\n        if (t == 0){\n            int p;\n            mint c, d;\n\
    \            cin >> p >> c >> d;\n            seg.update(p, F{c, d});\n      \
    \  }\n        else{\n            int l, r;\n            mint x;\n            cin\
    \ >> l >> r >> x;\n            F res = seg.prod(l, r);\n            mint ans =\
    \ res.a * x + res.b;\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - math/static_modint.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 16:37:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp.html
title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
---