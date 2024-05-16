---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/hash_map.hpp
    title: Hash Map
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':question:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#line\
    \ 2 \"src/data-structure/hash_map.hpp\"\n#include <chrono>\n#include <utility>\n\
    #include <cmath>\n#include <bits/stl_algobase.h>\n\nnamespace kyopro {\ntemplate\
    \ <typename Key,\n          typename Val,\n          std::size_t n = 1 << 20,\n\
    \          Val default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64* flag = new u64[n / 64];\n    Key* keys\
    \ = new Key[n];\n    Val* vals = new Val[n];\n\n    static constexpr u32 shift\
    \ = 64 - std::__lg(n);\n\n    u64 r;\n    u32 get_hash(Key k) const { return ((u64)k\
    \ * r) >> shift; }\n\n    static constexpr int block = 64;\n\npublic:\n    explicit\
    \ hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](Key\
    \ k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if\
    \ (~flag[hash / block] >> (hash % block) & static_cast<u64>(1)) {\n          \
    \      keys[hash] = k;\n                flag[hash / block] |= (static_cast<u64>(1)\
    \ << (hash % block));\n                return vals[hash] = default_val;\n    \
    \        }\n\n            if (keys[hash] == k) return vals[hash];\n          \
    \  hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    Val* find(Key k) const\
    \ {\n        u32 hash = get_hash(k);\n        while (1) {\n            if (~flag[hash\
    \ / block] >> (hash % block) & static_cast<u64>(1)) {\n                return\
    \ nullptr;\n            }\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Hash Map\n */\n#line 2 \"src/stream.hpp\"\n#include\
    \ <ctype.h>\n#include <stdio.h>\n#include <string>\n#line 2 \"src/internal/type_traits.hpp\"\
    \n#include <iostream>\n#include <limits>\n#include <numeric>\n#include <typeinfo>\n\
    #include <cstdint>\n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename...\
    \ Args> struct first_enabled {};\n\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<true, T>, Args...> {\n    using type = T;\n\
    };\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct int_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::int8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::int16_t>,\n \
    \                                std::enable_if<dgt <= 32, std::int32_t>,\n  \
    \                               std::enable_if<dgt <= 64, std::int64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __int128_t>>;\n};\n\n\
    template <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
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
    \ 4 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\n\n\
    using namespace std;\nusing namespace kyopro;\n\nint main() {\n    int q;\n  \
    \  read(q);\n    hash_map<__uint64_t, __uint64_t> mp;\n    while (q--) {\n   \
    \     int t;\n        read(t);\n        if (!t) {\n            __uint64_t k, v;\n\
    \            read(k, v);\n            mp[k] = v;\n        } else {\n         \
    \   __uint64_t k;\n            read(k);\n            put(mp[k]);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../../../src/data-structure/hash_map.hpp\"\n#include \"../../../src/stream.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int q;\n\
    \    read(q);\n    hash_map<__uint64_t, __uint64_t> mp;\n    while (q--) {\n \
    \       int t;\n        read(t);\n        if (!t) {\n            __uint64_t k,\
    \ v;\n            read(k, v);\n            mp[k] = v;\n        } else {\n    \
    \        __uint64_t k;\n            read(k);\n            put(mp[k]);\n      \
    \  }\n    }\n}\n"
  dependsOn:
  - src/data-structure/hash_map.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  requiredBy: []
  timestamp: '2024-05-16 17:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp.html
title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
---
