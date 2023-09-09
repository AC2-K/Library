---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <vector>\n#include \"../../atcoder/convolution.hpp\"\
    \nnamespace kyopro{\n\n\n/**\n * @brief \u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570\
    \n * @note mint\u306FACL\u306E\u65B9\u3067\u6E21\u3059\u3053\u3068\n*/\ntemplate\
    \ <typename mint, atcoder::internal::is_modint_t<mint>* = nullptr>\nstruct FormalPowerSeries\
    \ : public std::vector<mint> {\n    using std::vector<mint>::vector;\n    using\
    \ FPS = FormalPowerSeries<mint>;\n\n    void expand(size_t sz) {\n        if (this->size()\
    \ < sz) this->resize(sz);\n    }\n    \n    void shrink() {\n        while (!(*this).empty()\
    \ && (*this).back() == mint()) (*this).pop_back();\n    }\n    \n    FPS& operator+=(const\
    \ FPS& rhs) {\n        expand(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) (*this)[i] += rhs[i];\n        return (*this);\n    }\n    \n    FPS& operator-=(const\
    \ FPS& rhs) {\n        expand(rhs.size());\n        for (int i = 0; i < (int)rhs.size();\
    \ ++i) (*this)[i] -= rhs[i];\n        return (*this);\n    }\n    FPS& operator*=(const\
    \ FPS& rhs) {\n        shrink();\n        std::vector res = atcoder::convolution<mint>(*this,\
    \ rhs);\n        (*this) = {res.begin(), res.end()};\n        return (*this);\n\
    \    }\n\n    FPS& operator+=(const mint& rhs) {\n        expand(1);\n       \
    \ (*this)[0] += rhs;\n        return (*this);\n    }\n    FPS& operator-=(const\
    \ mint& rhs) {\n        expand(1);\n        (*this)[0] -= rhs;\n        return\
    \ (*this);\n    }\n    FPS& operator*=(const mint& rhs) {\n        for (int i\
    \ = 0; i < (int)this->size(); ++i) {\n            (*this)[i] *= rhs;\n       \
    \ }\n    }\n    FPS& operator/=(const mint& rhs) {\n        for (int i = 0; i\
    \ < (int)this->size(); ++i) {\n            (*this)[i] /= rhs;\n        }\n   \
    \ }\n\n    FPS operator+(const FPS& rhs) const { return FPS(*this) += rhs; }\n\
    \    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs; }\n    FPS\
    \ operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }\n    FPS operator+(const\
    \ mint& rhs) const { return FPS(*this) += rhs; }\n    FPS operator-(const mint&\
    \ rhs) const { return FPS(*this) -= rhs; }\n    FPS operator*(const mint& rhs)\
    \ const { return FPS(*this) *= rhs; }\n    FPS operator/(const mint& rhs) const\
    \ { return FPS(*this) /= rhs; }\n\n    friend FPS operator*(const mint& lhs, const\
    \ FPS& rhs) {\n        return FPS(rhs) *= lhs;\n    }\n};\n\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/FormalPowerSeries/FPS.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/FormalPowerSeries/FPS.hpp
layout: document
redirect_from:
- /library/src/FormalPowerSeries/FPS.hpp
- /library/src/FormalPowerSeries/FPS.hpp.html
title: "\u5F62\u5F0F\u7684\u3079\u304D\u7D1A\u6570"
---
