---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL/3_D.test.cpp
    title: test/AOJ/DSL/3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
      )"
    links: []
  bundledCode: "#line 2 \"src/data-structure/slide_window_minimum.hpp\"\n\n#include\
    \ <cassert>\n#include <deque>\n\nnamespace kyopro {\ntemplate <typename Key, typename\
    \ Value> class slide_window_minimum {\n    std::deque<std::pair<Key, Value>> deq;\n\
    \npublic:\n    bool empty() const noexcept { return deq.empty(); }\n\n    ///\
    \ @note keys given to this method must be increasing.\n    void emplace(Key key,\
    \ Value val) {\n        while (!deq.empty() && deq.back().second >= val) {\n \
    \           deq.pop_back();\n        }\n        deq.emplace_back(key, val);\n\
    \    }\n\n    void pop(Key t) {\n        while (!deq.empty() && deq.front().first\
    \ <= t) deq.pop_front();\n    }\n\n    Value fold() const noexcept {\n       \
    \ assert(!empty());\n        return deq.front().second;\n    }\n};\n\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024)\n*/\n"
  code: "#pragma once\n\n#include <cassert>\n#include <deque>\n\nnamespace kyopro\
    \ {\ntemplate <typename Key, typename Value> class slide_window_minimum {\n  \
    \  std::deque<std::pair<Key, Value>> deq;\n\npublic:\n    bool empty() const noexcept\
    \ { return deq.empty(); }\n\n    /// @note keys given to this method must be increasing.\n\
    \    void emplace(Key key, Value val) {\n        while (!deq.empty() && deq.back().second\
    \ >= val) {\n            deq.pop_back();\n        }\n        deq.emplace_back(key,\
    \ val);\n    }\n\n    void pop(Key t) {\n        while (!deq.empty() && deq.front().first\
    \ <= t) deq.pop_front();\n    }\n\n    Value fold() const noexcept {\n       \
    \ assert(!empty());\n        return deq.front().second;\n    }\n};\n\n};  // namespace\
    \ kyopro\n\n/**\n * @brief Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\
    \u5C0F\u5024)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/slide_window_minimum.hpp
  requiredBy: []
  timestamp: '2023-11-23 15:05:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL/3_D.test.cpp
documentation_of: src/data-structure/slide_window_minimum.hpp
layout: document
redirect_from:
- /library/src/data-structure/slide_window_minimum.hpp
- /library/src/data-structure/slide_window_minimum.hpp.html
title: "Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
---
