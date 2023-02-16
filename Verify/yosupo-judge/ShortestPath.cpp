#include<bits/stdc++.h>
#include"GraphAlgorithm/dijkstra.hpp"
#include"GraphAlgorithm/edge.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
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
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(nullptr);

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