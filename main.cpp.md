---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':warning:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n\
    #define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll =\
    \ long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\nusing\
    \ P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr\
    \ ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9\
    \ + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0\
    \ };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 2 \"math/barrett.hpp\"\nnamespace internal {\n\t//burret reduction\n\tclass\
    \ barrett {\n\t\tusing u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\tu32 m;\n\
    \t\tu64 im;\n\tpublic:\n\t\texplicit barrett() = default;\n\t\texplicit barrett(const\
    \ u32& m_) :m(m_), im((u64)(-1) / m_ + 1) {}\n\n\t\tu32 get_mod() const { return\
    \ m; }\n\t\tu32 mul(u32 a, u32 b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\t\t\treturn\
    \ 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\t\t\tu64 x;\n\
    \n\t\t\t_umul128(z, im, &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n#endif\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v +=\
    \ m;\n\t\t\treturn v;\n\t\t}\n\t};\n}\n#line 3 \"math/dynamic_modint.hpp\"\nclass\
    \ dynamic_modint32 {\n\tusing u32 = uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing\
    \ i32 = int32_t;\n\tusing i64 = int64_t;\n\tusing br = internal::barrett;\n\n\t\
    static br brt;\n\tstatic u32 mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(const\
    \ u32& mod_) {\n\t\tbrt = br(mod_);\t//change burrett\n\t\tmod = mod_;\n\t}\n\
    private:\n\tu32 normalize(const i64& x) const {\n\t\tu32 m = x % mod;\n\t\tif\
    \ (m < 0) {\n\t\t\tm += mod;\n\t\t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32()\
    \ :v(0) { assert(mod); }\n\tdynamic_modint32(const i64& v_) :v(normalize(v_))\
    \ { assert(mod); }\n\n\tu32 val() const { return v; }\n\n\tusing mint = dynamic_modint32;\n\
    \n\t//operators\n\tmint& operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\
    \treturn (*this);\n\t}\n\tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\
    \tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const\
    \ mint&r) {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\
    \n\t\treturn (*this);\n\t}\n\tmint& operator*=(const mint& r) {\n\t\tv = brt.mul(v,\
    \ r.v);\n\t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const { return\
    \ mint(*this) += r; }\n\tmint operator-(const mint& r) const { return mint(*this)\
    \ -= r; }\n\tmint operator*(const mint& r) const { return mint(*this) *= r; }\n\
    \n\n\n\tmint& operator+= (const i64& r) { return (*this) += mint(r); }\n\tmint&\
    \ operator-= (const i64& r) { return (*this) -= mint(r); }\n\tmint& operator*=\
    \ (const i64& r) { return (*this) *= mint(r); }\n\n\tfriend mint operator+(const\
    \ i64& l, const mint& r) { return mint(l) += r; }\n\tfriend mint operator+(const\
    \ mint& l, const i64& r) { return mint(l) += r; }\n\tfriend mint operator-(const\
    \ i64& l, const mint& r) { return mint(l) -= r; }\n\tfriend mint operator-(const\
    \ mint& l, const i64& r) { return mint(l) -= r; }\n\tfriend mint operator*(const\
    \ i64& l, const mint& r) { return mint(l) *= r; }\n\tfriend mint operator*(const\
    \ mint& l, const i64& r) { return mint(l) += r; }\n\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n\tmint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\
    \n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te\
    \ >>= 1;\n\t\t\tbase *= base;\n\t\t}\n\t\treturn base;\n\t}\n\tmint inv() const\
    \ {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) { return\
    \ (*this) *= r.inv(); }\n\tmint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n\tmint& operator/=(const i64& r) { return (*this) /= mint(r);\
    \ }\n\tfriend mint operator/(const mint& l, const i64& r) { return mint(l) /=\
    \ r; }\n\tfriend mint operator/(const i64& l, const mint& r) { return mint(l)\
    \ /= r; }\n};\ntypename dynamic_modint32::u32 dynamic_modint32::mod;\ntypename\
    \ dynamic_modint32::br dynamic_modint32::brt;\n\n///@brief dynamic modint(\u52D5\
    \u7684modint)\n///@docs docs/math/dynamic_modint.md\n#line 3 \"main.cpp\"\n\n\
    int mod;\nint q = 100000;\nbool is_prime(int q) {\n    if (q < 2) {\n        return\
    \ false;\n    }\n    if (q == 2) {\n        return true;\n    }\n    if (~q &\
    \ 1) {\n        return false;\n    }\n    for (int d = 2; 1ll * d * d <= q; d++)\
    \ {\n        if (q % d == 0) {\n            return false;\n        }\n    }\n\
    \    return true;\n}\nvoid test() {\n    using mint = dynamic_modint32;\n    mod\
    \ = rand();\n    if(!is_prime(mod)){\n        return;\n    }\n    q--;\n    mint::set_mod(mod);\n\
    \    mint ma = rand(), mb = rand();\n    if (mb.val() == 0) {\n        q++;\n\
    \        return;\n    }\n    mint mc = ma / mb;\n    if ((mc * mb).val() != ma.val())\
    \ {\n\n    }\n}\nint main() {\n    while(q){\n        test();\n    }\n}\n"
  code: "#include\"template.hpp\"\n#include\"math/dynamic_modint.hpp\"\n\nint mod;\n\
    int q = 100000;\nbool is_prime(int q) {\n    if (q < 2) {\n        return false;\n\
    \    }\n    if (q == 2) {\n        return true;\n    }\n    if (~q & 1) {\n  \
    \      return false;\n    }\n    for (int d = 2; 1ll * d * d <= q; d++) {\n  \
    \      if (q % d == 0) {\n            return false;\n        }\n    }\n    return\
    \ true;\n}\nvoid test() {\n    using mint = dynamic_modint32;\n    mod = rand();\n\
    \    if(!is_prime(mod)){\n        return;\n    }\n    q--;\n    mint::set_mod(mod);\n\
    \    mint ma = rand(), mb = rand();\n    if (mb.val() == 0) {\n        q++;\n\
    \        return;\n    }\n    mint mc = ma / mb;\n    if ((mc * mb).val() != ma.val())\
    \ {\n\n    }\n}\nint main() {\n    while(q){\n        test();\n    }\n}"
  dependsOn:
  - template.hpp
  - math/dynamic_modint.hpp
  - math/barrett.hpp
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-03-10 13:31:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
