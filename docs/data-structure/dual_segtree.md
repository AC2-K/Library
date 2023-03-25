## 概要
(あってる...?)\
$(F,\circ,\text{id})$ をモノイドとする。\
この時、 $F$ 上の列 $a=(a_1,a_2\dots,a_n)$について、以下のクエリを高速に処理する。
- $v\in F$ と区間 $[l,r)$ が与えられる。 $i\in [l,r)$ なる全ての $i$ に対して $a_i\leftarrow a_i\circ v$ と更新する。

- $i$ が与えられたとき、 $a_i$ を求める。

## 使いかた
### コンストラクタ
```cpp
dual_segtree<F,comp,id> seg(int n);
```
長さ $n$ の双対セグメント木を作ります。\
テンプレート引数は以下の通りです
- `comp`:$F$ 上の二項演算。すなわち上での $\circ$
- `id`:$F$ の単位元。上での $e$

最初 $a=(\text{id},\text{id},\text{id},\dots,\text{id})$ です。
### メソッド
```cpp
void apply(int l,int r,F x)
```
区間 $[l,r)$ に $x$ を作用させます。
- 計算量: $O(\log n)$

```cpp
F seg[int i]
```
$a_i$ を取得します
- 計算量 $O(\log n)$