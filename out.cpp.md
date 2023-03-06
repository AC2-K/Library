---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/segtree.md
    document_title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 1 \"out.cpp\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x)\
    \ (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\n\
    using ll = long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\n\
    using P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\n\
    constexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr int64_t\
    \ MOD = 1e9 + 7;\nconstexpr int64_t MOD2 = 998244353;\nconstexpr int dx[] = {\
    \ 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void\
    \ chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"data-structure/segtree.hpp\"\ntemplate<class S, S(*op)(S, S), S(*e)()>\n\
    class segtree {\n    int n;\n    vector<S> dat;\n    void Init(int n_) {\n   \
    \     int x = 1;\n        while (n_ > x) {\n            x <<= 1;\n        }\n\
    \        n = x;\n    }\npublic:\n    segtree(int n_) : segtree(vector<S>(n_, e()))\
    \ {   }\n    segtree(const vector<S>& v) :dat(4 * v.size()) {\n        Init(v.size());\n\
    \        for (int i = 0; i < v.size(); i++) {\n            set(i, v[i]);\n   \
    \     }\n        build();\n    }\n    inline void set(int pos, S val) {\n    \
    \    assert(0 <= pos && pos < n);\n        dat[pos + n - 1] = val;\n    }\n  \
    \  void build() {\n        for (int k = n - 2; k >= 0; k--) {\n            dat[k]\
    \ = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);\n        }\n    }\n\n    void update(int\
    \ pos, S val) {\n        assert(0 <= pos && pos < n);\n        pos += n - 1;\n\
    \        dat[pos] = val;\n        while (pos > 0) {\n            pos = (pos -\
    \ 1) >> 1;\n            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);\n\
    \        }\n    }\n    inline S prod(int a, int b) {\n        assert(0 <= a &&\
    \ b <= n);\n        assert(a <= b);\n        if (a == 0 && b == n)return dat[0];\n\
    \        return prod(a, b, 0, 0, n);\n    }\n\nprivate:\n    S prod(int a, int\
    \ b, int id, int l, int r) {\n        if (r <= a || b <= l) {\n            return\
    \ e();\n        }\n        else if (a <= l && r <= b) {\n            return dat[id];\n\
    \        }\n        else {\n            int mid = (l + r) >> 1;\n            S\
    \ vl = prod(a, b, (id << 1) + 1, l, mid);\n            S vr = prod(a, b, (id <<\
    \ 1) + 2, mid, r);\n            return op(vl, vr);\n        }\n    }\n\npublic:\n\
    \    //a[pos] <- a[pos]\u30FBx\n    void add(int pos, S x) {\n        update(pos,\
    \ op(dat[n + pos - 1], x));\n    }\n\n    S operator [](int pos) {\n        return\
    \ dat[n + pos - 1];\n    }\n};\n/// @brief segment tree(\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728)\n///@docs docs/data-structure/segtree.md\n#line 3 \"main.cpp\"\n\
    using namespace std;\n\ntemplate<unsigned long long mod>\nclass static_modint\
    \ {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64 = __int64_t;\n\t\
    using u64 = __uint64_t;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\ti128 v;\n\tvoid normalize(i128& v) {\n\t\tv %= mod;\n\t\tif (v < 0) {\n\t\t\
    \tv += mod;\n\t\t}\n\t}\npublic:\n\tstatic_modint(const u64& v_ = 0) :v(v_) {\
    \ normalize(v); }\n\n\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tnormalize(v);\n\t\treturn (*this);\n\t\
    }\n\tmint& operator-=(const mint& rhs) {\n\t\tv -= rhs.val();\n\t\tnormalize(v);\n\
    \t\treturn (*this);\n\t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv *= rhs.val();\n\
    \t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\n\n\n\n\tmint operator+(const mint&\
    \ r) const {\n\t\treturn mint(*this) += r;\n\t}\n\tmint operator-(const mint&\
    \ r) const {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64&\
    \ rhs) {\n\t\tv += rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\t}\n\tmint&\
    \ operator-=(const i64& rhs) {\n\t\tv -= rhs;\n\t\tnormalize(v);\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const i64& rhs) {\n\t\tv *= rhs;\n\t\tnormalize(v);\n\t\
    \treturn (*this);\n\t}\n\tfriend mint operator+(const i64& l, const mint& r) {\n\
    \t\treturn mint(l) += r;\n\t}\n\tfriend mint operator-(const i64& l, const mint&\
    \ r) {\n\t\treturn mint(l) -= r;\n\t}\n\tfriend mint operator*(const i64& l, const\
    \ mint& r){\n\t\treturn mint(l) *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\
    \t\treturn mint(*this) += r;\n\t}\n\tmint operator-(const i64& r) {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const i64& r) {\n\t\treturn mint(*this)\
    \ *= r;\n\t}\n\n\n\tmint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tbool operator==(const mint& r) {\n\t\treturn (*this).val() == r.val();\n\
    \t}\n\tmint pow(u128 e) {\n\t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\
    \tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>=\
    \ 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tmint inv() {\n\t\treturn pow(mod - 2);\n\
    \t}\n\n\tmint& operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t\
    }\n\tfriend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l)\
    \ /= mint(r);\n\t}\n\n\t//iostream\n\tfriend ostream& operator<<(ostream& os,\
    \ const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 vv;\n\t\tis >> vv;\n\t\tmt = vv;\n\
    \t\treturn is;\n\t}\n};\nusing mint = static_modint<MOD2>;\nstruct F\n{\n    mint\
    \ a,b;\n};\n\nF op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a\
    \ + r.b);\n    return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\nint main()\
    \ {\n    int n,q;\n    cin>>n>>q;\n    segtree<F,op,e> seg(n);\n    rep(i,n){\n\
    \        mint a,b;\n        cin>>a>>b;\n        seg.set(i,F{a,b});\n    }\n  \
    \  seg.build();\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int p;\n            mint c,d;\n            cin>>p>>c>>d;\n      \
    \      seg.update(p,F{c,d});\n        }else{\n            int l,r;\n         \
    \   mint x;\n            cin>>l>>r>>x;\n            F res=seg.prod(l,r);\n   \
    \         mint ans=res.a*x+res.b;\n            cout<<ans<<'\\n';\n        }\n\
    \    }\n}\n"
  code: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
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
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2023-03-06 14:01:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
SegmentTree:
- 集合$S$,
- 演算$\text{op}:S^2\to S$
- $e\in{S}$

について、$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. $\prod_{i\in[l,r)}{a_i}$ を出力

例えば$S\in\mathbb{Z}\cup\{\infty\},\text{op}=\min,e=\infty$とかにすると、一点更新のRMQになる。
## 使い方
### コンストラクタ
```cpp
segtree<S,op,e> seg(int n)
```
$a$を$e$で埋めて生成します。\
```cpp
segtree<S,op,e> seg(vector<S> a)
```
そのまま$a$を渡すこともできます。
\
\
template引数には、$S$に加えて$\text{op},e$を以下の形式で渡す必要があります。
```cpp
S op(S x,S y)
S e()
```
\
\
例として、RangeMinQueryには、以下のようにすればよいです。
```cpp
const int inf;  //大きい値

int op(int x,int y){
    return min(x,y);
}
int e(){
    return inf;
}
segtree<int,op,e> seg(n);    //サイズnのsegtree
segtree<int,op,e> seg(a);    //aで埋める
```
### メソッド
```cpp
void seg.update(int p,S val)
```
$a_p\leftarrow \text{val}$とする。
- 制約:$0\leq p<n$
- 計算量:$O(\log n)$
```cpp
S seg.prod(int l,int r)
```
$\prod_{i\in[l,r)}{a_i}$を返す。ただし、$l=r$の時は$e$を返す。
- 制約:$0\leq l\leq r <n$
- 計算量:$O(\log n)$

```cpp
void seg.add(int pos,S x)
```
$a_{\text{pos}}\leftarrow \text{op}(a_{\text{pos}},x)$とする
- 制約:$0\leq \text{pos}<n$
- 計算量:$O(\log n)$

```cpp
S seg(int pos)
```
$a_{\text{pos}}$を返す。
- 制約:$0\leq \text{pos} <n$
- 計算量:$O(1)$