---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data-structure/bbst/Treap.hpp
    title: Treap
  - icon: ':x:'
    path: src/random/xor_shift.hpp
    title: xor shift
  - icon: ':x:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 2 \"src/data-structure/bbst/Treap.hpp\"\n#include <cassert>\n#include\
    \ <memory>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <chrono>\n#include\
    \ <cstdint>\n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32 {\n \
    \   uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n */\n#line 5 \"src/data-structure/bbst/Treap.hpp\"\
    \n\nnamespace kyopro {\n\n/**\n * @brief Treap\n * @tparam T \u4E57\u305B\u308B\
    \u30C7\u30FC\u30BF\u578B\n */\ntemplate <class T> class Treap {\n    using u32\
    \ = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n        const T key;\n\
    \        const u32 priority;\n        std::shared_ptr<Node> l, r;\n        Node(const\
    \ T& key, u32 priority)\n            : key(key), priority(priority), l(nullptr),\
    \ r(nullptr) {}\n    };\n    using sptr = std::shared_ptr<Node>;\n    sptr root\
    \ = nullptr;\n    void split(const sptr t, const T& key, sptr& l, sptr& r) {\n\
    \        if (!t) {\n            l = r = nullptr;\n        } else if (key < t->key)\
    \ {\n            split(t->l, key, l, t->l);\n            r = t;\n        } else\
    \ {\n            split(t->r, key, t->r, r), l = t;\n        }\n    }\n\n    void\
    \ merge(sptr& t, const sptr& l, const sptr& r) {\n        if (!l || !r) {\n  \
    \          t = l ? l : r;\n        } else if (l->priority > r->priority) {\n \
    \           merge(l->r, l->r, r), t = l;\n        } else {\n            merge(r->l,\
    \ l, r->l), t = r;\n        }\n    }\n\n    void insert(sptr& t, const sptr& item)\
    \ {\n        if (!t) {\n            t = item;\n        } else if (item->priority\
    \ > t->priority) {\n            split(t, item->key, item->l, item->r);\n     \
    \       t = item;\n        } else {\n            insert(item->key < t->key ? t->l\
    \ : t->r, item);\n        }\n    }\n\n    void erase(sptr& t, const T& key) {\n\
    \        if (!t) return;\n        if (t->key == key) {\n            merge(t, t->l,\
    \ t->r);\n        } else {\n            erase(key < t->key ? t->l : t->r, key);\n\
    \        }\n    }\n\n    const sptr find(const sptr& t, const T& key) const {\n\
    \        if (!t) {\n            return nullptr;\n        } else if (t->key ==\
    \ key) {\n            return t;\n        } else {\n            return find(key\
    \ < t->key ? t->l : t->r, key);\n        }\n    }\n\npublic:\n    constexpr explicit\
    \ Treap() : rng(2023) {}\n    void insert(const T& key) {\n        insert(root,\
    \ std::make_shared<Node>(key, rng()));\n    }\n\n    void erase(const T& key)\
    \ { erase(root, key); }\n\n    const Node* find(const T& key) const { return find(root,\
    \ key).get(); }\n    T min_element() const {\n        assert(root);\n        sptr\
    \ cur = root;\n        while (cur->l) {\n            cur = cur->l;\n        }\n\
    \        T ans = cur->key;\n        return ans;\n    }\n    T max_element() {\n\
    \        assert(root);\n        sptr cur = root;\n        while (cur->r) {\n \
    \           cur = cur->r;\n        }\n        T ans = cur->key;\n        return\
    \ ans;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/bbst/Treap.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#include <concepts>\n\nnamespace kyopro {\n/**\n * \u6587\u5B57\u3092\
    1\u500B\u8AAD\u307F\u8FBC\u3080\n */\n\ninline char readchar() {\n    char c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n    return\
    \ c;\n}\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate <std::integral\
    \ T> constexpr inline void read(T& a) {\n    a = 0;\n    bool is_negative = false;\n\
    \    char c = getchar_unlocked();\n    while (isspace(c)) {\n        c = getchar_unlocked();\n\
    \    }\n    if (c == '-') is_negative = true, c = getchar_unlocked();\n    while\
    \ (isdigit(c)) {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n\
    \    }\n    if (is_negative) a *= -1;\n}\n\ntemplate <std::integral T> constexpr\
    \ inline void put(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n    \
    \    putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\n\n/**\n * \u6587\u5B57\u5217\n*/\ninline void\
    \ read(std::string& str) {\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ c = getchar_unlocked();\n    while (!isspace(c)) {\n        str += c;\n    \
    \    c = getchar_unlocked();\n    }\n}\ninline void put(const std::string& str)\
    \ {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\n\n/**\n * \u591A\u5909\u6570\n*/\ntemplate <typename Head, typename...\
    \ Tail>\nconstexpr inline void read(Head& head, Tail&... tail) {\n    read(head);\n\
    \    read(tail...);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void put(const Head& head,const Tail&... tail) {\n    put(head);\n  \
    \  put(tail...);\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line\
    \ 5 \"test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp\"\n\
    using namespace std;\nint main() {\n    kyopro::Treap<int> st;\n    int n, q;\n\
    \    kyopro::read(n, q);\n    for (int i = 0; i < n; ++i) {\n        int a;\n\
    \        kyopro::read(a);\n        st.insert(a);\n    }\n    while (q--) {\n \
    \       int t;\n        kyopro::read(t);\n        if (!t) {\n            int x;\n\
    \            kyopro::read(x);\n            st.insert(x);\n        } else if (t\
    \ == 1) {\n            int mn = st.min_element();\n            kyopro::put(mn);\n\
    \            st.erase(mn);\n        } else {\n            int mx = st.max_element();\n\
    \            kyopro::put(mx);\n            st.erase(mx);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../../src/data-structure/bbst/Treap.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nusing namespace std;\nint main() {\n    kyopro::Treap<int> st;\n    int n, q;\n\
    \    kyopro::read(n, q);\n    for (int i = 0; i < n; ++i) {\n        int a;\n\
    \        kyopro::read(a);\n        st.insert(a);\n    }\n    while (q--) {\n \
    \       int t;\n        kyopro::read(t);\n        if (!t) {\n            int x;\n\
    \            kyopro::read(x);\n            st.insert(x);\n        } else if (t\
    \ == 1) {\n            int mn = st.min_element();\n            kyopro::put(mn);\n\
    \            st.erase(mn);\n        } else {\n            int mx = st.max_element();\n\
    \            kyopro::put(mx);\n            st.erase(mx);\n        }\n    }\n}"
  dependsOn:
  - src/data-structure/bbst/Treap.hpp
  - src/random/xor_shift.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  requiredBy: []
  timestamp: '2023-07-21 13:15:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
---
