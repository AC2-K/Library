---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: atcoder/internal_type_traits.hpp
    title: atcoder/internal_type_traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
  bundledCode: "#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5 \"atcoder/internal_type_traits.hpp\"\
    \n#include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n"
  code: "#ifndef ATCODER_FENWICKTREE_HPP\n#define ATCODER_FENWICKTREE_HPP 1\n\n#include\
    \ <cassert>\n#include <vector>\n\n#include \"atcoder/internal_type_traits\"\n\n\
    namespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n#endif  // ATCODER_FENWICKTREE_HPP\n"
  dependsOn:
  - atcoder/internal_type_traits.hpp
  isVerificationFile: false
  path: atcoder/fenwicktree.hpp
  requiredBy: []
  timestamp: '2023-07-02 15:52:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: atcoder/fenwicktree.hpp
layout: document
redirect_from:
- /library/atcoder/fenwicktree.hpp
- /library/atcoder/fenwicktree.hpp.html
title: atcoder/fenwicktree.hpp
---
