---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr int64_t MOD = 1e9\
    \ + 7;\nconstexpr int64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\n\
    constexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
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
    \ docs/data-structure/segtree.md\n#line 3 \"main.cpp\"\nusing namespace std;\n\
    \ntemplate<unsigned long long mod>\nclass static_modint {\nprivate:\n\tusing mint\
    \ = static_modint<mod>;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\n\ti128 v;\n\tvoid normalize(i128&\
    \ v) {\n\t\tv %= mod;\n\t\tif (v < 0) {\n\t\t\tv += mod;\n\t\t}\n\t}\npublic:\n\
    \tstatic_modint(const u64& v_ = 0) :v(v_) { normalize(v); }\n\n\n\tu64 val() const\
    \ {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const mint& rhs) {\n\t\tv +=\
    \ rhs.val();\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
    \ mint& rhs) {\n\t\tv -= rhs.val();\n\t\tnormalize(v);\n\t\treturn (*this);\n\t\
    }\n\tmint& operator*=(const mint& rhs) {\n\t\tv *= rhs.val();\n\t\tnormalize(v);\n\
    \t\treturn (*this);\n\t}\n\n\n\n\n\tmint operator+(const mint& r) const {\n\t\t\
    return mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\tv += rhs;\n\
    \t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\tv -= rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\tv *= rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\t\
    friend mint operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\
    \t}\n\tfriend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ -= r;\n\t}\n\tfriend mint operator*(const i64& l, const mint& r){\n\t\treturn\
    \ mint(l) *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this)\
    \ += r;\n\t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tmint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\
    \tmint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool\
    \ operator==(const mint& r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint\
    \ pow(u128 e) {\n\t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e &\
    \ 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\
    \t}\n\t\treturn ans;\n\t}\n\n\tmint inv() {\n\t\treturn pow(mod - 2);\n\t}\n\n\
    \tmint& operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend\
    \ mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\
    \t}\n\n\t//iostream\n\tfriend ostream& operator<<(ostream& os, const mint& mt)\
    \ {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, mint& mt) {\n\t\ti64 vv;\n\t\tis >> vv;\n\t\tmt = vv;\n\t\treturn is;\n\t\
    }\n};\nusing mint = static_modint<MOD2>;\nstruct F\n{\n    mint a,b;\n};\n\nF\
    \ op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n \
    \   return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int\
    \ n,q;\n    cin>>n>>q;\n    segtree<F,op,e> seg(n);\n    rep(i,n){\n        mint\
    \ a,b;\n        cin>>a>>b;\n        seg.set(i,F{a,b});\n    }\n    seg.build();\n\
    \    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n       \
    \     int p;\n            mint c,d;\n            cin>>p>>c>>d;\n            seg.update(p,F{c,d});\n\
    \        }else{\n            int l,r;\n            mint x;\n            cin>>l>>r>>x;\n\
    \            F res=seg.prod(l,r);\n            mint ans=res.a*x+res.b;\n     \
    \       cout<<ans<<'\\n';\n        }\n    }\n}\n"
  code: "#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing namespace\
    \ std;\n\ntemplate<unsigned long long mod>\nclass static_modint {\nprivate:\n\t\
    using mint = static_modint<mod>;\n\tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\
    \tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\n\ti128 v;\n\tvoid normalize(i128&\
    \ v) {\n\t\tv %= mod;\n\t\tif (v < 0) {\n\t\t\tv += mod;\n\t\t}\n\t}\npublic:\n\
    \tstatic_modint(const u64& v_ = 0) :v(v_) { normalize(v); }\n\n\n\tu64 val() const\
    \ {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const mint& rhs) {\n\t\tv +=\
    \ rhs.val();\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
    \ mint& rhs) {\n\t\tv -= rhs.val();\n\t\tnormalize(v);\n\t\treturn (*this);\n\t\
    }\n\tmint& operator*=(const mint& rhs) {\n\t\tv *= rhs.val();\n\t\tnormalize(v);\n\
    \t\treturn (*this);\n\t}\n\n\n\n\n\tmint operator+(const mint& r) const {\n\t\t\
    return mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\tv += rhs;\n\
    \t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\tv -= rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\tv *= rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\t\
    friend mint operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\
    \t}\n\tfriend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ -= r;\n\t}\n\tfriend mint operator*(const i64& l, const mint& r){\n\t\treturn\
    \ mint(l) *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this)\
    \ += r;\n\t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tmint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\
    \tmint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool\
    \ operator==(const mint& r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint\
    \ pow(u128 e) {\n\t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e &\
    \ 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\
    \t}\n\t\treturn ans;\n\t}\n\n\tmint inv() {\n\t\treturn pow(mod - 2);\n\t}\n\n\
    \tmint& operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend\
    \ mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\
    \t}\n\n\t//iostream\n\tfriend ostream& operator<<(ostream& os, const mint& mt)\
    \ {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream& operator>>(istream&\
    \ is, mint& mt) {\n\t\ti64 vv;\n\t\tis >> vv;\n\t\tmt = vv;\n\t\treturn is;\n\t\
    }\n};\nusing mint = static_modint<MOD2>;\nstruct F\n{\n    mint a,b;\n};\n\nF\
    \ op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n \
    \   return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int\
    \ n,q;\n    cin>>n>>q;\n    segtree<F,op,e> seg(n);\n    rep(i,n){\n        mint\
    \ a,b;\n        cin>>a>>b;\n        seg.set(i,F{a,b});\n    }\n    seg.build();\n\
    \    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n       \
    \     int p;\n            mint c,d;\n            cin>>p>>c>>d;\n            seg.update(p,F{c,d});\n\
    \        }else{\n            int l,r;\n            mint x;\n            cin>>l>>r>>x;\n\
    \            F res=seg.prod(l,r);\n            mint ans=res.a*x+res.b;\n     \
    \       cout<<ans<<'\\n';\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-03-06 14:01:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
