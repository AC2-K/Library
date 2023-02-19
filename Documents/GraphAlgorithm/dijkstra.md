# dijkstra
ダイクストラ法!!!\
重み付き有向(無向でもいい)グラフと頂点 $s$ を渡すと、 $s$ を始点とした最短経路問題を全頂点に対して解きます。
```cpp
pair<vector<long long>,vector<int>> dijkstra(int s, vector<vector<edge>> g)
```
のように呼び出します。\
`edge`は、辺の行き先`to`と重み`cost`を持つ構造体です。[edge.hpp](https://github.com/AC2-K/Library-CPP/blob/main/GraphAlgorithm/edge.hpp)を参照してください。
\
\
呼び出すと、次の配列が返ってきます。
- $dist[v]$
- $prev[v]$
### dist
$dist[v]$ は $s\to v$ の最短経路長です。たどり着けないときは $dist[v]=10^{18}$ です。
### prev
$s\to v$ の最短パスを $(p_1=s,p_2,\dots,p_k=v)$ とします。このようなパスが存在すれば、 $prev[v]=p_{k-1}$ です。ただし、 $prev[s]=s$ です。\
そもそも最短パスが存在しなければ $prev[v]=-1$ です。
\
\
復元用です。