## 概要
$X,Y,P$に対して、$X^n\equiv Y (\text{mod} P)$なる最小の**非負整数**$n$を求めます。ただし、存在しない場合は$-1$をreturnします。

## 使い方
```cpp
long long dlp(long long x,long long y,long long p)
```
$x^n\equiv y(\text{mod} p)$なる最小の非負整数$n$を返します。存在しなければ$-1$を返します。
## 制約
- $0\leq x,y <p$
- $x,y\in\mathbb{Z}$
- $M\in\mathbb{N}$
- $0^0=1$と定めている
