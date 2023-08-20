---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data-structure/segtree.hpp
    title: SegmentTree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
  - icon: ':question:'
    path: src/stream.hpp
    title: "\u5165\u51FA\u529B"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <iostream>\n#line 2 \"src/data-structure/segtree.hpp\"\n#include <cassert>\n\
    #include <vector>\nnamespace kyopro {\n\n/**\n * @brief SegmentTree\n */\ntemplate\
    \ <class S, auto op, auto e> class segtree {\n    int lg, sz, n;\n    std::vector<S>\
    \ dat;\n\npublic:\n    segtree() {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& vec) : n((int)vec.size()) {\n  \
    \      sz = 1, lg = 0;\n        while (sz <= n) {\n            sz <<= 1;\n   \
    \         lg++;\n        }\n\n        dat = std::vector<S>(sz << 1, e());\n\n\
    \        for (int i = 0; i < n; i++) {\n            set(i, vec[i]);\n        }\n\
    \        build();\n    }\n\n    void set(int p, const S& v) {\n        assert(0\
    \ <= p && p < sz);\n        dat[sz + p] = v;\n    }\n    void build() {\n    \
    \    for (int i = sz - 1; i > 0; i--) {\n            dat[i] = op(dat[i << 1 |\
    \ 0], dat[i << 1 | 1]);\n        }\n    }\n\n    S operator[](int p) const { return\
    \ dat[sz + p]; }\n\n    void update(int p, const S& v) {\n        assert(0 <=\
    \ p && p < sz);\n        p += sz;\n        dat[p] = v;\n        while (p >>= 1)\
    \ {\n            dat[p] = op(dat[(p << 1) | 0], dat[(p << 1) | 1]);\n        }\n\
    \    }\n\n    S fold(int l, int r) const {\n        assert(0 <= l && l <= r &&\
    \ r <= sz);\n        if (l == 0 && r == n) {\n            return dat[1];\n   \
    \     }\n        l += sz, r += sz;\n        S sml = e(), smr = e();\n        while\
    \ (l != r) {\n            if (l & 1) sml = op(sml, dat[l++]);\n            if\
    \ (r & 1) smr = op(dat[--r], smr);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n    void apply(int p, const S& v) {\n  \
    \      assert(0 <= p && p < sz);\n        update(p, op(dat[sz + p], v));\n   \
    \ }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/segtree.md\n\
    \ */\n#line 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include\
    \ <string>\n#line 3 \"src/internal/type_traits.hpp\"\n#include <limits>\n#include\
    \ <numeric>\n#include <typeinfo>\nnamespace kyopro {\nnamespace internal {\n/*\n\
    \ * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n */\ntemplate\
    \ <typename... Args> struct first_enabled {};\n\ntemplate <typename T, typename...\
    \ Args>\nstruct first_enabled<std::enable_if<true, T>, Args...> {\n    using type\
    \ = T;\n};\ntemplate <typename T, typename... Args>\nstruct first_enabled<std::enable_if<false,\
    \ T>, Args...>\n    : first_enabled<Args...> {};\ntemplate <typename T, typename...\
    \ Args> struct first_enabled<T, Args...> {\n    using type = T;\n};\n\ntemplate\
    \ <typename... Args>\nusing first_enabled_t = typename first_enabled<Args...>::type;\n\
    \ntemplate <int dgt> struct int_least {\n    static_assert(dgt <= 128);\n    using\
    \ type = first_enabled_t<std::enable_if<dgt <= 8, __int8_t>,\n               \
    \                  std::enable_if<dgt <= 16, __int16_t>,\n                   \
    \              std::enable_if<dgt <= 32, __int32_t>,\n                       \
    \          std::enable_if<dgt <= 64, __int64_t>,\n                           \
    \      std::enable_if<dgt <= 128, __int128_t> >;\n};\ntemplate <int dgt> struct\
    \ uint_least {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, __uint8_t>,\n                                 std::enable_if<dgt <= 16,\
    \ __uint16_t>,\n                                 std::enable_if<dgt <= 32, __uint32_t>,\n\
    \                                 std::enable_if<dgt <= 64, __uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n#line 6 \"src/stream.hpp\"\
    \n\nnamespace kyopro {\n// read\nvoid single_read(char& c) noexcept {\n    c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n}\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nconstexpr void single_read(T&\
    \ a) noexcept {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if constexpr\
    \ (std::is_signed<T>::value) {\n        if (c == '-') is_negative = true, c =\
    \ getchar_unlocked();\n    }\n    while (isdigit(c)) {\n        a = 10 * a + (c\
    \ - '0');\n        c = getchar_unlocked();\n    }\n    if constexpr (std::is_signed<T>::value)\
    \ {\n        if (is_negative) a *= -1;\n    }\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) noexcept {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) noexcept {\n    char c =\
    \ getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n    while\
    \ (!isspace(c)) {\n        str += c;\n        c = getchar_unlocked();\n    }\n\
    }\ntemplate <typename T> constexpr inline void read(T& x) noexcept {\n    single_read(x);\n\
    }\ntemplate <typename Head, typename... Tail>\nconstexpr inline void read(Head&\
    \ head, Tail&... tail) noexcept {\n    single_read(head), read(tail...);\n}\n\n\
    // write\nvoid single_write(char c) noexcept { putchar_unlocked(c); }\ntemplate\
    \ <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a)\
    \ noexcept {\n    if (!a) {\n        putchar_unlocked('0');\n        return;\n\
    \    }\n    if constexpr (std::is_signed<T>::value) {\n        if (a < 0) putchar_unlocked('-'),\
    \ a *= -1;\n    }\n    constexpr int d = std::numeric_limits<T>::digits10;\n \
    \   char s[d];\n    int now = d;\n    while (a) {\n        s[--now] = static_cast<char>('0'\
    \ + a % 10);\n        a /= 10;\n    }\n    while (now < d) putchar_unlocked(s[now++]);\n\
    }\ntemplate <typename T, internal::is_modint_t<T>* = nullptr>\nvoid single_write(T\
    \ a) noexcept {\n    single_write(a.val());\n}\n\nvoid single_write(const std::string&\
    \ str) noexcept {\n    for (auto c : str) {\n        putchar_unlocked(c);\n  \
    \  }\n}\n\ntemplate <typename T> constexpr inline void write(T x) noexcept {\n\
    \    single_write(x);\n}\ntemplate <typename Head, typename... Tail>\nconstexpr\
    \ inline void write(Head head, Tail... tail) noexcept {\n    single_write(head);\n\
    \    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate <typename... Args>\
    \ constexpr inline void put(Args... x) noexcept {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief \u5165\u51FA\u529B\n */\n#line\
    \ 5 \"test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp\"\n\
    \nusing namespace std;\nusing namespace kyopro;\n\nconstexpr inline long long\
    \ op(long long x, long long y) { return x + y; }\nconstexpr inline long long e()\
    \ { return 0; }\nint main() {\n    int n, q;\n    read(n, q);\n    vector<long\
    \ long> a(n);\n    for (int i = 0; i < n; ++i) read(a[i]);\n\n    segtree<long\
    \ long, op, e> seg(a);\n    while (q--) {\n        int t;\n        scanf(\"%d\"\
    , &t);\n        if (!t) {\n            int p, x;\n            read(p, x);\n  \
    \          seg.apply(p, x);\n        } else {\n            int l, r;\n       \
    \     read(l, r);\n            put(seg.fold(l, r));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <iostream>\n#include \"../../../src/data-structure/segtree.hpp\"\n#include\
    \ \"../../../src/stream.hpp\"\n\nusing namespace std;\nusing namespace kyopro;\n\
    \nconstexpr inline long long op(long long x, long long y) { return x + y; }\n\
    constexpr inline long long e() { return 0; }\nint main() {\n    int n, q;\n  \
    \  read(n, q);\n    vector<long long> a(n);\n    for (int i = 0; i < n; ++i) read(a[i]);\n\
    \n    segtree<long long, op, e> seg(a);\n    while (q--) {\n        int t;\n \
    \       scanf(\"%d\", &t);\n        if (!t) {\n            int p, x;\n       \
    \     read(p, x);\n            seg.apply(p, x);\n        } else {\n          \
    \  int l, r;\n            read(l, r);\n            put(seg.fold(l, r));\n    \
    \    }\n    }\n}"
  dependsOn:
  - src/data-structure/segtree.hpp
  - src/stream.hpp
  - src/internal/type_traits.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
  requiredBy: []
  timestamp: '2023-08-20 07:26:53+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
- /verify/test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp.html
title: test/yosupo_judge/data_structure/Point_Add_Range_Sum_Segtree.test.cpp
---
