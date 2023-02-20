# ConvexHullTrick
直線群 $L$ を管理し、以下の処理を $O(\log n)$ で行います。
- $a,b$ が与えられる。 $L$ に $l:y=ax+b$ を追加する。
- $x$ が与えられる。 $$\min_{(x,y)\in{L}} y$$ を求めます。

## コンストラクタ
```cpp
ConvexHullTrick<typename T,bool is_max> cht
```
$a,b$ などなどの型を `T` で指定します(long longとか)\
クエリの $\min$ を $\max$ にしたいときは`is_max`をtrue`にします。
## add
```cpp
void cht.add(T a,T b)
```
$L$ に $l:y=ax+b$ を追加します。

## operator()
```cpp
T cht(T x)
```
$$\min_{(x,y)\in{L}} y$$ 
を求めます。