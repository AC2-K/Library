---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segtree.hpp
    title: "Segment Tree(\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/segtree.hpp\"\nnamespace library{\n\n/// @brief Segment Tree(\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728)\n/// @tparam S \u8981\u7D20\u306E\u578B\n/// @tparam\
    \ op \u4E8C\u9805\u6F14\u7B97\n/// @tparam e \u5358\u4F4D\u5143\ntemplate<class\
    \ S, S(*op)(S, S), S(*e)()>\nclass segtree {\n\tint lg, sz, n;\n\tstd::vector<S>\
    \ dat;\npublic:\n\tsegtree() :segtree(0) {}\n\tsegtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n\tsegtree(const std::vector<S>& vec) : n((int)vec.size()) {\n\t\t\
    sz = 1, lg = 0;\n\t\twhile (sz <= n) {\n\t\t\tsz <<= 1;\n\t\t\tlg++;\n\t\t}\n\n\
    \t\tdat = vector<S>(sz << 1, e());\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\
    set(i, vec[i]);\n\t\t}\n\t\tbuild();\n\t}\n\n\tinline void set(const int p, const\
    \ S& v) {\n\t\tdat[sz + p] = v;\n\t}\n\tinline void build() {\n\t\tfor (int i\
    \ = sz - 1; i > 0; i--) {\n\t\t\tdat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);\n\
    \t\t}\n\t}\n\tS operator[](const int p) const { return dat[sz + p]; }\n\n\tvoid\
    \ update(int p, const S& v) {\n\t\tp += sz;\n\t\tdat[p] = v;\n\t\twhile (p >>=\
    \ 1) {\n\t\t\tdat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);\n\t\t}\n\t}\n\n\t\
    S prod(int l, int r) const {\n\t\tif (l == 0 && r == n) {\n\t\t\treturn dat[1];\n\
    \t\t}\n\t\tl += sz, r += sz;\n\t\tS sml = e(), smr = e();\n\t\twhile (l != r)\
    \ {\n\t\t\tif (l & 1)sml = op(sml, dat[l++]);\n\t\t\tif (r & 1)smr = op(dat[--r],\
    \ smr);\n\t\t\tl >>= 1, r >>= 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\tinline\
    \ void apply(int p, const S& v) {\n\t\tupdate(p, op(dat[sz + p], v));\n\t}\n};\n\
    };  // namespace library\n\n\n/// @docs docs/data-structure/segtree.md\n#line\
    \ 4 \"test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp\"\n\n\
    using namespace std;\nusing namespace library;\nnamespace RSQ {\nusing S = ll;\n\
    S op(S x, S y) { return x + y; }\nS e() { return 0; }\n};  // namespace RSQ\n\
    int main(){\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n,q;\n\
    \    cin>>n>>q;\n    vector<ll> a(n);\n    for(auto&aa:a){\n        cin>>aa;\n\
    \    }\n\n    segtree<RSQ::S,RSQ::op,RSQ::e> seg(a);\n    while(q--){\n      \
    \  int l,r;\n        cin>>l>>r;\n        cout<<seg.prod(l,r)<<'\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\"\
    template.hpp\"\n#include\"data-structure/segtree.hpp\"\n\nusing namespace std;\n\
    using namespace library;\nnamespace RSQ {\nusing S = ll;\nS op(S x, S y) { return\
    \ x + y; }\nS e() { return 0; }\n};  // namespace RSQ\nint main(){\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int n,q;\n    cin>>n>>q;\n    vector<ll> a(n);\n    for(auto&aa:a){\n\
    \        cin>>aa;\n    }\n\n    segtree<RSQ::S,RSQ::op,RSQ::e> seg(a);\n    while(q--){\n\
    \        int l,r;\n        cin>>l>>r;\n        cout<<seg.prod(l,r)<<'\\n';\n \
    \   }\n}"
  dependsOn:
  - template.hpp
  - data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 18:29:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Sum_segtree.test.cpp
---
