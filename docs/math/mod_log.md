## 概要
$x,y,p$ に対して,

$$x^n \equiv y \mod p$$ 

となる最小の**非負整数**$n$を求めます.

## 使い方
```cpp
long long mod_log(long long x,long long y,long long p)
```
上のやつを解きます.条件を満たす $n$ が存在しない場合は $-1$ をreturnします.

### 計算量
- $O(\sqrt p)$

### 制約
- $0\leq x,y < p$
- $x,y\in\mathbb{Z}$
- $p\in\mathbb{N}$
- $0^0=1$ と定めている
