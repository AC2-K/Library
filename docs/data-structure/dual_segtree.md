# Dual SegmentTree(双対セグメント木)

$(F,\circ,\text{id})$ がモノイドをなすとする。\
この時、 $F$ 上の列 $a=(a_1,a_2\dots,a_n)$について、以下のクエリを高速に処理する。
- $v\in F$ と区間 $[l,r)$ が与えられる。 $i\in [l,r)$ なる全ての $i$ に対して $a_i\leftarrow a_i\circ x$ と更新する。

- $i$ が与えられたとき、 $a_i$ を求める。
