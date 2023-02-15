class Rho{
    using i128=__int128_t;
    mt19937 mt; //メルセンヌツイスタ
    class MillerRabin {
        using ll = long long;
        using i128 = __int128_t;
        const vector<ll> bases = { 2 , 7 , 61 };
        i128 mod_pow(i128 base, i128 exp, ll mod) {
            i128 ans = 1;
            base %= mod;
            while (exp) {
                if (exp & 1) {
                    ans *= base;
                    ans %= mod;
                }
                base *= base;
                base %= mod;
                exp >>= 1;
            }
            return ans;
        }
    
    public:
        bool is_prime(ll n) {
            if (n < 2) {
                return false;
            }
            ll d = n - 1;
            ll q = 0;
            while ((d & 1) == 0) {
                d >>= 1;
                q++;
            }
    
            for (ll a : bases) {
                if (a == n) {
                    return true;
                }
    
                if (mod_pow(a, d, n) != 1) {
                    bool flag = true;
                    for (ll r = 0; r < q; r++) {
                        ll pow = mod_pow(a, d * (1ll << r), n);
                        if (pow == n - 1) {
                            flag = false;
                            break;
                        }
                    }
    
                    if (flag) {
                        return false;
                    }
                }
            }
            return true;
        }
    }mr;
    long long c;
    ll f(i128 x,ll n){
        x%=n;
        return (x*x%n+c)%n;
    }
public:
    Rho(){
        mt.seed(clock());
    }

    ll find_factor(ll n){
        if(n==4){
            return 2;
        }
        c=mt()%n;
        ll x=mt()%n;
        ll y=x;
        ll d=1;

        while(d==1){
            x=f(x,n);
            y=f(f(y,n),n);
            d=__gcd(abs(x-y),n);
        }

        if(d==n){
            return -1;
        }
        return d;
    }


    vector<ll> fact(const ll n,bool sorting=true){
        if(n<2){
            return {};
        }
        if(mr.is_prime(n)){
            return{n};
        }
        ll res=-1;
        while(res==-1){
            res=find_factor(n);
        }
        vector<ll> V1=fact(res,false);
        vector<ll> V2=fact(n/res,false);
        V1.insert(V1.end(),V2.begin(),V2.end());
        if(sorting)sort(V1.begin(),V1.end());
        return V1;
    }
};