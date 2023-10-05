---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u90E8\u5206\u5217\u306E\u500B\u6570"
    links:
    - https://noshi91.hatenablog.com/entry/2023/02/26/135340
  bundledCode: "#line 1 \"src/dynamic_programming/number_of_subseq.hpp\"\n#include<vector>\n\
    \nnamespace kyopro {\nnamespace number_of_subseq_impl {\n\ntemplate <typename\
    \ T> void comp(vector<T>& a) {\n    vector<T> tmp(a);\n    sort(tmp.begin(), tmp.end());\n\
    \    tmp.erase(unique(all(tmp)), tmp.end());\n    for (int i = 0; i < (int)a.size();\
    \ ++i) {\n        a[i] = lower_bound(all(tmp), a[i]) - tmp.begin();\n    }\n}\n\
    \n};  // namespace number_of_subseq_impl\n \n/// @return Number of subsequence\
    \ of a  (including empty sequence)\ntemplate <typename mint, typename T>\nmint\
    \ num_of_subseq(std::vector<T> a) {\n    number_of_subseq_impl::comp(a);\n   \
    \ sum[0] = mint::(1);\n    rep(i, n) {\n        sum[i + 1] = 2 * sum[i] - dp[a[i]];\n\
    \        dp[a[i]] += sum[i] - dp[a[i]];\n    }\n    return sum[n];\n}\n};\n\n\
    /**\n * @brief \u90E8\u5206\u5217\u306E\u500B\u6570\n * @reference https://noshi91.hatenablog.com/entry/2023/02/26/135340\n\
    */\n"
  code: "#include<vector>\n\nnamespace kyopro {\nnamespace number_of_subseq_impl {\n\
    \ntemplate <typename T> void comp(vector<T>& a) {\n    vector<T> tmp(a);\n   \
    \ sort(tmp.begin(), tmp.end());\n    tmp.erase(unique(all(tmp)), tmp.end());\n\
    \    for (int i = 0; i < (int)a.size(); ++i) {\n        a[i] = lower_bound(all(tmp),\
    \ a[i]) - tmp.begin();\n    }\n}\n\n};  // namespace number_of_subseq_impl\n \n\
    /// @return Number of subsequence of a  (including empty sequence)\ntemplate <typename\
    \ mint, typename T>\nmint num_of_subseq(std::vector<T> a) {\n    number_of_subseq_impl::comp(a);\n\
    \    sum[0] = mint::(1);\n    rep(i, n) {\n        sum[i + 1] = 2 * sum[i] - dp[a[i]];\n\
    \        dp[a[i]] += sum[i] - dp[a[i]];\n    }\n    return sum[n];\n}\n};\n\n\
    /**\n * @brief \u90E8\u5206\u5217\u306E\u500B\u6570\n * @reference https://noshi91.hatenablog.com/entry/2023/02/26/135340\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: src/dynamic_programming/number_of_subseq.hpp
  requiredBy: []
  timestamp: '2023-10-05 23:50:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dynamic_programming/number_of_subseq.hpp
layout: document
redirect_from:
- /library/src/dynamic_programming/number_of_subseq.hpp
- /library/src/dynamic_programming/number_of_subseq.hpp.html
title: "\u90E8\u5206\u5217\u306E\u500B\u6570"
---
