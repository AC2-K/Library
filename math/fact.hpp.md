---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1/NTL_1_A.test.cpp
    title: test/AOJ/NTL/1/NTL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
    links: []
  bundledCode: "#line 1 \"math/fact.hpp\"\nvector<pair<ll, ll>> fact(ll n) {\n   \
    \ vector<pair<ll, ll>> ret;\n    for (ll div = 2; div * div <= n; div++) {\n \
    \       if (n % div != 0)continue;\n        ll exp = 0;\n        while (n % div\
    \ == 0) {\n            exp++;\n            n /= div;\n        }\n        ret.push_back(make_pair(div,\
    \ exp));\n    }\n    if (n != 1)ret.push_back(make_pair(n, 1));\n    return ret;\n\
    }\n///@brief factorize(\u7D20\u56E0\u6570\u5206\u89E3)\n"
  code: "vector<pair<ll, ll>> fact(ll n) {\n    vector<pair<ll, ll>> ret;\n    for\
    \ (ll div = 2; div * div <= n; div++) {\n        if (n % div != 0)continue;\n\
    \        ll exp = 0;\n        while (n % div == 0) {\n            exp++;\n   \
    \         n /= div;\n        }\n        ret.push_back(make_pair(div, exp));\n\
    \    }\n    if (n != 1)ret.push_back(make_pair(n, 1));\n    return ret;\n}\n///@brief\
    \ factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
  dependsOn: []
  isVerificationFile: false
  path: math/fact.hpp
  requiredBy: []
  timestamp: '2023-02-23 13:41:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1/NTL_1_A.test.cpp
documentation_of: math/fact.hpp
layout: document
redirect_from:
- /library/math/fact.hpp
- /library/math/fact.hpp.html
title: "factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
---
