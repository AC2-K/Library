---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: lazy_segtree
    links: []
  bundledCode: "#line 1 \"data-structure/lazy_segtree.hpp\"\ntemplate<\n    class\
    \ S, class F,\n    S(*op)(S, S), S(*e)(),\n    F(*comp)(F, F), F(*id)(),\n   \
    \ S(*mapping)(S, F)\n>\nclass lazy_segtree {\n    int sz;\n    vector<S> dat;\n\
    \    vector<F> lz;\npublic:\n    lazy_segtree(int n) :lazy_segtree(vector<S>(n,\
    \ e())) {    }\n    lazy_segtree(const vector<S>& a) :dat(4 * a.size(), e()),\
    \ lz(4 * a.size(), id()) {\n        int x = 1;\n        while (a.size() > x) {\n\
    \            x <<= 1;\n        }\n        sz = x;\n        for (int i = 0; i <\
    \ a.size(); i++) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\npublic:\n    void set(int pos, S x) {\n        assert(0 <= pos && pos <\
    \ sz);\n        dat[pos + sz - 1] = x;\n    }\n    void build() {\n        for\
    \ (int i = sz - 2; i >= 0; i--) {\n            dat[i] = op(dat[2 * i + 1], dat[2\
    \ * i + 2]);\n        }\n    }\n\nprivate:\n    void eval(int pos) {\n       \
    \ if (lz[pos] == id()) return;\n        if (pos < sz - 1) {\n            lz[2\
    \ * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n            lz[2 * pos + 2] =\
    \ comp(lz[2 * pos + 2], lz[pos]);\n        }\n        dat[pos] = mapping(dat[pos],\
    \ lz[pos]);\n        lz[pos] = id();\n    }\n\nprivate:\n    void update(int L,\
    \ int R, int l, int r, F x, int k) {\n        eval(k);\n        if (L <= l &&\
    \ r <= R) {\n            lz[k] = comp(lz[k], x);\n            eval(k);\n     \
    \   }\n        else if (L < r && l < R) {\n            int mid = (l + r) >> 1;\n\
    \            update(L, R, l, mid, x, 2 * k + 1);\n            update(L, R, mid,\
    \ r, x, 2 * k + 2);\n            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n\
    \        }\n    }\npublic:\n    void update(int l, int r, F x) {\n        assert(0\
    \ <= l && l <= r && r <= sz);\n        update(l, r, 0, sz, x, 0);\n    }\n\nprivate:\n\
    \    S prod(int L, int R, int l, int r, int k) {\n        eval(k);\n        if\
    \ (r <= L || R <= l) {\n            return e();\n        }\n        else if (L\
    \ <= l && r <= R) {\n            return dat[k];\n        }\n        else {\n \
    \           int mid = (l + r) >> 1;\n            S vl = prod(L, R, l, mid, 2 *\
    \ k + 1);\n            S vr = prod(L, R, mid, r, 2 * k + 2);\n            return\
    \ op(vl, vr);\n        }\n    }\n\npublic:\n    S prod(int l, int r) {\n     \
    \   assert(0 <= l && l <= r && r <= sz);\n        return prod(l, r, 0, sz, 0);\n\
    \    }\n\n    S operator[](int pos) {\n        return prod(pos, pos + 1);\n  \
    \  }\n};\n//@brief lazy_segtree\n"
  code: "template<\n    class S, class F,\n    S(*op)(S, S), S(*e)(),\n    F(*comp)(F,\
    \ F), F(*id)(),\n    S(*mapping)(S, F)\n>\nclass lazy_segtree {\n    int sz;\n\
    \    vector<S> dat;\n    vector<F> lz;\npublic:\n    lazy_segtree(int n) :lazy_segtree(vector<S>(n,\
    \ e())) {    }\n    lazy_segtree(const vector<S>& a) :dat(4 * a.size(), e()),\
    \ lz(4 * a.size(), id()) {\n        int x = 1;\n        while (a.size() > x) {\n\
    \            x <<= 1;\n        }\n        sz = x;\n        for (int i = 0; i <\
    \ a.size(); i++) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\npublic:\n    void set(int pos, S x) {\n        assert(0 <= pos && pos <\
    \ sz);\n        dat[pos + sz - 1] = x;\n    }\n    void build() {\n        for\
    \ (int i = sz - 2; i >= 0; i--) {\n            dat[i] = op(dat[2 * i + 1], dat[2\
    \ * i + 2]);\n        }\n    }\n\nprivate:\n    void eval(int pos) {\n       \
    \ if (lz[pos] == id()) return;\n        if (pos < sz - 1) {\n            lz[2\
    \ * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n            lz[2 * pos + 2] =\
    \ comp(lz[2 * pos + 2], lz[pos]);\n        }\n        dat[pos] = mapping(dat[pos],\
    \ lz[pos]);\n        lz[pos] = id();\n    }\n\nprivate:\n    void update(int L,\
    \ int R, int l, int r, F x, int k) {\n        eval(k);\n        if (L <= l &&\
    \ r <= R) {\n            lz[k] = comp(lz[k], x);\n            eval(k);\n     \
    \   }\n        else if (L < r && l < R) {\n            int mid = (l + r) >> 1;\n\
    \            update(L, R, l, mid, x, 2 * k + 1);\n            update(L, R, mid,\
    \ r, x, 2 * k + 2);\n            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n\
    \        }\n    }\npublic:\n    void update(int l, int r, F x) {\n        assert(0\
    \ <= l && l <= r && r <= sz);\n        update(l, r, 0, sz, x, 0);\n    }\n\nprivate:\n\
    \    S prod(int L, int R, int l, int r, int k) {\n        eval(k);\n        if\
    \ (r <= L || R <= l) {\n            return e();\n        }\n        else if (L\
    \ <= l && r <= R) {\n            return dat[k];\n        }\n        else {\n \
    \           int mid = (l + r) >> 1;\n            S vl = prod(L, R, l, mid, 2 *\
    \ k + 1);\n            S vr = prod(L, R, mid, r, 2 * k + 2);\n            return\
    \ op(vl, vr);\n        }\n    }\n\npublic:\n    S prod(int l, int r) {\n     \
    \   assert(0 <= l && l <= r && r <= sz);\n        return prod(l, r, 0, sz, 0);\n\
    \    }\n\n    S operator[](int pos) {\n        return prod(pos, pos + 1);\n  \
    \  }\n};\n//@brief lazy_segtree"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/lazy_segtree.hpp
- /library/data-structure/lazy_segtree.hpp.html
title: lazy_segtree
---
