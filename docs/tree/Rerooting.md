# 1. 概要
このライブラリは全方位木DP(Rerooting DP)を用いて問題を解くことをサポートします.

以下の問題を考えます([Tree Path Composite Sum](https://judge.yosupo.jp/problem/tree_path_composite_sum)を一般化した問題になっています)

> $n$ 頂点の木 $T=(V, E)$ が与えられます.\
> 可換モノイド $M$ があり, 各頂点 $v\in M$ 対して値 $a_v\in M$ が定まっています.\
> また, $V\times E$ から $M$ への  作用 $f:M\times V\times E \to M;(x,v,e)\to f_{e,v}(x)$ が定義されています.\
> $P:(x,y)\in V\times V\to S$ を以下のようにして定めます.
> 
> - $T$ における $x\to y$ の単純パスを $(v_0,e_0,v_1,\dots,e_k,v_{k+1})$ として $P(x,y)=f_{v_0,e_0}(f_{v_1,e_1}(\dots f_{v_k,e_k}(a_y)\dots))$
>
> すべての $x\in V$ に対して $q_x=\displaystyle\prod_{y\neq x}{P(x,y)}$ の値を計算してください.

このライブラリでは $O(N)$ -timeでこれを解きます.

# 2. 使用方法
## コンストラクタ
```cpp
template<typename M, typename OP, typename PUT_EV, typename LEAF>
Rerooting(int n, 
          const V& identity, 
          const OP& op,
          const PUT_EV& put_edge_vertex,
          const LEAF&LEAF
          )
```

- `M` : $M$ を表す型
- `OP`, `PUT_EV`, `LEAF` : それぞれ後述する`op`, `put_edge_vertex`, `leaf`の型

- `n` : $T$ の頂点数
- `identity` : $M$ の単位元
- `op` : $M$ の二項演算.
- `put_edge_vertex` : $x\in M,e\in E,v\in V$を引数に取り, $f_{e,v}(x)$ を返す関数
- `leaf` : $v\in V$ を引数に取り $a_v$ の値を返す関数


<details><summary>Tree Path Composite Sumでの実装例</summary>

```cpp
// https://judge.yosupo.jp/submission/229005

using mint = modint<998244353>;

int main() {
    ...
    using M = pair<mint, mint>
    auto op = [&](M x, M y) {
        return M(x.first + y.first, x.second + y.second);
    };
    auto put_edge_vertex = [&](M x, int e, int) {
        return M(b[e] * x.first + c[e] * x.second, x.second);
    };
    auto leaf = [&](int v) { return M(a[v], mint(1)); };

    Rerooting<M, decltype(op), decltype(put_edge_vertex), decltype(leaf)> 
        t(n, M(), op, put_edge_vertex, leaf);

    ...
}
```

</details>

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
上記の問題における $q_x$ の計算結果をvectorにして返します.

### 制約
- このメソッドの呼び出し以降に`add_edge`が呼び出されることはない.