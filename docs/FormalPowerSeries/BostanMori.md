## 概要

数列 $(a_i)_{i=0,1,2,\dots}$ に対し, 以下の条件を満たす定数 $c_0,c_1,c_2,\cdots,c_d$ が存在するならば, $(a_i)_{i=0,1,2,\dots}$ は **線形漸化的** であるといいます.

$$\forall n\geq d : c_0a_n+c_1a_{n-1}+\cdots+a_{n-k}c_k=0$$

このような線形漸化的な数列 $(a_i)_{i=0,1,\dots}$ に対して

- $a$ の先頭 $d$ 項
- $c_0,c_1,\dots,c_d$

が与えられたとき, $a$ を一意に決定することができます. このライブラリでは, そのような $(a_i)$ に対する $a_N$ の値を, $O(d\log d\log N)$ timeで求めます.

## BostanMori

``BostanMori(n, P, Q)``

高々 $d$ 次の多項式 $P,Q$ に対して, [Bostan-Mori法](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a) を利用し $\displaystyle[x^N]\frac{P}{Q}$ を返します.

$P,Q$ は`kyopro::FormalPowerSeries`として渡してください.

### 計算量

- $O(d\log d\log N)$
- ただし $\deg P,\deg Q\leq d$

### 制約

- $N\geq 0$

## NthTermOfLinearlyRecurrentSequence

``NthTermOfLinearlyRecurrentSequence(n, ainit, c)``

線形漸化的な数列 $(a_i)_{i=0,1,2,\dots}$ に対し

- 非負整数 $N$(=`n`)
- $a$ の先頭 $d$ 項(=`ainit`)
- $c_0,c_1,\dots,c_d$=(`c`)

が与えられたとき, $a_N$ の値を返します.

`a`, `c` は`std::vector<atcodr::modint>`として渡してください.

### 計算量

- $O(d\log d\log N)$

### 制約

- $N\geq 0$
- $\forall n\geq d:\displaystyle\sum_{i=0}^{k}{c_ia_{n-i}}$