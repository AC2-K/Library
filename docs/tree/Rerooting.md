# 1. 概要

このライブラリは全方位木DP(Rerooting DP)を用いて問題を解くことをサポートします.

以下の問題を考えます.

> $N$ 頂点の木 $T=(V, E)$ が与えられます.\
> **可換**モノイド $(M,\text{op},\text{id})$ があり, 各頂点 $v\in V$ に対して値 $a_v\in M$ が定まっているとします. \
> また,
> 
> - 写像 $f:M \times V \to M;(x,v)\to f_v(x)$ 
> - 写像 $g:M \times E \to M;(x,e)\to g_e(x)$
> 
> が定まっているとします.
>  
> 各 $r\in V$ に対して, 以下を行ってください.
> 
> - $q(v)\in M$ を以下のようにして定める.
>   - $v$ が根でない場合 $C_{r}(v)$ を $v$ から子方向へと伸びている辺の集合として\
>       $\displaystyle q(v)=a_v+f_v\left(\sum_{e=(v,u)\in C(v)}{g_e(q(u))}\right)$\
>       とする.
>   - $v$ が根の場合, 上と同様にして $C(v)$ を定め\
>       $\displaystyle q(v)=f_v\left(\sum_{e=(v,u)\in C(v)}{g_e(q(u))}\right)$\
>       とする
> 
> - $T$ を $r$ を根とする根付き木と見なし $q(r)$ の値を求める.

素直な木DPを毎回行うと計算量は $O(N^2)$ となってしまいます. しかし, 全方位木DPを用いれば計算量 $O(N)$ でこれを達成できます.

なお, 以下 $E,V$ を頂点番号や辺番号と同一視することにします.

# 2. 使用方法

## コンストラクタ

```cpp
template<typename M, 
         typename OP,
         typename PUT_E,
         typename PUT_V, 
         typename LEAF>
Rerooting(int n, 
          const V& identity, 
          const OP& op,
          const PUT_V& put_vertex,
          const PUT_E& put_edge,
          const LEAF&LEAF
          )
```

型:
- `M` : $M$ を表す型
- `OP`, `PUT_V`, `PUT_E`, `LEAF` : それぞれ後述する`op`, `put_vertex`, `put_edge`, `leaf`の型

変数:
- `n` : $T$ の頂点数
- `identity` : $M$ の単位元
- `op` : $M$ の二項演算
- `put_vertex` : $(x,v)\in M\times V$ を引数に取り, $f_v(x)$ を返す関数
- `put_edge` : $(x,e)\in M\times E$ を引数に取り, $g_{e}(x)$ を返す関数
- `leaf` : $v\in V$ を引数に取り $a_v$ の値を返す関数

なお, 本ライブラリではこれらの呼び出しは $O(1)$ で行えるものとして計算量を表記しています.

実用例をいくつか提示しておきます.

- [ABC222 - F](https://atcoder.jp/contests/abc222/submissions/57491947)
- [LibraryChecker - Tree Path Composite Sum](https://judge.yosupo.jp/submission/232590)

### 制約

- すべての引数が条件を満たしている

## add_edge

```cpp
void add_edge(int u, int v, int e)
```
$u,v$ の頂点間に辺 $e$ を張ります.

### 制約
- $0\leq u,v\lt N$
- $u\neq v$
- $0\leq e\lt N-1$
- 呼び出しごとに $e$ の値は異なる
- これが呼び出されるとき, $u,v$ は連結でない
- `add_edge`は全体で合計 $N-1$ 回呼び出される

## run

```cpp
std::vector<M> run()
```
上記の問題における $q(r)$ の計算結果の列をvectorにして返します.

### 制約

- 呼び出し時, `add_edge` が合計 $N-1$ 回呼び出された.
- このメソッドの呼び出し以降に`add_edge`が呼び出されることはない.

### 計算量 
- $O(N)$