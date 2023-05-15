## 概要

$(S,\mathtt{op},\mathtt{e})$がモノイドをなすとする.\
このとき, $S$ の要素の列 $a=(a_0,a_1,\dots,a_{n-1})$ に対して以下の処理を $O(\log n)$ で行う.

1. $a_p\leftarrow v$
1. 区間積を取得

## コンストラクタ1

```cpp
kyopro::segtree<S,op,e> seg(int n)
```

$a$ を $\mathtt{e}$ で埋めて生成します.
なお,`op`,`e`は

```cpp
S op(S x,S y) {
    //x op y を返す
}
S e() {
    //Sの単位元(e)を返す
}
```

のような形式で渡してください.

### 計算量

- $O(n)$

## コンストラクタ2

```cpp
kyopro::segtree<S,op,e> seg(std::vector<S> a)
```

そのまま $a$ を渡すこともできます.

### 計算量

- $O(\vert a\vert)$

## update

```cpp
void update(int p,S v)
```

$a_p \leftarrow v$ を行う

### 制約

- $0 \leq p \lt n$

### 計算量

- $O(\log n)$

## fold

```cpp
S fold(int l,int r)
```

区間 $[l,r)$ の区間積を求める.ただし, $l=r$ の時は $e$ を返す.

### 制約

- $0 \leq l \leq r \lt n$

### 計算量

- $O(\log n)$

## apply

```cpp
void apply(int pos,S x)
```

$a_{\mathtt{pos}}\leftarrow \mathtt{op}(a_{\mathtt{pos}},x)$ を行う

### 制約

- $0 \leq \mathtt{pos} \lt n$

### 計算量

- $O(\log n)$

## operator[]

```cpp
S seg[int p]
```

$a_{p}$を返す.

### 制約

- $0\leq \text{pos} \lt n$

### 計算量

- $O(1)$

## 初期化・・・set,build

最初から $a$ が与えられている状況において $O(n)$ で初期化しようと思うと,コンストラクタ2を使うことになります.しかし,このためだけにいちいちvectorを作るのはやや面倒...
\
\
ということで,初期化専用のメソッド`set`,`build`が定義されています.\
使い方は[こちら](https://ac2-k.github.io/library/test/yosupo_judge/data_structure/Point_Set_Range_Composite.test.cpp)を参照してください
