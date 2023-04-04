---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: HashMap
    links: []
  bundledCode: "#line 1 \"data-structure/hash_map.hpp\"\n/// @brief HashMap\n/// @tparam\
    \ Key Key\u306E\u578B\n/// @tparam Val Value\u306E\u578B\ntemplate <typename Key,\n\
    \          typename Val,\n          uint32_t n = 1 << 20,\n          Val default_val\
    \ = Val(),\n          Key unused = numeric_limits<Key>::max()>\nclass hash_map\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n\n\n    bitset<n>\
    \ flag;\n    vector<Key> keys;\n    vector<Val> vals;\n    static constexpr u32\
    \ shift = 64 - __lg(n);\n\n\n\n    static constexpr u64 rng() {\n        u64 v\
    \ = chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n\n        v ^= v >> 16;\n        v ^= v << 32;\n     \
    \   return v;\n    }\n    \n    u64 r = rng();\n    inline constexpr u64 get_hash(const\
    \ Key& k)const {\n        return (u64(k) * r) >> shift;\n    }\npublic:\n    hash_map()\
    \ :\n        keys(n),\n        vals(n,default_val)\n    {}\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!flag[hash]) {\n                keys[hash] = k;\n                flag[hash]\
    \ = true;\n                return vals[hash] = default_val;\n            }\n\n\
    \n            if (keys[hash] == k)return vals[hash];\n\n            hash = (hash\
    \ + 1) & (n - 1);    //1\u9032\u3081\u308B\n        }\n    }\n};\n"
  code: "/// @brief HashMap\n/// @tparam Key Key\u306E\u578B\n/// @tparam Val Value\u306E\
    \u578B\ntemplate <typename Key,\n          typename Val,\n          uint32_t n\
    \ = 1 << 20,\n          Val default_val = Val(),\n          Key unused = numeric_limits<Key>::max()>\n\
    class hash_map {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n\n\n\
    \    bitset<n> flag;\n    vector<Key> keys;\n    vector<Val> vals;\n    static\
    \ constexpr u32 shift = 64 - __lg(n);\n\n\n\n    static constexpr u64 rng() {\n\
    \        u64 v = chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n\n        v ^= v >> 16;\n        v ^= v << 32;\n     \
    \   return v;\n    }\n    \n    u64 r = rng();\n    inline constexpr u64 get_hash(const\
    \ Key& k)const {\n        return (u64(k) * r) >> shift;\n    }\npublic:\n    hash_map()\
    \ :\n        keys(n),\n        vals(n,default_val)\n    {}\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!flag[hash]) {\n                keys[hash] = k;\n                flag[hash]\
    \ = true;\n                return vals[hash] = default_val;\n            }\n\n\
    \n            if (keys[hash] == k)return vals[hash];\n\n            hash = (hash\
    \ + 1) & (n - 1);    //1\u9032\u3081\u308B\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/hash_map.hpp
  requiredBy: []
  timestamp: '2023-04-04 12:29:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/hash_map.hpp
layout: document
redirect_from:
- /library/data-structure/hash_map.hpp
- /library/data-structure/hash_map.hpp.html
title: HashMap
---
