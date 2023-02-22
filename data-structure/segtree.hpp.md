---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Longest Increasing Subsequence.test.cpp
    title: test/Library-Checker/Longest Increasing Subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Point Add Range Sum.test.cpp
    title: test/Library-Checker/Point Add Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Point Set Range Composite.test.cpp
    title: test/Library-Checker/Point Set Range Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Static Range Sum.test.cpp
    title: test/Library-Checker/Static Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
    title: test/Library-Checker/Vertex Add Subtree Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: segmenttree
    links: []
  bundledCode: "#line 1 \"data-structure/segtree.hpp\"\ntemplate<class S, S(*op)(S,\
    \ S), S(*e)()>\nclass segtree {\n    int n;\n    vector<S> dat;\n    void Init(int\
    \ n_) {\n        int x = 1;\n        while (n_ > x) {\n            x <<= 1;\n\
    \        }\n        n = x;\n    }\npublic:\n    segtree(int n_) : segtree(vector<S>(n_,\
    \ e())) {   }\n    segtree(const vector<S>& v) :dat(4 * v.size()) {\n        Init(v.size());\n\
    \        for (int i = 0; i < v.size(); i++) {\n            set(i, v[i]);\n   \
    \     }\n        build();\n    }\n    inline void set(int pos, S val) {\n    \
    \    assert(0 <= pos && pos < n);\n        dat[pos + n - 1] = val;\n    }\n  \
    \  void build() {\n        for (int k = n - 2; k >= 0; k--) {\n            dat[k]\
    \ = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);\n        }\n    }\n\n    void update(int\
    \ pos, S val) {\n        assert(0 <= pos && pos < n);\n        pos += n - 1;\n\
    \        dat[pos] = val;\n        while (pos > 0) {\n            pos = (pos -\
    \ 1) >> 1;\n            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);\n\
    \        }\n    }\n    inline S prod(int a, int b) {\n        assert(0 <= a &&\
    \ b <= n);\n        assert(a <= b);\n        if (a == 0 && b == n)return dat[0];\n\
    \        return prod(a, b, 0, 0, n);\n    }\n\nprivate:\n    S prod(int a, int\
    \ b, int id, int l, int r) {\n        if (r <= a || b <= l) {\n            return\
    \ e();\n        }\n        else if (a <= l && r <= b) {\n            return dat[id];\n\
    \        }\n        else {\n            int mid = (l + r) >> 1;\n            S\
    \ vl = prod(a, b, (id << 1) + 1, l, mid);\n            S vr = prod(a, b, (id <<\
    \ 1) + 2, mid, r);\n            return op(vl, vr);\n        }\n    }\n\npublic:\n\
    \    //a[pos] <- a[pos]\u30FBx\n    void add(int pos, S x) {\n        update(pos,\
    \ op(dat[n + pos - 1], x));\n    }\n\n    S operator [](int pos) {\n        return\
    \ dat[n + pos - 1];\n    }\n};\n/// @brief segmenttree\n"
  code: "template<class S, S(*op)(S, S), S(*e)()>\nclass segtree {\n    int n;\n \
    \   vector<S> dat;\n    void Init(int n_) {\n        int x = 1;\n        while\
    \ (n_ > x) {\n            x <<= 1;\n        }\n        n = x;\n    }\npublic:\n\
    \    segtree(int n_) : segtree(vector<S>(n_, e())) {   }\n    segtree(const vector<S>&\
    \ v) :dat(4 * v.size()) {\n        Init(v.size());\n        for (int i = 0; i\
    \ < v.size(); i++) {\n            set(i, v[i]);\n        }\n        build();\n\
    \    }\n    inline void set(int pos, S val) {\n        assert(0 <= pos && pos\
    \ < n);\n        dat[pos + n - 1] = val;\n    }\n    void build() {\n        for\
    \ (int k = n - 2; k >= 0; k--) {\n            dat[k] = op(dat[(k << 1) + 1], dat[(k\
    \ << 1) + 2]);\n        }\n    }\n\n    void update(int pos, S val) {\n      \
    \  assert(0 <= pos && pos < n);\n        pos += n - 1;\n        dat[pos] = val;\n\
    \        while (pos > 0) {\n            pos = (pos - 1) >> 1;\n            dat[pos]\
    \ = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);\n        }\n    }\n    inline\
    \ S prod(int a, int b) {\n        assert(0 <= a && b <= n);\n        assert(a\
    \ <= b);\n        if (a == 0 && b == n)return dat[0];\n        return prod(a,\
    \ b, 0, 0, n);\n    }\n\nprivate:\n    S prod(int a, int b, int id, int l, int\
    \ r) {\n        if (r <= a || b <= l) {\n            return e();\n        }\n\
    \        else if (a <= l && r <= b) {\n            return dat[id];\n        }\n\
    \        else {\n            int mid = (l + r) >> 1;\n            S vl = prod(a,\
    \ b, (id << 1) + 1, l, mid);\n            S vr = prod(a, b, (id << 1) + 2, mid,\
    \ r);\n            return op(vl, vr);\n        }\n    }\n\npublic:\n    //a[pos]\
    \ <- a[pos]\u30FBx\n    void add(int pos, S x) {\n        update(pos, op(dat[n\
    \ + pos - 1], x));\n    }\n\n    S operator [](int pos) {\n        return dat[n\
    \ + pos - 1];\n    }\n};\n/// @brief segmenttree"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-02-21 12:21:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Static Range Sum.test.cpp
  - test/Library-Checker/Vertex Add Subtree Sum.test.cpp
  - test/Library-Checker/Point Set Range Composite.test.cpp
  - test/Library-Checker/Longest Increasing Subsequence.test.cpp
  - test/Library-Checker/Point Add Range Sum.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
documentation_of: data-structure/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree.hpp
- /library/data-structure/segtree.hpp.html
title: segmenttree
---
