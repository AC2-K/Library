---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL/2_D_lazy.test.cpp
    title: test/AOJ/DSL/2_D_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_E_lazy.test.cpp
    title: test/AOJ/DSL/2_E_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data-structure/lazy_segtree.md
    document_title: LazySegmentTree
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp
  bundledCode: "#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n/// @brief LazySegmentTree\n/// @ref\n\
    /// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
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
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/lazy_segtree.md\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    /// @brief LazySegmentTree\n/// @ref\n/// https://github.com/atcoder/ac-library/blob/master/atcoder/lazysegtree.hpp\n\
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
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/lazy_segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-05-07 10:38:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL/2_D_lazy.test.cpp
  - test/AOJ/DSL/2_E_lazy.test.cpp
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
documentation_of: src/data-structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy_segtree.hpp
- /library/src/data-structure/lazy_segtree.hpp.html
title: LazySegmentTree
---
