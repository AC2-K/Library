#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include"template.hpp"
#include"math/primitive_root.hpp"
int main(){
    int q;
    cin>>q;
    while (q--){
        ll p;
        cin>>p;
        ll ans=primitive_root(p);
        cout<<ans<<'\n';
    }
}
