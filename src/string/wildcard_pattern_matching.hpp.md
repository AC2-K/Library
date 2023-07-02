---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: WildCard Pattern Matching
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: random/xor_shift.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../../atcoder/convolution\"\n#include \"../../atcoder/modint\"\
    \n#include <string>\n#include <vector>\n#include \"random/xor_shift.hpp\"\n\n\
    namespace kyopro {\nstd::vector<bool> wildcard_pattern_matching(const std::string&\
    \ s,\n                                            const std::string& t,\n    \
    \                                        char wild_card) {\n    assert(s.size()\
    \ >= t.size());\n    using mint = atcoder::modint998244353;\n    /**\n     * \u5404\
    \u6587\u5B57\u306B\u30CF\u30C3\u30B7\u30E5\u3092\u5272\u308A\u5F53\u3066\u308B\
    (\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9\u306B\u306E\u307F0\u3092\u5272\u308A\
    \u5F53\u3066\u308B\n     */\n    \n    static xor_shift32 rng;\n    static int\
    \ d = rng();\n    \n    auto to_integer = [&](char v) -> mint {\n        return\
    \ (v == wild_card ? mint() : mint(v + d));\n    };\n\n    std::vector<mint> sv(s.size()),\
    \ tv(t.size());\n    for (int i = 0; i < (int)s.size(); ++i) sv[i] = to_integer(s[i]);\n\
    \    for (int i = 0; i < (int)t.size(); ++i) tv[i] = to_integer(t[i]);\n\n   \
    \ std::reverse(tv.begin(), tv.end());\n\n    std::vector<mint> conv1;\n    {\n\
    \        std::vector<mint> s3 = sv;\n        for (auto& s3i : s3) s3i = s3i *\
    \ s3i * s3i;\n        conv1 = atcoder::convolution(s3, tv);\n    }\n    std::vector<mint>\
    \ conv2;\n    {\n        std::vector<mint> t3 = tv;\n        for (auto& t3i :\
    \ t3) t3i = t3i * t3i * t3i;\n        conv2 = atcoder::convolution(sv, t3);\n\
    \    }\n\n    std::vector<mint> conv3;\n    {\n        std::vector<mint> s2 =\
    \ sv, t2 = tv;\n        for (auto& s2i : s2) s2i *= s2i;\n        for (auto& t2i\
    \ : t2) t2i *= t2i;\n\n        conv3 = atcoder::convolution(s2, t2);\n    }\n\
    \    std::vector<bool> ans(s.size() - t.size() + 1);\n    for (int i = 0; i <\
    \ (int)ans.size(); ++i) {\n        ans[i] = (conv1[i + t.size() - 1] + conv2[i\
    \ + t.size() - 1] -\n                      2 * conv3[i + t.size() - 1] ==\n  \
    \                mint(0));\n    }\n    return ans;\n}\n\n};  // namespace kyopro\n\
    \n/**\n * @brief WildCard Pattern Matching\n */"
  dependsOn: []
  isVerificationFile: false
  path: src/string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/wildcard_pattern_matching.hpp
layout: document
redirect_from:
- /library/src/string/wildcard_pattern_matching.hpp
- /library/src/string/wildcard_pattern_matching.hpp.html
title: WildCard Pattern Matching
---
