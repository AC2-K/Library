---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/osak.hpp\"\nnamespace prime {\n\tnamespace Osak {\n\
    \t\tusing u32 = uint32_t;\n\t\tu32 limit;\n\t\tvector<u32> lpf;\n        void\
    \ init(const u32& lim) {\n            limit = lim;\n            lpf.resize(lim\
    \ + 1);\n            iota(lpf.begin(), lpf.end(), 0);\n            for (u32 i\
    \ = 2; i * i <= limit; i++) {\n                if (lpf[i] != i) {\n          \
    \          continue;\n                }\n                for (int j = i; j <=\
    \ limit; j += i) {\n                    lpf[j] = i;\n                }\n     \
    \       }\n        }\n\t\tu32 find_factor(const u32& n) {\n\t\t\tassert(1 <= n\
    \ && n <= limit);\n\t\t\treturn lpf[n];\n\t\t}\n\t\tu32 is_prime(const u32& n)\
    \ {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\treturn lpf[n] == n;\n\t\t}\n\t\
    \tvector<u32> factorize(u32 n) {\n\t\t\tassert(1 <= n && n <= limit);\n\t\t\t\
    vector<u32> st;\n\t\t\tst.emplace_back(n);\n\t\t\tst.reserve((size_t)__builtin_clz(n)\
    \ + 1);\n\t\t\tvector<u32> ans;\n\t\t\tans.reserve((size_t)__builtin_clz(n) +\
    \ 1);\n\t\t\twhile (st.size()) {\n\t\t\t\tu32 m = st.back();\n\t\t\t\tif (m ==\
    \ 1) {\n\t\t\t\t\tst.pop_back();\n\t\t\t\t\tcontinue;\n\t\t\t\t}\n\t\t\t\tu32\
    \ d = find_factor(m);\n\t\t\t\tif (m == d) {\n\t\t\t\t\tans.emplace_back(m);\n\
    \t\t\t\t\tst.pop_back();\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tst.back() /= d;\n\
    \t\t\t\t\tst.emplace_back(d);\n\t\t\t\t}\n\t\t\t}\n\t\t\tsort(ans.begin(), ans.end());\n\
    \t\t\treturn ans;\n\t\t}\n\t\tvector<pair<u32,u32>> exp_factorize(u32 n) {\n \
    \           if (n < 2) {\n                return {};\n            }\n        \
    \    vector<pair<u32, u32>> res;\n            res.reserve((size_t)__builtin_clz(n));\n\
    \            auto pf = factorize(n);\n            res.emplace_back(pf.front(),\
    \ 1);\n            for (int i = 1; i < pf.size(); i++) {\n                if (res.back().first\
    \ == pf[i]) {\n                    res.back().second++;\n                }\n \
    \               else {\n                    res.emplace_back(pf[i], 1);\n    \
    \            }\n            }\n            return res;\n\t\t}\n\t};\n};\n"
  code: "namespace prime {\n\tnamespace Osak {\n\t\tusing u32 = uint32_t;\n\t\tu32\
    \ limit;\n\t\tvector<u32> lpf;\n        void init(const u32& lim) {\n        \
    \    limit = lim;\n            lpf.resize(lim + 1);\n            iota(lpf.begin(),\
    \ lpf.end(), 0);\n            for (u32 i = 2; i * i <= limit; i++) {\n       \
    \         if (lpf[i] != i) {\n                    continue;\n                }\n\
    \                for (int j = i; j <= limit; j += i) {\n                    lpf[j]\
    \ = i;\n                }\n            }\n        }\n\t\tu32 find_factor(const\
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
    \t\t\treturn ans;\n\t\t}\n\t\tvector<pair<u32,u32>> exp_factorize(u32 n) {\n \
    \           if (n < 2) {\n                return {};\n            }\n        \
    \    vector<pair<u32, u32>> res;\n            res.reserve((size_t)__builtin_clz(n));\n\
    \            auto pf = factorize(n);\n            res.emplace_back(pf.front(),\
    \ 1);\n            for (int i = 1; i < pf.size(); i++) {\n                if (res.back().first\
    \ == pf[i]) {\n                    res.back().second++;\n                }\n \
    \               else {\n                    res.emplace_back(pf[i], 1);\n    \
    \            }\n            }\n            return res;\n\t\t}\n\t};\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/osak.hpp
  requiredBy: []
  timestamp: '2023-03-23 15:53:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/osak.hpp
layout: document
redirect_from:
- /library/math/osak.hpp
- /library/math/osak.hpp.html
title: math/osak.hpp
---
