#pragma once
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) std::begin(x), std::end(x)
#define popcount(x) __builtin_popcountll(x)
using i128 = __int128_t;
using ll = long long;
using ld = long double;
using graph = std::vector<std::vector<int>>;
using P = std::pair<int, int>;
constexpr int inf = std::numeric_limits<int>::max() / 2;
constexpr ll infl = std::numeric_limits<ll>::max() / 2;
const long double pi = acosl(-1);
constexpr int dx[] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
template <typename T1, typename T2> constexpr inline bool chmax(T1& a, T2 b) {
    return a < b && (a = b, true);
}
template <typename T1, typename T2> constexpr inline bool chmin(T1& a, T2 b) {
    return a > b && (a = b, true);
}