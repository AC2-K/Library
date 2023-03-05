---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/fast_prime_check.hpp
    title: "fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)"
  - icon: ':x:'
    path: math/mod_pow.hpp
    title: "mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)"
  - icon: ':x:'
    path: math/montgomery.hpp
    title: Montgomery
  - icon: ':x:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"sub.cpp\"\n#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconstexpr long double pi = acos(-1);\nconstexpr ll MOD = 1e9 + 7;\n\
    constexpr ll MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>inline void chmax(T&x,T y){if(x<y)x=y;}\n\
    template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}\n#line 1 \"math/mod_pow.hpp\"\
    \ntemplate <class T, class U = T>\nU mod_pow(T base, T exp, T mod){\n    if(base==0)return\
    \ 0;\n    T ans = 1;\n    base %= mod;\n    while (exp > 0) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n///@brief mod pow(\u30D0\u30A4\u30CA\u30EA\u6CD5)\n#line 2 \"math/montgomery.hpp\"\
    \nclass montgomery64 {\n    using mint = montgomery64;\n    using i64 = int64_t;\n\
    \    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\n    static u64 mod;\n\
    \    static u64 r;\n    static u64 n2;\n\n    static u64 get_r() {\n        u64\
    \ ret = mod;\n        for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n    \
    \    return ret;\n    }\npublic:\n    static void set_mod(const u128& m) {\n \
    \       assert(m < (i128(1) << 64));\n        assert((m & 1) == 1);\n        mod\
    \ = m;\n        n2 = -u128(m) % m;\n        r = get_r();\n        assert(r * mod\
    \ == 1);\n    }\n\nprotected:\n    u128 a;\n\npublic:\n    montgomery64() : a(0)\
    \ {}\n    template<typename T>\n    montgomery64(const T& b) : a(reduce((u128(b)\
    \ + mod)* n2)) {};\nprivate:\n    template<class T>\n    static u64 reduce(const\
    \ T& b) {\n        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;\n    }\npublic:\n\
    \    template<class T>\n    mint& operator=(const T& rhs) {\n        return (*this)\
    \ = mint(rhs);\n    }\n\n    mint& operator+=(const mint& b) {\n        if (i64(a\
    \ += b.a - 2 * mod) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    mint&\
    \ operator-=(const mint& b) {\n        if (i64(a -= b.a) < 0) a += 2 * mod;\n\
    \        return *this;\n    }\n\n    mint& operator*=(const mint& b) {\n     \
    \   a = reduce(u128(a) * b.a);\n        return *this;\n    }\n\n    mint& operator/=(const\
    \ mint& b) {\n        *this *= b.inv();\n        return *this;\n    }\n\n    mint\
    \ operator+(const mint& b) const { return mint(*this) += b; }\n    mint operator-(const\
    \ mint& b) const { return mint(*this) -= b; }\n    mint operator*(const mint&\
    \ b) const { return mint(*this) *= b; }\n    mint operator/(const mint& b) const\
    \ { return mint(*this) /= b; }\n    bool operator==(const mint& b) const {\n \
    \       return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n \
    \   }\n    bool operator!=(const mint& b) const {\n        return (a >= mod ?\
    \ a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n    }\n    mint operator-()\
    \ const { return mint() - mint(*this); }\n\n    mint pow(u128 n) const {\n   \
    \     mint ret(1), mul(*this);\n        while (n > 0) {\n            if (n & 1)\
    \ ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n    \
    \    return ret;\n    }\n\n    friend ostream& operator<<(ostream& os, const mint&\
    \ b) {\n        return os << b.val();\n    }\n\n    friend istream& operator>>(istream&\
    \ is, mint& b) {\n        int64_t t;\n        is >> t;\n        b = montgomery64(t);\n\
    \        return (is);\n    }\n\n    mint inv() const { return pow(mod - 2); }\n\
    \n    u64 val() const {\n        u64 ret = reduce(a);\n        return ret >= mod\
    \ ? ret - mod : ret;\n    }\n\n    static u64 get_mod() { return mod; }\n};\n\
    typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;\n\
    \nclass montgomery32 {\n    using mint = montgomery32;\n    using i32 = int32_t;\n\
    \    using u32 = uint32_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \    static u32 mod;\n    static u32 r;\n    static u32 n2;\n\n    static u32\
    \ get_r() {\n        u32 ret = mod;\n        for (i32 i = 0; i < 4; ++i) ret *=\
    \ 2 - mod * ret;\n        return ret;\n    }\npublic:\n    static void set_mod(u32\
    \ m) {\n        assert(m < (1ll << 31));\n        assert((m & 1) == 1);\n    \
    \    mod = m;\n        n2 = -u64(m) % m;\n        r = get_r();\n        assert(r\
    \ * mod == 1);\n    }\nprotected:\n    u128 a;\npublic:\n    montgomery32() :\
    \ a(0) {}\n    montgomery32(const int64_t& b)\n        : a(reduce(u64(b% mod +\
    \ mod)* n2)) {};\n\n    static u32 reduce(const u64& b) {\n        return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n    }\n\n    mint& operator+=(const mint&\
    \ b) {\n        if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n        return\
    \ *this;\n    }\n\n    mint& operator-=(const mint& b) {\n        if (i32(a -=\
    \ b.a) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    mint& operator*=(const\
    \ mint& b) {\n        a = reduce(u64(a) * b.a);\n        return *this;\n    }\n\
    \n    mint& operator/=(const mint& b) {\n        *this *= b.inv();\n        return\
    \ *this;\n    }\n\n    mint operator+(const mint& b) const { return mint(*this)\
    \ += b; }\n    mint operator-(const mint& b) const { return mint(*this) -= b;\
    \ }\n    mint operator*(const mint& b) const { return mint(*this) *= b; }\n  \
    \  mint operator/(const mint& b) const { return mint(*this) /= b; }\n    bool\
    \ operator==(const mint& b) const {\n        return (a >= mod ? a - mod : a) ==\
    \ (b.a >= mod ? b.a - mod : b.a);\n    }\n    bool operator!=(const mint& b) const\
    \ {\n        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \    }\n    mint operator-() const { return mint() - mint(*this); }\n\n    mint\
    \ pow(u64 n) const {\n        mint ret(1), mul(*this);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n        return os << b.val();\n    }\n\n    friend istream&\
    \ operator>>(istream& is, mint& b) {\n        int64_t t;\n        is >> t;\n \
    \       b = montgomery32(t);\n        return (is);\n    }\n\n    mint inv() const\
    \ { return pow(mod - 2); }\n\n    u32 val() const {\n        u32 ret = reduce(a);\n\
    \        return ret >= mod ? ret - mod : ret;\n    }   \n\n    static u32 get_mod()\
    \ { return mod; }\n};\ntypename montgomery32::u32 montgomery32::mod;\ntypename\
    \ montgomery32::u32 montgomery32::r;\ntypename montgomery32::u32 montgomery32::n2;\n\
    /// @brief Montgomery\n///by https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp\n\
    #line 4 \"math/fast_prime_check.hpp\"\nnamespace prime {\n    namespace miller{\n\
    \        using i128 = __int128_t;\n        using u128 = __uint128_t;\n       \
    \ using u64 = __uint64_t;\n        bool miller_rabin(u64 n,const u64 bases[],int\
    \ siz) {\n            u64 d = n - 1;\n            u64 q = __builtin_ctz(d);\n\
    \            d >>= q;\n\n            for(int i=0;i<siz;i++){\n               \
    \ u64 a = bases[i];\n                if (a == n) {\n                    return\
    \ true;\n                } else if (n % a == 0) {\n                    return\
    \ false;\n                }\n                if (mod_pow<u128>(a, d, n) != 1)\
    \ {\n                    bool flag = true;\n                    for (u64 r = 0;\
    \ r < q; r++) {\n                        u64 pow = mod_pow<u128>(a, d * (1ll <<\
    \ r), n);\n                        if (pow == n - 1) {\n                     \
    \       flag = false;\n                            break;\n                  \
    \      }\n                    }\n\n                    if (flag) {\n         \
    \               return false;\n                    }\n                }\n    \
    \        }\n            return true;\n        }\n\n\n        bool is_prime(u64\
    \ n){\n            static constexpr u64 bases_int[3] = {2, 7, 61};  // int\u3060\
    \u3068\u30012,7,61\u3067\u5341\u5206\n            static constexpr u64 bases_ll[7]\
    \ = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n            if (n < 2)\
    \ {\n                return false;\n            } else if (n == 2) {\n       \
    \         return true;\n            } else if (~n & 1) {\n                return\
    \ false;\n            }\n\n            if(n<(1ul<<31)){\n                return\
    \ miller_rabin(n, bases_int, 3);\n            } else {\n                return\
    \ miller_rabin(n, bases_ll, 7);\n            }\n        }\n    };\n};\nusing prime::miller::is_prime;\n\
    ///@brief fast prime check(MillerRabin\u306E\u7D20\u6570\u5224\u5B9A\u6CD5)\n\
    #line 5 \"sub.cpp\"\nnamespace prime{\n    namespace pollard{\n        using i128\
    \ = __int128_t;\n        using u128 = __uint128_t;\n        using u64 = __uint64_t;\n\
    \        u64 c;\n        u64 xor_shift() { \n            static u64 v = 7001;\n\
    \            v ^= v << 13;\n            v ^= v >> 7;\n            v ^= v << 17;\n\
    \n            return v;\n        }\n        i128 gcd(i128 x,i128 y){\n       \
    \     while(y!=0){\n                i128 ny = x % y;\n                i128 nx\
    \ = y;\n                x = nx, y = ny;\n            }\n            return x;\n\
    \        }\n        u64 find_factor(u64 n){\n            if (~n & 1ul) {\n   \
    \             return 2;\n            }\n            if (is_prime(n)) {\n     \
    \           return n;\n            }\n            while(1){\n                auto\
    \ f = [&](i128 x) -> u64 {\n                    x %= n;\n                    return\
    \ (x * x % n + c) % n;\n                };\n                c = xor_shift() %\
    \ n;\n                ll x = xor_shift() % n;\n                ll y = x;\n   \
    \             ll d = 1;\n                while (d == 1) {\n                  \
    \  x = f(x);\n                    y = f(f(y));\n\n                    d = gcd(abs(x\
    \ - y), n);\n                }\n                if (d != n) {\n              \
    \      return d;\n                }\n            }\n            exit(0);\n   \
    \     }\n\n        vector<u64> rho_fact(u64 n){\n            vector<u64> v;\n\
    \            while (n != 1) {\n                u64 d = 0;\n                d =\
    \ find_factor(n);\n                while (n % d == 0) {\n                    n\
    \ /= d;\n                    v.emplace_back(d);\n                }\n         \
    \   }\n            return v;\n        }\n        vector<u64> naive(u64&n){\n \
    \           static constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007,\
    \ 998244353};\n            vector<u64> res;\n            for (const auto& p :\
    \ basic_prime) {\n                while (n % p == 0) {\n                    n\
    \ /= p;\n                    res.emplace_back(p);\n                }\n       \
    \     }\n\n            return res;\n        }\n        vector<u64> fact(u64 n){\n\
    \            if (n < 2) {\n                return {};\n            }\n       \
    \     if (is_prime(n)) {\n                return {n};\n            }\n\n     \
    \       vector<u64> v = naive(n);\n            if (n != 1) {\n               \
    \ vector<u64> res = rho_fact(n);\n                v.insert(v.end(), all(res));\n\
    \            }\n            sort(all(v));\n            return v;\n        }\n\
    \    };  // namespace pollard\n};  // namespace prime\nusing prime::pollard::fact;\n\
    \nint main(){\n    int t;\n    cin >> t;\n    while (t--) {\n        __uint64_t\
    \ x;\n        cin >> x;\n        auto pf = fact(x);\n        cout << pf.size()\
    \ << ' ';\n        for (const auto& p : pf) {\n            cout << p << ' ';\n\
    \        }\n        cout << '\\n';\n    }\n}\n"
  code: "#line 1 \"main.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n#include\"template.hpp\"\n#include\"math/fast_prime_check.hpp\"\nnamespace prime{\n\
    \    namespace pollard{\n        using i128 = __int128_t;\n        using u128\
    \ = __uint128_t;\n        using u64 = __uint64_t;\n        u64 c;\n        u64\
    \ xor_shift() { \n            static u64 v = 7001;\n            v ^= v << 13;\n\
    \            v ^= v >> 7;\n            v ^= v << 17;\n\n            return v;\n\
    \        }\n        i128 gcd(i128 x,i128 y){\n            while(y!=0){\n     \
    \           i128 ny = x % y;\n                i128 nx = y;\n                x\
    \ = nx, y = ny;\n            }\n            return x;\n        }\n        u64\
    \ find_factor(u64 n){\n            if (~n & 1ul) {\n                return 2;\n\
    \            }\n            if (is_prime(n)) {\n                return n;\n  \
    \          }\n            while(1){\n                auto f = [&](i128 x) -> u64\
    \ {\n                    x %= n;\n                    return (x * x % n + c) %\
    \ n;\n                };\n                c = xor_shift() % n;\n             \
    \   ll x = xor_shift() % n;\n                ll y = x;\n                ll d =\
    \ 1;\n                while (d == 1) {\n                    x = f(x);\n      \
    \              y = f(f(y));\n\n                    d = gcd(abs(x - y), n);\n \
    \               }\n                if (d != n) {\n                    return d;\n\
    \                }\n            }\n            exit(0);\n        }\n\n       \
    \ vector<u64> rho_fact(u64 n){\n            vector<u64> v;\n            while\
    \ (n != 1) {\n                u64 d = 0;\n                d = find_factor(n);\n\
    \                while (n % d == 0) {\n                    n /= d;\n         \
    \           v.emplace_back(d);\n                }\n            }\n           \
    \ return v;\n        }\n        vector<u64> naive(u64&n){\n            static\
    \ constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353};\n\
    \            vector<u64> res;\n            for (const auto& p : basic_prime) {\n\
    \                while (n % p == 0) {\n                    n /= p;\n         \
    \           res.emplace_back(p);\n                }\n            }\n\n       \
    \     return res;\n        }\n        vector<u64> fact(u64 n){\n            if\
    \ (n < 2) {\n                return {};\n            }\n            if (is_prime(n))\
    \ {\n                return {n};\n            }\n\n            vector<u64> v =\
    \ naive(n);\n            if (n != 1) {\n                vector<u64> res = rho_fact(n);\n\
    \                v.insert(v.end(), all(res));\n            }\n            sort(all(v));\n\
    \            return v;\n        }\n    };  // namespace pollard\n};  // namespace\
    \ prime\nusing prime::pollard::fact;\n\nint main(){\n    int t;\n    cin >> t;\n\
    \    while (t--) {\n        __uint64_t x;\n        cin >> x;\n        auto pf\
    \ = fact(x);\n        cout << pf.size() << ' ';\n        for (const auto& p :\
    \ pf) {\n            cout << p << ' ';\n        }\n        cout << '\\n';\n  \
    \  }\n}"
  dependsOn:
  - template.hpp
  - math/fast_prime_check.hpp
  - math/mod_pow.hpp
  - math/montgomery.hpp
  isVerificationFile: false
  path: sub.cpp
  requiredBy: []
  timestamp: '2023-03-05 17:21:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sub.cpp
layout: document
redirect_from:
- /library/sub.cpp
- /library/sub.cpp.html
title: sub.cpp
---
