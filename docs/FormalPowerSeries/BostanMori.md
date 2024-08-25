
## 概要

- <https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a>
- <https://hitonanode.github.io/cplib-cpp/formal_power_series/coeff_of_rational_function.hpp.html>

全てこちらを元にしています.

数列 $a_0,a_1,a_2\dots$ に対し, 以下の条件を満たす定数 $c_0,c_1,c_2,\cdots,c_d$ が存在するならば, $(a_i)$ は **線形漸化的** であるといいます.

$$\forall n\geq d : c_0a_n+c_1a_{n-1}+\cdots+a_{n-k}c_k=0$$

線形漸化的な数列 $(a_i)$ に対して

- $a_0,a_1,\dots,a_{d-1}$
- $c_0,c_1,\dots,c_d$

が与えられたとき, このライブラリでは $a_N$ の値を $O(d\log d\log N)$ 時間で求めます.

## BostanMori

```cpp
BostanMori(n, P, Q)
```

高々 $d$ 次の多項式 $P(x),Q(x)$ に対して, [Bostan-Mori法](https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a) を用いて $\displaystyle[x^N]\frac{P(x)}{Q(x)}$ を計算します.

$P,Q$ は[FormalPowerSeries](https://ac2-k.github.io/Library/src/FormalPowerSeries/FPS.hpp)として渡してください.

### 計算量

- $O(d\log d\log N)$
- ただし $\deg P,\deg Q\leq d$

### 制約

- $N\geq 0$

## NthTermOfLinearlyRecurrentSequence

```cpp
NthTermOfLinearlyRecurrentSequence(n, ainit, c)
```

線形漸化的な数列 $(a_i)$ に対して

- 非負整数 $N$(=`n`)
- $a$ の先頭 $d$ 項(=`ainit`)
- $c_0,c_1,\dots,c_d$=(`c`)

が与えられたとき, $a_N$ の値を返します.

`a`, `c` は`std::vector<atcodr::modint>`として渡してください.

### 計算量

- $O(d\log d\log N)$

### 制約

- $N\geq 0$
- $\forall n\geq d:\displaystyle \sum_{i=0}^{k}{c_ia_{n-i}}=0$

## 線形漸化的数列の第 $N$ 項の計算

備忘録として残しておく.

$(a_i)$ と定数 $c_0,c_1,c_2\dots,c_d$ について以下が成り立っているとする.

$$ \forall n\geq d:\sum_{i=0}^{d}{c_ia_{n-i}}=0$$

ここで, 数列 $(a_i)$ の母関数 $\displaystyle A(x)=\sum_{i=0}^{\infty}{a_ix^i}$ を考える. すると $a_{n-i}=[x^{n-i}]A(x)=[x^n]\left(x^iA(x)\right)$ となる. したがって上の式は以下のようになる.

$$
\begin{aligned}
\forall n\geq d&:\sum_{i=0}^{d}{c_ia_{n-i}}&=0\\
\iff \forall n\geq d&:\sum_{i=0}^{d}{c_i[x^n]\left(x^iA(x)\right)}&=0\\
\iff \forall n\geq d&:[x^n]\left(A(x)\sum_{i=0}^{d}{c_ix^i}\right)&=0
\end{aligned}
$$

これはすなわち形式的べき級数 $\displaystyle \left(A(x)\sum_{i=0}^{d}{c_ix^i}\right)$ が $d$ 次未満の多項式として表せるということ. よってこの多項式を $P(x)$ とすると以下が成り立つ.

$$
A(x)\sum_{i=0}^{d}{c_ix^i}=P(x)
$$

よって $\displaystyle Q(x)=\sum_{i=0}^{d}{c_ix^i}$ とすると $A(x)Q(x)=P(x)$ が成り立ち $\displaystyle A(x)=\frac{P(x)}{Q(x)}$ と表すことができた.

$$a_N=[x^N]A(x)=[x^N]\frac{P(x)}{Q(x)}$$

であり $\displaystyle [x^N]\frac{P(x)}{Q(x)}$ について

- $Q(x)$ :\
    与えられる $c_0,c_1,c_2\dots,c_d$ から $O(d)$ 時間で容易に得られる.

- $P(x)$ :\
    $P$ は $d$ 次未満の多項式であるから, $\displaystyle \sum_{i=0}^{d-1}{a_ix^i}$ と $Q(x)$ を畳み込むことにより $O(\mathrm{M}(d))$ 時間で求まる.

- $\displaystyle [x^N]\frac{P(x)}{Q(x)}$ :\
    $P,Q$ からBostan-Mori法 により$O(\mathrm{M}(d)\log N)$ 時間で計算可能.

ただし, $\mathrm{M}(d)$ は $d$ 次未満の多項式を畳み込むのにかかる時間計算量.

以上により, $a_N$ の値を $O(\mathrm{M}(d)\log N)$ 時間で求めることができる.

このライブラリでは畳み込みの計算に`atcoder::convolution`を用いているので $M(d)=O(d\log d)$ である.

### 変形

実装の簡単のため $\displaystyle \sum_{i=0}^{d}{c_ia_{n-i}}=0$ という定義を用いたが, 移項して整理することで, よく用いられる $\displaystyle a_n=\sum_{i=1}^{d}{{c_{d}}{a_{n-d}}}$ という形にも帰着することができる.