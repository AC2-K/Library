---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "debug.hpp"

    #ifdef ONLINE_JUDGE


    #define debug(x) void(0)

    #else

    #define _GLIBCXX_DEBUG

    #define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl

    #endif

    '
  code: '#ifdef ONLINE_JUDGE


    #define debug(x) void(0)

    #else

    #define _GLIBCXX_DEBUG

    #define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl

    #endif'
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2023-02-28 13:51:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
