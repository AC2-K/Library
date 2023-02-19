# lazy_segtree
遅延評価セグメント木です。
## できること
モノイド $(S,\cdot,e),(F,\circ,\text{id})$ と写像 $f:S\times F\to S$ と、 $S$ の列 $a=(a_1,a_2\dots,a_n)$ に対して以下を $O(\log n)$ で処理する。

1. 整数 $l,r$ と $x\in F$ が与えられたとき、 $i\in\[l,r\)$ に対して $a_i\leftarrow{f}(a_i,x)$
1. 整数 $l,r$ が与えられたとき、 $$\prod_{i=l}^{r-1}{a_i}$$ を計算する。


## 条件
以下の条件を満たす必要があります。
- $f(f(x,y),z)=f(x,y \circ z)$
- $f(x\cdot y,z)=f(x,z)\cdot f(y,z)$

...あまり自信がありません。
## コンストラクタ
### サイズを渡す
```cpp
lazy_segtree<S,F,op,e,comp,id,mapping> seg(int n)
```
サイズ $n$ の lazy_segtree を作ります。最初はすべての要素は $e()$ で埋められています。\
セグメント木同様、 `op,e,comp,id,mapping`はそれぞれ関数で渡す必要があります。\
それぞれの役目を書いておきます。
- `S,F,e,id`:上の通り
- `op`: 上での「 $\cdot$ 」
- `comp`: 上での「 $\circ$ 」
- `mapping`:上での $f$

### $a$ を渡す
```cpp
lazy_segtree<S,F,op,e,comp,id,mapping> seg(vector<S> a)
```
あらかじめ $a$ が分かっていれば、そのまま渡してもいいです。

### 計算量
- いずれも $O(n)$ です

## update
```cpp
void seg.update(int l,int r,F x)
```

$i\in\[l,r\)$ に対して $a_i\leftarrow{f}(a_i,x)$ とします。

### 計算量
- $O(\log n)$

## prod
```cpp
S seg.prod(int l,int r)
```
$$\prod_{i=l}^{r-1}{a_i}$$ を計算します。ただし、 $l>r$ の時はエラーとなり、 $l=r$ のときは $e$を返します。

### 計算量
- $O(\log n)$
## operator []
```cpp
S seg[int pos]
```

$a_\text{pos}$ を返します。

### 計算量
- $O(\log n)$
## 初期化のための...
```cpp
void seg.set(int pos,int val)
void seg.build()
```
segtree同様に、`seg,build`が用意してあります。

### 計算量
- `set`: $O(1)$
- `build`: $O(n)$
