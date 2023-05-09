## 概要
EulerTourを扱います。\
EulerTourを使うことで、木に関する様々なクエリを $O(\log n),O(1)$ で処理することが出来ます。\
代表的なものだと
- Lowest Common Ancestor
- 木上の $2$ 頂点間の距離

はクエリごと $O(1)$ で処理できます。これらはメソッドに用意しています。\
また、BITやSegmentTreeと併用することで以下の問題がクエリごと $O(\log n)$ で処理できます。
- [Vertex Add Path Sum](https://judge.yosupo.jp/problem/vertex_add_path_sum)
- [Vertex Add Subtree Sum](https://judge.yosupo.jp/problem/vertex_add_subtree_sum)

## コンストラクタ
```cpp
kyopro::EulerTour tour(int n)
```

$n$頂点のグラフを生成します。この時点では辺は張られていません。

### 計算量
- $O(n)$

## add_edge
```cpp
void add_edge(int a,int b)
```
$a,b$ の間に無向辺を張ります。
### 制約
- $0\leq a,b<n$

### 計算量
- $O(1)$

## build
```cpp
void build(int r)
```
頂点 $r$ を根として前処理を行います。デフォルトでは頂点 $0$ が根です。
### 制約
- $0\leq r<n$
- **これが呼び出される時点で $T$ は木** 

### 計算量
- $O(n\log n)$

## lca
```cpp
int lca(int a,int b)
```
頂点 $a,b$ のLowest Common Ancestor(最小共通祖先)を返します。

### 制約
- $0\leq a,b<n$

### 計算量
- $O(1)$

## dist
```cpp
int dist(int a,int b)
```
頂点 $a,b$ の距離(最短経路長)を返します。

### 制約
- $0\leq a,b<n$

### 計算量
- $O(1)$

## idx
```cpp
std::pair<int,int> idx(int v)
```
EulerTour順に辿ったときの
- 最初に$v$ を訪れる時刻
- $v$ の部分木を抜ける時の時刻

をそれぞれfirst,secondに詰めて返します。

### 制約
- $0\leq v<n$

### 計算量
- $O(1)$

## is_in_subtree
```cpp
bool is_in_subtree(int a,int b)
```
$b$ が $a$ の部分木に含まれるか判定します。\
$a=b$ の場合は`true`です。

### 制約
- $0\leq a,b<n$

### 計算量
- $O(1)$

