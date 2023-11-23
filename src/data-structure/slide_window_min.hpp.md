---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
      )"
    links: []
  bundledCode: "#line 2 \"src/data-structure/slide_window_min.hpp\"\n\n#include <cassert>\n\
    #include <deque>\n\nnamespace kyopro {\ntemplate <typename Key, typename Value>\
    \ class slide_window_min {\n    std::deque<std::pair<Key, Value>> deq;\n\npublic:\n\
    \    bool empty() const noexcept { return deq.empty(); }\n\n    /// @note keys\
    \ given to this method must be increasing.\n    void emplace(Key key, Value val)\
    \ {\n        while (!deq.empty() && deq.back().second >= val) {\n            deq.pop_back();\n\
    \        }\n        deq.emplace_back(key, val);\n    }\n\n    void pop(Key t)\
    \ {\n        while (!deq.empty() && deq.front().first < t) deq.pop_front();\n\
    \    }\n\n    Value fold() const noexcept {\n        assert(!empty());\n     \
    \   return deq.front().second;\n    }\n};\n\n};  // namespace kyopro\n\n/**\n\
    \ * @brief Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)\n\
    */\n"
  code: "#pragma once\n\n#include <cassert>\n#include <deque>\n\nnamespace kyopro\
    \ {\ntemplate <typename Key, typename Value> class slide_window_min {\n    std::deque<std::pair<Key,\
    \ Value>> deq;\n\npublic:\n    bool empty() const noexcept { return deq.empty();\
    \ }\n\n    /// @note keys given to this method must be increasing.\n    void emplace(Key\
    \ key, Value val) {\n        while (!deq.empty() && deq.back().second >= val)\
    \ {\n            deq.pop_back();\n        }\n        deq.emplace_back(key, val);\n\
    \    }\n\n    void pop(Key t) {\n        while (!deq.empty() && deq.front().first\
    \ < t) deq.pop_front();\n    }\n\n    Value fold() const noexcept {\n        assert(!empty());\n\
    \        return deq.front().second;\n    }\n};\n\n};  // namespace kyopro\n\n\
    /**\n * @brief Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    )\n*/"
  dependsOn: []
  isVerificationFile: false
  path: src/data-structure/slide_window_min.hpp
  requiredBy: []
  timestamp: '2023-11-23 14:53:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data-structure/slide_window_min.hpp
layout: document
redirect_from:
- /library/src/data-structure/slide_window_min.hpp
- /library/src/data-structure/slide_window_min.hpp.html
title: "Slide Window Minimum(\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024)"
---
