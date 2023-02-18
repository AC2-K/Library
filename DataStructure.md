# DSU
素集合データ構造です。$n$ 頂点の無向グラフに対して
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
モノイド $(S,\cdot,1_{S})$ の列 $a=(a_1,a_2,\dots,a_n)$ について、以下の操作を $O(\log n)$ で行います
- $x\in S$ と $0\leq i<n$ なる $i\in\mathbb{Z}$ に対して  $a_i\leftarrow a_i\cdot x$ とする。

- $0\leq l<r<n$ なる整数 $l,r$ に対して、 $a_l \cdot a_{l+1} \dots,a_{r-1}\cdot a_{r-1}$を計算する 

### コンストラクタ
### サイズを渡す
```cpp
segtree<S,op,e> seg(int n)
```
サイズ $n$ のセグメント木を $a$ を $e$ で埋めて生成します。なお、
- $op$ は $S$ の二項演算
- $e$は上での $1_{S}$

です。これらは、それぞれ
- $op:S\to S$
- $e:()\to S$

の関数で渡す必要があることに気を付けてください。例えば、 $op=+$ としたいときは
```cpp
using S = int;
S op(S x,S y){return x+y;}
S e(){return 0;}
```
のようにして、定義する必要があります。

### $a$を渡す
```cpp
segtree<S,op,e> seg(vector<S> a)
```

すでに$a$の初期値が分かっている際は、そのまま $a$ を渡すことで構築することもできます。


### 計算量
- いずれも $O(n)$
## set,build
**これらはあくまで初期化用です。クエリ処理に使うことは基本的にはできません**
```cpp
seg.set(int pos,S val);
```
`set`とすることで、 $a_{\text{pos}}\leftarrow \text{val}$ とできます。\
これらを終えた後に次の`build`を呼び出す必要があります。

```cpp
seg.build();
```
上のようにしてセットしたセグメント木を構築します。
### 計算量
- `set`: $O(1)$
- `build`: $O(n)$