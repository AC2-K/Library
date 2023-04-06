---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':question:'
    path: misc/mo.hpp
    title: mo's algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = std::vector<std::vector<int>>;\nusing P = std::pair<int, int>;\nconstexpr\
    \ int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long\
    \ double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t\
    \ MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] =\
    \ { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 2 \"data-structure/BIT.hpp\"\nnamespace library{\n/// @brief Binary Index Tree\n\
    /// @tparam T \u8981\u7D20\u306E\u578B\n/// @tparam SumT \"\u548C\u304C\" \u53CE\
    \u307E\u308B\u3088\u3046\u306A\u578B\ntemplate<typename T,typename SumT = T>\n\
    class BIT {\n\tstd::vector<SumT> bit;\n\tint n;\npublic:\n    BIT(int n) :n(n),\
    \ bit(n + 1, T()) {}\n\tvoid add(int p, const T& w) {\n\t\tp++;\n\t\tfor (int\
    \ x = p; x <= n; x += x & -x) {\n\t\t\tbit[x] += w;\n\t\t}\n\t}\n\n\tSumT sum(int\
    \ p)const {\n\t\tT s = 0;\n\n\t\tfor (int x = p; x > 0; x -= x & -x) {\n\t\t\t\
    s += bit[x];\n\t\t}\n\t\treturn s;\n\t}\n\n\tSumT sum(int l, int r)const {\n\t\
    \treturn sum(r) - sum(l);\n\t}\n\n    \n    int lower_bound(SumT w)const {\n \
    \       if (w <= 0)return 0;\n\n        int x = 0;\n        int k = 1;\n     \
    \   while (k < n)k <<= 1;\n        for (; k > 0; k >>= 1) {\n            if (x\
    \ + k <= n && bit[x + k] < w) {\n                w -= bit[x + k];\n          \
    \      x += k;\n            }\n        }\n\n        return x + 1;\n    }\n};\n\
    };  // namespace library\n\n\n\n/// @docs docs/data-structure/BIT.md\n#line 4\
    \ \"misc/mo.hpp\"\n/// @brief mo's algorithm\nclass Mo {\n    int n;\n    std::vector<std::pair<int,\
    \ int>> lr;\n    const int logn;\n    const long long maxn;\n    std::vector<int>\
    \ ord;\npublic:\n    explicit Mo(int n) : n(n), logn(20), maxn(1ll << logn) {\
    \ lr.reserve(n); }\n    void add(int l, int r) { lr.emplace_back(l, r); }\n  \
    \  long long hilbertorder(int x, int y){\n        long long d = 0;\n        for\
    \ (int s = 1 << (logn - 1); s; s >>= 1) {\n            bool rx = x & s, ry = y\
    \ & s;\n            d = d << 2 | rx * 3 ^ static_cast<int>(ry);\n            if\
    \ (!ry){\n                if (rx)\n                {\n                    x =\
    \ maxn - x;\n                    y = maxn - y;\n                }\n          \
    \      std::swap(x, y);\n            }\n        }\n        return d;\n    }\n\n\
    private:\n    inline void line_up() {\n        int q = lr.size();\n        ord.resize(q);\n\
    \        std::iota(ord.begin(), ord.end(), 0);\n        std::vector<long long>\
    \ tmp(q);\n        for (int i = 0; i < q; i++) {\n            tmp[i] = hilbertorder(lr[i].first,\
    \ lr[i].second);\n        }\n        std::sort(ord.begin(), ord.end(), [&](int\
    \ a, int b) {\n            return tmp[a] < tmp[b];\n        });\n    }\npublic:\n\
    \    template< typename AL, typename AR, typename EL, typename ER, typename O\
    \ >\n    void build(const AL& add_left, const AR& add_right, const EL& erase_left,\
    \ const ER& erase_right, const O& out) {\n        line_up();\n        int l =\
    \ 0, r = 0;\n        for (const auto& idx : ord) {\n            while (l > lr[idx].first)\
    \ add_left(--l);\n            while (r < lr[idx].second) add_right(r++);\n   \
    \         while (l < lr[idx].first) erase_left(l++);\n            while (r > lr[idx].second)\
    \ erase_right(--r);\n            out(idx);\n        }\n    }\n\n    template<\
    \ typename A, typename E, typename O >\n    void build(const A& add, const E&\
    \ erase, const O& out) {\n        build(add, add, erase, erase, out);\n    }\n\
    };\n/// @docs docs/other/mo.md\n#line 6 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \n\n\nusing namespace std;\nusing namespace library;\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n    Mo mo(q);\n    vector<int> a(n);\n   \
    \ for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    vector<int> k(q);\n\
    \    for(int i=0;i<q;i++) {\n        int l, r;\n        scanf(\"%d%d%d\", &l,\
    \ &r, &k[i]);\n        k[i]++;\n        mo.add(l, r);\n    }\n    vector<int>\
    \ pressed = a;\n    auto tmp = a;\n    {\n        sort(tmp.begin(), tmp.end());\n\
    \        tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());\n        for (auto&\
    \ ai : pressed) {\n            ai = lower_bound(tmp.begin(),tmp.end(), ai) - tmp.begin();\n\
    \        }\n    }\n\n    int sz = tmp.size();\n    BIT<int> st(sz);\n    auto\
    \ add = [&](int x) -> void { st.add(pressed[x], 1); };\n    auto del = [&](int\
    \ x) -> void { st.add(pressed[x], -1); };\n    vector<int> ans(q);\n    auto out\
    \ = [&](int x) -> void {\n        int ok = st.lower_bound(k[x]);\n        ans[x]\
    \ = tmp[ok - 1];\n    };\n\n    mo.build(add, del, out);\n    for (auto& as :\
    \ ans) {\n        printf(\"%d\\n\", as);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include\"template.hpp\"\n#include\"data-structure/BIT.hpp\"\n#include\"misc/mo.hpp\"\
    \n\n\nusing namespace std;\nusing namespace library;\nint main() {\n    int n,\
    \ q;\n    scanf(\"%d%d\", &n, &q);\n    Mo mo(q);\n    vector<int> a(n);\n   \
    \ for (auto& aa : a) {\n        scanf(\"%d\", &aa);\n    }\n    vector<int> k(q);\n\
    \    for(int i=0;i<q;i++) {\n        int l, r;\n        scanf(\"%d%d%d\", &l,\
    \ &r, &k[i]);\n        k[i]++;\n        mo.add(l, r);\n    }\n    vector<int>\
    \ pressed = a;\n    auto tmp = a;\n    {\n        sort(tmp.begin(), tmp.end());\n\
    \        tmp.erase(unique(tmp.begin(),tmp.end()), tmp.end());\n        for (auto&\
    \ ai : pressed) {\n            ai = lower_bound(tmp.begin(),tmp.end(), ai) - tmp.begin();\n\
    \        }\n    }\n\n    int sz = tmp.size();\n    BIT<int> st(sz);\n    auto\
    \ add = [&](int x) -> void { st.add(pressed[x], 1); };\n    auto del = [&](int\
    \ x) -> void { st.add(pressed[x], -1); };\n    vector<int> ans(q);\n    auto out\
    \ = [&](int x) -> void {\n        int ok = st.lower_bound(k[x]);\n        ans[x]\
    \ = tmp[ok - 1];\n    };\n\n    mo.build(add, del, out);\n    for (auto& as :\
    \ ans) {\n        printf(\"%d\\n\", as);\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/BIT.hpp
  - misc/mo.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-04-06 20:41:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
---
