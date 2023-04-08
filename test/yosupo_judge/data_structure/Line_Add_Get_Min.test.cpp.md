---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/CHT.hpp
    title: Convex Hull Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include<iostream>\n\
    #line 2 \"src/data-structure/CHT.hpp\"\n#include <set>\nnamespace kyopro {\n\n\
    /// @brief Convex Hull Trick\ntemplate <class T = long long, bool query_type =\
    \ false> class CHT {\n    class line {\n      public:\n        T a, b;\n     \
    \   bool is_query;\n        mutable T nxt_a, nxt_b;\n        mutable bool has_nxt;\n\
    \        T get(T x) const { return a * x + b; }\n        T get_nxt(T x) const\
    \ { return nxt_a * x + nxt_b; }\n        line(T a, T b, bool q = false)\n    \
    \        : a(a), b(b), is_query(q), has_nxt(false) {}\n        friend bool operator<(const\
    \ line& l, const line& r) {\n            if (l.is_query) {\n                if\
    \ (!r.has_nxt) return true;\n                return r.get(l.a) < r.get_nxt(l.a);\n\
    \            }\n            if (r.is_query) {\n                if (!l.has_nxt)\
    \ return false;\n                return l.get(r.a) > l.get_nxt(r.a);\n       \
    \     }\n            return l.a == r.a ? l.b < r.b : l.a < r.a;\n        }\n \
    \   };\n\n    std::set<line> ls;\n    bool is_needed(const typename std::set<line>::iterator&\
    \ it) {\n        if (it != ls.begin() && it->a == prev(it)->a) {\n           \
    \ return it->b < prev(it)->b;\n        }\n        if (next(it) != ls.end() &&\
    \ it->a == next(it)->a) {\n            return it->b < next(it)->b;\n        }\n\
    \        if (it == ls.begin() || next(it) == ls.end()) {\n            return true;\n\
    \        }\n        return 1. * (it->b - prev(it)->b) * (next(it)->a - it->a)\
    \ <\n               1. * (it->b - next(it)->b) * (prev(it)->a - it->a);\n    }\n\
    \n  public:\n    void insert(T a, T b) {\n        if (query_type) {\n        \
    \    ls.emplace(-a, -b);\n        } else {\n            ls.emplace(a, b);\n  \
    \      }\n\n        const line& ln = (query_type ? line{-a, -b} : line{a, b});\n\
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
    \n};  // namespace kyopro\n\n/// @docs docs/data-structure/CHT.md\n#line 4 \"\
    test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\nusing namespace\
    \ std;\nint main(){\n    int n,q;\n    scanf(\"%d%d\",&n,&q);\n\n    kyopro::CHT<long\
    \ long> cht;    \n    for(int i=0;i<n;i++){\n        long long a,b;\n        scanf(\"\
    %lld%lld\",&a,&b);\n        cht.insert(a,b);\n    }\n    while(q--){\n       \
    \ int t;\n        scanf(\"%d\",&t);\n        if(!t){\n            long long a,b;\n\
    \            scanf(\"%lld%lld\",&a,&b);\n            cht.insert(a,b);\n      \
    \  }else{\n            long long x;\n            scanf(\"%lld\",&x);\n       \
    \     printf(\"%lld\\n\",cht(x));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include<iostream>\n\
    #include\"../../../src/data-structure/CHT.hpp\"\nusing namespace std;\nint main(){\n\
    \    int n,q;\n    scanf(\"%d%d\",&n,&q);\n\n    kyopro::CHT<long long> cht; \
    \   \n    for(int i=0;i<n;i++){\n        long long a,b;\n        scanf(\"%lld%lld\"\
    ,&a,&b);\n        cht.insert(a,b);\n    }\n    while(q--){\n        int t;\n \
    \       scanf(\"%d\",&t);\n        if(!t){\n            long long a,b;\n     \
    \       scanf(\"%lld%lld\",&a,&b);\n            cht.insert(a,b);\n        }else{\n\
    \            long long x;\n            scanf(\"%lld\",&x);\n            printf(\"\
    %lld\\n\",cht(x));\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/CHT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
---
