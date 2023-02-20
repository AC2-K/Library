#pragma once
#include"edge.hpp"
pair<vector<ll>,vector<int>> dijkstra(int s,const vector<vector<edge>>&g){
    vector<ll> dist(g.size(),infl);
    vector<int> pre(g.size(),-1);
    using st=pair<ll,int>;
    priority_queue<st,vector<st>,greater<st>> que;
    que.emplace(0,s);
    dist[s]=0;
    pre[s]=s;
    while(!que.empty()){
        auto[d,v]=que.top();
        que.pop();
        if(dist[v]!=d){
            continue;
        }

        for(const auto&[nv,c]:g[v]){
            if(dist[v]+c<dist[nv]){
                dist[nv]=dist[v]+c;
                pre[nv]=v;
                que.emplace(dist[nv],nv);
            }
        }
    }
    return make_pair(dist,pre);
}
///@brief dijkstra法