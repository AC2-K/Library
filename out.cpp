#line 2 "template.hpp"
#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using i128=__int128_t;
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
constexpr int inf = 1e9;
constexpr ll infl = 1e18;
constexpr ld eps = 1e-6;
constexpr long double pi = acos(-1);
constexpr ll MOD = 1e9 + 7;
constexpr ll MOD2 = 998244353;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 1 "math/mod_pow.hpp"
template <class T, class U = T>
U mod_pow(T base, T exp, T mod){
    if(base==0)return 0;
    U ans = 1;
    base %= mod;
    while (exp > 0) {
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
///@brief mod pow(バイナリ法)
#line 3 "main.test.cpp"
namespace fast_prime {
    //fast_is_prime
    using u64 = uint64_t;
    using i128 = __int128_t;
    using u128 = __uint128_t;
    namespace miller_rabin{
        bool miller_rabin(u64 p, const u64 base[], const int len) {
            u64 t = p - 1, s = 0;
            while((~t&1)){
                s++;
                t >>= 1;
            }
            for (int i = 0; i < len; i++){
                u64 a = base[i];
                if(a>=p){
                    break;
                }

                a %= p;
                if (mod_pow<u128>(a, t, p) == 1)
                {
                    return true;
                }

                for (int j = 0; j < s;j++){
                    if (mod_pow<u128>(a, (u128)(1) * (1ul << j) * t, p) == p - 1){
                        return true;
                    }
                }
            }

            return false;
        }

        constexpr bool is_prime_fast(u64 n) {
            constexpr u64 base_int[3] = {2, 7, 61}, base_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

            if (n == 2)return true;
            if (n < 2 || (~n & 1)){
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
