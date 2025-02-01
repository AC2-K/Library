---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.1/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: data-structure/lazy_segtree.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <tuple>\n#include <utility>\n\
    #include \"data-structure/lazy_segtree.hpp\"\nnamespace kyopro {\ntemplate <typename\
    \ T> class area_of_union_of_rectangles {\n    struct dat {\n        int min_val;\n\
    \        T min_width;\n\n        dat() = default;\n        dat(int min_val, T\
    \ min_width)\n            : min_val(min_val), min_width(min_width) {}\n    };\n\
    \n    static constexpr dat op(dat x, dat y) {\n        if (x.min_val < y.min_val)\
    \ {\n            return x;\n        } else if (x.min_val > y.min_val) {\n    \
    \        return y;\n        } else {\n            return dat(x.min_val, x.min_width\
    \ + y.min_width);\n        }\n    }\n    static constexpr dat e() { return dat(int(1e9),\
    \ 0); }\n\n    static constexpr int composition(int x, int y) { return x + y;\
    \ }\n    static constexpr int id() { return 0; }\n\n    static constexpr dat mapping(dat\
    \ x, int y) {\n        return dat(x.min_val + y, x.min_width);\n    }\n\n    std::vector<T>\
    \ xs, ys;\n    std::vector<std::tuple<T, T, T, int>> qs;\n\npublic:\n    void\
    \ add(T xl, T xr, T yl, T yr) {\n        xs.emplace_back(xl), xs.emplace_back(xr);\n\
    \        ys.emplace_back(yl), ys.emplace_back(yr);\n        qs.emplace_back(xl,\
    \ yl, yr, 1);\n        qs.emplace_back(xr, yl, yr, -1);\n    }\n\n    T calc()\
    \ {\n        std::sort(xs.begin(), xs.end()),\n            xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n        std::sort(ys.begin(), ys.end()),\n          \
    \  ys.erase(std::unique(ys.begin(), ys.end()), ys.end());\n\n        std::sort(qs.begin(),\
    \ qs.end());\n\n        for (auto& [x, yl, yr, v] : qs) {\n            yl = std::lower_bound(ys.begin(),\
    \ ys.end(), yl) - ys.begin();\n            yr = std::lower_bound(ys.begin(), ys.end(),\
    \ yr) - ys.begin();\n        }\n\n        lazy_segtree<dat, int, area_of_union_of_rectangles::op,\n\
    \                     area_of_union_of_rectangles::e,\n                     area_of_union_of_rectangles::composition,\n\
    \                     area_of_union_of_rectangles::id,\n                     area_of_union_of_rectangles::mapping>\n\
    \            sg((int)ys.size());\n        for (int i = 0; i < (int)ys.size() -\
    \ 1; ++i) {\n            sg.set(i, dat{0, ys[i + 1] - ys[i]});\n        }\n  \
    \      sg.build();\n\n        T ans = 0;\n        for (int i = 0, j = 0; i < (int)xs.size()\
    \ - 1; ++i) {\n            while (j < (int)qs.size() && std::get<0>(qs[j]) <=\
    \ xs[i]) {\n                auto [x, yl, yr, v] = qs[j];\n                sg.apply(yl,\
    \ yr, v);\n                ++j;\n            }\n\n            ans += T(xs[i +\
    \ 1] - xs[i]) * (ys.back() - ys[0]);\n\n            auto [v, w] = sg.fold(0, (int)ys.size()\
    \ - 1);\n            if (v == 0) {\n                ans -= T(xs[i + 1] - xs[i])\
    \ * w;\n            }\n        }\n        return ans;\n    }\n};\n};  // namespace\
    \ kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/data-structure-2d/area-of-union-of-rectangles.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/data-structure-2d/area-of-union-of-rectangles.hpp
layout: document
redirect_from:
- /library/src/data-structure/data-structure-2d/area-of-union-of-rectangles.hpp
- /library/src/data-structure/data-structure-2d/area-of-union-of-rectangles.hpp.html
title: src/data-structure/data-structure-2d/area-of-union-of-rectangles.hpp
---
