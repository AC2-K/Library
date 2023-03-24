---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':heavy_check_mark:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/segtree.hpp: line 7: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include\"template.hpp\"\n#include\"data-structure/segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing mint = static_modint32<MOD2>;\n\nstruct F\n{\n\
    \    mint a,b;\n};\n\nF op(F l,F r){\n    mint na = l.a * r.a;\n    mint nb =\
    \ (l.b * r.a + r.b);\n    return F{na, nb};\n}\nF e(){\n    return F{1,0};\n}\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    segtree<F, op, e> seg(n);\n\
    \    rep(i, n){\n        mint a, b;\n        cin >> a >> b;\n        seg.set(i,\
    \ F{a, b});\n    }\n    seg.build();\n    while (q--){\n        int t;\n     \
    \   cin >> t;\n        if (t == 0){\n            int p;\n            mint c, d;\n\
    \            cin >> p >> c >> d;\n            seg.update(p, F{c, d});\n      \
    \  }\n        else{\n            int l, r;\n            mint x;\n            cin\
    \ >> l >> r >> x;\n            F res = seg.prod(l, r);\n            mint ans =\
    \ res.a * x + res.b;\n            cout << ans << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  - math/static_modint.hpp
  isVerificationFile: true
  path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp
- /verify/test/yosupo judge/data structure/Point Set Range Composite.test.cpp.html
title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
---
