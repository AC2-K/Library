---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/hash_map.hpp
    title: HashMap
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include<iostream>\n\
    #line 2 \"src/data-structure/hash_map.hpp\"\n#include <bits/stl_algobase.h>\n\
    #include <chrono>\nnamespace kyopro {\n/// @brief HashMap\ntemplate <typename\
    \ Key,\n          typename Val,\n          uint32_t n = 1 << 20,\n          Val\
    \ default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    u64* flag = new u64[n];\n    Key* keys = new Key[n];\n\
    \    Val* vals = new Val[n];\n\n    static constexpr u32 shift = 64 - std::__lg(n);\n\
    \n    u64 r;\n    inline u32 get_hash(const Key& k) const { return ((u64)k * r)\
    \ >> shift; }\n\n    static constexpr uint8_t mod_msk = (1 << 6) - 1;\n\npublic:\n\
    \    explicit constexpr hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
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
    \ kyopro\n#line 4 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\
    \nint main() {\n    uint32_t q;\n    scanf(\"%d\", &q);\n    kyopro::hash_map<__uint64_t,\
    \ __uint64_t> mp;\n    while (q--) {\n        int t;\n        scanf(\"%d\",&t);\n\
    \        if(!t){\n            __uint64_t k, v;\n            scanf(\"%lld%lld\"\
    , &k, &v);\n            mp[k] = v;\n        }else{\n            __uint64_t k;\n\
    \            scanf(\"%lld\", &k);\n            printf(\"%lld\\n\", mp[k]);\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include<iostream>\n\
    #include\"../../../src/data-structure/hash_map.hpp\"\nint main() {\n    uint32_t\
    \ q;\n    scanf(\"%d\", &q);\n    kyopro::hash_map<__uint64_t, __uint64_t> mp;\n\
    \    while (q--) {\n        int t;\n        scanf(\"%d\",&t);\n        if(!t){\n\
    \            __uint64_t k, v;\n            scanf(\"%lld%lld\", &k, &v);\n    \
    \        mp[k] = v;\n        }else{\n            __uint64_t k;\n            scanf(\"\
    %lld\", &k);\n            printf(\"%lld\\n\", mp[k]);\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/hash_map.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  requiredBy: []
  timestamp: '2023-05-01 16:04:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp.html
title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
---
