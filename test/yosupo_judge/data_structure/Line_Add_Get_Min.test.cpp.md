---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/CHT.hpp
    title: Convex Hull Trick
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 3 \"data-structure/CHT.hpp\"\n\n/// @brief Convex Hull Trick\n/// @tparam\
    \ T \u4FC2\u6570\u306E\u578B\n/// @tparam query_type \u30AF\u30A8\u30EA\u306E\u30BF\
    \u30A4\u30D7.true\u306B\u3059\u308B\u3068\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\
    \u3088\u3046\u306B\u5909\u66F4\u3059\u308B\ntemplate<class T = ll, bool query_type\
    \ = false>\nclass CHT {\n    class line {\n\n      public:\n        T a, b;\n\
    \        bool is_query;\n        mutable T nxt_a, nxt_b;\n        mutable bool\
    \ has_nxt;\n        T get(T x) const { return a * x + b; }\n        T get_nxt(T\
    \ x) const { return nxt_a * x + nxt_b; }\n        line(T a, T b, bool q = false)\n\
    \            : a(a), b(b), is_query(q), has_nxt(false){}\n        friend bool\
    \ operator<(const line& l, const line& r) {\n            if (l.is_query) {\n \
    \               if (!r.has_nxt) return true;\n                return r.get(l.a)\
    \ < r.get_nxt(l.a);\n            }\n            if (r.is_query) {\n          \
    \      if (!l.has_nxt) return false;\n                return l.get(r.a) > l.get_nxt(r.a);\n\
    \            }\n            return l.a == r.a ? l.b < r.b : l.a < r.a;\n     \
    \   }\n    };\n\n    std::set<line> ls;\n    bool is_needed(const typename std::set<line>::iterator&\
    \ it) {\n        if (it != ls.begin() && it->a == prev(it)->a) {\n           \
    \ return it->b < prev(it)->b;\n        }\n        if (next(it) != ls.end() &&\
    \ it->a == next(it)->a) {\n            return it->b < next(it)->b;\n        }\n\
    \        if (it == ls.begin() || next(it) == ls.end()) {\n            return true;\n\
    \        }\n        return 1. * (it->b - prev(it)->b) * (next(it)->a - it->a)\
    \ <\n            1. * (it->b - next(it)->b) * (prev(it)->a - it->a);\n    }\n\n\
    \  public:\n    void insert(T a, T b) {\n        if (query_type) {\n         \
    \   ls.emplace(-a, -b);\n        } else {\n            ls.emplace(a, b);\n   \
    \     }\n\n        const line& ln = (query_type ? line{-a, -b} : line{a, b});\n\
    \        auto it = ls.find(ln);\n        if (!is_needed(it)) {\n            ls.erase(it);\n\
    \            return;\n        }\n        while (it != ls.begin() && !is_needed(prev(it)))\
    \ {\n            ls.erase(prev(it));\n        }\n        while (next(it) != ls.end()\
    \ && !is_needed(next(it))) {\n            ls.erase(next(it));\n        }\n   \
    \     if (it != ls.begin()) {\n            prev(it)->has_nxt = true;\n       \
    \     prev(it)->nxt_a = it->a;\n            prev(it)->nxt_b = it->b;\n       \
    \ }\n        if (next(it) != ls.end()) {\n            it->has_nxt = true;\n  \
    \          it->nxt_a = next(it)->a;\n            it->nxt_b = next(it)->b;\n  \
    \      }\n    }\n    T operator()(T x) const {\n        const auto& it = ls.lower_bound(line(x,\
    \ 0, true));\n        \n        if (query_type) {\n            return -it->a *\
    \ x - it->b;\n        } else {\n            return it->a * x + it->b;\n      \
    \  }\n    }\n};\n\n/// @docs docs/data-structure/CHT.md\n#line 5 \"test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp\"\
    \n\nint main(){\n    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int\
    \ i=0;i<n;i++){\n        ll a,b;\n        cin>>a>>b;\n        cht.insert(a,b);\n\
    \    }\n    while(q--){\n        int t;\n        cin>>t;\n        if(t==0){\n\
    \            ll a,b;\n            cin>>a>>b;\n            cht.insert(a,b);\n \
    \       }else{\n            ll x;\n            cin>>x;\n            cout<<cht(x)<<'\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/CHT.hpp\"\n\nint main(){\n\
    \    int n,q;\n    cin>>n>>q;\n\n    CHT cht;    \n    for(int i=0;i<n;i++){\n\
    \        ll a,b;\n        cin>>a>>b;\n        cht.insert(a,b);\n    }\n    while(q--){\n\
    \        int t;\n        cin>>t;\n        if(t==0){\n            ll a,b;\n   \
    \         cin>>a>>b;\n            cht.insert(a,b);\n        }else{\n         \
    \   ll x;\n            cin>>x;\n            cout<<cht(x)<<'\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - template.hpp
  - data-structure/CHT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 17:33:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
- /verify/test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp.html
title: test/yosupo_judge/data_structure/Line_Add_Get_Min.test.cpp
---
