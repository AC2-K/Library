---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':x:'
    path: src/math/matrix.hpp
    title: Matrix
  - icon: ':x:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
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
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <iostream>\n\
    #line 2 \"src/math/matrix.hpp\"\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief Matrix\n */\ntemplate <typename\
    \ T> class Matrix {\n    std::vector<std::vector<T>> dat;\n    int h = 0, w =\
    \ 0;\n\npublic:\n    constexpr Matrix(const std::vector<std::vector<T>>& dat)\n\
    \        : dat(dat), h(dat.size()), w(dat.front().size()) {}\n\n    constexpr\
    \ Matrix(int h_, int w_, T v = T())\n        : dat(h_, std::vector<T>(w_, v))\
    \ {}\n\n    using mat = Matrix<T>;\n    // access\n    constexpr std::vector<T>&\
    \ operator[](int i) { return dat[i]; }\n\n    // operator\n    constexpr mat&\
    \ operator+=(const mat& r) {\n        assert(r.h == this->h);\n        assert(r.w\
    \ == this->w);\n        for (int i = 0; i < h; i++) {\n            for (int j\
    \ = 0; j < w; j++) {\n                dat[i][j] += r.dat[i][j];\n            }\n\
    \        }\n        return (*this);\n    }\n    constexpr mat& operator-=(const\
    \ mat& r) {\n        assert(r.h == this->h);\n        assert(r.w == this->w);\n\
    \        for (int i = 0; i < h; i++) {\n            for (int j = 0; j < w; j++)\
    \ {\n                dat[i][j] -= r.dat[i][j];\n            }\n        }\n   \
    \     return (*this);\n    }\n\n    constexpr mat& operator*=(const mat& r) {\n\
    \        int ha = dat.size(), wa = dat.front().size();\n        int hb = r.dat.size(),\
    \ wb = r.dat.front().size();\n        assert(wa == hb);\n\n        std::vector<std::vector<T>>\
    \ res(ha, std::vector<T>(wb));\n        for (int i = 0; i < ha; i++) {\n     \
    \       for (int k = 0; k < wa; k++) {\n                for (int j = 0; j < wb;\
    \ j++) {\n                    res[i][j] += dat[i][k] * r.dat[k][j];\n        \
    \        }\n            }\n        }\n\n        std::swap(res, dat);\n       \
    \ return (*this);\n    }\n\n    constexpr mat operator+(const mat& r) { return\
    \ mat(*this) += r; }\n    constexpr mat operator-(const mat& r) { return mat(*this)\
    \ -= r; }\n    constexpr mat operator*(const mat& r) { return mat(*this) *= r;\
    \ }\n\n    template <typename P> constexpr mat pow(P e) const {\n        assert(e\
    \ >= 0);\n        int n = dat.size();\n        mat res(n, n, 0);\n        mat\
    \ pr(*this);\n        for (int i = 0; i < n; i++) res[i][i] = 1;\n\n        while\
    \ (e) {\n            if (e & 1) res *= pr;\n            pr *= pr;\n\n        \
    \    e >>= 1;\n        }\n\n        return res;\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n *  @docs docs/math/matrix.md\n */\n#line 3 \"src/math/gcd.hpp\"\n#include\
    \ <tuple>\nnamespace kyopro {\ntemplate <typename T> constexpr T inline _gcd(T\
    \ a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a\
    \ + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n   \
    \ a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (!a || !b) {\n            return a + b;\n        }\n        if (a\
    \ >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n      \
    \  } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n    \
    \    }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T ext_gcd(T\
    \ a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while (b)\
    \ {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T, T>{b, a % b};\n\
    \        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n        std::tie(y,\
    \ ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return a;\n}\n};  // namespace\
    \ kyopro\n#line 5 \"src/math/static_modint.hpp\"\nnamespace kyopro {\ntemplate\
    \ <__uint64_t _mod> class static_modint {\nprivate:\n    using mint = static_modint<mod>;\n\
    \    using i64 = long long;\n    using u64 = unsigned long long;\n    using u128\
    \ = __uint128_t;\n    using i128 = __int128_t;\n\n    u64 v;\n    constexpr u64\
    \ normalize(i64 v_) const {\n        v_ %= _mod;\n        if (v_ < 0) {\n    \
    \        v_ += _mod;\n        }\n        return v_;\n    }\n\npublic:\n    static\
    \ constexpr __uint64_t mod() { return _mod; }\n    constexpr static_modint() :\
    \ v(0) {}\n    constexpr static_modint(i64 v_) : v(normalize(v_)) {}\n\n    static\
    \ mint raw(u32 a) {\n        mint m;\n        m.v = a;\n        return m;\n  \
    \  }\n    constexpr u64 val() const { return v; }\n    constexpr mint& operator+=(const\
    \ mint& rhs) {\n        v += rhs.val();\n        if (v >= _mod) {\n          \
    \  v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr mint&\
    \ operator-=(const mint& rhs) {\n        v += _mod - rhs.val();\n        if (v\
    \ >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n   \
    \ }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u128)v *\
    \ rhs.val() % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(i64 rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(i64 l, const\
    \ mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend mint operator-(i64\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const i64& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n\n    constexpr mint operator+(i64 r) { return mint(*this) += r; }\n \
    \   constexpr mint operator-(i64 r) { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(i64\
    \ r) { return (*this) = mint(r); }\n\n    constexpr bool operator==(const mint&\
    \ r) const {\n        return (*this).val() == r.val();\n    }\n\n    template\
    \ <typename T> constexpr mint pow(T e) const {\n        mint ans(1), base(*this);\n\
    \        while (e) {\n            if (e & 1) {\n                ans *= base;\n\
    \            }\n            base *= base;\n            e >>= 1;\n        }\n \
    \       return ans;\n    }\n    constexpr mint inv() const {\n        long long\
    \ x, y;\n        auto d = ext_gcd((long long)_mod, (long long)v, x, y);\n    \
    \    assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint&\
    \ r) const { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, i64 r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(i64 l, const mint& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n\n    // stream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t _mod> class\
    \ static_modint32 {\nprivate:\n    using mint = static_modint32<_mod>;\n    using\
    \ i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    constexpr u32 normalize(i64 v_)\
    \ const {\n        v_ %= _mod;\n        if (v_ < 0) {\n            v_ += _mod;\n\
    \        }\n        return v_;\n    }\n\npublic:\n    static constexpr __uint32_t\
    \ mod() { return _mod; }\n    constexpr static_modint32() : v(0) {}\n    constexpr\
    \ static_modint32(i64 v_) : v(normalize(v_)) {}\n\n    static mint raw(u32 a)\
    \ {\n        mint m;\n        m.v = a;\n        return m;\n    }\n    constexpr\
    \ u32 val() const { return v; }\n    constexpr mint& operator+=(const mint& rhs)\
    \ {\n        v += rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n\
    \        }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) {\n        v += _mod - rhs.val();\n        if (v >= _mod) {\n   \
    \         v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator*=(const mint& rhs) {\n        v = (u64)v * rhs.val() % _mod;\n\
    \        return (*this);\n    }\n\n    constexpr mint operator+(const mint& r)\
    \ const { return mint(*this) += r; }\n    constexpr mint operator-(const mint&\
    \ r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const mint&\
    \ r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ rhs) {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ mint& operator-=(i64 rhs) {\n        (*this) -= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr friend mint operator+(i64 l, const\
    \ mint& r) {\n        return mint(l) += r;\n    }\n    constexpr friend mint operator-(i64\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(i64 l, const mint& r) {\n        return mint(l) *= r;\n    }\n\
    \n    constexpr mint operator+(i64 r) { return mint(*this) += r; }\n    constexpr\
    \ mint operator-(i64 r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64\
    \ r) { return mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return\
    \ (*this) = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n\
    \        return (*this).val() == r.val();\n    }\n    template <typename T> constexpr\
    \ mint pow(T e) const {\n        mint ans(1), base(*this);\n        while (e)\
    \ {\n            if (e & 1) {\n                ans *= base;\n            }\n \
    \           base *= base;\n            e >>= 1;\n        }\n        return ans;\n\
    \    }\n\n    constexpr mint inv() const {\n        long long x, y;\n        auto\
    \ d = ext_gcd((long long)_mod, (long long)v, x, y);\n        assert(d == 1);\n\
    \        return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint&\
    \ r) { return (*this) *= r.inv(); }\n    constexpr mint operator/(const mint&\
    \ r) const {\n        return mint(*this) *= r.inv();\n    }\n    constexpr friend\
    \ mint operator/(const mint& l, i64 r) {\n        return mint(l) /= mint(r);\n\
    \    }\n    constexpr friend mint operator/(i64 l, const mint& r) {\n        return\
    \ mint(l) /= mint(r);\n    }\n\n    // stream\n    constexpr friend std::ostream&\
    \ operator<<(std::ostream& os,\n                                             \
    \ const mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    constexpr\
    \ friend std::istream& operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n\
    \        is >> v_;\n        mt = v_;\n        return is;\n    }\n};\n};  // namespace\
    \ kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\nnamespace kyopro {\n\n/**\n *  \u6574\u6570\u306E\u5165\u51FA\u529B\
    \n */\ntemplate <typename T> constexpr inline void readint(T& a) {\n    a = 0;\n\
    \    bool is_negative = false;\n    char c = getchar_unlocked();\n    while (isspace(c))\
    \ {\n        c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true,\
    \ c = getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c -\
    \ '0');\n        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n\
    }\ntemplate <typename Head, typename... Tail>\nconstexpr inline void readint(Head&\
    \ head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n}\n\ntemplate\
    \ <typename T> void write_int(T a) {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        putchar_unlocked('\\n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now]\
    \ = (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T> constexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n/**\n *\
    \ \u6587\u5B57\u5217\u306E\u5165\u51FA\u529B\n */\n\nvoid readstr(std::string&\
    \ str) {\n    char c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    \    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\nvoid putstr(const std::string& str) {\n    for (auto c : str) {\n \
    \       putchar_unlocked(c);\n    }\n    putchar_unlocked('\\n');\n}\n\n};  //\
    \ namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 6 \"test/yosupo_judge/matrix/Matrix\
    \ Product.test.cpp\"\n#pragma GCC optimize(\"unroll-loops\")\n\nusing mint = kyopro::static_modint32<998244353>;\n\
    int main() {\n    int n, m, k;\n    kyopro::readint(n, m, k);\n    kyopro::Matrix<mint>\
    \ a(n, m), b(m, k);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0;\
    \ j < m; j++) {\n            kyopro::readint(a[i][j]);\n        }\n    }\n   \
    \ for (int i = 0; i < m; i++) {\n        for (int j = 0; j < k; j++) {\n     \
    \       kyopro::readint(b[i][j]);\n        }\n    }\n    auto res = a * b;\n \
    \   for (int i = 0; i < n; i++) {\n        for (int j = 0; j < k; j++) {\n   \
    \         kyopro::putint(res[i][j].val());\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <iostream>\n#include \"../../../src/math/matrix.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\nusing mint = kyopro::static_modint32<998244353>;\nint main() {\n    int n,\
    \ m, k;\n    kyopro::readint(n, m, k);\n    kyopro::Matrix<mint> a(n, m), b(m,\
    \ k);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++)\
    \ {\n            kyopro::readint(a[i][j]);\n        }\n    }\n    for (int i =\
    \ 0; i < m; i++) {\n        for (int j = 0; j < k; j++) {\n            kyopro::readint(b[i][j]);\n\
    \        }\n    }\n    auto res = a * b;\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < k; j++) {\n            kyopro::putint(res[i][j].val());\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/math/matrix.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/matrix/Matrix Product.test.cpp
  requiredBy: []
  timestamp: '2023-06-25 12:32:45+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/matrix/Matrix Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp.html
title: test/yosupo_judge/matrix/Matrix Product.test.cpp
---
