---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
    title: test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Merge Sort Tree
    links: []
  bundledCode: "#line 2 \"src/data-structure/data-structure-2d/merge-sort-tree.hpp\"\
    \n#include <algorithm>\n#include <iterator>\n#include <utility>\n#include <vector>\n\
    \nnamespace kyopro {\ntemplate <typename Key_x, typename Key_y, typename Value>\n\
    class merge_sort_tree {\n    int lg, sz;\n\n    struct point {\n        Key_x\
    \ x;\n        Key_y y;\n        Value v;\n        point(Key_x x, Key_y y, Value\
    \ v) : x(x), y(y), v(v) {}\n    };\n\n    std::vector<Key_x> xs;\n    std::vector<std::vector<Key_y>>\
    \ ys;  // x \u56FA\u5B9A\u3057\u305F\u3068\u304D\u306E (y, value)\n    std::vector<std::vector<Value>>\
    \ s;   // \u7D2F\u7A4D\u548C\n\n    std::vector<point> points;\n\npublic:\n  \
    \  merge_sort_tree() = default;\n\n    void add_point(Key_x x, Key_y y, Value\
    \ v) { points.emplace_back(x, y, v); }\n\n    void build() {\n        xs.resize(points.size());\n\
    \        for (int i = 0; i < (int)points.size(); ++i) xs[i] = points[i].x;\n\n\
    \        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n\n        sz = 1, lg = 0;\n        while (sz <= (int)xs.size())\
    \ {\n            sz <<= 1;\n            lg++;\n        }\n\n        std::vector<std::vector<std::pair<Key_y,\
    \ Value>>> d(sz << 1);\n        s.resize(sz << 1), ys.resize(sz << 1);\n\n   \
    \     for (int i = 0; i < (int)points.size(); i++) {\n            int p = std::lower_bound(xs.begin(),\
    \ xs.end(), points[i].x) -\n                    xs.begin();\n            d[sz\
    \ + p].emplace_back(points[i].y, points[i].v);\n        }\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            std::sort(d[i + sz].begin(), d[i + sz].end());\n\
    \        }\n\n        for (int i = sz - 1; i; --i) {\n            int l = (i <<\
    \ 1 | 0), r = (i << 1 | 1);\n\n            std::merge(d[l].begin(), d[l].end(),\
    \ d[r].begin(), d[r].end(),\n                       std::back_inserter(d[i]));\n\
    \        }\n\n        for (int i = 1; i < (int)2 * sz; ++i) {\n            ys[i].resize(d[i].size());\n\
    \            s[i].resize(d[i].size() + 1);\n\n            for (int j = 0; j <\
    \ (int)d[i].size(); ++j) {\n                ys[i][j] = d[i][j].first;\n      \
    \          s[i][j + 1] = s[i][j] + d[i][j].second;\n            }\n        }\n\
    \    }\n\nprivate:\n    Value get(int i, Key_y lower, Key_y upper) {\n       \
    \ int l =\n            std::lower_bound(ys[i].begin(), ys[i].end(), lower) - ys[i].begin();\n\
    \        int r =\n            std::lower_bound(ys[i].begin(), ys[i].end(), upper)\
    \ - ys[i].begin();\n\n        return s[i][r] - s[i][l];\n    }\n\npublic:\n  \
    \  Value fold(Key_x l, Key_y r, Key_y lower, Key_y upper) {\n        l = std::lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        r = std::lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n\n        l += sz, r += sz;\n\n        Value sum = 0;\n\n\
    \        while (l != r) {\n            if (l & 1) {\n                sum += get(l++,\
    \ lower, upper);\n            }\n            if (r & 1) {\n                sum\
    \ += get(--r, lower, upper);\n            }\n            l >>= 1, r >>= 1;\n \
    \       }\n\n        return sum;\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Merge Sort Tree\n*/\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <utility>\n\
    #include <vector>\n\nnamespace kyopro {\ntemplate <typename Key_x, typename Key_y,\
    \ typename Value>\nclass merge_sort_tree {\n    int lg, sz;\n\n    struct point\
    \ {\n        Key_x x;\n        Key_y y;\n        Value v;\n        point(Key_x\
    \ x, Key_y y, Value v) : x(x), y(y), v(v) {}\n    };\n\n    std::vector<Key_x>\
    \ xs;\n    std::vector<std::vector<Key_y>> ys;  // x \u56FA\u5B9A\u3057\u305F\u3068\
    \u304D\u306E (y, value)\n    std::vector<std::vector<Value>> s;   // \u7D2F\u7A4D\
    \u548C\n\n    std::vector<point> points;\n\npublic:\n    merge_sort_tree() = default;\n\
    \n    void add_point(Key_x x, Key_y y, Value v) { points.emplace_back(x, y, v);\
    \ }\n\n    void build() {\n        xs.resize(points.size());\n        for (int\
    \ i = 0; i < (int)points.size(); ++i) xs[i] = points[i].x;\n\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \n        sz = 1, lg = 0;\n        while (sz <= (int)xs.size()) {\n          \
    \  sz <<= 1;\n            lg++;\n        }\n\n        std::vector<std::vector<std::pair<Key_y,\
    \ Value>>> d(sz << 1);\n        s.resize(sz << 1), ys.resize(sz << 1);\n\n   \
    \     for (int i = 0; i < (int)points.size(); i++) {\n            int p = std::lower_bound(xs.begin(),\
    \ xs.end(), points[i].x) -\n                    xs.begin();\n            d[sz\
    \ + p].emplace_back(points[i].y, points[i].v);\n        }\n\n        for (int\
    \ i = 0; i < sz; ++i) {\n            std::sort(d[i + sz].begin(), d[i + sz].end());\n\
    \        }\n\n        for (int i = sz - 1; i; --i) {\n            int l = (i <<\
    \ 1 | 0), r = (i << 1 | 1);\n\n            std::merge(d[l].begin(), d[l].end(),\
    \ d[r].begin(), d[r].end(),\n                       std::back_inserter(d[i]));\n\
    \        }\n\n        for (int i = 1; i < (int)2 * sz; ++i) {\n            ys[i].resize(d[i].size());\n\
    \            s[i].resize(d[i].size() + 1);\n\n            for (int j = 0; j <\
    \ (int)d[i].size(); ++j) {\n                ys[i][j] = d[i][j].first;\n      \
    \          s[i][j + 1] = s[i][j] + d[i][j].second;\n            }\n        }\n\
    \    }\n\nprivate:\n    Value get(int i, Key_y lower, Key_y upper) {\n       \
    \ int l =\n            std::lower_bound(ys[i].begin(), ys[i].end(), lower) - ys[i].begin();\n\
    \        int r =\n            std::lower_bound(ys[i].begin(), ys[i].end(), upper)\
    \ - ys[i].begin();\n\n        return s[i][r] - s[i][l];\n    }\n\npublic:\n  \
    \  Value fold(Key_x l, Key_y r, Key_y lower, Key_y upper) {\n        l = std::lower_bound(xs.begin(),\
    \ xs.end(), l) - xs.begin();\n        r = std::lower_bound(xs.begin(), xs.end(),\
    \ r) - xs.begin();\n\n        l += sz, r += sz;\n\n        Value sum = 0;\n\n\
    \        while (l != r) {\n            if (l & 1) {\n                sum += get(l++,\
    \ lower, upper);\n            }\n            if (r & 1) {\n                sum\
    \ += get(--r, lower, upper);\n            }\n            l >>= 1, r >>= 1;\n \
    \       }\n\n        return sum;\n    }\n};\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Merge Sort Tree\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/data-structure-2d/merge-sort-tree.hpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/data_structure/Rectangle-Sum.test.cpp
documentation_of: src/data-structure/data-structure-2d/merge-sort-tree.hpp
layout: document
redirect_from:
- /library/src/data-structure/data-structure-2d/merge-sort-tree.hpp
- /library/src/data-structure/data-structure-2d/merge-sort-tree.hpp.html
title: Merge Sort Tree
---
