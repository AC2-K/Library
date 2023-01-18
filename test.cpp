#define Problem https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
//using i128=__int128_t;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
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
int main() {
    int n;
    cin>>n;
    vector<vector<pair<ll,ll>>> g(n);
    rep(i,n-1){
        int s,t,w;
        cin>>s>>t>>w;
        g[s].emplace_back(t,w);
        g[t].emplace_back(s,w);
    }

    auto dist=dijkstra(0,g);
    int v=0;
    ll now_max=0;
    rep(r,n){
        if(dist[r]>now_max){
            v=r;
            now_max=dist[r];
        }
    }

    dist=dijkstra(v,g);
    cout<<(*max_element(all(dist)))<<endl;
}
