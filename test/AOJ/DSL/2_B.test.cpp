#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"
#include"template.hpp"
#include"data-structure/segtree.hpp"
using S=ll;
S op(S x,S y){return x+y;}
S e(){return 0;}

using namespace std;
int main() {
    int n,q;
    cin>>n>>q;
    segtree<S,op,e> seg(n);
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            ll i,x;
            cin>>i>>x;
            i--;
            seg.apply(i,x);
        }else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout<<seg.prod(l,r+1)<<'\n';
        }
    }
}
