---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/hash_map.hpp
    title: HashMap
  - icon: ':question:'
    path: internal/barrett.hpp
    title: barrett reduction
  - icon: ':question:'
    path: internal/montgomery.hpp
    title: MontgomeryReduction
  - icon: ':question:'
    path: math/dynamic_modint.hpp
    title: "dynamic modint(\u52D5\u7684modint)"
  - icon: ':question:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  - icon: ':question:'
    path: math/mod_pow.hpp
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
  bundledCode: "#line 2 \"math/mod_log.hpp\"\n#include<cmath>\n#line 2 \"math/mod_pow.hpp\"\
    \nnamespace library {\n\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\
    \u6CD5)\ntemplate <class T, class U = T>\nconstexpr T mod_pow(T base, T exp, T\
    \ mod){\n    U ans = 1;\n    base %= mod;\n    while (exp) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n\n};  // namespace library\n#line 1 \"math/gcd.hpp\"\n#include <tuple>\n\
    namespace library {\ntemplate <typename T> constexpr inline T _gcd(T a, T b) {\n\
    \    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n    int\
    \ d = std::min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr inline T ext_gcd(T a, T b, T &x,\
    \ T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T\
    \ q = a / b;\n        std::tie(a, b) = std::make_pair(b, a % b);\n        std::tie(x,\
    \ nx) = std::make_pair(nx, x - nx * q);\n        std::tie(y, ny) = std::make_pair(ny,\
    \ y - ny * q);\n    }\n    return a;\n}\n\n};  // namespace library\n#line 1 \"\
    data-structure/hash_map.hpp\"\n#include<iostream>\n#include<chrono>\nnamespace\
    \ library{\n\n/// @brief HashMap\n/// @tparam Key Key\u306E\u578B\n/// @tparam\
    \ Val Value\u306E\u578B\ntemplate <typename Key,\n          typename Val,\n  \
    \        uint32_t n = 1 << 20,\n          Val default_val = Val()\n          >\n\
    class hash_map {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n   \
    \ u64* flag = new u64[n];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\
    \n    static constexpr u32 shift = 64 - std::__lg(n);\n\n    u64 r;\n    inline\
    \ u32 get_hash(const Key& k) const {\n        return ((u64)k * r) >> shift;\n\
    \    }\n\n    static constexpr uint8_t mod_msk = (1 << 6) - 1;\n\n  public:  \
    \ \n    explicit constexpr hash_map(){\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \        r ^= r >> 16;\n        r ^= r << 32;\n    }\n    Val& operator[](const\
    \ Key& k) {\n        u32 hash = get_hash(k);\n\n        while (1) {\n        \
    \    if (!(flag[hash >> 6] &\n                  (static_cast<u64>(1) << (hash\
    \ & mod_msk)))) {\n                keys[hash] = k;\n                flag[hash\
    \ >> 6] |= static_cast<u64>(1)\n                                   << (hash &\
    \ mod_msk);\n                return vals[hash] = default_val;\n            }\n\
    \n            if (keys[hash] == k)return vals[hash];\n            hash = (hash\
    \ + 1) & (n - 1);\n        }\n    }\n\n    const Val* find(const Key&k)const{\n\
    \        u32 hash = get_hash(k);\n        while (1) {\n            if (!(flag[hash\
    \ >> 6] &\n                  (static_cast<u64>(1) << (hash & mod_msk))))\n   \
    \             return nullptr;\n            if (keys[hash] == k) return &(vals[hash]);\n\
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n\n\n};  // namespace\
    \ library\n#line 3 \"internal/barrett.hpp\"\nnamespace library {\nnamespace internal\
    \ {\n/// @brief barrett reduction\nclass barrett {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    u64 m;\n    u64 im;\n\n  public:\n    explicit\
    \ barrett() = default;\n    constexpr explicit barrett(u64 m_)\n        : m(m_),\
    \ im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\n    inline u64 get_mod()\
    \ const { return m; }\n    inline u64 reduce(int64_t a) const {\n        if (a\
    \ < 0) return m - reduce(-a);\n        u64 q = ((__uint128_t)a * im) >> 64;\n\
    \        a -= m * q;\n        if (a >= m) a -= m;\n        return a;\n    }\n\
    \    inline u64 mul(u64 a, u64 b) {\n        if (a == 0 || b == 0) {\n       \
    \     return 0;\n        }\n        u64 z = a;\n        z *= b;\n        u64 x\
    \ = (u64)(((__uint128_t)(z)*im) >> 64);\n\n        u32 v = (u32)(z - x * m);\n\
    \n        if (v >= m) v += m;\n        return v;\n    }\n};\n};  // namespace\
    \ internal\n};  // namespace library\n#line 3 \"internal/montgomery.hpp\"\nnamespace\
    \ library {\nnamespace internal {\nusing u32 = uint32_t;\nusing u64 = uint64_t;\n\
    using i32 = int32_t;\nusing i64 = int64_t;\nusing u128 = __uint128_t;\nusing i128\
    \ = __int128_t;\n/// @brief MontgomeryReduction\ntemplate <typename T, typename\
    \ LargeT>\nclass MontgomeryReduction {\n    static constexpr int lg = std::numeric_limits<T>::digits;\n\
    \    T mod, r, r2, minv;\n    T calc_inv() {\n        T t = 0, res = 0;\n    \
    \    for (int i = 0; i < lg; i++) {\n            if (~t & 1) {\n             \
    \   t += mod;\n                res += static_cast<T>(1) << i;\n            }\n\
    \            t >>= 1;\n        }\n        return res;\n    }\n\n  public:\n  \
    \  MontgomeryReduction() = default;\n    constexpr T get_mod() { return mod; }\n\
    \    constexpr int get_lg() { return lg; }\n\n    void set_mod(const T& m) {\n\
    \n        assert(m > 0);\n        assert(m & 1);\n\n        mod = m;\n\n     \
    \   r = (-static_cast<T>(mod)) % mod;\n        r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n        minv = calc_inv();\n    }\n\n    T reduce(LargeT x) const {\n\
    \        u64 res =\n            (x + static_cast<LargeT>(static_cast<T>(x) * minv)\
    \ * mod) >> lg;\n\n        if (res >= mod) res -= mod;\n        return res;\n\
    \    }\n\n    T generate(LargeT x) { return reduce(x * r2); }\n\n    T mult(T\
    \ x, T y) { return reduce(static_cast<LargeT>(x) * y); }\n};\n};  // namespace\
    \ internal\n};  // namespace library\n#line 4 \"math/dynamic_modint.hpp\"\n\n\
    namespace library{\ntemplate<int id=-1>\nclass barrett_modint {\n\tusing u32 =\
    \ uint32_t;\n\tusing u64 = uint64_t;\n\n\tusing i32 = int32_t;\n\tusing i64 =\
    \ int64_t;\n\tusing br = internal::barrett;\n\n\tstatic br brt;\n\tstatic u32\
    \ mod;\n\tu32 v;\t//value\npublic:\n\tstatic void set_mod(u32 mod_) {\n\t\tbrt\
    \ = br(mod_);\n\t\tmod = mod_;\n\t}\npublic:\n\texplicit constexpr barrett_modint()\
    \ :v(0) { assert(mod); }\t//mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n\texplicit constexpr barrett_modint(i64 v_) :v(brt.reduce(v_))\
    \ { assert(mod); }\t\n\n\tu32 val() const { return v; }\n    static u32 get_mod()\
    \ { return mod; }\n    using mint = barrett_modint<id>;\n\n\t//operators\n\tconstexpr\
    \ mint& operator=(i64 r) {\n\t\tv = brt.reduce(r); \n\t\treturn (*this);\n\t}\n\
    \tconstexpr mint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod)\
    \ {\n\t\t\tv -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator-=(const\
    \ mint&r) {\n\t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\
    \n\t\treturn (*this);\n\t}\n\tconstexpr mint& operator*=(const mint& r) {\n\t\t\
    v = brt.mul(v, r.v);\n\t\treturn (*this);\n\t}\n\n\tconstexpr mint operator+(const\
    \ mint& r) const { return mint(*this) += r; }\n\tconstexpr mint operator-(const\
    \ mint& r) const { return mint(*this) -= r; }\n\tconstexpr mint operator*(const\
    \ mint& r) const { return mint(*this) *= r; }\n\n\n\n\tconstexpr mint& operator+=\
    \ (i64 r) { return (*this) += mint(r); }\n\tconstexpr mint& operator-= (i64 r)\
    \ { return (*this) -= mint(r); }\n\tconstexpr mint& operator*= (i64 r) { return\
    \ (*this) *= mint(r); }\n\n\tfriend mint operator+(i64 l, const mint& r) { return\
    \ mint(l) += r; }\n\tfriend mint operator+(const mint& l, i64 r) { return mint(l)\
    \ += r; }\n\tfriend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n\tfriend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\t\
    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n\tfriend\
    \ mint operator*(const mint& l, i64 r) { return mint(l) += r; }\n\n\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mint& mt) {\n\t\tos << mt.val();\n\
    \t\treturn os;\n\t}\n\tfriend std::istream& operator>>(std::istream& is, mint&\
    \ mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\t\treturn is;\n\t}\n\tconstexpr\
    \ mint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\n\t\twhile (e) {\n\t\
    \t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te >>= 1;\n\t\t\tbase *=\
    \ base;\n\t\t}\n\t\treturn res;\n\t}\n\tconstexpr mint inv() const {\n\t\treturn\
    \ pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) { return (*this) *=\
    \ r.inv(); }\n\tmint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n\tmint& operator/=(i64 r) { return (*this) /= mint(r); }\n\tfriend mint operator/(const\
    \ mint& l, i64 r) { return mint(l) /= r; }\n\tfriend mint operator/(i64 l, const\
    \ mint& r) { return mint(l) /= r; }\n};\n};  // namespace library\ntemplate <int\
    \ id> typename library::barrett_modint<id>::u32 library::barrett_modint<id>::mod;\n\
    template<int id>typename library::barrett_modint<id>::br library::barrett_modint<id>::brt;\n\
    \nnamespace library{\n\ntemplate <typename T = uint32_t, typename LargeT = uint64_t,\
    \ int id = -1>\nclass dynamic_modint {\n        static T mod;\n        static\
    \ internal::MontgomeryReduction<T, LargeT> mr;\n\n      public:\n        static\
    \ void set_mod(T mod_) {\n            mr.set_mod(mod_);\n            mod = mod_;\n\
    \        }\n\n        static T get_mod() { return mod; }\n\n      private:\n \
    \       T v;\n      public:\n        dynamic_modint(T v_ = 0) {\n            \
    \    assert(mod);\n                v = mr.generate(v_);\n        }\n        T\
    \ val() const { return mr.reduce(v); }\n\n        using mint = dynamic_modint<T,\
    \ LargeT,id>;\n        mint& operator+=(const mint& r) {\n                v +=\
    \ r.v;\n                if (v >= mr.get_mod()) {\n                        v -=\
    \ mr.get_mod();\n                }\n\n                return (*this);\n      \
    \  }\n\n        mint& operator-=(const mint& r) {\n                v += mr.get_mod()\
    \ - r.v;\n                if (v >= mr.get_mod) {\n                        v -=\
    \ mr.get_mod();\n                }\n\n                return (*this);\n      \
    \  }\n\n        mint& operator*=(const mint& r) {\n                v = mr.mult(v,\
    \ r.v);\n                return (*this);\n        }\n\n        mint operator+(const\
    \ mint& r) { return mint(*this) += r; }\n        mint operator-(const mint& r)\
    \ { return mint(*this) -= r; }\n        mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n\n        mint& operator=(const T& v_) {\n            \
    \    (*this) = mint(v_);\n                return (*this);\n        }\n\n     \
    \   friend std::ostream& operator<<(std::ostream& os, const mint& mt) {\n    \
    \            os << mt.val();\n                return os;\n        }\n        friend\
    \ std::istream& operator>>(std::istream& is, mint& mt) {\n                T v_;\n\
    \                is >> v_;\n                mt = v_;\n                return is;\n\
    \        }\n        template <typename P> mint pow(P e) const {\n            \
    \    assert(e >= 0);\n                mint res(1), base(*this);\n\n          \
    \      while (e) {\n                        if (e & 1) {\n                   \
    \             res *= base;\n                        }\n                      \
    \  e >>= 1;\n                        base *= base;\n                }\n      \
    \          return res;\n        }\n        mint inv() const { return pow(mod -\
    \ 2); }\n\n        mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n        mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n        mint& operator/=(T r) { return (*this) /= mint(r); }\n        friend\
    \ mint operator/(const mint& l, T r) {\n                return mint(l) /= r;\n\
    \        }\n        friend mint operator/(T l, const mint& r) {\n            \
    \    return mint(l) /= r;\n        }\n};\n\n};  // namespace library\n\ntemplate\
    \ <typename T, typename LargeT, int id>\nT library::dynamic_modint<T, LargeT,\
    \ id>::mod;\ntemplate <typename T, typename LargeT, int id>\nlibrary::internal::MontgomeryReduction<T,\
    \ LargeT>\n    library::dynamic_modint<T, LargeT, id>::mr;\n\n///@brief dynamic\
    \ modint(\u52D5\u7684modint)\n///@docs docs/math/dynamic_modint.md\n#line 7 \"\
    math/mod_log.hpp\"\n\nnamespace library {\nnamespace internal{\n    long long\
    \ __mod_log(uint64_t x, uint64_t y, uint64_t p) {\n        if (y == 1 || p ==\
    \ 1) {\n            return 0;\n        }\n        if (x == 0) {\n            if\
    \ (y == 0) {\n                return 1;\n            }\n            else {\n \
    \               return -1;\n            }\n        }\n        uint32_t m = (uint32_t)std::sqrt(p)\
    \ + 1;\n        hash_map<uint64_t, int> mp;\n        uint64_t xm = mod_pow<uint64_t>(x,\
    \ m, p);\n        uint64_t add = 0, g, k = (p == 1 ? 0 : 1);\n        while ((g\
    \ = _gcd(x, p)) > 1) {\n            if (y == k)return add;\n            if (y\
    \ % g)return -1;\n            y /= g, p /= g, add++;\n            k = (k * (x\
    \ / g)) % p;\n        }\n\n        long long pr = y;\n        for (int j = 0;\
    \ j <= m; j++) {\n            mp[pr] = j;\n            (pr *= x) %= p;\n     \
    \   }\n        pr = k;\n        for (int i = 1; i <= m; i++) {\n            (pr\
    \ *= xm) %= p;\n            auto ptr = mp.find(pr);\n            if (ptr) {\n\
    \                int j = *ptr;\n                return m * i - j + add;\n    \
    \        }\n        }\n        return -1;\n    }\n\n    long long __mod_log32(uint32_t\
    \ x, uint32_t y, uint32_t p) {\n        if (y == 1 || p == 1) {\n            return\
    \ 0;\n        }\n        if (x == 0) {\n            if (y == 0) {\n          \
    \      return 1;\n            }\n            else {\n                return -1;\n\
    \            }\n        }\n        uint32_t m = (uint32_t)std::ceil(std::sqrt(p));\n\
    \        using mint = barrett_modint<10>;\n        if (mint::get_mod() != p) {\n\
    \            mint::set_mod(p);\n        }\n        uint64_t add = 0, g = 0;\n\
    \        mint k(1);\n        while ((g = _gcd(x, p)) != 1) {\n            if (y\
    \ == k.val())return add;\n            if (y % g)return -1;\n            y /= g,\
    \ p /= g, add++;\n            k = (k.val() * (x / g));\n        }\n\n        hash_map<uint32_t,\
    \ uint32_t, 1 << 16> mp;\n\n        mint xm = mint(x).pow(m);\n        mint pr\
    \ = mint(y);\n        for (int j = 0; j <= m; j++) {\n            mp[pr.val()]\
    \ = j;\n            pr *= x;\n        }\n        pr = k;\n        for (int i =\
    \ 1; i <= m; i++) {\n            pr *= xm;\n            auto ptr = mp.find(pr.val());\n\
    \            if (ptr) {\n                int j = *ptr;\n                return\
    \ m * i - j + add;\n            }\n        }\n        return -1;\n    }\n};\n\n\
    \n/// @brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)\ntemplate<typename T>\n\
    inline long long mod_log(T a,T b,T c){\n    if (c <= 1 << 30) {\n        return\
    \ internal::__mod_log32(a, b, c);\n    } else {\n        return internal::__mod_log(a,\
    \ b, c);\n    }\n}\n};  // namespace library\n\n\n/// @docs docs/math/DLP.md\n"
  code: "#pragma once\n#include<cmath>\n#include\"math/mod_pow.hpp\"\n#include\"math/gcd.hpp\"\
    \n#include\"data-structure/hash_map.hpp\"\n#include\"math/dynamic_modint.hpp\"\
    \n\nnamespace library {\nnamespace internal{\n    long long __mod_log(uint64_t\
    \ x, uint64_t y, uint64_t p) {\n        if (y == 1 || p == 1) {\n            return\
    \ 0;\n        }\n        if (x == 0) {\n            if (y == 0) {\n          \
    \      return 1;\n            }\n            else {\n                return -1;\n\
    \            }\n        }\n        uint32_t m = (uint32_t)std::sqrt(p) + 1;\n\
    \        hash_map<uint64_t, int> mp;\n        uint64_t xm = mod_pow<uint64_t>(x,\
    \ m, p);\n        uint64_t add = 0, g, k = (p == 1 ? 0 : 1);\n        while ((g\
    \ = _gcd(x, p)) > 1) {\n            if (y == k)return add;\n            if (y\
    \ % g)return -1;\n            y /= g, p /= g, add++;\n            k = (k * (x\
    \ / g)) % p;\n        }\n\n        long long pr = y;\n        for (int j = 0;\
    \ j <= m; j++) {\n            mp[pr] = j;\n            (pr *= x) %= p;\n     \
    \   }\n        pr = k;\n        for (int i = 1; i <= m; i++) {\n            (pr\
    \ *= xm) %= p;\n            auto ptr = mp.find(pr);\n            if (ptr) {\n\
    \                int j = *ptr;\n                return m * i - j + add;\n    \
    \        }\n        }\n        return -1;\n    }\n\n    long long __mod_log32(uint32_t\
    \ x, uint32_t y, uint32_t p) {\n        if (y == 1 || p == 1) {\n            return\
    \ 0;\n        }\n        if (x == 0) {\n            if (y == 0) {\n          \
    \      return 1;\n            }\n            else {\n                return -1;\n\
    \            }\n        }\n        uint32_t m = (uint32_t)std::ceil(std::sqrt(p));\n\
    \        using mint = barrett_modint<10>;\n        if (mint::get_mod() != p) {\n\
    \            mint::set_mod(p);\n        }\n        uint64_t add = 0, g = 0;\n\
    \        mint k(1);\n        while ((g = _gcd(x, p)) != 1) {\n            if (y\
    \ == k.val())return add;\n            if (y % g)return -1;\n            y /= g,\
    \ p /= g, add++;\n            k = (k.val() * (x / g));\n        }\n\n        hash_map<uint32_t,\
    \ uint32_t, 1 << 16> mp;\n\n        mint xm = mint(x).pow(m);\n        mint pr\
    \ = mint(y);\n        for (int j = 0; j <= m; j++) {\n            mp[pr.val()]\
    \ = j;\n            pr *= x;\n        }\n        pr = k;\n        for (int i =\
    \ 1; i <= m; i++) {\n            pr *= xm;\n            auto ptr = mp.find(pr.val());\n\
    \            if (ptr) {\n                int j = *ptr;\n                return\
    \ m * i - j + add;\n            }\n        }\n        return -1;\n    }\n};\n\n\
    \n/// @brief Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)\ntemplate<typename T>\n\
    inline long long mod_log(T a,T b,T c){\n    if (c <= 1 << 30) {\n        return\
    \ internal::__mod_log32(a, b, c);\n    } else {\n        return internal::__mod_log(a,\
    \ b, c);\n    }\n}\n};  // namespace library\n\n\n/// @docs docs/math/DLP.md"
  dependsOn:
  - math/mod_pow.hpp
  - math/gcd.hpp
  - data-structure/hash_map.hpp
  - math/dynamic_modint.hpp
  - internal/barrett.hpp
  - internal/montgomery.hpp
  isVerificationFile: false
  path: math/mod_log.hpp
  requiredBy: []
  timestamp: '2023-04-06 21:43:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/math/Discrete_Logarithm.test.cpp
documentation_of: math/mod_log.hpp
layout: document
redirect_from:
- /library/math/mod_log.hpp
- /library/math/mod_log.hpp.html
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
