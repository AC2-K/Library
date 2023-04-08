#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include<iostream>
#include"../../../src/math/static_modint.hpp"
#include"../../../src/math/matrix.hpp"
#pragma GCC optimize("unroll-loops")

using mint = kyopro::static_modint32<998244353>;
int main() {
    int n, m, k;
    scanf("%d%d%d",&n,&m,&k);
    using mat = kyopro::Matrix<mint>;
    mat a(n, m), b(m, k);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) { 
        int v;
        scanf("%d",&v);
        a[i][j]=mint(v);
    }
    for(int i=0;i<m;i++)for(int j=0;j<k;j++) { 
        int v;
        scanf("%d",&v);
        b[i][j]=mint(v);
    }
    auto res = a * b;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++) { printf("%d ",res[i][j].val()); }
        puts("");
    }
}

