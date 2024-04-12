# 概要

整除関係における高速ゼータ変換, 高速メビウス変換を実装したものです.
\
`multiple::`で定義されている $\zeta,\mu$ と `divisor::`で定義されている $\zeta,\mu$ が異なることに注意してください.

# `namespace::multiple`
倍数変換がまとめてあります

## zeta

```cpp
void zeta(vector<T>& f)
```

$f$ が与えられたとき, $f$ を以下で定義される $\zeta f$ に置き換えます. 

$$(\zeta f)(x)=\sum_{x \vert y}{f(y)}$$

### 計算量

- $O(n\log\log n)$

## mobius

```cpp
void mobius(vector<T>& F)
```

$f$ が与えられたとき, $f$ を以下で定義される $\mu f$ に置き換えます. (一意に定まることが保証される)

$$\zeta (\mu f)=f$$

### 計算量

- $O(n\log\log n)$

# `namespace::divisor`
約数変換がまとめてあります

## zeta

```cpp
void zeta(vector<T>& f)
```

$f$ が与えられたとき, $f$ を以下で定義される $\zeta f$ に置き換えます. 

$$(\zeta f)(x)=\sum_{y \vert x}{f(y)}$$

```multiple::zeta``` と $x,y$ の整除関係が逆になっています.

## 計算量

- $O(n\log\log n)$

## mobius

```cpp
void mobius(vector<T>& F)
```

$f$ が与えられたとき, $f$ を以下で定義される $\mu f$ に置き換えます. (一意に定まることが保証される)

$$\zeta (\mu f)=f$$

### 計算量

- $O(n\log\log n)$


# GCD・LCM Convolution

GCD, LCM Convolutionについて備忘録としてまとめておきます.
"GCD,LCM Convolutionとは" については以下参照.

- https://judge.yosupo.jp/problem/gcd_convolution
- https://judge.yosupo.jp/problem/lcm_convolution

これらのGCD・LCM Convolutionは上のライブラリを用いれば $O(N\log \log N)$ で求めることができます.

まずはGCD Convolutionについて.
$a,b,c$ に(`multiple::`の)ゼータ変換を施したものをそれぞれ $\hat{a},\hat{b},\hat{c}$とします. すなわち, 以下で $\hat{a},\hat{b}, \hat{c}$ を定めます.

$$\hat{a}(x)=\sum_{x \vert y}{a(y)}$$

$$\hat{b}(x)=\sum_{x \vert y}{b(y)}$$

$$\hat{c}(x)=\sum_{x \vert y}{c(y)}$$

この時, $\hat{a}(i)\hat{b}(i)$ について以下が成り立ちます.

$$
\begin{aligned}
\hat{a}(i)\hat{b}(i)&=\left(\sum_{i\vert j}{a(j)}\right)\left(\sum_{i\vert k}{b(k)}\right)\\
&=\sum_{i\vert j\land i\vert k}{a(j)b(k)}\\
&=\sum_{i\vert \gcd(j,k)}{a(j)b(k)} 
\end{aligned}
$$

よって $\hat{a},\hat{b}$ の各点積をとると $c$ のゼータ変換 $\hat{c}$ に一致することが分かります. こうして $\hat{c}$ が得られ, 得られた $\hat{c}$に対してゼータ変換の逆変換であるメビウス変換を施せば $c$ 本体を復元することができ, これにより求めていた $c$ が得られました.

以上の結果を簡潔にまとめれば, 要は`multiple::`で定義した $\zeta,\mu$ について以下が成り立つということです($\ast$ は各点積をとる演算).

$$ c=\mu((\zeta a) \ast (\zeta b))$$

$c$ を $a,b$ のLCM Convolution, $\zeta,\mu$ を`divisor::`で定義したものに取り換えてもこの式は成り立ちます(証明は上と同様にすればよい).
\
これを利用すれば $a,b$ のLCM Convolutionを求めることもできます.
