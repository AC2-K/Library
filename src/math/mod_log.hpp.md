---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/hash_map.hpp
    title: HashMap
  - icon: ':heavy_check_mark:'
    path: src/internal/barrett.hpp
    title: barrett reduction
  - icon: ':heavy_check_mark:'
    path: src/internal/montgomery.hpp
    title: MontgomeryReduction
  - icon: ':heavy_check_mark:'
    path: src/math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':heavy_check_mark:'
    path: src/math/gcd.hpp
    title: src/math/gcd.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/DLP.md
    document_title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
    links: []
  bundledCode: "#line 2 \"src/math/mod_log.hpp\"\n#include <cmath>\n#line 2 \"src/data-structure/hash_map.hpp\"\
    \n#include <chrono>\nnamespace kyopro {\n/// @brief HashMap\ntemplate <typename\
    \ Key,\n          typename Val,\n          uint32_t n = 1 << 20,\n          Val\
    \ default_val = Val()>\nclass hash_map {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n\n    u64* flag = new u64[n];\n    Key* keys = new Key[n];\n\
    \    Val* vals = new Val[n];\n\n    static constexpr u32 shift = 64 - std::__lg(n);\n\
    \n    u64 r;\n    inline u32 get_hash(const Key& k) const { return ((u64)k * r)\
    \ >> shift; }\n\n    static constexpr uint8_t mod_msk = (1 << 6) - 1;\n\n  public:\n\
    \    explicit constexpr hash_map() {\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash\
    \ & mod_msk)))) {\n                keys[hash] = k;\n                flag[hash\
    \ >> 6] |= static_cast<u64>(1) << (hash & mod_msk);\n                return vals[hash]\
    \ = default_val;\n            }\n\n            if (keys[hash] == k) return vals[hash];\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n\n    const Val*\
    \ find(const Key& k) const {\n        u32 hash = get_hash(k);\n        while (1)\
    \ {\n            if (!(flag[hash >> 6] & (static_cast<u64>(1) << (hash & mod_msk))))\n\
    \                return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n};  // namespace\
    \ kyopro\n#line 2 \"src/math/dynamic_modint.hpp\"\n#include <cassert>\n#include\
    \ <iostream>\n#line 2 \"src/internal/barrett.hpp\"\nnamespace kyopro {\nnamespace\
    \ internal {\n///@brief barrett reduction\nclass barrett {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\n  public:\n    explicit\
    \ barrett() = default;\n    explicit barrett(u64 m_)\n        : m(m_), im((u64)(long\
    \ double)static_cast<u64>(-1) / m_ + 1) {}\n\n    inline u64 get_mod() const {\
    \ return m; }\n    constexpr u64 reduce(int64_t a) const {\n        if (a < 0)\
    \ return m - reduce(-a);\n        u64 q = ((__uint128_t)a * im) >> 64;\n     \
    \   a -= m * q;\n        if (a >= m) a -= m;\n        return a;\n    }\n    constexpr\
    \ u64 mul(u64 a, u64 b) const {\n        if (a == 0 || b == 0) {\n           \
    \ return 0;\n        }\n        u64 z = a;\n        z *= b;\n        u64 x = (u64)(((__uint128_t)z\
    \ * im) >> 64);\n\n        u32 v = (u32)(z - x * m);\n\n        if (v >= m) v\
    \ += m;\n        return v;\n    }\n};\n};  // namespace internal\n};  // namespace\
    \ kyopro\n#line 3 \"src/internal/montgomery.hpp\"\n#include <limits>\n#include\
    \ <numeric>\nnamespace kyopro {\nnamespace internal {\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i32 = int32_t;\nusing i64 = int64_t;\nusing u128\
    \ = __uint128_t;\nusing i128 = __int128_t;\n/// @brief MontgomeryReduction\ntemplate\
    \ <typename T, typename LargeT> class Montgomery {\n    static constexpr int lg\
    \ = std::numeric_limits<T>::digits;\n    T mod, r, r2, minv;\n    T calc_inv()\
    \ {\n        T t = 0, res = 0;\n        for (int i = 0; i < lg; i++) {\n     \
    \       if (~t & 1) {\n                t += mod;\n                res += static_cast<T>(1)\
    \ << i;\n            }\n            t >>= 1;\n        }\n        return res;\n\
    \    }\n\n  public:\n    Montgomery() = default;\n    constexpr inline T get_mod()\
    \ { return mod; }\n    constexpr inline int get_lg() { return lg; }\n\n    void\
    \ set_mod(const T& m) {\n        assert(m > 0);\n        assert(m & 1);\n\n  \
    \      mod = m;\n\n        r = (-static_cast<T>(mod)) % mod;\n        r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n        minv = calc_inv();\n    }\n\n    T reduce(LargeT x) const {\n\
    \        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x) * minv)\
    \ * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return res;\n\
    \    }\n\n    inline T generate(LargeT x) { return reduce(x * r2); }\n\n    inline\
    \ T mult(T x, T y) { return reduce((LargeT)x * y); }\n};\n};  // namespace internal\n\
    };  // namespace kyopro\n#line 6 \"src/math/dynamic_modint.hpp\"\nnamespace kyopro\
    \ {\ntemplate <int id = -1> class barrett_modint {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using br = internal::barrett;\n\n    static br brt;\n    static u32 mod;\n\
    \    u32 v;  // value\n  public:\n    static inline void set_mod(u32 mod_) {\n\
    \        brt = br(mod_);\n        mod = mod_;\n    }\n\n  public:\n    explicit\
    \ constexpr barrett_modint() : v(0) {\n        assert(mod);\n    }  // mod\u304C\
    \u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n   \
    \ explicit constexpr barrett_modint(i64 v_) : v(brt.reduce(v_)) {\n        assert(mod);\n\
    \    }\n\n    u32 val() const { return v; }\n    static u32 get_mod() { return\
    \ mod; }\n    using mint = barrett_modint<id>;\n\n    // operators\n    constexpr\
    \ mint& operator=(i64 r) {\n        v = brt.reduce(r);\n        return (*this);\n\
    \    }\n    constexpr mint& operator+=(const mint& r) {\n        v += r.v;\n \
    \       if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& r) {\n        v += mod - r.v;\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        v = brt.mul(v,\
    \ r.v);\n        return (*this);\n    }\n\n    constexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n    constexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ r) { return (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) { return (*this)\
    \ *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) { return mint(l)\
    \ += r; }\n    friend mint operator+(const mint& l, i64 r) { return mint(l) +=\
    \ r; }\n    friend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n    friend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\
    \    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n  \
    \  friend mint operator*(const mint& l, i64 r) { return mint(l) += r; }\n\n  \
    \  friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n     \
    \   os << mt.val();\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n    template <typename T> mint pow(T e) const {\n    \
    \    mint res(1), base(*this);\n\n        while (e) {\n            if (e & 1)\
    \ {\n                res *= base;\n            }\n            e >>= 1;\n     \
    \       base *= base;\n        }\n        return res;\n    }\n    inline mint\
    \ inv() const { return pow(mod - 2); }\n\n    mint& operator/=(const mint& r)\
    \ { return (*this) *= r.inv(); }\n    mint operator/(const mint& r) const { return\
    \ mint(*this) *= r.inv(); }\n    mint& operator/=(i64 r) { return (*this) /= mint(r);\
    \ }\n    friend mint operator/(const mint& l, i64 r) { return mint(l) /= r; }\n\
    \    friend mint operator/(i64 l, const mint& r) { return mint(l) /= r; }\n};\n\
    };  // namespace kyopro\ntemplate <int id>\ntypename kyopro::barrett_modint<id>::u32\
    \ kyopro::barrett_modint<id>::mod;\ntemplate <int id>\ntypename kyopro::barrett_modint<id>::br\
    \ kyopro::barrett_modint<id>::brt;\n\nnamespace kyopro {\ntemplate <typename T\
    \ = uint32_t, typename LargeT = uint64_t, int id = -1>\nclass dynamic_modint {\n\
    \    static T mod;\n    static internal::Montgomery<T, LargeT> mr;\n\n  public:\n\
    \    static void inline set_mod(T mod_) {\n        mr.set_mod(mod_);\n       \
    \ mod = mod_;\n    }\n\n    static inline T get_mod() { return mod; }\n\n  private:\n\
    \    T v;\n\n  public:\n    dynamic_modint(T v_ = 0) {\n        assert(mod);\n\
    \        v = mr.generate(v_);\n    }\n    inline T val() const { return mr.reduce(v);\
    \ }\n\n    using mint = dynamic_modint<T, LargeT, id>;\n    mint& operator+=(const\
    \ mint& r) {\n        v += r.v;\n        if (v >= mr.get_mod()) {\n          \
    \  v -= mr.get_mod();\n        }\n\n        return (*this);\n    }\n\n    mint&\
    \ operator-=(const mint& r) {\n        v += mr.get_mod() - r.v;\n        if (v\
    \ >= mr.get_mod) {\n            v -= mr.get_mod();\n        }\n\n        return\
    \ (*this);\n    }\n\n    mint& operator*=(const mint& r) {\n        v = mr.mult(v,\
    \ r.v);\n        return (*this);\n    }\n\n    mint operator+(const mint& r) {\
    \ return mint(*this) += r; }\n    mint operator-(const mint& r) { return mint(*this)\
    \ -= r; }\n    mint operator*(const mint& r) { return mint(*this) *= r; }\n\n\
    \    mint& operator=(const T& v_) {\n        (*this) = mint(v_);\n        return\
    \ (*this);\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    friend\
    \ std::istream& operator>>(std::istream& is, mint& mt) {\n        T v_;\n    \
    \    is >> v_;\n        mt = v_;\n        return is;\n    }\n    template <typename\
    \ P> mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1), base(*this);\n\
    \n        while (e) {\n            if (e & 1) {\n                res *= base;\n\
    \            }\n            e >>= 1;\n            base *= base;\n        }\n \
    \       return res;\n    }\n    mint inv() const { return pow(mod - 2); }\n\n\
    \    mint& operator/=(const mint& r) { return (*this) *= r.inv(); }\n    mint\
    \ operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n    mint&\
    \ operator/=(T r) { return (*this) /= mint(r); }\n    friend mint operator/(const\
    \ mint& l, T r) { return mint(l) /= r; }\n    friend mint operator/(T l, const\
    \ mint& r) { return mint(l) /= r; }\n};\n};  // namespace kyopro\ntemplate <typename\
    \ T, typename LargeT, int id>\nT kyopro::dynamic_modint<T, LargeT, id>::mod;\n\
    template <typename T, typename LargeT, int id>\nkyopro::internal::Montgomery<T,\
    \ LargeT>\n    kyopro::dynamic_modint<T, LargeT, id>::mr;\n\n/// @brief dynamic\
    \ modint(\u52D5\u7684modint)\n/// @docs docs/math/dynamic_modint.md\n#line 3 \"\
    src/math/gcd.hpp\"\n#include <tuple>\nnamespace kyopro {\ntemplate <typename T>\
    \ constexpr T _gcd(T a, T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0\
    \ || b == 0) return a + b;\n    int d = std::min<T>(__builtin_ctzll(a), __builtin_ctzll(b));\n\
    \    a >>= __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n\
    \        if (a == 0 || b == 0) {\n            return a + b;\n        }\n     \
    \   if (a > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n\
    \        } else {\n            b -= a;\n            b >>= __builtin_ctzll(b);\n\
    \        }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T\
    \ ext_gcd(T a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n\
    \    while (b) {\n        T q = a / b;\n        std::tie(a, b) = std::pair<T,\
    \ T>{b, a % b};\n        std::tie(x, nx) = std::pair<T, T>{nx, x - nx * q};\n\
    \        std::tie(y, ny) = std::pair<T, T>{ny, y - ny * q};\n    }\n    return\
    \ a;\n}\n};  // namespace kyopro\n#line 2 \"src/math/mod_pow.hpp\"\nnamespace\
    \ kyopro {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)\n\
    template <class T, class U = T> constexpr T mod_pow(T base, T exp, T mod) {\n\
    \    U ans = 1;\n    base %= mod;\n    while (exp) {\n        if (exp & 1) {\n\
    \            ans *= base;\n            ans %= mod;\n        }\n        base *=\
    \ base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return ans;\n}\n\
    };  // namespace kyopro\n#line 7 \"src/math/mod_log.hpp\"\nnamespace kyopro {\n\
    namespace internal {\nlong long __mod_log(uint64_t x, uint64_t y, uint64_t p)\
    \ {\n    if (y == 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n\
    \        if (y == 0) {\n            return 1;\n        } else {\n            return\
    \ -1;\n        }\n    }\n    uint32_t m = (uint32_t)sqrt(p) + 1;\n    hash_map<uint64_t,\
    \ int> mp;\n    uint64_t xm = mod_pow<uint64_t>(x, m, p);\n    uint64_t add =\
    \ 0, g, k = (p == 1 ? 0 : 1);\n    while ((g = _gcd(x, p)) > 1) {\n        if\
    \ (y == k) return add;\n        if (y % g) return -1;\n        y /= g, p /= g,\
    \ add++;\n        k = (k * (x / g)) % p;\n    }\n\n    long long pr = y;\n   \
    \ for (int j = 0; j <= m; j++) {\n        mp[pr] = j;\n        (pr *= x) %= p;\n\
    \    }\n    pr = k;\n    for (int i = 1; i <= m; i++) {\n        (pr *= xm) %=\
    \ p;\n        auto ptr = mp.find(pr);\n        if (ptr) {\n            int j =\
    \ *ptr;\n            return m * i - j + add;\n        }\n    }\n    return -1;\n\
    }\n\nlong long __mod_log32(uint32_t x, uint32_t y, uint32_t p) {\n    if (y ==\
    \ 1 || p == 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y ==\
    \ 0) {\n            return 1;\n        } else {\n            return -1;\n    \
    \    }\n    }\n    uint32_t m = (uint32_t)std::ceil(std::sqrt(p));\n    using\
    \ mint = barrett_modint<10>;\n    if (mint::get_mod() != p) {\n        mint::set_mod(p);\n\
    \    }\n    uint64_t add = 0, g = 0;\n    mint k(1);\n    while ((g = _gcd(x,\
    \ p)) != 1) {\n        if (y == k.val()) return add;\n        if (y % g) return\
    \ -1;\n        y /= g, p /= g, add++;\n        k = (k.val() * (x / g));\n    }\n\
    \n    hash_map<uint32_t, uint32_t, 1 << 16> mp;\n\n    mint xm = mint(x).pow(m);\n\
    \    mint pr = mint(y);\n    for (int j = 0; j <= m; j++) {\n        mp[pr.val()]\
    \ = j;\n        pr *= x;\n    }\n    pr = k;\n    for (int i = 1; i <= m; i++)\
    \ {\n        pr *= xm;\n        auto ptr = mp.find(pr.val());\n        if (ptr)\
    \ {\n            int j = *ptr;\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n};  // namespace internal\n\n/// @brief Discrete Logarithm(\u96E2\
    \u6563\u5BFE\u6570)\ntemplate <typename T> inline long long mod_log(T a, T b,\
    \ T c) {\n    if (c < 1 << 30) {\n        return internal::__mod_log32(a, b, c);\n\
    \    } else {\n        return internal::__mod_log(a, b, c);\n    }\n}\n};  //\
    \ namespace kyopro\n\n///@docs docs/math/DLP.md\n"
  code: "#pragma once\n#include <cmath>\n#include \"../data-structure/hash_map.hpp\"\
    \n#include \"../math/dynamic_modint.hpp\"\n#include \"../math/gcd.hpp\"\n#include\
    \ \"../math/mod_pow.hpp\"\nnamespace kyopro {\nnamespace internal {\nlong long\
    \ __mod_log(uint64_t x, uint64_t y, uint64_t p) {\n    if (y == 1 || p == 1) {\n\
    \        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n        \
    \    return 1;\n        } else {\n            return -1;\n        }\n    }\n \
    \   uint32_t m = (uint32_t)sqrt(p) + 1;\n    hash_map<uint64_t, int> mp;\n   \
    \ uint64_t xm = mod_pow<uint64_t>(x, m, p);\n    uint64_t add = 0, g, k = (p ==\
    \ 1 ? 0 : 1);\n    while ((g = _gcd(x, p)) > 1) {\n        if (y == k) return\
    \ add;\n        if (y % g) return -1;\n        y /= g, p /= g, add++;\n      \
    \  k = (k * (x / g)) % p;\n    }\n\n    long long pr = y;\n    for (int j = 0;\
    \ j <= m; j++) {\n        mp[pr] = j;\n        (pr *= x) %= p;\n    }\n    pr\
    \ = k;\n    for (int i = 1; i <= m; i++) {\n        (pr *= xm) %= p;\n       \
    \ auto ptr = mp.find(pr);\n        if (ptr) {\n            int j = *ptr;\n   \
    \         return m * i - j + add;\n        }\n    }\n    return -1;\n}\n\nlong\
    \ long __mod_log32(uint32_t x, uint32_t y, uint32_t p) {\n    if (y == 1 || p\
    \ == 1) {\n        return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n\
    \            return 1;\n        } else {\n            return -1;\n        }\n\
    \    }\n    uint32_t m = (uint32_t)std::ceil(std::sqrt(p));\n    using mint =\
    \ barrett_modint<10>;\n    if (mint::get_mod() != p) {\n        mint::set_mod(p);\n\
    \    }\n    uint64_t add = 0, g = 0;\n    mint k(1);\n    while ((g = _gcd(x,\
    \ p)) != 1) {\n        if (y == k.val()) return add;\n        if (y % g) return\
    \ -1;\n        y /= g, p /= g, add++;\n        k = (k.val() * (x / g));\n    }\n\
    \n    hash_map<uint32_t, uint32_t, 1 << 16> mp;\n\n    mint xm = mint(x).pow(m);\n\
    \    mint pr = mint(y);\n    for (int j = 0; j <= m; j++) {\n        mp[pr.val()]\
    \ = j;\n        pr *= x;\n    }\n    pr = k;\n    for (int i = 1; i <= m; i++)\
    \ {\n        pr *= xm;\n        auto ptr = mp.find(pr.val());\n        if (ptr)\
    \ {\n            int j = *ptr;\n            return m * i - j + add;\n        }\n\
    \    }\n    return -1;\n}\n};  // namespace internal\n\n/// @brief Discrete Logarithm(\u96E2\
    \u6563\u5BFE\u6570)\ntemplate <typename T> inline long long mod_log(T a, T b,\
    \ T c) {\n    if (c < 1 << 30) {\n        return internal::__mod_log32(a, b, c);\n\
    \    } else {\n        return internal::__mod_log(a, b, c);\n    }\n}\n};  //\
    \ namespace kyopro\n\n///@docs docs/math/DLP.md"
  dependsOn:
  - src/data-structure/hash_map.hpp
  - src/math/dynamic_modint.hpp
  - src/internal/barrett.hpp
  - src/internal/montgomery.hpp
  - src/math/gcd.hpp
  - src/math/mod_pow.hpp
  isVerificationFile: false
  path: src/math/mod_log.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: src/math/mod_log.hpp
layout: document
redirect_from:
- /library/src/math/mod_log.hpp
- /library/src/math/mod_log.hpp.html
title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
---
## 概要
$x,y,p$に対して、$x^n\equiv y \bmod p$なる最小の**非負整数**$n$を求めます。ただし、存在しない場合は$-1$をreturnします。

## 使い方
```cpp
long long dlp(long long x,long long y,long long p)
```
上のやつを解きます

- 計算量:$O(\sqrt p)$
- 制約:
    - $0\leq x,y <p$
    - $x,y\in\mathbb{Z}$
    - $p\in\mathbb{N}$
    - $0^0=1$と定めている
