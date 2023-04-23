---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure-2d/PointAddRectangleSum.hpp
    title: src/data-structure-2d/PointAddRectangleSum.hpp
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure-2d/PointAddRectangleSum.hpp\"\
    \n#include <algorithm>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/// @brief Binary Index Tree\ntemplate <typename T, typename\
    \ SumT = T>\nclass BIT {\n    std::vector<SumT> bit;\n    int n;\n\npublic:\n\
    \    explicit BIT() {}\n    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n \
    \   void add(int p, const T& w) {\n        p++;\n        for (int x = p; x <=\
    \ n; x += x & -x) {\n            bit[x] += w;\n        }\n    }\n\n    SumT sum(int\
    \ p) const {\n        T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x)\
    \ {\n            s += bit[x];\n        }\n        return s;\n    }\n\n    inline\
    \ SumT sum(int l, int r) const { return sum(r) - sum(l); }\n\n    int lower_bound(SumT\
    \ w) const {\n        if (w <= 0) return 0;\n\n        int x = 0;\n        int\
    \ k = 1;\n        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n \
    \           if (x + k <= n && bit[x + k] < w) {\n                w -= bit[x +\
    \ k];\n                x += k;\n            }\n        }\n\n        return x +\
    \ 1;\n    }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/BIT.md\n\
    #line 4 \"src/data-structure-2d/PointAddRectangleSum.hpp\"\nnamespace kyopro {\n\
    template <typename T, typename S>\nclass PointAddRectangleSum {\n    std::vector<BIT<S>>\
    \ dat;\n    std::vector<std::vector<T>> ys;\n\n    T n;\n    std::vector<std::pair<T,\
    \ T>> ps;\n\npublic:\n    void add_point(T x, T y) { ps.emplace_back(x, y); }\n\
    \n    void build() {\n        std::sort(ps.begin(), ps.end());\n        ps.erase(std::unique(ps.begin(),\
    \ ps.end()), ps.end());\n\n        n = ps.size();\n        dat.resize(2 * n);\n\
    \n        ys.resize(2 * n);\n        for (int i = 0; i < n; ++i) {\n         \
    \   ys[i + n].emplace_back(ps[i].second);\n            dat[i + n] = BIT<S>(1);\n\
    \        }\n\n        for (int i = n - 1; i > 0; --i) {\n            ys[i].resize(ys[i\
    \ << 1 | 0].size() + ys[i << 1 | 1].size());\n            std::merge(ys[i << 1\
    \ | 0].begin(), ys[i << 1 | 0].end(),\n                       ys[i << 1 | 1].begin(),\
    \ ys[i << 1 | 1].end(),\n                       ys[i].begin());\n\n          \
    \  ys[i].erase(std::unique(ys[i].begin(), ys[i].end()), ys[i].end());\n      \
    \      dat[i] = BIT<S>(ys[i].size());\n        }\n    }\n\n    inline int id(T\
    \ x) const {\n        return std::lower_bound(\n                   ps.begin(),\
    \ ps.end(), std::make_pair(x, T()),\n                   [](const std::pair<T,\
    \ T>& a, const std::pair<T, T>& b) {\n                       return a.first <\
    \ b.first;\n                   }) -\n               ps.begin();\n    }\n\n   \
    \ inline int id(int i, T y) const {\n        return std::lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n    }\n\n    void add(T x, T y, S w) {\n \
    \       int i = std::lower_bound(ps.begin(), ps.end(), std::make_pair(x, y)) -\n\
    \                ps.begin();\n\n        for (i += n; i; i >>= 1) {\n         \
    \   dat[i].add(id(i, y), w);\n        }\n    }\n\n    S sum(T xl, T yl, T xr,\
    \ T yr) {\n        S sum = 0;\n\n        int a = id(xl), b = id(xr);\n       \
    \ a += n, b += n;\n        while (a < b) {\n            if (a & 1) {\n       \
    \         sum += dat[a].sum(id(a, yl), id(a, yr));\n                ++a;\n   \
    \         }\n            if (b & 1) {\n                --b;\n                sum\
    \ += dat[b].sum(id(b, yl), id(b, yr));\n            }\n\n            a >>= 1,\
    \ b >>= 1;\n        }\n\n        return sum;\n    }\n};\n};  // namespace kyopro\n\
    #line 4 \"test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp\"\
    \nint main() {\n    using namespace std;\n    kyopro::PointAddRectangleSum<int,\
    \ long long> rtree;\n\n    int N, Q;\n    scanf(\"%d %d\\n\", &N, &Q);\n    int\
    \ X[N], Y[N], W[N];\n    int c[Q];\n    int s[Q], t[Q], u[Q], v[Q];\n    for (int\
    \ i = 0; i < N; ++i) {\n        scanf(\"%d %d %d\\n\", &X[i], &Y[i], &W[i]);\n\
    \        rtree.add_point(X[i], Y[i]);\n    }\n    for (int i = 0; i < Q; ++i)\
    \ {\n        scanf(\"%d \", &c[i]);\n        if (c[i]) {\n            scanf(\"\
    %d %d %d %d\\n\", &s[i], &t[i], &u[i], &v[i]);\n        } else {\n           \
    \ scanf(\"%d %d %d\\n\", &s[i], &t[i], &u[i]);\n            rtree.add_point(s[i],\
    \ t[i]);\n        }\n    }\n\n    rtree.build();\n\n    for (int i = 0; i < N;\
    \ ++i) rtree.add(X[i], Y[i], W[i]);\n\n    for (int i = 0; i < Q; ++i) {\n   \
    \     if (c[i]) {\n            printf(\"%lld\\n\", rtree.sum(s[i], t[i], u[i],\
    \ v[i]));\n        } else {\n            rtree.add(s[i], t[i], u[i]);\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure-2d/PointAddRectangleSum.hpp\"\
    \nint main() {\n    using namespace std;\n    kyopro::PointAddRectangleSum<int,\
    \ long long> rtree;\n\n    int N, Q;\n    scanf(\"%d %d\\n\", &N, &Q);\n    int\
    \ X[N], Y[N], W[N];\n    int c[Q];\n    int s[Q], t[Q], u[Q], v[Q];\n    for (int\
    \ i = 0; i < N; ++i) {\n        scanf(\"%d %d %d\\n\", &X[i], &Y[i], &W[i]);\n\
    \        rtree.add_point(X[i], Y[i]);\n    }\n    for (int i = 0; i < Q; ++i)\
    \ {\n        scanf(\"%d \", &c[i]);\n        if (c[i]) {\n            scanf(\"\
    %d %d %d %d\\n\", &s[i], &t[i], &u[i], &v[i]);\n        } else {\n           \
    \ scanf(\"%d %d %d\\n\", &s[i], &t[i], &u[i]);\n            rtree.add_point(s[i],\
    \ t[i]);\n        }\n    }\n\n    rtree.build();\n\n    for (int i = 0; i < N;\
    \ ++i) rtree.add(X[i], Y[i], W[i]);\n\n    for (int i = 0; i < Q; ++i) {\n   \
    \     if (c[i]) {\n            printf(\"%lld\\n\", rtree.sum(s[i], t[i], u[i],\
    \ v[i]));\n        } else {\n            rtree.add(s[i], t[i], u[i]);\n      \
    \  }\n    }\n}\n"
  dependsOn:
  - src/data-structure-2d/PointAddRectangleSum.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 12:50:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Rectangle_Sum_BIT.test.cpp
---
