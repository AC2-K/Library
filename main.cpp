#include"template.hpp"
#include"string/rolling_hash.hpp"

int main(){
    int n;
    cin>>n;
    vector<RollingHash> s(n);
    rep(i,n){
        string si;
        cin>>si;
        s[i]=RollingHash(si);
    }

    unordered_map<ll,unordered_map<ll,ll>> prefixes;  //先頭i文字を並べまくったやつ
    for(auto&h:s){
        rep(len,h.size()+1){
            prefixes[len][h.range(0,len)]++;
        }
    }
 
    for(auto&hs:s){
        int ng=hs.size()+1;
        int ok=0;
        while(abs(ok-ng)>1){
            int mid=(ok+ng)/2;
            if(prefixes[mid][hs.range(0,mid)]>=2){
                ok=mid;
            }else{
                ng=mid;
            }
        }
        cout<<ok<<endl;
    }

}