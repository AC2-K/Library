# BabyStepGiantStep(BSGS)

集合 $S$ ,写像 $f:S\to S$ , $s,g\in S$ に対して、以下を満たす最小の非負整数 $t$ を求めます。
$$f^t(s)=g$$

ただし、以下の条件を満たす必要があります。 $f^i$ みたいなのは、 $f$ の$i$ 回合成です。
- ある $n\in\mathbb{N}$ が存在して、任意の $x\in S$ に対して $f^n(x)=x$ が成り立つ。
- 逆写像 $f^{-1}$ が存在する
- ある $m\in\mathbb{N}$が存在して $f^m$ が高速に求まる。

このとき、 $n,m,f^m$ が実際に求まれば、上記の $t$ が $O((m+\frac{n}{m})\log m)$ で求まる。\
$m=\text{ceil}(\sqrt n)$ だと計算量 $(\sqrt n\log n)$で求まる!!!