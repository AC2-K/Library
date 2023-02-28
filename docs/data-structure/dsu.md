## 概要
$n$頂点の無向グラフに対して、以下のクエリを$O(\alpha(n))$で処理します。
1. 頂点$v,u$の間に無向辺を追加する
1. 頂点$v,u$が連結か判定する。

$\alpha$ はアッカーマン関数の逆関数です。
## 使い方
```cpp
DSU dsu(int n)
```
$n$頂点$0$辺の無向グラフを生成します。計算量は$O(n)$

```cpp
int root(int x)
```
頂点$x$の属する連結成分の代表元を返します。計算量は$O(\alpha(n))$

```cpp
bool same(int x,int y)
```
頂点$x,y$が連結かを判定します。計算量は$O(\alpha(n))$
```cpp
bool merge(int x,int y)
```
頂点$x,y$の間に無向辺を張ります。ただし、すでに無向辺が張られていた場合は`false`を返して終了します。計算量は$O(\alpha(n))$\

```cpp
int size(int x)
```
頂点$x$の属する連結成分の頂点数を求めます。計算量は$O(\alpha(n))$

```cpp
int group_size()
```
連結成分の個数を求めます。計算量は$O(\alpha(n))$