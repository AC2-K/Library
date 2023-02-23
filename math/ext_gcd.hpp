ll ext_gcd(ll a,ll b,ll&x,ll&y){
    if(b==0){
        x=1,y=0;
        return a;
    }else{
        ll d=ext_gcd(b,a%b,y,x);    //遡る
        y-=a/b*x;
        return d;
    }
}
/// @brief ext gcd(拡張ユークリッドの互除法)
/// @return ax+by=gcd(a,b)なるx,yを格納する,返り値にgcd(a,b)