# LibraryCPP
使ってるライブラリ集(C++)です
# DataStructure
データ構造とかです\
略語
- RMQ:区間の最小値(最大値)を求めるクエリ
- RSQ:区間和を求めるクエリ
- RUQ:区間更新クエリ
- RAQ:区間可算クエリ

|ファイル名|中身|verify|
|:--------|:---|:-----|
|SegTree|セグメント木|RMQ:[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DSL_2_A/judge/7442587/C++17)|
|||RSQ:[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DSL_2_B/judge/7442608/C++17)
|lazy_segtree|遅延評価セグメント木|RAQ:[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DSL_2_E/judge/7442453/C++17)|
|||RUQ:[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DSL_2_D/judge/7442479/C++17)|
|||RMQ&RUQ:[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DSL_2_F/judge/7434784/C++17)|
|dsu|UnionFind|[リンク](https://judge.yosupo.jp/submission/120804)|
# GraphAlgorithm
グラフ問題のためのライブラリです
|ファイル名|中身|verify|
|:--------|:---|:-----|
|MST|最小全域木|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/GRL_2_A/judge/7440641/C++17)|
|dijkstra|ダイクストラ法|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/GRL_1_A/judge/7325288/C++17)|
# Math
数学系統のライブラリです
|ファイル名|中身|verify|
|:--------|:---|:-----|
|fact|$O(\sqrt n)$の素因数分解|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/NTL_1_A/judge/7312275/C++17)|
|FastPrimeCheck|ミラーラビンの素数判定|[ココ](https://algo-method.com/submissions/758365)と[ココ](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/ALDS1_1_C/judge/7314111/C++17)...一部ケースでバグってる|
|FastFact|$\rho$法|作成中|
|mint|modint|未|
|pow|繰り返しニ乗法|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/NTL_1_B/judge/7312276/C++17)|
|PrimeCheck|エラトステネスの篩|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/ALDS1_1_C/judge/7325294/C++17)|
|DLP|離散対数(BSGS)|作成中|
# StringAlgorithm
文字列アルゴリズムです
|ファイル名|中身|verify|
|:--------|:---|:-----|
|RollingHash|ローリングハッシュ|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/ALDS1_14_B/judge/7325179/C++17)|
# Other
その他の便利そうなやつです
|ファイル名|中身|verify|
|:--------|:---|:-----|
|LIS|狭義/広義単調増加部分列|[リンク](https://onlinejudge.u-aizu.ac.jp/status/users/ac2000_/submissions/1/DPL_1_D/judge/7325298/C++17)|
|press|座標圧縮|[リンク](https://atcoder.jp/contests/abc036/submissions/37949032)|