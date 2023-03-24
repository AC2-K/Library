---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/D.test.cpp
    title: test/AOJ/DSL/2/D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/E.test.cpp
    title: test/AOJ/DSL/2/E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/lazy_segtree.md
    document_title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\
      \u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/lazy_segtree.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/// @brief Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n/// @docs docs/data-structure/lazy_segtree.md\n\
    \n#pragma once\ntemplate<\n    class S, class F,\n    S(*op)(S, S), S(*e)(),\n\
    \    F(*comp)(F, F), F(*id)(),\n    S(*mapping)(S, F)\n>\nclass lazy_segtree {\n\
    \    int sz;\n    vector<S> dat;\n    vector<F> lz;\npublic:\n    lazy_segtree(int\
    \ n) :lazy_segtree(vector<S>(n, e())) {    }\n    lazy_segtree(const vector<S>&\
    \ a) :dat(4 * a.size(), e()), lz(4 * a.size(), id()) {\n        int x = 1;\n \
    \       while (a.size() > x) {\n            x <<= 1;\n        }\n        sz =\
    \ x;\n        for (int i = 0; i < a.size(); i++) {\n            set(i, a[i]);\n\
    \        }\n        build();\n    }\npublic:\n    void set(int pos, S x) {\n \
    \       assert(0 <= pos && pos < sz);\n        dat[pos + sz - 1] = x;\n    }\n\
    \    void build() {\n        for (int i = sz - 2; i >= 0; i--) {\n           \
    \ dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);\n        }\n    }\n\nprivate:\n\
    \    void eval(int pos) {\n        if (lz[pos] == id()) return;\n        if (pos\
    \ < sz - 1) {\n            lz[2 * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n\
    \            lz[2 * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);\n        }\n  \
    \      dat[pos] = mapping(dat[pos], lz[pos]);\n        lz[pos] = id();\n    }\n\
    \nprivate:\n    void internal_apply(int L, int R, int l, int r, const F& x, int\
    \ k) {\n        eval(k);\n        if (L <= l && r <= R) {\n            lz[k] =\
    \ comp(lz[k], x);\n            eval(k);\n        }\n        else if (L < r &&\
    \ l < R) {\n            int mid = (l + r) >> 1;\n            internal_apply(L,\
    \ R, l, mid, x, 2 * k + 1);\n            internal_apply(L, R, mid, r, x, 2 * k\
    \ + 2);\n            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n\
    \    }\npublic:\n    void apply(int l, int r, const F& x) {\n        assert(0\
    \ <= l && l <= r && r <= sz);\n        internal_apply(l, r, 0, sz, x, 0);\n  \
    \  }\n\nprivate:\n    S internal_prod(int L, int R, int l, int r, int k) {\n \
    \       eval(k);\n        if (r <= L || R <= l) {\n            return e();\n \
    \       }\n        else if (L <= l && r <= R) {\n            return dat[k];\n\
    \        }\n        else {\n            int mid = (l + r) >> 1;\n            S\
    \ vl = internal_prod(L, R, l, mid, 2 * k + 1);\n            S vr = internal_prod(L,\
    \ R, mid, r, 2 * k + 2);\n            return op(vl, vr);\n        }\n    }\n\n\
    public:\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r && r <= sz);\n\
    \        return internal_prod(l, r, 0, sz, 0);\n    }\n\n    S operator[](int\
    \ pos) {\n        return prod(pos, pos + 1);\n    }\n};\n//@brief lazy segtree(\u9045\
    \u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-03-25 02:02:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2/D.test.cpp
  - test/AOJ/DSL/2/E.test.cpp
documentation_of: data-structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/lazy_segtree.hpp
- /library/data-structure/lazy_segtree.hpp.html
title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
  \u30F3\u30C8\u6728)"
---
