---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/GRL/5/C.cpp
    title: test/AOJ/GRL/5/C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: main.test.cpp
    title: main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/1/C.test.cpp
    title: test/AOJ/ALDS/1/C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/14/B.test.cpp
    title: test/AOJ/ALDS/14/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/1/A.test.cpp
    title: test/AOJ/DSL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/B.test.cpp
    title: test/AOJ/DSL/2/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/D.test.cpp
    title: test/AOJ/DSL/2/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/E.test.cpp
    title: test/AOJ/DSL/2/E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/1/A.test.cpp
    title: test/AOJ/GRL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/2/A.test.cpp
    title: test/AOJ/GRL/2/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/A.test.cpp
    title: test/AOJ/NTL/1/A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/B.test.cpp
    title: test/AOJ/NTL/1/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/D.test.cpp
    title: test/AOJ/NTL/1/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/E.test.cpp
    title: test/AOJ/NTL/1/E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Line Add Get Min.test.cpp
    title: test/yosupo judge/data structure/Line Add Get Min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
    title: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
    title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Static RMQ.test.cpp
    title: test/yosupo judge/data structure/Static RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Static Range Sum.test.cpp
    title: test/yosupo judge/data structure/Static Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/UnionFind.test.cpp
    title: test/yosupo judge/data structure/UnionFind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/graph/Shortest Path.test.cpp
    title: test/yosupo judge/graph/Shortest Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Discrete Logarithm.test.cpp
    title: test/yosupo judge/math/Discrete Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/math/Factorize.test.cpp
    title: test/yosupo judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
    title: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Primitive Root.test.cpp
    title: test/yosupo judge/new/Primitive Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
    title: test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/tree/Tree Diameter.test.cpp
    title: test/yosupo judge/tree/Tree Diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "template.hpp"

    #include<bits/stdc++.h>

    using namespace std;

    #define rep(i, N)  for(int i=0;i<(N);i++)

    #define all(x) (x).begin(),(x).end()

    #define popcount(x) __builtin_popcount(x)

    using i128=__int128_t;

    using ll = long long;

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
  code: '#pragma once

    #include<bits/stdc++.h>

    using namespace std;

    #define rep(i, N)  for(int i=0;i<(N);i++)

    #define all(x) (x).begin(),(x).end()

    #define popcount(x) __builtin_popcount(x)

    using i128=__int128_t;

    using ll = long long;

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
  - test/AOJ/GRL/5/C.cpp
  timestamp: '2023-02-28 20:50:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - main.test.cpp
  - test/yosupo judge/math/Discrete Logarithm.test.cpp
  - test/yosupo judge/math/Factorize.test.cpp
  - test/yosupo judge/graph/Shortest Path.test.cpp
  - test/yosupo judge/tree/Lowest Common Ancestor.test.cpp
  - test/yosupo judge/tree/Tree Diameter.test.cpp
  - test/yosupo judge/data structure/Static Range Sum.test.cpp
  - test/yosupo judge/data structure/Line Add Get Min.test.cpp
  - test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - test/yosupo judge/data structure/UnionFind.test.cpp
  - test/yosupo judge/data structure/Static RMQ.test.cpp
  - test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  - test/yosupo judge/new/Primitive Root.test.cpp
  - test/AOJ/ALDS/1/C.test.cpp
  - test/AOJ/ALDS/14/B.test.cpp
  - test/AOJ/NTL/1/E.test.cpp
  - test/AOJ/NTL/1/A.test.cpp
  - test/AOJ/NTL/1/D.test.cpp
  - test/AOJ/NTL/1/B.test.cpp
  - test/AOJ/DSL/2/E.test.cpp
  - test/AOJ/DSL/2/D.test.cpp
  - test/AOJ/DSL/2/B.test.cpp
  - test/AOJ/DSL/1/A.test.cpp
  - test/AOJ/GRL/2/A.test.cpp
  - test/AOJ/GRL/1/A.test.cpp
documentation_of: template.hpp
layout: document
redirect_from:
- /library/template.hpp
- /library/template.hpp.html
title: template.hpp
---