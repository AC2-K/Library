---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/lazy_segtree.hpp
    title: LazySegmentTree
  - icon: ':question:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':question:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':question:'
    path: src/stream.hpp
    title: fastIO
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    #include <iostream>\n#line 2 \"src/data-structure/lazy_segtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nnamespace kyopro {\n/**\n * @brief LazySegmentTree\n\
    \ */\ntemplate <class S,\n          class F,\n          auto op,\n          auto\
    \ e,\n          auto composition,\n          auto id,\n          auto mapping>\n\
    class lazy_segtree {\n    int lg, sz, n;\n    std::vector<S> dat;\n    std::vector<F>\
    \ lazy;\n\npublic:\n    lazy_segtree() {}\n    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    lazy_segtree(const std::vector<S>& a) : n((int)a.size()) {\n \
    \       sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n  \
    \          lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n \
    \       lazy = std::vector<F>(sz, id());\n        for (int i = 0; i < n; ++i)\
    \ {\n            set(i, a[i]);\n        }\n        build();\n    }\n\npublic:\n\
    \    void set(int i, const S& v) {\n        assert(0 <= i && i < sz);\n      \
    \  dat[i + sz] = v;\n    }\n    void build() {\n        for (int i = sz - 1; i\
    \ > 0; --i) {\n            push_up(i);\n        }\n    }\n\nprivate:\n    void\
    \ all_apply(int p, const F& f) {\n        dat[p] = mapping(dat[p], f);\n     \
    \   if (p < sz) lazy[p] = composition(lazy[p], f);\n    }\n    void push_up(int\
    \ k) { dat[k] = op(dat[k << 1 | 0], dat[k << 1 | 1]); }\n    void push_down(int\
    \ p) {\n        if (lazy[p] == id()) {\n            return;\n        }\n     \
    \   all_apply(p << 1 | 0, lazy[p]);\n        all_apply(p << 1 | 1, lazy[p]);\n\
    \        lazy[p] = id();\n    }\n\npublic:\n    S operator[](int p) {\n      \
    \  assert(0 <= p && p < n);\n        p += sz;\n        for (int i = lg; i > 0;\
    \ --i) push_down(p >> i);\n        return dat[p];\n    }\n    S fold(int l, int\
    \ r) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return\
    \ e();\n\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i) {\n\
    \            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n\n        S sml = e(), smr = e();\n \
    \       while (l < r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n   \
    \         if (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n\
    \        }\n\n        return op(sml, smr);\n    }\n    void apply(int l, int r,\
    \ const F& v) {\n        assert(0 <= l && l <= r && r <= n);\n        if (l ==\
    \ r) return;\n        l += sz, r += sz;\n        for (int i = lg; i > 0; --i)\
    \ {\n            if (((l >> i) << i) != l) {\n                push_down(l >> i);\n\
    \            }\n            if (((r >> i) << i) != r) {\n                push_down((r\
    \ - 1) >> i);\n            }\n        }\n        {\n            int l2 = l, r2\
    \ = r;\n            while (l < r) {\n                if (l & 1) all_apply(l++,\
    \ v);\n                if (r & 1) all_apply(--r, v);\n                l >>= 1;\n\
    \                r >>= 1;\n            }\n            l = l2;\n            r =\
    \ r2;\n        }\n\n        for (int i = 1; i <= lg; ++i) {\n            if (((l\
    \ >> i) << i) != l) push_up(l >> i);\n            if (((r >> i) << i) != r) push_up((r\
    \ - 1) >> i);\n        }\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs\
    \ docs/data-structure/lazy_segtree.md\n */\n#line 3 \"src/math/gcd.hpp\"\n#include\
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
    \ <__uint64_t _mod> class static_modint {\nprivate:\n    using mint = static_modint<_mod>;\n\
    \    using i64 = long long;\n    using u64 = unsigned long long;\n    using u128\
    \ = __uint128_t;\n    using i128 = __int128_t;\n\n    u64 v;\n    constexpr u64\
    \ normalize(i64 v_) const {\n        v_ %= _mod;\n        if (v_ < 0) {\n    \
    \        v_ += _mod;\n        }\n        return v_;\n    }\n\npublic:\n    static\
    \ constexpr u64 mod() { return _mod; }\n    constexpr static_modint() : v(0) {}\n\
    \    constexpr static_modint(i64 v_) : v(normalize(v_)) {}\n\n    static mint\
    \ raw(u64 a) {\n        mint m;\n        m.v = a;\n        return m;\n    }\n\
    \    constexpr u64 val() const { return v; }\n    constexpr mint& operator+=(const\
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
    \        }\n        return v_;\n    }\n\npublic:\n    static constexpr u32 mod()\
    \ { return _mod; }\n    constexpr static_modint32() : v(0) {}\n    constexpr static_modint32(i64\
    \ v_) : v(normalize(v_)) {}\n\n    static mint raw(u32 a) {\n        mint m;\n\
    \        m.v = a;\n        return m;\n    }\n    constexpr u32 val() const { return\
    \ v; }\n    constexpr mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n\
    \        if (v >= _mod) {\n            v -= _mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += _mod -\
    \ rhs.val();\n        if (v >= _mod) {\n            v -= _mod;\n        }\n  \
    \      return (*this);\n    }\n    constexpr mint& operator*=(const mint& rhs)\
    \ {\n        v = (u64)v * rhs.val() % _mod;\n        return (*this);\n    }\n\n\
    \    constexpr mint operator+(const mint& r) const { return mint(*this) += r;\
    \ }\n    constexpr mint operator-(const mint& r) const { return mint(*this) -=\
    \ r; }\n    constexpr mint operator*(const mint& r) const { return mint(*this)\
    \ *= r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
    \        return (*this);\n    }\n    constexpr mint& operator-=(i64 rhs) {\n \
    \       (*this) -= mint(rhs);\n        return (*this);\n    }\n    constexpr mint&\
    \ operator*=(i64 rhs) {\n        (*this) *= mint(rhs);\n        return (*this);\n\
    \    }\n    constexpr friend mint operator+(i64 l, const mint& r) {\n        return\
    \ mint(l) += r;\n    }\n    constexpr friend mint operator-(i64 l, const mint&\
    \ r) {\n        return mint(l) -= r;\n    }\n    constexpr friend mint operator*(i64\
    \ l, const mint& r) {\n        return mint(l) *= r;\n    }\n\n    constexpr mint\
    \ operator+(i64 r) { return mint(*this) += r; }\n    constexpr mint operator-(i64\
    \ r) { return mint(*this) -= r; }\n    constexpr mint operator*(i64 r) { return\
    \ mint(*this) *= r; }\n\n    constexpr mint& operator=(i64 r) { return (*this)\
    \ = mint(r); }\n\n    constexpr bool operator==(const mint& r) const {\n     \
    \   return (*this).val() == r.val();\n    }\n    template <typename T> constexpr\
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
    \ <string>\nnamespace kyopro {\n/**\n * \u6587\u5B57\u30921\u500B\u8AAD\u307F\u8FBC\
    \u3080\n */\ninline char readchar() {\n    char c = getchar_unlocked();\n    while\
    \ (isspace(c)) c = getchar_unlocked();\n    return c;\n}\n\n/**\n *  \u6574\u6570\
    \u306E\u5165\u51FA\u529B\n */\ntemplate <typename T> constexpr inline void readint(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = readchar();\n\
    \    if (c == '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c))\
    \ {\n        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n\
    \    if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\n\
    constexpr inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n\
    \    readint(tail...);\n}\n\ntemplate <typename T> constexpr inline void putint(T\
    \ a) {\n    if (!a) {\n        putchar_unlocked('0');\n        putchar_unlocked('\\\
    n');\n        return;\n    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n\
    \    char s[37];\n    int now = 37;\n    while (a) {\n        s[--now] = (char)'0'\
    \ + a % 10;\n        a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n\
    \    putchar_unlocked('\\n');\n}\ntemplate <typename Head, typename... Tail>\n\
    constexpr inline void putint(Head head, Tail... tail) {\n    putint(head);\n \
    \   putchar_unlocked('\\n');\n    putint(tail...);\n}\n\n/**\n * \u6587\u5B57\u5217\
    \u306E\u5165\u51FA\u529B\n */\ninline void readstr(std::string& str) {\n    char\
    \ c = readchar();\n    while (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n\
    \    }\n}\ninline void readstr(std::string& str, std::string& tail...) {\n   \
    \ readstr(str);\n    readstr(tail);\n}\ninline void putstr(const std::string&\
    \ str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n    }\n    putchar_unlocked('\\\
    n');\n}\ninline void putstr(const std::string& str, const std::string& tail...)\
    \ {\n    putstr(str);\n    putstr(tail);\n}\n\n};  // namespace kyopro\n\n/**\n\
    \ * @brief fastIO\n */\n#line 6 \"test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp\"\
    \nusing mint = kyopro::static_modint32<998244353>;\nstruct S {\n    mint s;\n\
    \    int len;\n};\ninline S op(S a, S b) { return S{a.s + b.s, a.len + b.len};\
    \ }\ninline S e() { return S{0, 0}; }\nusing Affine = std::pair<mint, mint>;\n\
    inline Affine composition(Affine g, Affine f) {\n    // f(g)\n    // a(cx+d)+b\n\
    \    auto a = f.first, b = f.second;\n    auto c = g.first, d = g.second;\n  \
    \  return Affine(a * c, a * d + b);\n}\ninline Affine id() { return Affine(1,\
    \ 0); }\ninline S mapping(S d, Affine f) {\n    mint a = f.first, b = f.second;\n\
    \    d.s *= a, d.s += b * d.len;\n    return d;\n};\n\nint main() {\n    int n,\
    \ q;\n    kyopro::readint(n, q);\n    kyopro::lazy_segtree<S, Affine, op, e, composition,\
    \ id, mapping> sg(n);\n    for (int i = 0; i < n; i++) {\n        mint a;\n  \
    \      kyopro::readint(a);\n        sg.set(i, {a, 1});\n    }\n    sg.build();\n\
    \    while (q--) {\n        int t;\n        kyopro::readint(t);\n        if (t\
    \ == 0) {\n            int l, r;\n            mint b, c;\n            kyopro::readint(l,\
    \ r, b, c);\n            sg.apply(l, r, Affine(b, c));\n        } else {\n   \
    \         int l, r;\n            kyopro::readint(l, r);\n            auto res\
    \ = sg.fold(l, r);\n            kyopro::putint(res.s.val());\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include <iostream>\n#include \"../../../src/data-structure/lazy_segtree.hpp\"\
    \n#include \"../../../src/math/static_modint.hpp\"\n#include \"../../../src/stream.hpp\"\
    \nusing mint = kyopro::static_modint32<998244353>;\nstruct S {\n    mint s;\n\
    \    int len;\n};\ninline S op(S a, S b) { return S{a.s + b.s, a.len + b.len};\
    \ }\ninline S e() { return S{0, 0}; }\nusing Affine = std::pair<mint, mint>;\n\
    inline Affine composition(Affine g, Affine f) {\n    // f(g)\n    // a(cx+d)+b\n\
    \    auto a = f.first, b = f.second;\n    auto c = g.first, d = g.second;\n  \
    \  return Affine(a * c, a * d + b);\n}\ninline Affine id() { return Affine(1,\
    \ 0); }\ninline S mapping(S d, Affine f) {\n    mint a = f.first, b = f.second;\n\
    \    d.s *= a, d.s += b * d.len;\n    return d;\n};\n\nint main() {\n    int n,\
    \ q;\n    kyopro::readint(n, q);\n    kyopro::lazy_segtree<S, Affine, op, e, composition,\
    \ id, mapping> sg(n);\n    for (int i = 0; i < n; i++) {\n        mint a;\n  \
    \      kyopro::readint(a);\n        sg.set(i, {a, 1});\n    }\n    sg.build();\n\
    \    while (q--) {\n        int t;\n        kyopro::readint(t);\n        if (t\
    \ == 0) {\n            int l, r;\n            mint b, c;\n            kyopro::readint(l,\
    \ r, b, c);\n            sg.apply(l, r, Affine(b, c));\n        } else {\n   \
    \         int l, r;\n            kyopro::readint(l, r);\n            auto res\
    \ = sg.fold(l, r);\n            kyopro::putint(res.s.val());\n        }\n    }\n\
    }"
  dependsOn:
  - src/data-structure/lazy_segtree.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-11 14:15:58+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Affine_Range_Sum.test.cpp
---
