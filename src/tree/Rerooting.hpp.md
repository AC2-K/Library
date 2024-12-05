---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \ <typename M,\n          typename OP,\n          typename PUT_V,\n          typename\
    \ PUT_E,\n          typename LEAF>\nclass Rerooting {\n    const M identity;\n\
    \    const OP op;\n    const PUT_V put_vertex;\n    const PUT_E put_edge;\n  \
    \  const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int, std::pair<int,\
    \ int>>> es;\n\npublic:\n    Rerooting(int n,\n              const M& identity,\n\
    \              const OP& op,\n              const PUT_V& put_vertex,\n       \
    \       const PUT_E& put_edge,\n              const LEAF& leaf)\n        : n(n),\n\
    \          identity(identity),\n          op(op),\n          put_vertex(put_vertex),\n\
    \          put_edge(put_edge),\n          leaf(leaf) {\n        es.reserve(2 *\
    \ n - 2);\n    }\n\n    void add_edge(int u, int v, int i) {\n        es.emplace_back(u,\
    \ std::pair(v, i));\n        es.emplace_back(v, std::pair(u, i));\n    }\n\n \
    \   std::vector<M> run() {\n        assert(es.size() == 2 * n - 2);\n\n      \
    \  internal::csr g(n, es);\n\n        std::vector<M> dp1(n);\n        {\n    \
    \        auto push_up = [&](const auto& push_up, int v, int p = -1) -> M {\n \
    \               dp1[v] = identity;\n\n                for (auto [nv, e] : g[v])\
    \ {\n                    if (nv == p) continue;\n                    dp1[v] =\
    \ op(dp1[v], put_edge(push_up(push_up, nv, v), e));\n                }\n\n   \
    \             dp1[v] = put_vertex(dp1[v], v);\n\n                dp1[v] = op(dp1[v],\
    \ leaf(v));\n\n                return dp1[v];\n            };\n            push_up(push_up,\
    \ 0, -1);\n        }\n\n        std::vector<M> dp(n);\n\n        {\n         \
    \   // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\u3044\u304F\n\n\
    \            auto push_down = [&](const auto& push_down, int v, int p,\n     \
    \                            M agg) -> void {\n                dp[v] = agg;\n\n\
    \                std::vector<std::pair<int, int>> children;\n                std::vector<M>\
    \ pref, suff;\n\n                for (auto [nv, e] : g[v]) {\n               \
    \     if (nv == p) continue;\n\n                    children.emplace_back(nv,\
    \ e);\n                    pref.emplace_back(put_edge(dp1[nv], e));\n        \
    \            suff.emplace_back(put_edge(dp1[nv], e));\n                }\n\n \
    \               if (children.empty()) return;\n\n                for (int i =\
    \ 0; i < (int)pref.size() - 1; ++i) {\n                    pref[i + 1] = op(pref[i\
    \ + 1], pref[i]);\n                }\n\n                for (int i = (int)suff.size()\
    \ - 1; i > 0; --i) {\n                    suff[i - 1] = op(suff[i - 1], suff[i]);\n\
    \                }\n\n                dp[v] = op(dp[v], put_vertex(pref.back(),\
    \ v));\n\n                for (int i = 0; i < (int)children.size(); ++i) {\n \
    \                   M next_agg = op(leaf(v), agg);\n\n                    if (i\
    \ > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n    \
    \                }\n\n                    if (i < (int)suff.size() - 1) {\n  \
    \                      next_agg = op(next_agg, suff[i + 1]);\n               \
    \     }\n                    \n                    next_agg = put_vertex(\n  \
    \                      put_edge(put_vertex(next_agg, v), children[i].second),\n\
    \                        children[i].first);\n\n                    push_down(push_down,\
    \ children[i].first, v, next_agg);\n                }\n                return;\n\
    \            };\n            push_down(push_down, 0, -1, identity);\n        }\n\
    \n        return dp;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Solving\
    \ DP on tree for all roots(\u5168\u65B9\u4F4D\u6728DP)\n * @docs docs/tree/Rerooting.md\n\
    \ */\n"
  code: "#pragma once\n#include \"../../src/internal/CSR.hpp\"\n\nnamespace kyopro\
    \ {\ntemplate <typename M,\n          typename OP,\n          typename PUT_V,\n\
    \          typename PUT_E,\n          typename LEAF>\nclass Rerooting {\n    const\
    \ M identity;\n    const OP op;\n    const PUT_V put_vertex;\n    const PUT_E\
    \ put_edge;\n    const LEAF leaf;\n\n    const int n;\n\n    std::vector<std::pair<int,\
    \ std::pair<int, int>>> es;\n\npublic:\n    Rerooting(int n,\n              const\
    \ M& identity,\n              const OP& op,\n              const PUT_V& put_vertex,\n\
    \              const PUT_E& put_edge,\n              const LEAF& leaf)\n     \
    \   : n(n),\n          identity(identity),\n          op(op),\n          put_vertex(put_vertex),\n\
    \          put_edge(put_edge),\n          leaf(leaf) {\n        es.reserve(2 *\
    \ n - 2);\n    }\n\n    void add_edge(int u, int v, int i) {\n        es.emplace_back(u,\
    \ std::pair(v, i));\n        es.emplace_back(v, std::pair(u, i));\n    }\n\n \
    \   std::vector<M> run() {\n        assert(es.size() == 2 * n - 2);\n\n      \
    \  internal::csr g(n, es);\n\n        std::vector<M> dp1(n);\n        {\n    \
    \        auto push_up = [&](const auto& push_up, int v, int p = -1) -> M {\n \
    \               dp1[v] = identity;\n\n                for (auto [nv, e] : g[v])\
    \ {\n                    if (nv == p) continue;\n                    dp1[v] =\
    \ op(dp1[v], put_edge(push_up(push_up, nv, v), e));\n                }\n\n   \
    \             dp1[v] = put_vertex(dp1[v], v);\n\n                dp1[v] = op(dp1[v],\
    \ leaf(v));\n\n                return dp1[v];\n            };\n            push_up(push_up,\
    \ 0, -1);\n        }\n\n        std::vector<M> dp(n);\n\n        {\n         \
    \   // \u4E0A\u304B\u3089\u4E0B\u3078\u4F1D\u642C\u3057\u3066\u3044\u304F\n\n\
    \            auto push_down = [&](const auto& push_down, int v, int p,\n     \
    \                            M agg) -> void {\n                dp[v] = agg;\n\n\
    \                std::vector<std::pair<int, int>> children;\n                std::vector<M>\
    \ pref, suff;\n\n                for (auto [nv, e] : g[v]) {\n               \
    \     if (nv == p) continue;\n\n                    children.emplace_back(nv,\
    \ e);\n                    pref.emplace_back(put_edge(dp1[nv], e));\n        \
    \            suff.emplace_back(put_edge(dp1[nv], e));\n                }\n\n \
    \               if (children.empty()) return;\n\n                for (int i =\
    \ 0; i < (int)pref.size() - 1; ++i) {\n                    pref[i + 1] = op(pref[i\
    \ + 1], pref[i]);\n                }\n\n                for (int i = (int)suff.size()\
    \ - 1; i > 0; --i) {\n                    suff[i - 1] = op(suff[i - 1], suff[i]);\n\
    \                }\n\n                dp[v] = op(dp[v], put_vertex(pref.back(),\
    \ v));\n\n                for (int i = 0; i < (int)children.size(); ++i) {\n \
    \                   M next_agg = op(leaf(v), agg);\n\n                    if (i\
    \ > 0) {\n                        next_agg = op(next_agg, pref[i - 1]);\n    \
    \                }\n\n                    if (i < (int)suff.size() - 1) {\n  \
    \                      next_agg = op(next_agg, suff[i + 1]);\n               \
    \     }\n                    \n                    next_agg = put_vertex(\n  \
    \                      put_edge(put_vertex(next_agg, v), children[i].second),\n\
    \                        children[i].first);\n\n                    push_down(push_down,\
    \ children[i].first, v, next_agg);\n                }\n                return;\n\
    \            };\n            push_down(push_down, 0, -1, identity);\n        }\n\
    \n        return dp;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief Solving\
    \ DP on tree for all roots(\u5168\u65B9\u4F4D\u6728DP)\n * @docs docs/tree/Rerooting.md\n\
    \ */"
  dependsOn:
  - src/internal/CSR.hpp
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-09-02 21:21:38+09:00'
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

以下の問題を考えます.

> $N$ 頂点の木 $T=(V, E)$ が与えられます.\
> **可換**モノイド $(M,\text{op},\text{id})$ があり, 各頂点 $v\in V$ に対して値 $a_v\in M$ が定まっているとします. \
> また,
> 
> - 写像 $f:M \times V \to M;(x,v)\to f_v(x)$ 
> - 写像 $g:M \times E \to M;(x,e)\to g_e(x)$
> 
> が定まっているとします.
>  
> 各 $r\in V$ に対して, 以下を行ってください.
> 
> - $q(v)\in M$ を以下のようにして定める.
>   - $v$ が根でない場合 $C_{r}(v)$ を $v$ から子方向へと伸びている辺の集合として\
>       $\displaystyle q(v)=a_v+f_v\left(\sum_{e=(v,u)\in C(v)}{g_e(q(u))}\right)$\
>       とする.
>   - $v$ が根の場合, 上と同様にして $C(v)$ を定め\
>       $\displaystyle q(v)=f_v\left(\sum_{e=(v,u)\in C(v)}{g_e(q(u))}\right)$\
>       とする
> 
> - $T$ を $r$ を根とする根付き木と見なし $q(r)$ の値を求める.

素直な木DPを毎回行うと計算量は $O(N^2)$ となってしまいます. しかし, 全方位木DPを用いれば計算量 $O(N)$ でこれを達成できます.

なお, 以下 $E,V$ を頂点番号や辺番号と同一視することにします.

# 2. 使用方法

## コンストラクタ

```cpp
template<typename M, 
         typename OP,
         typename PUT_E,
         typename PUT_V, 
         typename LEAF>
Rerooting(int n, 
          const V& identity, 
          const OP& op,
          const PUT_V& put_vertex,
          const PUT_E& put_edge,
          const LEAF&LEAF
          )
```

型:
- `M` : $M$ を表す型
- `OP`, `PUT_V`, `PUT_E`, `LEAF` : それぞれ後述する`op`, `put_vertex`, `put_edge`, `leaf`の型

変数:
- `n` : $T$ の頂点数
- `identity` : $M$ の単位元
- `op` : $M$ の二項演算
- `put_vertex` : $(x,v)\in M\times V$ を引数に取り, $f_v(x)$ を返す関数
- `put_edge` : $(x,e)\in M\times E$ を引数に取り, $g_{e}(x)$ を返す関数
- `leaf` : $v\in V$ を引数に取り $a_v$ の値を返す関数

なお, 本ライブラリではこれらの呼び出しは $O(1)$ で行えるものとして計算量を表記しています.

実用例をいくつか提示しておきます.

- [ABC222 - F](https://atcoder.jp/contests/abc222/submissions/57491947)
- [LibraryChecker - Tree Path Composite Sum](https://judge.yosupo.jp/submission/232590)

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
上記の問題における $q(r)$ の計算結果の列をvectorにして返します.

### 制約

- 呼び出し時, `add_edge` が合計 $N-1$ 回呼び出された.
- このメソッドの呼び出し以降に`add_edge`が呼び出されることはない.

### 計算量 
- $O(N)$