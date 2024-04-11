---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
    title: test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/divisor-multiple-transform.md
    document_title: "Divisor\u30FBMultiple Transform"
    links: []
  bundledCode: "#line 2 \"src/math/divisor-multiple-transform.hpp\"\n#include <vector>\n\
    namespace kyopro {\n\nnamespace internal {\nstd::vector<int> enumerate_primes(int\
    \ n) {\n    std::vector<int> primes;\n    {\n        std::vector<bool> f(n + 1);\n\
    \        for (int i = 2; i <= n; ++i) {\n            if (f[i]) continue;\n\n \
    \           primes.emplace_back(i);\n            for (int j = 2 * i; j <= n; j\
    \ += i) f[j] = 1;\n        }\n    }\n    return primes;\n}\n};  // namespace internal\n\
    \nnamespace multiple {\ntemplate <typename T> void zeta(std::vector<T>& f) {\n\
    \    std::vector primes = internal::enumerate_primes(f.size());\n    for (auto\
    \ p : primes) {\n        for (int i = ((int)f.size() - 1) / p; i >= 1; --i) {\n\
    \            f[i] += f[p * i];\n        }\n    }\n    return;\n}\n\ntemplate <typename\
    \ T> void mobius(std::vector<T>& f) {\n    std::vector primes = internal::enumerate_primes(f.size());\n\
    \n    for (auto p : primes) {\n        for (int i = 1 / p; p * i < (int)f.size();\
    \ ++i) {\n            f[i] -= f[p * i];\n        }\n    }\n    return;\n}\n};\
    \  // namespace multiple\n\nnamespace divisor {\ntemplate <typename T> void zeta(std::vector<T>&\
    \ f) {\n    std::vector primes = internal::enumerate_primes(f.size());\n\n   \
    \ for (auto p : primes) {\n        for (int i = 1; i * p < (int)f.size(); ++i)\
    \ {\n            f[i * p] += f[i];\n        }\n    }\n};\ntemplate <typename T>\
    \ void mobius(std::vector<T>& f) {\n    std::vector primes = internal::enumerate_primes(f.size());\n\
    \    for (auto p : primes) {\n        for (int i = (int)(f.size() - 1) / p * p;\
    \ i >= 1; i -= p) {\n            f[i] -= f[i / p];\n        }\n    }\n};\n}; \
    \ // namespace divisor\n\n};  // namespace kyopro\n\n/**\n * @brief Divisor\u30FB\
    Multiple Transform\n * @docs docs/math/divisor-multiple-transform.md\n */\n"
  code: "#pragma once\n#include <vector>\nnamespace kyopro {\n\nnamespace internal\
    \ {\nstd::vector<int> enumerate_primes(int n) {\n    std::vector<int> primes;\n\
    \    {\n        std::vector<bool> f(n + 1);\n        for (int i = 2; i <= n; ++i)\
    \ {\n            if (f[i]) continue;\n\n            primes.emplace_back(i);\n\
    \            for (int j = 2 * i; j <= n; j += i) f[j] = 1;\n        }\n    }\n\
    \    return primes;\n}\n};  // namespace internal\n\nnamespace multiple {\ntemplate\
    \ <typename T> void zeta(std::vector<T>& f) {\n    std::vector primes = internal::enumerate_primes(f.size());\n\
    \    for (auto p : primes) {\n        for (int i = ((int)f.size() - 1) / p; i\
    \ >= 1; --i) {\n            f[i] += f[p * i];\n        }\n    }\n    return;\n\
    }\n\ntemplate <typename T> void mobius(std::vector<T>& f) {\n    std::vector primes\
    \ = internal::enumerate_primes(f.size());\n\n    for (auto p : primes) {\n   \
    \     for (int i = 1 / p; p * i < (int)f.size(); ++i) {\n            f[i] -= f[p\
    \ * i];\n        }\n    }\n    return;\n}\n};  // namespace multiple\n\nnamespace\
    \ divisor {\ntemplate <typename T> void zeta(std::vector<T>& f) {\n    std::vector\
    \ primes = internal::enumerate_primes(f.size());\n\n    for (auto p : primes)\
    \ {\n        for (int i = 1; i * p < (int)f.size(); ++i) {\n            f[i *\
    \ p] += f[i];\n        }\n    }\n};\ntemplate <typename T> void mobius(std::vector<T>&\
    \ f) {\n    std::vector primes = internal::enumerate_primes(f.size());\n    for\
    \ (auto p : primes) {\n        for (int i = (int)(f.size() - 1) / p * p; i >=\
    \ 1; i -= p) {\n            f[i] -= f[i / p];\n        }\n    }\n};\n};  // namespace\
    \ divisor\n\n};  // namespace kyopro\n\n/**\n * @brief Divisor\u30FBMultiple Transform\n\
    \ * @docs docs/math/divisor-multiple-transform.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor-multiple-transform.hpp
  requiredBy: []
  timestamp: '2024-04-12 00:02:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/convolution/Gcd_Convolution.test.cpp
documentation_of: src/math/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/src/math/divisor-multiple-transform.hpp
- /library/src/math/divisor-multiple-transform.hpp.html
title: "Divisor\u30FBMultiple Transform"
---
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