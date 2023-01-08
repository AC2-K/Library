#include"template.hpp"
/// @brief 単一始点最短経路問題をdijkstra法で解く
/// @param s 始点となる頂点
/// @param g グラフ。pairのfirstに番号、secondに重みを格納する
/// @return 結果をvectorで返す
vector<ll> dijkstra(int s,const vector<vector<pair<ll,ll>>>&g){
    int n=g.size();
    priority_queue<P,vector<P>,greater<P>> que;
    que.emplace(0,s);
    vector<ll> dist(n,infl);
    vector<bool> confirm(n,false);
    dist[s]=0;
    while(!que.empty()){
        auto T=que.top();
        que.pop();
        int vc=T.first,vv=T.second;
        if(confirm[vv])continue;
        confirm[vv]=true;
        for(auto nex:g[vv]){
            int nv=nex.first,nc=nex.second;
            if(dist[nv]<dist[vv]+nc)continue;
            dist[nv]=dist[vv]+nc;
            que.emplace(dist[nv],nv);
        }
    }
    return dist;
}
