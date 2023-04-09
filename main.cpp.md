---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Z algorithm
    links: []
  bundledCode: "#line 2 \"main.cpp\"\n#include <cassert>\r\n#include <string>\r\n\
    #include <vector>\r\nnamespace kyopro {\r\n/// @brief Z algorithm\r\n/// @return\
    \ LCP(S,S[i:]) (i=0,1,...,|str|-1)\r\nstd::vector<int> Z(const std::string& str)\
    \ {\r\n    assert(str.size());\r\n    std::vector<int> res(str.size());\r\n  \
    \  res.front() = (int)str.size();\r\n\r\n    int i = 1, j = 0;\r\n\r\n    while\
    \ (i < (int)str.size()) {\r\n        while (i + j < (int)str.size() && str[j]\
    \ == str[i + j]) {\r\n            j++;\r\n        }\r\n\r\n        res[i] = j;\r\
    \n        if (j == 0) {\r\n            i++;\r\n            continue;\r\n     \
    \   }\r\n        int k = 1;\r\n        while (i + k < (int)str.size() && k + res[k]\
    \ < j) {\r\n            res[i + k] = res[k];\r\n            k++;\r\n        }\r\
    \n        i += k, j -= k;\r\n    }\r\n    return res;\r\n}\r\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\r\n#include <cassert>\r\n#include <string>\r\n#include <vector>\r\
    \nnamespace kyopro {\r\n/// @brief Z algorithm\r\n/// @return LCP(S,S[i:]) (i=0,1,...,|str|-1)\r\
    \nstd::vector<int> Z(const std::string& str) {\r\n    assert(str.size());\r\n\
    \    std::vector<int> res(str.size());\r\n    res.front() = (int)str.size();\r\
    \n\r\n    int i = 1, j = 0;\r\n\r\n    while (i < (int)str.size()) {\r\n     \
    \   while (i + j < (int)str.size() && str[j] == str[i + j]) {\r\n            j++;\r\
    \n        }\r\n\r\n        res[i] = j;\r\n        if (j == 0) {\r\n          \
    \  i++;\r\n            continue;\r\n        }\r\n        int k = 1;\r\n      \
    \  while (i + k < (int)str.size() && k + res[k] < j) {\r\n            res[i +\
    \ k] = res[k];\r\n            k++;\r\n        }\r\n        i += k, j -= k;\r\n\
    \    }\r\n    return res;\r\n}\r\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-04-09 12:27:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: Z algorithm
---
