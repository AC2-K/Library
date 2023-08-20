---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bbst/Treap.hpp
    title: Treap
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: xor shift
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ <string>\n#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include\
    \ <limits>\n#include <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace\
    \ internal {\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\
    \ using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt> using\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/stream.hpp\"\
    \n\nnamespace kyopro {\n// read\nvoid single_read(char& c) {\n    c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    a = 0;\n    bool is_negative = false;\n\
    \    char c = getchar_unlocked();\n    while (isspace(c)) {\n        c = getchar_unlocked();\n\
    \    }\n    if (c == '-') is_negative = true, c = getchar_unlocked();\n    while\
    \ (isdigit(c)) {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n\
    \    }\n    if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 5 \"test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp\"\
    \nusing namespace std;\nint main() {\n    kyopro::Treap<int> st;\n    int n, q;\n\
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
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 22:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue.test.cpp
---
