#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"
#include<iostream>
#include"data-structure/CHT.hpp"
using namespace std;
int main(){
    int n,q;
    scanf("%d%d",&n,&q);

    kyopro::CHT<long long> cht;    
    for(int i=0;i<n;i++){
        long long a,b;
        scanf("%lld%lld",&a,&b);
        cht.insert(a,b);
    }
    while(q--){
        int t;
        scanf("%d",&t);
        if(!t){
            long long a,b;
            scanf("%lld%lld",&a,&b);
            cht.insert(a,b);
        }else{
            long long x;
            scanf("%lld",&x);
            printf("%lld\n",cht(x));
        }
    }
}