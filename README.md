# LibraryCPP
## What's this???
使ってるライブラリ集(C++)です。なお、基本的には以下のテンプレートを用いています。
```cpp:template.hpp
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
```
- [template.hpp](https://github.com/AC2-K/Library-CPP/blob/main/template.hpp)

AOJとかでAtCoderで動くことを確認している...はず。

バグ、エラーなどなど...不備を見つけた際は、[twitter](https://twitter.com/ac2000_cp)などに連絡いただけるととても助かります。

## ドキュメント
ゆるゆる更新していきます。
|FileName|Document|
|-------:|-------:|
|[dsu.hpp](https://github.com/AC2-K/Library-CPP/blob/main/DataStructure/dsu.hpp)|[dsu.md](https://github.com/AC2-K/Library-CPP/blob/main/Documents/DataStructure/dsu.md)|
|[segtree.hpp](https://github.com/AC2-K/Library-CPP/blob/main/DataStructure/segtree.hpp)|[segtree.md](https://github.com/AC2-K/Library-CPP/blob/main/Documents/DataStructure/segtree.md)|
|[lazy_segtree.hpp](https://github.com/AC2-K/Library-CPP/blob/main/DataStructure/lazy_segtree.hpp)|[lazy_segtree.md](https://github.com/AC2-K/Library-CPP/blob/main/Documents/DataStructure/lazy_segtree.md)|
