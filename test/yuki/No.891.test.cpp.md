---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  - icon: ':question:'
    path: math/matrix.hpp
    title: "matirx(\u884C\u5217)"
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
    PROBLEM: https://yukicoder.me/problems/no/891
    links:
    - https://yukicoder.me/problems/no/891
  bundledCode: "#line 1 \"test/yuki/No.891.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/891\"\
    \n\n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\n#define rep(i, N) for (int\
    \ i = 0; i < (N); i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 4 \"math/gcd.hpp\"\ntemplate <typename T> constexpr T _gcd(T a, T b) {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr T ext_gcd(T a, T b, T &x, T &y)\
    \ {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T q = a\
    \ / b;\n        std::tie(a, b) = std::pair<T,T>{b, a % b};\n        std::tie(x,\
    \ nx) = std::pair<T,T>{nx, x - nx * q};\n        std::tie(y, ny) = std::pair<T,T>{ny,\
    \ y - ny * q};\n    }\n    return a;\n}\n#line 6 \"math/static_modint.hpp\"\n\
    template <__uint64_t mod> class static_modint {\n  private:\n    using mint =\
    \ static_modint<mod>;\n    using i64 = long long;\n    using u64 = unsigned long\
    \ long;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\n    u64\
    \ v;\n    inline u64 normalize(i64 v_) const {\n        v_ %= mod;\n        if\
    \ (v_ < 0) {\n            v_ += mod;\n        }\n        return v_;\n    }\n\n\
    \  public:\n    constexpr static_modint() : v(0) {}\n    constexpr static_modint(const\
    \ i64& v_) : v(normalize(v_)) {}\n\n    // operator\n    constexpr u64 val() const\
    \ { return v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v\
    \ += rhs.val();\n        if (v >= mod) {\n            v -= mod;\n        }\n \
    \       return (*this);\n    }\n    constexpr mint& operator-=(const mint& rhs)\
    \ {\n        v += mod - rhs.val();\n        if (v >= mod) {\n            v -=\
    \ mod;\n        }\n        return (*this);\n    }\n    constexpr mint& operator*=(const\
    \ mint& rhs) {\n        v = (u128)v * rhs.val() % mod;\n        return (*this);\n\
    \    }\n\n    constexpr mint operator+(const mint& r) const { return mint(*this)\
    \ += r; }\n    constexpr mint operator-(const mint& r) const { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(const i64& rhs) {\n        (*this)\
    \ += mint(rhs);\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ i64& rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator*=(const i64& rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(const i64&\
    \ l, const mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend\
    \ mint operator-(const i64& l, const mint& r) {\n        return mint(l) -= r;\n\
    \    }\n    constexpr friend mint operator*(const i64& l, const mint& r) {\n \
    \       return mint(l) *= r;\n    }\n\n    constexpr mint operator+(const i64&\
    \ r) { return mint(*this) += r; }\n    constexpr mint operator-(const i64& r)\
    \ { return mint(*this) -= r; }\n    constexpr mint operator*(const i64& r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(const i64& r) { return\
    \ (*this) = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n\
    \        return (*this).val() == r.val();\n    }\n\n    template <typename T>\
    \ constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n       \
    \ while (e) {\n            if (e & 1) {\n                ans *= base;\n      \
    \      }\n            base *= base;\n            e >>= 1;\n        }\n       \
    \ return ans;\n    }\n    constexpr inline mint inv() const {\n        ll x, y;\n\
    \        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n        assert(d == 1);\n  \
    \      return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint& r)\
    \ { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint& r) const\
    \ { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, const i64& r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(const i64& l, const mint& r) {\n        return mint(l)\
    \ /= mint(r);\n    }\n\n    // iostream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t mod> class\
    \ static_modint32 {\n  private:\n    using mint = static_modint32<mod>;\n    using\
    \ i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    inline u32 normalize(i64 v_) const\
    \ {\n        v_ %= mod;\n        if (v_ < 0) {\n            v_ += mod;\n     \
    \   }\n        return v_;\n    }\n\n  public:\n    constexpr static_modint32()\
    \ : v(0) {}\n    constexpr static_modint32(const i64& v_) : v(normalize(v_)) {}\n\
    \n    // operator\n    constexpr u64 val() const { return (u64)v; }\n    constexpr\
    \ mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v\
    \ >= mod) {\n            v -= mod;\n        }\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u64)v\
    \ * rhs.val() % mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(const\
    \ i64& rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const i64& rhs) {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(const i64& rhs)\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(const i64& l, const mint& r) {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(const i64& l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(const\
    \ i64& l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(const i64& r) { return mint(*this) += r; }\n    constexpr mint\
    \ operator-(const i64& r) { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ i64& r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(const\
    \ i64& r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const\
    \ mint& r) const {\n        return (*this).val() == r.val();\n    }\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n\n    constexpr inline mint inv() const {\n      \
    \  ll x, y;\n        auto d = ext_gcd((ll)mod, (ll)v, x, y);\n        assert(d\
    \ == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const\
    \ mint& r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr\
    \ friend mint operator/(const mint& l, const i64& r) {\n        return mint(l)\
    \ /= mint(r);\n    }\n    constexpr friend mint operator/(const i64& l, const\
    \ mint& r) {\n        return mint(l) /= mint(r);\n    }\n\n    // iostream\n \
    \   constexpr friend std::ostream& operator<<(std::ostream& os, const mint& mt)\
    \ {\n        os << mt.val();\n        return os;\n    }\n    constexpr friend\
    \ std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n  \
    \      is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n///@brief static\
    \ modint(\u9759\u7684modint)\n///@docs docs/math/static_modint.md\n#line 1 \"\
    math/matrix.hpp\"\n\n/// @brief matirx(\u884C\u5217)\ntemplate<typename T>\nclass\
    \ Matrix {\n    std::vector<std::vector<T>> dat;\n    int h = 0, w = 0;\n\n  public:\n\
    \    Matrix(const std::vector<std::vector<T>>& dat)\n        : dat(dat), h(dat.size()),\
    \ w(dat.front().size()) {}\n\n    Matrix(int h_, int w_, const T& v = T())\n \
    \       : dat(h_, std::vector<T>(w_, v)){}\n        \n    using mat = Matrix<T>;\n\
    \    //access\n    std::vector<T>& operator[](int i) { return dat[i]; }\n\n  \
    \  //operator\n    mat& operator+=(const mat& r) {\n        assert(r.h == this->h);\n\
    \        assert(r.w == this->w);\n        for (int i = 0; i < h; i++) {\n    \
    \        for (int j = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n\
    \            }\n        }\n        return (*this);\n    }\n    mat& operator-=(const\
    \ mat&r){\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n\
    \        for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++)\
    \ {\n                dat[i][j] -= r.dat[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n    \n    mat& operator*=(const mat& r) {\n    \
    \    int ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(),\
    \ wb = r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++){\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    mat operator+(const mat& r) { return mat(*this)\
    \ += r; }\n    mat operator-(const mat& r) { return mat(*this) -= r; }\n    mat\
    \ operator*(const mat& r) { return mat(*this) *= r; }\n\n    template<typename\
    \ P>\n    mat pow(P e) const {\n        assert(e >= 0);\n        int n = dat.size();\n\
    \        mat res(n, n, 0);\n        mat pr(*this);\n        for (int i = 0; i\
    \ < n; i++) res[i][i] = 1;\n\n        while (e) {\n            if (e & 1) res\
    \ *= pr;\n            pr *= pr;\n            \n            e >>= 1;\n        }\n\
    \        \n        return res;\n    }\n};\n/// @docs docs/math/matrix.md\n#line\
    \ 6 \"test/yuki/No.891.test.cpp\"\nusing namespace std;\nusing mint = static_modint32<MOD>;\n\
    int main() {\n    int a, b, n;\n    cin >> a >> b >> n;\n    Matrix<mint> A({{a,\
    \ b}, {1, 0}});\n    A = A.pow(n);\n    cout << A[1][0] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/891\"\n\n#include\"template.hpp\"\
    \n#include\"math/static_modint.hpp\"\n#include\"math/matrix.hpp\"\nusing namespace\
    \ std;\nusing mint = static_modint32<MOD>;\nint main() {\n    int a, b, n;\n \
    \   cin >> a >> b >> n;\n    Matrix<mint> A({{a, b}, {1, 0}});\n    A = A.pow(n);\n\
    \    cout << A[1][0] << '\\n';\n}\n"
  dependsOn:
  - template.hpp
  - math/static_modint.hpp
  - math/gcd.hpp
  - math/matrix.hpp
  isVerificationFile: true
  path: test/yuki/No.891.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 14:59:40+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yuki/No.891.test.cpp
layout: document
redirect_from:
- /verify/test/yuki/No.891.test.cpp
- /verify/test/yuki/No.891.test.cpp.html
title: test/yuki/No.891.test.cpp
---
