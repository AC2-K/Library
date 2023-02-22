---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: BabyStepGiantStep
    links: []
  bundledCode: "#line 1 \"math/BSGS.hpp\"\ntemplate<class S> bsgs(S s, S g, ll n,\
    \ ll m, const function<S(S)>& f, const function<S(S)>& fm) {\n    if(s == g){\n\
    \        return 0;\n    }\n    map<S, ll> mp;\n    for (int j = 1; j <= m; j++)\
    \ {\n        g = f(g);\n        mp[g] = j;\n    }\n    for (int i = 1;; i++) {\n\
    \        s = fm(s);\n\n        if (mp.find(s) != mp.end()) {\n            return\
    \ m * i - mp[s];\n        }\n\n        if (n <= m * i)break;\n    }\n    return\
    \ -1;\n}\n///@brief BabyStepGiantStep\n"
  code: "template<class S> bsgs(S s, S g, ll n, ll m, const function<S(S)>& f, const\
    \ function<S(S)>& fm) {\n    if(s == g){\n        return 0;\n    }\n    map<S,\
    \ ll> mp;\n    for (int j = 1; j <= m; j++) {\n        g = f(g);\n        mp[g]\
    \ = j;\n    }\n    for (int i = 1;; i++) {\n        s = fm(s);\n\n        if (mp.find(s)\
    \ != mp.end()) {\n            return m * i - mp[s];\n        }\n\n        if (n\
    \ <= m * i)break;\n    }\n    return -1;\n}\n///@brief BabyStepGiantStep"
  dependsOn: []
  isVerificationFile: false
  path: math/BSGS.hpp
  requiredBy: []
  timestamp: '2023-02-21 08:23:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/BSGS.hpp
layout: document
redirect_from:
- /library/math/BSGS.hpp
- /library/math/BSGS.hpp.html
title: BabyStepGiantStep
---
