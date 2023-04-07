---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/dynamic_segtree.hpp
    title: "Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728)"
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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yuki/No-789_dynamic.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/789\"\n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x)\
    \ (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\n\
    using ll = long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\n\
    using P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\n\
    constexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t\
    \ MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = {\
    \ 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr\
    \ inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline\
    \ void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"data-structure/dynamic_segtree.hpp\"\
    \n/// @brief Dynamic Segment Tree(\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\ntemplate<class S,S(*op)(S,S),S(*e)()>\nclass dynamic_segtree {\n\n  public:\n\
    \    dynamic_segtree(const size_t& n) : n(n), root(nullptr) {}\n\n  private:\n\
    \    struct node {\n        S val;\n        node* left;\n        node* right;\n\
    \n        node(const S& v) : val(v), left(nullptr), right(nullptr) {}\n    };\n\
    \    node* root;\n    size_t n;\n\n  public:\n    \n    void update(const size_t&\
    \ p, const S& x) {\n        assert(0 <= p && p < n);\n        internal_update(root,\
    \ 0, n, p, x);\n    }\n    void add(const size_t& p, const S& x) {\n        assert(0\
    \ <= p && p < n);\n        internal_add(root, 0, n, p, x);\n    }\n    S operator[](const\
    \ size_t& p) {\n        assert(0 <= p && p < n);\n        return internal_access(root,\
    \ 0, n, p);\n    }\n    S prod(const size_t& l, const size_t& r) {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        if (l == r) {\n            return e();\n\
    \        }\n\n        return internal_prod(root, 0, n, l, r);\n    }\n\n  private:\n\
    \    void internal_update(node*& p,\n                         const size_t& l,\n\
    \                         const size_t& r,\n                         const size_t&\
    \ idx,\n                         const S& new_val) {\n        if (p == nullptr)\
    \ {\n            p = new node(e());\n        }\n        if (r - l == 1) {\n  \
    \          p->val = new_val;\n            return;\n        }\n        size_t mid\
    \ = (l + r) >> 1;\n        if (idx < mid)\n            internal_update(p->left,\
    \ l, mid, idx, new_val);\n        else\n            internal_update(p->right,\
    \ mid, r, idx, new_val);\n        p->val = e();\n        if (p->left != nullptr)\
    \ p->val = op(p->left->val, p->val);\n        if (p->right != nullptr) p->val\
    \ = op(p->val, p->right->val);\n    }\n    void internal_add(node*& p,\n     \
    \                 const size_t& l,\n                      const size_t& r,\n \
    \                     const size_t& idx,\n                      const S& new_val)\
    \ {\n        if (p == nullptr) {\n            p = new node(e());\n        }\n\n\
    \        if (r - l == 1) {\n            p->val = op(p->val, new_val);\n      \
    \      ;\n            return;\n        }\n        size_t mid = (l + r) >> 1;\n\
    \        if (idx < mid)\n            internal_add(p->left, l, mid, idx, new_val);\n\
    \        else\n            internal_add(p->right, mid, r, idx, new_val);\n   \
    \     p->val = e();\n        if (p->left != nullptr) p->val = op(p->left->val,\
    \ p->val);\n        if (p->right != nullptr) p->val = op(p->val, p->right->val);\n\
    \    }\n    S internal_access(node*& p,\n                      const size_t& l,\n\
    \                      const size_t& r,\n                      const size_t& idx)\
    \ {\n        if (p == nullptr) {\n            return e();\n        }\n       \
    \ if (r - l == 1) {\n            return p->val;\n        }\n\n        size_t mid\
    \ = (l + r) >> 1;\n        if (idx < mid)\n            return internal_access(p->left,\
    \ l, mid, idx);\n        else\n            return internal_access(p->right, mid,\
    \ r, idx);\n    }\n    S internal_prod(node*& p,\n                    const size_t&\
    \ l,\n                    const size_t& r,\n                    const size_t&\
    \ L,\n                    const size_t& R) {\n        if (p == nullptr || r <=\
    \ L || R <= l) {\n            return e();\n        }\n        if (L <= l && r\
    \ <= R) {\n            return p->val;\n        }\n\n        size_t mid = (l +\
    \ r) >> 1;\n        return op(internal_prod(p->left, l, mid, L, R),\n        \
    \          internal_prod(p->right, mid, r, L, R));\n    }\n};\n\n/// @docs docs/data-structure/dynamic_segtree.md\n\
    #line 5 \"test/yuki/No-789_dynamic.test.cpp\"\nint op(int x, int y) { return x\
    \ + y; }\nint e() { return 0; }\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\tconst size_t n = 1000000001;\n\tdynamic_segtree<int,\
    \ op, e> seg(n);\n\n\tint q;\n\tcin >> q;\n\tlong long ans = 0;\n\twhile (q--)\
    \ {\n\t\tint type;\n\t\tcin >> type;\n\t\tif (type == 0) {\n\t\t\tsize_t x;\n\t\
    \t\tlong long y;\n\t\t\tcin >> x >> y;\n\t\t\tseg.add(x, y);\n\t\t}\n\t\telse\
    \ {\n\t\t\tsize_t l, r;\n\t\t\tcin >> l >> r;\n\t\t\tans += seg.prod(l, r + 1);\n\
    \t\t}\n\t}\n\tcout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include\"template.hpp\"\
    \n#include\"data-structure/dynamic_segtree.hpp\"\nint op(int x, int y) { return\
    \ x + y; }\nint e() { return 0; }\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\tconst size_t n = 1000000001;\n\tdynamic_segtree<int,\
    \ op, e> seg(n);\n\n\tint q;\n\tcin >> q;\n\tlong long ans = 0;\n\twhile (q--)\
    \ {\n\t\tint type;\n\t\tcin >> type;\n\t\tif (type == 0) {\n\t\t\tsize_t x;\n\t\
    \t\tlong long y;\n\t\t\tcin >> x >> y;\n\t\t\tseg.add(x, y);\n\t\t}\n\t\telse\
    \ {\n\t\t\tsize_t l, r;\n\t\t\tcin >> l >> r;\n\t\t\tans += seg.prod(l, r + 1);\n\
    \t\t}\n\t}\n\tcout << ans << '\\n';\n}"
  dependsOn:
  - template.hpp
  - data-structure/dynamic_segtree.hpp
  isVerificationFile: true
  path: test/yuki/No-789_dynamic.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 13:04:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki/No-789_dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/No-789_dynamic.test.cpp
- /verify/test/yuki/No-789_dynamic.test.cpp.html
title: test/yuki/No-789_dynamic.test.cpp
---
