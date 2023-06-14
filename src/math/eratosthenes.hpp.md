---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
    links: []
  bundledCode: "#line 1 \"src/math/eratosthenes.hpp\"\n#include <bitset>\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n\n/**\n * @brief \u30A8\u30E9\
    \u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n */\nclass eratosthenes_sieve {\n\
    \    std::vector<int> mpf;  // minimum prime factor\n\n    std::vector<int> mobius;\n\
    \npublic:\n    eratosthenes_sieve(int n) : mpf(n + 1, -1), mobius(n + 1, 1) {\n\
    \        for (int i = 2; i <= n; ++i) {\n            if (!is_prime(i)) continue;\n\
    \            mpf[i] = i;\n\n            mobius[i] = -1;\n            if ((long\
    \ long)i * i > n) continue;\n            for (int j = i * 2; j <= n; j += i) {\n\
    \                if (mpf[j] == -1) mpf[j] = i;\n\n                if (j / i %\
    \ i == 0) {\n                    mobius[i] = 0;\n                } else {\n  \
    \                  mobius[j] = -mobius[j];\n                }\n            }\n\
    \        }\n    }\n\n    bool is_prime(int p) const { return mpf[p] == p; }\n\n\
    \    std::vector<int> enumerate_primes() const {\n        std::vector<int> res;\n\
    \        for (int i = 2; i < (int)mpf.size(); ++i) {\n            if (is_prime(i))\
    \ res.emplace_back(i);\n        }\n        return res;\n    }\n\n    std::vector<int>\
    \ enumerate_mobius() const { return mobius; }\n    \n    std::vector<int> factorize(int\
    \ a) const {\n        assert(1 <= a && a < (int)mpf.size());\n        if (a <=\
    \ 1) return {};\n        std::vector<int> res;\n        while (a > 1) {\n    \
    \        res.emplace_back(mpf[a]), a /= mpf[a];\n        }\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> exp_factorize(int n) {\n      \
    \  std::vector<int> pf = factorize(n);\n\n        if (pf.empty()) {\n        \
    \    return {};\n        }\n\n        std::vector<std::pair<int, int>> res;\n\
    \        res.emplace_back(pf.front(), 1);\n        for (int i = 1; i < (int)pf.size();\
    \ i++) {\n            if (res.back().first == pf[i]) {\n                res.back().second++;\n\
    \            } else {\n                res.emplace_back(pf[i], 1);\n         \
    \   }\n        }\n\n        return res;\n    }\n\n    std::vector<int> enumerate_divisor(int\
    \ n) {\n        std::vector<std::pair<int,int>> pf = exp_factorize(n);\n     \
    \   std::vector<int> divisor{1};\n        for (auto [p, e] : pf) {\n         \
    \   int pow = p;\n            int sz = divisor.size();\n            for (int i\
    \ = 0; i < e; ++i) {\n                for (int j = 0; j < sz; ++j)\n         \
    \           divisor.emplace_back(divisor[j] * pow);\n                pow *= p;\n\
    \            }\n        }\n\n        return divisor;\n    }\n};\n\n};  // namespace\
    \ kyopro\n\n\n"
  code: "#include <bitset>\n#include <cassert>\n#include <vector>\nnamespace kyopro\
    \ {\n\n/**\n * @brief \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n\
    \ */\nclass eratosthenes_sieve {\n    std::vector<int> mpf;  // minimum prime\
    \ factor\n\n    std::vector<int> mobius;\n\npublic:\n    eratosthenes_sieve(int\
    \ n) : mpf(n + 1, -1), mobius(n + 1, 1) {\n        for (int i = 2; i <= n; ++i)\
    \ {\n            if (!is_prime(i)) continue;\n            mpf[i] = i;\n\n    \
    \        mobius[i] = -1;\n            if ((long long)i * i > n) continue;\n  \
    \          for (int j = i * 2; j <= n; j += i) {\n                if (mpf[j] ==\
    \ -1) mpf[j] = i;\n\n                if (j / i % i == 0) {\n                 \
    \   mobius[i] = 0;\n                } else {\n                    mobius[j] =\
    \ -mobius[j];\n                }\n            }\n        }\n    }\n\n    bool\
    \ is_prime(int p) const { return mpf[p] == p; }\n\n    std::vector<int> enumerate_primes()\
    \ const {\n        std::vector<int> res;\n        for (int i = 2; i < (int)mpf.size();\
    \ ++i) {\n            if (is_prime(i)) res.emplace_back(i);\n        }\n     \
    \   return res;\n    }\n\n    std::vector<int> enumerate_mobius() const { return\
    \ mobius; }\n    \n    std::vector<int> factorize(int a) const {\n        assert(1\
    \ <= a && a < (int)mpf.size());\n        if (a <= 1) return {};\n        std::vector<int>\
    \ res;\n        while (a > 1) {\n            res.emplace_back(mpf[a]), a /= mpf[a];\n\
    \        }\n        return res;\n    }\n\n    std::vector<std::pair<int, int>>\
    \ exp_factorize(int n) {\n        std::vector<int> pf = factorize(n);\n\n    \
    \    if (pf.empty()) {\n            return {};\n        }\n\n        std::vector<std::pair<int,\
    \ int>> res;\n        res.emplace_back(pf.front(), 1);\n        for (int i = 1;\
    \ i < (int)pf.size(); i++) {\n            if (res.back().first == pf[i]) {\n \
    \               res.back().second++;\n            } else {\n                res.emplace_back(pf[i],\
    \ 1);\n            }\n        }\n\n        return res;\n    }\n\n    std::vector<int>\
    \ enumerate_divisor(int n) {\n        std::vector<std::pair<int,int>> pf = exp_factorize(n);\n\
    \        std::vector<int> divisor{1};\n        for (auto [p, e] : pf) {\n    \
    \        int pow = p;\n            int sz = divisor.size();\n            for (int\
    \ i = 0; i < e; ++i) {\n                for (int j = 0; j < sz; ++j)\n       \
    \             divisor.emplace_back(divisor[j] * pow);\n                pow *=\
    \ p;\n            }\n        }\n\n        return divisor;\n    }\n};\n\n};  //\
    \ namespace kyopro\n\n\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/eratosthenes.hpp
  requiredBy: []
  timestamp: '2023-06-14 23:07:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/eratosthenes.hpp
layout: document
redirect_from:
- /library/src/math/eratosthenes.hpp
- /library/src/math/eratosthenes.hpp.html
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
