## 概要
Binary Index Tree(BIT) とは、整数列に対する
- 一点加算
- 区間和の計算

をクエリごと $O(\log n)$ で処理するデータ構造です。

## コンストラクタ
```cpp
kyopro::BIT<T> bit(int n);
```
長さ $n$ の数列を扱うBITを生成します。
Tは、**和が収まる型**の名前です。

以下、扱う数列を $a=(a_0,a_1,\dots,a_{n-1})\subset\mathbb{Z}$ であるとします。
### 計算量
- $O(n)$

## add
```cpp
void add(int i,S w)
```
$a_i\leftarrow a_i+w$ を行います。

### 制約
- $0 \leq i \lt n$

### 計算量
- $O(\log n)$

## sum
```cpp
S sum(int p)
```

$\sum_{0 \leq i \lt p}{a_i}$ を計算します

```cpp
S sum(int l,int r)
```

$\sum_{l \leq i \lt r}{a_i}$ を計算します


### 制約
- $0 \leq p \lt n$
- $0 \leq l \leq r \lt n$

### 計算量
- いずれも $O(\log n)$

## lower_bound
```cpp
int lower_bound(S w)
```
$\sum_{0 \leq i \lt k}{a_i} \geq w$ となるような最小の $k$ を求めます
### 制約
- 呼び出されるとき、$a$ の各項は非負である

### 計算量
- $O(\log n)$
