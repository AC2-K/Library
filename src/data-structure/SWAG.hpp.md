---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
    title: test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Slide Window Aggrigation
    links: []
  bundledCode: "#line 2 \"src/data-structure/SWAG.hpp\"\n#include <vector>\n#include\
    \ <algorithm>\nnamespace kyopro {\n/**\n * @brief Slide Window Aggrigation\n */\n\
    template <class S, auto op, auto e>\nclass SWAG {\n    std::vector<S> front_stack,\
    \ back_stack;\n    std::vector<S> front_prod, back_prod;\n\npublic:\n    constexpr\
    \ explicit SWAG() {\n        front_prod.emplace_back(e()), back_prod.emplace_back(e());\n\
    \    }\n    void reserve(size_t sz) {\n        back_stack.reserve(sz), back_prod.reserve(sz\
    \ + 1);\n    }\n    void push(const S& x) {\n        back_stack.emplace_back(x);\n\
    \        back_prod.emplace_back(op(back_prod.back(), x));\n    }\n    void pop_back()\
    \ { back_stack.pop_back(), back_prod.pop_back(); }\n    void pop_front() {\n \
    \       if (front_stack.empty()) {\n            std::reverse(back_stack.begin(),\
    \ back_stack.end());\n            std::swap(front_stack, back_stack);\n      \
    \      back_prod.clear(), front_prod.clear();\n            back_prod.emplace_back(e());\n\
    \            front_prod.resize(front_stack.size() + 1);\n            front_prod[0]\
    \ = e();\n            for (int i = 0; i < (int)front_stack.size(); ++i) {\n  \
    \              front_prod[i + 1] = op(front_stack[i], front_prod[i]);\n      \
    \      }\n        }\n        front_prod.pop_back(), front_stack.pop_back();\n\
    \    }\n\n    S fold() const { return op(front_prod.back(), back_prod.back());\
    \ }\n};\n};  // namespace kyopro\n"
  code: "#pragma once\n#include <vector>\n#include <algorithm>\nnamespace kyopro {\n\
    /**\n * @brief Slide Window Aggrigation\n */\ntemplate <class S, auto op, auto\
    \ e>\nclass SWAG {\n    std::vector<S> front_stack, back_stack;\n    std::vector<S>\
    \ front_prod, back_prod;\n\npublic:\n    constexpr explicit SWAG() {\n       \
    \ front_prod.emplace_back(e()), back_prod.emplace_back(e());\n    }\n    void\
    \ reserve(size_t sz) {\n        back_stack.reserve(sz), back_prod.reserve(sz +\
    \ 1);\n    }\n    void push(const S& x) {\n        back_stack.emplace_back(x);\n\
    \        back_prod.emplace_back(op(back_prod.back(), x));\n    }\n    void pop_back()\
    \ { back_stack.pop_back(), back_prod.pop_back(); }\n    void pop_front() {\n \
    \       if (front_stack.empty()) {\n            std::reverse(back_stack.begin(),\
    \ back_stack.end());\n            std::swap(front_stack, back_stack);\n      \
    \      back_prod.clear(), front_prod.clear();\n            back_prod.emplace_back(e());\n\
    \            front_prod.resize(front_stack.size() + 1);\n            front_prod[0]\
    \ = e();\n            for (int i = 0; i < (int)front_stack.size(); ++i) {\n  \
    \              front_prod[i + 1] = op(front_stack[i], front_prod[i]);\n      \
    \      }\n        }\n        front_prod.pop_back(), front_stack.pop_back();\n\
    \    }\n\n    S fold() const { return op(front_prod.back(), back_prod.back());\
    \ }\n};\n};  // namespace kyopro"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/SWAG.hpp
  requiredBy: []
  timestamp: '2023-05-08 05:54:18+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo_judge/data_structure/Queue_Operate_All_Composite.test.cpp
documentation_of: src/data-structure/SWAG.hpp
layout: document
redirect_from:
- /library/src/data-structure/SWAG.hpp
- /library/src/data-structure/SWAG.hpp.html
title: Slide Window Aggrigation
---