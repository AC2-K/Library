---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/CHT.md
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 1 \"src/data-structure/CHT.hpp\"\n/// @brief Convex Hull Trick\n\
    /// @tparam T \n/// @tparam query_type \u30AF\u30A8\u30EA\u306E\u30BF\u30A4\u30D7\
    .true\u306B\u3059\u308B\u3068\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\u3088\u3046\
    \u306B\u5909\u66F4\u3059\u308B\n/// @docs docs/data-structure/CHT.md\ntemplate<class\
    \ T = ll, bool query_type = false>\nclass CHT {\n\tclass line {\n\tpublic:\n\t\
    \tT a, b;\n\t\tbool is_query;\n\t\tmutable T nxt_a, nxt_b;\n\t\tmutable bool has_nxt;\n\
    \t\tT get(T x)const { return a * x + b; }\n\t\tT get_nxt(T x)const { return nxt_a\
    \ * x + nxt_b; }\n\t\tline(T a, T b, bool q = false) :a(a), b(b), is_query(q),\
    \ has_nxt(false) {}\n\t\tfriend bool operator<(const line& l, const line& r) {\n\
    \t\t\tif (l.is_query) {\n\t\t\t\tif (!r.has_nxt)return true;\n\t\t\t\treturn r.get(l.a)\
    \ < r.get_nxt(l.a);\n\t\t\t}\n\t\t\tif (r.is_query) {\n\t\t\t\tif (!l.has_nxt)return\
    \ false;\n\t\t\t\treturn l.get(r.a) > l.get_nxt(r.a);\n\t\t\t}\n\t\t\treturn l.a\
    \ == r.a ? l.b < r.b : l.a < r.a;\n\t\t}\n\t};\n\n\tset<line> ls;\n\tbool is_needed(const\
    \ typename set<line>::iterator& it) {\n\t\tif (it != ls.begin() && it->a == prev(it)->a){\n\
    \t\t\treturn it->b < prev(it)->b;\n\t\t}\n\t\tif (next(it) != ls.end() && it->a\
    \ == next(it)->a){\n\t\t\treturn it->b < next(it)->b;\n\t\t}\n\t\tif (it == ls.begin()\
    \ || next(it) == ls.end()){\n\t\t\treturn true;\n\t\t}\n        return 1. * (it->b\
    \ - prev(it)->b) * (next(it)->a - it->a) <\n            1. * (it->b - next(it)->b)\
    \ * (prev(it)->a - it->a);\n    }\n\npublic:\n\tvoid add(T a,T b) {\n\t\tif(query_type){\n\
    \t\t\tls.emplace(-a,-b);\n\t\t}\n\t\telse{\n\t\t\tls.emplace(a,b);\n\t\t}\n\n\
    \        const line&ln=(query_type?line{-a,-b}:line{a,b});\n        auto it=ls.find(ln);\n\
    \t\tif (!is_needed(it)) {\n\t\t\tls.erase(it);\n\t\t\treturn;\n\t\t}\n\t\twhile\
    \ (it != ls.begin() && !is_needed(prev(it))){\n            ls.erase(prev(it));\n\
    \        }\n\t\twhile (next(it) != ls.end() && !is_needed(next(it))){\n      \
    \      ls.erase(next(it));\n        }\n\t\tif (it != ls.begin()) {\n\t\t\tprev(it)->has_nxt\
    \ = true;\n\t\t\tprev(it)->nxt_a = it->a;\n\t\t\tprev(it)->nxt_b = it->b;\n\t\t\
    }\n\t\tif (next(it) != ls.end()) {\n\t\t\tit->has_nxt = true;\n\t\t\tit->nxt_a\
    \ = next(it)->a;\n\t\t\tit->nxt_b = next(it)->b;\n\t\t}\n\t}\n\tT operator()(T\
    \ x) {\n\t\tconst auto& it = ls.lower_bound(line(x, 0, true));\n\n\t\tif (query_type)\
    \ {\t\n\t\t\treturn -it->a * x - it->b;\n\t\t}\n\t\telse {\n\t\t\treturn it->a\
    \ * x + it->b;\n\t\t}\n\t}\n};\n"
  code: "/// @brief Convex Hull Trick\n/// @tparam T \n/// @tparam query_type \u30AF\
    \u30A8\u30EA\u306E\u30BF\u30A4\u30D7.true\u306B\u3059\u308B\u3068\u6700\u5927\u5024\
    \u3092\u6C42\u3081\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\u308B\n/// @docs\
    \ docs/data-structure/CHT.md\ntemplate<class T = ll, bool query_type = false>\n\
    class CHT {\n\tclass line {\n\tpublic:\n\t\tT a, b;\n\t\tbool is_query;\n\t\t\
    mutable T nxt_a, nxt_b;\n\t\tmutable bool has_nxt;\n\t\tT get(T x)const { return\
    \ a * x + b; }\n\t\tT get_nxt(T x)const { return nxt_a * x + nxt_b; }\n\t\tline(T\
    \ a, T b, bool q = false) :a(a), b(b), is_query(q), has_nxt(false) {}\n\t\tfriend\
    \ bool operator<(const line& l, const line& r) {\n\t\t\tif (l.is_query) {\n\t\t\
    \t\tif (!r.has_nxt)return true;\n\t\t\t\treturn r.get(l.a) < r.get_nxt(l.a);\n\
    \t\t\t}\n\t\t\tif (r.is_query) {\n\t\t\t\tif (!l.has_nxt)return false;\n\t\t\t\
    \treturn l.get(r.a) > l.get_nxt(r.a);\n\t\t\t}\n\t\t\treturn l.a == r.a ? l.b\
    \ < r.b : l.a < r.a;\n\t\t}\n\t};\n\n\tset<line> ls;\n\tbool is_needed(const typename\
    \ set<line>::iterator& it) {\n\t\tif (it != ls.begin() && it->a == prev(it)->a){\n\
    \t\t\treturn it->b < prev(it)->b;\n\t\t}\n\t\tif (next(it) != ls.end() && it->a\
    \ == next(it)->a){\n\t\t\treturn it->b < next(it)->b;\n\t\t}\n\t\tif (it == ls.begin()\
    \ || next(it) == ls.end()){\n\t\t\treturn true;\n\t\t}\n        return 1. * (it->b\
    \ - prev(it)->b) * (next(it)->a - it->a) <\n            1. * (it->b - next(it)->b)\
    \ * (prev(it)->a - it->a);\n    }\n\npublic:\n\tvoid add(T a,T b) {\n\t\tif(query_type){\n\
    \t\t\tls.emplace(-a,-b);\n\t\t}\n\t\telse{\n\t\t\tls.emplace(a,b);\n\t\t}\n\n\
    \        const line&ln=(query_type?line{-a,-b}:line{a,b});\n        auto it=ls.find(ln);\n\
    \t\tif (!is_needed(it)) {\n\t\t\tls.erase(it);\n\t\t\treturn;\n\t\t}\n\t\twhile\
    \ (it != ls.begin() && !is_needed(prev(it))){\n            ls.erase(prev(it));\n\
    \        }\n\t\twhile (next(it) != ls.end() && !is_needed(next(it))){\n      \
    \      ls.erase(next(it));\n        }\n\t\tif (it != ls.begin()) {\n\t\t\tprev(it)->has_nxt\
    \ = true;\n\t\t\tprev(it)->nxt_a = it->a;\n\t\t\tprev(it)->nxt_b = it->b;\n\t\t\
    }\n\t\tif (next(it) != ls.end()) {\n\t\t\tit->has_nxt = true;\n\t\t\tit->nxt_a\
    \ = next(it)->a;\n\t\t\tit->nxt_b = next(it)->b;\n\t\t}\n\t}\n\tT operator()(T\
    \ x) {\n\t\tconst auto& it = ls.lower_bound(line(x, 0, true));\n\n\t\tif (query_type)\
    \ {\t\n\t\t\treturn -it->a * x - it->b;\n\t\t}\n\t\telse {\n\t\t\treturn it->a\
    \ * x + it->b;\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/CHT.hpp
  requiredBy: []
  timestamp: '2023-03-27 01:42:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/CHT.hpp
layout: document
redirect_from:
- /library/src/data-structure/CHT.hpp
- /library/src/data-structure/CHT.hpp.html
title: Convex Hull Trick
---
