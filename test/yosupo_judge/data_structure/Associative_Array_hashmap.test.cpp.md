---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/hash_map.hpp
    title: Hash Map
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: fastIO
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
    \ 2 \"src/data-structure/hash_map.hpp\"\n#include <bits/stl_algobase.h>\n#include\
    \ <chrono>\nnamespace kyopro {\n/**\n * @brief Hash Map\n */\ntemplate <typename\
    \ Key,\n          typename Val,\n          uint32_t n = 1 << 20,\n          Val\
    \ default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    u64* flag = new u64[n];\n    Key* keys = new Key[n];\n\
    \    Val* vals = new Val[n];\n\n    static constexpr u32 shift = 64 - std::__lg(n);\n\
    \n    u64 r;\n    u32 get_hash(const Key& k) const { return ((u64)k * r) >> shift;\
    \ }\n\n    static constexpr int mod_msk = (1 << 6) - 1;\n\npublic:\n    explicit\
    \ constexpr hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash\
    \ & mod_msk)))) {\n                keys[hash] = k;\n                flag[hash\
    \ >> 6] |= static_cast<u64>(1) << (hash & mod_msk);\n                return vals[hash]\
    \ = default_val;\n            }\n\n            if (keys[hash] == k) return vals[hash];\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    Val* find(const\
    \ Key& k) const {\n        u32 hash = get_hash(k);\n        while (1) {\n    \
    \        if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))\n\
    \                return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @docs docs/data-structure/hash_map.md\n */\n#line 2 \"src/stream.hpp\"\
    \n#include <ctype.h>\n#include <stdio.h>\n#include <string>\nnamespace kyopro\
    \ {\n\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\n */\ntemplate <typename\
    \ T> constexpr inline void readint(T& a) {\n    a = 0;\n    bool is_negative =\
    \ false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n       \
    \ c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c = getchar_unlocked();\n\
    \    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n\
    \    }\n    if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename...\
    \ Tail>\nconstexpr inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n\
    \    readint(tail...);\n}\n\ntemplate <typename T> void write_int(T a) {\n   \
    \ if (!a) {\n        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n\
    \        return;\n    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char\
    \ s[37];\n    int now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a\
    \ % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\nvoid readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\nvoid putstr(const std::string& str) {\n    for (auto c : str) {\n \
    \       putchar_unlocked(c);\n    }\n    putchar_unlocked('\\n');\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 4 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\
    \nint main() {\n    uint32_t q;\n    kyopro::readint(q);\n    kyopro::hash_map<__uint64_t,\
    \ __uint64_t> mp;\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n\
    \        if (!t) {\n            __uint64_t k, v;\n            kyopro::readint(k,\
    \ v);\n            mp[k] = v;\n        } else {\n            __uint64_t k;\n \
    \           kyopro::readint(k);\n            kyopro::putint(mp[k]);\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ \"../../../src/data-structure/hash_map.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nint main() {\n    uint32_t q;\n    kyopro::readint(q);\n    kyopro::hash_map<__uint64_t,\
    \ __uint64_t> mp;\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n\
    \        if (!t) {\n            __uint64_t k, v;\n            kyopro::readint(k,\
    \ v);\n            mp[k] = v;\n        } else {\n            __uint64_t k;\n \
    \           kyopro::readint(k);\n            kyopro::putint(mp[k]);\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/data-structure/hash_map.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  requiredBy: []
  timestamp: '2023-07-03 15:58:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp.html
title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
---
