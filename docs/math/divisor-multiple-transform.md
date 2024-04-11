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

$$(\zeta f)(x)=\sum_{x \vert y}{f(y)}$$

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

$$(\zeta f)(x)=\sum_{y \vert x}{f(y)}$$

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


# GCD・LCM Convolution

GCD, LCM Convolutionについて備忘録としてまとめておきます.
"GCD,LCM Convolutionとは"については以下参照.

- https://judge.yosupo.jp/problem/gcd_convolution
- https://judge.yosupo.jp/problem/lcm_convolution

これらのGCD・LCM Convolutionは上のライブラリを用いれば $O(N\log \log N)$ で求めることができます.

GCD-Convolutionで説明しましょう.
$a,b,c$ に(`multiple::`の)ゼータ変換を施したものをそれぞれ $\hat{a},\hat{b},\hat{c}$とします. この時, $\hat{a}_i\hat{b}_i$ について以下が成り立ちます.

$$
\begin{aligned}
\hat{a}_i\hat{b}_i&=\left(\sum_{i\vert j}{a_j}\right)\left(\sum_{i\vert k}{b_k}\right)\\
&=\sum_{i\vert j\land i\vert k}{a_jb_k}\\
&=\sum_{\gcd(j,k)\vert i}{a_jb_k} 

\end{aligned}$$

よって $\hat{a},\hat{b}$ の各点積をとると $c$ のゼータ変換 $\hat{c}$ に一致することが分かります. こうして得られた $\hat{c}$ に対してゼータ変換の逆変換であるメビウス変換を施せば $c$ 本体を復元することができ, これにより求めていた $c$ が得られました.

以上の結果を簡潔にまとめれば, 要は`multiple::`で定義した $\zeta,\mu$ について以下が成り立つということです($\ast$ は各点積をとる演算).

$$ c=\mu((\zeta a) \ast (\zeta b))$$

$c$ を$a,b$のLCM Convolution, $\zeta,\mu$ を`divisor::`で定義したものに取り換えてもこの式は成り立ちます(証明は上と同様にすればよい).\ 
これを利用すればa,bのLCM Convolutionを求めることもできます.