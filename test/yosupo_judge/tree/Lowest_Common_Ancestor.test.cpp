#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include<iostream>
#include"../../../src/tree/EulerTour.hpp"
using namespace std;
int main(){
    int n, q;
    scanf("%d%d",&n,&q);
    kyopro::EulerTour g(n);
    for (int i = 1; i < n; i++) {
        int p;
        scanf("%d", &p);
        g.add_edge(p, i);
    }
    g.build();
    while (q--) {
        int u, v;
        scanf("%d%d",&u,&v);
        printf("%d\n",g.lca(u, v));
    }
}