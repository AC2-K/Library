---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
    title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: HashMap
    links: []
  bundledCode: "#line 2 \"src/data-structure/hash_map.hpp\"\n#include <chrono>\nnamespace\
    \ kyopro {\n/// @brief HashMap\ntemplate <typename Key,\n          typename Val,\n\
    \          uint32_t n = 1 << 20,\n          Val default_val = Val()>\nclass hash_map\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64* flag = new\
    \ u64[n];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\n    static\
    \ constexpr u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    inline u32 get_hash(const\
    \ Key& k) const { return ((u64)k * r) >> shift; }\n\n    static constexpr uint8_t\
    \ mod_msk = (1 << 6) - 1;\n\npublic:\n    explicit constexpr hash_map() {\n  \
    \      r = std::chrono::steady_clock::now().time_since_epoch().count();\n    \
    \    r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const Key&\
    \ k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if\
    \ (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash & mod_msk))))\
    \ {\n                keys[hash] = k;\n                flag[hash >> 6] |= static_cast<u64>(1)\
    \ << (hash & mod_msk);\n                return vals[hash] = default_val;\n   \
    \         }\n\n            if (keys[hash] == k) return vals[hash];\n         \
    \   hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    const Val* find(const\
    \ Key& k) const {\n        u32 hash = get_hash(k);\n        while (1) {\n    \
    \        if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))\n\
    \                return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n"
  code: "#pragma once\n#include <chrono>\nnamespace kyopro {\n/// @brief HashMap\n\
    template <typename Key,\n          typename Val,\n          uint32_t n = 1 <<\
    \ 20,\n          Val default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64* flag = new u64[n];\n    Key* keys = new\
    \ Key[n];\n    Val* vals = new Val[n];\n\n    static constexpr u32 shift = 64\
    \ - std::__lg(n);\n\n    u64 r;\n    inline u32 get_hash(const Key& k) const {\
    \ return ((u64)k * r) >> shift; }\n\n    static constexpr uint8_t mod_msk = (1\
    \ << 6) - 1;\n\npublic:\n    explicit constexpr hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash\
    \ & mod_msk)))) {\n                keys[hash] = k;\n                flag[hash\
    \ >> 6] |= static_cast<u64>(1) << (hash & mod_msk);\n                return vals[hash]\
    \ = default_val;\n            }\n\n            if (keys[hash] == k) return vals[hash];\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    const Val*\
    \ find(const Key& k) const {\n        u32 hash = get_hash(k);\n        while (1)\
    \ {\n            if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))\n\
    \                return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/hash_map.hpp
  requiredBy:
  - src/math/mod_log.hpp
  timestamp: '2023-04-23 12:26:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  - test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
documentation_of: src/data-structure/hash_map.hpp
layout: document
redirect_from:
- /library/src/data-structure/hash_map.hpp
- /library/src/data-structure/hash_map.hpp.html
title: HashMap
---