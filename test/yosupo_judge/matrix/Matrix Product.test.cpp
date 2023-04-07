#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include"template.hpp"
#include"math/static_modint.hpp"
#include"math/matrix.hpp"
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
using mint = static_modint32<MOD2>;
int main() {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    using mat = Matrix<mint>;
    mat a(n, m), b(m, k);
    rep(i, n) rep(j, m) { 
        int v;
        scanf("%d",&v);
        a[i][j]=mint(v);
    }
    rep(i, m) rep(j, k) { 
        int v;
        scanf("%d",&v);
        b[i][j]=mint(v);
    }
    auto res = a * b;
    rep(i, n) {
        rep(j, k) { printf("%d ",res[i][j].val()); }
        puts("");
    }
}

