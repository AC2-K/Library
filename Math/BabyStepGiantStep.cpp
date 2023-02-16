ll bsgs(S s,S g,ll n,ll m,const function<S(S)>&f,const function<S(S)>&fm){
    map<S,ll> mp;
    for(int j=1;j<=m;j++){
        g=f(g);
        mp[g]=j;
    }
    for(int i=1;;i++){
        s=fm(s);

        if(mp.find(s)!=mp.end()){
            return m*i-mp[s];
        }

        if(n<=m*i)break;
    }
    return -1;
}
/// @brief BabyStep GiantStep 
//条件を満たすf:S->Sについて、f^m(s)=gなる最小のmを求める