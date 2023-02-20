#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include"template.hpp"
#include"data-structure/cht.hpp"

int main(){
    int n,q;
    cin>>n>>q;

    CHT cht;    
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        cht.add(a,b);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            ll a,b;
            cin>>a>>b;
            cht.add(a,b);
        }else{
            ll x;
            cin>>x;
            cout<<cht(x)<<'\n';
        }
    }
}