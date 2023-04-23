---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure-2d/RangeTree.hpp
    title: src/data-structure-2d/RangeTree.hpp
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure-2d/RangeTree.hpp\"\n#include\
    \ <algorithm>\n#line 2 \"src/data-structure/segtree.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/// @brief Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nclass segtree {\n    int lg,\
    \ sz, n;\n    std::vector<S> dat;\n\npublic:\n    segtree() {}\n    segtree(int\
    \ n) : segtree(std::vector<S>(n, e())) {}\n    segtree(const std::vector<S>& vec)\
    \ : n((int)vec.size()) {\n        sz = 1, lg = 0;\n        while (sz <= n) {\n\
    \            sz <<= 1;\n            lg++;\n        }\n\n        dat = std::vector<S>(sz\
    \ << 1, e());\n\n        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n\
    \        }\n        build();\n    }\n\n    inline void set(int p, const S& v)\
    \ { dat[sz + p] = v; }\n    inline void build() {\n        for (int i = sz - 1;\
    \ i > 0; i--) {\n            dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n  \
    \      }\n    }\n    S operator[](int p) const { return dat[sz + p]; }\n\n   \
    \ inline void update(int p, const S& v) {\n        p += sz;\n        dat[p] =\
    \ v;\n        while (p >>= 1) {\n            dat[p] = op(dat[(p << 1)], dat[(p\
    \ << 1) ^ 1]);\n        }\n    }\n\n    inline S prod(int l, int r) const {\n\
    \        if (l == 0 && r == n) {\n            return dat[1];\n        }\n    \
    \    l += sz, r += sz;\n        S sml = e(), smr = e();\n        while (l != r)\
    \ {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if (r & 1) smr\
    \ = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n        return\
    \ op(sml, smr);\n    }\n    inline void apply(int p, const S& v) { update(p, op(dat[sz\
    \ + p], v)); }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/segtree.md\n\
    #line 4 \"src/data-structure-2d/RangeTree.hpp\"\nnamespace kyopro {\ntemplate\
    \ <typename T, typename S, S (*op)(S, S), S (*e)()>\nclass RangeTree {\n    std::vector<segtree<S,\
    \ op, e>> dat;\n    std::vector<std::vector<T>> ys;\n\n    T n;\n    std::vector<std::pair<T,\
    \ T>> ps;\n\npublic:\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\
    \n    void build() {\n        std::sort(ps.begin(), ps.end());\n        ps.erase(std::unique(ps.begin(),\
    \ ps.end()), ps.end());\n\n        n = ps.size();\n        dat.assign(2 * n, segtree<S,\
    \ op, e>());\n\n        ys.resize(2 * n);\n        for (int i = 0; i < n; ++i)\
    \ {\n            ys[i + n].emplace_back(ps[i].second);\n            dat[i + n]\
    \ = segtree<S, op, e>(1);\n        }\n\n        for (int i = n - 1; i > 0; --i)\
    \ {\n            ys[i].resize(ys[i << 1 | 0].size() + ys[i << 1 | 1].size());\n\
    \            std::merge(ys[i << 1 | 0].begin(), ys[i << 1 | 0].end(),\n      \
    \                 ys[i << 1 | 1].begin(), ys[i << 1 | 1].end(),\n            \
    \           ys[i].begin());\n\n            ys[i].erase(std::unique(ys[i].begin(),\
    \ ys[i].end()), ys[i].end());\n            dat[i] = segtree<S, op, e>(ys[i].size());\n\
    \        }\n    }\n\n    inline int id(T x) const {\n        return std::lower_bound(\n\
    \                   ps.begin(), ps.end(), std::make_pair(x, T()),\n          \
    \         [](const std::pair<T, T>& a, const std::pair<T, T>& b) {\n         \
    \              return a.first < b.first;\n                   }) -\n          \
    \     ps.begin();\n    }\n\n    inline int id(int i, T y) const {\n        return\
    \ std::lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();\n    }\n\n\
    \    void add(T x, T y, S w) {\n        int i = std::lower_bound(ps.begin(), ps.end(),\
    \ std::make_pair(x, y)) -\n                ps.begin();\n\n        for (i += n;\
    \ i; i >>= 1) {\n            dat[i].apply(id(i, y), w);\n        }\n    }\n\n\
    \    S sum(T xl, T yl, T xr, T yr) {\n        S suml = e(), sumr = e();\n\n  \
    \      int a = id(xl), b = id(xr);\n        a += n, b += n;\n        while (a\
    \ < b) {\n            if (a & 1) {\n                suml = op(suml, dat[a].prod(id(a,\
    \ yl), id(a, yr)));\n                ++a;\n            }\n            if (b &\
    \ 1) {\n                --b;\n                sumr = op(sumr, dat[b].prod(id(b,\
    \ yl), id(b, yr)));\n            }\n\n            a >>= 1, b >>= 1;\n        }\n\
    \n        return op(suml, sumr);\n    }\n};\n};  // namespace kyopro\n#line 4\
    \ \"test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp\"\
    \ninline long long op(long long a, long long b) { return a + b; };\ninline long\
    \ long e() { return 0; }\nint main() {\n    using namespace std;\n    kyopro::RangeTree<int,\
    \ long long, op, e> rtree;\n\n    int N, Q;\n    scanf(\"%d %d\\n\", &N, &Q);\n\
    \    int X[N], Y[N], W[N];\n    int c[Q];\n    int s[Q], t[Q], u[Q], v[Q];\n \
    \   for (int i = 0; i < Q; ++i) {\n        scanf(\"%d %d %d\\n\", &X[i], &Y[i],\
    \ &W[i]);\n        rtree.add_point(X[i], Y[i]);\n    }\n    for (int i = 0; i\
    \ < Q; ++i) {\n        scanf(\"%d \", &c[i]);\n        if (c[i]) {\n         \
    \   scanf(\"%d %d %d %d\\n\", &s[i], &t[i], &u[i], &v[i]);\n        } else {\n\
    \            scanf(\"%d %d %d\\n\", &s[i], &t[i], &u[i]);\n            rtree.add_point(s[i],\
    \ t[i]);\n        }\n    }\n\n    rtree.build();\n\n    for (int i = 0; i < N;\
    \ ++i) rtree.add(X[i], Y[i], W[i]);\n    \n    for (int i = 0; i < Q; ++i) {\n\
    \        if (c[i]) {\n            printf(\"%lld\\n\", rtree.sum(s[i], t[i], u[i],\
    \ v[i]));\n        } else {\n            rtree.add(s[i], t[i], u[i]);\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure-2d/RangeTree.hpp\"\
    \ninline long long op(long long a, long long b) { return a + b; };\ninline long\
    \ long e() { return 0; }\nint main() {\n    using namespace std;\n    kyopro::RangeTree<int,\
    \ long long, op, e> rtree;\n\n    int N, Q;\n    scanf(\"%d %d\\n\", &N, &Q);\n\
    \    int X[N], Y[N], W[N];\n    int c[Q];\n    int s[Q], t[Q], u[Q], v[Q];\n \
    \   for (int i = 0; i < Q; ++i) {\n        scanf(\"%d %d %d\\n\", &X[i], &Y[i],\
    \ &W[i]);\n        rtree.add_point(X[i], Y[i]);\n    }\n    for (int i = 0; i\
    \ < Q; ++i) {\n        scanf(\"%d \", &c[i]);\n        if (c[i]) {\n         \
    \   scanf(\"%d %d %d %d\\n\", &s[i], &t[i], &u[i], &v[i]);\n        } else {\n\
    \            scanf(\"%d %d %d\\n\", &s[i], &t[i], &u[i]);\n            rtree.add_point(s[i],\
    \ t[i]);\n        }\n    }\n\n    rtree.build();\n\n    for (int i = 0; i < N;\
    \ ++i) rtree.add(X[i], Y[i], W[i]);\n    \n    for (int i = 0; i < Q; ++i) {\n\
    \        if (c[i]) {\n            printf(\"%lld\\n\", rtree.sum(s[i], t[i], u[i],\
    \ v[i]));\n        } else {\n            rtree.add(s[i], t[i], u[i]);\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/data-structure-2d/RangeTree.hpp
  - src/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 12:50:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_Segtree.test.cpp
---
