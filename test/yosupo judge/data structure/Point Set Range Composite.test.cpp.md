---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: math/prime_mint.hpp
    title: modint
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
  bundledCode: "#line 1 \"test/yosupo judge/data structure/Point Set Range Composite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\ntemplate<class S, S(*op)(S,\
    \ S), S(*e)()>\nclass segtree {\n    int n;\n    vector<S> dat;\n    void Init(int\
    \ n_) {\n        int x = 1;\n        while (n_ > x) {\n            x <<= 1;\n\
    \        }\n        n = x;\n    }\npublic:\n    segtree(int n_) : segtree(vector<S>(n_,\
    \ e())) {   }\n    segtree(const vector<S>& v) :dat(4 * v.size()) {\n        Init(v.size());\n\
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
    \u30C8\u6728)\n#line 1 \"math/prime_mint.hpp\"\ntemplate<const ll mod>class modint\
    \ {\nprivate:\n\tusing mint = modint<mod>;\n\tll value = 0;\npublic:\n\tmodint(ll\
    \ v = 0) {\n\t\tv %= mod;\n\t\tif(v < 0)v += mod;\n\t\tvalue = v;\n\t}\n\tll val()\
    \ {\n\t\treturn value % mod;\n\t}\n\tmint operator+(mint fp) {\n\t\treturn mint(value\
    \ + fp.val());\n\t}\n\tmint operator-(mint fp) {\n\t\treturn mint(value - fp.val());\n\
    \t}\n\tmint operator*(mint fp) {\n\t\treturn mint(value * fp.val());\n\t}\n\t\
    void operator=(mint fp) {\n\t\tvalue = fp.val();\n\t}\n\tvoid operator=(ll val)\
    \ {\n\t\tvalue = val % mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\
    \t}\n\tvoid operator+=(mint fp) {\n\t\t(value += fp.val()) %= mod;\n\t\tif(value\
    \ < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t}\n\tvoid operator-=(mint fp) {\n\t\t\
    value = value - fp.val();\n\t\tvalue %= mod;\n\t\tif(value < 0) {\n\t\t\tvalue\
    \ += mod;\n\t\t}\n\t}\n\tvoid operator*=(mint fp) {\n\t\tvalue = value * fp.val();\n\
    \t\tvalue = value % mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t\
    }\n\tbool operator==(mint fp) {\n\t\treturn value == fp.val();\n\t}\n\tbool operator<(mint\
    \ fp) {\n\t\treturn value < fp.val();\n\t}\n\tbool operator>(mint fp) {\n\t\t\
    return value > fp.val();\n\t}\n\tbool operator<=(mint fp) {\n\t\treturn value\
    \ <= fp.val();\n\t}\n\tbool operator>=(mint fp) {\n\t\treturn value >= fp.val();\n\
    \t}\n\n\tll inv() {\n\t\treturn mod_pow(mod - 2);\n\t}\n\tll mod_pow(ll exp) {\n\
    \t\tll base = value;\n\t\tll ans = 1;\n\t\tbase %= mod;\n\t\twhile (exp > 0) {\n\
    \t\t\tif (exp & 1) {\n\t\t\t\tans *= base;\n\t\t\t\tans %= mod;\n\t\t\t}\n\t\t\
    \tbase *= base;\n\t\t\tbase %= mod;\n\t\t\texp >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\tstatic ll mod_pow(ll base,ll exp){\n\t\tll ans = 1;\n\t\tbase %= mod;\n\
    \t\twhile (exp > 0) {\n\t\t\tif (exp & 1) {\n\t\t\t\tans *= base;\n\t\t\t\tans\
    \ %= mod;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\tbase %= mod;\n\t\t\texp >>= 1;\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tmint operator/(mint a) {\n\t\treturn mint(a.inv()*value);\n\
    \t}\n\tvoid operator/=(mint a) {\n\t\tvalue = value * a.inv();\n\t\tvalue %= mod;\n\
    \t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\tll v;\n\t\tis\
    \ >> v;\n\t\tmt = mint(v);\n\t\treturn is;\n\t}\n\tfriend ostream& operator <<\
    \ (ostream& os, mint& mt) {\n\t\treturn os << mt.val();\n\t}\n};\n\n///@brief\
    \ modint\n#line 5 \"test/yosupo judge/data structure/Point Set Range Composite.test.cpp\"\
    \nusing mint=modint<MOD2>;\n\nstruct F\n{\n    mint a,b;\n};\n\nF op(F l,F r){\n\
    \    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n    return F{na,\
    \ nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int n,q;\n    cin>>n>>q;\n\
    \    segtree<F,op,e> seg(n);\n    rep(i,n){\n        mint a,b;\n        cin>>a>>b;\n\
    \        seg.set(i,F{a,b});\n    }\n    seg.build();\n    while(q--){\n      \
    \  int t;\n        cin>>t;\n        if(t==0){\n            int p;\n          \
    \  mint c,d;\n            cin>>p>>c>>d;\n            seg.update(p,F{c,d});\n \
    \       }else{\n            int l,r;\n            mint x;\n            cin>>l>>r>>x;\n\
    \            F res=seg.prod(l,r);\n            mint ans=res.a*x+res.b;\n     \
    \       cout<<ans<<'\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"\
    math/prime_mint.hpp\"\nusing mint=modint<MOD2>;\n\nstruct F\n{\n    mint a,b;\n\
    };\n\nF op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb = (l.b * r.a + r.b);\n\
    \    return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\nint main() {\n    int\
    \ n,q;\n    cin>>n>>q;\n    segtree<F,op,e> seg(n);\n    rep(i,n){\n        mint\
    \ a,b;\n        cin>>a>>b;\n        seg.set(i,F{a,b});\n    }\n    seg.build();\n\
    \    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n       \
    \     int p;\n            mint c,d;\n            cin>>p>>c>>d;\n            seg.update(p,F{c,d});\n\
    \        }else{\n            int l,r;\n            mint x;\n            cin>>l>>r>>x;\n\
    \            F res=seg.prod(l,r);\n            mint ans=res.a*x+res.b;\n     \
    \       cout<<ans<<'\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - math/prime_mint.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp.html
title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
---
