---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree.hpp
    title: data-structure/segtree.hpp
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
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/segtree.hpp\"\
    \ntemplate<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\
    \tvector<S> dat;\n\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(vector<S>(n,\
    \ e())) {}\n\tsegtree(const vector<S>& vec) : n((int)vec.size()) {\n\t\tsz = 1,\
    \ lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\t\
    dat = vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tset(i,\
    \ vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const S&\
    \ v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i = sz\
    \ - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\t\t\
    }\n\t}\n\tS operator[](const int p) const { return dat[sz + p]; }\n\n\tinline\
    \ void update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p\
    \ >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\
    \n\tinline S prod(int l, int r) const {\n\t\tl += sz, r += sz;\n\t\tS sml = e(),\
    \ smr = e();\n\t\twhile (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\
    \t\t\tif (r & 1)smr = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\t\
    return op(sml, smr);\n\t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p,\
    \ op(dat[sz + p], v));\n\t}\n};\n#line 4 \"test/yosupo judge/data structure/Point\
    \ Add Range Sum.test.cpp\"\nll op(ll x,ll y){return x+y;}\nll e(){return 0;}\n\
    int main(){\n    int n,q;\n    cin>>n>>q;\n    vector<ll> a(n);\n    for(auto&aa:a){\n\
    \        cin>>aa;\n    }\n\n    segtree<ll,op,e> seg(a);\n    while(q--){\n  \
    \      int t;\n        cin>>t;\n        if(t==0){\n            int p,x;\n    \
    \        cin>>p>>x;\n            seg.apply(p,x);\n        }else{\n           \
    \ int l,r;\n            cin>>l>>r;\n            cout<<seg.prod(l,r)<<'\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nll op(ll x,ll\
    \ y){return x+y;}\nll e(){return 0;}\nint main(){\n    int n,q;\n    cin>>n>>q;\n\
    \    vector<ll> a(n);\n    for(auto&aa:a){\n        cin>>aa;\n    }\n\n    segtree<ll,op,e>\
    \ seg(a);\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            int p,x;\n            cin>>p>>x;\n            seg.apply(p,x);\n \
    \       }else{\n            int l,r;\n            cin>>l>>r;\n            cout<<seg.prod(l,r)<<'\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 19:44:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Point Add Range Sum.test.cpp
- /verify/test/yosupo judge/data structure/Point Add Range Sum.test.cpp.html
title: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
---
