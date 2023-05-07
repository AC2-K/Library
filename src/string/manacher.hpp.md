---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
    title: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Manacher's algorithm
    links: []
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n#include <cassert>\n#include\
    \ <string>\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\n/**\n\
    \ * @brief Manacher's algorithm\n*/\nstd::vector<int> manacher(std::string s,\
    \ bool even = true) {\n    assert(s.size());\n    if (even) {\n        std::string\
    \ t;\n        t.resize(2 * (int)s.size() - 1);\n        for (int i = 0; i < (int)s.size();\
    \ i++) {\n            t[2 * i] = s[i];\n        }\n        for (int i = 0; i <\
    \ (int)s.size(); i++) {\n            t[2 * i + 1] = '$';\n        }\n        std::swap(t,\
    \ s);\n    }\n    std::vector<int> res(s.size());\n\n    int i = 0, j = 0;\n\n\
    \    while (i < (int)s.size()) {\n        while (i - j >= 0 && i + j < (int)s.size()\
    \ && s[i - j] == s[i + j]) {\n            j++;\n        }\n        res[i] = j;\n\
    \n        int k = 1;\n        while (i - k >= 0 && i + k < (int)s.size() && k\
    \ + res[i - k] < j) {\n            res[i + k] = res[i - k], k++;\n        }\n\
    \        i += k, j -= k;\n    }\n\n    if (even) {\n        for (int i = 0; i\
    \ < (int)res.size(); i++) {\n            if (~(i ^ res[i]) & 1) {\n          \
    \      res[i]--;\n            }\n        }\n    } else {\n        for (auto& r\
    \ : res) {\n            r = 2 * r - 1;\n        }\n    }\n    return res;\n}\n\
    };  // namespace kyopro\n"
  code: "#pragma once\n#include <cassert>\n#include <string>\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\n\n/**\n * @brief Manacher's algorithm\n\
    */\nstd::vector<int> manacher(std::string s, bool even = true) {\n    assert(s.size());\n\
    \    if (even) {\n        std::string t;\n        t.resize(2 * (int)s.size() -\
    \ 1);\n        for (int i = 0; i < (int)s.size(); i++) {\n            t[2 * i]\
    \ = s[i];\n        }\n        for (int i = 0; i < (int)s.size(); i++) {\n    \
    \        t[2 * i + 1] = '$';\n        }\n        std::swap(t, s);\n    }\n   \
    \ std::vector<int> res(s.size());\n\n    int i = 0, j = 0;\n\n    while (i < (int)s.size())\
    \ {\n        while (i - j >= 0 && i + j < (int)s.size() && s[i - j] == s[i + j])\
    \ {\n            j++;\n        }\n        res[i] = j;\n\n        int k = 1;\n\
    \        while (i - k >= 0 && i + k < (int)s.size() && k + res[i - k] < j) {\n\
    \            res[i + k] = res[i - k], k++;\n        }\n        i += k, j -= k;\n\
    \    }\n\n    if (even) {\n        for (int i = 0; i < (int)res.size(); i++) {\n\
    \            if (~(i ^ res[i]) & 1) {\n                res[i]--;\n           \
    \ }\n        }\n    } else {\n        for (auto& r : res) {\n            r = 2\
    \ * r - 1;\n        }\n    }\n    return res;\n}\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: Manacher's algorithm
---
