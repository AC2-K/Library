---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/lazy_segtree.hpp
    title: LazySegmentTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"test/AOJ/DSL/2_E_lazy.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n#include<iostream>\n#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n/// @brief LazySegmentTree\n\
    /// @ref\n/// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
    template <class S,\n          class F,\n          auto op,\n          auto e,\n\
    \          auto composition,\n          auto id,\n          auto mapping>\nclass\
    \ lazy_segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n    std::vector<F>\
    \ lazy;\n\npublic:\n    lazy_segtree() {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    lazy_segtree(const std::vector<S>& a) : n((int)a.size()) {\n \
    \       sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n  \
    \          lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n \
    \       lazy = std::vector<F>(sz, id());\n        for (int i = 0; i < n; ++i)\
    \ {\n            set(i, a[i]);\n        }\n        build();\n    }\n\npublic:\n\
    \    void set(int i, const S& v) {\n        assert(0 <= i && i < sz);\n      \
    \  dat[i + sz] = v;\n    }\n    void build() {\n        for (int i = sz - 1; i\
    \ > 0; --i) {\n            push_up(i);\n        }\n    }\n\nprivate:\n    void\
    \ all_apply(int p, const F& f) {\n        dat[p] = mapping(dat[p], f);\n     \
    \   if (p < sz) lazy[p] = composition(lazy[p], f);\n    }\n    void push_up(int\
    \ k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]); }\n    void push_down(int\
    \ p) {\n        if (lazy[p] == id()) {\n            return;\n        }\n     \
    \   all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p << 1 | 1, lazy[p]);\n\
    \        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int p) {\n      \
    \  assert(0 <= p && p < n);\n        p += sz;\n        for (int i = lg; i > 0;\
    \ --i) push_down(p >> i);\n        return dat[p];\n    }\n    S prod(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i) {\n\
    \            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n\n        S sml = e(), smr = e();\n \
    \       while (l < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n   \
    \         if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n\n        return op(sml, smr);\n    }\n    void apply(int l, int r,\
    \ const F& v) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return;\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ v);\n                if (r & 1) all_apply(--r, v);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= lg; ++i) {\n            if (((l\
    \ >> i) << i) != l) push_up(l >> i);\n            if (((r >> i) << i) != r) push_up((r\
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/lazy_segtree.md\n\
    #line 4 \"test/AOJ/DSL/2_E_lazy.test.cpp\"\n\ninline int op(int x, int y) { return\
    \ x + y; }\ninline int comp(int x, int y) { return x + y; }\ninline int mapping(int\
    \ x, int y) { return x + y; }\ninline int e() { return 0; }\ninline int id() {\
    \ return 0; }\n\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n \
    \   kyopro::lazy_segtree<int, int, op, e, comp, id, mapping> seg(n);\n    while\
    \ (q--) {\n        int t;\n        scanf(\"%d\", &t);\n        if (!t) {\n   \
    \         int l, r, val;\n            scanf(\"%d%d%d\", &l, &r, &val);\n     \
    \       l--, r--;\n            seg.apply(l, r + 1, val);\n        } else {\n \
    \           int i;\n            scanf(\"%d\", &i);\n            i--;\n       \
    \     printf(\"%d\\n\", seg[i]);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n#include<iostream>\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\
    \n\ninline int op(int x, int y) { return x + y; }\ninline int comp(int x, int\
    \ y) { return x + y; }\ninline int mapping(int x, int y) { return x + y; }\ninline\
    \ int e() { return 0; }\ninline int id() { return 0; }\n\nint main() {\n    int\
    \ n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::lazy_segtree<int, int, op,\
    \ e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n        scanf(\"\
    %d\", &t);\n        if (!t) {\n            int l, r, val;\n            scanf(\"\
    %d%d%d\", &l, &r, &val);\n            l--, r--;\n            seg.apply(l, r +\
    \ 1, val);\n        } else {\n            int i;\n            scanf(\"%d\", &i);\n\
    \            i--;\n            printf(\"%d\\n\", seg[i]);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_E_lazy.test.cpp
  requiredBy: []
  timestamp: '2023-05-07 10:38:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_E_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_E_lazy.test.cpp
- /verify/test/AOJ/DSL/2_E_lazy.test.cpp.html
title: test/AOJ/DSL/2_E_lazy.test.cpp
---
