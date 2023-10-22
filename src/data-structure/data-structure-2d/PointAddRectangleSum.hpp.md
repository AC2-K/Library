---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data-structure/data-structure-2d/PointAddRectangleSum.hpp\"\
    \n#include <algorithm>\n#line 2 \"src/data-structure/BIT.hpp\"\n#include <vector>\n\
    namespace kyopro {\n/**\n * @brief Binary Index Tree\n */\ntemplate <typename\
    \ T> class BIT {\n    std::vector<T> bit;\n    int n;\n\npublic:\n    explicit\
    \ BIT() {}\n    explicit BIT(int n) : n(n), bit(n + 1, T()) {}\n    void add(int\
    \ p, T w) {\n        p++;\n        for (int x = p; x <= n; x += x & -x) {\n  \
    \          bit[x] += w;\n        }\n    }\n\n    T sum(int p) const {\n      \
    \  T s = 0;\n\n        for (int x = p; x > 0; x -= x & -x) {\n            s +=\
    \ bit[x];\n        }\n        return s;\n    }\n\n    T sum(int l, int r) const\
    \ { return sum(r) - sum(l); }\n\n    int lower_bound(T w) const {\n        if\
    \ (w <= 0) return 0;\n\n        int x = 0;\n        int k = 1;\n        while\
    \ (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n            if (x + k <=\
    \ n && bit[x + k] < w) {\n                w -= bit[x + k];\n                x\
    \ += k;\n            }\n        }\n\n        return x + 1;\n    }\n\n    T operator[](int\
    \ i) { return sum(i + 1) - sum(i); }\n    void update(int i, T v) { add(i, -sum(i\
    \ + 1) + sum(i) + v); }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n#line 4 \"src/data-structure/data-structure-2d/PointAddRectangleSum.hpp\"\
    \nnamespace kyopro {\ntemplate <typename T, typename S> class PointAddRectangleSum\
    \ {\n    std::vector<BIT<S>> dat;\n    std::vector<std::vector<T>> ys;\n\n   \
    \ T n;\n    std::vector<std::pair<T, T>> ps;\n\npublic:\n    void add_point(T\
    \ x, T y) { ps.emplace_back(x, y); }\n\n    void build() {\n        std::sort(ps.begin(),\
    \ ps.end());\n        ps.erase(std::unique(ps.begin(), ps.end()), ps.end());\n\
    \n        n = ps.size();\n        dat.resize(2 * n);\n\n        ys.resize(2 *\
    \ n);\n        for (int i = 0; i < n; ++i) {\n            ys[i + n].emplace_back(ps[i].second);\n\
    \            dat[i + n] = BIT<S>(1);\n        }\n\n        for (int i = n - 1;\
    \ i > 0; --i) {\n            ys[i].resize(ys[i << 1 | 0].size() + ys[i << 1 |\
    \ 1].size());\n            std::merge(ys[i << 1 | 0].begin(), ys[i << 1 | 0].end(),\n\
    \                       ys[i << 1 | 1].begin(), ys[i << 1 | 1].end(),\n      \
    \                 ys[i].begin());\n\n            ys[i].erase(std::unique(ys[i].begin(),\
    \ ys[i].end()), ys[i].end());\n            dat[i] = BIT<S>(ys[i].size());\n  \
    \      }\n    }\n\nprivate:\n    int id(T x) const {\n        return std::lower_bound(\n\
    \                   ps.begin(), ps.end(), std::make_pair(x, T()),\n          \
    \         [](const std::pair<T, T>& a, const std::pair<T, T>& b) {\n         \
    \              return a.first < b.first;\n                   }) -\n          \
    \     ps.begin();\n    }\n\n    int id(int i, T y) const {\n        return std::lower_bound(ys[i].begin(),\
    \ ys[i].end(), y) - ys[i].begin();\n    }\n\npublic:\n    void add(T x, T y, S\
    \ w) {\n        int i = std::lower_bound(ps.begin(), ps.end(), std::make_pair(x,\
    \ y)) -\n                ps.begin();\n\n        for (i += n; i; i >>= 1) {\n \
    \           dat[i].add(id(i, y), w);\n        }\n    }\n\n    S sum(T xl, T yl,\
    \ T xr, T yr) {\n        S sum = 0;\n\n        int a = id(xl), b = id(xr);\n \
    \       a += n, b += n;\n        while (a < b) {\n            if (a & 1) {\n \
    \               sum += dat[a].sum(id(a, yl), id(a, yr));\n                ++a;\n\
    \            }\n            if (b & 1) {\n                --b;\n             \
    \   sum += dat[b].sum(id(b, yl), id(b, yr));\n            }\n\n            a >>=\
    \ 1, b >>= 1;\n        }\n\n        return sum;\n    }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <algorithm>\n#include \"../BIT.hpp\"\nnamespace kyopro\
    \ {\ntemplate <typename T, typename S> class PointAddRectangleSum {\n    std::vector<BIT<S>>\
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
    \      dat[i] = BIT<S>(ys[i].size());\n        }\n    }\n\nprivate:\n    int id(T\
    \ x) const {\n        return std::lower_bound(\n                   ps.begin(),\
    \ ps.end(), std::make_pair(x, T()),\n                   [](const std::pair<T,\
    \ T>& a, const std::pair<T, T>& b) {\n                       return a.first <\
    \ b.first;\n                   }) -\n               ps.begin();\n    }\n\n   \
    \ int id(int i, T y) const {\n        return std::lower_bound(ys[i].begin(), ys[i].end(),\
    \ y) - ys[i].begin();\n    }\n\npublic:\n    void add(T x, T y, S w) {\n     \
    \   int i = std::lower_bound(ps.begin(), ps.end(), std::make_pair(x, y)) -\n \
    \               ps.begin();\n\n        for (i += n; i; i >>= 1) {\n          \
    \  dat[i].add(id(i, y), w);\n        }\n    }\n\n    S sum(T xl, T yl, T xr, T\
    \ yr) {\n        S sum = 0;\n\n        int a = id(xl), b = id(xr);\n        a\
    \ += n, b += n;\n        while (a < b) {\n            if (a & 1) {\n         \
    \       sum += dat[a].sum(id(a, yl), id(a, yr));\n                ++a;\n     \
    \       }\n            if (b & 1) {\n                --b;\n                sum\
    \ += dat[b].sum(id(b, yl), id(b, yr));\n            }\n\n            a >>= 1,\
    \ b >>= 1;\n        }\n\n        return sum;\n    }\n};\n};  // namespace kyopro"
  dependsOn:
  - src/data-structure/BIT.hpp
  isVerificationFile: false
  path: src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
  requiredBy: []
  timestamp: '2023-10-14 19:23:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
layout: document
redirect_from:
- /library/src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
- /library/src/data-structure/data-structure-2d/PointAddRectangleSum.hpp.html
title: src/data-structure/data-structure-2d/PointAddRectangleSum.hpp
---
