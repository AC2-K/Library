/// @brief HashMap
/// @tparam Key Keyの型
/// @tparam Val Valueの型
template <typename Key,
          typename Val,
          uint32_t n = 1 << 20,
          Val default_val = Val(),
          Key unused = numeric_limits<Key>::max()>
class hash_map {
    using u32 = uint32_t;
    using u64 = uint64_t;



    bitset<n> flag;
    vector<Key> keys;
    vector<Val> vals;
    static constexpr u32 shift = 64 - __lg(n);



    static constexpr u64 rng() {
        u64 v = chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();

        v ^= v >> 16;
        v ^= v << 32;
        return v;
    }
    
    u64 r = rng();
    inline constexpr u64 get_hash(const Key& k)const {
        return (u64(k) * r) >> shift;
    }
public:
    hash_map() :
        keys(n),
        vals(n,default_val)
    {}
    Val& operator[](const Key& k) {
        u32 hash = get_hash(k);

        while (1) {
            if (!flag[hash]) {
                keys[hash] = k;
                flag[hash] = true;
                return vals[hash] = default_val;
            }


            if (keys[hash] == k)return vals[hash];

            hash = (hash + 1) & (n - 1);    //1進める
        }
    }
};