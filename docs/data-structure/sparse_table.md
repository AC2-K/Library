## 概要
- 全ての $a\in S$ に対して $a \bullet a=a$
- 全ての$a,b,c\in S$ に対して $(a\bullet b)\bullet c=a\bullet(b\bullet c)$

となるような集合 $S$ と $S$ の二項演算 $\bullet$ があるとします。\
例えば
- $(S,\bullet)=(\mathbb{Z},\max)$
- $(S,\bullet)=(\mathbb{Z},\min)$
- $(S,\bullet)=(\mathbb{Z},\text{gcd})$
- $(S,\bullet)=(\mathbb{Z},\text{lcm})$

は条件を満たします。\
この時、$S$ の列 $a=(a_0,a_1,\dots,a_{n-1})$に対して
- $l,r$ が与えられたとき、区間積 $a_l\bullet a_{l+1} \dots a_{r-1}$を求める。

というクエリを 
- 前処理・・・$O(n\log n)$
- クエリ・・・$O(1)$ 

で処理します。\
なお、セグメント木やBITとは違って更新はできません。したがって、**静的な**列を扱うことしかできないことに注意してください。

## コンストラクタ
```cpp
kyopro::sparse_table<S,op> st(int n)
kyopro::sparse_table<S,op> st(std::vector<S> a)
```
長さを渡す場合、後述する`set`メソッドで値を入れてから`build`で構築するようにしてください。\
単に`std::vector`を渡す場合はそのまま構築されます

テンプレート引数の`op`は上での$\bullet$のことで、
```cpp
S op(S x,S y){
    //x・yを返す
}
```
みたいに定義してそのまま渡してください。
### 計算量
- $n$ を渡す場合は $O(n)$
- $a$ を渡す場合は $O(n\log n)$

## set,build
```cpp
void set(int i,S v)
void build()
```
`set`で$a_i\leftarrow v$ を行います。終わったら`build`で構築してください。

どちらも初期化用
### 制約
- $0\leq i<n$

### 計算量
- `set`・・・$O(1)$
- `build`・・・$O(n\log n)$

### fold
```cpp
S fold(int l,int r)
```
区間積 $a_l\bullet a_{l+1} \dots a_{r-1}$を求めます。



### 制約
- $0\leq l<r<n$

### 計算量
- $O(1)$