---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "static modint(\u9759\u7684modint)"
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"out.cpp\"\n#line 1 \"main.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/matrix_product\"\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#define rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x)\
    \ (x).begin(),(x).end()\n#define popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\n\
    using ll = long long;\nusing ld = long double;\nusing graph = vector<vector<int>>;\n\
    using P = pair<int, int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\n\
    constexpr ld eps = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t\
    \ MOD = 1e9 + 7;\nconstexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = {\
    \ 1,0,-1,0 };\nconstexpr int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void\
    \ chmax(T&x,T y){if(x<y)x=y;}\ntemplate<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 2 \"math/static_modint.hpp\"\ntemplate<__uint64_t mod>\nclass static_modint\
    \ {\nprivate:\n\tusing mint = static_modint<mod>;\n\tusing i64 = long long;\n\t\
    using u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\tusing i128 = __int128_t;\n\
    \n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\
    \t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\tstatic_modint() :v(0)\
    \ {}\n\tstatic_modint(const i64& v_) :v(normalize(v_)) { }\n\n\t//operator\n\t\
    u64 val() const {\n\t\treturn v;\n\t}\n\tmint& operator+=(const mint& rhs) {\n\
    \t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod - rhs.val();\n\t\tif\
    \ (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\t\treturn (*this);\n\t}\n\
    \n\n\tmint operator+(const mint& r) const {\n\t\treturn mint(*this) += r;\n\t\
    }\n\tmint operator-(const mint& r) const {\n\t\treturn mint(*this) -= r;\n\t}\n\
    \tmint operator*(const mint& r) const {\n\t\treturn mint(*this) *= r;\n\t}\n\n\
    \tmint& operator+=(const i64& rhs) {\n\t\t(*this) += mint(rhs);\n\t\treturn (*this);\n\
    \t}\n\tmint& operator-=(const i64& rhs) {\n\t\t(*this) -= mint(rhs);\n\t\treturn\
    \ (*this);\n\t}\n\tmint& operator*=(const i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\
    \t\treturn (*this);\n\t}\n\tfriend mint operator+(const i64& l, const mint& r)\
    \ {\n\t\treturn mint(l) += r;\n\t}\n\tfriend mint operator-(const i64& l, const\
    \ mint& r) {\n\t\treturn mint(l) -= r;\n\t}\n\tfriend mint operator*(const i64&\
    \ l, const mint& r) {\n\t\treturn mint(l) *= r;\n\t}\n\n\tmint operator+(const\
    \ i64& r) {\n\t\treturn mint(*this) += r;\n\t}\n\tmint operator-(const i64& r)\
    \ {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint operator*(const i64& r) {\n\t\t\
    return mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const i64& r) {\n\t\treturn\
    \ (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint& r) {\n\t\treturn (*this).val()\
    \ == r.val();\n\t}\n\tmint pow(u128 e) const {\n\t\tmint ans(1), base(*this);\n\
    \t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans *= base;\n\t\t\t}\n\t\t\tbase\
    \ *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\t}\n\n\tmint inv() const\
    \ {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) {\n\t\t\
    return (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const mint& l, const\
    \ i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\tfriend ostream&\
    \ operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\
    \t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\t\
    is >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\ntemplate<__uint32_t mod>\nclass\
    \ static_modint32 {\nprivate:\n\tusing mint = static_modint32<mod>;\n\tusing i32\
    \ = __int32_t;\n\tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\tusing u64\
    \ = unsigned long long;\n\n\tu32 v;\n\tu32 normalize(i64 v_) const {\n\t\tv_ %=\
    \ mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\npublic:\n\
    \tstatic_modint32() :v(0) {}\n\tstatic_modint32(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv = (u64)v * rhs.val() % mod;\n\
    \t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u64 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n#line 2 \"math/matrix.hpp\"\ntemplate<typename T>\n\
    class Matrix {\n    vector<vector<T>> dat;\n    int h, w;\npublic:\n    Matrix(const\
    \ vector<vector<T>>& dat)\n        : dat(dat), h(dat.size()), w(dat.front().size())\
    \ {}\n\n    Matrix(int h_, int w_, const T& v = T())\n        : dat(h_, vector<T>(w_,\
    \ v)){}\n    static Matrix<T> I(int sz) {\n        Matrix<T> ans(sz);\n      \
    \  rep(i, sz) { ans[i][i] = 1; }\n        return ans;\n    }\n    using mat =\
    \ Matrix<T>;\n    //access\n    vector<T>& operator[](int i) { return dat[i];\
    \ }\n\n    //operator\n    mat& operator+=(const mat& r) {\n        assert(r.h\
    \ == this->h);\n        assert(r.w == this->w);\n        for (int i = 0; i < h;\
    \ i++) {\n            for (int j = 0; j < w; j++) {\n                dat[i][j]\
    \ += r.dat[i][j];\n            }\n        }\n        return (*this);\n    }\n\
    \    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    mat& operator*=(const mat& r)\
    \ {\n        int ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(),\
    \ wb = r.dat.front().size();\n        assert(wa == hb);\n\n        vector<vector<T>>\
    \ res(ha, vector<T>(wb));\n        rep(i, ha) rep(j, wb) rep(k, wa) {\n      \
    \      res[i][j] += dat[i][k] * r.dat[k][j];\n        }\n        swap(res, dat);\n\
    \        return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    mat pow(__uint64_t\
    \ e) const {\n        mat pr=I(this->h);\n        mat pw(*this);\n\n        while(e){\n\
    \            if(e&1){\n                pw *= pw;\n            }\n            pw\
    \ *= pw;\n            e >>= 1;\n        }\n        return pr;\n    }\n};\n#line\
    \ 5 \"main.test.cpp\"\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\nusing mint = static_modint32<MOD2>;\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, m,\
    \ k;\n    cin >> n >> m >> k;\n    using mat = Matrix<mint>;\n    mat a(n, m),\
    \ b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i, m) rep(j,\
    \ k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n        rep(j,\
    \ k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n}\n"
  code: "#line 1 \"main.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 2 \"math/static_modint.hpp\"\
    \ntemplate<__uint64_t mod>\nclass static_modint {\nprivate:\n\tusing mint = static_modint<mod>;\n\
    \tusing i64 = long long;\n\tusing u64 = unsigned long long;\n\tusing u128 = __uint128_t;\n\
    \tusing i128 = __int128_t;\n\n\tu64 v;\n\tu64 normalize(i64 v_) const {\n\t\t\
    v_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t}\n\
    public:\n\tstatic_modint() :v(0) {}\n\tstatic_modint(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv = (u128)v * rhs.val() % mod;\n\
    \t\treturn (*this);\n\t}\n\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u128 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\ntemplate<__uint32_t\
    \ mod>\nclass static_modint32 {\nprivate:\n\tusing mint = static_modint32<mod>;\n\
    \tusing i32 = __int32_t;\n\tusing u32 = __uint32_t;\n\tusing i64 = __int64_t;\n\
    \tusing u64 = unsigned long long;\n\n\tu32 v;\n\tu32 normalize(i64 v_) const {\n\
    \t\tv_ %= mod;\n\t\tif (v_ < 0) {\n\t\t\tv_ += mod;\n\t\t}\n\t\treturn v_;\n\t\
    }\npublic:\n\tstatic_modint32() :v(0) {}\n\tstatic_modint32(const i64& v_) :v(normalize(v_))\
    \ { }\n\n\t//operator\n\tu64 val() const {\n\t\treturn (u64)v;\n\t}\n\tmint& operator+=(const\
    \ mint& rhs) {\n\t\tv += rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t\
    }\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint& rhs) {\n\t\tv += mod\
    \ - rhs.val();\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\
    \t}\n\tmint& operator*=(const mint& rhs) {\n\t\tv = (u64)v * rhs.val() % mod;\n\
    \t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const {\n\t\treturn\
    \ mint(*this) += r;\n\t}\n\tmint operator-(const mint& r) const {\n\t\treturn\
    \ mint(*this) -= r;\n\t}\n\tmint operator*(const mint& r) const {\n\t\treturn\
    \ mint(*this) *= r;\n\t}\n\n\tmint& operator+=(const i64& rhs) {\n\t\t(*this)\
    \ += mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const i64& rhs)\
    \ {\n\t\t(*this) -= mint(rhs);\n\t\treturn (*this);\n\t}\n\tmint& operator*=(const\
    \ i64& rhs) {\n\t\t(*this) *= mint(rhs);\n\t\treturn (*this);\n\t}\n\tfriend mint\
    \ operator+(const i64& l, const mint& r) {\n\t\treturn mint(l) += r;\n\t}\n\t\
    friend mint operator-(const i64& l, const mint& r) {\n\t\treturn mint(l) -= r;\n\
    \t}\n\tfriend mint operator*(const i64& l, const mint& r) {\n\t\treturn mint(l)\
    \ *= r;\n\t}\n\n\tmint operator+(const i64& r) {\n\t\treturn mint(*this) += r;\n\
    \t}\n\tmint operator-(const i64& r) {\n\t\treturn mint(*this) -= r;\n\t}\n\tmint\
    \ operator*(const i64& r) {\n\t\treturn mint(*this) *= r;\n\t}\n\n\n\tmint& operator=(const\
    \ i64& r) {\n\t\treturn (*this) = mint(r);\n\t}\n\n\tbool operator==(const mint&\
    \ r) {\n\t\treturn (*this).val() == r.val();\n\t}\n\tmint pow(u64 e) const {\n\
    \t\tmint ans(1), base(*this);\n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tans\
    \ *= base;\n\t\t\t}\n\t\t\tbase *= base;\n\t\t\te >>= 1;\n\t\t}\n\t\treturn ans;\n\
    \t}\n\n\tmint inv() const {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const\
    \ mint& r) {\n\t\treturn (*this) *= r.inv();\n\t}\n\tfriend mint operator/(const\
    \ mint& l, const i64& r) {\n\t\treturn mint(l) /= mint(r);\n\t}\n\n\t//iostream\n\
    \tfriend ostream& operator<<(ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend istream& operator>>(istream& is, mint& mt) {\n\t\
    \ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n#line 2 \"math/matrix.hpp\"\ntemplate<typename T>\n\
    class Matrix {\n    vector<vector<T>> dat;\n    int h, w;\npublic:\n    Matrix(const\
    \ vector<vector<T>>& dat)\n        : dat(dat), h(dat.size()), w(dat.front().size())\
    \ {}\n\n    Matrix(int h_, int w_, const T& v = T())\n        : dat(h_, vector<T>(w_,\
    \ v)){}\n    static Matrix<T> I(int sz) {\n        Matrix<T> ans(sz);\n      \
    \  rep(i, sz) { ans[i][i] = 1; }\n        return ans;\n    }\n    using mat =\
    \ Matrix<T>;\n    //access\n    vector<T>& operator[](int i) { return dat[i];\
    \ }\n\n    //operator\n    mat& operator+=(const mat& r) {\n        assert(r.h\
    \ == this->h);\n        assert(r.w == this->w);\n        for (int i = 0; i < h;\
    \ i++) {\n            for (int j = 0; j < w; j++) {\n                dat[i][j]\
    \ += r.dat[i][j];\n            }\n        }\n        return (*this);\n    }\n\
    \    mat& operator-=(const mat&r){\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] -= r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    mat& operator*=(const mat& r)\
    \ {\n        int ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(),\
    \ wb = r.dat.front().size();\n        assert(wa == hb);\n\n        vector<vector<T>>\
    \ res(ha, vector<T>(wb));\n        rep(i, ha) rep(j, wb) rep(k, wa) {\n      \
    \      res[i][j] += dat[i][k] * r.dat[k][j];\n        }\n        swap(res, dat);\n\
    \        return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    mat pow(__uint64_t\
    \ e) const {\n        mat pr=I(this->h);\n        mat pw(*this);\n\n        while(e){\n\
    \            if(e&1){\n                pw *= pw;\n            }\n            pw\
    \ *= pw;\n            e >>= 1;\n        }\n        return pr;\n    }\n};\n#line\
    \ 5 \"main.test.cpp\"\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\nusing mint = static_modint32<MOD2>;\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n    int n, m,\
    \ k;\n    cin >> n >> m >> k;\n    using mat = Matrix<mint>;\n    mat a(n, m),\
    \ b(m, k);\n    rep(i, n) rep(j, m) { cin >> a[i][j]; }\n    rep(i, m) rep(j,\
    \ k) { cin >> b[i][j]; }\n    auto res = a * b;\n    rep(i, n) {\n        rep(j,\
    \ k) { cout << res[i][j] << ' '; }\n        cout << '\\n';\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: out.cpp
  requiredBy: []
  timestamp: '2023-03-12 16:22:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: out.cpp
layout: document
redirect_from:
- /library/out.cpp
- /library/out.cpp.html
title: "static modint(\u9759\u7684modint)"
---
