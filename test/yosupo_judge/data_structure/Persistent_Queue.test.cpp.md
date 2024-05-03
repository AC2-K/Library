---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/persistent/queue.hpp
    title: "\u6C38\u7D9AQueue"
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_queue
    links:
    - https://judge.yosupo.jp/problem/persistent_queue
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Persistent_Queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"src/data-structure/persistent/queue.hpp\"\
    \n#include <cassert>\nnamespace kyopro {\n\ntemplate <typename T, int lg = 20>\
    \ class persistent_queue {\n    struct Node {\n        Node() = default;\n   \
    \     uint32_t index;\n        T val;\n        Node* prev[20];\n    };\n\n   \
    \ Node *front_ptr = nullptr, *back_ptr = nullptr;\n    int siz;\n\npublic:\n \
    \   persistent_queue(Node* front_ptr = nullptr,\n                     Node* back_ptr\
    \ = nullptr,\n                     int siz = 0)\n        : front_ptr(front_ptr),\
    \ back_ptr(back_ptr), siz(siz) {}\n    bool empty() { return siz; }\n    persistent_queue\
    \ push(const T& x) {\n        Node* ptr = new Node();\n        ptr->val = x;\n\
    \        ptr->prev[0] = back_ptr;\n        for (int i = 1; i < lg; i++) {\n  \
    \          Node* c = ptr->prev[i - 1];\n            if (c)\n                ptr->prev[i]\
    \ = c->prev[i - 1];\n            else\n                break;\n        }\n\n \
    \       if (siz) {\n            return persistent_queue(front_ptr, ptr, siz +\
    \ 1);\n        } else {\n            return persistent_queue(ptr, ptr, siz + 1);\n\
    \        }\n    }\n    persistent_queue pop() {\n        if (!front_ptr || !back_ptr\
    \ || siz == 1) {\n            return persistent_queue();\n        }\n        int\
    \ d = siz - 2;\n        Node* cur = back_ptr;\n        while (d) {\n         \
    \   int jump = 31 - __builtin_clz(d);\n            d -= (1 << jump);\n       \
    \     cur = cur->prev[jump];\n        }\n\n        return persistent_queue(cur,\
    \ back_ptr, siz - 1);\n    }\n\n    T front() {\n        assert(siz);\n      \
    \  return front_ptr->val;\n    }\n    T back() {\n        assert(siz);\n     \
    \   return back_ptr->val;\n    }\n};\n};  // namespace kyopro\n\n/**\n * @brief\
    \ \u6C38\u7D9AQueue\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include\
    \ <stdio.h>\n#include <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include\
    \ <limits>\n#include <numeric>\n#include <typeinfo>\n#include <cstdint>\n\nnamespace\
    \ kyopro {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled\
    \ {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
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
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n\ninline void single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
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
    \ kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\n */\n#line 6 \"test/yosupo_judge/data_structure/Persistent_Queue.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int q;\n\
    \    read(q);\n    std::vector<kyopro::persistent_queue<int>> v(q + 1);\n    for\
    \ (int i = 1; i <= q; i++) {\n        int t, idx;\n        read(t, idx);\n   \
    \     idx++;\n\n        if (!t) {\n            int s;\n            read(s);\n\
    \            v[i] = v[idx].push(s);\n        } else {\n            put(v[idx].front());\n\
    \            v[i] = v[idx].pop();\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_queue\"\n#include\
    \ <iostream>\n#include <vector>\n#include \"../../../src/data-structure/persistent/queue.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n\nusing namespace std;\nusing namespace\
    \ kyopro;\n\nint main() {\n    int q;\n    read(q);\n    std::vector<kyopro::persistent_queue<int>>\
    \ v(q + 1);\n    for (int i = 1; i <= q; i++) {\n        int t, idx;\n       \
    \ read(t, idx);\n        idx++;\n\n        if (!t) {\n            int s;\n   \
    \         read(s);\n            v[i] = v[idx].push(s);\n        } else {\n   \
    \         put(v[idx].front());\n            v[i] = v[idx].pop();\n        }\n\
    \    }\n}"
  dependsOn:
  - src/data-structure/persistent/queue.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
  requiredBy: []
  timestamp: '2023-10-22 17:20:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
- /verify/test/yosupo_judge/data_structure/Persistent_Queue.test.cpp.html
title: test/yosupo_judge/data_structure/Persistent_Queue.test.cpp
---
