---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/barrett.hpp
    title: barrett reduction
  - icon: ':heavy_check_mark:'
    path: math/dynamic_modint.hpp
    title: dynamic_modint(64bit)
  - icon: ':heavy_check_mark:'
    path: math/gcd.hpp
    title: "gcd(\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\
      \u3069)"
  - icon: ':heavy_check_mark:'
    path: math/montgomery.hpp
    title: MontgomeryReduction
  - icon: ':heavy_check_mark:'
    path: template.hpp
    title: template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\
    \n#line 2 \"template.hpp\"\n#include<bits/stdc++.h>\nusing namespace std;\n#define\
    \ rep(i, N)  for(int i=0;i<(N);i++)\n#define all(x) (x).begin(),(x).end()\n#define\
    \ popcount(x) __builtin_popcount(x)\nusing i128=__int128_t;\nusing ll = long long;\n\
    using ld = long double;\nusing graph = vector<vector<int>>;\nusing P = pair<int,\
    \ int>;\nconstexpr int inf = 1e9;\nconstexpr ll infl = 1e18;\nconstexpr ld eps\
    \ = 1e-6;\nconst long double pi = acos(-1);\nconstexpr uint64_t MOD = 1e9 + 7;\n\
    constexpr uint64_t MOD2 = 998244353;\nconstexpr int dx[] = { 1,0,-1,0 };\nconstexpr\
    \ int dy[] = { 0,1,0,-1 };\ntemplate<class T>static constexpr inline void chmax(T&x,T\
    \ y){if(x<y)x=y;}\ntemplate<class T>static constexpr inline void chmin(T&x,T y){if(x>y)x=y;}\n\
    #line 2 \"math/gcd.hpp\"\ntemplate<typename T>\nconstexpr inline T _gcd(T a, T\
    \ b) {\n    assert(a >= 0 && b >= 0);\n    if (a == 0 || b == 0) return a + b;\n\
    \    int d = min(__builtin_ctzll(a), __builtin_ctzll(b));\n    a >>= __builtin_ctzll(a),\
    \ b >>= __builtin_ctzll(b);\n    while (a != b) {\n        if (a == 0 || b ==\
    \ 0) {\n            return a + b;\n        }\n        if (a > b) {\n         \
    \   a -= b;\n            a >>= __builtin_ctzll(a);\n        }else{\n         \
    \   b -= a;\n            b >>= __builtin_ctzll(b);\n        }\n    }\n\n    return\
    \ a << d;\n}\ntemplate<typename T>\nconstexpr inline T ext_gcd(T a, T b, T &x,\
    \ T &y) {\n    x = 1, y = 0;\n    T nx = 0, ny = 1;\n    while(b) {\n        T\
    \ q = a / b;\n        tie(a, b) = make_pair(b, a % b);\n        tie(x, nx) = make_pair(nx,\
    \ x - nx*q);\n        tie(y, ny) = make_pair(ny, y - ny*q);\n    }\n    return\
    \ a;\n}\n/// @return ax + by = gcd(a,b)\u306A\u308Bx,y\u3092\u683C\u7D0D\u3059\
    \u308B,\u8FD4\u308A\u5024\u306Bgcd(a,b)\n\n/// @brief gcd(\u30E6\u30FC\u30AF\u30EA\
    \u30C3\u30C9\u306E\u4E92\u9664\u6CD5\u306A\u3069)\n#line 2 \"math/barrett.hpp\"\
    \nnamespace internal {\n\t///@brief barrett reduction\n\tclass barrett {\n\t\t\
    using u32 = uint32_t;\n\t\tusing u64 = uint64_t;\n\n\t\tu32 m;\n\t\tu64 im;\n\t\
    public:\n\t\texplicit barrett() = default;\n\t\texplicit barrett(const u32& m_)\
    \ :m(m_), im((u64)(-1) / m_ + 1) {}\n\n\t\tu32 get_mod() const { return m; }\n\
    \t\tu32 mul(u32 a, u32 b) {\n\t\t\tif (a == 0 || b == 0) {\n\t\t\t\treturn 0;\n\
    \t\t\t}\n\t\t\tu64 z = a;\n\t\t\tz *= b;\n#ifdef _MSC_VER\n\t\t\tu64 x;\n\n\t\t\
    \t_umul128(z, im, &x);\n#else\n\t\t\tu64 x = (u64)(((__uint128_t)(z)*im) >> 64);\n\
    #endif\n\n\t\t\tu32 v = (u32)(z - x * m);\n\n\t\t\tif (v >= m)v += m;\n\t\t\t\
    return v;\n\t\t}\n\t};\n}\n#line 2 \"math/montgomery.hpp\"\nnamespace internal\
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
    \ reduce(static_cast<LargeT>(x) * y);\n        }\n    };\n};\n#line 4 \"math/dynamic_modint.hpp\"\
    \nclass dynamic_modint32 {\n\tusing u32 = uint32_t;\n\tusing u64 = uint64_t;\n\
    \n\tusing i32 = int32_t;\n\tusing i64 = int64_t;\n\tusing br = internal::barrett;\n\
    \n\tstatic br brt;\n\tstatic u32 mod;\n\tu32 v;\t//value\npublic:\n\tstatic void\
    \ set_mod(const u32& mod_) {\n\t\tbrt = br(mod_);\n\t\tmod = mod_;\n\t}\nprivate:\n\
    \tu32 normalize(const i64& x) const {\n\t\ti32 m = x % mod;\n\t\tif (m < 0) {\n\
    \t\t\tm += mod;\n\t\t}\n\t\treturn m;\n\t}\npublic:\n\tdynamic_modint32() :v(0)\
    \ { assert(mod); }\t//mod\u304C\u6C7A\u5B9A\u6E08\u307F\u3067\u3042\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\n\tdynamic_modint32(const i64& v_) :v(normalize(v_))\
    \ { assert(mod); }\t\n\n\tu32 val() const { return v; }\n    static u32 get_mod()\
    \ { return mod; }\n    using mint = dynamic_modint32;\n\n\t//operators\n\tmint&\
    \ operator=(const i64& r) {\n\t\tv = normalize(r); \n\t\treturn (*this);\n\t}\n\
    \tmint& operator+=(const mint& r) {\n\t\tv += r.v;\n\t\tif (v >= mod) {\n\t\t\t\
    v -= mod;\n\t\t}\n\t\treturn (*this);\n\t}\n\tmint& operator-=(const mint&r) {\n\
    \t\tv += mod - r.v;\n\t\tif (v >= mod) {\n\t\t\tv -= mod;\n\t\t}\n\n\t\treturn\
    \ (*this);\n\t}\n\tmint& operator*=(const mint& r) {\n\t\tv = brt.mul(v, r.v);\n\
    \t\treturn (*this);\n\t}\n\n\tmint operator+(const mint& r) const { return mint(*this)\
    \ += r; }\n\tmint operator-(const mint& r) const { return mint(*this) -= r; }\n\
    \tmint operator*(const mint& r) const { return mint(*this) *= r; }\n\n\n\n\tmint&\
    \ operator+= (const i64& r) { return (*this) += mint(r); }\n\tmint& operator-=\
    \ (const i64& r) { return (*this) -= mint(r); }\n\tmint& operator*= (const i64&\
    \ r) { return (*this) *= mint(r); }\n\n\tfriend mint operator+(const i64& l, const\
    \ mint& r) { return mint(l) += r; }\n\tfriend mint operator+(const mint& l, const\
    \ i64& r) { return mint(l) += r; }\n\tfriend mint operator-(const i64& l, const\
    \ mint& r) { return mint(l) -= r; }\n\tfriend mint operator-(const mint& l, const\
    \ i64& r) { return mint(l) -= r; }\n\tfriend mint operator*(const i64& l, const\
    \ mint& r) { return mint(l) *= r; }\n\tfriend mint operator*(const mint& l, const\
    \ i64& r) { return mint(l) += r; }\n\n\n\tfriend ostream& operator<<(ostream&\
    \ os, const mint& mt) {\n\t\tos << mt.val();\n\t\treturn os;\n\t}\n\tfriend istream&\
    \ operator>>(istream& is, mint& mt) {\n\t\ti64 v_;\n\t\tis >> v_;\n\t\tmt = v_;\n\
    \t\treturn is;\n\t}\n\tmint pow(u64 e) const {\n\t\tmint res(1), base(*this);\n\
    \n\t\twhile (e) {\n\t\t\tif (e & 1) {\n\t\t\t\tres *= base;\n\t\t\t}\n\t\t\te\
    \ >>= 1;\n\t\t\tbase *= base;\n\t\t}\n\t\treturn res;\n\t}\n\tmint inv() const\
    \ {\n\t\treturn pow(mod - 2);\n\t}\n\n\tmint& operator/=(const mint& r) { return\
    \ (*this) *= r.inv(); }\n\tmint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n\tmint& operator/=(const i64& r) { return (*this) /= mint(r);\
    \ }\n\tfriend mint operator/(const mint& l, const i64& r) { return mint(l) /=\
    \ r; }\n\tfriend mint operator/(const i64& l, const mint& r) { return mint(l)\
    \ /= r; }\n};\ntypename dynamic_modint32::u32 dynamic_modint32::mod;\ntypename\
    \ dynamic_modint32::br dynamic_modint32::brt;\n\n\n/// @brief dynamic_modint(64bit)\n\
    /// @tparam T \u578B(64bit,32bit\u306A\u3069)\n/// @tparam LargeT \u7A4D\u304C\
    \u53CE\u307E\u3063\u3066\u304F\u308C\u308B\u578B\n/// @note T,LargeT\u306E\u3044\
    \u305A\u308C\u3082unsigned\u3067\u6E21\u3059\ntemplate <typename T = uint32_t,\
    \ typename LargeT = uint64_t>\n class dynamic_modint {\n        static T mod;\n\
    \        static internal::MontgomeryReduction64<T, LargeT> mr;\n\n      public:\n\
    \        static void set_mod(const T& mod_) {\n                mr.set_mod(mod_);\n\
    \                mod = mod_;\n        }\n\n        static T get_mod() { return\
    \ mod; }\n\n      private:\n        T v;\n      public:\n        dynamic_modint(const\
    \ T& v_ = 0) {\n                assert(mod);\n                v = mr.generate(v_);\n\
    \        }\n        T val() const { return mr.reduce(v); }\n\n        using mint\
    \ = dynamic_modint<T, LargeT>;\n        mint& operator+=(const mint& r) {\n  \
    \              v += r.v;\n                if (v >= mr.get_mod()) {\n         \
    \               v -= mr.get_mod();\n                }\n\n                return\
    \ (*this);\n        }\n\n        mint& operator-=(const mint& r) {\n         \
    \       v += mr.get_mod() - r.v;\n                if (v >= mr.get_mod) {\n   \
    \                     v -= mr.get_mod();\n                }\n\n              \
    \  return (*this);\n        }\n\n        mint& operator*=(const mint& r) {\n \
    \               v = mr.mult(v, r.v);\n                return (*this);\n      \
    \  }\n\n        mint operator+(const mint& r) { return mint(*this) += r; }\n \
    \       mint operator-(const mint& r) { return mint(*this) -= r; }\n        mint\
    \ operator*(const mint& r) { return mint(*this) *= r; }\n\n        mint& operator=(const\
    \ T& v_) {\n                (*this) = mint(v_);\n                return (*this);\n\
    \        }\n\n        friend ostream& operator<<(ostream& os, const mint& mt)\
    \ {\n                os << mt.val();\n                return os;\n        }\n\
    \        friend istream& operator>>(istream& is, mint& mt) {\n               \
    \ T v_;\n                is >> v_;\n                mt = v_;\n               \
    \ return is;\n        }\n        template <typename P> mint pow(P e) const {\n\
    \                assert(e >= 0);\n                mint res(1), base(*this);\n\n\
    \                while (e) {\n                        if (e & 1) {\n         \
    \                       res *= base;\n                        }\n            \
    \            e >>= 1;\n                        base *= base;\n               \
    \ }\n                return res;\n        }\n        mint inv() const { return\
    \ pow(mod - 2); }\n\n        mint& operator/=(const mint& r) { return (*this)\
    \ *= r.inv(); }\n        mint operator/(const mint& r) const { return mint(*this)\
    \ *= r.inv(); }\n        mint& operator/=(const T& r) { return (*this) /= mint(r);\
    \ }\n        friend mint operator/(const mint& l, const T& r) {\n            \
    \    return mint(l) /= r;\n        }\n        friend mint operator/(const T& l,\
    \ const mint& r) {\n                return mint(l) /= r;\n        }\n};\ntemplate<typename\
    \ T, typename LargeT>T dynamic_modint<T, LargeT>::mod;\ntemplate<typename T,typename\
    \ LargeT>internal::MontgomeryReduction64<T,LargeT> dynamic_modint<T,LargeT>::mr;\n\
    \n\n\n///@brief dynamic modint(\u52D5\u7684modint)\n///@docs docs/math/dynamic_modint.md\n\
    #line 6 \"test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp\"\ninline uint64_t\
    \ dlp(ll x, ll y, ll p) {\n    if (y == 1 || p == 1) {\n        return 0;\n  \
    \  }\n    if (x == 0) {\n        if (y == 0) {\n            return 1;\n      \
    \  }\n        else {\n            return -1;\n        }\n    }\n\n    using mint\
    \ = dynamic_modint32;\n    if (mint::get_mod() != p) {\n        mint::set_mod(p);\n\
    \    }\n    ll m = sqrt(p) + 1;\n    unordered_map<uint32_t, int> mp;\n    ll\
    \ xm = mint(x).pow(m).val();\n    ll add = 0, g, k = (p == 1 ? 0 : 1);\n    while\
    \ ((g = _gcd(x, p)) > 1) {\n        if (y == k)return add;\n        if (y % g)return\
    \ -1;\n        y /= g, p /= g, add++;\n        k = (k * (x / g)) % p;\n    }\n\
    \    mint pr = y;\n    for (int j = 0; j <= m; j++) {\n        mp[pr.val()] =\
    \ j;\n        pr *= x;\n    }\n    pr = k;\n    for (int i = 1; i <= m; i++) {\n\
    \        pr *= xm;\n        if (mp.find(pr.val()) != mp.end()) {\n           \
    \ int j = mp[pr.val()];\n            return m * i - j + add;\n        }\n    }\n\
    \    return -1;\n}\nint main() {\n    int t;\n    scanf(\"%d\", &t);\n    while\
    \ (t--) {\n        int x,y,p;\n        scanf(\"%d%d%d\", &x, &y, &p);\n      \
    \  printf(\"%lld\\n\", dlp(x, y, p));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include\"template.hpp\"\n#include\"math/gcd.hpp\"\n#include\"math/dynamic_modint.hpp\"\
    \ninline uint64_t dlp(ll x, ll y, ll p) {\n    if (y == 1 || p == 1) {\n     \
    \   return 0;\n    }\n    if (x == 0) {\n        if (y == 0) {\n            return\
    \ 1;\n        }\n        else {\n            return -1;\n        }\n    }\n\n\
    \    using mint = dynamic_modint32;\n    if (mint::get_mod() != p) {\n       \
    \ mint::set_mod(p);\n    }\n    ll m = sqrt(p) + 1;\n    unordered_map<uint32_t,\
    \ int> mp;\n    ll xm = mint(x).pow(m).val();\n    ll add = 0, g, k = (p == 1\
    \ ? 0 : 1);\n    while ((g = _gcd(x, p)) > 1) {\n        if (y == k)return add;\n\
    \        if (y % g)return -1;\n        y /= g, p /= g, add++;\n        k = (k\
    \ * (x / g)) % p;\n    }\n    mint pr = y;\n    for (int j = 0; j <= m; j++) {\n\
    \        mp[pr.val()] = j;\n        pr *= x;\n    }\n    pr = k;\n    for (int\
    \ i = 1; i <= m; i++) {\n        pr *= xm;\n        if (mp.find(pr.val()) != mp.end())\
    \ {\n            int j = mp[pr.val()];\n            return m * i - j + add;\n\
    \        }\n    }\n    return -1;\n}\nint main() {\n    int t;\n    scanf(\"%d\"\
    , &t);\n    while (t--) {\n        int x,y,p;\n        scanf(\"%d%d%d\", &x, &y,\
    \ &p);\n        printf(\"%lld\\n\", dlp(x, y, p));\n    }\n}\n"
  dependsOn:
  - template.hpp
  - math/gcd.hpp
  - math/dynamic_modint.hpp
  - math/barrett.hpp
  - math/montgomery.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  requiredBy: []
  timestamp: '2023-04-01 11:49:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
- /verify/test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp.html
title: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
---
