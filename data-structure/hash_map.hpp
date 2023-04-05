/// @brief HashMap
/// @tparam Key Keyの型
/// @tparam Val Valueの型
/// @brief HashMap(open address)
/// @tparam Key Keyの型
/// @tparam Val Valueの型
template <typename Key,
          typename Val,
          uint32_t n = 1 << 20,
          Val default_val = Val()
          >
class hash_map {
    using u32 = uint32_t;
    using u64 = uint64_t;

    bitset<n> flag;
    Key* keys = new Key[n];
    Val* vals=new Val[n];

    static constexpr u32 shift = 64 - __lg(n);

    u64 r;
    inline u32 get_hash(const Key& k) const {
        return ((u64)k * r) >> shift;
    }

  public:   
    explicit constexpr hash_map(){
        r = chrono::steady_clock::now().time_since_epoch().count();
        r ^= r >> 16;
        r ^= r << 32;
    }
    Val& operator[](const Key& k) {
        u32 hash = get_hash(k);

        while (1) {
            if (!flag.test(hash)) {
                keys[hash] = k;
                flag.set(hash);
                return vals[hash] = default_val;
            }

            if (keys[hash] == k)return vals[hash];
            hash = (hash + 1) & (n - 1);
        }
    }


    bool exists(const Key&k)const{
        u32 hash = get_hash(k);
        while (1) {
            if (!flag.test(hash)) return false;
            if (keys[hash] == k) return true;
            hash = (hash + 1) & (n - 1);
        }
    }
};