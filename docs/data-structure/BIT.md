## 概要

Binary Index Tree(BIT) とは、整数列に対する

- 一点加算
- 区間和の計算

をクエリごと $O(\log n)$ で処理するデータ構造です.

## コンストラクタ

```cpp
kyopro::BIT<T> a(int n);
```

長さ $n$ の数列を扱うBITを生成します.
Tは、**和が収まる** 型名です. 
<details>
<summary>おまけ</summary>
型にoperatorを定義してから渡すことで,群やモノイドを乗せることができます(このライブラリはモノイドには対応していません...)
</details>


### 計算量

- $O(n)$

## add

```cpp
void add(int i,T w)
```

$a_i\leftarrow a_i+w$ を行います.

### 制約

- $0 \leq i \lt n$

### 計算量

- $O(\log n)$

## update
```cpp
void update(int i, T w)
```
$a_i\leftarrow w$ を行います.
### 制約

- $0 \leq i \lt n$

### 計算量

- $O(\log n)$


## sum

```cpp
T sum(int p)
```

$\sum_{0 \leq i \lt p}{a_i}$ を計算します

```cpp
T sum(int l, int r)
```

$\sum_{l \leq i \lt r}{a_i}$ を計算します

### 制約

- $0 \leq p \lt n$
- $0 \leq l \leq r \lt n$

### 計算量

- いずれも $O(\log n)$

## operator[]
```cpp
T a[int i]
```
$a_i$ の値を返します

### 制約

- $0 \leq i \lt n$

### 計算量

- いずれも $O(\log n)$



## lower_bound

```cpp
int lower_bound(T w)
```

$\sum_{0 \leq i \lt k}{a_i} \geq w$ となるような最小の $k$ を求めます.\
存在しなければ $\vert a \vert$ を返します.

### 制約

- 呼び出されるとき、$a$ の各項は非負である

### 計算量

- $O(\log n)$
