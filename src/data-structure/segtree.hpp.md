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
    document_title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
    links: []
  bundledCode: "#line 2 \"src/data-structure/segtree.hpp\"\n#include <vector>\nnamespace\
    \ kyopro {\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\n\
    template <class S, S (*op)(S, S), S (*e)()>\nclass segtree {\n    int lg, sz,\
    \ n;\n    std::vector<S> dat;\n\npublic:\n    segtree() {}\n    segtree(int n)\
    \ : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>& vec)\
    \ : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n) {\n\
    \            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    inline void set(int p, const S& v)\
    \ { dat[sz + p] = v; }\n    inline void build() {\n        for (int i = sz - 1;\
    \ i > 0; i--) {\n            dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n  \
    \      }\n    }\n    S operator[](int p) const { return dat[sz + p]; }\n\n   \
    \ inline void update(int p, const S& v) {\n        p += sz;\n        dat[p] =\
    \ v;\n        while (p >>= 1) {\n            dat[p] = op(dat[(p << 1)], dat[(p\
    \ << 1) ^ 1]);\n        }\n    }\n\n    inline S prod(int l, int r) const {\n\
    \        if (l == 0 && r == n) {\n            return dat[1];\n        }\n    \
    \    l += sz, r += sz;\n        S sml = e(), smr = e();\n        while (l != r)\
    \ {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr\
    \ = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n    inline void apply(int p, const S& v) { update(p, op(dat[sz\
    \ + p], v)); }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/segtree.md\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n/// @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\n\
    class segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree()\
    \ {}\n    segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const\
    \ std::vector<S>& vec) : n((int)vec.size()) {\n        sz = 1, lg = 0;\n     \
    \   while (sz <= n) {\n            sz <<= 1;\n            lg++;\n        }\n\n\
    \        dat = std::vector<S>(sz << 1, e());\n\n        for (int i = 0; i < n;\
    \ i++) {\n            set(i, vec[i]);\n        }\n        build();\n    }\n\n\
    \    inline void set(int p, const S& v) { dat[sz + p] = v; }\n    inline void\
    \ build() {\n        for (int i = sz - 1; i > 0; i--) {\n            dat[i] =\
    \ op(dat[i << 1], dat[(i << 1) ^ 1]);\n        }\n    }\n    S operator[](int\
    \ p) const { return dat[sz + p]; }\n\n    inline void update(int p, const S& v)\
    \ {\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1) {\n      \
    \      dat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n        }\n    }\n\n  \
    \  inline S prod(int l, int r) const {\n        if (l == 0 && r == n) {\n    \
    \        return dat[1];\n        }\n        l += sz, r += sz;\n        S sml =\
    \ e(), smr = e();\n        while (l != r) {\n            if (l & 1) sml = op(sml,\
    \ dat[l++]);\n            if (r & 1) smr = op(dat[--r], smr);\n            l >>=\
    \ 1, r >>= 1;\n        }\n        return op(sml, smr);\n    }\n    inline void\
    \ apply(int p, const S& v) { update(p, op(dat[sz + p], v)); }\n};\n};  // namespace\
    \ kyopro\n\n/// @docs docs/data-structure/segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/segtree.hpp
  requiredBy:
  - src/data-structure-2d/RangeTree.hpp
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  - test/AOJ/DSL/2_B.test.cpp
documentation_of: src/data-structure/segtree.hpp
layout: document
redirect_from:
- /library/src/data-structure/segtree.hpp
- /library/src/data-structure/segtree.hpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# 概要
$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. 区間積を取得

# 使い方
## コンストラクタ
```cpp
segtree<S,op,e> seg(int n)
```
$a$を$e$で埋めて生成します。
```cpp
segtree<S,op,e> seg(std::vector<S> a)
```
そのまま$a$を渡すこともできます。
\
\
テンプレート引数には、 $S$ と, $\text{op},e$nを以下の形式で渡す必要があります。
```cpp
S op(S x,S y)
S e()
```
\
\
例として、RmQは、以下のように定義できます。
```cpp

int op(int x,int y){
    return min(x,y);
}
int e(){
    return (十分大きい値);
}
segtree<int,op,e> seg(n);
```

## メソッド
```cpp
void seg.update(int p,S v)
```
$a_p\leftarrow v$とする。
- 制約:$0\leq p<n$
- 計算量:$O(\log n)$

```cpp
S seg.prod(int l,int r)
```
区間積を求める。ただし、$l=r$の時は$e$を返す。
- 制約:$0\leq l\leq r <n$
- 計算量:$O(\log n)$

```cpp
void seg.apply(int pos,S x)
```
$a_{\text{pos}}\leftarrow \text{op}(a_{\text{pos}},x)$とする
- 制約:$0\leq \text{pos}<n$
- 計算量:$O(\log n)$

```cpp
S seg[int pos]
```
$a_{\text{pos}}$を返す。
- 制約:$0\leq \text{pos} <n$
- 計算量:$O(1)$