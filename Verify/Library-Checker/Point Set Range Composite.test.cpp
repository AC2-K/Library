#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include"template.hpp"
#include"DataStructure/segtree.hpp"
#include"Math/prime_mint.hpp"
using mint=modint<MOD2>;

struct F
{
    mint a,b;
};

F op(F l,F r){
    mint na = l.a * r.a;
    mint nb = (l.b * r.a + r.b);
    return F{na, nb};
}
F e(){
    return F{1,0};
}
int main() {
    int n,q;
    cin>>n>>q;
    segtree<F,op,e> seg(n);
    rep(i,n){
        mint a,b;
        cin>>a>>b;
        seg.set(i,F{a,b});
    }
    seg.build();
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int p;
            mint c,d;
            cin>>p>>c>>d;
            seg.update(p,F{c,d});
        }else{
            int l,r;
            mint x;
            cin>>l>>r>>x;
            F res=seg.prod(l,r);
            mint ans=res.a*x+res.b;
            cout<<ans<<'\n';
        }
    }
}