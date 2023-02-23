#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"

#include"template.hpp"
#include"graph/lca.hpp"


int main(){
    int n;
    cin>>n;
    graph g(n);
    rep(v,n){
        int k;
        cin>>k;
        rep(i,k){
            int c;
            cin>>c;
            g[c].emplace_back(v);
            g[v].emplace_back(c);
        }
    }

    LCA lca(g);
    lca.setup();


    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<lca.query(u,v)<<'\n';
    }
}