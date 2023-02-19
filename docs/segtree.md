# segtree
セグメント木です。
モノイド $(S,\cdot,e)$ の列 $a=(a_1,a_2,\dots,a_n)$ について、以下を $O(\log n)$ で処理します。

- $x \in S$ と $1\leq p\leq n$ なる整数 $p$ に対して、 $a_p\leftarrow x$ とする
- $1\leq l\leq r\leq n$ なる整数 $l,r$ が与えられたとき、
$$\prod_{i=l}^{r-1}{a_i}$$
を計算する。ただし、 $l=r$ のときは $e$ を返す。

## コンストラクタ
### サイズを渡す
```cpp
segtree<S,op,e> seg(int n)
```
サイズ $n$ のセグメント木を $a$ を $e$ で埋めて生成します。なお、 $op$ は $S$ の二項演算.すなわち、上での「 $\cdot$ 」です。
です。これらは、それぞれ
- $op:S^2\to S$
- $e:()\to S$

の関数で渡す必要があります。例えば、 $op=+$ としたいときは
```cpp
using S = int;
S op(S x,S y){return x+y;}
S e(){return 0;}
```
のようにして、定義するとよいです。

### $a$を渡す
```cpp
segtree<S,op,e> seg(vector<S> a)
```

すでに $a$ の初期値が分かっている際は、そのまま $a$ を渡すことで構築することもできます。


### 計算量
- いずれも $O(n)$
## update
```cpp
void seg.update(int pos,S val)
```
$a_\text{val}\leftarrow \text{val}$ とします。
### 計算量
- $O(\log n)$


## prod
```cpp
S seg.prod(int l,int r)
```
$$\prod_{i=l}^{r-1}{a_i}$$

を計算します。 ただし、 $l=r$ の時は $e$ を返します。 $l>r$ の場合はエラーとなります。


### 計算量
- $O(\log n)$

## add
```cpp
void seg.add(int pos,S val)
```

$a_{\text{pos}}\leftarrow a_{\text{pos}}\cdot\text{val}$ とします。

### 計算量
- $O(\log n)$

## operator[]
```cpp
S seg[int pos]
```

$a_{\text{pos}}$ を返します。
### 計算量
- $O(1)$


## 初期化のための...
あんまり使わないけど...
```cpp
void seg.set(int p,S val)
void seg.build()
```
というのがあります。これらはコンストラクタの
```cpp
segtree<S,op,e> seg(vector<S> a)
```

の、`a`を生成しなくてよいバージョンとほぼ同等です。つまり、以下のような初期化を
```cpp
vector<S> a(n);
for(int i=0;i<n;i++){
  cin>>a[i];
}

segtree<S,op,e> seg(a);
```
以下のような初期化に!!!
```cpp
segtree<S,op,e> seg(n);
for(int i=0;i<n;i++){
  S ai;
  cin>>ai;
  seg.set(i,ai);
}

seg.build();
```

`set`を呼び出した後、すぐに`build`を呼び出す必要があることを忘れないでください。
### 計算量
- `set`: $O(1)$
- `build` : $O(n)$ 
