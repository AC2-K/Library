# 概要

整除関係における高速ゼータ変換, 高速メビウス変換を実装したものです.
\
`multiple::`で定義されている$\zeta,\mu$ と `divisor::`で定義されている$\zeta,\mu$が異なることに気を付けてください.


# `namespace::multiple`
倍数変換がまとめてあります

## zeta

```cpp
void zeta(vector<T>& f)
```

$f$ が与えられたとき, $f$ を以下で定義される $\zeta f(x)$ に置き換えます. 

$$(\zeta f)(x)=\sum_{x \mid y}{f(y)}$$

### 計算量

- $O(n\log\log n)$

## mobius

```cpp
void mobius(vector<T>& F)
```

$f$ が与えられたとき, $f$ を以下で定義される $\mu f(x)$ に置き換えます. 

$$\zeta (\mu f)=f$$
### 計算量

- $O(n\log\log n)$


# `namespace::divisor`
約数変換がまとめてあります

## zeta

```cpp
void zeta(vector<T>& f)
```

$f$ が与えられたとき, $f$ を以下で定義される $\zeta f(x)$ に置き換えます. 

$$(\zeta f)(x)=\sum_{y \mid x}{f(y)}$$

```multiple::zeta``` と $x,y$ の整除関係が逆になっていることに気を付けてください.

## 計算量

- $O(n\log\log n)$

## mobius

```cpp
void mobius(vector<T>& F)
```

$f$ が与えられたとき, $f$ を以下で定義される $\mu f(x)$ に置き換えます. 

$$\zeta (\mu f)=f$$

### 計算量

- $O(n\log\log n)$