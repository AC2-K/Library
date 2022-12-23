template<class T>class vector_front{
    //ハッシュの割り当て
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator() (T x) const {
            static const uint64_t FIXED_RANDOM =    
                chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    } rng;
    int n;
    vector<T> vec;
    vector<ll> hash;
public:
    //コンストラクタと、ハッシュ表
    set_hash(vector<T> v_):n(),vec(v_){n=vec.size();  }
    vector<ll> make_hash(){
        hash.resize(n+1);
        set<ll> found;
        for(int i=0;i<n;i++){
            ll x=vec[i];
            if(found.find(x)!=found.end()){
                hash[i+1]=hash[i];
            }
            else{
                found.insert(x);
                hash[i+1]=hash[i]^rng(x);
            }
        }
        return hash;
    }
    //区間[1,b]のハッシュを貰う(x,yは1-index)
    ll get(int x){
        if(hash.empty())make_hash();
        return hash[x];
    }
};

template<class T>class vector_front_mul{
    //ハッシュの割り当て
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        size_t operator() (T x) const {
            static const uint64_t FIXED_RANDOM =    
                chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
        }
    } rng;
    int n;
    vector<T> vec;
    vector<ll> hash;
public:
    //コンストラクタと、ハッシュ表
    set_hash(vector<T> v_):n(),vec(v_){n=vec.size();  }
    vector<ll> make_hash(){
        hash.resize(n+1);
        set<ll> found;
        for(int i=0;i<n;i++){
            ll x=vec[i];
            if(found.find(x)!=found.end()){
                hash[i+1]=hash[i];
            }
            else{
                found.insert(x);
                hash[i+1]=hash[i]+rng(x);
            }
        }
        return hash;
    }
    //区間[1,b]のハッシュを貰う(x,yは1-index)
    ll get(int x){
        if(hash.empty())make_hash();
        return hash[x];
    }
};