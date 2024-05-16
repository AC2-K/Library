---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/3_D.test.cpp
    title: test/AOJ/DSL/3_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/5_B.test.cpp
    title: test/AOJ/DSL/5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/P1508.test.cpp
    title: test/AOJ/P1508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Subset_Convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
    title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
    title: test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
    title: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/graph/Shortest_Path.test.cpp
    title: test/yosupo_judge/graph/Shortest_Path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
    title: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
    title: test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/polynomial/Exp_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
    title: test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Tree_Diameter.test.cpp
    title: test/yosupo_judge/tree/Tree_Diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Template
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i,\
    \ n) for (int i = 0; i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n\
    #define popcount(x) __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing graph = std::vector<std::vector<int>>;\n\
    using P = std::pair<int, int>;\nconstexpr int inf = std::numeric_limits<int>::max()\
    \ / 2;\nconstexpr ll infl = std::numeric_limits<ll>::max() / 2;\nconst long double\
    \ pi = acosl(-1);\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr\
    \ int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename\
    \ T2> constexpr inline bool chmax(T1& a, T2 b) {\n    return a < b && (a = b,\
    \ true);\n}\ntemplate <typename T1, typename T2> constexpr inline bool chmin(T1&\
    \ a, T2 b) {\n    return a > b && (a = b, true);\n}\n\n/**\n * @brief Template\n\
    */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#define rep(i, n) for (int i = 0;\
    \ i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconst long double pi = acosl(-1);\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmax(T1& a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a >\
    \ b && (a = b, true);\n}\n\n/**\n * @brief Template\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/template.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/P1508.test.cpp
  - test/AOJ/DSL/5_B.test.cpp
  - test/AOJ/DSL/3_D.test.cpp
  - test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
  - test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  - test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Set_Path_Composite.test.cpp
  - test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  - test/yosupo_judge/data_structure/Range_Reverse_Range_Sum.test.cpp
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Log of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Polynomial_Taylor_Shift.test.cpp
  - test/yosupo_judge/polynomial/Pow_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Inv_of Formal_Power_Series.test.cpp
  - test/yosupo_judge/polynomial/Exp_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/graph/Shortest_Path.test.cpp
  - test/yosupo_judge/math/Number_of_Subsequences.test.cpp
  - test/yosupo_judge/matrix/Pow_of_Matrix.test.cpp
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  - test/yosupo_judge/convolution/Bitwise_And_Convolution.test.cpp
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Convex.test.cpp
  - test/yosupo_judge/convolution/Subset_Convolution.test.cpp
  - test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  - test/yosupo_judge/tree/Tree_Diameter.test.cpp
documentation_of: src/template.hpp
layout: document
redirect_from:
- /library/src/template.hpp
- /library/src/template.hpp.html
title: Template
---
