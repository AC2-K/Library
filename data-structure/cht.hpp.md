---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo judge/data structure/Line Add Get Min.test.cpp
    title: test/yosupo judge/data structure/Line Add Get Min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: ConvexHullTrick
    links: []
  bundledCode: "#line 1 \"data-structure/cht.hpp\"\ntemplate<typename T = ll, bool\
    \ query_type = false>\nclass CHT {\n\tclass line {\n\tpublic:\n\t\tT a, b;\n\t\
    \tbool is_query;\n\t\tmutable T nxt_a, nxt_b;\n\t\tmutable bool has_nxt;\n\t\t\
    T get(T x)const { return a * x + b; }\n\t\tT get_nxt(T x)const { return nxt_a\
    \ * x + nxt_b; }\n\t\tline(T a, T b, bool q = false) :a(a), b(b), is_query(q),\
    \ has_nxt(false) {}\n\t\tfriend bool operator<(const line& l, const line& r) {\n\
    \t\t\tif (l.is_query) {\n\t\t\t\tif (!r.has_nxt)return true;\n\t\t\t\treturn r.get(l.a)\
    \ < r.get_nxt(l.a);\n\t\t\t}\n\t\t\tif (r.is_query) {\n\t\t\t\tif (!l.has_nxt)return\
    \ false;\n\t\t\t\treturn l.get(r.a) > l.get_nxt(r.a);\n\t\t\t}\n\t\t\treturn l.a\
    \ == r.a ? l.b < r.b : l.a < r.a;\n\t\t}\n\t};\n\n\tset<line> ls;\n\tbool is_needed(const\
    \ typename set<line>::iterator& it) {\n\t\tif (it != ls.begin() && it->a == prev(it)->a){\n\
    \t\t\treturn it->b < prev(it)->b;\n\t\t}\n\t\tif (next(it) != ls.end() && it->a\
    \ == next(it)->a){\n\t\t\treturn it->b < next(it)->b;\n\t\t}\n\t\tif (it == ls.begin()\
    \ || next(it) == ls.end()){\n\t\t\treturn true;\n\t\t}\n\t\t//\u7CBE\u5EA6\u5927\
    \u4E08\u592B...?\n\t\treturn 1.*(it->b - prev(it)->b) * (next(it)->a - it->a)\
    \ < 1.*(it->b - next(it)->b) * (prev(it)->a - it->a);\t\n\t}\n\npublic:\n\tvoid\
    \ add(T a,T b) {\n\t\tif(query_type){\n\t\t\tls.emplace(-a,-b);\n\t\t}else{\n\t\
    \t\tls.emplace(a,b);\n\t\t}\n\n        const line&ln=(query_type?line{-a,-b}:line{a,b});\n\
    \        auto it=ls.find(ln);\n\t\tif (!is_needed(it)) {\n\t\t\tls.erase(it);\n\
    \t\t\treturn;\n\t\t}\n\t\twhile (it != ls.begin() && !is_needed(prev(it))){\n\
    \            ls.erase(prev(it));\n        }\n\t\twhile (next(it) != ls.end() &&\
    \ !is_needed(next(it))){\n            ls.erase(next(it));\n        }\n\t\tif (it\
    \ != ls.begin()) {\n\t\t\tprev(it)->has_nxt = true;\n\t\t\tprev(it)->nxt_a = it->a;\n\
    \t\t\tprev(it)->nxt_b = it->b;\n\t\t}\n\t\tif (next(it) != ls.end()) {\n\t\t\t\
    it->has_nxt = true;\n\t\t\tit->nxt_a = next(it)->a;\n\t\t\tit->nxt_b = next(it)->b;\n\
    \t\t}\n\t}\n\tT operator()(T x) const {\n\t\tconst auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n\n\t\tif (query_type) {\t\n\t\t\treturn -it->a * x - it->b;\n\t\t\
    }\n\t\telse {\n\t\t\treturn it->a * x + it->b;\n\t\t}\n\t}\n};\n///@brief ConvexHullTrick\n"
  code: "template<typename T = ll, bool query_type = false>\nclass CHT {\n\tclass\
    \ line {\n\tpublic:\n\t\tT a, b;\n\t\tbool is_query;\n\t\tmutable T nxt_a, nxt_b;\n\
    \t\tmutable bool has_nxt;\n\t\tT get(T x)const { return a * x + b; }\n\t\tT get_nxt(T\
    \ x)const { return nxt_a * x + nxt_b; }\n\t\tline(T a, T b, bool q = false) :a(a),\
    \ b(b), is_query(q), has_nxt(false) {}\n\t\tfriend bool operator<(const line&\
    \ l, const line& r) {\n\t\t\tif (l.is_query) {\n\t\t\t\tif (!r.has_nxt)return\
    \ true;\n\t\t\t\treturn r.get(l.a) < r.get_nxt(l.a);\n\t\t\t}\n\t\t\tif (r.is_query)\
    \ {\n\t\t\t\tif (!l.has_nxt)return false;\n\t\t\t\treturn l.get(r.a) > l.get_nxt(r.a);\n\
    \t\t\t}\n\t\t\treturn l.a == r.a ? l.b < r.b : l.a < r.a;\n\t\t}\n\t};\n\n\tset<line>\
    \ ls;\n\tbool is_needed(const typename set<line>::iterator& it) {\n\t\tif (it\
    \ != ls.begin() && it->a == prev(it)->a){\n\t\t\treturn it->b < prev(it)->b;\n\
    \t\t}\n\t\tif (next(it) != ls.end() && it->a == next(it)->a){\n\t\t\treturn it->b\
    \ < next(it)->b;\n\t\t}\n\t\tif (it == ls.begin() || next(it) == ls.end()){\n\t\
    \t\treturn true;\n\t\t}\n\t\t//\u7CBE\u5EA6\u5927\u4E08\u592B...?\n\t\treturn\
    \ 1.*(it->b - prev(it)->b) * (next(it)->a - it->a) < 1.*(it->b - next(it)->b)\
    \ * (prev(it)->a - it->a);\t\n\t}\n\npublic:\n\tvoid add(T a,T b) {\n\t\tif(query_type){\n\
    \t\t\tls.emplace(-a,-b);\n\t\t}else{\n\t\t\tls.emplace(a,b);\n\t\t}\n\n      \
    \  const line&ln=(query_type?line{-a,-b}:line{a,b});\n        auto it=ls.find(ln);\n\
    \t\tif (!is_needed(it)) {\n\t\t\tls.erase(it);\n\t\t\treturn;\n\t\t}\n\t\twhile\
    \ (it != ls.begin() && !is_needed(prev(it))){\n            ls.erase(prev(it));\n\
    \        }\n\t\twhile (next(it) != ls.end() && !is_needed(next(it))){\n      \
    \      ls.erase(next(it));\n        }\n\t\tif (it != ls.begin()) {\n\t\t\tprev(it)->has_nxt\
    \ = true;\n\t\t\tprev(it)->nxt_a = it->a;\n\t\t\tprev(it)->nxt_b = it->b;\n\t\t\
    }\n\t\tif (next(it) != ls.end()) {\n\t\t\tit->has_nxt = true;\n\t\t\tit->nxt_a\
    \ = next(it)->a;\n\t\t\tit->nxt_b = next(it)->b;\n\t\t}\n\t}\n\tT operator()(T\
    \ x) const {\n\t\tconst auto& it = ls.lower_bound(line(x, 0, true));\n\n\t\tif\
    \ (query_type) {\t\n\t\t\treturn -it->a * x - it->b;\n\t\t}\n\t\telse {\n\t\t\t\
    return it->a * x + it->b;\n\t\t}\n\t}\n};\n///@brief ConvexHullTrick"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht.hpp
  requiredBy: []
  timestamp: '2023-02-28 21:29:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo judge/data structure/Line Add Get Min.test.cpp
documentation_of: data-structure/cht.hpp
layout: document
redirect_from:
- /library/data-structure/cht.hpp
- /library/data-structure/cht.hpp.html
title: ConvexHullTrick
---
