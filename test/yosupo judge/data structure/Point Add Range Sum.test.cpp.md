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
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo judge/data structure/Point Add Range Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#line\
    \ 1 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    const int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll MOD2 = 998244353;\n\
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
    \u30C8\u6728)\n#line 4 \"test/yosupo judge/data structure/Point Add Range Sum.test.cpp\"\
    \nll op(ll x,ll y){return x+y;}\nll e(){return 0;}\nint main(){\n    int n,q;\n\
    \    cin>>n>>q;\n    vector<ll> a(n);\n    for(auto&aa:a){\n        cin>>aa;\n\
    \    }\n\n    segtree<ll,op,e> seg(a);\n    while(q--){\n        int t;\n    \
    \    cin>>t;\n        if(t==0){\n            int p,x;\n            cin>>p>>x;\n\
    \            seg.add(p,x);\n        }else{\n            int l,r;\n           \
    \ cin>>l>>r;\n            cout<<seg.prod(l,r)<<'\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nll op(ll x,ll\
    \ y){return x+y;}\nll e(){return 0;}\nint main(){\n    int n,q;\n    cin>>n>>q;\n\
    \    vector<ll> a(n);\n    for(auto&aa:a){\n        cin>>aa;\n    }\n\n    segtree<ll,op,e>\
    \ seg(a);\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int p,x;\n            cin>>p>>x;\n            seg.add(p,x);\n   \
    \     }else{\n            int l,r;\n            cin>>l>>r;\n            cout<<seg.prod(l,r)<<'\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  requiredBy: []
  timestamp: '2023-02-28 13:51:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Point Add Range Sum.test.cpp
- /verify/test/yosupo judge/data structure/Point Add Range Sum.test.cpp.html
title: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
---
