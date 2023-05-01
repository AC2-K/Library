---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/hash_map.hpp\"\n#include <bits/stl_algobase.h>\n\
    #include <chrono>\nnamespace kyopro {\n/// @brief HashMap\ntemplate <typename\
    \ Key,\n          typename Val,\n          uint32_t n = 1 << 17,\n          Val\
    \ default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\npublic:\n    struct data {\n        Key key;\n        Val\
    \ val;\n    };\nprivate:\n    u64 flag[n >> 6];\n    data dat[n];\n\n    static\
    \ constexpr u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    u32 get_hash(const\
    \ Key& k) const { return ((u64)k * r) >> shift; }\n\n    static constexpr uint8_t\
    \ mod_msk = (1 << 6) - 1;\n\npublic:\n    explicit constexpr hash_map() {\n  \
    \      r = std::chrono::steady_clock::now().time_since_epoch().count();\n    \
    \    r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const Key&\
    \ k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n            if\
    \ (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash & mod_msk))))\
    \ {\n                dat[hash].key = k;\n                flag[hash >> 6] |= (static_cast<u64>(1)\
    \ << (hash & mod_msk));\n\n                return dat[hash].val = default_val;\n\
    \            }\n\n            if (dat[hash].key == k) return dat[hash].val;\n\
    \            if (++hash == n) hash = 0;\n        }\n    }\n    Val* find(const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n        while (1) {\n          \
    \  if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk)))){\n    \
    \            return nullptr;\n            }\n            if (dat[hash].key ==\
    \ k) return &(dat[hash].val);\n            if (++hash == n) hash = 0;\n\n    \
    \    }\n    }\n};\n};  // namespace kyopro\n#line 4 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\
    \nint main() {\n    int q;\n    scanf(\"%d\", &q);\n    kyopro::hash_map<long\
    \ long, long long,1<<20> mp;\n    while (q--) {\n        int t;\n        scanf(\"\
    %d\", &t);\n        if (!t) {\n            long long k, v;\n            scanf(\"\
    %lld%lld\", &k, &v);\n            mp[k] = v;\n        } else {\n            long\
    \ long k;\n            scanf(\"%lld\", &k);\n            auto p = mp.find(k);\n\
    \            printf(\"%lld\\n\", (p ? *p : 0LL));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <iostream>\n#include \"../../../src/data-structure/hash_map.hpp\"\nint main()\
    \ {\n    int q;\n    scanf(\"%d\", &q);\n    kyopro::hash_map<long long, long\
    \ long,1<<20> mp;\n    while (q--) {\n        int t;\n        scanf(\"%d\", &t);\n\
    \        if (!t) {\n            long long k, v;\n            scanf(\"%lld%lld\"\
    , &k, &v);\n            mp[k] = v;\n        } else {\n            long long k;\n\
    \            scanf(\"%lld\", &k);\n            auto p = mp.find(k);\n        \
    \    printf(\"%lld\\n\", (p ? *p : 0LL));\n        }\n    }\n}\n"
  dependsOn:
  - src/data-structure/hash_map.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  requiredBy: []
  timestamp: '2023-05-01 10:46:37+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp.html
title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
---
