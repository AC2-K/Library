## 概要
- モノイド $(S,\cdot,\mathtt{e}),(F,\circ,\mathtt{id})$
- 演算 $*:S\times F\to S$ 
 
に対して、以下の条件が満たされるとします。

- 任意の $x\in S$ に対して $x * \mathtt{id}=x$
- 任意の $x,y\in S,f\in F$に対して $(x \cdot y)\ast f=(x\ast f)\cdot(y\ast f)$
- 任意の $x\in S$ と $f_1,f_2\in F$ について$(x\ast f_1)*f_2=x\ast (f1\circ f2)$
 
この時、$S$ の列 $a=(a_0,a_1,\dots,a_{n-1})$ に対して以下をクエリごと $O(\log n)$ で行います。
 
- $l,r$ が与えられたとき、$a_l\cdot a_{l+1}\dots a_{r-1}$ を計算する
- $l,r$ と $f\in F$が与えられたとき、全ての $i\in [l,r)$ に対して $a_i\leftarrow a_i*f$ と更新

## コンストラクタ1
```cpp
kyopro::lazy_segtree<S,F,op,e,composition,id,mapping> seg(int n);
```
$a$ を長さ $n$,初期値$e$で初期化して生成します。
### 計算量
- $O(n)$

## コンストラクタ2
```cpp
kyopro::lazy_segtree<S,F,op,e,composition,id,mapping> seg(std::vector<S> a);
```
$a$ をそのまま渡すこともできます。

## 計算量
- $n$ を $a$ の長さとして $O(n)$

## fold
```cpp
S fold(int l,int r)
```
$a_l\cdot a_{l+1}\dots a_r$ を計算します。$l=r$ の時は $\mathbb{e}$ を返します。

### 制約
- $0\leq l\leq r<n$

### 計算量
- $O(\log n)$

## apply
```cpp
void apply(int l,int r,F f)
```
$i\in[l,r)$ に対して、$a_i\leftarrow a_i*f$ と更新します

### 制約
- $0\leq l\leq r<n$

### 計算量
- $O(\log n)$

## operator[]
```cpp
S seg[int i]
```
$a_i$ を返す

### 制約
- $0\leq i<n$

### 計算量
- $O(\log n)$