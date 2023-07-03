---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/wildcard_pattern_matching.md
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
    \n#include <string>\n#include <vector>\n#include<algorithm>\n#include \"random/xor_shift.hpp\"\
    \n\nnamespace kyopro {\nstd::vector<bool> wildcard_pattern_matching(const std::string&\
    \ s,\n                                            const std::string& t,\n    \
    \                                        char wild_card) {\n    assert(s.size()\
    \ >= t.size());\n    using mint = atcoder::modint998244353;\n    \n    // \u5404\
    \u6587\u5B57\u306B\u30CF\u30C3\u30B7\u30E5\u3092\u5272\u308A\u5F53\u3066\u308B\
    (\u30EF\u30A4\u30EB\u30C9\u30AB\u30FC\u30C9\u306B\u306E\u307F0\u3092\u5272\u308A\
    \u5F53\u3066\u308B\n    \n    static xor_shift32 rng;\n    static int d = rng();\n\
    \    \n    auto to_integer = [&](char v) -> mint {\n        return (v == wild_card\
    \ ? mint() : mint(v + d));\n    };\n\n    std::vector<mint> sv(s.size()), tv(t.size());\n\
    \    for (int i = 0; i < (int)s.size(); ++i) sv[i] = to_integer(s[i]);\n    for\
    \ (int i = 0; i < (int)t.size(); ++i) tv[i] = to_integer(t[i]);\n\n    // \u7573\
    \u307F\u8FBC\u307F\u3067\u30DE\u30C3\u30C1\u3092\u8A08\u7B97\u3059\u308B\n   \
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
    \n/**\n * @brief WildCard Pattern Matching\n * @docs docs/string/wildcard_pattern_matching.md\n\
    \ */\n"
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
## 概要
ワイルドカードを含むパターンマッチングを実装したものです.\
ワイルドカードを含むパターンマッチングとは、以下のような問題です.
> 文字列 $S$ , $T$ と文字 $w$ が与えられるので、各 $i=0,1,\dots,\vert S \vert - \vert T \vert +1$ に対して以下を判定する:
> > $S[i:i+\vert T \vert)$ と $T$ が**マッチしている**か?
>
> ただし、文字列 $a,b$ に対して $a$ と $b$ が**マッチする**とは、以下の両方が成り立つこと:
> - $\vert a \vert = \vert b \vert$
> - 各 $i$ に対して、以下のいずれかが成り立つ
>   - $a_i=b_i$
>   - $a_i,b_i$ のいずれかが $w$ に一致する

愚直に計算すると $O(\vert S \vert \vert T \vert)$ 時間かかりますが、うまい方法をとると $n=\vert S \vert + \vert T \vert$ として $O(n\log n)$ 時間に落とすことができます.
## wildcard_pattern_matching
```cpp
std::vector<bool> wildcard_pattern_matching(const string& s,const string& t,char wildcard)
```
長さ $\vert \mathtt{s} \vert - \vert \mathtt{t} \vert +1$ のvectorを返します.\
返り値の $i$ 番目の要素には、 $\mathtt{s} [i:i+\vert T \vert)$ と $\mathtt{t}$ がマッチするか(`true`/`false`)が格納されています.

### 計算量
- $n=\vert \mathtt{s} \vert + \vert \mathtt{t} \vert$ として $O(n\log n)$

## 制約
- $\vert \mathtt{s} \vert\geq\vert \mathtt{t} \vert$

## 誤判定の確率
マッチ判定をを $\mod 998244353$ の畳み込みで計算しているので、たまに誤判定します(えぇ...).\
誤判定確率は一回当たりexpected $1/998244353$ です.

## 誤判定対策
心配であれば、何度も判定を行い、すべてに通過したもののみをマッチしたとみなすことで(高い確率で)正しい結果を得られます.
