---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/dynamic_modint.hpp
    title: dynamic_modint(64bit)
  - icon: ':heavy_check_mark:'
    path: math/miller.hpp
    title: "MillerRabin\u306E\u7D20\u6570\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: math/phi_function.hpp
    title: "phi function(\\phi \u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: math/primitive_root.hpp
    title: "primitive root(\u539F\u59CB\u6839)"
  - icon: ':heavy_check_mark:'
    path: math/rho.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Pollard Rho\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL/1_D.test.cpp
    title: test/AOJ/NTL/1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
    title: test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/math/Factorize.test.cpp
    title: test/yosupo_judge/math/Factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/new/Primitive_Root.test.cpp
    title: test/yosupo_judge/new/Primitive_Root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yuki/No-3030.test.cpp
    title: test/yuki/No-3030.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: MontgomeryReduction
    links: []
  bundledCode: "#line 2 \"math/montgomery.hpp\"\nnamespace internal {\n    using u32\
    \ = uint32_t;\n    using u64 = uint64_t;\n    using i32 = int32_t;\n    using\
    \ i64 = int64_t;\n    using u128 = __uint128_t;\n    using i128 = __int128_t;\n\
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
    \ reduce(static_cast<LargeT>(x) * y);\n        }\n    };\n};\n"
  code: "#pragma once\nnamespace internal {\n    using u32 = uint32_t;\n    using\
    \ u64 = uint64_t;\n    using i32 = int32_t;\n    using i64 = int64_t;\n    using\
    \ u128 = __uint128_t;\n    using i128 = __int128_t;\n    /// @brief MontgomeryReduction\n\
    \    template<typename T,typename LargeT>\n    class MontgomeryReduction64 {\n\
    \        static constexpr int lg = numeric_limits<T>::digits;\n        T mod,\
    \ r, r2, minv;\n        T calc_inv() {\n            T t = 0, res = 0;\n      \
    \      for (int i = 0; i < lg; i++) {\n                if (~t & 1) {\n       \
    \             t += mod;\n                    res += static_cast<T>(1) << i;\n\
    \                }\n                t >>= 1;\n            }\n            return\
    \ res;\n        }\n\n\n    public:\n        MontgomeryReduction64() = default;\n\
    \        constexpr T get_mod() { return mod; }\n        constexpr int get_lg()\
    \ { return lg; }\n\n\n        void set_mod(const T& m) {\n            assert(m\
    \ > 0);\n            assert(m & 1);\n\n            mod = m;\n\n            r =\
    \ (-static_cast<T>(mod)) % mod;\n            r2 = (-static_cast<LargeT>(mod))\
    \ % mod;\n            minv = calc_inv();\n        }\n\n\n        T reduce(LargeT\
    \ x) const {\n            u64 res = (x + static_cast<LargeT>(static_cast<T>(x)\
    \ * minv) * mod) >> lg;\n\n            if (res >= mod)res -= mod;\n          \
    \  return res;\n        }\n\n        T generate(LargeT x) {\n            return\
    \ reduce(x * r2);\n        }\n\n        T mult(T x, T y) {\n            return\
    \ reduce(static_cast<LargeT>(x) * y);\n        }\n    };\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/montgomery.hpp
  requiredBy:
  - math/rho.hpp
  - math/dynamic_modint.hpp
  - math/primitive_root.hpp
  - math/phi_function.hpp
  - math/miller.hpp
  timestamp: '2023-03-31 22:26:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL/1_D.test.cpp
  - test/yuki/No-3030.test.cpp
  - test/yosupo_judge/math/Discrete_Logarithm_32bit.test.cpp
  - test/yosupo_judge/math/Factorize.test.cpp
  - test/yosupo_judge/new/Primitive_Root.test.cpp
documentation_of: math/montgomery.hpp
layout: document
redirect_from:
- /library/math/montgomery.hpp
- /library/math/montgomery.hpp.html
title: MontgomeryReduction
---
