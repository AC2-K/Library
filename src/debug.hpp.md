---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
    title: test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
    title: test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
    title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    document_title: Debugger
    links: []
  bundledCode: "#line 1 \"src/debug.hpp\"\n#ifdef ONLINE_JUDGE\n#define debug(x) void(0)\n\
    #else\n#define _GLIBCXX_DEBUG\n#define debug(x) std::cerr << __LINE__ << \" :\
    \ \" << #x << \" = \" << (x) << std::endl\n#endif\n\n/**\n * @brief Debugger\n\
    */\n"
  code: "#ifdef ONLINE_JUDGE\n#define debug(x) void(0)\n#else\n#define _GLIBCXX_DEBUG\n\
    #define debug(x) std::cerr << __LINE__ << \" : \" << #x << \" = \" << (x) << std::endl\n\
    #endif\n\n/**\n * @brief Debugger\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/debug.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/data_structure/Range Reverse_Range_Sum_SplayTree.test.cpp
  - test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  - test/yosupo_judge/convolution/Min_Plus_Convolution_Convex_and_Arbitrary.test.cpp
documentation_of: src/debug.hpp
layout: document
redirect_from:
- /library/src/debug.hpp
- /library/src/debug.hpp.html
title: Debugger
---
