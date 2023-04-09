---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/string/Z.hpp
    title: Z algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/yosupo_judge/string/Z_algorithm.hpp\"\n#include<iostream>\n\
    #include<string>\n\n#line 2 \"src/string/Z.hpp\"\n#include <cassert>\n#line 4\
    \ \"src/string/Z.hpp\"\n#include <vector>\nnamespace kyopro {\n/// @brief Z algorithm\n\
    /// @return LCP(S,S[i:]) (i=0,1,...,|str|-1)\nstd::vector<int> Z(const std::string&\
    \ str) {\n    assert(str.size());\n    std::vector<int> res(str.size());\n   \
    \ res.front() = (int)str.size();\n\n    int i = 1, j = 0;\n\n    while (i < (int)str.size())\
    \ {\n        while (i + j < (int)str.size() && str[j] == str[i + j]) {\n     \
    \       j++;\n        }\n\n        res[i] = j;\n        if (j == 0) {\n      \
    \      i++;\n            continue;\n        }\n        int k = 1;\n        while\
    \ (i + k < (int)str.size() && k + res[k] < j) {\n            res[i + k] = res[k];\n\
    \            k++;\n        }\n        i += k, j -= k;\n    }\n    return res;\n\
    }\n};  // namespace kyopro\n#line 5 \"test/yosupo_judge/string/Z_algorithm.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    std::string s;\n    std::cin >> s;\n    auto res = kyopro::Z(s);\n    for(const\
    \ auto&r:res){\n        std::cout << r << ' ';\n    }\n    std::cout << '\\n';\n\
    }\n"
  code: "#include<iostream>\n#include<string>\n\n#include\"../../../src/string/Z.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    std::string s;\n    std::cin >> s;\n    auto res = kyopro::Z(s);\n    for(const\
    \ auto&r:res){\n        std::cout << r << ' ';\n    }\n    std::cout << '\\n';\n\
    }"
  dependsOn:
  - src/string/Z.hpp
  isVerificationFile: false
  path: test/yosupo_judge/string/Z_algorithm.hpp
  requiredBy: []
  timestamp: '2023-04-09 12:37:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/yosupo_judge/string/Z_algorithm.hpp
layout: document
redirect_from:
- /library/test/yosupo_judge/string/Z_algorithm.hpp
- /library/test/yosupo_judge/string/Z_algorithm.hpp.html
title: test/yosupo_judge/string/Z_algorithm.hpp
---
