---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/hash_map.hpp
    title: HashMap
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
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
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline\
    \ void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void\
    \ chmin(T&x,T y){if(x>y)x=y;}\n#line 3 \"data-structure/hash_map.hpp\"\n/// @brief\
    \ HashMap\ntemplate <typename Key,\n          typename Val,\n          uint32_t\
    \ n = 1 << 20,\n          Val default_val = Val()\n          >\nclass hash_map\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    u64* flag = new\
    \ u64[n];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\n    static\
    \ constexpr u32 shift = 64 - __lg(n);\n\n    u64 r;\n    inline u32 get_hash(const\
    \ Key& k) const {\n        return ((u64)k * r) >> shift;\n    }\n\n    static\
    \ constexpr uint8_t mod_msk = (1 << 6) - 1;\n\n  public:   \n    explicit constexpr\
    \ hash_map(){\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash\
    \ & mod_msk)))) {\n                keys[hash] = k;\n                flag[hash\
    \ >> 6] |= static_cast<u64>(1)\n                                   << (hash &\
    \ mod_msk);\n                return vals[hash] = default_val;\n            }\n\
    \n            if (keys[hash] == k)return vals[hash];\n            hash = (hash\
    \ + 1) & (n - 1);\n        }\n    }\n\n    const Val* find(const Key&k)const{\n\
    \        u32 hash = get_hash(k);\n        while (1) {\n            if (!(flag[hash\
    \ >> 6] &\n                  (static_cast<u64>(1) << (hash & mod_msk))))\n   \
    \             return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n#line 3 \"test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\nint main()\
    \ {\n    uint32_t q;\n    scanf(\"%d\", &q);\n    hash_map<uint64_t, __uint64_t>\
    \ mp;\n    while (q--) {\n        int t;\n        scanf(\"%d\",&t);\n        if(!t){\n\
    \            __uint64_t k, v;\n            scanf(\"%lld%lld\", &k, &v);\n    \
    \        mp[k] = v;\n        }else{\n            __uint64_t k;\n            scanf(\"\
    %lld\", &k);\n            printf(\"%lld\\n\", mp[k]);\n        }\n    }\n}\n"
  code: "#include\"template.hpp\"\n#include\"data-structure/hash_map.hpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\nint main() {\n\
    \    uint32_t q;\n    scanf(\"%d\", &q);\n    hash_map<uint64_t, __uint64_t> mp;\n\
    \    while (q--) {\n        int t;\n        scanf(\"%d\",&t);\n        if(!t){\n\
    \            __uint64_t k, v;\n            scanf(\"%lld%lld\", &k, &v);\n    \
    \        mp[k] = v;\n        }else{\n            __uint64_t k;\n            scanf(\"\
    %lld\", &k);\n            printf(\"%lld\\n\", mp[k]);\n        }\n    }\n}\n"
  dependsOn:
  - template.hpp
  - data-structure/hash_map.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 13:04:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
- /verify/test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp.html
title: test/yosupo_judge/data_structure/Associative_Array_hashmap.test.cpp
---
