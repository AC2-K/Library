## 概要

$x,y,p$ に対して,

$$x^n \equiv y (\bmod p)$$

となる最小の**非負整数**$n$を求めます.

## 使い方

```cpp
T mod_log(T x, T y, T p)
```

上のやつを解きます. 条件を満たす $n$ が存在しない場合は $-1$ をreturnします.

### 計算量

- $O(\sqrt p)$

### 制約

- $0\leq x,y \lt p$
- $x,y,p\in\mathbb{Z}$
- $0^0=1$
