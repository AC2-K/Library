#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include"template.hpp"
#include"data-structure/segtree.hpp"
ll op(ll x,ll y){return x+y;}
ll e(){return 0;}
int main(){
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto&aa:a){
        cin>>aa;
    }

    segtree<ll,op,e> seg(a);
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int p,x;
            cin>>p>>x;
            seg.add(p,x);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<seg.prod(l,r)<<'\n';
        }
    }
}