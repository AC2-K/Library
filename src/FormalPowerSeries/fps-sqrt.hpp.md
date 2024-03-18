---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sqrt of FPS
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/mod_log.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../FormalPowerSeries/FPS.hpp\"\n#include \"../math/mod_sqrt.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief Sqrt of FPS\n */\ntemplate <typename mint>\n\
    FormalPowerSeries<mint> fps_sqrt(const FormalPowerSeries<mint>& f,\n         \
    \                        int deg = -1LL) {\n    if (f.empty()) return FormalPowerSeries<mint>{};\n\
    \n    if (deg == -1) deg = f.size();\n\n    int g0 = mod_sqrt_lazy(f[0].val(),\
    \ mint::mod());\n\n    if (g0 == 0) {\n        for (int i = 1; i < (int)f.size();\
    \ ++i) {\n            if (f[i] == mint()) continue;\n\n            if (i & 1)\
    \ return FormalPowerSeries<mint>{};\n\n            FormalPowerSeries<mint> g =\
    \ fps_sqrt(\n                FormalPowerSeries<mint>{f.begin() + i, f.end()},\
    \ deg - i / 2);\n            if (g.empty()) return FormalPowerSeries<mint>{};\n\
    \            g.resize(g.size() + i / 2);\n            for (int j = g.size() -\
    \ 1; j >= i / 2; --j) g[j] = g[j - i / 2];\n            for (int j = 0; j < i\
    \ / 2; ++j) g[j] = 0;\n            if (g.size() < deg) g.resize(deg);\n\n    \
    \        return g;\n        }\n        return f;\n    }\n    if (g0 == -1) return\
    \ FormalPowerSeries<mint>{};\n\n    const mint inv2 = mint::raw(2).inv();\n\n\
    \    FormalPowerSeries<mint> g{mint::raw(g0)};\n\n    for (long long n = 1; n\
    \ < deg; n <<= 1) {\n        g = g + f.pref(2 * n) * g.inv(2 * n);\n        for\
    \ (int j = 0; j < (int)g.size(); ++j) g[j] *= inv2;\n    }\n\n    return g.pref(deg);\n\
    }\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/FormalPowerSeries/fps-sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FormalPowerSeries/fps-sqrt.hpp
layout: document
redirect_from:
- /library/src/FormalPowerSeries/fps-sqrt.hpp
- /library/src/FormalPowerSeries/fps-sqrt.hpp.html
title: Sqrt of FPS
---
