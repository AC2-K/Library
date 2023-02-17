#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include"template.hpp"
#include"DataStructure/segtree.hpp"
namespace for_segtree{
    using S=ll;
    S op(S x,S y){return x+y;}
    S e(){return 0;}
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    vector<ll> a(n);
    for(auto&aa:a){
        cin>>aa;
    }

    segtree<for_segtree::S,for_segtree::op,for_segtree::e> seg(a);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<seg.prod(l,r)<<'\n';
    }
}