---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2_B.test.cpp
    title: test/AOJ/DSL/2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
    title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
    title: test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
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
  bundledCode: "#line 1 \"data-structure/segtree.hpp\"\n#include<vector>\nnamespace\
    \ library{\n\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)\n\
    /// @tparam S \u8981\u7D20\u306E\u578B\n/// @tparam op \u4E8C\u9805\u6F14\u7B97\
    \n/// @tparam e \u5358\u4F4D\u5143\ntemplate<class S, S(*op)(S, S), S(*e)()>\n\
    class segtree {\n\tint lg, sz, n;\n\tstd::vector<S> dat;\npublic:\n\tsegtree()\
    \ :segtree(0) {}\n\tsegtree(int n) : segtree(std::vector<S>(n, e())) {}\n\tsegtree(const\
    \ std::vector<S>& vec) : n((int)vec.size()) {\n\t\tsz = 1, lg = 0;\n\t\twhile\
    \ (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\tdat = std::vector<S>(sz\
    \ << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tset(i, vec[i]);\n\t\t\
    }\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const S& v) {\n\t\tdat[sz\
    \ + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i = sz - 1; i > 0; i--)\
    \ {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\t\t}\n\t}\n\tS operator[](const\
    \ int p) const { return dat[sz + p]; }\n\n\tvoid update(int p, const S& v) {\n\
    \t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p >>= 1) {\n\t\t\tdat[p] = op(dat[(p\
    \ << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\n\tS prod(int l, int r) const {\n\t\
    \tif (l == 0 && r == n) {\n\t\t\treturn dat[1];\n\t\t}\n\t\tl += sz, r += sz;\n\
    \t\tS sml = e(), smr = e();\n\t\twhile (l != r) {\n\t\t\tif (l & 1)sml = op(sml,\
    \ dat[l++]);\n\t\t\tif (r & 1)smr = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\
    \t\t}\n\t\treturn op(sml, smr);\n\t}\n\tinline void apply(int p, const S& v) {\n\
    \t\tupdate(p, op(dat[sz + p], v));\n\t}\n};\n};  // namespace library\n\n\n///\
    \ @docs docs/data-structure/segtree.md\n"
  code: "#include<vector>\nnamespace library{\n\n/// @brief Segment Tree(\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728)\n/// @tparam S \u8981\u7D20\u306E\u578B\n/// @tparam\
    \ op \u4E8C\u9805\u6F14\u7B97\n/// @tparam e \u5358\u4F4D\u5143\ntemplate<class\
    \ S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\tstd::vector<S>\
    \ dat;\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n\tsegtree(const std::vector<S>& vec) : n((int)vec.size()) {\n\t\t\
    sz = 1, lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\
    \t\tdat = std::vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\
    \t\t\tset(i, vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int\
    \ p, const S& v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor\
    \ (int i = sz - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1)\
    \ ^ 1]);\n\t\t}\n\t}\n\tS operator[](const int p) const { return dat[sz + p];\
    \ }\n\n\tvoid update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\t\
    while (p >>= 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\t\
    }\n\t}\n\n\tS prod(int l, int r) const {\n\t\tif (l == 0 && r == n) {\n\t\t\t\
    return dat[1];\n\t\t}\n\t\tl += sz, r += sz;\n\t\tS sml = e(), smr = e();\n\t\t\
    while (l != r) {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\t\t\tif (r & 1)smr\
    \ = op(dat[--r], smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\
    \t}\n\tinline void apply(int p, const S& v) {\n\t\tupdate(p, op(dat[sz + p], v));\n\
    \t}\n};\n};  // namespace library\n\n\n/// @docs docs/data-structure/segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-04-06 20:41:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2_B.test.cpp
  - test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp
  - test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
  - test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  - test/yosupo_judge/math/Longest_Increasing_Subsequence.test.cpp
documentation_of: data-structure/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree.hpp
- /library/data-structure/segtree.hpp.html
title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# SegmentTree(セグメント木)
## 概要
$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. 区間 $[l,r)$ の積を取得

## 使い方
### コンストラクタ
```cpp
segtree<S,op,e> seg(int n)
```
$a$を$e$で埋めて生成します。
```cpp
segtree<S,op,e> seg(vector<S> a)
```
そのまま$a$を渡すこともできます。
\
\
template引数には、$S$に加えて$\text{op},e$を以下の形式で渡す必要があります。
```cpp
S op(S x,S y)
S e()
```
\
\
例として、RangeMinQueryには、以下のようにすればよいです。
```cpp
const int inf;  //大きい値

int op(int x,int y){
    return min(x,y);
}
int e(){
    return inf;
}
segtree<int,op,e> seg(n);    //サイズnのsegtree
```

### メソッド
```cpp
void seg.update(int p,S val)
```
$a_p\leftarrow \text{val}$とする。
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