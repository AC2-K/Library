---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data-structure-2d/RangeTree.hpp
    title: src/data-structure-2d/RangeTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_B.test.cpp
    title: test/AOJ/DSL/2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
    title: test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/segtree.md
    document_title: SegmentTree
    links: []
  bundledCode: "#line 2 \"src/data-structure/segtree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief SegmentTree\n */\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()>\nclass segtree {\n    int lg, sz, n;\n    std::vector<S>\
    \ dat;\n\npublic:\n    segtree() {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& vec) : n((int)vec.size()) {\n  \
    \      sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n   \
    \         lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n\n\
    \        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n        }\n\
    \        build();\n    }\n\n    void set(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build() {\n    \
    \    for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i << 1 |\
    \ 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const { return\
    \ dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0 <=\
    \ p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1)\
    \ {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n\
    \    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n   \
    \     }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n        while\
    \ (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if\
    \ (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    void apply(int p, const S& v) {\n  \
    \      assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/segtree.md\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nnamespace kyopro {\n\
    \n/**\n * @brief SegmentTree\n */\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    class segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree()\
    \ {}\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const\
    \ std::vector<S>& vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n     \
    \   while (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n\
    \        dat = std::vector<S>(sz << 1, e());\n\n        for (int i = 0; i < n;\
    \ i++) {\n            set(i, vec[i]);\n        }\n        build();\n    }\n\n\
    \    void set(int p, const S& v) {\n        assert(0 <= p && p < sz);\n      \
    \  dat[sz + p] = v;\n    }\n    void build() {\n        for (int i = sz - 1; i\
    \ > 0; i--) {\n            dat[i] = op(dat[i << 1 | 0], dat[i << 1 | 1]);\n  \
    \      }\n    }\n\n    S operator[](int p) const { return dat[sz + p]; }\n\n \
    \   void update(int p, const S& v) {\n        assert(0 <= p && p < sz);\n    \
    \    p += sz;\n        dat[p] = v;\n        while (p >>= 1) {\n            dat[p]\
    \ = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n    }\n\n    S fold(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= sz);\n        if\
    \ (l == 0 && r == n) {\n            return dat[1];\n        }\n        l += sz,\
    \ r += sz;\n        S sml = e(), smr = e();\n        while (l != r) {\n      \
    \      if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr = op(dat[--r],\
    \ smr);\n            l >>= 1, r >>= 1;\n        }\n        return op(sml, smr);\n\
    \    }\n    void apply(int p, const S& v) {\n        assert(0 <= p && p < sz);\n\
    \        update(p, op(dat[sz + p], v));\n    }\n};\n};  // namespace kyopro\n\n\
    /**\n * @docs docs/data-structure/segtree.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy:
  - src/data-structure-2d/RangeTree.hpp
  timestamp: '2023-05-09 23:52:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  - test/AOJ/DSL/2_B.test.cpp
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: SegmentTree
---
## 概要
$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. 区間積を取得


## コンストラクタ1
```cpp
kyopro::segtree<S,op,e> seg(int n)
```
$a$を$e$で埋めて生成します。
なお、`op`,`e`は

```cpp
S op(S x,S y) {
    //x op y を返す
}
S e() {
    //eの値を渡す
}
```

のような形式で渡してください。
### 計算量
- $O(n)$

## コンストラクタ2
```cpp
kyopro::segtree<S,op,e> seg(std::vector<S> a)
```
そのまま$a$を渡すこともできます。

### 計算量
- $n$ を $a$ の長さとして $O(n)$


## update
```cpp
void update(int p,S v)
```
$a_p\leftarrow v$ を行う

### 制約
- $0\leq p<n$

### 計算量
- $O(\log n)$

## fold
```cpp
S fold(int l,int r)
```

区間$[l,r)$の総積を求める。ただし、$l=r$の時は$e$を返す。

### 制約
- $0\leq l\leq r <n$

### 計算量
- $O(\log n)$


## apply
```cpp
void apply(int pos,S x)
```
$a_{\text{pos}}\leftarrow \text{op}(a_{\text{pos}},x)$を行う
### 制約
- $0\leq \text{pos}<n$


### 計算量
- $O(\log n)$

## operator[]
```cpp
S seg[int p]
```
$a_{p}$を返す。
### 制約
- $0\leq \text{pos} <n$

### 計算量
- 計算量:$O(1)$


## 初期化・・・set,build
最初から $a$ が与えられている状況において $O(n)$ で初期化しようと思うと、コンストラクタ2を使うことになります。しかし、このためだけにいちいちvectorを作るのはやや面倒...
\
\
ということで、初期化専用のメソッド`set`,`build`が定義されています。\
使い方は[こちら](https://ac2-k.github.io/library/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp)を参照してください
