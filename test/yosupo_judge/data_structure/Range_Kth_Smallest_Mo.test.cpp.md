---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: Mo's algorithm
  - icon: ':question:'
    path: src/data-structure/BIT.hpp
    title: Binary Index Tree
  - icon: ':question:'
    path: src/internal/type_traits.hpp
    title: src/internal/type_traits.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 2 \"src/stream.hpp\"\n#include <ctype.h>\n#include <stdio.h>\n#include <string>\n\
    #line 2 \"src/internal/type_traits.hpp\"\n#include <iostream>\n#include <limits>\n\
    #include <numeric>\n#include <typeinfo>\n\nnamespace kyopro {\nnamespace internal\
    \ {\ntemplate <typename... Args> struct first_enabled {};\n\ntemplate <typename\
    \ T, typename... Args>\nstruct first_enabled<std::enable_if<true, T>, Args...>\
    \ {\n    using type = T;\n};\ntemplate <typename T, typename... Args>\nstruct\
    \ first_enabled<std::enable_if<false, T>, Args...>\n    : first_enabled<Args...>\
    \ {};\ntemplate <typename T, typename... Args> struct first_enabled<T, Args...>\
    \ {\n    using type = T;\n};\n\ntemplate <typename... Args>\nusing first_enabled_t\
    \ = typename first_enabled<Args...>::type;\n\ntemplate <int dgt> struct int_least\
    \ {\n    static_assert(dgt <= 128);\n    using type = first_enabled_t<std::enable_if<dgt\
    \ <= 8, std::int8_t>,\n                                 std::enable_if<dgt <=\
    \ 16, std::int16_t>,\n                                 std::enable_if<dgt <= 32,\
    \ std::int32_t>,\n                                 std::enable_if<dgt <= 64, std::int64_t>,\n\
    \                                 std::enable_if<dgt <= 128, __int128_t> >;\n\
    };\ntemplate <int dgt> struct uint_least {\n    static_assert(dgt <= 128);\n \
    \   using type = first_enabled_t<std::enable_if<dgt <= 8, std::uint8_t>,\n   \
    \                              std::enable_if<dgt <= 16, std::uint16_t>,\n   \
    \                              std::enable_if<dgt <= 32, std::uint32_t>,\n   \
    \                              std::enable_if<dgt <= 64, std::uint64_t>,\n   \
    \                              std::enable_if<dgt <= 128, __uint128_t> >;\n};\n\
    \ntemplate <int dgt> using int_least_t = typename int_least<dgt>::type;\ntemplate\
    \ <int dgt> using uint_least_t = typename uint_least<dgt>::type;\n\ntemplate <typename\
    \ T>\nusing double_size_uint_t = uint_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \ntemplate <typename T>\nusing double_size_int_t = int_least_t<2 * std::numeric_limits<T>::digits>;\n\
    \nstruct modint_base {};\ntemplate <typename T> using is_modint = std::is_base_of<modint_base,\
    \ T>;\ntemplate <typename T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n\n// is_integral\ntemplate <typename T>\nusing is_integral_t =\n    std::enable_if_t<std::is_integral_v<T>\
    \ || std::is_same_v<T, __int128_t> ||\n                   std::is_same_v<T, __uint128_t>>;\n\
    };  // namespace internal\n};  // namespace kyopro\n\n/*\n * @ref https://qiita.com/kazatsuyu/items/f8c3b304e7f8b35263d8\n\
    \ */\n#line 6 \"src/stream.hpp\"\n\nnamespace kyopro {\n// read\nvoid single_read(char&\
    \ c) {\n    c = getchar_unlocked();\n    while (isspace(c)) c = getchar_unlocked();\n\
    }\ntemplate <typename T, internal::is_integral_t<T>* = nullptr>\nvoid single_read(T&\
    \ a) {\n    a = 0;\n    bool is_negative = false;\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) {\n        c = getchar_unlocked();\n    }\n    if (c ==\
    \ '-') is_negative = true, c = getchar_unlocked();\n    while (isdigit(c)) {\n\
    \        a = 10 * a + (c - '0');\n        c = getchar_unlocked();\n    }\n   \
    \ if (is_negative) a *= -1;\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_read(T& a) {\n    long long x;\n    single_read(x);\n\
    \    a = T(x);\n}\nvoid single_read(std::string& str) {\n    char c = getchar_unlocked();\n\
    \    while (isspace(c)) c = getchar_unlocked();\n    while (!isspace(c)) {\n \
    \       str += c;\n        c = getchar_unlocked();\n    }\n}\ntemplate<typename\
    \ T>\nvoid read(T& x) {single_read(x);}\ntemplate <typename Head, typename...\
    \ Tail>\nvoid read(Head& head, Tail&... tail) {\n    single_read(head), read(tail...);\n\
    }\n\n// write\nvoid single_write(char c) { putchar_unlocked(c); }\ntemplate <typename\
    \ T, internal::is_integral_t<T>* = nullptr>\nvoid single_write(T a) {\n    if\
    \ (!a) {\n        putchar_unlocked('0');\n        return;\n    }\n    if (a <\
    \ 0) putchar_unlocked('-'), a *= -1;\n    char s[37];\n    int now = 37;\n   \
    \ while (a) {\n        s[--now] = (char)'0' + a % 10;\n        a /= 10;\n    }\n\
    \    while (now < 37) putchar_unlocked(s[now++]);\n}\ntemplate <typename T, internal::is_modint_t<T>*\
    \ = nullptr>\nvoid single_write(T a) {\n    single_write(a.val());\n}\n\nvoid\
    \ single_write(const std::string& str) {\n    for (auto c : str) {\n        putchar_unlocked(c);\n\
    \    }\n}\n\ntemplate<typename T>\nvoid write(T x) { single_write(x); }\ntemplate\
    \ <typename Head, typename... Tail> void write(Head head, Tail... tail) {\n  \
    \  single_write(head);\n    putchar_unlocked(' ');\n    write(tail...);\n}\ntemplate\
    \ <typename... Args> void put(Args... x) {\n    write(x...);\n    putchar_unlocked('\\\
    n');\n}\n};  // namespace kyopro\n\n/**\n * @brief fastIO\n */\n#line 2 \"src/algorithm/mo.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/algorithm/mo.hpp\"\n#include <utility>\n\
    #include <vector>\nnamespace kyopro {\n/**\n * @brief Mo's algorithm\n */\nclass\
    \ Mo {\n    int n;\n    std::vector<std::pair<int, int>> lr;\n    const int logn;\n\
    \    const long long maxn;\n    std::vector<int> ord;\n\npublic:\n    explicit\
    \ Mo(int n) : n(n), logn(20), maxn(1ll << logn) { lr.reserve(n); }\n    void add(int\
    \ l, int r) { lr.emplace_back(l, r); }\n\nprivate:\n    long long hilbertorder(int\
    \ x, int y) {\n        long long d = 0;\n        for (int s = 1 << (logn - 1);\
    \ s; s >>= 1) {\n            bool rx = x & s, ry = y & s;\n            d = d <<\
    \ 2 | rx * 3 ^ static_cast<int>(ry);\n            if (!ry) {\n               \
    \ if (rx) {\n                    x = maxn - x;\n                    y = maxn -\
    \ y;\n                }\n                std::swap(x, y);\n            }\n   \
    \     }\n        return d;\n    }\n    void line_up() {\n        int q = lr.size();\n\
    \        ord.resize(q);\n        std::iota(std::begin(ord), std::end(ord), 0);\n\
    \        std::vector<long long> tmp(q);\n        for (int i = 0; i < q; i++) {\n\
    \            tmp[i] = hilbertorder(lr[i].first, lr[i].second);\n        }\n  \
    \      std::sort(std::begin(ord), std::end(ord),\n                  [&](int a,\
    \ int b) { return tmp[a] < tmp[b]; });\n    }\n\npublic:\n    template <typename\
    \ AL, typename AR, typename EL, typename ER, typename O>\n    void build(const\
    \ AL& add_left,\n               const AR& add_right,\n               const EL&\
    \ erase_left,\n               const ER& erase_right,\n               const O&\
    \ out) {\n        line_up();\n        int l = 0, r = 0;\n        for (auto idx\
    \ : ord) {\n            while (l > lr[idx].first) add_left(--l);\n           \
    \ while (r < lr[idx].second) add_right(r++);\n            while (l < lr[idx].first)\
    \ erase_left(l++);\n            while (r > lr[idx].second) erase_right(--r);\n\
    \            out(idx);\n        }\n    }\n\n    template <typename A, typename\
    \ E, typename O>\n    void build(const A& add, const E& erase, const O& out) {\n\
    \        build(add, add, erase, erase, out);\n    }\n};\n};  // namespace kyopro\n\
    \n/**\n * @docs docs/other/mo.md\n * @ref https://ei1333.hateblo.jp/entry/2017/09/11/211011\n\
    \ */\n#line 3 \"src/data-structure/BIT.hpp\"\nnamespace kyopro {\n/**\n * @brief\
    \ Binary Index Tree\n */\ntemplate <typename T> class BIT {\n    std::vector<T>\
    \ bit;\n    int n;\n\npublic:\n    explicit BIT() {}\n    explicit BIT(int n)\
    \ : n(n), bit(n + 1, T()) {}\n    void add(int p, T w) {\n        p++;\n     \
    \   for (int x = p; x <= n; x += x & -x) {\n            bit[x] += w;\n       \
    \ }\n    }\n\n    T sum(int p) const {\n        T s = 0;\n\n        for (int x\
    \ = p; x > 0; x -= x & -x) {\n            s += bit[x];\n        }\n        return\
    \ s;\n    }\n\n    T sum(int l, int r) const { return sum(r) - sum(l); }\n\n \
    \   int lower_bound(T w) const {\n        if (w <= 0) return 0;\n\n        int\
    \ x = 0;\n        int k = 1;\n        while (k < n) k <<= 1;\n        for (; k\
    \ > 0; k >>= 1) {\n            if (x + k <= n && bit[x + k] < w) {\n         \
    \       w -= bit[x + k];\n                x += k;\n            }\n        }\n\n\
    \        return x + 1;\n    }\n\n    T operator[](int i) { return sum(i + 1) -\
    \ sum(i); }\n    void update(int i, T v) { add(i, T::mod() - sum(i + 1) + sum(i)\
    \ + v); }\n};\n};  // namespace kyopro\n\n/**\n * @docs docs/data-structure/BIT.md\n\
    \ */\n#line 7 \"test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp\"\
    \nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n    Mo mo(q);\n    vector<int> a(n);\n    for (auto& aa : a)\
    \ \n        read(aa);\n    \n    vector<int> k(q);\n    for (int i = 0; i < q;\
    \ i++) {\n        int l, r;\n        read(l, r, k[i]);\n        k[i]++;\n    \
    \    mo.add(l, r);\n    }\n    vector<int> pressed = a;\n    auto tmp = a;\n \
    \   {\n        std::sort(tmp.begin(), tmp.end());\n        tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n        for (auto& ai : pressed) {\n            ai\
    \ = lower_bound(tmp.begin(), tmp.end(), ai) - tmp.begin();\n        }\n    }\n\
    \n    int sz = tmp.size();\n    BIT<int> st(sz);\n    auto add = [&](int x) ->\
    \ void { st.add(pressed[x], 1); };\n    auto del = [&](int x) -> void { st.add(pressed[x],\
    \ -1); };\n    vector<int> ans(q);\n    auto out = [&](int x) -> void {\n    \
    \    int ok = st.lower_bound(k[x]);\n        ans[x] = tmp[ok - 1];\n    };\n\n\
    \    mo.build(add, del, out);\n    for (auto r : ans) put(r);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../src/stream.hpp\"\n#include \"../../../src/algorithm/mo.hpp\"\
    \n#include \"../../../src/data-structure/BIT.hpp\"\n#include\"../../../src/stream.hpp\"\
    \nusing namespace std;\nusing namespace kyopro;\n\nint main() {\n    int n, q;\n\
    \    read(n, q);\n    Mo mo(q);\n    vector<int> a(n);\n    for (auto& aa : a)\
    \ \n        read(aa);\n    \n    vector<int> k(q);\n    for (int i = 0; i < q;\
    \ i++) {\n        int l, r;\n        read(l, r, k[i]);\n        k[i]++;\n    \
    \    mo.add(l, r);\n    }\n    vector<int> pressed = a;\n    auto tmp = a;\n \
    \   {\n        std::sort(tmp.begin(), tmp.end());\n        tmp.erase(std::unique(tmp.begin(),\
    \ tmp.end()), tmp.end());\n        for (auto& ai : pressed) {\n            ai\
    \ = lower_bound(tmp.begin(), tmp.end(), ai) - tmp.begin();\n        }\n    }\n\
    \n    int sz = tmp.size();\n    BIT<int> st(sz);\n    auto add = [&](int x) ->\
    \ void { st.add(pressed[x], 1); };\n    auto del = [&](int x) -> void { st.add(pressed[x],\
    \ -1); };\n    vector<int> ans(q);\n    auto out = [&](int x) -> void {\n    \
    \    int ok = st.lower_bound(k[x]);\n        ans[x] = tmp[ok - 1];\n    };\n\n\
    \    mo.build(add, del, out);\n    for (auto r : ans) put(r);\n}\n"
  dependsOn:
  - src/stream.hpp
  - src/internal/type_traits.hpp
  - src/algorithm/mo.hpp
  - src/data-structure/BIT.hpp
  isVerificationFile: true
  path: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
  requiredBy: []
  timestamp: '2023-09-27 10:48:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
- /verify/test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp.html
title: test/yosupo_judge/data_structure/Range_Kth_Smallest_Mo.test.cpp
---
