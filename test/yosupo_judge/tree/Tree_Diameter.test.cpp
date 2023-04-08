#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include<iostream>
#include<vector>
#include<algorithm>
#include"../../../src/graph/dijkstra.hpp"

int main() {
    int n;
    scanf("%d",&n);
    std::vector<std::vector<kyopro::edge>> g(n);
    for(int i=0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }

    auto dist=kyopro::dijkstra(0,g).first;
    int v=std::max_element(dist.begin(),dist.end())-dist.begin();
    dist=kyopro::dijkstra(v,g).first;
    auto it=std::max_element(dist.begin(),dist.end());
    int u=it-dist.begin();
    printf("%lld\n",*it);

    int cur=u;
    std::vector<int> ans;
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
    printf("%d\n",(int)ans.size());
    for(auto&k:ans)printf("%d ",k);
}