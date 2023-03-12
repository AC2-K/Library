---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/B.test.cpp
    title: test/AOJ/DSL/2/B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
    title: test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - icon: ':x:'
    path: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
    title: test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Static Range Sum.test.cpp
    title: test/yosupo judge/data structure/Static Range Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Vertex Add Subtree Sum.test.cpp
    title: test/yosupo judge/data structure/Vertex Add Subtree Sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
    title: test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/data-structure/segtree.md
    document_title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    \ dat[n + pos - 1];\n    }\n};\n/// @brief segment tree(\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728)\n///@docs docs/data-structure/segtree.md\n"
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
    \ + pos - 1];\n    }\n};\n/// @brief segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n///@docs docs/data-structure/segtree.md"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree.hpp
  requiredBy: []
  timestamp: '2023-03-06 04:18:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo judge/data structure/Vertex Add Subtree Sum.test.cpp
  - test/yosupo judge/data structure/Static Range Sum.test.cpp
  - test/yosupo judge/data structure/Point Set Range Composite.test.cpp
  - test/yosupo judge/data structure/Point Add Range Sum.test.cpp
  - test/yosupo judge/new/Longest Increasing Subsequence.test.cpp
  - test/AOJ/DSL/2/B.test.cpp
documentation_of: data-structure/segtree.hpp
layout: document
redirect_from:
- /library/data-structure/segtree.hpp
- /library/data-structure/segtree.hpp.html
title: "segment tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
# SegmentTree(セグメント木)
## 概要
$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. $\prod_{i\in[l,r)}{a_i}$ を出力

例えば$$S=\mathbb{Z}\cup\{\infty\},\text{op}=\min,e=\infty$$とかにすると、一点更新のRMQになる。
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
$\prod_{i\in[l,r)}{a_i}$を返す。ただし、$l=r$の時は$e$を返す。
- 制約:$0\leq l\leq r <n$
- 計算量:$O(\log n)$

```cpp
void seg.add(int pos,S x)
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