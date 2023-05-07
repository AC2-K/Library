---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"main.cpp\"\n#include<iostream>\ntemplate<typename str>\n\
    void putstr(const str&s){\n\tfor(auto c:s)putchar_unlocked(c);\n\n\tputchar_unlocked('\\\
    n');\n}\nint main(){\n\tputstr(\"COMCOM\");\n}\n"
  code: "#include<iostream>\ntemplate<typename str>\nvoid putstr(const str&s){\n\t\
    for(auto c:s)putchar_unlocked(c);\n\n\tputchar_unlocked('\\n');\n}\nint main(){\n\
    \tputstr(\"COMCOM\");\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: main.cpp
  requiredBy: []
  timestamp: '2023-05-07 10:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: main.cpp
layout: document
redirect_from:
- /library/main.cpp
- /library/main.cpp.html
title: main.cpp
---
