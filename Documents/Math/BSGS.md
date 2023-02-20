# BabyStepGiantStep(BSGS)

集合 $S$ ,写像 $f:S\to S$ , $s,g\in S$ に対して、以下を満たす最小の非負整数 $t$ を求めます。(存在しないときは、そのことを検知する)
$$f^t(s)=g$$

ただし、以下の条件を満たす必要があります。 $f^i$ みたいなのは、 $f$ の $i$ 回合成です。
- ある $p\in\mathbb{N}$ が存在して、任意の $x\in S$ に対して $f^p(x)=x$ が成り立つことが分かっている。
- $p\leq n$ を満たす $n\in\mathbb{N}$ が具体的にわかる。
- 逆写像 $f^{-1}$ が存在する
- ある $m\in\mathbb{N}$が存在して $f^m$ が求まっている。

このとき、 $n,m,f^m$ が実際に求まれば、上記の $t$ が $O((m+\frac{n}{m})\log (m+\frac{n}{m}))$ で求まる。\
$m=\text{ceil}(\sqrt n)$ だと計算量 $(\sqrt n\log n)$で求まる!!!
## 使い方
```cpp
template<class S>
void bsgs(S s,S g,ll n,ll m,function<S(S)> f,function<S(S)> fm)
```
$s,g,n,m,f$ は上の通り。 $fm$ は $f^m$ \
$f,fm$ はラムダ式とかで渡す。