#include"template.hpp"
#include"math/mod_pow.hpp"
namespace fast_prime {
    //fast_is_prime
    using u64 = uint64_t;
    using i128 = __int128_t;
    using u128 = __uint128_t;
    namespace miller_rabin
    {
        bool miller_rabin(u64 p, const u64 base[], const int len) {
            u64 s = 0;
            u64 t = p - 1;

            while((~t&1ul)){
                s++;
                t >>= 1;
            }
            for (int i = 0; i < len; i++){
                u64 a = base[i];
                if (p % a == 0){
                    return p != a;
                }

                a %= p;
                if (mod_pow<i128>(a, t, p) == 1){
                    return true;
                }
                u64 e = t;
                for (int j = 0; j < s; j++){
                    if (mod_pow<i128>(a, e, p) == p - 1){
                        cout << a << endl;
                        return true;
                    }
                    e <<= 1;
                }
            }

            return false;
        }

        constexpr bool is_prime_fast(u64 n) {
            constexpr u64 base_int[3] = {2, 7, 61}, base_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

            if (n == 2)return true;
            if (n < 2 || (~n&1)){
                return false;
            }
            if (n < (1u << 31)){
                return miller_rabin(n, base_int, 3);
            }
            else{
                return miller_rabin(n, base_ll, 7);
            }
        }
    };
};
using fast_prime::miller_rabin::is_prime_fast;
int main() {
    int n;
    cin >> n;
    while (n--) {
        unsigned long long x;
        cin >> x;
        cout << x << ' ';
        if (is_prime_fast(x))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
}