---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/Library-Checker/Longest Increasing Subsequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
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
    \u30C8\u6728)\n#line 4 \"test/Library-Checker/Longest Increasing Subsequence.test.cpp\"\
    \nusing S = P;\nS op(S x, S y) { return max(x,y); }\nS e() { return P(0,0); }\n\
    vector<int> press(const vector<int>&A){\n    vector<int> B;\n    vector<int> T;\n\
    \    rep(i,A.size())T.push_back(A[i]);\n    sort(all(T));\n    T.erase(unique(all(T)),T.end());\n\
    \    rep(i,A.size()){\n        int pos=lower_bound(all(T),A[i])-T.begin();\n \
    \       B.push_back(pos);\n    }\n    return B;\n}\nint main() {\n    int n;\n\
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
  path: test/Library-Checker/Longest Increasing Subsequence.test.cpp
  requiredBy: []
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Library-Checker/Longest Increasing Subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/Library-Checker/Longest Increasing Subsequence.test.cpp
- /verify/test/Library-Checker/Longest Increasing Subsequence.test.cpp.html
title: test/Library-Checker/Longest Increasing Subsequence.test.cpp
---
