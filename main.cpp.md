---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"main.cpp\"\n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n\
    #define rep(i, N) for (int i = 0; i < (N); i++)\n#define all(x) (x).begin(), (x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128 = __int128_t;\nusing ll\
    \ = long long;\nusing ld = long double;\nusing graph = std::vector<std::vector<int>>;\n\
    using P = std::pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl =\
    \ 1e18;\nconstexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr\
    \ uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int\
    \ dx[] = {1, 0, -1, 0};\nconstexpr int dy[] = {0, 1, 0, -1};\ntemplate <class\
    \ T>\nconstexpr inline void chmax(T& x, T y) {\n    if (x < y) x = y;\n}\ntemplate\
    \ <class T>\nconstexpr inline void chmin(T& x, T y) {\n    if (x > y) x = y;\n\
    }\n#line 4 \"src/random/xor_shift.hpp\"\n\nnamespace kyopro {\nstruct xor_shift32\
    \ {\n    uint32_t rng;\n    xor_shift32() : rng(std::rand()) {}\n    uint32_t\
    \ operator()() {\n        rng ^= rng << 13;\n        rng ^= rng >> 17;\n     \
    \   rng ^= rng << 5;\n        return rng;\n    }\n};\n};  // namespace kyopro\n\
    #line 6 \"src/BST/Treap.hpp\"\nnamespace kyopro {\n\ntemplate <class T>\nclass\
    \ ReversibleBST {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct\
    \ Node {\n        const T key;\n        const u32 priority;\n        std::shared_ptr<Node>\
    \ l, r;\n        Node(const T& key, u32 priority)\n            : key(key), priority(priority),\
    \ l(nullptr), r(nullptr) {}\n    };\n    using sptr = std::shared_ptr<Node>;\n\
    \    sptr root = nullptr;\n    void split(const sptr t, const T& key, sptr& l,\
    \ sptr& r) {\n        if (!t) {\n            l = r = nullptr;\n        } else\
    \ if (key < t->key) {\n            split(t->l, key, l, t->l);\n            r =\
    \ t;\n        } else {\n            split(t->r, key, t->r, r), l = t;\n      \
    \  }\n    }\n\n    void merge(sptr& t, const sptr& l, const sptr& r) {\n     \
    \   if (!l || !r) {\n            t = l ? l : r;\n        } else if (l->priority\
    \ > r->priority) {\n            merge(l->r, l->r, r), t = l;\n        } else {\n\
    \            merge(r->l, l, r->l), t = r;\n        }\n    }\n\n    void insert(sptr&\
    \ t, const sptr& item) {\n        if (!t) {\n            t = item;\n        }\
    \ else if (item->priority > t->priority) {\n            split(t, item->key, item->l,\
    \ item->r);\n            t = item;\n        } else {\n            insert(item->key\
    \ < t->key ? t->l : t->r, item);\n        }\n    }\n\n    void erase(sptr& t,\
    \ const T& key) {\n        if (!t) return;\n        if (t->key == key) {\n   \
    \         merge(t, t->l, t->r);\n        } else {\n            erase(key < t->key\
    \ ? t->l : t->r, key);\n        }\n    }\n\n    const sptr find(const sptr& t,\
    \ const T& key) const {\n        if (!t) {\n            return nullptr;\n    \
    \    } else if (t->key == key) {\n            return t;\n        } else {\n  \
    \          return find(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n\
    public:\n    void insert(const T& key) {\n        insert(root, std::make_shared<Node>(key,\
    \ rng()));\n    }\n\n    void erase(const T& key) { erase(root, key); }\n\n  \
    \  const Node* find(const T& key) const { return find(root, key).get(); }\n  \
    \  T min_element() const {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element() const {\n     \
    \   assert(root);\n        sptr cur = root;\n        while (cur->r) {\n      \
    \      cur = cur->r;\n        }\n        T ans = cur->key;\n        return ans;\n\
    \    }\n    T pop_front() {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n\
    \    T pop_back() {\n        assert(root);\n        sptr cur = root;\n       \
    \ while (cur->r) {\n            cur = cur->r;\n        }\n        T ans = cur->key;\n\
    \        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n};\n};  // namespace\
    \ kyopro\n#line 3 \"main.cpp\"\n\nint main() {\n    kyopro::ReversibleBST<int>\
    \ st;\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    rep(i, n) {\n        int\
    \ a;\n        scanf(\"%d\", &a);\n        st.insert(a);\n    }\n    while (q--)\
    \ {\n        int t;\n        scanf(\"%d\", &t);\n        if (!t) {\n         \
    \   int x;\n            scanf(\"%d\", &x);\n            st.insert(x);\n      \
    \  } else if (t == 1) {\n            int mn = st.pop_front();\n            printf(\"\
    %d\\n\", mn);\n            st.erase(mn);\n\n        } else {\n            int\
    \ mx = st.pop_back();\n            printf(\"%d\\n\", mx);\n            st.erase(mx);\n\
    \        }\n    }\n}\n"
  code: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i, N)\
    \ for (int i = 0; i < (N); i++)\n#define all(x) (x).begin(), (x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128 = __int128_t;\nusing ll = long\
    \ long;\nusing ld = long double;\nusing graph = std::vector<std::vector<int>>;\n\
    using P = std::pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl =\
    \ 1e18;\nconstexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr\
    \ uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int\
    \ dx[] = {1, 0, -1, 0};\nconstexpr int dy[] = {0, 1, 0, -1};\ntemplate <class\
    \ T>\nconstexpr inline void chmax(T& x, T y) {\n    if (x < y) x = y;\n}\ntemplate\
    \ <class T>\nconstexpr inline void chmin(T& x, T y) {\n    if (x > y) x = y;\n\
    }\n#line 4 \"src/random/xor_shift.hpp\"\n\nnamespace kyopro {\nstruct xor_shift32\
    \ {\n    uint32_t rng;\n    xor_shift32() : rng(std::rand()) {}\n    uint32_t\
    \ operator()() {\n        rng ^= rng << 13;\n        rng ^= rng >> 17;\n     \
    \   rng ^= rng << 5;\n        return rng;\n    }\n};\n};  // namespace kyopro\n\
    #line 6 \"src/BST/Treap.hpp\"\nnamespace kyopro {\n\ntemplate <class T>\nclass\
    \ ReversibleBST {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct\
    \ Node {\n        const T key;\n        const u32 priority;\n        std::shared_ptr<Node>\
    \ l, r;\n        Node(const T& key, u32 priority)\n            : key(key), priority(priority),\
    \ l(nullptr), r(nullptr) {}\n    };\n    using sptr = std::shared_ptr<Node>;\n\
    \    sptr root = nullptr;\n    void split(const sptr t, const T& key, sptr& l,\
    \ sptr& r) {\n        if (!t) {\n            l = r = nullptr;\n        } else\
    \ if (key < t->key) {\n            split(t->l, key, l, t->l);\n            r =\
    \ t;\n        } else {\n            split(t->r, key, t->r, r), l = t;\n      \
    \  }\n    }\n\n    void merge(sptr& t, const sptr& l, const sptr& r) {\n     \
    \   if (!l || !r) {\n            t = l ? l : r;\n        } else if (l->priority\
    \ > r->priority) {\n            merge(l->r, l->r, r), t = l;\n        } else {\n\
    \            merge(r->l, l, r->l), t = r;\n        }\n    }\n\n    void insert(sptr&\
    \ t, const sptr& item) {\n        if (!t) {\n            t = item;\n        }\
    \ else if (item->priority > t->priority) {\n            split(t, item->key, item->l,\
    \ item->r);\n            t = item;\n        } else {\n            insert(item->key\
    \ < t->key ? t->l : t->r, item);\n        }\n    }\n\n    void erase(sptr& t,\
    \ const T& key) {\n        if (!t) return;\n        if (t->key == key) {\n   \
    \         merge(t, t->l, t->r);\n        } else {\n            erase(key < t->key\
    \ ? t->l : t->r, key);\n        }\n    }\n\n    const sptr find(const sptr& t,\
    \ const T& key) const {\n        if (!t) {\n            return nullptr;\n    \
    \    } else if (t->key == key) {\n            return t;\n        } else {\n  \
    \          return find(key < t->key ? t->l : t->r, key);\n        }\n    }\n\n\
    public:\n    void insert(const T& key) {\n        insert(root, std::make_shared<Node>(key,\
    \ rng()));\n    }\n\n    void erase(const T& key) { erase(root, key); }\n\n  \
    \  const Node* find(const T& key) const { return find(root, key).get(); }\n  \
    \  T min_element() const {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        return ans;\n    }\n    T max_element() const {\n     \
    \   assert(root);\n        sptr cur = root;\n        while (cur->r) {\n      \
    \      cur = cur->r;\n        }\n        T ans = cur->key;\n        return ans;\n\
    \    }\n    T pop_front() {\n        assert(root);\n        sptr cur = root;\n\
    \        while (cur->l) {\n            cur = cur->l;\n        }\n        T ans\
    \ = cur->key;\n        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n\
    \    T pop_back() {\n        assert(root);\n        sptr cur = root;\n       \
    \ while (cur->r) {\n            cur = cur->r;\n        }\n        T ans = cur->key;\n\
    \        merge(cur, cur->l, cur->r);\n        return ans;\n    }\n};\n};  // namespace\
    \ kyopro\n#line 3 \"main.cpp\"\n\nint main() {\n    kyopro::ReversibleBST<int>\
    \ st;\n    int n, q;\n    scanf(\"%d%d\", &n, &q);\n    rep(i, n) {\n        int\
    \ a;\n        scanf(\"%d\", &a);\n        st.insert(a);\n    }\n    while (q--)\
    \ {\n        int t;\n        scanf(\"%d\", &t);\n        if (!t) {\n         \
    \   int x;\n            scanf(\"%d\", &x);\n            st.insert(x);\n      \
    \  } else if (t == 1) {\n            int mn = st.pop_front();\n            printf(\"\
    %d\\n\", mn);\n            st.erase(mn);\n\n        } else {\n            int\
    \ mx = st.pop_back();\n            printf(\"%d\\n\", mx);\n            st.erase(mx);\n\
    \        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-05-03 10:43:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
