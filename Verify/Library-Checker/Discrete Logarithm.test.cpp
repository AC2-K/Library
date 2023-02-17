#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"
#include"template.hpp"
#include"Math/DLP.hpp"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int x,y,p;
        cin>>x>>y>>p;
        cout<<dlp(x,y,p)<<'\n';
    }
}