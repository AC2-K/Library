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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo judge/new/Longest Increasing Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
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
    \ op(dat[sz + p], v));\n\t}\n};\n#line 4 \"test/yosupo judge/new/Longest Increasing\
    \ Subsequence.test.cpp\"\nusing S = P;\nS op(S x, S y) { return max(x,y); }\n\
    S e() { return P(0,0); }\nvector<int> press(const vector<int>&A){\n    vector<int>\
    \ B;\n    vector<int> T;\n    rep(i,A.size())T.push_back(A[i]);\n    sort(all(T));\n\
    \    T.erase(unique(all(T)),T.end());\n    rep(i,A.size()){\n        int pos=lower_bound(all(T),A[i])-T.begin();\n\
    \        B.push_back(pos);\n    }\n    return B;\n}\nint main() {\n    int n;\n\
    \    cin>>n;\n    vector<int> a(n);\n    for(auto&aa:a){\n        cin>>aa;\n \
    \   }   \n    a=press(a);\n    vector<int> prv(n,-1);\n    iota(all(prv),0);\n\
    \    segtree<S,op,e> dp(n+1);\n    rep(i,n){\n        auto[mx,p]=dp.prod(0,a[i]);\n\
    \        if(mx+1>=dp[a[i]].first){\n            prv[i]=p;\n            dp.update(a[i],P(mx+1,i));\n\
    \        }\n    }\n    auto[res,cur]=dp.prod(0,n+1);\n    vector<int> idx;\n \
    \   rep(i,res){\n        idx.push_back(cur);\n        cur=prv[cur];\n    }\n \
    \   cout<<idx.size()<<'\\n';\n    reverse(all(idx));\n    for(auto&i:idx){\n \
    \       cout<<i<<' ';\n    }\n    cout<<'\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\nusing S =\
    \ P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\nvector<int>\
    \ press(const vector<int>&A){\n    vector<int> B;\n    vector<int> T;\n    rep(i,A.size())T.push_back(A[i]);\n\
    \    sort(all(T));\n    T.erase(unique(all(T)),T.end());\n    rep(i,A.size()){\n\
    \        int pos=lower_bound(all(T),A[i])-T.begin();\n        B.push_back(pos);\n\
    \    }\n    return B;\n}\nint main() {\n    int n;\n    cin>>n;\n    vector<int>\
    \ a(n);\n    for(auto&aa:a){\n        cin>>aa;\n    }   \n    a=press(a);\n  \
    \  vector<int> prv(n,-1);\n    iota(all(prv),0);\n    segtree<S,op,e> dp(n+1);\n\
    \    rep(i,n){\n        auto[mx,p]=dp.prod(0,a[i]);\n        if(mx+1>=dp[a[i]].first){\n\
    \            prv[i]=p;\n            dp.update(a[i],P(mx+1,i));\n        }\n  \
    \  }\n    auto[res,cur]=dp.prod(0,n+1);\n    vector<int> idx;\n    rep(i,res){\n\
    \        idx.push_back(cur);\n        cur=prv[cur];\n    }\n    cout<<idx.size()<<'\\\
    n';\n    reverse(all(idx));\n    for(auto&i:idx){\n        cout<<i<<' ';\n   \
    \ }\n    cout<<'\\n';\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 19:44:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
- /verify/test/yosupo judge/new/Longest Increasing Subsequence.test.cpp.html
title: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
---
