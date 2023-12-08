---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Min Plus Convolution(Convex, Convex)
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: internal/type_traits.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <limits>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#include \"internal/type_traits.hpp\"\n\nnamespace kyopro {\n\
    template <typename T>\nstd::vector<T> min_plus_convolution_convex_convex(const\
    \ std::vector<T>& a,\n                                                  std::vector<T>&\
    \ b) {\n    constexpr T INF = std::numeric_limits<T>::max() / 2;\n    const int\
    \ n = a.size();\n    const int m = b.size();\n    const T A0 = INF;\n    const\
    \ T B0 = INF;\n\n    std::vector<T> da(n);\n    std::vector<T> db(m);\n    for\
    \ (int i = 1; i < n; ++i) da[i] = a[i] - a[i - 1];\n    for (int i = 1; i < m;\
    \ ++i) db[i] = b[i] - b[i - 1];\n    da[0] = a[0] - INF, db[0] = b[0] - INF;\n\
    \n    std::vector<T> ds;\n    ds.reserve(da.size() + db.size());\n    for (int\
    \ ia = 0, ib = 0; ia < n || ib < m;) {\n        if (ia == (int)da.size()) {\n\
    \            ds.emplace_back(db[ib++]);\n        } else if (ib == m) {\n     \
    \       ds.emplace_back(da[ia++]);\n        } else {\n            if (da[ia] >\
    \ db[ib]) {\n                ds.emplace_back(db[ib++]);\n            } else {\n\
    \                ds.emplace_back(da[ia++]);\n            }\n        }\n    }\n\
    \n    std::vector<T> res(n + m - 1);\n    T sum = ds[0];\n    for (int k = 1;\
    \ k < (int)ds.size(); ++k) {\n        sum += ds[k];\n        res[k - 1] = sum\
    \ + A0 + B0;\n    }\n    return res;\n}\n};  // namespace kyopro\n\n/**\n * @brief\
    \ Min Plus Convolution(Convex, Convex)\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/min_plus_convolution_convex_convex.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/convolution/min_plus_convolution_convex_convex.hpp
layout: document
redirect_from:
- /library/src/convolution/min_plus_convolution_convex_convex.hpp
- /library/src/convolution/min_plus_convolution_convex_convex.hpp.html
title: Min Plus Convolution(Convex, Convex)
---
