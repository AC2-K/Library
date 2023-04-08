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
  bundledCode: '#line 1 "src/debug.hpp"

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
  path: src/debug.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/debug.hpp
layout: document
redirect_from:
- /library/src/debug.hpp
- /library/src/debug.hpp.html
title: src/debug.hpp
---
