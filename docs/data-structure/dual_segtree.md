## 概要

双対セグメント木(DualSegmentTree)とは、以下のようなデータ構造です

> モノイド $(F,\circ,\mathtt{id})$ の列 $f=(f_0,f_1\dots,f_{n-1})$ に対して、以下をいずれものクエリごと $O(\log n)$ で処理する
>
> - $l,r$ と $g\in F$ が与えられたとき、 全ての $i\in [l,r)$ に対して $f_i\leftarrow f_i\circ g$ と更新する
> - $i$ が与えられたとき、 $f_i$ を求める

LazySegmentTreeの作用素側のみを取り出したデータ構造と考えることもできます.

## コンストラクタ

```cpp
kyopro::dual_segtree<F,composition,id> ds(int n);
```

$f=(\mathtt{id},\mathtt{id},...,\mathtt{id})$ で初期化します.\
`composition,id`は以下の形式で定義して渡してください.

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
