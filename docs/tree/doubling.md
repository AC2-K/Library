## 概要

木をダブリングを用いて管理することで

- Level Ancestor
- Lowest Common Ancestor

を高速に求めます.

## コンストラクタ

```cpp
doubling T(int n)
```

頂点数 $n$ で初期化します. この時点ではまだ辺は貼られていません.

### 制約

- 木 $T$ の**高さは** $2^{21} = 2097152 \gt 2\times 10^6$ を超えない.

### 計算量

- $O(n\log n)$

## add_edge

```cpp
void add_edge(int a, int b, int c)
```

頂点 $a,b$ の間に重み $c$ の無向辺を張ります. $c$ は省略可能で, デフォルトでは $c = 1$ です.

### 制約

- $0\leq a,b < n$

### 計算量

- $O(1)$

## build

```cpp
void build(int r)
```

$T$ の根を頂点 $r$ として前処理を行います. $r$ は省略可能で, デフォルトでは $r=0$ です.

### 制約

- $0\leq r < n$
- これが呼び出される時点で $T$ の辺は全て張り終えている.

### 計算量

- $O(n\log n)$

## level_ancestor

```cpp
int level_ancestor(int v, int k)
```

頂点 $v$ から根の方向に $k$ 辿った頂点を返します. すなわち, 頂点 $v$ から根へのパスを

$$p = (p_0=v , p_1 , p_2 \dots p_{\vert p\vert -1} = r)$$

とするときの $p_k$  を返します. 条件を満たす頂点が存在しなければ $-1$ をreturnします.
### 制約

- $0\leq v\lt n$

### 計算量

- $O(\log k)$

## lca

```cpp
int lca(int u, int v)
```

頂点 $u,v$ のLowest Common Ancestor(最深共通祖先)を返します

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## depth

```cpp
int depth(int v)
```

頂点 $u$ の深さを返します. ここでの「深さ」は**重み無し**であることに注意してください.

## unweighted_dist

```cpp
int unweighted_dist(int u, int v)
```

頂点 $u,v$ の距離を返します. ここでの「距離」は**重み無し**です.

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## dist

```cpp
long long dist(int u, int v)
```

頂点 $u,v$ の距離を返します.ここでの「距離」は**重み付き**です.
$v$ は省略可能で, デフォルトでは $v$ は$r$(=根)となります.

### 制約

- $0\leq u,v\lt n$

### 計算量

- $O(\log n)$

## jump

```cpp
int jump(int from, int to, int k)
```

$\mathtt{from}$ から $\mathtt{to}$ に $k$ 進んだ頂点を返します. すなわち, $\mathtt{from}\to\mathtt{to}$の最短パスを

$$p=(p_0=\mathtt{from},p_1,p_2,\dots,p_{\vert p\vert-1}=\mathtt{to})$$

としたときの $p_k$ を返します. ただし, そのような $p_k$ が存在しなければ $-1$ をreturnします.

### 制約

- $0\leq\mathtt{from},\mathtt{to}\lt n$

### 計算量

- $O(\log k)$
