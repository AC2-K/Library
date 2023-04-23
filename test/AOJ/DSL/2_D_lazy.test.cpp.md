---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: "Segment Tree with Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\
      \u30E1\u30F3\u30C8\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include <iostream>\n#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n/// @brief Segment Tree with\
    \ Lazy Propagation(\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\ntemplate <class S,\n          class F,\n          S (*op)(S, S),\n        \
    \  S (*e)(),\n          F (*comp)(F, F),\n          F (*id)(),\n          S (*mapping)(S,\
    \ F)>\nclass lazy_segtree {\n    int sz;\n    std::vector<S> dat;\n    std::vector<F>\
    \ lz;\n\npublic:\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e()))\
    \ {}\n    lazy_segtree(const std::vector<S>& a)\n        : dat(4 * a.size(), e()),\
    \ lz(4 * a.size(), id()) {\n        int x = 1;\n        while (a.size() > x) {\n\
    \            x <<= 1;\n        }\n        sz = x;\n        for (int i = 0; i <\
    \ a.size(); i++) {\n            set(i, a[i]);\n        }\n        build();\n \
    \   }\n\npublic:\n    inline void set(int pos, S x) {\n        assert(0 <= pos\
    \ && pos < sz);\n        dat[pos + sz - 1] = x;\n    }\n    inline void build()\
    \ {\n        for (int i = sz - 2; i >= 0; i--) {\n            dat[i] = op(dat[2\
    \ * i + 1], dat[2 * i + 2]);\n        }\n    }\n\nprivate:\n    void eval(int\
    \ pos) {\n        if (lz[pos] == id()) return;\n        if (pos < sz - 1) {\n\
    \            lz[2 * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);\n            lz[2\
    \ * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);\n        }\n        dat[pos] =\
    \ mapping(dat[pos], lz[pos]);\n        lz[pos] = id();\n    }\n\nprivate:\n  \
    \  void internal_apply(int L, int R, int l, int r, const F& x, int k) {\n    \
    \    eval(k);\n        if (L <= l && r <= R) {\n            lz[k] = comp(lz[k],\
    \ x);\n            eval(k);\n        } else if (L < r && l < R) {\n          \
    \  int mid = (l + r) >> 1;\n            internal_apply(L, R, l, mid, x, 2 * k\
    \ + 1);\n            internal_apply(L, R, mid, r, x, 2 * k + 2);\n           \
    \ dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);\n        }\n    }\n\npublic:\n\
    \    inline void apply(int l, int r, const F& x) {\n        assert(0 <= l && l\
    \ <= r && r <= sz);\n        internal_apply(l, r, 0, sz, x, 0);\n    }\n\nprivate:\n\
    \    S internal_prod(int L, int R, int l, int r, int k) {\n        eval(k);\n\
    \        if (r <= L || R <= l) {\n            return e();\n        } else if (L\
    \ <= l && r <= R) {\n            return dat[k];\n        } else {\n          \
    \  int mid = (l + r) >> 1;\n            S vl = internal_prod(L, R, l, mid, 2 *\
    \ k + 1);\n            S vr = internal_prod(L, R, mid, r, 2 * k + 2);\n      \
    \      return op(vl, vr);\n        }\n    }\n\npublic:\n    inline S prod(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= sz);\n        return internal_prod(l,\
    \ r, 0, sz, 0);\n    }\n\n    inline S operator[](int pos) { return prod(pos,\
    \ pos + 1); }\n};\n};  // namespace kyopro\n\n/// @docs docs/data-structure/lazy_segtree.md\n\
    #line 5 \"test/AOJ/DSL/2_D_lazy.test.cpp\"\nusing namespace std;\nint op(int x,\
    \ int y) { return min(x, y); }\nint comp(int x, int y) { return y; }\nint mapping(int\
    \ x, int y) { return y; }\nint e() { return (1ll << 31) - 1; }\nint id() { return\
    \ (1ll << 31) - 1; }\n\nint main() {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n\
    \    kyopro::lazy_segtree<int, int, op, e, comp, id, mapping> seg(n);\n    while\
    \ (q--) {\n        int t;\n        scanf(\"%d\", &t);\n        if (!t) {\n   \
    \         int l, r, add;\n            scanf(\"%d%d%d\", &l, &r, &add);\n     \
    \       seg.apply(l, r + 1, add);\n        } else {\n            int i;\n    \
    \        scanf(\"%d\", &i);\n            printf(\"%lld\\n\", seg[i]);\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include <iostream>\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\
    \nusing namespace std;\nint op(int x, int y) { return min(x, y); }\nint comp(int\
    \ x, int y) { return y; }\nint mapping(int x, int y) { return y; }\nint e() {\
    \ return (1ll << 31) - 1; }\nint id() { return (1ll << 31) - 1; }\n\nint main()\
    \ {\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    kyopro::lazy_segtree<int,\
    \ int, op, e, comp, id, mapping> seg(n);\n    while (q--) {\n        int t;\n\
    \        scanf(\"%d\", &t);\n        if (!t) {\n            int l, r, add;\n \
    \           scanf(\"%d%d%d\", &l, &r, &add);\n            seg.apply(l, r + 1,\
    \ add);\n        } else {\n            int i;\n            scanf(\"%d\", &i);\n\
    \            printf(\"%lld\\n\", seg[i]);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL/2_D_lazy.test.cpp
  requiredBy: []
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL/2_D_lazy.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp
- /verify/test/AOJ/DSL/2_D_lazy.test.cpp.html
title: test/AOJ/DSL/2_D_lazy.test.cpp
---
