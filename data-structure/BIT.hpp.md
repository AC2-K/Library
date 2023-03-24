---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/BIT.md
    document_title: Binary Index Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/BIT.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/// @brief Binary Index Tree\n/// @tparam Type \u8981\u7D20\u306E\u578B\n\
    /// @tparam SumType \"\u548C\u304C\" \u53CE\u307E\u308B\u3088\u3046\u306A\u578B\
    \n/// @docs docs/data-structure/BIT.md\n\n#pragma once\ntemplate <typename Type,\
    \ typename SumType = Type>\nclass BIT {\n    int _n;\n    vector<SumType> _dat;\n\
    public:\n    explicit BIT(int _n) : _n(_n), _dat(_n, SumType()) {}\n\n    inline\
    \ void add(int p, Type v) {\n        p++;\n        for (; p <= _n; p += p & (-p))\
    \ {\n            _dat[p - 1] += SumType(v);\n        }\n    }\n\n    inline SumType\
    \ sum(int p) {\n        SumType res = 0;\n        for (; p > 0; p -= p & -p) {\n\
    \            res += _dat[p - 1];\n        }\n        return res;\n    }\n\n  \
    \  inline SumType sum(int l, int r) { return sum(r) - sum(l); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/BIT.hpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/BIT.hpp
layout: document
redirect_from:
- /library/data-structure/BIT.hpp
- /library/data-structure/BIT.hpp.html
title: Binary Index Tree
---
