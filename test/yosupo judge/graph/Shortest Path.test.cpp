#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include"template.hpp"
#include"graph/dijkstra.hpp"
int main() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    vector<vector<edge>> g(n);
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
    }
    auto [dist,trace]=dijkstra(s,g);
    if(dist[t]>=infl){
        cout<<-1<<'\n';
        return 0;
    }

    int cur=t;
    vector<int> path;
    while(cur!=trace[cur]){
        path.emplace_back(cur);
        cur=trace[cur];
    }

    path.emplace_back(cur);
    cout<<dist[t]<<' '<<path.size()-1<<'\n';
    reverse(all(path));
    for(int i=1;i<path.size();i++){
        cout<<path[i-1]<<' '<<path[i]<<'\n';
    }
}