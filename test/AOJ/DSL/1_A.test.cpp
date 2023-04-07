#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include"template.hpp"
#include"data-structure/dsu.hpp"

using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    DSU dsu(n);
    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==0){
            dsu.merge(x,y);
        }else{
            cout<<(dsu.same(x,y)?"1\n":"0\n");
        }
    }
}