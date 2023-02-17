#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include"template.hpp"
#include"GraphAlgorithm/dijkstra.hpp"
int main() {
    int n;
    cin>>n;
    vector<vector<edge>> g(n);
    rep(i,n-1){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    auto dist=dijkstra(0,g).first;
    ll dist_max=*max_element(all(dist));
    int v=find(all(dist),dist_max)-dist.begin();
    dist=dijkstra(v,g).first;
    dist_max=*max_element(all(dist));
    int u=find(all(dist),dist_max)-dist.begin();
    cout<<dist_max<<' ';

    int cur=u;
    vector<int> ans;
    while(cur!=v){
        ans.emplace_back(cur);
        for(auto&[p,c]:g[cur]){
            if(dist[p]+c==dist[cur]){
                cur=p;
                break;
            }
        }
    }
    ans.emplace_back(v);
    cout<<ans.size()<<'\n';
    for(auto&k:ans)cout<<k<<' ';
    cout<<'\n';
}