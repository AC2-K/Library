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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include\"template.hpp\"\n#include\"data-structure/dual_segtree.hpp\"\n#include\"\
    math/static_modint.hpp\"\nusing mint = static_modint32<MOD2>;\nusing Affine =\
    \ pair<mint, mint>;\nAffine op(Affine g, Affine f) {\n\tauto a = f.first, b =\
    \ f.second;\n\tauto c = g.first, d = g.second;\n\treturn Affine(a * c, a * d +\
    \ b);\n}\nAffine e() { return Affine(1, 0); }\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tdual_segtree<Affine,\
    \ op, e> sg(n);\n\tvector<mint> a(n);\n\tfor (auto& aa : a) {\n\t\tcin >> aa;\n\
    \t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;   \n\t\tif (t == 0) {\n\t\t\t\
    int l, r;\n\t\t\tmint b, c;\n\t\t\tcin >> l >> r >> b >> c;\n\t\t\tsg.apply(l,\
    \ r, Affine(b, c));\n\t\t}\n\t\telse {\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\t\
    auto f = sg[i];\n\t\t\tmint ans = f.first * a[i] + f.second;\n\t\t\tcout << ans\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
- /verify/test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp.html
title: test/yosupo_judge/new/Range_Affine_Point_Get.test.cpp
---
