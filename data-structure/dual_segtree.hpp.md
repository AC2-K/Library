---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/AOJ/DSL/2/D2.cpp
    title: test/AOJ/DSL/2/D2.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/2/E2.test.cpp
    title: test/AOJ/DSL/2/E2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/dual_segtree.md
    document_title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      )"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ data-structure/dual_segtree.hpp: line 7: #pragma once found in a non-first line\n"
  code: "/// @brief Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n/// @tparam F \u8981\u7D20\u306E\u578B\n/// @tparam comp \u4E8C\u9805\u6F14\
    \u7B97\n/// @tparam id \u5358\u4F4D\u5143\n/// @docs docs/data-structure/dual_segtree.md\n\
    \n#pragma once\ntemplate<class F, F(*comp)(F, F), F(*id)()>\nclass dual_segtree\
    \ {\n\tint n, sz, lg;\n\n\tconst int lowest = -1;\n\tvector<pair<int, F>> dat;\n\
    \n\tint cur;\n\tconst F id_val = id();\n\npublic:\n\tdual_segtree(const int& n_)\
    \ : n(n_), cur(0) {\n\t\tsz = 1;\n\t\tlg = 0;\n\t\twhile (sz < n) {\n\t\t\tsz\
    \ <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\t\tdat.assign(sz << 1, make_pair(lowest, id_val));\n\
    \t}\n\nprivate:\n\tvoid innner_apply(const int& p, const int& l, const int& r,\
    \ const int& L, const  int& R, const  F& f) {\n\t\tif (r <= L || R <= l) {\n\t\
    \t\treturn;\n\t\t}\n\t\tif (L <= l && r <= R) {\n\t\t\tF nf = comp(dat[p].second,\
    \ f);\n\t\t\tdat[p] = make_pair(cur, nf);\n\t\t\treturn;\n\t\t}\n\t\tint md =\
    \ (l + r) >> 1;\n\t\tinnner_apply(2 * p + 1, l, md, L, R, f);\n\t\tinnner_apply(2\
    \ * p + 2, md, r, L, R, f);\n\t}\npublic:\n\tvoid apply(const int& l, const int&\
    \ r, const F& x) {\n\t\tassert(0 <= l && l <= r && r <= n);\n\t\tinnner_apply(0,\
    \ 0, sz, l, r, x);\n\t\tcur++;\n\t}\n\n\tF operator[](int p) {\n\t\tp = p + sz\
    \ - 1;\t//1-index\n\n\t\tvector<pair<int, F>> path;\n\t\tpath.emplace_back(dat[p]);\n\
    \t\tpath.reserve(lg);\n\t\twhile (p) {\n\t\t\tp = (p - 1) >> 1;\n\t\t\tpath.emplace_back(dat[p]);\n\
    \t\t};\n\n\t\tsort(path.begin(), path.end());\n\n\t\tF res = id_val;\n\t\tfor\
    \ (const auto& q : path) {\n\t\t\tif (q.first == lowest || q.second == id_val)\
    \ {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tres = comp(res, q.second);\n\t\t}\n\n\t\
    \treturn res;\n\t}\n\t//debug\n\tvoid print() {\n\t\tcout << \"[\";\n\t\tfor (int\
    \ i = 0; i < n; i++) {\n\t\t\tcout << (*this)[i] << ' ';\n\t\t}\n\t\tcout << \"\
    ]\\n\";\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dual_segtree.hpp
  requiredBy:
  - test/AOJ/DSL/2/D2.cpp
  timestamp: '2023-03-26 02:30:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/2/E2.test.cpp
documentation_of: data-structure/dual_segtree.hpp
layout: document
redirect_from:
- /library/data-structure/dual_segtree.hpp
- /library/data-structure/dual_segtree.hpp.html
title: "Dual Segmenttree(\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
---
## 概要
(あってる...?)\
$(F,\circ,\text{id})$ をモノイドとする。\
この時、 $F$ 上の列 $a=(a_1,a_2\dots,a_n)$について、以下のクエリを高速に処理する。
- $v\in F$ と区間 $[l,r)$ が与えられる。 $i\in [l,r)$ なる全ての $i$ に対して $a_i\leftarrow a_i\circ v$ と更新する。

- $i$ が与えられたとき、 $a_i$ を求める。

## 使いかた
### コンストラクタ
```cpp
dual_segtree<F,comp,id> seg(int n);
```
長さ $n$ の双対セグメント木を作ります。\
テンプレート引数は以下の通りです
- `comp`:$F$ 上の二項演算。すなわち上での $\circ$
- `id`:$F$ の単位元。上での $e$

最初 $a=(\text{id},\text{id},\text{id},\dots,\text{id})$ です。
### メソッド
```cpp
void apply(int l,int r,F x)
```
区間 $[l,r)$ に $x$ を作用させます。
- 計算量: $O(\log n)$

```cpp
F seg[int i]
```
$a_i$ を取得します
- 計算量 $O(\log n)$