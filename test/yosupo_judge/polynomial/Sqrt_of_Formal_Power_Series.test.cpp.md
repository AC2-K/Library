---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/mod_log.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\"\
    \n\n#include \"../../../src/FormalPowerSeries/fps-sqrt.hpp\"\n#include \"../../../src/debug.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n    int n;\n    read(n);\n    FormalPowerSeries<mint> f(n);\n\n\
    \    rep(i, n) {\n        int x;\n        read(x);\n        f[i] = mint::raw(x);\n\
    \    }\n\n    f = fps_sqrt<mint>(f);\n    if (f.empty()) {\n        put(-1);\n\
    \    } else {\n        rep(i, (int)f.size()) put(f[i].val());\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
- /verify/test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp.html
title: test/yosupo_judge/polynomial/Sqrt_of_Formal_Power_Series.test.cpp
---
