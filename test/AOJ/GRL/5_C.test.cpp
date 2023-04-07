#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_C"

#include"template.hpp"
#include"graph/euler_tour.hpp"
using namespace std;
int main(){
    int n;
    cin>>n;
    EulerTour g(n);
    rep(v, n) {
        int k;
        cin>>k;
        rep(i,k){
            int c;
            cin>>c;
            g.add_edge(v, c);
        }
    }

    g.build();
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        cout << g.lca(u, v) << '\n';
    }
}