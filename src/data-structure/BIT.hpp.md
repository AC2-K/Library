---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
    title: src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
    title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/BIT.md
    document_title: Binary Index Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/**\n * @brief Binary Index Tree\n */\ntemplate <typename T> class\
    \ BIT {\n    std::vector<T> bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n\
    \    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int p, T w)\
    \ {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n          \
    \  bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n        T s = 0;\n\
    \n        for (int x = p; x > 0; x -= x & -x) {\n            s += bit[x];\n  \
    \      }\n        return s;\n    }\n\n    T sum(int l, int r) const { return sum(r)\
    \ - sum(l); }\n\n    int lower_bound(T w) const {\n        if (w <= 0) return\
    \ 0;\n\n        int x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n\
    \        for (; k > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] <\
    \ w) {\n                w -= bit[x + k];\n                x += k;\n          \
    \  }\n        }\n\n        return x + 1;\n    }\n\n    T operator[](int i) { return\
    \ sum(i + 1) - sum(i); }\n    void update(int i, T v) { add(i, T::mod() - sum(i\
    \ + 1) + sum(i) + v); }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/**\n * @brief Binary\
    \ Index Tree\n */\ntemplate <typename T> class BIT {\n    std::vector<T> bit;\n\
    \    int n;\n\npublic:\n    explicit BIT() {}\n    explicit BIT(int n) : n(n),\
    \ bit(n + 1, T()) {}\n    void add(int p, T w) {\n        p++;\n        for (int\
    \ x = p; x <= n; x += x & -x) {\n            bit[x] += w;\n        }\n    }\n\n\
    \    T sum(int p) const {\n        T s = 0;\n\n        for (int x = p; x > 0;\
    \ x -= x & -x) {\n            s += bit[x];\n        }\n        return s;\n   \
    \ }\n\n    T sum(int l, int r) const { return sum(r) - sum(l); }\n\n    int lower_bound(T\
    \ w) const {\n        if (w <= 0) return 0;\n\n        int x = 0;\n        int\
    \ k = 1;\n        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n \
    \           if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x +\
    \ k];\n                x += k;\n            }\n        }\n\n        return x +\
    \ 1;\n    }\n\n    T operator[](int i) { return sum(i + 1) - sum(i); }\n    void\
    \ update(int i, T v) { add(i, T::mod() - sum(i + 1) + sum(i) + v); }\n};\n}; \
    \ // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/BIT.hpp
  requiredBy:
  - src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
  timestamp: '2023-09-10 10:33:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_BIT.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
documentation_of: src/data-structure/BIT.hpp
layout: document
redirect_from:
- /library/src/data-structure/BIT.hpp
- /library/src/data-structure/BIT.hpp.html
title: Binary Index Tree
---
## 概要

Binary Index Tree(BIT) とは、整数列に対する

- 一点加算
- 区間和の計算

をクエリごと $O(\log n)$ で処理するデータ構造です.

## コンストラクタ

```cpp
kyopro::BIT<T> a(int n);
```

長さ $n$ の数列を扱うBITを生成します.
Tは、**和が収まる** 型名です. 
<details>
<summary>おまけ</summary>
型にoperatorを定義してから渡すことで,群やモノイドを乗せることができます(このライブラリはモノイドには対応していません...)
</details>


### 計算量

- $O(n)$

## add

```cpp
void add(int i,T w)
```

$a_i\leftarrow a_i+w$ を行います.

### 制約

- $0 \leq i \lt n$

### 計算量

- $O(\log n)$

## update
```cpp
void update(int i, T w)
```
$a_i\leftarrow w$ を行います.
### 制約

- $0 \leq i \lt n$

### 計算量

- $O(\log n)$


## sum

```cpp
T sum(int p)
```

$\sum_{0 \leq i \lt p}{a_i}$ を計算します

```cpp
T sum(int l, int r)
```

$\sum_{l \leq i \lt r}{a_i}$ を計算します

### 制約

- $0 \leq p \lt n$
- $0 \leq l \leq r \lt n$

### 計算量

- いずれも $O(\log n)$

## operator[]
```cpp
T a[int i]
```
$a_i$ の値を返します

### 制約

- $0 \leq i \lt n$

### 計算量

- いずれも $O(\log n)$



## lower_bound

```cpp
int lower_bound(T w)
```

$\sum_{0 \leq i \lt k}{a_i} \geq w$ となるような最小の $k$ を求めます.\
存在しなければ $\vert a \vert$ を返します.

### 制約

- 呼び出されるとき、$a$ の各項は非負である

### 計算量

- $O(\log n)$
