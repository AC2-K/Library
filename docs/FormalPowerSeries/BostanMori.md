# BostanMori法(線形漸化式の高速計算)

## 概要

数列 $(a_i)_{i=0,1,2,\dots}^{}$ に対し, 以下の条件を満たす定数 $c_0,c_1,c_2,\cdots,c_d$ が存在するとき, $(a_i)_{i=0,1,2,\dots}$ は**線形漸化的**であるという.

$$\forall n\geq d : c_0a_n+c_1a_{n-1}+\cdots+a_{n-k}c_k=0$$

このような線形漸化的な数列 $(a_i)_{i=0,1,\dots}$ 

- $a$ の先頭 $d$ 項
- $c_0,c_1,\dots,c_d$

が与えられたとき, $a$ は一意に定まります. このライブラリではそのような $(a_i)$ に対する, $a_N$ の値を $O(d\log d\log N)$ timeで求めます.

## BostanMori

` BostanMori(n, P, Q)`

$\displaystyle[x^N]\frac{P}{Q}$ を返します.

$n$は任意の整数型, $P,Q$は形式的べき級数(本ライブラリの`kyopro::FormalPowerSeries<atcoder::modint>`)として渡してください. 係数を `mint` で返します.

### 計算量

- $O(d\log d\log N)$
- ただし $\deg P,\deg Q\leq d$

### 制約

- $N\geq 0$

## linear_reccurence_sequence

`linear_reccurence_sequence(n, a, c)`

線形漸化的な数列 $(a_i)_{i=0,1,2,\dots}$ に対し

- 非負整数 $N$(=`n`)
- $a$ の先頭 $d$ 項(=`a`)
- $c_0,c_1,\dots,c_d$=(`c`)

が与えられたとき, $a_N$ の値返します.

$n$ は任意の整数型, $a,c$ は`std::vector<atcodr::modint>`として渡してください.

### 計算量

- $O(d\log d\log N)$

### 制約

- $N\geq 0$
- $\forall n\geq d:\displaystyle\sum_{i=0}^{k}{c_ia_{n-i}}$