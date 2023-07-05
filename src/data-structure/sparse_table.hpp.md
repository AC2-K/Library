---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: src/tree/EulerTour.hpp
    title: Euler Tour
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL/5_C.test.cpp
    title: test/AOJ/GRL/5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
    title: test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
    title: test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
    title: test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data-structure/sparse_table.md
    document_title: SparseTable
    links: []
  bundledCode: "#line 2 \"src/data-structure/sparse_table.hpp\"\n#include <numeric>\n\
    #include <vector>\nnamespace kyopro {\n\n/**\n * @brief SparseTable\n */\ntemplate\
    \ <class T, auto op> class sparse_table {\n    std::vector<T> vec;\n    std::vector<std::vector<T>>\
    \ table;\n    std::vector<int> look_up;\n\npublic:\n    constexpr explicit sparse_table(int\
    \ n) : vec(n) {}\n    constexpr explicit sparse_table(const std::vector<T>& vec)\
    \ : vec(vec) {\n        build();\n    }\n    void set(int p, const T& v) { vec[p]\
    \ = v; }\n    void build() {\n        int sz = vec.size();\n        int log =\
    \ 0;\n        while ((1 << log) <= sz) {\n            log++;\n        }\n    \
    \    table.assign(log, std::vector<T>(1 << log));\n        for (int i = 0; i <\
    \ sz; i++) {\n            table[0][i] = vec[i];\n        }\n        for (int i\
    \ = 1; i < log; i++) {\n            for (int j = 0; j + (1 << i) <= (1 << log);\
    \ j++) {\n                table[i][j] =\n                    op(table[i - 1][j],\
    \ table[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz\
    \ + 1);\n        for (int i = 2; i < (int)look_up.size(); i++) {\n           \
    \ look_up[i] = look_up[i >> 1] + 1;\n        }\n    }\n\n    T fold(int l, int\
    \ r) const {\n        int b = look_up[r - l];\n        return op(table[b][l],\
    \ table[b][r - (1 << b)]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/sparse_table.md\n */\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\nnamespace kyopro {\n\
    \n/**\n * @brief SparseTable\n */\ntemplate <class T, auto op> class sparse_table\
    \ {\n    std::vector<T> vec;\n    std::vector<std::vector<T>> table;\n    std::vector<int>\
    \ look_up;\n\npublic:\n    constexpr explicit sparse_table(int n) : vec(n) {}\n\
    \    constexpr explicit sparse_table(const std::vector<T>& vec) : vec(vec) {\n\
    \        build();\n    }\n    void set(int p, const T& v) { vec[p] = v; }\n  \
    \  void build() {\n        int sz = vec.size();\n        int log = 0;\n      \
    \  while ((1 << log) <= sz) {\n            log++;\n        }\n        table.assign(log,\
    \ std::vector<T>(1 << log));\n        for (int i = 0; i < sz; i++) {\n       \
    \     table[0][i] = vec[i];\n        }\n        for (int i = 1; i < log; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <= (1 << log); j++) {\n        \
    \        table[i][j] =\n                    op(table[i - 1][j], table[i - 1][j\
    \ + (1 << (i - 1))]);\n            }\n        }\n        look_up.resize(sz + 1);\n\
    \        for (int i = 2; i < (int)look_up.size(); i++) {\n            look_up[i]\
    \ = look_up[i >> 1] + 1;\n        }\n    }\n\n    T fold(int l, int r) const {\n\
    \        int b = look_up[r - l];\n        return op(table[b][l], table[b][r -\
    \ (1 << b)]);\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/sparse_table.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/sparse_table.hpp
  requiredBy:
  - src/tree/EulerTour.hpp
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo_judge/tree/Lowest_Common_Ancestor_RMQ.test.cpp
  - test/yosupo_judge/data_structure/Vertex_Add_Path_Sum.test.cpp
  - test/yosupo_judge/data_structure/Vertex_add_Subtree_Sum.test.cpp
  - test/yosupo_judge/data_structure/Static_RMQ.test.cpp
  - test/AOJ/GRL/5_C.test.cpp
documentation_of: src/data-structure/sparse_table.hpp
layout: document
redirect_from:
- /library/src/data-structure/sparse_table.hpp
- /library/src/data-structure/sparse_table.hpp.html
title: SparseTable
---
## 概要

- 全ての $a\in S$ に対して $a \bullet a=a$
- 全ての $a,b,c\in S$ に対して $(a\bullet b)\bullet c=a\bullet(b\bullet c)$

となるような集合 $S$ と $S$ の二項演算 $\bullet$ があるとします。\
例えば

- $(S,\bullet)=(\mathbb{Z},\max)$
- $(S,\bullet)=(\mathbb{Z},\min)$
- $(S,\bullet)=(\mathbb{Z},\text{gcd})$
- $(S,\bullet)=(\mathbb{Z},\text{lcm})$

は条件を満たします。\
この時、 $S$ の要素の列 $a=(a_0,a_1,\dots,a_{n-1})$に対して

- $l,r$ が与えられたとき、区間積 $a_l\bullet a_{l+1} \dots a_{r-1}$を求める。

というクエリを

- 前処理・・・ $O(n\log n)$
- クエリ・・・ $O(1)$

で処理します。\
なお、セグメント木やBITとは違って更新はできません。したがって、**静的な**列を扱うことしかできないことに注意してください。

## コンストラクタ

```cpp
kyopro::sparse_table<S,op> st(int n)
kyopro::sparse_table<S,op> st(std::vector<S> a)
```

長さを渡す場合、後述する`set`メソッドで値を入れてから`build`で構築するようにしてください。\
単に`std::vector`を渡す場合はそのまま構築されます

テンプレート引数の`op`は上での $\bullet$ のことで、

```cpp
S op(S x,S y){
    //x・yを返す
}
```

みたいに定義してそのまま渡してください。

### 計算量

- $n$ を渡す場合は $O(n)$
- $a$ を渡す場合は $O(n\log n)$

## set,build

```cpp
void set(int i,S v)
void build()
```

`set`で $a_i\leftarrow v$ を行います。終わったら`build`で構築してください。

どちらも初期化用

### 制約

- $0 \leq i \lt n$

### 計算量

- `set`・・・ $O(1)$
- `build`・・・ $O(n\log n)$

### fold

```cpp
S fold(int l,int r)
```

区間積 $a_l \bullet a_{l+1} \dots a_{r-1}$ を求めます。

### 制約

- $0 \leq l \lt r \lt n$

### 計算量

- $O(1)$
