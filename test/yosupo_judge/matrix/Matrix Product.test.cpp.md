---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':x:'
    path: src/math/matrix.hpp
    title: "\u884C\u5217"
  - icon: ':question:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u9AD8\u901F\u5165\u51FA\u529B"
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
    \ <vector>\nnamespace kyopro {\n\n/**\n * @brief \u884C\u5217\n */\ntemplate <typename\
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
    \n/**\n *  @docs docs/math/matrix.md\n */\n#line 3 \"src/math/static_modint.hpp\"\
    \n#include <cstdint>\n#line 5 \"src/math/static_modint.hpp\"\n\n#line 3 \"src/internal/type_traits.hpp\"\
    \n#include <limits>\n#include <numeric>\n#include <typeinfo>\nnamespace kyopro\
    \ {\nnamespace internal {\ntemplate <typename... Args> struct first_enabled {};\n\
    \ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __int8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __int16_t>,\n                                 std::enable_if<dgt <= 32, __int32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __int64_t>,\n    \
    \                             std::enable_if<dgt <= 128, __int128_t> >;\n};\n\
    template <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __uint8_t>,\n              \
    \                   std::enable_if<dgt <= 16, __uint16_t>,\n                 \
    \                std::enable_if<dgt <= 32, __uint32_t>,\n                    \
    \             std::enable_if<dgt <= 64, __uint64_t>,\n                       \
    \          std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\ntemplate <int dgt>\
    \ using int_least_t = typename int_least<dgt>::type;\ntemplate <int dgt> using\
    \ uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename T>\nusing\
    \ double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\ntemplate\
    \ <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 3 \"src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate\
    \ <typename T> constexpr inline T _gcd(T a, T b) noexcept {\n    assert(a >= 0\
    \ && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a),\
    \ __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n\
    \    while (a != b) {\n        if (!a || !b) {\n            return a + b;\n  \
    \      }\n        if (a >= b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr inline\
    \ T ext_gcd(T a, T b, T& x, T& y) noexcept {\n    x = 1, y = 0;\n    T nx = 0,\
    \ ny = 1;\n    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 8 \"src/math/static_modint.hpp\"\nnamespace\
    \ kyopro {\ntemplate <int _mod> class modint : internal::modint_base {\n    using\
    \ mint = modint<_mod>;\n    using i32 = std::int32_t;\n    using u32 = std::uint32_t;\n\
    \    using i64 = std::int64_t;\n    using u64 = std::uint64_t;\n\n    u32 v;\n\
    \    constexpr u32 normalize(i64 v_) const noexcept {\n        v_ %= _mod;\n \
    \       if (v_ < 0) {\n            v_ += _mod;\n        }\n        return v_;\n\
    \    }\n\npublic:\n    static constexpr u32 mod() noexcept { return _mod; }\n\
    \    constexpr modint() noexcept : v(0) {}\n    constexpr modint(i64 v_) noexcept\
    \ : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n        mint m;\n   \
    \     m.v = a;\n        return m;\n    }\n    constexpr u32 val() const noexcept\
    \ { return v; }\n    constexpr mint& operator+=(const mint& rhs) noexcept {\n\
    \        v += rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n \
    \       }\n        return (*this);\n    }\n    constexpr mint& operator-=(const\
    \ mint& rhs) noexcept {\n        v += _mod - rhs.val();\n        if (v >= _mod)\
    \ {\n            v -= _mod;\n        }\n        return (*this);\n    }\n    constexpr\
    \ mint& operator*=(const mint& rhs) noexcept {\n        v = (u64)v * rhs.val()\
    \ % _mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const noexcept {\n        return mint(*this) += r;\n    }\n    constexpr\
    \ mint operator-(const mint& r) const noexcept {\n        return mint(*this) -=\
    \ r;\n    }\n    constexpr mint operator*(const mint& r) const noexcept {\n  \
    \      return mint(*this) *= r;\n    }\n\n    constexpr mint& operator+=(i64 rhs)\
    \ noexcept {\n        (*this) += mint(rhs);\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(i64 rhs) noexcept {\n        (*this) -= mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator*=(i64 rhs) noexcept\
    \ {\n        (*this) *= mint(rhs);\n        return (*this);\n    }\n    constexpr\
    \ friend mint operator+(i64 l, const mint& r) noexcept {\n        return mint(l)\
    \ += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint& r) noexcept\
    \ {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) *= r;\n    }\n\n    constexpr\
    \ mint operator+(i64 r) const noexcept { return mint(*this) += r; }\n    constexpr\
    \ mint operator-(i64 r) const noexcept { return mint(*this) -= r; }\n    constexpr\
    \ mint operator*(i64 r) const noexcept { return mint(*this) *= r; }\n\n    constexpr\
    \ mint& operator=(i64 r) noexcept { return (*this) = mint(r); }\n\n    constexpr\
    \ bool operator==(const mint& r) const noexcept {\n        return (*this).val()\
    \ == r.val();\n    }\n    template <typename T> constexpr mint pow(T e) const\
    \ noexcept {\n        mint ans(1), base(*this);\n        while (e) {\n       \
    \     if (e & 1) {\n                ans *= base;\n            }\n            base\
    \ *= base;\n            e >>= 1;\n        }\n        return ans;\n    }\n\n  \
    \  constexpr mint inv() const noexcept {\n        long long x, y;\n        auto\
    \ d = ext_gcd((long long)_mod, (long long)v, x, y);\n        assert(d == 1);\n\
    \        return mint(y);\n    }\n\n    constexpr mint& operator/=(const mint&\
    \ r) noexcept {\n        return (*this) *= r.inv();\n    }\n    constexpr mint\
    \ operator/(const mint& r) const noexcept {\n        return mint(*this) *= r.inv();\n\
    \    }\n    constexpr friend mint operator/(const mint& l, i64 r) noexcept {\n\
    \        return mint(l) /= mint(r);\n    }\n    constexpr friend mint operator/(i64\
    \ l, const mint& r) noexcept {\n        return mint(l) /= mint(r);\n    }\n};\n\
    };  // namespace kyopro\n\n/**\n * @brief \u9759\u7684modint\n * @docs docs/math/static_modint.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n// read\nvoid single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief \u9AD8\u901F\u5165\u51FA\u529B\
    \n */\n#line 6 \"test/yosupo_judge/matrix/Matrix Product.test.cpp\"\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n\nusing mint = kyopro::modint<998244353>;\nint main()\
    \ {\n    int n, m, k;\n    kyopro::read(n, m, k);\n    kyopro::Matrix<mint> a(n,\
    \ m), b(m, k);\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j <\
    \ m; j++) {\n            kyopro::read(a[i][j]);\n        }\n    }\n    for (int\
    \ i = 0; i < m; i++) {\n        for (int j = 0; j < k; j++) {\n            kyopro::read(b[i][j]);\n\
    \        }\n    }\n    auto res = a * b;\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < k; j++) {\n            kyopro::put(res[i][j].val());\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <iostream>\n#include \"../../../src/math/matrix.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\nusing mint = kyopro::modint<998244353>;\nint main() {\n    int n, m, k;\n\
    \    kyopro::read(n, m, k);\n    kyopro::Matrix<mint> a(n, m), b(m, k);\n    for\
    \ (int i = 0; i < n; i++) {\n        for (int j = 0; j < m; j++) {\n         \
    \   kyopro::read(a[i][j]);\n        }\n    }\n    for (int i = 0; i < m; i++)\
    \ {\n        for (int j = 0; j < k; j++) {\n            kyopro::read(b[i][j]);\n\
    \        }\n    }\n    auto res = a * b;\n    for (int i = 0; i < n; i++) {\n\
    \        for (int j = 0; j < k; j++) {\n            kyopro::put(res[i][j].val());\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/math/matrix.hpp
  - src/math/static_modint.hpp
  - src/internal/type_traits.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/matrix/Matrix Product.test.cpp
  requiredBy: []
  timestamp: '2023-10-19 20:45:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/matrix/Matrix Product.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp
- /verify/test/yosupo_judge/matrix/Matrix Product.test.cpp.html
title: test/yosupo_judge/matrix/Matrix Product.test.cpp
---
