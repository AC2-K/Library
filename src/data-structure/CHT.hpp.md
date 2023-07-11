---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
    title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-structure/CHT.md
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 2 \"src/data-structure/CHT.hpp\"\n#include <set>\nnamespace\
    \ kyopro {\n\n/**\n * @brief Convex Hull Trick\n * @tparam query_type true\u306B\
    \u3059\u308B\u3068\u30AF\u30A8\u30EA\u3067\u6700\u5927\u5024\u3092\u6C42\u3081\
    \u308B\u3088\u3046\u306B\u5909\u66F4\u3059\u308B\n */\ntemplate <class T = long\
    \ long, bool query_type = false> class CHT {\n    class line {\n    public:\n\
    \        T a, b;\n        bool is_query;\n        mutable T nxt_a, nxt_b;\n  \
    \      mutable bool has_nxt;\n        T get(T x) const { return a * x + b; }\n\
    \        T get_nxt(T x) const { return nxt_a * x + nxt_b; }\n        line(T a,\
    \ T b, bool q = false)\n            : a(a), b(b), is_query(q), has_nxt(false)\
    \ {}\n        friend bool operator<(const line& l, const line& r) {\n        \
    \    if (l.is_query) {\n                if (!r.has_nxt) return true;\n       \
    \         return r.get(l.a) < r.get_nxt(l.a);\n            }\n            if (r.is_query)\
    \ {\n                if (!l.has_nxt) return false;\n                return l.get(r.a)\
    \ > l.get_nxt(r.a);\n            }\n            return l.a == r.a ? l.b < r.b\
    \ : l.a < r.a;\n        }\n    };\n\n    std::set<line> ls;\n    bool is_needed(const\
    \ typename std::set<line>::iterator& it) {\n        if (it != ls.begin() && it->a\
    \ == prev(it)->a) {\n            return it->b < prev(it)->b;\n        }\n    \
    \    if (next(it) != ls.end() && it->a == next(it)->a) {\n            return it->b\
    \ < next(it)->b;\n        }\n        if (it == ls.begin() || next(it) == ls.end())\
    \ {\n            return true;\n        }\n        return 1. * (it->b - prev(it)->b)\
    \ * (next(it)->a - it->a) <\n               1. * (it->b - next(it)->b) * (prev(it)->a\
    \ - it->a);\n    }\n\npublic:\n    void insert(T a, T b) {\n        if (query_type)\
    \ {\n            ls.emplace(-a, -b);\n        } else {\n            ls.emplace(a,\
    \ b);\n        }\n\n        const line& ln = (query_type ? line{-a, -b} : line{a,\
    \ b});\n        auto it = ls.find(ln);\n        if (!is_needed(it)) {\n      \
    \      ls.erase(it);\n            return;\n        }\n        while (it != ls.begin()\
    \ && !is_needed(prev(it))) {\n            ls.erase(prev(it));\n        }\n   \
    \     while (next(it) != ls.end() && !is_needed(next(it))) {\n            ls.erase(next(it));\n\
    \        }\n        if (it != ls.begin()) {\n            prev(it)->has_nxt = true;\n\
    \            prev(it)->nxt_a = it->a;\n            prev(it)->nxt_b = it->b;\n\
    \        }\n        if (next(it) != ls.end()) {\n            it->has_nxt = true;\n\
    \            it->nxt_a = next(it)->a;\n            it->nxt_b = next(it)->b;\n\
    \        }\n    }\n    T operator()(T x) const {\n        const auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n\n        if (query_type) {\n            return -it->a * x - it->b;\n\
    \        } else {\n            return it->a * x + it->b;\n        }\n    }\n};\n\
    \n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/CHT.md\n */\n"
  code: "#pragma once\n#include <set>\nnamespace kyopro {\n\n/**\n * @brief Convex\
    \ Hull Trick\n * @tparam query_type true\u306B\u3059\u308B\u3068\u30AF\u30A8\u30EA\
    \u3067\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\u3088\u3046\u306B\u5909\u66F4\
    \u3059\u308B\n */\ntemplate <class T = long long, bool query_type = false> class\
    \ CHT {\n    class line {\n    public:\n        T a, b;\n        bool is_query;\n\
    \        mutable T nxt_a, nxt_b;\n        mutable bool has_nxt;\n        T get(T\
    \ x) const { return a * x + b; }\n        T get_nxt(T x) const { return nxt_a\
    \ * x + nxt_b; }\n        line(T a, T b, bool q = false)\n            : a(a),\
    \ b(b), is_query(q), has_nxt(false) {}\n        friend bool operator<(const line&\
    \ l, const line& r) {\n            if (l.is_query) {\n                if (!r.has_nxt)\
    \ return true;\n                return r.get(l.a) < r.get_nxt(l.a);\n        \
    \    }\n            if (r.is_query) {\n                if (!l.has_nxt) return\
    \ false;\n                return l.get(r.a) > l.get_nxt(r.a);\n            }\n\
    \            return l.a == r.a ? l.b < r.b : l.a < r.a;\n        }\n    };\n\n\
    \    std::set<line> ls;\n    bool is_needed(const typename std::set<line>::iterator&\
    \ it) {\n        if (it != ls.begin() && it->a == prev(it)->a) {\n           \
    \ return it->b < prev(it)->b;\n        }\n        if (next(it) != ls.end() &&\
    \ it->a == next(it)->a) {\n            return it->b < next(it)->b;\n        }\n\
    \        if (it == ls.begin() || next(it) == ls.end()) {\n            return true;\n\
    \        }\n        return 1. * (it->b - prev(it)->b) * (next(it)->a - it->a)\
    \ <\n               1. * (it->b - next(it)->b) * (prev(it)->a - it->a);\n    }\n\
    \npublic:\n    void insert(T a, T b) {\n        if (query_type) {\n          \
    \  ls.emplace(-a, -b);\n        } else {\n            ls.emplace(a, b);\n    \
    \    }\n\n        const line& ln = (query_type ? line{-a, -b} : line{a, b});\n\
    \        auto it = ls.find(ln);\n        if (!is_needed(it)) {\n            ls.erase(it);\n\
    \            return;\n        }\n        while (it != ls.begin() && !is_needed(prev(it)))\
    \ {\n            ls.erase(prev(it));\n        }\n        while (next(it) != ls.end()\
    \ && !is_needed(next(it))) {\n            ls.erase(next(it));\n        }\n   \
    \     if (it != ls.begin()) {\n            prev(it)->has_nxt = true;\n       \
    \     prev(it)->nxt_a = it->a;\n            prev(it)->nxt_b = it->b;\n       \
    \ }\n        if (next(it) != ls.end()) {\n            it->has_nxt = true;\n  \
    \          it->nxt_a = next(it)->a;\n            it->nxt_b = next(it)->b;\n  \
    \      }\n    }\n    T operator()(T x) const {\n        const auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n\n        if (query_type) {\n            return -it->a * x - it->b;\n\
    \        } else {\n            return it->a * x + it->b;\n        }\n    }\n};\n\
    \n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/CHT.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/CHT.hpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
documentation_of: src/data-structure/CHT.hpp
layout: document
redirect_from:
- /library/src/data-structure/CHT.hpp
- /library/src/data-structure/CHT.hpp.html
title: Convex Hull Trick
---
