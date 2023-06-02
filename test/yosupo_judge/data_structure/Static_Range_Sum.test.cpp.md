---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: SegmentTree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n\n/**\n * @brief SegmentTree\n */\ntemplate\
    \ <class S, S (*op)(S, S), S (*e)()> class segtree {\n    int lg, sz, n;\n   \
    \ std::vector<S> dat;\n\npublic:\n    segtree() {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& vec) : n((int)vec.size()) {\n  \
    \      sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n   \
    \         lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n\n\
    \        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n        }\n\
    \        build();\n    }\n\n    void set(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build() {\n    \
    \    for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i << 1 |\
    \ 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const { return\
    \ dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0 <=\
    \ p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1)\
    \ {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n\
    \    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n   \
    \     }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n        while\
    \ (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if\
    \ (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    void apply(int p, const S& v) {\n  \
    \      assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/segtree.md\n\
    \ */\n#line 4 \"test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp\"\n\
    \ninline long long op(long long x, long long y) { return x + y; }\ninline long\
    \ long e() { return 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n,\
    \ &q);\n\n    kyopro::segtree<long long, op, e> seg(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        int a;\n        scanf(\"%d\", &a);\n        seg.set(i,\
    \ a);\n    }\n    seg.build();\n    while (q--) {\n        int l, r;\n       \
    \ scanf(\"%d%d\", &l, &r);\n        printf(\"%lld\\n\", seg.fold(l, r));\n   \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <iostream>\n#include \"../../../src/data-structure/segtree.hpp\"\n\ninline long\
    \ long op(long long x, long long y) { return x + y; }\ninline long long e() {\
    \ return 0; }\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\n \
    \   kyopro::segtree<long long, op, e> seg(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        int a;\n        scanf(\"%d\", &a);\n        seg.set(i, a);\n    }\n\
    \    seg.build();\n    while (q--) {\n        int l, r;\n        scanf(\"%d%d\"\
    , &l, &r);\n        printf(\"%lld\\n\", seg.fold(l, r));\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 08:00:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Static_Range_Sum.test.cpp
---
