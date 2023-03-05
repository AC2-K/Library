---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import random\ndef Miller_Rabin_test(num):\n    if num == 2:\n        return\
    \ True\n    if num > 2 and num & 1 == 0:\n        return False\n\n    s, t = 0,\
    \ num-1\n    while t & 1 == 0:\n        s, t = s+1, t >> 1\n    a = random.randint(1,\
    \ num-1)\n    if pow(a, t, num) == 1:\n        return True\n    for i in range(0,\
    \ s):\n        if pow(a, pow(2, i) * t, num) == num-1:\n            return True\n\
    \    return False\n\n\n\nn=int(input())\n\nfor _ in range(n):\n    p = int(input())\n\
    \n    if Miller_Rabin_test(p):\n        print(\"{} 1\\n\".format(p))\n    else:\n\
    \        print(\"{} 0\\n\".format(p))"
  dependsOn: []
  isVerificationFile: false
  path: test.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test.py
layout: document
redirect_from:
- /library/test.py
- /library/test.py.html
title: test.py
---
