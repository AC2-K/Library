#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include"template.hpp"
#include"data-structure/lazy_segtree.hpp"

int op(int x,int y){return x+y;}
int comp(int x,int y){return x+y;}
int mapping(int x,int y){return x+y;}
int e(){return 0;}
int id(){return 0;}

int main() {
    int n,q;
    cin>>n>>q;
    lazy_segtree<int,int,op,e,comp,id,mapping> seg(n);
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int l,r;
            cin>>l>>r;
            int new_val;
            cin>>new_val;
            l--,r--;
            seg.update(l,r+1,new_val);
        }else{
            int i;
            cin>>i;
            i--;
            cout<<seg[i]<<'\n';
        }
    }
}