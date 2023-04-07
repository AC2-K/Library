---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Osak\u6CD5"
    links: []
  bundledCode: "#line 2 \"math/osak.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <numeric>\n#include <vector>\nnamespace prime {\n\
    /// @brief Osak\u6CD5\nnamespace Osak {\nusing u32 = uint32_t;\nu32 limit;\nstd::vector<u32>\
    \ lpf;\nvoid init(const u32& lim) {\n    limit = lim;\n    lpf.resize(lim + 1);\n\
    \    std::iota(lpf.begin(), lpf.end(), 0);\n    for (u32 i = 2; i * i <= limit;\
    \ i++) {\n        if (lpf[i] != i) {\n            continue;\n        }\n     \
    \   for (int j = i; j <= limit; j += i) {\n            lpf[j] = i;\n        }\n\
    \    }\n}\nu32 find_factor(const u32& n) {\n    assert(1 <= n && n <= limit);\n\
    \    return lpf[n];\n}\nu32 is_prime(const u32& n) {\n    assert(1 <= n && n <=\
    \ limit);\n    return lpf[n] == n;\n}\nstd::vector<u32> factorize(u32 n) {\n \
    \   assert(1 <= n && n <= limit);\n    std::vector<u32> st;\n    st.emplace_back(n);\n\
    \    st.reserve((size_t)__builtin_clz(n) + 1);\n    std::vector<u32> ans;\n  \
    \  ans.reserve((size_t)__builtin_clz(n) + 1);\n    while (st.size()) {\n     \
    \   u32 m = st.back();\n        if (m == 1) {\n            st.pop_back();\n  \
    \          continue;\n        }\n        u32 d = find_factor(m);\n        if (m\
    \ == d) {\n            ans.emplace_back(m);\n            st.pop_back();\n    \
    \    } else {\n            st.back() /= d;\n            st.emplace_back(d);\n\
    \        }\n    }\n    std::sort(ans.begin(), ans.end());\n    return ans;\n}\n\
    std::vector<std::pair<u32, u32>> exp_factorize(u32 n) {\n    if (n < 2) {\n  \
    \      return {};\n    }\n    std::vector<std::pair<u32, u32>> res;\n    auto\
    \ pf = factorize(n);\n    res.emplace_back(pf.front(), 1);\n    for (int i = 1;\
    \ i < pf.size(); i++) {\n        if (res.back().first == pf[i]) {\n          \
    \  res.back().second++;\n        } else {\n            res.emplace_back(pf[i],\
    \ 1);\n        }\n    }\n    return res;\n}\n};  // namespace Osak\n};  // namespace\
    \ library\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <numeric>\n#include <vector>\nnamespace prime {\n/// @brief Osak\u6CD5\
    \nnamespace Osak {\nusing u32 = uint32_t;\nu32 limit;\nstd::vector<u32> lpf;\n\
    void init(const u32& lim) {\n    limit = lim;\n    lpf.resize(lim + 1);\n    std::iota(lpf.begin(),\
    \ lpf.end(), 0);\n    for (u32 i = 2; i * i <= limit; i++) {\n        if (lpf[i]\
    \ != i) {\n            continue;\n        }\n        for (int j = i; j <= limit;\
    \ j += i) {\n            lpf[j] = i;\n        }\n    }\n}\nu32 find_factor(const\
    \ u32& n) {\n    assert(1 <= n && n <= limit);\n    return lpf[n];\n}\nu32 is_prime(const\
    \ u32& n) {\n    assert(1 <= n && n <= limit);\n    return lpf[n] == n;\n}\nstd::vector<u32>\
    \ factorize(u32 n) {\n    assert(1 <= n && n <= limit);\n    std::vector<u32>\
    \ st;\n    st.emplace_back(n);\n    st.reserve((size_t)__builtin_clz(n) + 1);\n\
    \    std::vector<u32> ans;\n    ans.reserve((size_t)__builtin_clz(n) + 1);\n \
    \   while (st.size()) {\n        u32 m = st.back();\n        if (m == 1) {\n \
    \           st.pop_back();\n            continue;\n        }\n        u32 d =\
    \ find_factor(m);\n        if (m == d) {\n            ans.emplace_back(m);\n \
    \           st.pop_back();\n        } else {\n            st.back() /= d;\n  \
    \          st.emplace_back(d);\n        }\n    }\n    std::sort(ans.begin(), ans.end());\n\
    \    return ans;\n}\nstd::vector<std::pair<u32, u32>> exp_factorize(u32 n) {\n\
    \    if (n < 2) {\n        return {};\n    }\n    std::vector<std::pair<u32, u32>>\
    \ res;\n    auto pf = factorize(n);\n    res.emplace_back(pf.front(), 1);\n  \
    \  for (int i = 1; i < pf.size(); i++) {\n        if (res.back().first == pf[i])\
    \ {\n            res.back().second++;\n        } else {\n            res.emplace_back(pf[i],\
    \ 1);\n        }\n    }\n    return res;\n}\n};  // namespace Osak\n};  // namespace\
    \ library\n"
  dependsOn: []
  isVerificationFile: false
  path: math/osak.hpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osak.hpp
layout: document
redirect_from:
- /library/math/osak.hpp
- /library/math/osak.hpp.html
title: "Osak\u6CD5"
---
