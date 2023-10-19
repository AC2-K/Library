## 概要

無向木をEulerTourにより扱うことで, 様々なクエリを $O(\log n)$ あるいは $O(1)$ で処理することが出来ます.

## コンストラクタ

```cpp
EulerTour et(int n)
```

頂点数 $n$ で初期化します. この時点ではまだ辺は貼られていません.

### 計算量

- $O(n)$

## add_edge

```cpp
void add_edge(int a, int b)
```

頂点 $a,b$ の間に無向辺を張ります.

### 制約

- $0\leq a,b\lt n$

### 計算量

- $O(1)$

## build

```cpp
void build(int r)
```

根を頂点 $r$ として前処理を行います. $r$ は省略可能で, デフォルトでは $r=0$ です.

### 制約

- $0\leq r\lt n$
- これが呼び出される時点で $T$ の辺は全て張り終えている.

### 計算量

- $O(n\log n)$

## lca

```cpp
int lca(int a,int b)
```

頂点 $a, b$ のLowest Common Ancestor(最深共通祖先)を返します.

### 制約

- $0\leq a,b\lt n$

### 計算量

- $O(1)$

## dist

```cpp
int dist(int a, int b)
```

頂点 $a,b$ の距離を返します.

### 制約

- $0\leq a,b\lt n$

### 計算量

- $O(1)$

## idx

```cpp
pair<int, int> idx(int v)
```

EulerTour順に辿ったときの

- 最初に $v$ を訪れる時刻
- $v$ の部分木を抜ける時の時刻

をそれぞれ`first`, `second`に詰めて返します.

### 制約

- $0\leq v\lt n$

### 計算量

- $O(1)$

## is_in_subtree

```cpp
bool is_in_subtree(int a, int b)
```

$b$ が $a$ の部分木に含まれるか判定します. $a=b$ の場合は`true`です.

### 制約

- $0\leq a,b\lt n$

### 計算量

- $O(1)$
