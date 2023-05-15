---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS/1_C.test.cpp
    title: test/AOJ/ALDS/1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 1 \"src/math/sieve.hpp\"\n#include <bitset>\n#include <vector>\n\
    namespace kyopro {\n\n/**\n * @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
    \u306E\u7BE9\n * @tparam ALLOC \u78BA\u4FDD\u3057\u3066\u304A\u304F\u30B5\u30A4\
    \u30BA\n */\ntemplate <int ALLOC> class sieve {\n    std::bitset<ALLOC + 1> isp;\n\
    \    std::vector<int> prime_v;\n\npublic:\n    constexpr sieve() : sieve(ALLOC)\
    \ {}\n    constexpr sieve(int n) {\n        isp.flip();\n        isp[0] = isp[1]\
    \ = 0;\n        for (int i = 2; i <= n; ++i) {\n            if (!isp[i]) continue;\n\
    \            prime_v.emplace_back(i);\n            if ((long long)i * i > n) continue;\n\
    \            for (int j = i * 2; j <= n; j += i) {\n                isp[j] = 0;\n\
    \            }\n        }\n    }\n    const std::vector<int>& primes() const {\
    \ return prime_v; }\n    constexpr int num_of_primes() const { return prime_v.size();\
    \ }\n    constexpr int kth_prime(int i) const { return prime_v[i]; }\n    constexpr\
    \ bool is_prime(int p) { return isp[p]; }\n};\n\n};  // namespace kyopro\n"
  code: "#include <bitset>\n#include <vector>\nnamespace kyopro {\n\n/**\n * @brief\
    \ \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n * @tparam ALLOC \u78BA\
    \u4FDD\u3057\u3066\u304A\u304F\u30B5\u30A4\u30BA\n */\ntemplate <int ALLOC> class\
    \ sieve {\n    std::bitset<ALLOC + 1> isp;\n    std::vector<int> prime_v;\n\n\
    public:\n    constexpr sieve() : sieve(ALLOC) {}\n    constexpr sieve(int n) {\n\
    \        isp.flip();\n        isp[0] = isp[1] = 0;\n        for (int i = 2; i\
    \ <= n; ++i) {\n            if (!isp[i]) continue;\n            prime_v.emplace_back(i);\n\
    \            if ((long long)i * i > n) continue;\n            for (int j = i *\
    \ 2; j <= n; j += i) {\n                isp[j] = 0;\n            }\n        }\n\
    \    }\n    const std::vector<int>& primes() const { return prime_v; }\n    constexpr\
    \ int num_of_primes() const { return prime_v.size(); }\n    constexpr int kth_prime(int\
    \ i) const { return prime_v[i]; }\n    constexpr bool is_prime(int p) { return\
    \ isp[p]; }\n};\n\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/math/sieve.hpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS/1_C.test.cpp
documentation_of: src/math/sieve.hpp
layout: document
redirect_from:
- /library/src/math/sieve.hpp
- /library/src/math/sieve.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
