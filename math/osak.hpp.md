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
  bundledCode: "#line 1 \"math/osak.hpp\"\n#include<vector>\n#include<algorithm>\n\
    #include<cassert>\n#include<numeric>\nnamespace library {\n\t/// @brief Osak\u6CD5\
    \n\tnamespace Osak {\n\t\tusing u32 = uint32_t;\n\t\tu32 limit;\n\t\tstd::vector<u32>\
    \ lpf;\n\t\tvoid init(u32 lim) {\n\t\t\tlimit = lim;\n\t\t\tlpf.resize(lim + 1);\n\
    \t\t\tiota(lpf.begin(), lpf.end(), 0);\n\t\t\tfor (u32 i = 2; i * i <= limit;\
    \ i++) {\n\t\t\t\tif (lpf[i] != i) {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\t\
    for (int j = i; j <= limit; j += i) {\n\t\t\t\t\tlpf[j] = i;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\tu32 find_factor(u32 n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\
    \t\treturn lpf[n];\n\t\t}\n\t\tu32 is_prime(u32 n) {\n\t\t\tassert(1 <= n && n\
    \ <= limit);\n\t\t\treturn lpf[n] == n;\n\t\t}\n\t\tstd::vector<u32> factorize(u32\
    \ n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\tstd::vector<u32> st;\n\t\t\t\
    st.emplace_back(n);\n\t\t\tst.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\tstd::vector<u32>\
    \ ans;\n\t\t\tans.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\twhile (st.size())\
    \ {\n\t\t\t\tu32 m = st.back();\n\t\t\t\tif (m == 1) {\n\t\t\t\t\tst.pop_back();\n\
    \t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tu32 d = find_factor(m);\n\t\t\t\tif (m\
    \ == d) {\n\t\t\t\t\tans.emplace_back(m);\n\t\t\t\t\tst.pop_back();\n\t\t\t\t\
    }\n\t\t\t\telse {\n\t\t\t\t\tst.back() /= d;\n\t\t\t\t\tst.emplace_back(d);\n\t\
    \t\t\t}\n\t\t\t}\n\t\t\tsort(ans.begin(), ans.end());\n\t\t\treturn ans;\n\t\t\
    }\n\t\tstd::vector<std::pair<int, int>> exp_factorize(u32 n) {\n\t\t\tif (n <\
    \ 2) {\n\t\t\t\treturn {};\n\t\t\t}\n\t\t\tstd::vector<std::pair<int, int>> res;\n\
    \t\t\tres.reserve((size_t)std::__lg(n) + 1);\n\t\t\tauto pf = factorize(n);\n\t\
    \t\tres.emplace_back(pf.front(), 1);\n\t\t\tfor (int i = 1; i < pf.size(); i++)\
    \ {\n\t\t\t\tif (res.back().first == pf[i]) {\n\t\t\t\t\tres.back().second++;\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres.emplace_back(pf[i], 1);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t\treturn res;\n\t\t}\n\t};  // namespace Osak\n};  // namespace library\n"
  code: "#include<vector>\n#include<algorithm>\n#include<cassert>\n#include<numeric>\n\
    namespace library {\n\t/// @brief Osak\u6CD5\n\tnamespace Osak {\n\t\tusing u32\
    \ = uint32_t;\n\t\tu32 limit;\n\t\tstd::vector<u32> lpf;\n\t\tvoid init(u32 lim)\
    \ {\n\t\t\tlimit = lim;\n\t\t\tlpf.resize(lim + 1);\n\t\t\tiota(lpf.begin(), lpf.end(),\
    \ 0);\n\t\t\tfor (u32 i = 2; i * i <= limit; i++) {\n\t\t\t\tif (lpf[i] != i)\
    \ {\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tfor (int j = i; j <= limit; j +=\
    \ i) {\n\t\t\t\t\tlpf[j] = i;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tu32 find_factor(u32\
    \ n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\treturn lpf[n];\n\t\t}\n\t\t\
    u32 is_prime(u32 n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\treturn lpf[n]\
    \ == n;\n\t\t}\n\t\tstd::vector<u32> factorize(u32 n) {\n\t\t\tassert(1 <= n &&\
    \ n <= limit);\n\t\t\tstd::vector<u32> st;\n\t\t\tst.emplace_back(n);\n\t\t\t\
    st.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\tstd::vector<u32> ans;\n\t\t\t\
    ans.reserve((size_t)__builtin_clz(n) + 1);\n\t\t\twhile (st.size()) {\n\t\t\t\t\
    u32 m = st.back();\n\t\t\t\tif (m == 1) {\n\t\t\t\t\tst.pop_back();\n\t\t\t\t\t\
    continue;\n\t\t\t\t}\n\t\t\t\tu32 d = find_factor(m);\n\t\t\t\tif (m == d) {\n\
    \t\t\t\t\tans.emplace_back(m);\n\t\t\t\t\tst.pop_back();\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tst.back() /= d;\n\t\t\t\t\tst.emplace_back(d);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t\tsort(ans.begin(), ans.end());\n\t\t\treturn ans;\n\t\t}\n\t\tstd::vector<std::pair<int,\
    \ int>> exp_factorize(u32 n) {\n\t\t\tif (n < 2) {\n\t\t\t\treturn {};\n\t\t\t\
    }\n\t\t\tstd::vector<std::pair<int, int>> res;\n\t\t\tres.reserve((size_t)std::__lg(n)\
    \ + 1);\n\t\t\tauto pf = factorize(n);\n\t\t\tres.emplace_back(pf.front(), 1);\n\
    \t\t\tfor (int i = 1; i < pf.size(); i++) {\n\t\t\t\tif (res.back().first == pf[i])\
    \ {\n\t\t\t\t\tres.back().second++;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres.emplace_back(pf[i],\
    \ 1);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\t};  // namespace Osak\n\
    };  // namespace library\n"
  dependsOn: []
  isVerificationFile: false
  path: math/osak.hpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osak.hpp
layout: document
redirect_from:
- /library/math/osak.hpp
- /library/math/osak.hpp.html
title: "Osak\u6CD5"
---
