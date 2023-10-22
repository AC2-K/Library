#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"

#include"../../../src/stream.hpp"
#include"../../../src/template.hpp"
#include"../../../src/math/static_modint.hpp"
#include"../../../src/dynamic_programming/number_of_subseq.hpp"

using namespace std;
using namespace kyopro;

using mint = modint<998244353>;

int main() {
    int n;
    read(n);
    vector<int> a(n);
    rep(i, n) read(a[i]);
    put(num_of_subseq<mint, int>(a) - 1);
}