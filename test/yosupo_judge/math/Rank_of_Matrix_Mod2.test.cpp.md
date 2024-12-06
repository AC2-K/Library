---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data-structure/bitvector.hpp
    title: bitvector
  - icon: ':heavy_check_mark:'
    path: src/internal/type_traits.hpp
    title: Type Traits
  - icon: ':heavy_check_mark:'
    path: src/math/gauss_jordan.hpp
    title: "Gauss Jordan\u306E\u6383\u304D\u51FA\u3057\u6CD5"
  - icon: ':heavy_check_mark:'
    path: src/math/mod_pow.hpp
    title: "Modulo Power(\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/stream.hpp
    title: "Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)"
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_rank_mod_2
    links:
    - https://judge.yosupo.jp/problem/matrix_rank_mod_2
  bundledCode: "#line 1 \"test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/matrix_rank_mod_2\"\n#line 2\
    \ \"src/math/gauss_jordan.hpp\"\n\n#include <bitset>\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"src/data-structure/bitvector.hpp\"\
    \n\n#line 4 \"src/data-structure/bitvector.hpp\"\n#include <cstdint>\n#include\
    \ <limits>\n#include <numeric>\n#line 8 \"src/data-structure/bitvector.hpp\"\n\
    \nnamespace std {\ntemplate <typename bits = __uint128_t> class bitvec {\n   \
    \ using usize = std::size_t;\n\n    const int dgt = std::numeric_limits<bits>::digits;\n\
    \n    usize size_;\n\n    std::vector<bits> arr;\n\npublic:\n    bitvec(usize\
    \ size_) : size_(size_), arr((size_ + dgt - 1) / dgt) {}\n\n    usize size() const\
    \ { return size_; }\n\n    void resize(usize size_) { this->size_ = size_; }\n\
    \n    bool at(usize p) const {\n        assert(0 <= p && p < size());\n      \
    \  return arr[p / dgt] >> (p % dgt) & 1;\n    }\n\n    bool operator[](usize p)\
    \ const { return at(p); }\n\n    void set(usize p, bool f) {\n        assert(0\
    \ <= p && p < size());\n\n        if (f) {\n            arr[p / dgt] |= (bits(1)\
    \ << (p % dgt));\n        } else {\n            arr[p / dgt] &= ~(bits(1) << (p\
    \ % dgt));\n        }\n    }\n\n    bitvec& operator^=(const bitvec<bits>& rhs)\
    \ {\n        assert((*this).size() == rhs.size());\n        assert((*this).arr.size()\
    \ == rhs.arr.size());\n        for (int i = 0; i < (int)(this->arr).size(); ++i)\
    \ {\n            this->arr[i] ^= rhs.arr[i];\n        }\n        return (*this);\n\
    \    }\n    bitvec& operator&=(const bitvec<bits>& rhs) {\n        assert((*this).size()\
    \ == rhs.size());\n        assert((*this).arr.size() == rhs.arr.size());\n   \
    \     for (int i = 0; i < (int)(this->arr).size(); ++i) {\n            this->arr[i]\
    \ &= rhs.arr[i];\n        }\n        return (*this);\n    }\n    bitvec& operator|=(const\
    \ bitvec<bits>& rhs) {\n        assert((*this).size() == rhs.size());\n      \
    \  assert((*this).arr.size() == rhs.arr.size());\n\n        for (int i = 0; i\
    \ < (int)(this->arr).size(); ++i) {\n            this->arr[i] |= rhs.arr[i];\n\
    \        }\n        return (*this);\n    }\n\n    void swap(bitvec<bits>& rhs)\
    \ {\n        std::swap(this->size_, rhs.size_);\n        std::swap(this->arr,\
    \ rhs.arr);\n    }\n};\n};  // namespace std\n\n/**\n * @brief bitvector\n */\n\
    #line 9 \"src/math/gauss_jordan.hpp\"\n\nnamespace kyopro {\n\n/// @return rank\
    \ of a\ntemplate <typename Container>\nint gauss_jordan(int n, int m, std::vector<Container>&\
    \ a) {\n    int rank = 0;\n\n    for (int j = 0; j < m && rank < n; ++j) {\n \
    \       int pivot = -1;\n\n        for (int i = rank; i < n; ++i) {\n        \
    \    if (a[i][j]) {\n                pivot = i;\n                break;\n    \
    \        }\n        }\n\n        if (pivot == -1) continue;\n\n        a[rank].swap(a[pivot]);\n\
    \n        for (int i = 0; i < n; ++i) {\n            if (i != rank) {\n      \
    \          if (a[i][j]) {\n                    a[i] ^= a[rank];\n            \
    \    }\n            }\n        }\n\n        ++rank;\n    }\n    return rank;\n\
    }\n};  // namespace kyopro\n\n/**\n * @brief Gauss Jordan\u306E\u6383\u304D\u51FA\
    \u3057\u6CD5\n */\n#line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n\
    #line 5 \"src/internal/type_traits.hpp\"\n#include <typeinfo>\n#line 7 \"src/internal/type_traits.hpp\"\
    \n\nnamespace kyopro {\nnamespace internal {\ntemplate <typename... Args> struct\
    \ first_enabled {};\n\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<true,\
    \ T>, Args...> {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\n\
    struct first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt, std::enable_if_t<dgt\
    \ <= 128>* = nullptr> struct int_least {\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t>>;\n};\n\
    \ntemplate <int dgt, std::enable_if_t<dgt <= 128>* = nullptr> struct uint_least\
    \ {\n    using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n\
    \                                 std::enable_if<dgt <= 16, std::uint16_t>,\n\
    \                                 std::enable_if<dgt <= 32, std::uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, std::uint64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __uint128_t>>;\n\
    };\n\ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\n\
    template <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate\
    \ <typename T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/**\n * @brief Type Traits\n\
    \ * @see https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\n#line 3\
    \ \"src/math/mod_pow.hpp\"\nnamespace kyopro {\n\ntemplate <typename T>\nconstexpr\
    \ T mod_pow(internal::double_size_uint_t<T> base, T exp, T mod) {\n    internal::double_size_uint_t<T>\
    \ ans = (mod == 1 ? 0 : 1);\n    base %= mod;\n    while (exp) {\n        if (exp\
    \ & 1) {\n            ans *= base;\n            ans %= mod;\n        }\n     \
    \   base *= base;\n        base %= mod;\n        exp >>= 1;\n    }\n    return\
    \ ans;\n}\n};  // namespace kyopro\n\n/**\n * @brief Modulo Power(\u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5)\n */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n\
    #include <stdio.h>\n#include <string>\n#line 6 \"src/stream.hpp\"\n\nnamespace\
    \ kyopro {\n\ninline void single_read(char& c) {\n    c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate <typename T, internal::is_integral_t<T>*\
    \ = nullptr>\ninline void single_read(T& a) {\n    a = 0;\n    bool is_negative\
    \ = false;\n    char c = getchar_unlocked();\n    while (isspace(c)) {\n     \
    \   c = getchar_unlocked();\n    }\n    if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    while (isdigit(c)) {\n        a = 10 * a + (c - '0');\n\
    \        c = getchar_unlocked();\n    }\n    if (is_negative) a *= -1;\n}\ntemplate\
    \ <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_read(T&\
    \ a) {\n    long long x;\n    single_read(x);\n    a = T(x);\n}\ninline void single_read(std::string&\
    \ str) noexcept {\n    char c = getchar_unlocked();\n    while (isspace(c)) c\
    \ = getchar_unlocked();\n    while (!isspace(c)) {\n        str += c;\n      \
    \  c = getchar_unlocked();\n    }\n}\ntemplate<typename T>\ninline void read(T&\
    \ x) noexcept {single_read(x);}\ntemplate <typename Head, typename... Tail>\n\
    inline void read(Head& head, Tail&... tail) noexcept {\n    single_read(head),\
    \ read(tail...);\n}\n\ninline void single_write(char c) noexcept { putchar_unlocked(c);\
    \ }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\ninline void\
    \ single_write(T a) noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n\
    \        return;\n    }\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ (a < 0) putchar_unlocked('-'), a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n\
    \    char s[d + 1];\n    int now = d + 1;\n    while (a) {\n        s[--now] =\
    \ (char)'0' + a % 10;\n        a /= 10;\n    }\n    while (now <= d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\ninline void single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\ninline void single_write(const\
    \ std::string& str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\ntemplate <typename T> inline void write(T x) noexcept { single_write(x);\
    \ }\ntemplate <typename Head, typename... Tail>\ninline void write(Head head,\
    \ Tail... tail) noexcept {\n    single_write(head);\n    putchar_unlocked(' ');\n\
    \    write(tail...);\n}\ntemplate <typename... Args> inline void put(Args... x)\
    \ noexcept {\n    write(x...);\n    putchar_unlocked('\\n');\n}\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Fast IO(\u9AD8\u901F\u5165\u51FA\u529B)\n */\n#line\
    \ 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define all(x) std::begin(x), std::end(x)\n#define popcount(x)\
    \ __builtin_popcountll(x)\nusing i128 = __int128_t;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing graph = std::vector<std::vector<int>>;\nusing P = std::pair<int,\
    \ int>;\nconstexpr int inf = std::numeric_limits<int>::max() / 2;\nconstexpr ll\
    \ infl = std::numeric_limits<ll>::max() / 2;\nconst long double pi = acosl(-1);\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};\nconstexpr int dy[] = {0,\
    \ 1, 0, -1, 1, 1, -1, -1, 0};\ntemplate <typename T1, typename T2> constexpr inline\
    \ bool chmax(T1& a, T2 b) {\n    return a < b && (a = b, true);\n}\ntemplate <typename\
    \ T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {\n    return a >\
    \ b && (a = b, true);\n}\n\n/**\n * @brief Template\n*/\n#line 6 \"test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ m;\n    read(n, m);\n\n    if (n < m) {\n        vector a(n, bitvec(m));\n \
    \       rep(i, n) rep(j, m) {\n            char x;\n            read(x);\n   \
    \         a[i].set(j, x - '0');\n        }\n        put(gauss_jordan(n, m, a));\n\
    \    } else {\n        vector a(m, bitvec(n));\n        rep(i, n) rep(j, m) {\n\
    \            char x;\n            read(x);\n            a[j].set(i, x - '0');\n\
    \        }\n        put(gauss_jordan(m, n, a));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_rank_mod_2\"\n#include\
    \ \"../../../src/math/gauss_jordan.hpp\"\n#include \"../../../src/math/mod_pow.hpp\"\
    \n#include \"../../../src/stream.hpp\"\n#include \"../../../src/template.hpp\"\
    \n\nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n,\
    \ m;\n    read(n, m);\n\n    if (n < m) {\n        vector a(n, bitvec(m));\n \
    \       rep(i, n) rep(j, m) {\n            char x;\n            read(x);\n   \
    \         a[i].set(j, x - '0');\n        }\n        put(gauss_jordan(n, m, a));\n\
    \    } else {\n        vector a(m, bitvec(n));\n        rep(i, n) rep(j, m) {\n\
    \            char x;\n            read(x);\n            a[j].set(i, x - '0');\n\
    \        }\n        put(gauss_jordan(m, n, a));\n    }\n}"
  dependsOn:
  - src/math/gauss_jordan.hpp
  - src/data-structure/bitvector.hpp
  - src/math/mod_pow.hpp
  - src/internal/type_traits.hpp
  - src/stream.hpp
  - src/template.hpp
  isVerificationFile: true
  path: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
  requiredBy: []
  timestamp: '2024-12-06 15:11:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
- /verify/test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp.html
title: test/yosupo_judge/math/Rank_of_Matrix_Mod2.test.cpp
---