---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E8C\u9805\u4FC2\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: internal/barrett.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"internal/barrett.hpp\"\n#include<cassert>\nnamespace\
    \ kyopro {\ntemplate <int MAX>\nclass dynamic_combination {\n    int fac[MAX],\
    \ ifac[MAX];\n    int m;\n    constexpr int fact_pow(int a, int p) {\n       \
    \ int ans = 1;\n        while (p) {\n            if (p & 1) ans = bar.mul(ans,\
    \ a);\n            p >>= 1;\n            a = bar.mul(a, a);\n        }\n     \
    \   return ans;\n    }\n    void build() {\n        fac[0] = ifac[0] = fac[1]\
    \ = ifac[1] = 1;\n        int N = std::min(m, MAX);\n        for (int i = 2; i\
    \ < N; ++i) {\n            fac[i] = bar.mul(fac[i - 1], i);\n        }\n\n   \
    \     ifac[N - 1] = fact_pow(fac[N - 1], m - 2);\n        for (int i = N - 2;\
    \ i > 1; --i) {\n            ifac[i] = bar.mul(ifac[i + 1], i + 1);\n        }\n\
    \    }\n\n    internal::barrett bar;\n\npublic:\n    constexpr dynamic_combination(int\
    \ modulo) : m(modulo), bar(modulo) {\n        build();\n    }\n\n    constexpr\
    \ int binom(int n, int r) const {\n        assert(n >= r);\n        return bar.mul(fac[n],\
    \ bar.mul(ifac[r], ifac[n - r]));\n    }\n    constexpr int perm(int n, int r)\
    \ const {\n        assert(n >= r);\n        return fac[n] * ifac[n - r];\n   \
    \ }\n    constexpr int fact(int n) const { return fac[n]; }\n};\n\ntemplate <typename\
    \ mint, int MAX>\nclass combination {\n    mint fac[MAX + 1];\n    mint ifac[MAX\
    \ + 1];\n\npublic:\n    constexpr explicit combination() {\n        fac[0] = 1;\n\
    \        for (int i = 1; i <= MAX; ++i) {\n            fac[i] = fac[i - 1] * i;\n\
    \        }\n        ifac[MAX] = fac[MAX].inv();\n        for (int i = MAX; i >\
    \ 0; --i) {\n            ifac[i - 1] = ifac[i] * i;\n        }\n    }\n\n    constexpr\
    \ mint binom(int n, int r) const {\n        assert(n >= r);\n        return fac[n]\
    \ * ifac[r] * ifac[n - r];\n    }\n    constexpr mint perm(int n, int r) const\
    \ {\n        assert(n >= r);\n        return fac[n] * ifac[n - r];\n    }\n  \
    \  constexpr mint fact(int n) { return fac[n]; }\n};\n\n};  // namespace kyopro\n\
    \n/// @brief \u4E8C\u9805\u4FC2\u6570"
  dependsOn: []
  isVerificationFile: false
  path: src/math/combination.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/combination.hpp
layout: document
redirect_from:
- /library/src/math/combination.hpp
- /library/src/math/combination.hpp.html
title: "\u4E8C\u9805\u4FC2\u6570"
---
