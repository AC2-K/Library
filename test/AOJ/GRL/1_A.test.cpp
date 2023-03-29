#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_A"

#include"template.hpp"
#include"graph/dijkstra.hpp"

int main(){
    int n,m,r;
    cin>>n>>m>>r;
    vector<vector<edge>> g(n);
    rep(i,m){
        int s,t,w;
        cin>>s>>t>>w;
        g[s].emplace_back(t,w);
    }

    auto res=dijkstra(r,g).first;

    rep(v,n){
        if(res[v]>=infl)cout<<"INF\n";
        else cout<<res[v]<<'\n';
    }
}