#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include<iostream>
#include<algorithm>
#include"../../../src/graph/dijkstra.hpp"
using namespace std;
int main() {
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    std::vector<std::vector<kyopro::edge>> g(n);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
    }
    auto [dist,trace]=dijkstra(s,g);
    if(dist[t]>=(long long)1e18){
        puts("-1");
        return 0;
    }

    int cur = t;
    std::vector<int> path;
    while(cur!=trace[cur]){
        path.emplace_back(cur);
        cur=trace[cur];
    }

    path.emplace_back(cur);
    printf("%lld %lld\n",dist[t],path.size()-1);
    std::reverse(path.begin(),path.end());
    for(int i=1;i<(int)path.size();i++){
        printf("%d %d\n",path[i-1],path[i]);
    }
}