# lazy_segtree
遅延評価セグメント木です。具体的な使い方だけ知りたい人は、少し下にスクロールしてください。

## できること
モノイド $(S,\text{op},e)$ と 集合 $F$ ,写像 $g:S\times F\to S$ について、 $S$ の列 $a=(a_1,a_2,\dots,a_n)$ に対して、以下をそれぞれ $O(\log n)$ で処理する
- $1\leq l\leq r\leq n$ なる整数 $l,r$ と $x\in F$ が与えられたとき、各整数 $i=l,l+1,\dots,r-1$ に対して $a_i\leftarrow g(a_i,x)$ とする
- $1\leq l\leq r\leq n$ なる整数 $l,r$ が与えられたとき、 $$\prod_{i=l}^{r-1}{a_i}$$ を計算する。
