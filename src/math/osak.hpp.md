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
  bundledCode: "#line 1 \"src/math/osak.hpp\"\nnamespace prime {\n\t/// @brief Osak\u6CD5\
    \n\tnamespace Osak {\n\t\tusing u32 = uint32_t;\n\t\tu32 limit;\n\t\tvector<u32>\
    \ lpf;\n\t\tvoid init(const u32& lim) {\n\t\t\tlimit = lim;\n\t\t\tlpf.resize(lim\
    \ + 1);\n\t\t\tiota(lpf.begin(), lpf.end(), 0);\n\t\t\tfor (u32 i = 2; i * i <=\
    \ limit; i++) {\n\t\t\t\tif (lpf[i] != i) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\
    \t\t\tfor (int j = i; j <= limit; j += i) {\n\t\t\t\t\tlpf[j] = i;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\t\tu32 find_factor(const u32& n) {\n\t\t\tassert(1 <= n && n\
    \ <= limit);\n\t\t\treturn lpf[n];\n\t\t}\n\t\tu32 is_prime(const u32& n) {\n\t\
    \t\tassert(1 <= n && n <= limit);\n\t\t\treturn lpf[n] == n;\n\t\t}\n\t\tvector<u32>\
    \ factorize(u32 n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\tvector<u32> st;\n\
    \t\t\tst.emplace_back(n);\n\t\t\tst.reserve((size_t)__builtin_clz(n) + 1);\n\t\
    \t\tvector<u32> ans;\n\t\t\tans.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\t\
    while (st.size()) {\n\t\t\t\tu32 m = st.back();\n\t\t\t\tif (m == 1) {\n\t\t\t\
    \t\tst.pop_back();\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tu32 d = find_factor(m);\n\
    \t\t\t\tif (m == d) {\n\t\t\t\t\tans.emplace_back(m);\n\t\t\t\t\tst.pop_back();\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tst.back() /= d;\n\t\t\t\t\tst.emplace_back(d);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tsort(ans.begin(), ans.end());\n\t\t\treturn ans;\n\t\
    \t}\n\t\tvector<pair<u32, u32>> exp_factorize(u32 n) {\n\t\t\tif (n < 2) {\n\t\
    \t\t\treturn {};\n\t\t\t}\n\t\t\tvector<pair<u32, u32>> res;\n\t\t\tres.reserve((size_t)__builtin_clz(n));\n\
    \t\t\tauto pf = factorize(n);\n\t\t\tres.emplace_back(pf.front(), 1);\n\t\t\t\
    for (int i = 1; i < pf.size(); i++) {\n\t\t\t\tif (res.back().first == pf[i])\
    \ {\n\t\t\t\t\tres.back().second++;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres.emplace_back(pf[i],\
    \ 1);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t};  // namespace Osak\n\
    };  // namespace prime\n"
  code: "namespace prime {\n\t/// @brief Osak\u6CD5\n\tnamespace Osak {\n\t\tusing\
    \ u32 = uint32_t;\n\t\tu32 limit;\n\t\tvector<u32> lpf;\n\t\tvoid init(const u32&\
    \ lim) {\n\t\t\tlimit = lim;\n\t\t\tlpf.resize(lim + 1);\n\t\t\tiota(lpf.begin(),\
    \ lpf.end(), 0);\n\t\t\tfor (u32 i = 2; i * i <= limit; i++) {\n\t\t\t\tif (lpf[i]\
    \ != i) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tfor (int j = i; j <= limit;\
    \ j += i) {\n\t\t\t\t\tlpf[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tu32 find_factor(const\
    \ u32& n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\treturn lpf[n];\n\t\t}\n\
    \t\tu32 is_prime(const u32& n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\t\
    return lpf[n] == n;\n\t\t}\n\t\tvector<u32> factorize(u32 n) {\n\t\t\tassert(1\
    \ <= n && n <= limit);\n\t\t\tvector<u32> st;\n\t\t\tst.emplace_back(n);\n\t\t\
    \tst.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\tvector<u32> ans;\n\t\t\tans.reserve((size_t)__builtin_clz(n)\
    \ + 1);\n\t\t\twhile (st.size()) {\n\t\t\t\tu32 m = st.back();\n\t\t\t\tif (m\
    \ == 1) {\n\t\t\t\t\tst.pop_back();\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\t\
    u32 d = find_factor(m);\n\t\t\t\tif (m == d) {\n\t\t\t\t\tans.emplace_back(m);\n\
    \t\t\t\t\tst.pop_back();\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tst.back() /= d;\n\
    \t\t\t\t\tst.emplace_back(d);\n\t\t\t\t}\n\t\t\t}\n\t\t\tsort(ans.begin(), ans.end());\n\
    \t\t\treturn ans;\n\t\t}\n\t\tvector<pair<u32, u32>> exp_factorize(u32 n) {\n\t\
    \t\tif (n < 2) {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t\tvector<pair<u32, u32>> res;\n\
    \t\t\tres.reserve((size_t)__builtin_clz(n));\n\t\t\tauto pf = factorize(n);\n\t\
    \t\tres.emplace_back(pf.front(), 1);\n\t\t\tfor (int i = 1; i < pf.size(); i++)\
    \ {\n\t\t\t\tif (res.back().first == pf[i]) {\n\t\t\t\t\tres.back().second++;\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres.emplace_back(pf[i], 1);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t\treturn res;\n\t\t}\n\t};  // namespace Osak\n};  // namespace prime\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/osak.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/osak.hpp
layout: document
redirect_from:
- /library/src/math/osak.hpp
- /library/src/math/osak.hpp.html
title: "Osak\u6CD5"
---
