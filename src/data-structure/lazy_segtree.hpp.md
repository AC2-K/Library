---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_D_lazy.test.cpp
    title: test/AOJ/DSL/2_D_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_E_lazy.test.cpp
    title: test/AOJ/DSL/2_E_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/lazy_segtree.md
    document_title: LazySegmentTree
    links: []
  bundledCode: "#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n/**\n * @brief LazySegmentTree\n */\ntemplate\
    \ <class S,\n          class F,\n          auto op,\n          auto e,\n     \
    \     auto composition,\n          auto id,\n          auto mapping>\nclass lazy_segtree\
    \ {\n    int lg, sz, n;\n    std::vector<S> dat;\n    std::vector<F> lazy;\n\n\
    public:\n    lazy_segtree() {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
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
    \ --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int l, int\
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
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/lazy_segtree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    /**\n * @brief LazySegmentTree\n */\ntemplate <class S,\n          class F,\n\
    \          auto op,\n          auto e,\n          auto composition,\n        \
    \  auto id,\n          auto mapping>\nclass lazy_segtree {\n    int lg, sz, n;\n\
    \    std::vector<S> dat;\n    std::vector<F> lazy;\n\npublic:\n    lazy_segtree()\
    \ {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}\n    lazy_segtree(const\
    \ std::vector<S>& a) : n((int)a.size()) {\n        sz = 1, lg = 0;\n        while\
    \ (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n       \
    \ dat = std::vector<S>(sz << 1, e());\n        lazy = std::vector<F>(sz, id());\n\
    \        for (int i = 0; i < n; ++i) {\n            set(i, a[i]);\n        }\n\
    \        build();\n    }\n\npublic:\n    void set(int i, const S& v) {\n     \
    \   assert(0 <= i && i < sz);\n        dat[i + sz] = v;\n    }\n    void build()\
    \ {\n        for (int i = sz - 1; i > 0; --i) {\n            push_up(i);\n   \
    \     }\n    }\n\nprivate:\n    void all_apply(int p, const F& f) {\n        dat[p]\
    \ = mapping(dat[p], f);\n        if (p < sz) lazy[p] = composition(lazy[p], f);\n\
    \    }\n    void push_up(int k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]);\
    \ }\n    void push_down(int p) {\n        if (lazy[p] == id()) {\n           \
    \ return;\n        }\n        all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p\
    \ << 1 | 1, lazy[p]);\n        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int\
    \ p) {\n        assert(0 <= p && p < n);\n        p += sz;\n        for (int i\
    \ = lg; i > 0; --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r)\
    \ return e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
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
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/lazy_segtree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/lazy_segtree.hpp
  requiredBy: []
  timestamp: '2023-05-09 23:52:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  - test/AOJ/DSL/2_D_lazy.test.cpp
  - test/AOJ/DSL/2_E_lazy.test.cpp
documentation_of: src/data-structure/lazy_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/lazy_segtree.hpp
- /library/src/data-structure/lazy_segtree.hpp.html
title: LazySegmentTree
---
## 概要

- モノイド $(S,\bullet,\mathtt{e}),(F,\circ,\mathtt{id})$
- 演算 $\ast:S\times F\to S$

に対して、以下の条件が満たされるとします。

- 任意の $x\in S$ に対して $x \ast \mathtt{id}=x$
- 任意の $x,y\in S,f\in F$に対して $(x \bullet y)\ast f=(x\ast f)\bullet(y\ast f)$
- 任意の $x\in S$ と $f_1,f_2\in F$ について $(x\ast f_1) \ast f_2=x\ast (f1\circ f2)$

この時, $S$ の要素の列 $a=(a_0,a_1,\dots,a_{n-1})$ に対して以下をクエリごと $O(\log n)$ で行います。

- $l,r$ が与えられたとき、 $a_l\bullet a_{l+1}\dots a_{r-1}$ を計算する
- $l,r$ と $f\in F$が与えられたとき、全ての $i\in [l,r)$ に対して $a_i\leftarrow a_i*f$ と更新

## コンストラクタ1

```cpp
kyopro::lazy_segtree<S,F,op,e,composition,id,mapping> seg(int n);
```

$a$ を長さ $n$ ,初期値 $\mathtt{e}$ の状態で作成します

### 計算量

- $O(n)$

## コンストラクタ2

```cpp
kyopro::lazy_segtree<S,F,op,e,composition,id,mapping> seg(std::vector<S> a);
```

$a$ をそのまま渡すこともできます。

## 計算量

- $O(\vert a\vert)$

## fold

```cpp
S fold(int l,int r)
```

$a_l\bullet a_{l+1}\dots a_r$ を計算します。 $l=r$ の時は $\mathtt{e}$ を返します。

### 制約

- $0 \leq l \leq r \lt n$

### 計算量

- $O(\log n)$

## apply

```cpp
void apply(int l,int r,F f)
```

全ての $i\in[l,r)$ に対して、$a_i \leftarrow a_i \ast f$ と更新します

### 制約

- $0 \leq l \leq r \lt n$

### 計算量

- $O(\log n)$

## operator[]

```cpp
S seg[int i]
```

$a_i$ を返す

### 制約

- $0 \leq i \lt n$

### 計算量

- $O(\log n)$
