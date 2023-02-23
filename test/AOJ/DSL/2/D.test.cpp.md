---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segtree.hpp
    title: "lazy segtree(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL/2/D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#line 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing ll = long long;\n//using i128=__int128_t;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst\
    \ long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
    const int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1 };\ntemplate<class\
    \ T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T\
    \ y){if(x>y)x=y;}\n#line 1 \"data-structure/lazy_segtree.hpp\"\ntemplate<\n  \
    \  class S, class F,\n    S(*op)(S, S), S(*e)(),\n    F(*comp)(F, F), F(*id)(),\n\
    \    S(*mapping)(S, F)\n>\nclass lazy_segtree {\n    int sz;\n    vector<S> dat;\n\
    \    vector<F> lz;\npublic:\n    lazy_segtree(int n) :lazy_segtree(vector<S>(n,\
    \ e())) {    }\n    lazy_segtree(const vector<S>& a) :dat(4 * a.size(), e()),\
    \ lz(4 * a.size(), id()) {\n        int x = 1;\n        while (a.size() > x) {\n\
    \            x <<= 1;\n        }\n        sz = x;\n        for (int i = 0; i <\
    \ a.size(); i++) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\npublic:\n    void set(int pos, S x) {\n        assert(0 <= pos && pos <\
    \ sz);\n        dat[pos + sz - 1] = x;\n    }\n    void build() {\n        for\
    \ (int i = sz - 2; i >= 0; i--) {\n            dat[i] = op(dat[2 * i + 1], dat[2\
    \ * i + 2]);\n        }\n    }\n\nprivate:\n    void eval(int pos) {\n       \
    \ if (lz[pos] == id()) return;\n        if (pos < sz - 1) {\n            lz[2\
    \ * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n            lz[2 * pos + 2] =\
    \ comp(lz[2 * pos + 2], lz[pos]);\n        }\n        dat[pos] = mapping(dat[pos],\
    \ lz[pos]);\n        lz[pos] = id();\n    }\n\nprivate:\n    void update(int L,\
    \ int R, int l, int r, F x, int k) {\n        eval(k);\n        if (L <= l &&\
    \ r <= R) {\n            lz[k] = comp(lz[k], x);\n            eval(k);\n     \
    \   }\n        else if (L < r && l < R) {\n            int mid = (l + r) >> 1;\n\
    \            update(L, R, l, mid, x, 2 * k + 1);\n            update(L, R, mid,\
    \ r, x, 2 * k + 2);\n            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n\
    \        }\n    }\npublic:\n    void update(int l, int r, F x) {\n        assert(0\
    \ <= l && l <= r && r <= sz);\n        update(l, r, 0, sz, x, 0);\n    }\n\nprivate:\n\
    \    S prod(int L, int R, int l, int r, int k) {\n        eval(k);\n        if\
    \ (r <= L || R <= l) {\n            return e();\n        }\n        else if (L\
    \ <= l && r <= R) {\n            return dat[k];\n        }\n        else {\n \
    \           int mid = (l + r) >> 1;\n            S vl = prod(L, R, l, mid, 2 *\
    \ k + 1);\n            S vr = prod(L, R, mid, r, 2 * k + 2);\n            return\
    \ op(vl, vr);\n        }\n    }\n\npublic:\n    S prod(int l, int r) {\n     \
    \   assert(0 <= l && l <= r && r <= sz);\n        return prod(l, r, 0, sz, 0);\n\
    \    }\n\n    S operator[](int pos) {\n        return prod(pos, pos + 1);\n  \
    \  }\n};\n//@brief lazy segtree(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728)\n#line 5 \"test/AOJ/DSL/2/D.test.cpp\"\n\nint op(int x,int y){return\
    \ min(x,y);}\nint comp(int x,int y){return y;}\nint mapping(int x,int y){return\
    \ y;}\nint e(){return (1ll<<31)-1;}\nint id(){return (1ll<<31)-1;}\n\nint main(){\n\
    \    int n,q;\n    cin>>n>>q;\n    lazy_segtree<int,int,op,e,comp,id,mapping>\
    \ seg(n);\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int l,r;\n            cin>>l>>r;\n            int new_val;\n    \
    \        cin>>new_val;\n            seg.update(l,r+1,new_val);\n        }else{\n\
    \            int i;\n            cin>>i;\n            cout<<seg[i]<<'\\n';\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/lazy_segtree.hpp\"\n\n\
    int op(int x,int y){return min(x,y);}\nint comp(int x,int y){return y;}\nint mapping(int\
    \ x,int y){return y;}\nint e(){return (1ll<<31)-1;}\nint id(){return (1ll<<31)-1;}\n\
    \nint main(){\n    int n,q;\n    cin>>n>>q;\n    lazy_segtree<int,int,op,e,comp,id,mapping>\
    \ seg(n);\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int l,r;\n            cin>>l>>r;\n            int new_val;\n    \
    \        cin>>new_val;\n            seg.update(l,r+1,new_val);\n        }else{\n\
    \            int i;\n            cin>>i;\n            cout<<seg[i]<<'\\n';\n \
    \       }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2/D.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 14:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2/D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2/D.test.cpp
- /verify/test/AOJ/DSL/2/D.test.cpp.html
title: test/AOJ/DSL/2/D.test.cpp
---
