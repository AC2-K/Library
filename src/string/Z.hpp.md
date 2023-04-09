---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/yosupo_judge/string/Z_algorithm.hpp
    title: test/yosupo_judge/string/Z_algorithm.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Z algorithm
    links: []
  bundledCode: "#line 2 \"src/string/Z.hpp\"\n#include <cassert>\n#include <string>\n\
    #include <vector>\nnamespace kyopro {\n/// @brief Z algorithm\n/// @return LCP(S,S[i:])\
    \ (i=0,1,...,|str|-1)\nstd::vector<int> Z(const std::string& str) {\n    assert(str.size());\n\
    \    std::vector<int> res(str.size());\n    res.front() = (int)str.size();\n\n\
    \    int i = 1, j = 0;\n\n    while (i < (int)str.size()) {\n        while (i\
    \ + j < (int)str.size() && str[j] == str[i + j]) {\n            j++;\n       \
    \ }\n\n        res[i] = j;\n        if (j == 0) {\n            i++;\n        \
    \    continue;\n        }\n        int k = 1;\n        while (i + k < (int)str.size()\
    \ && k + res[k] < j) {\n            res[i + k] = res[k];\n            k++;\n \
    \       }\n        i += k, j -= k;\n    }\n    return res;\n}\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <string>\n#include <vector>\n\
    namespace kyopro {\n/// @brief Z algorithm\n/// @return LCP(S,S[i:]) (i=0,1,...,|str|-1)\n\
    std::vector<int> Z(const std::string& str) {\n    assert(str.size());\n    std::vector<int>\
    \ res(str.size());\n    res.front() = (int)str.size();\n\n    int i = 1, j = 0;\n\
    \n    while (i < (int)str.size()) {\n        while (i + j < (int)str.size() &&\
    \ str[j] == str[i + j]) {\n            j++;\n        }\n\n        res[i] = j;\n\
    \        if (j == 0) {\n            i++;\n            continue;\n        }\n \
    \       int k = 1;\n        while (i + k < (int)str.size() && k + res[k] < j)\
    \ {\n            res[i + k] = res[k];\n            k++;\n        }\n        i\
    \ += k, j -= k;\n    }\n    return res;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Z.hpp
  requiredBy:
  - test/yosupo_judge/string/Z_algorithm.hpp
  timestamp: '2023-04-09 12:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/Z.hpp
layout: document
redirect_from:
- /library/src/string/Z.hpp
- /library/src/string/Z.hpp.html
title: Z algorithm
---
