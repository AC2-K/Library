---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/CHT.hpp
    title: Convex Hull Trick
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line\
    \ 2 \"src/template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"src/data-structure/CHT.hpp\"\
    \n/// @brief Convex Hull Trick\n/// @tparam T \n/// @tparam query_type \u30AF\u30A8\
    \u30EA\u306E\u30BF\u30A4\u30D7.true\u306B\u3059\u308B\u3068\u6700\u5927\u5024\u3092\
    \u6C42\u3081\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\u308B\n/// @docs docs/data-structure/CHT.md\n\
    template<class T = ll, bool query_type = false>\nclass CHT {\n\tclass line {\n\
    \tpublic:\n\t\tT a, b;\n\t\tbool is_query;\n\t\tmutable T nxt_a, nxt_b;\n\t\t\
    mutable bool has_nxt;\n\t\tT get(T x)const { return a * x + b; }\n\t\tT get_nxt(T\
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
    \t\treturn true;\n\t\t}\n        return 1. * (it->b - prev(it)->b) * (next(it)->a\
    \ - it->a) <\n            1. * (it->b - next(it)->b) * (prev(it)->a - it->a);\n\
    \    }\n\npublic:\n\tvoid add(T a,T b) {\n\t\tif(query_type){\n\t\t\tls.emplace(-a,-b);\n\
    \t\t}\n\t\telse{\n\t\t\tls.emplace(a,b);\n\t\t}\n\n        const line&ln=(query_type?line{-a,-b}:line{a,b});\n\
    \        auto it=ls.find(ln);\n\t\tif (!is_needed(it)) {\n\t\t\tls.erase(it);\n\
    \t\t\treturn;\n\t\t}\n\t\twhile (it != ls.begin() && !is_needed(prev(it))){\n\
    \            ls.erase(prev(it));\n        }\n\t\twhile (next(it) != ls.end() &&\
    \ !is_needed(next(it))){\n            ls.erase(next(it));\n        }\n\t\tif (it\
    \ != ls.begin()) {\n\t\t\tprev(it)->has_nxt = true;\n\t\t\tprev(it)->nxt_a = it->a;\n\
    \t\t\tprev(it)->nxt_b = it->b;\n\t\t}\n\t\tif (next(it) != ls.end()) {\n\t\t\t\
    it->has_nxt = true;\n\t\t\tit->nxt_a = next(it)->a;\n\t\t\tit->nxt_b = next(it)->b;\n\
    \t\t}\n\t}\n\tT operator()(T x) {\n\t\tconst auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n\n\t\tif (query_type) {\t\n\t\t\treturn -it->a * x - it->b;\n\t\t\
    }\n\t\telse {\n\t\t\treturn it->a * x + it->b;\n\t\t}\n\t}\n};\n#line 5 \"test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n\nint main(){\n    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int\
    \ i=0;i<n;i++){\n        ll a,b;\n        cin>>a>>b;\n        cht.add(a,b);\n\
    \    }\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            ll a,b;\n            cin>>a>>b;\n            cht.add(a,b);\n    \
    \    }else{\n            ll x;\n            cin>>x;\n            cout<<cht(x)<<'\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include\"../../../src/template.hpp\"\n#include\"../../../src/data-structure/CHT.hpp\"\
    \n\nint main(){\n    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int\
    \ i=0;i<n;i++){\n        ll a,b;\n        cin>>a>>b;\n        cht.add(a,b);\n\
    \    }\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            ll a,b;\n            cin>>a>>b;\n            cht.add(a,b);\n    \
    \    }else{\n            ll x;\n            cin>>x;\n            cout<<cht(x)<<'\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/data-structure/CHT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-03-27 02:22:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
---
