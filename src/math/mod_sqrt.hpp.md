---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/mod_log.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"math/mod_log.hpp\"\n#include \"math/primitive_root.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u5E73\u65B9\u5270\u4F59(O(\u221Ap))\n\
    \ * @note \u9045\u3044\n */\nconstexpr int mod_sqrt_lazy(int x, int p) {\n   \
    \ if (x == 0) return 0;\n    if (p == 2) return x;\n    int g = primitive_root(p);\n\
    \    int e = mod_log(g, x, p);\n    if (e % 2 != 0) {\n        return -1;\n  \
    \  } else {\n        return mod_pow(g, e / 2, p);\n    }\n}\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/mod_sqrt.hpp
layout: document
redirect_from:
- /library/src/math/mod_sqrt.hpp
- /library/src/math/mod_sqrt.hpp.html
title: "\u5E73\u65B9\u5270\u4F59(O(\u221Ap))"
---
