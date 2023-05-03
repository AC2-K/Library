---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/Z.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo_judge/string/Z_algorithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include<iostream>\n\
    #include<string>\n\n#line 2 \"src/string/Z.hpp\"\n#include <cassert>\n#line 4\
    \ \"src/string/Z.hpp\"\n#include <vector>\nnamespace kyopro {\n/// @brief Z algorithm\n\
    /// @return LCP(S,S[i:]) (i=0,1,...,|str|-1)\nstd::vector<int> Z(const std::string&\
    \ str) {\n    assert(str.size());\n    std::vector<int> res(str.size());\n   \
    \ res.front() = (int)str.size();\n\n    int i = 1, j = 0;\n\n    while (i < (int)str.size())\
    \ {\n        while (i + j < (int)str.size() && str[j] == str[i + j]) {\n     \
    \       ++j;\n        }\n\n        res[i] = j;\n        if (j == 0) {\n      \
    \      ++i;\n            continue;\n        }\n        int k = 1;\n        while\
    \ (i + k < (int)str.size() && k + res[k] < j) {\n            res[i + k] = res[k];\n\
    \            ++k;\n        }\n        i += k, j -= k;\n    }\n    return res;\n\
    }\n};  // namespace kyopro\n#line 6 \"test/yosupo_judge/string/Z_algorithm.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    std::string s;\n    std::cin >> s;\n    auto res = kyopro::Z(s);\n    for(const\
    \ auto&r:res){\n        std::cout << r << ' ';\n    }\n    std::cout << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include<iostream>\n\
    #include<string>\n\n#include\"../../../src/string/Z.hpp\"\n\nint main() {\n  \
    \  std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    std::string\
    \ s;\n    std::cin >> s;\n    auto res = kyopro::Z(s);\n    for(const auto&r:res){\n\
    \        std::cout << r << ' ';\n    }\n    std::cout << '\\n';\n}"
  dependsOn:
  - src/string/Z.hpp
  isVerificationFile: true
  path: test/yosupo_judge/string/Z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2023-05-03 22:08:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/string/Z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/string/Z_algorithm.test.cpp
- /verify/test/yosupo_judge/string/Z_algorithm.test.cpp.html
title: test/yosupo_judge/string/Z_algorithm.test.cpp
---
