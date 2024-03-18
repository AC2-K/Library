---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "\u96E2\u6563\u5BFE\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
    title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No430.test.cpp
    title: test/yuki/No430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Hash Map
    links: []
  bundledCode: "#line 2 \"src/data-structure/hash_map.hpp\"\n#include <chrono>\n#include\
    \ <utility>\n#include <cmath>\n#include <bits/stl_algobase.h>\n\nnamespace kyopro\
    \ {\ntemplate <typename Key,\n          typename Val,\n          std::size_t n\
    \ = 1 << 20,\n          Val default_val = Val()>\nclass hash_map {\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64* flag = new u64[n / 64];\n\
    \    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\n    static constexpr\
    \ u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    u32 get_hash(Key k) const\
    \ { return ((u64)k * r) >> shift; }\n\n    static constexpr int block = 64;\n\n\
    public:\n    explicit hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
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
    \ kyopro\n\n/**\n * @brief Hash Map\n */\n"
  code: "#pragma once\n#include <chrono>\n#include <utility>\n#include <cmath>\n#include\
    \ <bits/stl_algobase.h>\n\nnamespace kyopro {\ntemplate <typename Key,\n     \
    \     typename Val,\n          std::size_t n = 1 << 20,\n          Val default_val\
    \ = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    u64* flag = new u64[n / 64];\n    Key* keys = new Key[n];\n    Val* vals\
    \ = new Val[n];\n\n    static constexpr u32 shift = 64 - std::__lg(n);\n\n   \
    \ u64 r;\n    u32 get_hash(Key k) const { return ((u64)k * r) >> shift; }\n\n\
    \    static constexpr int block = 64;\n\npublic:\n    explicit hash_map() {\n\
    \        r = std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \      r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](Key k)\
    \ {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if (~flag[hash\
    \ / block] >> (hash % block) & static_cast<u64>(1)) {\n                keys[hash]\
    \ = k;\n                flag[hash / block] |= (static_cast<u64>(1) << (hash %\
    \ block));\n                return vals[hash] = default_val;\n            }\n\n\
    \            if (keys[hash] == k) return vals[hash];\n            hash = (hash\
    \ + 1) & (n - 1);\n        }\n    }\n\n    Val* find(Key k) const {\n        u32\
    \ hash = get_hash(k);\n        while (1) {\n            if (~flag[hash / block]\
    \ >> (hash % block) & static_cast<u64>(1)) {\n                return nullptr;\n\
    \            }\n            if (keys[hash] == k) return &(vals[hash]);\n     \
    \       hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @brief Hash Map\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/hash_map.hpp
  requiredBy:
  - src/math/mod_log.hpp
  timestamp: '2023-10-23 07:13:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yuki/No430.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
documentation_of: src/data-structure/hash_map.hpp
layout: document
redirect_from:
- /library/src/data-structure/hash_map.hpp
- /library/src/data-structure/hash_map.hpp.html
title: Hash Map
---
