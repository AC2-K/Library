template<class T>class set_hash{
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
    ll hash;
    map<T,ll> mapping;
public:

    void insert(T x){
        if(mapping.find(x)!=mapping.end())return;
        mapping[x]=rng(x);
        hash=hash^mapping[x];
    }
    void erase(T x){
        if(mapping.find(x)==mapping.end())continue;
        hash=hash^mapping[x];
    }
    ll val(){return hash;}
};
