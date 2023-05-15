---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/BST/lazy_reversible_bst.hpp
    title: "\u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\u53CD\u8EE2\u53EF\u80FD \u5E73\
      \u8861\u4E8C\u5206\u63A2\u7D22\u6728"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/static_modint.hpp
    title: "\u9759\u7684modint"
  - icon: ':heavy_check_mark:'
    path: src/random/xor_shift.hpp
    title: xor shift
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#line 2 \"src/BST/lazy_reversible_bst.hpp\"\n#include <cassert>\n#include <memory>\n\
    #include <utility>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <chrono>\n\
    #include <cstdint>\n#include <random>\n\nnamespace kyopro {\nstruct xor_shift32\
    \ {\n    uint32_t rng;\n    constexpr explicit xor_shift32(uint32_t seed) : rng(seed)\
    \ {}\n    explicit xor_shift32()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint32_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 17;\n        rng ^= rng << 5;\n        return rng;\n    }\n\
    };\n\nstruct xor_shift {\n    uint64_t rng;\n    constexpr xor_shift(uint64_t\
    \ seed) : rng(seed) {}\n    explicit xor_shift()\n        : rng(std::chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n    constexpr uint64_t operator()() {\n        rng ^= rng << 13;\n     \
    \   rng ^= rng >> 7;\n        rng ^= rng << 17;\n        return rng;\n    }\n\
    };\n\n};  // namespace kyopro\n\n/**\n * @brief xor shift\n*/\n#line 6 \"src/BST/lazy_reversible_bst.hpp\"\
    \n\nnamespace kyopro {\n/**\n * @brief \u9045\u5EF6\u8A55\u4FA1\u3064\u304D\u30FB\
    \u53CD\u8EE2\u53EF\u80FD \u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728\n * @tparam\
    \ S \u30E2\u30CE\u30A4\u30C9\n * @tparam F \u4F5C\u7528\u7D20\n * @tparam op S\u306E\
    \u4E8C\u9805\u6F14\u7B97\n * @tparam e S\u306E\u5358\u4F4D\u5143\n * @tparam composition\
    \ F\u306E\u4E8C\u9805\u6F14\u7B97\n * @tparam id F\u306E\u5358\u4F4D\u5143\n *\
    \ @tparam mapping \u4F5C\u7528\n */\ntemplate <typename S,\n          class F,\n\
    \          S (*op)(S, S),\n          S (*e)(),\n          F (*composition)(F,\
    \ F),\n          F (*id)(),\n          S (*mapping)(S, F, int)>\nclass lazy_reversible_bst\
    \ {\n    using u32 = uint32_t;\n    xor_shift32 rng;\n    struct Node {\n    \
    \    std::unique_ptr<Node> l, r;\n        u32 priority;\n        S value, prod;\n\
    \n        F lazy;\n        int size;\n        bool rev;\n\n        Node(const\
    \ S& v, u32 prio)\n            : l(),\n              r(),\n              priority(prio),\n\
    \              value(v),\n              prod(e()),\n              lazy(id()),\n\
    \              size(1),\n              rev(false) {}\n    };\n\n    using ptr\
    \ = std::unique_ptr<Node>;\n    int size(const ptr& p) const { return p ? p->size\
    \ : 0; }\n    S fold(const ptr& p) { return p ? p->prod : e(); }\n\n    void update(const\
    \ ptr& p) {\n        if (!p) return;\n        p->size = size(p->l) + size(p->r)\
    \ + 1;\n        p->prod = op(p->value, op(fold(p->l), fold(p->r)));\n    }\n \
    \   void push(const ptr& p) {\n        if (!p) return;\n        if (p->rev) {\n\
    \            p->rev = false;\n            std::swap(p->l, p->r);\n           \
    \ reverse(p->l), reverse(p->r);\n        }\n\n        if (p->lazy != id()) {\n\
    \            if (p->l) {\n                p->l->lazy = composition(p->l->lazy,\
    \ p->lazy);\n                p->l->prod = mapping(p->l->prod, p->lazy, size(p->l));\n\
    \            }\n            if (p->r) {\n                p->r->lazy = composition(p->r->lazy,\
    \ p->lazy);\n                p->r->prod = mapping(p->r->prod, p->lazy, size(p->r));\n\
    \            }\n\n            p->value = mapping(p->value, p->lazy, 1);\n    \
    \        p->lazy = id();\n        }\n\n        update(p);\n    }\n\n    std::pair<ptr,\
    \ ptr> split(ptr p, int k) {\n        if (!p) return {nullptr, nullptr};\n\n \
    \       push(p);\n        int s = size(p->l);\n        if (s >= k) {\n       \
    \     auto [l, r] = split(std::move(p->l), k);\n            p->l = std::move(r);\n\
    \            update(p);\n\n            return {std::move(l), std::move(p)};\n\
    \        } else {\n            auto [l, r] = split(std::move(p->r), k - s - 1);\n\
    \n            p->r = std::move(l);\n            update(p);\n\n            return\
    \ {std::move(p), std::move(r)};\n        }\n    }\n\n    ptr merge(ptr l, ptr\
    \ r) {\n        if (!l) return r;\n        if (!r) return l;\n        push(l),\
    \ push(r);\n        if (l->priority < r->priority) {\n            r->l = merge(std::move(l),\
    \ std::move(r->l));\n            update(r);\n            return r;\n        }\
    \ else {\n            l->r = merge(std::move(l->r), std::move(r));\n         \
    \   update(l);\n            return l;\n        }\n    }\n\n    void reverse(const\
    \ ptr& p) {\n        if (p) {\n            p->rev ^= 1;\n        }\n    }\n  \
    \  ptr root = nullptr;\n\npublic:\n    constexpr explicit lazy_reversible_bst()\
    \ : rng(2023) {}\n    void insert(int i, S a) {\n        auto [l, r] = split(std::move(root),\
    \ i);\n        ptr item = std::make_unique<Node>(a, rng());\n        root = merge(std::move(l),\
    \ std::move(item));\n        root = merge(std::move(root), std::move(r));\n  \
    \  }\n\n    void erase(int i) {\n        auto [xy, z] = split(std::move(root),\
    \ i + 1);\n        auto [x, y] = split(std::move(xy), i);\n        root = merge(std::move(x),\
    \ std::move(z));\n    }\n\n    S fold(int l, int r) {\n        auto [xy, z] =\
    \ split(std::move(root), r);\n        auto [x, y] = split(std::move(xy), l);\n\
    \        auto res = fold(y);\n        xy = merge(std::move(x), std::move(y));\n\
    \        root = merge(std::move(xy), std::move(z));\n        return res;\n   \
    \ }\n\n    void apply(int l, int r, const F& f) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n\n        y->lazy = composition(y->lazy,\
    \ f);\n        y->prod = mapping(y->prod, f, size(y));\n\n        xy = merge(std::move(x),\
    \ std::move(y));\n        root = merge(std::move(xy), std::move(z));\n    }\n\n\
    \    void reverse(int l, int r) {\n        auto [xy, z] = split(std::move(root),\
    \ r);\n        auto [x, y] = split(std::move(xy), l);\n        reverse(y);\n \
    \       xy = merge(std::move(x), std::move(y));\n        root = merge(std::move(xy),\
    \ std::move(z));\n    }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/BST/lazy_reversible_bst.md\n\
    \ * @ref https://xuzijian629.hatenablog.com/entry/2018/12/08/000452\n */\n#line\
    \ 3 \"src/math/static_modint.hpp\"\n#include <iostream>\n#line 3 \"src/math/gcd.hpp\"\
    \n#include <tuple>\nnamespace kyopro {\ntemplate <typename T>\nconstexpr T inline\
    \ _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return\
    \ a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n \
    \   a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (!a||!b) {\n            return a + b;\n        }\n        if (a >=\
    \ b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n        }\
    \ else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n       \
    \ }\n    }\n\n    return a << d;\n}\ntemplate <typename T>\nconstexpr T ext_gcd(T\
    \ a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while (b)\
    \ {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T, T>{b, a % b};\n\
    \        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n        std::tie(y,\
    \ ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return a;\n}\n};  // namespace\
    \ kyopro\n#line 5 \"src/math/static_modint.hpp\"\nnamespace kyopro {\ntemplate\
    \ <__uint64_t mod> class static_modint {\nprivate:\n    using mint = static_modint<mod>;\n\
    \    using i64 = long long;\n    using u64 = unsigned long long;\n    using u128\
    \ = __uint128_t;\n    using i128 = __int128_t;\n\n    u64 v;\n    constexpr u64\
    \ normalize(i64 v_) const {\n        v_ %= mod;\n        if (v_ < 0) {\n     \
    \       v_ += mod;\n        }\n        return v_;\n    }\n\npublic:\n    constexpr\
    \ static_modint() : v(0) {}\n    constexpr static_modint(i64 v_) : v(normalize(v_))\
    \ {}\n\n    // operator\n    constexpr u64 val() const { return v; }\n    constexpr\
    \ mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n        if (v\
    \ >= mod) {\n            v -= mod;\n        }\n        return (*this);\n    }\n\
    \    constexpr mint& operator-=(const mint& rhs) {\n        v += mod - rhs.val();\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& rhs) {\n        v = (u128)v\
    \ * rhs.val() % mod;\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
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
    \ x, y;\n        auto d = ext_gcd((long long)mod, (long long)v, x, y);\n     \
    \   assert(d == 1);\n        return mint(y);\n    }\n\n    constexpr mint& operator/=(const\
    \ mint& r) { return (*this) *= r.inv(); }\n    constexpr mint inv(const mint&\
    \ r) const { return mint(*this) *= r.inv(); }\n    constexpr friend mint operator/(const\
    \ mint& l, i64 r) {\n        return mint(l) /= mint(r);\n    }\n    constexpr\
    \ friend mint operator/(i64 l, const mint& r) {\n        return mint(l) /= mint(r);\n\
    \    }\n\n    // stream\n    constexpr friend std::ostream& operator<<(std::ostream&\
    \ os,\n                                              const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    constexpr friend std::istream&\
    \ operator>>(std::istream& is, mint& mt) {\n        i64 v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n};\ntemplate <__uint32_t mod> class\
    \ static_modint32 {\nprivate:\n    using mint = static_modint32<mod>;\n    using\
    \ i32 = __int32_t;\n    using u32 = __uint32_t;\n    using i64 = __int64_t;\n\
    \    using u64 = __uint64_t;\n\n    u32 v;\n    constexpr u32 normalize(i64 v_)\
    \ const {\n        v_ %= mod;\n        if (v_ < 0) {\n            v_ += mod;\n\
    \        }\n        return v_;\n    }\n\npublic:\n    constexpr static_modint32()\
    \ : v(0) {}\n    constexpr static_modint32(i64 v_) : v(normalize(v_)) {}\n\n \
    \   // operator\n    static mint raw(u32 a) {\n        mint m;\n        m.v =\
    \ a;\n        return m;\n    }\n    constexpr u32 val() const { return v; }\n\
    \    constexpr mint& operator+=(const mint& rhs) {\n        v += rhs.val();\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& rhs) {\n        v += mod -\
    \ rhs.val();\n        if (v >= mod) {\n            v -= mod;\n        }\n    \
    \    return (*this);\n    }\n    constexpr mint& operator*=(const mint& rhs) {\n\
    \        v = (u64)v * rhs.val() % mod;\n        return (*this);\n    }\n\n   \
    \ constexpr mint operator+(const mint& r) const { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const { return mint(*this) -= r;\
    \ }\n    constexpr mint operator*(const mint& r) const { return mint(*this) *=\
    \ r; }\n\n    constexpr mint& operator+=(i64 rhs) {\n        (*this) += mint(rhs);\n\
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
    \ d = ext_gcd((long long)mod, (long long)v, x, y);\n        assert(d == 1);\n\
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
    \ */\n#line 2 \"src/stream.hpp\"\n#include <stdio.h>\n#include <ctype.h>\nnamespace\
    \ kyopro {\ntemplate <typename T>\nconstexpr inline void readint(T& a) {\n   \
    \ a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n  \
    \  while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void readint(Head& head, Tail&... tail) {\n    readint(head);\n    readint(tail...);\n\
    }\ntemplate <typename T>\nconstexpr inline void putint(T a) {\n    if (!a) {\n\
    \        putchar_unlocked('0');\n        putchar_unlocked('\\n');\n        return;\n\
    \    }\n    if (a < 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int\
    \ now = 37;\n    while (a) {\n        s[--now] = (char)'0' + a % 10;\n       \
    \ a /= 10;\n    }\n    while (now < 37) putchar_unlocked(s[now++]);\n    putchar_unlocked('\\\
    n');\n}\ntemplate <typename Head, typename... Tail>\nconstexpr inline void putint(Head\
    \ head, Tail... tail) {\n    putint(head);\n    putint(tail...);\n}\n\n};  //\
    \ namespace kyopro\n\n\n/**\n * @brief \u5165\u51FA\u529B\n*/\n#line 6 \"test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp\"\
    \nusing mint = kyopro::static_modint32<998244353>;\nusing S = mint;\ninline S\
    \ op(S a, S b) { return a + b; }\ninline S e() { return mint(0); }\nusing Affine\
    \ = std::pair<mint, mint>;\ninline Affine composition(Affine g, Affine f) {\n\
    \    // f(g)\n    // a(cx+d)+b\n    auto a = f.first, b = f.second;\n    auto\
    \ c = g.first, d = g.second;\n    return Affine(a * c, a * d + b);\n}\ninline\
    \ Affine id() { return Affine(1, 0); }\ninline S mapping(S d, Affine f, int length)\
    \ {\n    auto [a, b] = f;\n    return a * d + b * length;\n};\nint main() {\n\
    \    kyopro::lazy_reversible_bst<S, Affine, op, e, composition, id, mapping>\n\
    \        stree;\n    int n, q;\n    kyopro::readint(n, q);\n    for (int i = 0;\
    \ i < n; ++i) {\n        mint ai;\n        kyopro::readint(ai);\n        stree.insert(i,\
    \ ai);\n    }\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n\
    \        if (t == 0) {\n            int i, x;\n            kyopro::readint(i,\
    \ x);\n            stree.insert(i, mint::raw(x));\n        } else if (t == 1)\
    \ {\n            int i;\n            kyopro::readint(i);\n            stree.erase(i);\n\
    \        } else if (t == 2) {\n            int l, r;\n            kyopro::readint(l,\
    \ r);\n            stree.reverse(l, r);\n        } else if (t == 3) {\n      \
    \      int l, r, a, b;\n            kyopro::readint(l, r, a, b);\n           \
    \ stree.apply(l, r, Affine(mint::raw(a), mint::raw(b)));\n        } else {\n \
    \           int l, r;\n            kyopro::readint(l, r);\n            kyopro::putint(stree.fold(l,\
    \ r).val());\n        }\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"../../../src/BST/lazy_reversible_bst.hpp\"\n#include \"../../../src/math/static_modint.hpp\"\
    \n#include \"../../../src/stream.hpp\"\nusing mint = kyopro::static_modint32<998244353>;\n\
    using S = mint;\ninline S op(S a, S b) { return a + b; }\ninline S e() { return\
    \ mint(0); }\nusing Affine = std::pair<mint, mint>;\ninline Affine composition(Affine\
    \ g, Affine f) {\n    // f(g)\n    // a(cx+d)+b\n    auto a = f.first, b = f.second;\n\
    \    auto c = g.first, d = g.second;\n    return Affine(a * c, a * d + b);\n}\n\
    inline Affine id() { return Affine(1, 0); }\ninline S mapping(S d, Affine f, int\
    \ length) {\n    auto [a, b] = f;\n    return a * d + b * length;\n};\nint main()\
    \ {\n    kyopro::lazy_reversible_bst<S, Affine, op, e, composition, id, mapping>\n\
    \        stree;\n    int n, q;\n    kyopro::readint(n, q);\n    for (int i = 0;\
    \ i < n; ++i) {\n        mint ai;\n        kyopro::readint(ai);\n        stree.insert(i,\
    \ ai);\n    }\n    while (q--) {\n        int t;\n        kyopro::readint(t);\n\
    \        if (t == 0) {\n            int i, x;\n            kyopro::readint(i,\
    \ x);\n            stree.insert(i, mint::raw(x));\n        } else if (t == 1)\
    \ {\n            int i;\n            kyopro::readint(i);\n            stree.erase(i);\n\
    \        } else if (t == 2) {\n            int l, r;\n            kyopro::readint(l,\
    \ r);\n            stree.reverse(l, r);\n        } else if (t == 3) {\n      \
    \      int l, r, a, b;\n            kyopro::readint(l, r, a, b);\n           \
    \ stree.apply(l, r, Affine(mint::raw(a), mint::raw(b)));\n        } else {\n \
    \           int l, r;\n            kyopro::readint(l, r);\n            kyopro::putint(stree.fold(l,\
    \ r).val());\n        }\n    }\n}"
  dependsOn:
  - src/BST/lazy_reversible_bst.hpp
  - src/random/xor_shift.hpp
  - src/math/static_modint.hpp
  - src/math/gcd.hpp
  - src/stream.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
  requiredBy: []
  timestamp: '2023-05-15 06:44:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
- /verify/test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp.html
title: test/yosupo_judge/data_structure/Dynamic_Sequence_Range_Affine_Range_Sum.test.cpp
---