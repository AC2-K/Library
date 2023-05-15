## 概要
Miller Rabinの素数判定法を実装したものです.


## is_prime
```cpp
bool kyopro::miller::is_prime(T n)
```
クラス`kyopro::miller`の静的メソッドです.与えられた正の整数 $n$ が素数であるか判定します.


### 制約
- $1 \leq n \lt 2^{64}$

### 計算量
- $O(\log n)$