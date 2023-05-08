---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/manacher.hpp
    title: Manacher's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo_judge/string/Enumerate_Palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\
    #include <iostream>\n#line 2 \"src/string/manacher.hpp\"\n#include <cassert>\n\
    #include <string>\n#include <utility>\n#include <vector>\nnamespace kyopro {\n\
    \n/**\n * @brief Manacher's algorithm\n*/\nstd::vector<int> manacher(std::string\
    \ s, bool even = true) {\n    assert(s.size());\n    if (even) {\n        std::string\
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
    };  // namespace kyopro\n#line 4 \"test/yosupo_judge/string/Enumerate_Palindromes.test.cpp\"\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string s;\n    std::cin >> s;\n    auto res = kyopro::manacher(s);\n\
    \    for (const auto& r : res) {\n        std::cout << r << ' ';\n    }\n    std::cout\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n#include <iostream>\n#include \"../../../src/string/manacher.hpp\"\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    std::string\
    \ s;\n    std::cin >> s;\n    auto res = kyopro::manacher(s);\n    for (const\
    \ auto& r : res) {\n        std::cout << r << ' ';\n    }\n    std::cout << '\\\
    n';\n}"
  dependsOn:
  - src/string/manacher.hpp
  isVerificationFile: true
  path: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
- /verify/test/yosupo_judge/string/Enumerate_Palindromes.test.cpp.html
title: test/yosupo_judge/string/Enumerate_Palindromes.test.cpp
---
