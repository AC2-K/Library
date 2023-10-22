---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/5_B.test.cpp
    title: test/AOJ/DSL/5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
    title: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,\
    \ N) for (int i = 0; i < (N); i++)\n#define all(x) std::begin(x), std::end(x)\n\
    #define popcount(x) __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing graph = std::vector<std::vector<int>>;\n\
    using P = std::pair<int, int>;\nconstexpr int inf = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max() / 2;\nconstexpr ld\
    \ eps = 1e-12;\nconst long double pi = acosl(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\n\
    template <typename T1, typename T2> constexpr inline bool chmax(T1& a, T2 b) {\n\
    \    return a < b && (a = b, true);\n}\ntemplate <typename T1, typename T2> constexpr\
    \ inline bool chmin(T1& a, T2 b) {\n    return a > b && (a = b, true);\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#define rep(i, N) for (int i = 0;\
    \ i < (N); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconstexpr ld eps = 1e-12;\nconst\
    \ long double pi = acosl(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr\
    \ int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename\
    \ T2> constexpr inline bool chmax(T1& a, T2 b) {\n    return a < b && (a = b,\
    \ true);\n}\ntemplate <typename T1, typename T2> constexpr inline bool chmin(T1&\
    \ a, T2 b) {\n    return a > b && (a = b, true);\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2023-09-06 14:57:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  - test/yosupo_judge/polynomial/Exp of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/yosupo_judge/math/Number_of_Subsequences.test.cpp
  - test/yosupo_judge/new/Range_Reverse_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - test/AOJ/DSL/5_B.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: src/template.hpp
---
