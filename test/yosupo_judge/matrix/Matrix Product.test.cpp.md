---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/gcd.hpp
    title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
      \u3069)"
  - icon: ':x:'
    path: math/matrix.hpp
    title: "maxtirx(\u884C\u5217)"
  - icon: ':question:'
    path: math/static_modint.hpp
    title: "static modint(\u9759\u7684modint)"
  - icon: ':question:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/yosupo_judge/matrix/Matrix Product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"template.hpp\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n\
    #define all(x) (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\n\
    using i128=__int128_t;\nusing ll = long long;\nusing ld = long double;\nusing\
    \ graph = vector<vector<int>>;\nusing P = pair<int, int>;\nconstexpr int inf =\
    \ 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\nconst long double\
    \ pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 =\
    \ 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1\
    \ };\ntemplate<class T>static constexpr inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n#line\
    \ 1 \"math/gcd.hpp\"\ntemplate<typename T>\nstatic constexpr inline T _gcd(T a,T\
    \ b){\n    T s = a, t = b;\n    while (s % t != 0) {\n        T u = s % t;\n\n\
    \        s = t;\n        t = u;\n    }\n    return t;\n}\ntemplate<typename T>\n\
    static constexpr inline T ext_gcd(T a, T b, T &x, T &y) {\n    x = 1, y = 0;\n\
    \    T nx = 0, ny = 1;\n    while(b) {\n        T q = a / b;\n        tie(a, b)\
    \ = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx, x - nx*q);\n    \
    \    tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n/// @return\
    \ ax+by=gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\u308B,\u8FD4\u308A\u5024\
    \u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\u306A\u3069)\n#line 3 \"math/static_modint.hpp\"\ntemplate<__uint64_t\
    \ mod>\nclass static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\t\
    using i64 = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tconstexpr static_modint() :v(0) {}\n\tconstexpr static_modint(const\
    \ i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\tconstexpr u64 val() const\
    \ {\n\t\treturn v;\n\t}\n\tconstexpr mint& operator+=(const mint& rhs) {\n\t\t\
    v += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\
    \t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\t\
    return (*this);\n\t}\n\n\n\tconstexpr mint operator+(const mint& r) const {\n\t\
    \treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const mint& r) const\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const mint&\
    \ r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n\t\tll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n   \
    \     assert(d == 1);\n        return mint(y);\n\t}\n\n\tconstexpr mint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tconstexpr friend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tconstexpr friend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos\
    \ << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr friend istream& operator>>(istream&\
    \ is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t\
    }\n};\ntemplate<__uint32_t mod>\nclass static_modint32 {\nprivate:\n\tusing mint\
    \ = static_modint32<mod>;\n\tusing i32 = __int32_t;\n\tusing u32 = __uint32_t;\n\
    \tusing i64 = __int64_t;\n\tusing u64 = __uint64_t;\n\n\tu32 v;\n\tinline u32\
    \ normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\
    \t\t}\n\t\treturn v_;\n\t}\npublic:\n\tconstexpr static_modint32() :v(0) {}\n\t\
    constexpr static_modint32(const i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\
    \tconstexpr u64 val() const {\n\t\treturn (u64)v;\n\t}\n\tconstexpr mint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const mint& rhs) {\n\
    \t\tv += mod - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn\
    \ (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& rhs) {\n\t\tv = (u64)v\
    \ * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\n\tconstexpr mint operator+(const\
    \ mint& r) const {\n\t\treturn mint(*this) += r;\n\t}\n\tconstexpr mint operator-(const\
    \ mint& r) const {\n\t\treturn mint(*this) -= r;\n\t}\n\tconstexpr mint operator*(const\
    \ mint& r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\tconstexpr mint& operator+=(const\
    \ i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\t}\n\tconstexpr\
    \ mint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tconstexpr mint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tconstexpr friend mint operator+(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\tconstexpr friend mint operator-(const\
    \ i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tconstexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t\
    }\n\n\tconstexpr mint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tconstexpr mint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\
    \t}\n\tconstexpr mint operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\
    \t}\n\n\n\tconstexpr mint& operator=(const i64& r) {\n\t\treturn (*this) = mint(r);\n\
    \t}\n\n\tconstexpr bool operator==(const mint& r) const {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tconstexpr mint pow(u64 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tconstexpr mint inv()\
    \ const {\n        ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n\
    \        assert(d == 1);\n        return mint(y);\n    }\n\n\tconstexpr mint&\
    \ operator/=(const mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n    constexpr\
    \ mint operator/(const mint& r) { return mint(*this) *= r.inv(); }\n    constexpr\
    \ friend mint operator/(const mint& l, const i64& r) {\n\t\treturn mint(l) /=\
    \ mint(r);\n\t}\n\n\t//iostream\n\tconstexpr friend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tconstexpr\
    \ friend istream& operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >>\
    \ v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n\n};\n///@brief static modint(\u9759\
    \u7684modint)\n///@docs docs/math/static_modint.md\n#line 1 \"math/matrix.hpp\"\
    \ntemplate<typename T>\nclass Matrix {\n    vector<vector<T>> dat;\n    int h\
    \ = 0, w = 0;\n\n  public:\n    Matrix(const vector<vector<T>>& dat)\n       \
    \ : dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    Matrix(int h_, int\
    \ w_, const T& v = T())\n        : dat(h_, vector<T>(w_, v)){}\n        \n   \
    \ using mat = Matrix<T>;\n    //access\n    vector<T>& operator[](int i) { return\
    \ dat[i]; }\n\n    //operator\n    mat& operator+=(const mat& r) {\n        assert(r.h\
    \ == this->h);\n        assert(r.w == this->w);\n        for (int i = 0; i < h;\
    \ i++) {\n            for (int j = 0; j < w; j++) {\n                dat[i][j]\
    \ += r.dat[i][j];\n            }\n        }\n        return (*this);\n    }\n\
    \    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    \n    mat& operator*=(const mat&\
    \ r) {\n        int ha = dat.size(), wa = dat.front().size();\n        int hb\
    \ = r.dat.size(), wb = r.dat.front().size();\n        assert(wa == hb);\n\n  \
    \      vector<vector<T>> res(ha, vector<T>(wb));\n        for (int i = 0; i <\
    \ ha; i++) {\n            for (int k = 0; k < wa; k++){\n                for (int\
    \ j = 0; j < wb; j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n\
    \                }\n            }\n        }\n\n        swap(res, dat);\n    \
    \    return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    explicit mat pow(__uint64_t\
    \ e) const {\n        int n = dat.size();\n        mat res(n, n, 0);\n       \
    \ mat pr(*this);\n        for (int i = 0; i < n; i++) res[i][i] = 1;\n\n     \
    \   while (e) {\n            if (e & 1) res *= pr;\n            pr *= pr;\n  \
    \          \n            e >>= 1;\n        }\n        \n        return res;\n\
    \    }\n};\n/// @brief maxtirx(\u884C\u5217)\n/// @docs docs/math/matrix.md\n\
    #line 5 \"test/yosupo_judge/matrix/Matrix Product.test.cpp\"\n#pragma GCC target(\"\
    avx2\")\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\nusing mint = static_modint32<MOD2>;\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int n, m, k;\n    cin >> n >> m >> k;\n    using mat = Matrix<mint>;\n\
    \    mat a(n, m), b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i,\
    \ m) rep(j, k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n \
    \       rep(j, k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n\
    }\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\"\
    template.hpp\"\n#include\"math/static_modint.hpp\"\n#include\"math/matrix.hpp\"\
    \n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\nusing mint = static_modint32<MOD2>;\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(0);\n    int n, m, k;\n    cin >> n >> m >> k;\n    using mat = Matrix<mint>;\n\
    \    mat a(n, m), b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i,\
    \ m) rep(j, k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n \
    \       rep(j, k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n\
    }\n\n"
  dependsOn:
  - template.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/yosupo_judge/matrix/Matrix Product.test.cpp
  requiredBy: []
  timestamp: '2023-03-30 16:15:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/matrix/Matrix Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp.html
title: test/yosupo_judge/matrix/Matrix Product.test.cpp
---
