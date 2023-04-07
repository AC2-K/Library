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
    title: dynamic_modint
  - icon: ':question:'
    path: math/gcd.hpp
    title: math/gcd.hpp
  - icon: ':x:'
    path: math/mod_log.hpp
    title: "Discrete Logarithm(\u96E2\u6563\u5BFE\u6570)"
  - icon: ':question:'
    path: math/mod_pow.hpp
    title: "mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\u6CD5)"
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
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo_judge/math/Discrete_Logarithm.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n#line 2\
    \ \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define rep(i,\
    \ N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define popcount(x)\
    \ __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int, int>;\n\
    constexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps = 1e-6;\n\
    const long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\nconstexpr\
    \ uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr int\
    \ dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 1 \"math/mod_pow.hpp\"\ntemplate <class T, class U = T>\nconstexpr T mod_pow(T\
    \ base, T exp, T mod){\n    U ans = 1;\n    base %= mod;\n    while (exp) {\n\
    \        if (exp & 1) {\n            ans *= base;\n            ans %= mod;\n \
    \       }\n        base *= base;\n        base %= mod;\n        exp >>= 1;\n \
    \   }\n    return ans;\n}\n///@brief mod pow(\u7E70\u308A\u8FD4\u3057\u30CB\u4E57\
    \u6CD5)\n#line 3 \"math/gcd.hpp\"\ntemplate <typename T> constexpr T _gcd(T a,\
    \ T b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a +\
    \ b;\n    int d = std::min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>=\
    \ __builtin_ctzll(a), b >>= __builtin_ctzll(b);\n    while (a != b) {\n      \
    \  if (a == 0 || b == 0) {\n            return a + b;\n        }\n        if (a\
    \ > b) {\n            a -= b;\n            a >>= __builtin_ctzll(a);\n       \
    \ }else{\n            b -= a;\n            b >>= __builtin_ctzll(b);\n       \
    \ }\n    }\n\n    return a << d;\n}\ntemplate <typename T> constexpr T ext_gcd(T\
    \ a, T b, T& x, T& y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b)\
    \ {\n        T q = a / b;\n        std::tie(a, b) = std::make_pair(b, a % b);\n\
    \        std::tie(x, nx) = std::make_pair(nx, x - nx*q);\n        std::tie(y,\
    \ ny) = std::make_pair(ny, y - ny*q);\n    }\n    return a;\n}\n#line 3 \"data-structure/hash_map.hpp\"\
    \n/// @brief HashMap\ntemplate <typename Key,\n          typename Val,\n     \
    \     uint32_t n = 1 << 20,\n          Val default_val = Val()\n          >\n\
    class hash_map {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\n   \
    \ u64* flag = new u64[n];\n    Key* keys = new Key[n];\n    Val* vals = new Val[n];\n\
    \n    static constexpr u32 shift = 64 - __lg(n);\n\n    u64 r;\n    inline u32\
    \ get_hash(const Key& k) const {\n        return ((u64)k * r) >> shift;\n    }\n\
    \n    static constexpr uint8_t mod_msk = (1 << 6) - 1;\n\n  public:   \n    explicit\
    \ constexpr hash_map(){\n        r = std::chrono::steady_clock::now().time_since_epoch().count();\n\
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
    \            hash = (hash + 1) & (n - 1);\n        }\n    }\n};\n#line 2 \"internal/barrett.hpp\"\
    \nnamespace internal {\n\t///@brief barrett reduction\n\tclass barrett {\n\t\t\
    using u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\tu64 m;\n\t\tu64 im;\n\t\
    public:\n\t\texplicit barrett() = default;\n\t\texplicit barrett(u64 m_) :m(m_),\
    \ im((u64)(long double)static_cast<u64>(-1) / m_ + 1) {}\n\n\t\tu64 get_mod()\
    \ const { return m; }\n\t\tu64 reduce(int64_t a)const{\n        \tif (a < 0) return\
    \ m - reduce(-a);\n            u64 q = ((__uint128_t)a * im) >> 64;\n        \
    \    a -= m * q;\n            if (a >= m) a -= m;\n            return a;\n   \
    \     }\n\t\tu64 mul(u64 a, u64 b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\t\t\t\
    return 0;\n\t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im)\
    \ >> 64);\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\
    \treturn v;\n\t\t}\n\t};\n}\n#line 2 \"internal/montgomery.hpp\"\nnamespace internal\
    \ {\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using i32 = int32_t;\n\
    \    using i64 = int64_t;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\
    \    /// @brief MontgomeryReduction\n    template<typename T,typename LargeT>\n\
    \    class MontgomeryReduction64 {\n        static constexpr int lg = numeric_limits<T>::digits;\n\
    \        T mod, r, r2, minv;\n        T calc_inv() {\n            T t = 0, res\
    \ = 0;\n            for (int i = 0; i < lg; i++) {\n                if (~t & 1)\
    \ {\n                    t += mod;\n                    res += static_cast<T>(1)\
    \ << i;\n                }\n                t >>= 1;\n            }\n        \
    \    return res;\n        }\n\n\n    public:\n        MontgomeryReduction64()\
    \ = default;\n        constexpr T get_mod() { return mod; }\n        constexpr\
    \ int get_lg() { return lg; }\n\n\n        void set_mod(const T& m) {\n      \
    \      assert(m > 0);\n            assert(m & 1);\n\n            mod = m;\n\n\
    \            r = (-static_cast<T>(mod)) % mod;\n            r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n            minv = calc_inv();\n        }\n\n\n        T reduce(LargeT\
    \ x) const {\n            u64 res = (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n            if (res >= mod)res -= mod;\n          \
    \  return res;\n        }\n\n        T generate(LargeT x) {\n            return\
    \ reduce(x * r2);\n        }\n\n        T mult(T x, T y) {\n            return\
    \ reduce(static_cast<LargeT>(x) * y);\n        }\n    };\n};\n#line 6 \"math/dynamic_modint.hpp\"\
    \ntemplate <int id = -1>\nclass barrett_modint {\n    using u32 = uint32_t;\n\
    \    using u64 = uint64_t;\n\n    using i32 = int32_t;\n    using i64 = int64_t;\n\
    \    using br = internal::barrett;\n\n    static br brt;\n    static u32 mod;\n\
    \    u32 v;  // value\n  public:\n    static void set_mod(u32 mod_) {\n      \
    \  brt = br(mod_);\n        mod = mod_;\n    }\n\n  public:\n    explicit constexpr\
    \ barrett_modint() : v(0) {\n        assert(mod);\n    }  // mod\u304C\u6C7A\u5B9A\
    \u6E08\u307F\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n    explicit constexpr\
    \ barrett_modint(i64 v_) : v(brt.reduce(v_)) {\n        assert(mod);\n    }\n\n\
    \    u32 val() const { return v; }\n    static u32 get_mod() { return mod; }\n\
    \    using mint = barrett_modint<id>;\n    \n    // operators\n    constexpr mint&\
    \ operator=(i64 r) {\n        v = brt.reduce(r);\n        return (*this);\n  \
    \  }\n    constexpr mint& operator+=(const mint& r) {\n        v += r.v;\n   \
    \     if (v >= mod) {\n            v -= mod;\n        }\n        return (*this);\n\
    \    }\n    constexpr mint& operator-=(const mint& r) {\n        v += mod - r.v;\n\
    \        if (v >= mod) {\n            v -= mod;\n        }\n\n        return (*this);\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        v = brt.mul(v,\
    \ r.v);\n        return (*this);\n    }\n    constexpr mint operator+(const mint&\
    \ r) const { return mint(*this) += r; }\n    constexpr mint operator-(const mint&\
    \ r) const { return mint(*this) -= r; }\n    constexpr mint operator*(const mint&\
    \ r) const { return mint(*this) *= r; }\n\n    constexpr mint& operator+=(i64\
    \ r) { return (*this) += mint(r); }\n    constexpr mint& operator-=(i64 r) { return\
    \ (*this) -= mint(r); }\n    constexpr mint& operator*=(i64 r) { return (*this)\
    \ *= mint(r); }\n\n    friend mint operator+(i64 l, const mint& r) { return mint(l)\
    \ += r; }\n    friend mint operator+(const mint& l, i64 r) { return mint(l) +=\
    \ r; }\n    friend mint operator-(i64 l, const mint& r) { return mint(l) -= r;\
    \ }\n    friend mint operator-(const mint& l, i64 r) { return mint(l) -= r; }\n\
    \    friend mint operator*(i64 l, const mint& r) { return mint(l) *= r; }\n  \
    \  friend mint operator*(const mint& l, i64 r) { return mint(l) += r; }\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const mint& mt) {\n        os <<\
    \ mt.val();\n        return os;\n    }\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& mt) {\n        i64 v_;\n        is >> v_;\n        mt = v_;\n    \
    \    return is;\n    }\n    template <typename P> \n    constexpr mint pow(P e)\
    \ const {\n        assert(e >= 0);\n        mint res(1), base(*this);\n\n    \
    \    while (e) {\n            if (e & 1) {\n                res *= base;\n   \
    \         }\n            e >>= 1;\n            base *= base;\n        }\n    \
    \    return res;\n    }\n    constexpr mint inv() const { return pow(mod - 2);\
    \ }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv(); }\n  \
    \  mint operator/(const mint& r) const { return mint(*this) *= r.inv(); }\n  \
    \  mint& operator/=(i64 r) { return (*this) /= mint(r); }\n    friend mint operator/(const\
    \ mint& l, i64 r) { return mint(l) /= r; }\n    friend mint operator/(i64 l, const\
    \ mint& r) { return mint(l) /= r; }\n};\ntemplate <int id> typename barrett_modint<id>::u32\
    \ barrett_modint<id>::mod;\ntemplate<int id>typename barrett_modint<id>::br barrett_modint<id>::brt;\n\
    \n\n/// @brief dynamic_modint\ntemplate <typename T = uint32_t, typename LargeT\
    \ = uint64_t, int id = -1>\nclass dynamic_modint {\n    static T mod;\n    static\
    \ internal::MontgomeryReduction64<T, LargeT> mr;\n\n  public:\n    static void\
    \ set_mod(T mod_) {\n        mr.set_mod(mod_);\n        mod = mod_;\n    }\n \
    \   static T get_mod() { return mod; }\n\n  private:\n    T v;\n\n  public:\n\
    \    dynamic_modint(T v_ = 0) {\n        assert(mod);\n        v = mr.generate(v_);\n\
    \    }\n    T val() const { return mr.reduce(v); }\n    using mint = dynamic_modint<T,\
    \ LargeT, id>;\n    mint& operator+=(const mint& r) {\n        v += r.v;\n   \
    \     if (v >= mr.get_mod()) {\n            v -= mr.get_mod();\n        }\n\n\
    \        return (*this);\n    }\n    mint& operator-=(const mint& r) {\n     \
    \   v += mr.get_mod() - r.v;\n        if (v >= mr.get_mod) {\n            v -=\
    \ mr.get_mod();\n        }\n\n        return (*this);\n    }\n    mint& operator*=(const\
    \ mint& r) {\n        v = mr.mult(v, r.v);\n        return (*this);\n    }\n \
    \   mint operator+(const mint& r) { return mint(*this) += r; }\n    mint operator-(const\
    \ mint& r) { return mint(*this) -= r; }\n    mint operator*(const mint& r) { return\
    \ mint(*this) *= r; }\n    mint& operator=(const T& v_) {\n        (*this) = mint(v_);\n\
    \        return (*this);\n    }\n    friend ostream& operator<<(ostream& os, const\
    \ mint& mt) {\n        os << mt.val();\n        return os;\n    }\n    friend\
    \ istream& operator>>(istream& is, mint& mt) {\n        T v_;\n        is >> v_;\n\
    \        mt = v_;\n        return is;\n    }\n    template <typename P> \n   \
    \ constexpr mint pow(P e) const {\n        assert(e >= 0);\n        mint res(1),\
    \ base(*this);\n\n        while (e) {\n            if (e & 1) {\n            \
    \    res *= base;\n            }\n            e >>= 1;\n            base *= base;\n\
    \        }\n        return res;\n    }\n    mint inv() const { return pow(mod\
    \ - 2); }\n\n    mint& operator/=(const mint& r) { return (*this) *= r.inv();\
    \ }\n    mint operator/(const mint& r) const { return mint(*this) *= r.inv();\
    \ }\n    mint& operator/=(T r) { return (*this) /= mint(r); }\n    friend mint\
    \ operator/(const mint& l, T r) { return mint(l) /= r; };\n    friend mint operator/(T\
    \ l, const mint& r) { return mint(l) /= r; }\n};\ntemplate<typename T, typename\
    \ LargeT,int id>T dynamic_modint<T, LargeT,id>::mod;\ntemplate<typename T,typename\
    \ LargeT,int id>internal::MontgomeryReduction64<T,LargeT> dynamic_modint<T,LargeT,id>::mr;\n\
    \n\n///@docs docs/math/dynamic_modint.md\n#line 6 \"math/mod_log.hpp\"\nnamespace\
    \ internal{\n    ll __mod_log(uint64_t x, uint64_t y, uint64_t p) {\n        if\
    \ (y == 1 || p == 1) {\n            return 0;\n        }\n        if (x == 0)\
    \ {\n            if (y == 0) {\n                return 1;\n            }\n   \
    \         else {\n                return -1;\n            }\n        }\n     \
    \   uint32_t m = (uint32_t)sqrt(p) + 1;\n        hash_map<uint64_t, int> mp;\n\
    \        uint64_t xm = mod_pow<uint64_t>(x, m, p);\n        uint64_t add = 0,\
    \ g, k = (p == 1 ? 0 : 1);\n        while ((g = _gcd(x, p)) > 1) {\n         \
    \   if (y == k)return add;\n            if (y % g)return -1;\n            y /=\
    \ g, p /= g, add++;\n            k = (k * (x / g)) % p;\n        }\n\n       \
    \ ll pr = y;\n        for (int j = 0; j <= m; j++) {\n            mp[pr] = j;\n\
    \            (pr *= x) %= p;\n        }\n        pr = k;\n        for (int i =\
    \ 1; i <= m; i++) {\n            (pr *= xm) %= p;\n            auto ptr = mp.find(pr);\n\
    \            if (ptr) {\n                int j = *ptr;\n                return\
    \ m * i - j + add;\n            }\n        }\n        return -1;\n    }\n\n  \
    \  ll __mod_log32(uint32_t x, uint32_t y, uint32_t p) {\n        if (y == 1 ||\
    \ p == 1) {\n            return 0;\n        }\n        if (x == 0) {\n       \
    \     if (y == 0) {\n                return 1;\n            }\n            else\
    \ {\n                return -1;\n            }\n        }\n        uint32_t m\
    \ = (uint32_t)ceil(sqrt(p));\n        using mint = barrett_modint<10>;\n     \
    \   if (mint::get_mod() != p) {\n            mint::set_mod(p);\n        }\n  \
    \      uint64_t add = 0, g = 0;\n        mint k(1);\n        while ((g = _gcd(x,\
    \ p)) != 1) {\n            if (y == k.val())return add;\n            if (y % g)return\
    \ -1;\n            y /= g, p /= g, add++;\n            k = (k.val() * (x / g));\n\
    \        }\n\n        hash_map<uint32_t, uint32_t, 1 << 16> mp;\n\n        mint\
    \ xm = mint(x).pow(m);\n        mint pr = mint(y);\n        for (int j = 0; j\
    \ <= m; j++) {\n            mp[pr.val()] = j;\n            pr *= x;\n        }\n\
    \        pr = k;\n        for (int i = 1; i <= m; i++) {\n            pr *= xm;\n\
    \            auto ptr = mp.find(pr.val());\n            if (ptr) {\n         \
    \       int j = *ptr;\n                return m * i - j + add;\n            }\n\
    \        }\n        return -1;\n    }\n};\n\n\n/// @brief Discrete Logarithm(\u96E2\
    \u6563\u5BFE\u6570)\ntemplate<typename T>\ninline ll mod_log(T a,T b,T c){\n \
    \   if (c < 1 << 30) {\n        return internal::__mod_log32(a, b, c);\n    }\
    \ else {\n        return internal::__mod_log(a, b, c);\n    }\n}\n\n\n\n///@docs\
    \ docs/math/DLP.md\n#line 4 \"test/yosupo_judge/math/Discrete_Logarithm.test.cpp\"\
    \nint main() {\n    int t;\n    scanf(\"%d\", &t);\n    while (t--) {\n      \
    \  int x, y, p;\n        scanf(\"%d%d%d\", &x, &y, &p);\n        printf(\"%lld\\\
    n\", mod_log<long long>(x, y, p));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n#include\"template.hpp\"\n#include\"math/mod_log.hpp\"\nint main() {\n    int\
    \ t;\n    scanf(\"%d\", &t);\n    while (t--) {\n        int x, y, p;\n      \
    \  scanf(\"%d%d%d\", &x, &y, &p);\n        printf(\"%lld\\n\", mod_log<long long>(x,\
    \ y, p));\n    }\n}"
  dependsOn:
  - template.hpp
  - math/mod_log.hpp
  - math/mod_pow.hpp
  - math/gcd.hpp
  - data-structure/hash_map.hpp
  - math/dynamic_modint.hpp
  - internal/barrett.hpp
  - internal/montgomery.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
  requiredBy: []
  timestamp: '2023-04-07 15:13:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Discrete_Logarithm.test.cpp
- /verify/test/yosupo_judge/math/Discrete_Logarithm.test.cpp.html
title: test/yosupo_judge/math/Discrete_Logarithm.test.cpp
---
