# SegmentTree(セグメント木)
## 概要
$(S,\text{op},e)$がモノイドをなすとする。\
このとき、$S$の列$a=(a_0,a_1,\dots,a_{n-1})$に対して以下の処理を$O(\log n)$で行う。

1. $a_p\leftarrow v$
1. 区間 $[l,r)$ の積を取得

## 使い方
### コンストラクタ
```cpp
segtree<S,op,e> seg(int n)
```
$a$を$e$で埋めて生成します。
```cpp
segtree<S,op,e> seg(std::vector<S> a)
```
そのまま$a$を渡すこともできます。
\
\
template引数には、$S$に加えて$\text{op},e$を以下の形式で渡す必要があります。
```cpp
S op(S x,S y)
S e()
```
\
\
例として、RangeMinQueryには、以下のようにすればよいです。
```cpp
const int inf;  //大きい値

int op(int x,int y){
    return min(x,y);
}
int e(){
    return inf;
}
segtree<int,op,e> seg(n);    //サイズnのsegtree
```

### メソッド
```cpp
void seg.update(int p,S val)
```
$a_p\leftarrow \text{val}$とする。
- 制約:$0\leq p<n$
- 計算量:$O(\log n)$

```cpp
S seg.prod(int l,int r)
```
区間積を求める。ただし、$l=r$の時は$e$を返す。
- 制約:$0\leq l\leq r <n$
- 計算量:$O(\log n)$

```cpp
void seg.apply(int pos,S x)
```
$a_{\text{pos}}\leftarrow \text{op}(a_{\text{pos}},x)$とする
- 制約:$0\leq \text{pos}<n$
- 計算量:$O(\log n)$

```cpp
S seg[int pos]
```
$a_{\text{pos}}$を返す。
- 制約:$0\leq \text{pos} <n$
- 計算量:$O(1)$