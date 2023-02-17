#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include"template.hpp"
#include"StringAlgorithm/rolling_hash.hpp"
int main() {
    string s;
    cin>>s;
    RollingHash rh;
    auto hash=rh.build(s);
    rep(i,s.size()){
        int ng=s.size()-i+1;
        int ok=0;
        while(ok+1!=ng){
            int md=(ok+ng)>>1;
            if(rh.range(hash,i,i+md)==rh.range(hash,0,md)){
                ok=md;
            }else{
                ng=md;
            }
        }
        cout<<ok<<'\n';
    }
}