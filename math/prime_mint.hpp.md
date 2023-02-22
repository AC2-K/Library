---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Library-Checker/Point Set Range Composite.test.cpp
    title: test/Library-Checker/Point Set Range Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: modint
    links: []
  bundledCode: "#line 1 \"math/prime_mint.hpp\"\ntemplate<const ll mod>class modint\
    \ {\nprivate:\n\tusing mint = modint<mod>;\n\tll value = 0;\npublic:\n\tmodint(ll\
    \ v = 0) {\n\t\tv %= mod;\n\t\tif(v < 0)v += mod;\n\t\tvalue = v;\n\t}\n\tll val()\
    \ {\n\t\treturn value % mod;\n\t}\n\tmint operator+(mint fp) {\n\t\treturn mint(value\
    \ + fp.val());\n\t}\n\tmint operator-(mint fp) {\n\t\treturn mint(value - fp.val());\n\
    \t}\n\tmint operator*(mint fp) {\n\t\treturn mint(value * fp.val());\n\t}\n\t\
    void operator=(mint fp) {\n\t\tvalue = fp.val();\n\t}\n\tvoid operator=(ll val)\
    \ {\n\t\tvalue = val % mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\
    \t}\n\tvoid operator+=(mint fp) {\n\t\t(value += fp.val()) %= mod;\n\t\tif(value\
    \ < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t}\n\tvoid operator-=(mint fp) {\n\t\t\
    value = value - fp.val();\n\t\tvalue %= mod;\n\t\tif(value < 0) {\n\t\t\tvalue\
    \ += mod;\n\t\t}\n\t}\n\tvoid operator*=(mint fp) {\n\t\tvalue = value * fp.val();\n\
    \t\tvalue = value % mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t\
    }\n\tbool operator==(mint fp) {\n\t\treturn value == fp.val();\n\t}\n\tbool operator<(mint\
    \ fp) {\n\t\treturn value < fp.val();\n\t}\n\tbool operator>(mint fp) {\n\t\t\
    return value > fp.val();\n\t}\n\tbool operator<=(mint fp) {\n\t\treturn value\
    \ <= fp.val();\n\t}\n\tbool operator>=(mint fp) {\n\t\treturn value >= fp.val();\n\
    \t}\n\n\tll inv() {\n\t\treturn mod_pow(mod - 2);\n\t}\n\tll mod_pow(ll exp) {\n\
    \t\tll base = value;\n\t\tll ans = 1;\n\t\tbase %= mod;\n\t\twhile (exp > 0) {\n\
    \t\t\tif (exp & 1) {\n\t\t\t\tans *= base;\n\t\t\t\tans %= mod;\n\t\t\t}\n\t\t\
    \tbase *= base;\n\t\t\tbase %= mod;\n\t\t\texp >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\tstatic ll mod_pow(ll base,ll exp){\n\t\tll ans = 1;\n\t\tbase %= mod;\n\
    \t\twhile (exp > 0) {\n\t\t\tif (exp & 1) {\n\t\t\t\tans *= base;\n\t\t\t\tans\
    \ %= mod;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\tbase %= mod;\n\t\t\texp >>= 1;\n\
    \t\t}\n\t\treturn ans;\n\t}\n\tmint operator/(mint a) {\n\t\treturn mint(a.inv()*value);\n\
    \t}\n\tvoid operator/=(mint a) {\n\t\tvalue = value * a.inv();\n\t\tvalue %= mod;\n\
    \t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\tll v;\n\t\tis\
    \ >> v;\n\t\tmt = mint(v);\n\t\treturn is;\n\t}\n\tfriend ostream& operator <<\
    \ (ostream& os, mint& mt) {\n\t\treturn os << mt.val();\n\t}\n};\n\n///@brief\
    \ modint\n"
  code: "template<const ll mod>class modint {\nprivate:\n\tusing mint = modint<mod>;\n\
    \tll value = 0;\npublic:\n\tmodint(ll v = 0) {\n\t\tv %= mod;\n\t\tif(v < 0)v\
    \ += mod;\n\t\tvalue = v;\n\t}\n\tll val() {\n\t\treturn value % mod;\n\t}\n\t\
    mint operator+(mint fp) {\n\t\treturn mint(value + fp.val());\n\t}\n\tmint operator-(mint\
    \ fp) {\n\t\treturn mint(value - fp.val());\n\t}\n\tmint operator*(mint fp) {\n\
    \t\treturn mint(value * fp.val());\n\t}\n\tvoid operator=(mint fp) {\n\t\tvalue\
    \ = fp.val();\n\t}\n\tvoid operator=(ll val) {\n\t\tvalue = val % mod;\n\t\tif(value\
    \ < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t}\n\tvoid operator+=(mint fp) {\n\t\t\
    (value += fp.val()) %= mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\
    \t}\n\tvoid operator-=(mint fp) {\n\t\tvalue = value - fp.val();\n\t\tvalue %=\
    \ mod;\n\t\tif(value < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t}\n\tvoid operator*=(mint\
    \ fp) {\n\t\tvalue = value * fp.val();\n\t\tvalue = value % mod;\n\t\tif(value\
    \ < 0) {\n\t\t\tvalue += mod;\n\t\t}\n\t}\n\tbool operator==(mint fp) {\n\t\t\
    return value == fp.val();\n\t}\n\tbool operator<(mint fp) {\n\t\treturn value\
    \ < fp.val();\n\t}\n\tbool operator>(mint fp) {\n\t\treturn value > fp.val();\n\
    \t}\n\tbool operator<=(mint fp) {\n\t\treturn value <= fp.val();\n\t}\n\tbool\
    \ operator>=(mint fp) {\n\t\treturn value >= fp.val();\n\t}\n\n\tll inv() {\n\t\
    \treturn mod_pow(mod - 2);\n\t}\n\tll mod_pow(ll exp) {\n\t\tll base = value;\n\
    \t\tll ans = 1;\n\t\tbase %= mod;\n\t\twhile (exp > 0) {\n\t\t\tif (exp & 1) {\n\
    \t\t\t\tans *= base;\n\t\t\t\tans %= mod;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\t\
    base %= mod;\n\t\t\texp >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\tstatic ll mod_pow(ll\
    \ base,ll exp){\n\t\tll ans = 1;\n\t\tbase %= mod;\n\t\twhile (exp > 0) {\n\t\t\
    \tif (exp & 1) {\n\t\t\t\tans *= base;\n\t\t\t\tans %= mod;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\tbase %= mod;\n\t\t\texp >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\
    \tmint operator/(mint a) {\n\t\treturn mint(a.inv()*value);\n\t}\n\tvoid operator/=(mint\
    \ a) {\n\t\tvalue = value * a.inv();\n\t\tvalue %= mod;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\tll v;\n\t\tis >> v;\n\t\tmt = mint(v);\n\
    \t\treturn is;\n\t}\n\tfriend ostream& operator << (ostream& os, mint& mt) {\n\
    \t\treturn os << mt.val();\n\t}\n};\n\n///@brief modint"
  dependsOn: []
  isVerificationFile: false
  path: math/prime_mint.hpp
  requiredBy: []
  timestamp: '2023-02-21 13:24:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Library-Checker/Point Set Range Composite.test.cpp
documentation_of: math/prime_mint.hpp
layout: document
redirect_from:
- /library/math/prime_mint.hpp
- /library/math/prime_mint.hpp.html
title: modint
---
