---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Montgomery(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97(from Nyaan's\
      \ library))"
    links:
    - https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp
  bundledCode: "#line 2 \"math/montgomery.hpp\"\nclass montgomery64 {\n    using mint\
    \ = montgomery64;\n    using i64 = int64_t;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    static u64 mod;\n    static u64 r;\n    static u64\
    \ n2;\n\n    static u64 get_r() {\n        u64 ret = mod;\n        for (i64 i\
    \ = 0; i < 5; ++i) ret *= 2 - mod * ret;\n        return ret;\n    }\npublic:\n\
    \    static void set_mod(const u128& m) {\n        assert(m < (i128(1) << 64));\n\
    \        assert((m & 1) == 1);\n        mod = m;\n        n2 = -u128(m) % m;\n\
    \        r = get_r();\n        assert(r * mod == 1);\n    }\n\nprotected:\n  \
    \  u128 a;\n\npublic:\n    montgomery64() : a(0) {}\n    template<typename T>\n\
    \    montgomery64(const T& b) : a(reduce((u128(b) + mod)* n2)) {};\nprivate:\n\
    \    template<class T>\n    static u64 reduce(const T& b) {\n        return (b\
    \ + u128(u64(b) * u64(-r)) * mod) >> 64;\n    }\npublic:\n    template<class T>\n\
    \    mint& operator=(const T& rhs) {\n        return (*this) = mint(rhs);\n  \
    \  }\n\n    mint& operator+=(const mint& b) {\n        if (i64(a += b.a - 2 *\
    \ mod) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    mint& operator-=(const\
    \ mint& b) {\n        if (i64(a -= b.a) < 0) a += 2 * mod;\n        return *this;\n\
    \    }\n\n    mint& operator*=(const mint& b) {\n        a = reduce(u128(a) *\
    \ b.a);\n        return *this;\n    }\n\n    mint& operator/=(const mint& b) {\n\
    \        *this *= b.inv();\n        return *this;\n    }\n\n    mint operator+(const\
    \ mint& b) const { return mint(*this) += b; }\n    mint operator-(const mint&\
    \ b) const { return mint(*this) -= b; }\n    mint operator*(const mint& b) const\
    \ { return mint(*this) *= b; }\n    mint operator/(const mint& b) const { return\
    \ mint(*this) /= b; }\n    bool operator==(const mint& b) const {\n        return\
    \ (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n    }\n    bool\
    \ operator!=(const mint& b) const {\n        return (a >= mod ? a - mod : a) !=\
    \ (b.a >= mod ? b.a - mod : b.a);\n    }\n    mint operator-() const { return\
    \ mint() - mint(*this); }\n\n    mint pow(u128 n) const {\n        mint ret(1),\
    \ mul(*this);\n        while (n > 0) {\n            if (n & 1) ret *= mul;\n \
    \           mul *= mul;\n            n >>= 1;\n        }\n        return ret;\n\
    \    }\n\n    friend ostream& operator<<(ostream& os, const mint& b) {\n     \
    \   return os << b.val();\n    }\n\n    friend istream& operator>>(istream& is,\
    \ mint& b) {\n        int64_t t;\n        is >> t;\n        b = montgomery64(t);\n\
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
    /// @brief Montgomery(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97(from Nyaan's\
    \ library))\n///by https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp\n"
  code: "#pragma once\nclass montgomery64 {\n    using mint = montgomery64;\n    using\
    \ i64 = int64_t;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\n\
    \    static u64 mod;\n    static u64 r;\n    static u64 n2;\n\n    static u64\
    \ get_r() {\n        u64 ret = mod;\n        for (i64 i = 0; i < 5; ++i) ret *=\
    \ 2 - mod * ret;\n        return ret;\n    }\npublic:\n    static void set_mod(const\
    \ u128& m) {\n        assert(m < (i128(1) << 64));\n        assert((m & 1) ==\
    \ 1);\n        mod = m;\n        n2 = -u128(m) % m;\n        r = get_r();\n  \
    \      assert(r * mod == 1);\n    }\n\nprotected:\n    u128 a;\n\npublic:\n  \
    \  montgomery64() : a(0) {}\n    template<typename T>\n    montgomery64(const\
    \ T& b) : a(reduce((u128(b) + mod)* n2)) {};\nprivate:\n    template<class T>\n\
    \    static u64 reduce(const T& b) {\n        return (b + u128(u64(b) * u64(-r))\
    \ * mod) >> 64;\n    }\npublic:\n    template<class T>\n    mint& operator=(const\
    \ T& rhs) {\n        return (*this) = mint(rhs);\n    }\n\n    mint& operator+=(const\
    \ mint& b) {\n        if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;\n       \
    \ return *this;\n    }\n\n    mint& operator-=(const mint& b) {\n        if (i64(a\
    \ -= b.a) < 0) a += 2 * mod;\n        return *this;\n    }\n\n    mint& operator*=(const\
    \ mint& b) {\n        a = reduce(u128(a) * b.a);\n        return *this;\n    }\n\
    \n    mint& operator/=(const mint& b) {\n        *this *= b.inv();\n        return\
    \ *this;\n    }\n\n    mint operator+(const mint& b) const { return mint(*this)\
    \ += b; }\n    mint operator-(const mint& b) const { return mint(*this) -= b;\
    \ }\n    mint operator*(const mint& b) const { return mint(*this) *= b; }\n  \
    \  mint operator/(const mint& b) const { return mint(*this) /= b; }\n    bool\
    \ operator==(const mint& b) const {\n        return (a >= mod ? a - mod : a) ==\
    \ (b.a >= mod ? b.a - mod : b.a);\n    }\n    bool operator!=(const mint& b) const\
    \ {\n        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);\n\
    \    }\n    mint operator-() const { return mint() - mint(*this); }\n\n    mint\
    \ pow(u128 n) const {\n        mint ret(1), mul(*this);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, const mint& b) {\n        return os << b.val();\n    }\n\n    friend istream&\
    \ operator>>(istream& is, mint& b) {\n        int64_t t;\n        is >> t;\n \
    \       b = montgomery64(t);\n        return (is);\n    }\n\n    mint inv() const\
    \ { return pow(mod - 2); }\n\n    u64 val() const {\n        u64 ret = reduce(a);\n\
    \        return ret >= mod ? ret - mod : ret;\n    }\n\n    static u64 get_mod()\
    \ { return mod; }\n};\ntypename montgomery64::u64 montgomery64::mod, montgomery64::r,\
    \ montgomery64::n2;\n\nclass montgomery32 {\n    using mint = montgomery32;\n\
    \    using i32 = int32_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \    using u128 = __uint128_t;\n    static u32 mod;\n    static u32 r;\n    static\
    \ u32 n2;\n\n    static u32 get_r() {\n        u32 ret = mod;\n        for (i32\
    \ i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n        return ret;\n    }\npublic:\n\
    \    static void set_mod(u32 m) {\n        assert(m < (1ll << 31));\n        assert((m\
    \ & 1) == 1);\n        mod = m;\n        n2 = -u64(m) % m;\n        r = get_r();\n\
    \        assert(r * mod == 1);\n    }\nprotected:\n    u128 a;\npublic:\n    montgomery32()\
    \ : a(0) {}\n    montgomery32(const int64_t& b)\n        : a(reduce(u64(b% mod\
    \ + mod)* n2)) {};\n\n    static u32 reduce(const u64& b) {\n        return (b\
    \ + u64(u32(b) * u32(-r)) * mod) >> 32;\n    }\n\n    mint& operator+=(const mint&\
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
    /// @brief Montgomery(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97(from Nyaan's\
    \ library))\n///by https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp"
  dependsOn: []
  isVerificationFile: false
  path: math/montgomery.hpp
  requiredBy: []
  timestamp: '2023-03-05 17:53:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/montgomery.hpp
layout: document
redirect_from:
- /library/math/montgomery.hpp
- /library/math/montgomery.hpp.html
title: "Montgomery(\u30E2\u30F3\u30B4\u30E1\u30EA\u4E57\u7B97(from Nyaan's library))"
---
