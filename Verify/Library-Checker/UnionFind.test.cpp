#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include"template.hpp"
#include"DataStructure/dsu.hpp"
int main() {
    int n,q;
    cin>>n>>q;
    DSU dsu(n);
    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0){
            dsu.merge(x,y);
        }else{
            if(dsu.same(x,y))cout<<"1\n";
            else cout<<"0\n";
        }
    }
}