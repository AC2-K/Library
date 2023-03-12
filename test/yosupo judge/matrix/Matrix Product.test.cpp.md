---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett.hpp
    title: math/barrett.hpp
  - icon: ':heavy_check_mark:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: math/matrix.hpp
    title: math/matrix.hpp
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo judge/matrix/Matrix Product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 =\
    \ 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1\
    \ };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class\
    \ T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"math/barrett.hpp\"\nnamespace\
    \ internal {\n\t//barret reduction\n\tclass barrett {\n\t\tusing u32 = uint32_t;\n\
    \t\tusing u64 = uint64_t;\n\n\t\tu32 m;\n\t\tu64 im;\n\tpublic:\n\t\texplicit\
    \ barrett() = default;\n\t\texplicit barrett(const u32& m_) :m(m_), im((u64)(-1)\
    \ / m_ + 1) {}\n\n\t\tu32 get_mod() const { return m; }\n\t\tu32 mul(u32 a, u32\
    \ b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\t\t\treturn 0;\n\t\t\t}\n\t\t\tu64 z\
    \ = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\t\t\tu64 x;\n\n\t\t\t_umul128(z, im,\
    \ &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n#endif\n\n\t\
    \t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\treturn v;\n\t\
    \t}\n\t};\n}\n#line 3 \"math/dynamic_modint.hpp\"\nclass dynamic_modint32 {\n\t\
    using u32 = uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing i32 = int32_t;\n\tusing\
    \ i64 = int64_t;\n\tusing br = internal::barrett;\n\n\tstatic br brt;\n\tstatic\
    \ u32 mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(const u32& mod_)\
    \ {\n\t\tbrt = br(mod_);\n\t\tmod = mod_;\n\t}\nprivate:\n\tu32 normalize(const\
    \ i64& x) const {\n\t\ti32 m = x % mod;\n\t\tif (m < 0) {\n\t\t\tm += mod;\n\t\
    \t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32() :v(0) { assert(mod); }\t\
    //mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \n\tdynamic_modint32(const i64& v_) :v(normalize(v_)) { assert(mod); }\t\n\n\t\
    u32 val() const { return v; }\n\n\tusing mint = dynamic_modint32;\n\n\t//operators\n\
    \tmint& operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\treturn (*this);\n\
    \t}\n\tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod) {\n\
    \t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint&r)\
    \ {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\n\t\t\
    return (*this);\n\t}\n\tmint& operator*=(const mint& r) {\n\t\tv = brt.mul(v,\
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
    \u7684modint)\n///@docs docs/math/dynamic_modint.md\n#line 2 \"math/matrix.hpp\"\
    \ntemplate<typename T>\nclass Matrix {\n    vector<vector<T>> dat;\n    int h,\
    \ w;\npublic:\n    Matrix(const vector<vector<T>>& dat)\n        : dat(dat), h(dat.size()),\
    \ w(dat.front().size()) {}\n\n    Matrix(int h_, int w_, const T& v = T())\n \
    \       : dat(h_, vector<T>(w_, v)){}\n    static Matrix<T> I(int sz) {\n    \
    \    Matrix<T> ans(sz);\n        rep(i, sz) { ans[i][i] = 1; }\n        return\
    \ ans;\n    }\n    using mat = Matrix<T>;\n    //access\n    vector<T>& operator[](int\
    \ i) { return dat[i]; }\n\n    //operator\n    mat& operator+=(const mat& r) {\n\
    \        assert(r.h == this->h);\n        assert(r.w == this->w);\n        for\
    \ (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++) {\n     \
    \           dat[i][j] += r.dat[i][j];\n            }\n        }\n        return\
    \ (*this);\n    }\n    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n\
    \        assert(r.w == this->w);\n        for (int i = 0; i < h; i++) {\n    \
    \        for (int j = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    mat& operator*=(const\
    \ mat& r) {\n        int ha = dat.size(), wa = dat.front().size();\n        int\
    \ hb = r.dat.size(), wb = r.dat.front().size();\n        assert(wa == hb);\n\n\
    \        vector<vector<T>> res(ha, vector<T>(wb));\n        rep(i, ha) rep(j,\
    \ wb) rep(k, wa) {\n            res[i][j] += dat[i][k] * r.dat[k][j];\n      \
    \  }\n        swap(res, dat);\n        return (*this);\n    }\n\n    mat operator+(const\
    \ mat& r) { return mat(*this) += r; }\n    mat operator-(const mat& r) { return\
    \ mat(*this) -= r; }\n    mat operator*(const mat& r) { return mat(*this) *= r;\
    \ }\n\n    mat pow(__uint64_t e) const {\n        mat pr=I(this->h);\n       \
    \ mat pw(*this);\n\n        while(e){\n            if(e&1){\n                pw\
    \ *= pw;\n            }\n            pw *= pw;\n            e >>= 1;\n       \
    \ }\n        return pr;\n    }\n};\n#line 5 \"test/yosupo judge/matrix/Matrix\
    \ Product.test.cpp\"\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\nusing mint = dynamic_modint32;\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, m, k;\n\
    \    cin >> n >> m >> k;\n    mint::set_mod(MOD2);\n    using mat = Matrix<mint>;\n\
    \    mat a(n, m), b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i,\
    \ m) rep(j, k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n \
    \       rep(j, k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    template.hpp\"\n#include\"math/dynamic_modint.hpp\"\n#include\"math/matrix.hpp\"\
    \n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"\
    unroll-loops\")\nusing mint = dynamic_modint32;\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int n, m, k;\n    cin >> n >> m >> k;\n    mint::set_mod(MOD2);\n\
    \    using mat = Matrix<mint>;\n    mat a(n, m), b(m, k);\n    rep(i, n) rep(j,\
    \ m) { cin >> a[i][j]; }\n    rep(i, m) rep(j, k) { cin >> b[i][j]; }\n    auto\
    \ res = a * b;\n    rep(i, n) {\n        rep(j, k) { cout << res[i][j] << ' ';\
    \ }\n        cout << '\\n';\n    }\n}\n"
  dependsOn:
  - template.hpp
  - math/dynamic_modint.hpp
  - math/barrett.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/yosupo judge/matrix/Matrix Product.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 15:12:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo judge/matrix/Matrix Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo judge/matrix/Matrix Product.test.cpp
- /verify/test/yosupo judge/matrix/Matrix Product.test.cpp.html
title: test/yosupo judge/matrix/Matrix Product.test.cpp
---
