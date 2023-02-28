---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: rolling hash
    links: []
  bundledCode: "#line 1 \"out.cpp\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x)\
    \ (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\n\
    using ll = long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\n\
    using P = pair<int, int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\n\
    const ll MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0 };\nconst int dy[4] =\
    \ { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/large_mod.hpp\"\n\
    inline long long safe_mod(long long a, long long m) {\n    return (a % m + m)\
    \ % m;\n}\ninline long long mul(long long a, long long b, long long m) {\n   \
    \ a = safe_mod(a, m); b = safe_mod(b, m);\n    if (b == 0) return 0;\n    long\
    \ long res = mul(safe_mod(a + a, m), b>>1, m);\n    if (b & 1) res = safe_mod(res\
    \ + a, m);\n    return res;\n}\ntemplate<typename T>\n__uint128_t large_modpow(T\
    \ base,T exp,T mod){\n    if(base==0)return 0;\n    __uint128_t ans = 1;\n   \
    \ base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans = mul(ans,base,mod);\n\
    \        }\n        base = mul(base,base,mod);\n        exp >>= 1;\n    }\n  \
    \  return ans;\n}\n#line 3 \"string/rolling_hash.hpp\"\nusing ull = uint_fast64_t;\n\
    \n\nnamespace for_hash {\n\tconstexpr ull mapping_max = (ull)'Z';\n\tull base\
    \ = -1;\t//base\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u3068\u308B\n\tconstexpr ull\
    \ mod = (1uL << 61) - 1;\n\tconstexpr ull primitive_root = 37;\n\tull strong_rand()\
    \ {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ull> rand(1uL, mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\tvoid generate_base() {\n        if(base != -1) return;\n\t\tull r = mod\
    \ - 1;\n\t\twhile (gcd(r, mod - 1) != 1 || r <= mapping_max) {\n\t\t\tr = strong_rand();\n\
    \t\t}\n\t\tbase = large_modpow(primitive_root, r, mod);\n\t}\n};\n\nclass RollingHash\
    \ {\n\tusing i128 = __int128_t;\t//\u5909\u3048\u307E\u3057\u3087\u3046\u306D\
    ~\n\tstatic constexpr ull msk30 = (1ul << 30) - 1;\n\tstatic constexpr ull msk61\
    \ = (1ul << 31) - 1;\n\tstring str;\n\tvector<ull> hash, pow;\n\n\n\tull mul(i128\
    \ a, i128 b)const {\n\t\ti128 t = a * b;\n\n\t\tt = (t >> 61) + (t & for_hash::mod);\n\
    \n\t\tif (t >= for_hash::mod) {\n\t\t\tt -= for_hash::mod;\n\t\t}\n\n\n\t\treturn\
    \ t;\n\t}\n\n\tull mapping(const char& c) {\n\t\treturn (ull)c;\t//\u5909\u66F4\
    \u3059\u308B?\n\t}\npublic:\n\tRollingHash() :str() {\t}\n\n\tRollingHash(const\
    \ string& str) :str(str) {\n\t\tfor_hash::generate_base();\n\t\tbuild();\n\t}\n\
    \n\tvoid build() {\n\t\thash.resize(str.size() + 1);\n\t\tpow.resize(str.size()\
    \ + 1, 1);\n\n\t\tfor (int i = 0; i < str.size(); i++) {\n\t\t\thash[i + 1] =\
    \ mul(hash[i], for_hash::base) + mapping(str[i]);\n\t\t\tpow[i + 1] = mul(pow[i],\
    \ for_hash::base);\n\t\t\tif (hash[i + 1] >= for_hash::mod) {\n\t\t\t\thash[i\
    \ + 1] -= for_hash::mod;\n\t\t\t}\n\t\t}\n\t}\n\tull range(int l, int r) const\
    \ {\n\t\tull ret = for_hash::mod + hash[r] - mul(hash[l], pow[r - l]);\n\t\treturn\
    \ ret < for_hash::mod ? ret : ret - for_hash::mod;\n\t}\n\tint size(){return str.size();}\n\
    };\n\n///@brief rolling hash\n#line 3 \"main.cpp\"\n\nint main(){\n    int n;\n\
    \    cin>>n;\n    vector<RollingHash> s(n);\n    rep(i,n){\n        string si;\n\
    \        cin>>si;\n        s[i]=RollingHash(si);\n    }\n\n    unordered_map<int,unordered_map<ull,int>>\
    \ prefixes;  //\u5148\u982Di\u6587\u5B57\u3092\u4E26\u3079\u307E\u304F\u3063\u305F\
    \u3084\u3064\n    for(auto&h:s){\n        rep(len,h.size()+1){\n            prefixes[len][h.range(0,len)]++;\n\
    \        }\n    }\n \n    for(auto&hs:s){\n        int ng=hs.size()+1;\n     \
    \   int ok=0;\n        while(abs(ok-ng)>1){\n            int mid=(ok+ng)/2;\n\
    \            if(prefixes[mid][hs.range(0,mid)]>=2){\n                ok=mid;\n\
    \            }else{\n                ng=mid;\n            }\n        }\n     \
    \   cout<<ok<<endl;\n    }\n\n}\n"
  code: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n\
    #define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconst int inf = 1e9;\nconst ll infl = 1e18;\nconst ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconst ll MOD = 1e9 + 7;\nconst ll\
    \ MOD2 = 998244353;\nconst int dx[4] = { 1,0,-1,0 };\nconst int dy[4] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/large_mod.hpp\"\n\
    inline long long safe_mod(long long a, long long m) {\n    return (a % m + m)\
    \ % m;\n}\ninline long long mul(long long a, long long b, long long m) {\n   \
    \ a = safe_mod(a, m); b = safe_mod(b, m);\n    if (b == 0) return 0;\n    long\
    \ long res = mul(safe_mod(a + a, m), b>>1, m);\n    if (b & 1) res = safe_mod(res\
    \ + a, m);\n    return res;\n}\ntemplate<typename T>\n__uint128_t large_modpow(T\
    \ base,T exp,T mod){\n    if(base==0)return 0;\n    __uint128_t ans = 1;\n   \
    \ base %= mod;\n    while (exp) {\n        if (exp & 1) {\n            ans = mul(ans,base,mod);\n\
    \        }\n        base = mul(base,base,mod);\n        exp >>= 1;\n    }\n  \
    \  return ans;\n}\n#line 3 \"string/rolling_hash.hpp\"\nusing ull = uint_fast64_t;\n\
    \n\nnamespace for_hash {\n\tconstexpr ull mapping_max = (ull)'Z';\n\tull base\
    \ = -1;\t//base\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u3068\u308B\n\tconstexpr ull\
    \ mod = (1uL << 61) - 1;\n\tconstexpr ull primitive_root = 37;\n\tull strong_rand()\
    \ {\n\t\tmt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\tuniform_int_distribution<ull> rand(1uL, mod - 1);\n\t\treturn rand(engine);\n\
    \t}\n\tvoid generate_base() {\n        if(base != -1) return;\n\t\tull r = mod\
    \ - 1;\n\t\twhile (gcd(r, mod - 1) != 1 || r <= mapping_max) {\n\t\t\tr = strong_rand();\n\
    \t\t}\n\t\tbase = large_modpow(primitive_root, r, mod);\n\t}\n};\n\nclass RollingHash\
    \ {\n\tusing i128 = __int128_t;\t//\u5909\u3048\u307E\u3057\u3087\u3046\u306D\
    ~\n\tstatic constexpr ull msk30 = (1ul << 30) - 1;\n\tstatic constexpr ull msk61\
    \ = (1ul << 31) - 1;\n\tstring str;\n\tvector<ull> hash, pow;\n\n\n\tull mul(i128\
    \ a, i128 b)const {\n\t\ti128 t = a * b;\n\n\t\tt = (t >> 61) + (t & for_hash::mod);\n\
    \n\t\tif (t >= for_hash::mod) {\n\t\t\tt -= for_hash::mod;\n\t\t}\n\n\n\t\treturn\
    \ t;\n\t}\n\n\tull mapping(const char& c) {\n\t\treturn (ull)c;\t//\u5909\u66F4\
    \u3059\u308B?\n\t}\npublic:\n\tRollingHash() :str() {\t}\n\n\tRollingHash(const\
    \ string& str) :str(str) {\n\t\tfor_hash::generate_base();\n\t\tbuild();\n\t}\n\
    \n\tvoid build() {\n\t\thash.resize(str.size() + 1);\n\t\tpow.resize(str.size()\
    \ + 1, 1);\n\n\t\tfor (int i = 0; i < str.size(); i++) {\n\t\t\thash[i + 1] =\
    \ mul(hash[i], for_hash::base) + mapping(str[i]);\n\t\t\tpow[i + 1] = mul(pow[i],\
    \ for_hash::base);\n\t\t\tif (hash[i + 1] >= for_hash::mod) {\n\t\t\t\thash[i\
    \ + 1] -= for_hash::mod;\n\t\t\t}\n\t\t}\n\t}\n\tull range(int l, int r) const\
    \ {\n\t\tull ret = for_hash::mod + hash[r] - mul(hash[l], pow[r - l]);\n\t\treturn\
    \ ret < for_hash::mod ? ret : ret - for_hash::mod;\n\t}\n\tint size(){return str.size();}\n\
    };\n\n///@brief rolling hash\n#line 3 \"main.cpp\"\n\nint main(){\n    int n;\n\
    \    cin>>n;\n    vector<RollingHash> s(n);\n    rep(i,n){\n        string si;\n\
    \        cin>>si;\n        s[i]=RollingHash(si);\n    }\n\n    unordered_map<int,unordered_map<ull,int>>\
    \ prefixes;  //\u5148\u982Di\u6587\u5B57\u3092\u4E26\u3079\u307E\u304F\u3063\u305F\
    \u3084\u3064\n    for(auto&h:s){\n        rep(len,h.size()+1){\n            prefixes[len][h.range(0,len)]++;\n\
    \        }\n    }\n \n    for(auto&hs:s){\n        int ng=hs.size()+1;\n     \
    \   int ok=0;\n        while(abs(ok-ng)>1){\n            int mid=(ok+ng)/2;\n\
    \            if(prefixes[mid][hs.range(0,mid)]>=2){\n                ok=mid;\n\
    \            }else{\n                ng=mid;\n            }\n        }\n     \
    \   cout<<ok<<endl;\n    }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2023-02-28 21:29:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: rolling hash
---
