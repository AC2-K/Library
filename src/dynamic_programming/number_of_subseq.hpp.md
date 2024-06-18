---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
    title: test/yosupo_judge/math/Number_of_Subsequences.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Count subsequences \u90E8\u5206\u5217\u306E\u500B\u6570"
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/26/135340
  bundledCode: "#line 2 \"src/dynamic_programming/number_of_subseq.hpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\nnamespace kyopro {\nnamespace number_of_subseq_impl\
    \ {\n\ntemplate <typename T> void comp(std::vector<T>& a) {\n    std::vector<T>\
    \ tmp(a);\n    std::sort(tmp.begin(), tmp.end());\n    tmp.erase(std::unique(tmp.begin(),tmp.end()),\
    \ tmp.end());\n    for (int i = 0; i < (int)a.size(); ++i) {\n        a[i] = lower_bound(tmp.begin(),\
    \ tmp.end(), a[i]) - tmp.begin();\n    }\n}\n\n};  // namespace number_of_subseq_impl\n\
    \n/**\n * @note Empty Sequence is included.\n*/\ntemplate <typename mint, typename\
    \ T>\nmint num_of_subseq(std::vector<T> a) {\n    number_of_subseq_impl::comp(a);\n\
    \    std::vector<mint> dp(a.size() + 1), sum(a.size() + 1);\n    sum[0] = mint(1);\n\
    \    for (int i = 0; i < (int)a.size(); ++i) {\n        sum[i + 1] = 2 * sum[i]\
    \ - dp[a[i]];\n        dp[a[i]] += sum[i] - dp[a[i]];\n    }\n    return sum[a.size()];\n\
    }\n};\n\n/**\n * @brief Count subsequences \u90E8\u5206\u5217\u306E\u500B\u6570\
    \n * @see https://noshi91.hatenablog.com/entry/2023/02/26/135340\n*/\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nnamespace kyopro\
    \ {\nnamespace number_of_subseq_impl {\n\ntemplate <typename T> void comp(std::vector<T>&\
    \ a) {\n    std::vector<T> tmp(a);\n    std::sort(tmp.begin(), tmp.end());\n \
    \   tmp.erase(std::unique(tmp.begin(),tmp.end()), tmp.end());\n    for (int i\
    \ = 0; i < (int)a.size(); ++i) {\n        a[i] = lower_bound(tmp.begin(), tmp.end(),\
    \ a[i]) - tmp.begin();\n    }\n}\n\n};  // namespace number_of_subseq_impl\n\n\
    /**\n * @note Empty Sequence is included.\n*/\ntemplate <typename mint, typename\
    \ T>\nmint num_of_subseq(std::vector<T> a) {\n    number_of_subseq_impl::comp(a);\n\
    \    std::vector<mint> dp(a.size() + 1), sum(a.size() + 1);\n    sum[0] = mint(1);\n\
    \    for (int i = 0; i < (int)a.size(); ++i) {\n        sum[i + 1] = 2 * sum[i]\
    \ - dp[a[i]];\n        dp[a[i]] += sum[i] - dp[a[i]];\n    }\n    return sum[a.size()];\n\
    }\n};\n\n/**\n * @brief Count subsequences \u90E8\u5206\u5217\u306E\u500B\u6570\
    \n * @see https://noshi91.hatenablog.com/entry/2023/02/26/135340\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/dynamic_programming/number_of_subseq.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Number_of_Subsequences.test.cpp
documentation_of: src/dynamic_programming/number_of_subseq.hpp
layout: document
redirect_from:
- /library/src/dynamic_programming/number_of_subseq.hpp
- /library/src/dynamic_programming/number_of_subseq.hpp.html
title: "Count subsequences \u90E8\u5206\u5217\u306E\u500B\u6570"
---