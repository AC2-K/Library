---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: template.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    template.hpp\"\n#include\"math/static_modint.hpp\"\n#include\"math/matrix.hpp\"\
    \n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\nusing mint = static_modint32<MOD2>;\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int n, m, k;\n    cin >> n >> m >> k;\n    using mat = Matrix<mint>;\n\
    \    mat a(n, m), b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i,\
    \ m) rep(j, k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n \
    \       rep(j, k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/matrix/Matrix Product.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/matrix/Matrix Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp.html
title: test/yosupo_judge/matrix/Matrix Product.test.cpp
---
