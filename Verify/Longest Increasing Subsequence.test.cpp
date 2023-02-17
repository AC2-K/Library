#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"
#include"template.hpp"
#include"DataStructure/segtree.hpp"
#include"Other/press.hpp"
using S = P;
S op(S x, S y) { return max(x,y); }
S e() { return P(0,0); }
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }   
    a=press(a);
    vector<int> prv(n,-1);
    iota(all(prv),0);
    segtree<S,op,e> dp(n+1);
    rep(i,n){
        auto[mx,p]=dp.prod(0,a[i]);
        if(mx+1>=dp[a[i]].first){
            prv[i]=p;
            dp.update(a[i],P(mx+1,i));
        }
    }
    auto[res,cur]=dp.prod(0,n+1);
    vector<int> idx;
    rep(i,res){
        idx.push_back(cur);
        cur=prv[cur];
    }
    cout<<idx.size()<<'\n';
    reverse(all(idx));
    for(auto&i:idx){
        cout<<i<<' ';
    }
    cout<<'\n';
}