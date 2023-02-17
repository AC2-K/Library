# DSU
素集合データ構造です。$n$頂点の無向グラフに対して
- 辺の追加
- $2$つの頂点について、連結かの判定

を $O(\alpha(n))$ で処理してくれる。
## コンストラクタ
```cpp
DSU dsu(int n)
```
$n$ 頂点 $0$ 辺のグラフを生成します。
### 計算量
- $O(n)$
## root
```cpp
int dsu.root(int x)
```
頂点 $x$ の属する連結成分の代表元を返します。
- $O(\alpha(n))$
## same
```cpp
bool dsu.same(int x,int y)
```
頂点 $x$ と頂点 $y$ が連結か返します
### 計算量
- $O(\alpha(n))$
## merge
```cpp
bool dsu.merge(int u,int v)
```
頂点 $u$ と頂点 $v$ の間に無向辺を張ります。ただし、元から $u,v$ が連結だったら `false` を返して終了します。
### 計算量
- $O(\alpha(n))$

## size
```cpp
int size(int v)
```
頂点 $v$ の属する連結成分の頂点数を返します
### 計算量
- $O(\alpha(n))$
## groups_size
```cpp
int groups_size()
```
連結成分の個数を求めます。
### 計算量
- $O(n)$

# segtree
セグメント木です。
のモノイド $(S,op,e)$ の列 $a=(a_1,a_2,\dots,a_n)$ について、