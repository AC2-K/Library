---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/BinaryTrie.hpp
    title: Binary Trie
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':question:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  - icon: ':question:'
    path: src/template.hpp
    title: Template
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
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 2 \"src/data-structure/BinaryTrie.hpp\"\n#include <cassert>\n#include\
    \ <cstdint>\n\nnamespace kyopro {\ntemplate <typename T, std::uint32_t lg> class\
    \ BinaryTrie {\n    using u32 = std::uint32_t;\n    using usize = std::size_t;\n\
    \n    struct Node {\n        usize cnt;\n        Node* par;\n        Node* ch[2]{nullptr,\
    \ nullptr};\n\n        Node() : cnt(0), par(nullptr) {}\n    };\n\npublic:\n \
    \   Node* root = new Node();\n\n    BinaryTrie() : root(new Node()){}\n\n    usize\
    \ size() const { return root->cnt; }\n    bool empty() const { return size() ==\
    \ 0; }\n    \n    usize count(T x) const {\n        Node* cur = root;\n      \
    \  for (int i = lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n\n\
    \            if (cur->ch[b] == nullptr || cur->ch[b] == 0) {\n               \
    \ return 0;\n            } else {\n                cur = cur->ch[b];\n       \
    \     }\n        }\n\n        return cur->cnt;\n    }\n\n    void insert(T x)\
    \ {\n        Node* cur = root;\n\n        for (int i = lg - 1; i >= 0; --i) {\n\
    \            T b = (x >> i & T(1));\n\n            if (cur->ch[b] == nullptr)\
    \ {\n                cur->ch[b] = new Node();\n                cur->ch[b]->par\
    \ = cur;\n            }\n\n            cur = cur->ch[b];\n        }\n\n      \
    \  ++cur->cnt;\n\n        while (cur->par != nullptr) {\n            cur = cur->par;\n\
    \n            cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) cur->cnt\
    \ += cur->ch[0]->cnt;\n            if (cur->ch[1] != nullptr) cur->cnt += cur->ch[1]->cnt;\n\
    \        }\n    }\n\n    void erase(T x) {\n        Node* cur = root;\n      \
    \  for (int i = lg - 1; i >= 0; --i) {\n            T b = (x >> i & T(1));\n \
    \           cur = cur->ch[b];\n            assert(cur);\n        }\n\n       \
    \ --cur->cnt;\n\n        while (cur->par != nullptr) {\n            cur = cur->par;\n\
    \n            cur->cnt = 0;\n\n            if (cur->ch[0] != nullptr) {\n    \
    \            cur->cnt += cur->ch[0]->cnt;\n            }\n            if (cur->ch[1]\
    \ != nullptr) {\n                cur->cnt += cur->ch[1]->cnt;\n            }\n\
    \        }\n    }\n\n    T max() const {\n        assert(size() > 0);\n\n    \
    \    Node* cur = root;\n\n        T res = 0;\n        for (int i = lg - 1; i >=\
    \ 0; --i) {\n            if (cur->ch[1] != nullptr && cur->ch[1]->cnt != 0) {\n\
    \                cur = cur->ch[1];\n                res |= (T(1) << i);\n    \
    \        } else {\n                cur = cur->ch[0];\n            }\n        }\n\
    \n        return res;\n    }\n\n    T min() const {\n        assert(size() > 0);\n\
    \n        Node* cur = root;\n\n        T res = 0;\n\n        for (int i = lg -\
    \ 1; i >= 0; --i) {\n            if (cur->ch[0] != nullptr && cur->ch[0]->cnt\
    \ != 0) {\n                cur = cur->ch[0];\n            } else {\n         \
    \       cur = cur->ch[1];\n                res |= (T(1) << i);\n            }\n\
    \        }\n\n        return res;\n    }\n\n    T kth_smallest(usize k) const\
    \ {\n        assert(k < this->size());\n\n        Node* cur = root;\n        T\
    \ res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n            if (cur->ch[0]\
    \ != nullptr && k < cur->ch[0]->cnt) {\n                cur = cur->ch[0];\n  \
    \          } else {\n                if (cur->ch[0] != nullptr) k -= cur->ch[0]->cnt;\n\
    \n                cur = cur->ch[1];\n                res |= (T(1) << i);\n   \
    \         }\n        }\n\n        return res;\n    }\n\n    T kth_largest(usize\
    \ k) const {\n        assert(k < this->size());\n\n        Node* cur = root;\n\
    \        T res = 0;\n\n        for (int i = lg - 1; i >= 0; --i) {\n         \
    \   if (cur->ch[1] != nullptr && k < cur->ch[1]->cnt) {\n                cur =\
    \ cur->ch[1];\n                res |= (T(1) << i);\n            } else {\n   \
    \             if (cur->ch[1] != nullptr) k -= cur->ch[1]->cnt;\n             \
    \   cur = cur->ch[0];\n            }\n        }\n\n        return res;\n    }\n\
    };\n\n};  // namespace kyopro\n\n\n/**\n * @brief Binary Trie\n */\n#line 2 \"\
    src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    #line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include <limits>\n\
    #include <numeric>\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
    \n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 6\
    \ \"src/stream.hpp\"\n\nnamespace kyopro {\n\ninline void single_read(char& c)\
    \ {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\ninline void single_read(std::string& str) noexcept {\n    char\
    \ c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n  \
    \  while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\ntemplate<typename T>\ninline void read(T& x) noexcept {single_read(x);}\n\
    template <typename Head, typename... Tail>\ninline void read(Head& head, Tail&...\
    \ tail) noexcept {\n    single_read(head), read(tail...);\n}\n\ninline void single_write(char\
    \ c) noexcept { putchar_unlocked(c); }\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_write(T a) noexcept {\n    if (!a) {\n      \
    \  putchar_unlocked('0');\n        return;\n    }\n    if constexpr (std::is_signed_v<T>)\
    \ {\n        if (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr\
    \ int d = std::numeric_limits<T>::digits10;\n    char s[d + 1];\n    int now =\
    \ d + 1;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /=\
    \ 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n}\ntemplate <typename\
    \ T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T a) noexcept\
    \ {\n    single_write(a.val());\n}\ninline void single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)\n */\n#line\
    \ 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconst long double pi = acosl(-1);\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmax(T1& a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a >\
    \ b && (a = b, true);\n}\n\n/**\n * @brief Template\n*/\n#line 6 \"test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nusing u32 = uint32_t;\nconst\
    \ int offset = 1e9;\n\nint main() {\n    int n, q;\n    read(n, q);\n\n    BinaryTrie<u32,\
    \ 32> pq;\n\n    rep(i, n) {\n        int s;\n        read(s);\n        pq.insert(s\
    \ + offset);\n    }\n\n    while (q--) {\n        int t;\n        read(t);\n\n\
    \        if (t == 0) {\n            int x;\n            read(x);\n           \
    \ pq.insert(x + offset);\n        } else if (t == 1) {\n            u32 mn = pq.min();\n\
    \            pq.erase(mn);\n\n            put((int)mn - offset);\n        } else\
    \ {\n            u32 mx = pq.max();\n            pq.erase(mx);\n\n           \
    \ put((int)mx - offset);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../../src/data-structure/BinaryTrie.hpp\"\n#include \"../../../src/stream.hpp\"\
    \n#include \"../../../src/template.hpp\"\n\nusing namespace std;\nusing namespace\
    \ kyopro;\n\nusing u32 = uint32_t;\nconst int offset = 1e9;\n\nint main() {\n\
    \    int n, q;\n    read(n, q);\n\n    BinaryTrie<u32, 32> pq;\n\n    rep(i, n)\
    \ {\n        int s;\n        read(s);\n        pq.insert(s + offset);\n    }\n\
    \n    while (q--) {\n        int t;\n        read(t);\n\n        if (t == 0) {\n\
    \            int x;\n            read(x);\n            pq.insert(x + offset);\n\
    \        } else if (t == 1) {\n            u32 mn = pq.min();\n            pq.erase(mn);\n\
    \n            put((int)mn - offset);\n        } else {\n            u32 mx = pq.max();\n\
    \            pq.erase(mx);\n\n            put((int)mx - offset);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/data-structure/BinaryTrie.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 22:53:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
- /verify/test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp.html
title: test/yosupo_judge/data_structure/Double-Ended_Priority_Queue_Trie.test.cpp
---
