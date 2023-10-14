## 概要

木をダブリングを用いて管理することで

- Level Ancestor
- Lowest Common Ancestor

を高速に求めます.

## コンストラクタ

```cpp
doubling T(int n)
```

$n$ 頂点の木 $T$ を生成します.この時点ではまだ辺は貼られていません.

### 制約

- 木 $T$ の**高さは** $2^{21} = 2097152 \geq 2\times 10^6$ を超えない.

### 計算量

- $O(n\log n)$

## add_edge

```cpp
void add_edge(int a, int b, int c)
```

頂点 $a,b$ に重み $c$ の無向辺を張ります.デフォルトでは $c = 1$ です.

### 制約

- $0\leq a,b < n$

### 計算量

- $O(1)$

## build

```cpp
void build(int root)
```

$T$ の根を頂点 $\mathtt{root}$ として前処理を行います.\
デフォルトでは $\mathtt{root}=0$ です.

### 制約

- $0\leq \mathtt{root} < n$

### 計算量

- $O(n\log n)$

## level_ancestor

```cpp
int level_ancestor(int v, int k)
```

頂点 $v$ から根の方向に $k$ 辿った頂点を返します.\
すなわち, 頂点 $v$ から根へのパスを

$$p = (p_0=v , p_1 , p_2 \dots p_{\vert p\vert -1} = \mathtt{root})$$

とするとき, $p_k$  を返します.条件を満たす頂点が存在しなければ $-1$ をreturnします.
### 制約

- $0\leq v < n$

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

頂点 $u$ の深さを返します. ただし, ここでの「深さ」は**重み無し**です.

## unweighted_dist

```cpp
long long unweighted_dist(int u,int v)
```

頂点 $u,v$ の距離を返します. ここでの「距離」は**重み無し**です.

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## dist

```cpp
long long dist(int v)
```

頂点 $u$ の深さを返します.ただし,ここでの「深さ」は**重み付き**です.

```cpp
long long dist(int u,int v)
```

頂点 $u,v$ の距離を返します.ここでの「距離」は**重み付き**です.

### 制約

- $0\leq u,v < n$

### 計算量

- $O(\log n)$

## jump

```cpp
int jump(int from,int to,int k)
```

$\mathtt{from}$ から $\mathtt{to}$ に $k$ 進んだ頂点を返します.\
すなわち, $\mathtt{from}\to\mathtt{to}$の最短パスを

$$p=(p_0=\mathtt{from},p_1,p_2,\dots,p_{\vert p\vert-1}=\mathtt{to})$$

としたとき, $p_k$ を返します.ただし, $k\geq\vert p\vert$ ならば $-1$ を返します.

### 制約

- $0\leq\mathtt{from},\mathtt{to} < n$

### 計算量

- $O(\log k)$
