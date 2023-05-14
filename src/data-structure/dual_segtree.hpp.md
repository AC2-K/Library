---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_D_dual.test.cpp
    title: test/AOJ/DSL/2_D_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_E_dual.test.cpp
    title: test/AOJ/DSL/2_E_dual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
    title: test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dual_segtree.md
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data-structure/dual_segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n/**\n * @brief \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam id F \u306E\
    \u5358\u4F4D\u5143\n */\ntemplate <class F, F (*composition)(F, F), F (*id)()>\n\
    class dual_segtree {\n    std::vector<F> dat;\n    int _n, sz, lg;\n\npublic:\n\
    \    dual_segtree() {}\n    dual_segtree(int _n) : _n(_n) {\n        sz = 1, lg\
    \ = 0;\n        while (sz < _n) {\n            ++lg;\n            sz <<= 1;\n\
    \        }\n        dat.assign(sz << 1, id());\n    }\n\nprivate:\n    void update(int\
    \ p, const F& v) { dat[p] = composition(dat[p], v); }\n    void push(int p) {\n\
    \        if (dat[p] == id()) {\n            return;\n        }\n        update(p\
    \ << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n        dat[p] = id();\n\
    \    }\n\npublic:\n    F operator[](int p) {\n        assert(0 <= p && p < _n);\n\
    \n        F res = id();\n\n        p += sz;\n        for (int i = lg; i > 0; i--)\
    \ {\n            push(p >> i);\n        }\n        return dat[p];\n    }\n\n \
    \   void apply(int l, int r, const F& v) {\n        assert(0 <= l && l <= r &&\
    \ r <= _n);\n        if (l == r) return;\n        l += sz, r += sz;\n        for\
    \ (int i = lg; i > 0; i--) {\n            if (((l >> i) << i) != l) {\n      \
    \          push(l >> i);\n            }\n            if (((r >> i) << i) != r)\
    \ {\n                push((r - 1) >> i);\n            }\n        }\n        while\
    \ (l < r) {\n            if (l & 1) {\n                update(l++, v);\n     \
    \       }\n            if (r & 1) {\n                update(--r, v);\n       \
    \     }\n            l >>= 1, r >>= 1;\n        }\n    }\n};\n\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/data-structure/dual_segtree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    /**\n * @brief \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n * @tparam F\
    \ \u4F5C\u7528\u7D20\n * @tparam id F \u306E\u5358\u4F4D\u5143\n */\ntemplate\
    \ <class F, F (*composition)(F, F), F (*id)()>\nclass dual_segtree {\n    std::vector<F>\
    \ dat;\n    int _n, sz, lg;\n\npublic:\n    dual_segtree() {}\n    dual_segtree(int\
    \ _n) : _n(_n) {\n        sz = 1, lg = 0;\n        while (sz < _n) {\n       \
    \     ++lg;\n            sz <<= 1;\n        }\n        dat.assign(sz << 1, id());\n\
    \    }\n\nprivate:\n    void update(int p, const F& v) { dat[p] = composition(dat[p],\
    \ v); }\n    void push(int p) {\n        if (dat[p] == id()) {\n            return;\n\
    \        }\n        update(p << 1 | 0, dat[p]);\n        update(p << 1 | 1, dat[p]);\n\
    \        dat[p] = id();\n    }\n\npublic:\n    F operator[](int p) {\n       \
    \ assert(0 <= p && p < _n);\n\n        F res = id();\n\n        p += sz;\n   \
    \     for (int i = lg; i > 0; i--) {\n            push(p >> i);\n        }\n \
    \       return dat[p];\n    }\n\n    void apply(int l, int r, const F& v) {\n\
    \        assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return;\n \
    \       l += sz, r += sz;\n        for (int i = lg; i > 0; i--) {\n          \
    \  if (((l >> i) << i) != l) {\n                push(l >> i);\n            }\n\
    \            if (((r >> i) << i) != r) {\n                push((r - 1) >> i);\n\
    \            }\n        }\n        while (l < r) {\n            if (l & 1) {\n\
    \                update(l++, v);\n            }\n            if (r & 1) {\n  \
    \              update(--r, v);\n            }\n            l >>= 1, r >>= 1;\n\
    \        }\n    }\n};\n\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/dual_segtree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/dual_segtree.hpp
  requiredBy: []
  timestamp: '2023-05-07 23:12:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Affine_Point_Get.test.cpp
  - test/AOJ/DSL/2_D_dual.test.cpp
  - test/AOJ/DSL/2_E_dual.test.cpp
documentation_of: src/data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/dual_segtree.hpp
- /library/src/data-structure/dual_segtree.hpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## 概要
双対セグメント木(DualSegmentTree)とは、以下のようなデータ構造です

> モノイド $(F,\circ,\mathtt{id})$ の列 $f=(f_0,f_1\dots,f_{n-1})$ に対して、以下をいずれものクエリごと $O(\log n)$ で処理する
> 
> - $l,r$ と $g\in F$ が与えられたとき、 全ての $i\in [l,r)$ に対して $f_i\leftarrow f_i\circ g$ と更新する
> - $i$ が与えられたとき、 $f_i$ を求める

LazySegmentTreeの作用素側のみを取り出したと考えることもできます.

## コンストラクタ
```cpp
kyopro::dual_segtree<F,composition,id> ds(int n);
```
$f=(\mathtt{id},\mathtt{id},...,\mathtt{id})$ で初期化します。\
`composition,id`は以下の形式で定義して渡してください。


```cpp
F composition(F x,F y){
    //x∘yを返す
}

F id(){
    //Fの単位元(id)を返す
}
```
### 計算量
- $O(n)$

## apply
```cpp
void apply(int l,int r,F g)
```
全ての $i\in [l,r)$ に対して $f_i\leftarrow f_i\circ g$ と更新します

### 制約
- $0 \leq l \leq r \lt n$

### 計算量
- $O(\log n)$

## operator[]
```cpp
F ds[int i]
```
$f_i$ を求めます

### 制約
- $0 \leq i \lt n$

### 計算量
- $O(\log n)$

