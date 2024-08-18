---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/internal/CSR.hpp
    title: "CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
      \u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
    title: test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/Rerooting.md
    document_title: "Solving DP on tree for all roots(\u5168\u65B9\u4F4D\u6728DP)"
    links: []
  bundledCode: "#line 2 \"src/internal/CSR.hpp\"\n\n#include <cassert>\n#include <iterator>\n\
    #include <utility>\n#include <vector>\n\nnamespace kyopro {\nnamespace internal\
    \ {\n\ntemplate <typename T, typename _size_t> class csr {\n    _size_t n;\n \
    \   std::vector<T> d;\n    std::vector<_size_t> ssum;\n\npublic:\n    csr() =\
    \ default;\n    csr(_size_t n, const std::vector<std::pair<_size_t, T>>& v)\n\
    \        : n(n), ssum(n + 1), d(v.size()) {\n        for (int i = 0; i < (int)v.size();\
    \ ++i) {\n            ++ssum[v[i].first + 1];\n        }\n        for (int i =\
    \ 0; i < n; ++i) {\n            ssum[i + 1] += ssum[i];\n        }\n\n       \
    \ std::vector cnt = ssum;\n        for (auto e : v) d[cnt[e.first]++] = e.second;\n\
    \    }\n\n    struct vector_range {\n        using iterator = typename std::vector<T>::iterator;\n\
    \        iterator l, r;\n\n        iterator begin() const { return l; }\n    \
    \    iterator end() const { return r; }\n        _size_t size() { return std::distance(l,\
    \ r); }\n        T& operator[](_size_t i) const { return l[i]; }\n    };\n   \
    \ struct const_vector_range {\n        using const_iterator = typename std::vector<T>::const_iterator;\n\
    \        const_iterator l, r;\n\n        const_iterator begin() const { return\
    \ l; }\n        const_iterator end() const { return r; }\n        _size_t size()\
    \ { return (_size_t)std::distance(l, r); }\n        const T& operator[](_size_t\
    \ i) const { return l[i]; }\n    };\n\n    vector_range operator[](_size_t i)\
    \ {\n        return vector_range{d.begin() + ssum[i], d.begin() + ssum[i + 1]};\n\
    \    }\n    const_vector_range operator[](_size_t i) const {\n        return const_vector_range{d.begin()\
    \ + ssum[i], d.begin() + ssum[i + 1]};\n    }\n\n    _size_t size() const { return\
    \ (_size_t)n; }\n};\n};  // namespace internal\n};  // namespace kyopro\n\n/**\n\
    \ * @brief CSR\u5F62\u5F0F(\u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u306E\u5727\
    \u7E2E)\n */\n#line 3 \"src/tree/Rerooting.hpp\"\n\nnamespace kyopro {\ntemplate\
    \ <typename M, typename OP, typename PUT_EV, typename LEAF>\nclass Rerooting {\n\
    \    const M identity;\n    const OP op;\n    const PUT_EV put_edge_vertex;\n\
    \    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const M& identity,\n\
    \              const OP& op,\n              const PUT_EV& put_edge_vertex,\n \
    \             const LEAF& leaf)\n        : n(n),\n          identity(identity),\n\
    \          op(op),\n          put_edge_vertex(put_edge_vertex),\n          leaf(leaf)\
    \ {\n        es.reserve(2 * n - 2);\n    }\n    void add_edge(int u, int v, int\
    \ i) {\n        es.emplace_back(u, std::pair(v, i));\n        es.emplace_back(v,\
    \ std::pair(u, i));\n    }\n\n    std::vector<M> run() {\n        assert(es.size()\
    \ == 2 * n - 2);\n\n        internal::csr g(n, es);\n\n        std::vector<M>\
    \ dp1(n);\n        {\n            auto push_up = [&](const auto& push_up, int\
    \ v, int p = -1) -> M {\n                dp1[v] = leaf(v);\n                for\
    \ (auto [nv, e_idx] : g[v]) {\n                    if (nv == p) continue;\n  \
    \                  dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),\n\
    \                                                        e_idx, v));\n       \
    \             // \u9802\u70B9, \u8FBA\u306E\u60C5\u5831\u3092\u6DFB\u52A0\n  \
    \              }\n                return dp1[v];\n            };\n           \
    \ push_up(push_up, 0, -1);\n        }\n\n        std::vector<M> dp(n);\n\n   \
    \     {\n            // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\
    \u3044\u304F\n            \n            auto push_down = [&](const auto& push_down,\
    \ int v, int p,\n                                 M agg) -> void {\n         \
    \       dp[v] = agg;\n                std::vector<std::pair<int, int>> children;\n\
    \                std::vector<M> pref, suff;\n                for (auto [nv, e_idx]\
    \ : g[v]) {\n                    if (nv == p) continue;\n                    children.emplace_back(nv,\
    \ e_idx);\n                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                }\n\n                if (children.empty()) return;\n \
    \               for (int i = 0; i < (int)pref.size() - 1; ++i) {\n           \
    \         pref[i + 1] = op(pref[i + 1], pref[i]);\n                }\n       \
    \         for (int i = (int)suff.size() - 1; i > 0; --i) {\n                 \
    \   suff[i - 1] = op(suff[i - 1], suff[i]);\n                }\n             \
    \   dp[v] = op(dp[v], pref.back());\n\n                for (int i = 0; i < (int)children.size();\
    \ ++i) {\n                    M next_agg = op(leaf(v), agg);\n               \
    \     if (i > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n\
    \                    }\n                    if (i < (int)suff.size() - 1) {\n\
    \                        next_agg = op(next_agg, suff[i + 1]);\n             \
    \       }\n\n                    next_agg = put_edge_vertex(next_agg, children[i].second,\n\
    \                                               children[i].first);\n\n      \
    \              push_down(push_down, children[i].first, v, next_agg);\n       \
    \         }\n                return;\n            };\n            push_down(push_down,\
    \ 0, -1, identity);\n        }\n\n        return dp;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Solving DP on tree for all roots(\u5168\u65B9\u4F4D\
    \u6728DP)\n * @docs docs/tree/Rerooting.md\n */\n"
  code: "#pragma once\n#include \"../../src/internal/CSR.hpp\"\n\nnamespace kyopro\
    \ {\ntemplate <typename M, typename OP, typename PUT_EV, typename LEAF>\nclass\
    \ Rerooting {\n    const M identity;\n    const OP op;\n    const PUT_EV put_edge_vertex;\n\
    \    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const M& identity,\n\
    \              const OP& op,\n              const PUT_EV& put_edge_vertex,\n \
    \             const LEAF& leaf)\n        : n(n),\n          identity(identity),\n\
    \          op(op),\n          put_edge_vertex(put_edge_vertex),\n          leaf(leaf)\
    \ {\n        es.reserve(2 * n - 2);\n    }\n    void add_edge(int u, int v, int\
    \ i) {\n        es.emplace_back(u, std::pair(v, i));\n        es.emplace_back(v,\
    \ std::pair(u, i));\n    }\n\n    std::vector<M> run() {\n        assert(es.size()\
    \ == 2 * n - 2);\n\n        internal::csr g(n, es);\n\n        std::vector<M>\
    \ dp1(n);\n        {\n            auto push_up = [&](const auto& push_up, int\
    \ v, int p = -1) -> M {\n                dp1[v] = leaf(v);\n                for\
    \ (auto [nv, e_idx] : g[v]) {\n                    if (nv == p) continue;\n  \
    \                  dp1[v] = op(dp1[v], put_edge_vertex(push_up(push_up, nv, v),\n\
    \                                                        e_idx, v));\n       \
    \             // \u9802\u70B9, \u8FBA\u306E\u60C5\u5831\u3092\u6DFB\u52A0\n  \
    \              }\n                return dp1[v];\n            };\n           \
    \ push_up(push_up, 0, -1);\n        }\n\n        std::vector<M> dp(n);\n\n   \
    \     {\n            // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\
    \u3044\u304F\n            \n            auto push_down = [&](const auto& push_down,\
    \ int v, int p,\n                                 M agg) -> void {\n         \
    \       dp[v] = agg;\n                std::vector<std::pair<int, int>> children;\n\
    \                std::vector<M> pref, suff;\n                for (auto [nv, e_idx]\
    \ : g[v]) {\n                    if (nv == p) continue;\n                    children.emplace_back(nv,\
    \ e_idx);\n                    pref.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                    suff.emplace_back(put_edge_vertex(dp1[nv], e_idx,\
    \ v));\n                }\n\n                if (children.empty()) return;\n \
    \               for (int i = 0; i < (int)pref.size() - 1; ++i) {\n           \
    \         pref[i + 1] = op(pref[i + 1], pref[i]);\n                }\n       \
    \         for (int i = (int)suff.size() - 1; i > 0; --i) {\n                 \
    \   suff[i - 1] = op(suff[i - 1], suff[i]);\n                }\n             \
    \   dp[v] = op(dp[v], pref.back());\n\n                for (int i = 0; i < (int)children.size();\
    \ ++i) {\n                    M next_agg = op(leaf(v), agg);\n               \
    \     if (i > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n\
    \                    }\n                    if (i < (int)suff.size() - 1) {\n\
    \                        next_agg = op(next_agg, suff[i + 1]);\n             \
    \       }\n\n                    next_agg = put_edge_vertex(next_agg, children[i].second,\n\
    \                                               children[i].first);\n\n      \
    \              push_down(push_down, children[i].first, v, next_agg);\n       \
    \         }\n                return;\n            };\n            push_down(push_down,\
    \ 0, -1, identity);\n        }\n\n        return dp;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Solving DP on tree for all roots(\u5168\u65B9\u4F4D\
    \u6728DP)\n * @docs docs/tree/Rerooting.md\n */"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-08-18 01:00:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/tree/Tree_Path_Composite_Sum.test.cpp
documentation_of: src/tree/Rerooting.hpp
layout: document
redirect_from:
- /library/src/tree/Rerooting.hpp
- /library/src/tree/Rerooting.hpp.html
title: "Solving DP on tree for all roots(\u5168\u65B9\u4F4D\u6728DP)"
---
# 1. 概要

このライブラリは全方位木DP(Rerooting DP)を用いて問題を解くことをサポートします.

以下の問題を考えます(これは[Tree Path Composite Sum](https://judge.yosupo.jp/problem/tree_path_composite_sum)を一般化した問題となっています)

> $n$ 頂点の木 $T=(V, E)$ が与えられます.\
> 可換モノイド $M$ があり, 各頂点 $v\in M$ 対して値 $a_v\in M$ が定まっています.\
> また, $V\times E$ から $M$ への  作用 $f:M\times V\times E \to M;(x,v,e)\to f_{e,v}(x)$ が定義されています.\
> $P:(x,y)\in V\times V\to S$ を以下のようにして定めます.
> 
> - $T$ における $x\to y$ の単純パスを $(v_0,e_0,v_1,\dots,v_{k},e_k,v_{k+1})$ として $P(x,y)=f_{v_0,e_0}(f_{v_1,e_1}(\dots f_{v_k,e_k}(a_y)\dots))$
>
> すべての $x\in V$ に対して $q_x=\displaystyle\prod_{y\neq x}{P(x,y)}$ の値を計算してください.

このライブラリでは $O(N)$ 時間でこれを解きます.

# 2. 使用方法

## コンストラクタ

```cpp
template<typename M, typename OP, typename PUT_EV, typename LEAF>
Rerooting(int n, 
          const V& identity, 
          const OP& op,
          const PUT_EV& put_edge_vertex,
          const LEAF&LEAF
          )
```

- `M` : $M$ を表す型
- `OP`, `PUT_EV`, `LEAF` : それぞれ後述する`op`, `put_edge_vertex`, `leaf`の型

- `n` : $T$ の頂点数
- `identity` : $M$ の単位元
- `op` : $M$ の二項演算.
- `put_edge_vertex` : $x\in M,e\in E,v\in V$を引数に取り, $f_{e,v}(x)$ を返す関数
- `leaf` : $v\in V$ を引数に取り $a_v$ の値を返す関数


なお, 本ライブラリではこれらの呼び出しは $O(1)$ で行えるものとして計算量を表記しています.

<details> <summary> 実装例 </summary>

[ABC222 F - Expensive Expense](https://atcoder.jp/contests/abc222/tasks/abc222_f)

```cpp

int main() {
    ...

    vector<int> c(n - 1), d(n);
    auto op = [&](ll x, ll y) { return max(x, y); };
    auto put_edge_vertex = [&](ll x, int e, int v) { return x + c[e]; };
    auto leaf = [&](int v) { return d[v]; };

    Rerooting<ll, decltype(op), decltype(put_edge_vertex), decltype(leaf)> t(
        n, 0, op, put_edge_vertex, leaf);
    
    ...
}
```

[Library Checker 「Tree Path Composite Sum」](https://judge.yosupo.jp/submission/229005)


```cpp

using mint = modint<998244353>;

int main() {
    ...

    using M = pair<mint, mint>
    auto op = [&](M x, M y) {
        return M(x.first + y.first, x.second + y.second);
    };
    auto put_edge_vertex = [&](M x, int e, int) {
        return M(b[e] * x.first + c[e] * x.second, x.second);
    };
    auto leaf = [&](int v) { return M(a[v], mint(1)); };

    Rerooting<M, decltype(op), decltype(put_edge_vertex), decltype(leaf)> 
        t(n, M(), op, put_edge_vertex, leaf);

    ...
}

```


</details>

### 制約

- すべての引数が条件を満たしている

## add_edge

```cpp
void add_edge(int u, int v, int e)
```
$u,v$ の頂点間に辺 $e$ を張ります.

### 制約
- $0\leq u,v\lt N$
- $u\neq v$
- $0\leq e\lt N-1$
- 呼び出しごとに $e$ の値は異なる
- これが呼び出されるとき, $u,v$ は連結でない
- `add_edge`は全体で合計 $N-1$ 回呼び出される

## run

```cpp
std::vector<M> run()
```
上記の問題における $q_x$ の計算結果をvectorにして返します.

### 制約

- 呼び出し時, `add_edge` が合計 $N-1$ 回呼び出された.
- このメソッドの呼び出し以降に`add_edge`が呼び出されることはない.

### 計算量 
- $O(N)$