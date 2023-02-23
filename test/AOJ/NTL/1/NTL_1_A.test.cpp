#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include"template.hpp"
#include"math/fact.hpp"
int main(){
    int n;
    cin>>n;
    auto res=fact(n);
    cout<<n<<':';
    for(const auto&[p,e]:res){
        rep(i,e){
            cout<<' '<<p;
        }
    }
    cout<<'\n';
}