#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include"template.hpp"
#include"graph/mst.hpp"
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    MST g(n);
    rep(i,m){
        int s,t,w;
        cin>>s>>t>>w;
        g.add_edge(s,t,w);
    }

    cout<<g.result()<<'\n';
}