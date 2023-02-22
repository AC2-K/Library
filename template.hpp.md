---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: main.cpp
    title: main.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':x:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_D.test.cpp
    title: test/AOJ/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_E.test.cpp
    title: test/AOJ/NTL_1_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Discrete Logarithm.test.cpp
    title: test/Library-Checker/Discrete Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Line Add Get Min.test.cpp
    title: test/Library-Checker/Line Add Get Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Longest Increasing Subsequence.test.cpp
    title: test/Library-Checker/Longest Increasing Subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Lowest Common Ancestor.test.cpp
    title: test/Library-Checker/Lowest Common Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Point Add Range Sum.test.cpp
    title: test/Library-Checker/Point Add Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Point Set Range Composite.test.cpp
    title: test/Library-Checker/Point Set Range Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Shortest Path.test.cpp
    title: test/Library-Checker/Shortest Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Static RMQ.test.cpp
    title: test/Library-Checker/Static RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Static Range Sum.test.cpp
    title: test/Library-Checker/Static Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Tree Diameter.test.cpp
    title: test/Library-Checker/Tree Diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/UnionFind.test.cpp
    title: test/Library-Checker/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Z algorithm with Hash.test.cpp
    title: test/Library-Checker/Z algorithm with Hash.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "template.hpp"

    #include<bits/stdc++.h>

    using namespace std;

    #define rep(i, N)  for(int i=0;i<(N);i++)

    #define all(x) (x).begin(),(x).end()

    #define popcount(x) __builtin_popcount(x)

    using ll = long long;

    //using i128=__int128_t;

    using ld = long double;

    using graph = vector<vector<int>>;

    using P = pair<int, int>;

    const int inf = 1e9;

    const ll infl = 1e18;

    const ld eps = 1e-6;

    const long double pi = acos(-1);

    const ll MOD = 1e9 + 7;

    const ll MOD2 = 998244353;

    const int dx[4] = { 1,0,-1,0 };

    const int dy[4] = { 0,1,0,-1 };

    template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}

    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}

    '
  code: '#include<bits/stdc++.h>

    using namespace std;

    #define rep(i, N)  for(int i=0;i<(N);i++)

    #define all(x) (x).begin(),(x).end()

    #define popcount(x) __builtin_popcount(x)

    using ll = long long;

    //using i128=__int128_t;

    using ld = long double;

    using graph = vector<vector<int>>;

    using P = pair<int, int>;

    const int inf = 1e9;

    const ll infl = 1e18;

    const ld eps = 1e-6;

    const long double pi = acos(-1);

    const ll MOD = 1e9 + 7;

    const ll MOD2 = 998244353;

    const int dx[4] = { 1,0,-1,0 };

    const int dy[4] = { 0,1,0,-1 };

    template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}

    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}'
  dependsOn: []
  isVerificationFile: false
  path: template.hpp
  requiredBy:
  - main.cpp
  timestamp: '2023-02-17 14:40:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/Library-Checker/Static Range Sum.test.cpp
  - test/Library-Checker/Z algorithm with Hash.test.cpp
  - test/Library-Checker/Discrete Logarithm.test.cpp
  - test/Library-Checker/Line Add Get Min.test.cpp
  - test/Library-Checker/Point Set Range Composite.test.cpp
  - test/Library-Checker/Lowest Common Ancestor.test.cpp
  - test/Library-Checker/UnionFind.test.cpp
  - test/Library-Checker/Tree Diameter.test.cpp
  - test/Library-Checker/Longest Increasing Subsequence.test.cpp
  - test/Library-Checker/Shortest Path.test.cpp
  - test/Library-Checker/Static RMQ.test.cpp
  - test/Library-Checker/Point Add Range Sum.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/NTL_1_D.test.cpp
  - test/AOJ/NTL_1_E.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---
