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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include\"template.hpp\"\n#include\"data-structure/lazy_segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing mint = static_modint32<MOD2>;\nstruct S {\n  \
    \  mint s;\n    int len;\n};\nS op(S a, S b) { return S{a.s + b.s, a.len + b.len};\
    \ }\nS e() { return S{0, 0}; }\nusing Affine = pair<mint, mint>;\nAffine composition(Affine\
    \ g, Affine f) {\n\t//f(g)\n\t//a(cx+d)+b\n\tauto a = f.first, b = f.second;\n\
    \tauto c = g.first, d = g.second;\n\treturn Affine(a * c, a * d + b);\n}\nAffine\
    \ id() { return Affine(1, 0); }\nS mapping(S d, Affine f) {\n    mint a = f.first,\
    \ b = f.second;\n    d.s *= a, d.s += b * d.len;\n    return d;\n};\n\nint main(){\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int n, q;\n    cin\
    \ >> n >> q;\n    lazy_segtree<S, Affine, op, e, composition, id, mapping> sg(n);\n\
    \    rep(i,n){\n        mint a;\n        cin >> a;\n        sg.set(i, {a, 1});\n\
    \    }\n    sg.build();\n    while(q--){\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int l, r;\n            mint b, c;\n      \
    \      cin >> l >> r >> b >> c;\n            sg.apply(l, r, Affine(b, c));\n \
    \       } else {\n            int l, r;\n            cin >> l >> r;\n        \
    \    auto res = sg.prod(l, r);\n            cout << res.s << '\\n';\n        }\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
---
