## 概要

整除関係における高速ゼータ変換,高速メビウス変換を実装したものです

## fast_zeta

```cpp
void fast_zeta(std::vector<T>& f)
```

長さ $n$ の数列 $f$ に対し、以下を満たす長さ $n$ の数列 $F$を求め、$f$ を $F$ で置き換えます。

$$F[n]=\sum_{\mathbb{d} \mid n}{f[d]}$$

### 計算量

- $O(n\log\log n)$

## fast_mobius

```cpp
void fast_zeta(std::vector<T>& F)
```

上とは逆に、 $F$ が与えられたとき条件を満たす $f$ を求めます。そして、$F$ を $f$ で置き換えます。

### 計算量

- $O(n\log\log n)$
