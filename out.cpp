#line 1 "main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

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
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 1 "math/large_mod.hpp"
inline unsigned long long safe_mod(unsigned long long a, unsigned long long m) {
    return (a % m + m) % m;
}
unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long m) {
    a = safe_mod(a, m);
    b = safe_mod(b, m);
    if (b == 0) return 0;
    unsigned long long res = mul(safe_mod(a + a, m), b >> 1, m);
    if (b & 1){
        res = safe_mod(res + a, m);
    }
    return res;
}
template<typename T>
T large_modpow(T base,T exp,T mod){
    T ans = 1 % mod;
    base %= mod;
    while (exp) {
        if (exp & 1) {
            ans = mul(ans, base, mod);
        }
        base = mul(base, base, mod);
        exp >>= 1;
    }
    return ans;
}

unsigned long long i128_modpow(__uint128_t base, __uint128_t exp, unsigned long long mod){
    i128 res = (mod == 1 ? 0 : 1);
    base %= mod;
    while (exp){
        if (exp & 1){
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
#line 3 "math/fast_prime_check.hpp"

namespace prime
{
    using ull = unsigned long long;
    // MillerRabin
    bool is_prime_long(ull n){
        static const vector<ull> bases 
            = {2ull, 325ull, 9375ull, 28178ull, 450775ull, 9780504ull, 1795265022ull};

        ull d = n ^ 1uL;
        ull q = __builtin_ctz(d);
        d >>= q;

        for (const auto &a : bases){
            if (a == n){
                return true;
            }
            else if (a % n == 0){
                return false;
            }

            if (i128_modpow(a, d, n) != 1){
                bool is_prime_flag = true;
                for (ull r = 0; r < q;r++){
                    ull pw = i128_modpow(a, d * (1uL << r), n);

                    if(pw==n-1){
                        is_prime_flag = false;
                        break;
                    }
                }

                if(is_prime_flag){
                    return false;
                }
            }
        }
        return true;
    }

    bool is_prime_int(ull n){
        static const vector<ull> bases 
            = {2ull, 7ull, 61ull};

        ull d = n ^ 1uL;
        ull q = __builtin_ctzll(d);
        d >>= q;
        for (const auto &a : bases){
            if (a == n){
                return true;
            }
            else if (a % n == 0){
                return false;
            }

            if (i128_modpow(a, d, n) != 1){
                bool is_prime_flag = true;
                for (ull r = 0; r < q;r++){
                    ull pw = i128_modpow(a, d * (1uL << r), n);

                    if(pw==n-1){
                        is_prime_flag = false;
                        break;
                    }
                }

                if(is_prime_flag){
                    return false;
                }
            }
        }
        return true;
    }

    inline bool is_prime(ull n){
        if (n < 2){
            return false;
        }
        if(n == 2){
            return true;
        }
        if (~n & 1uL){
            return false;
        }

        
        if (n <= (1uL << 31)){
            return is_prime_int(n);
        }
        else{
            return is_prime_long(n);
        }
    }
};
///@brief fast prime check(MillerRabinの素数判定法)
#line 1 "math/prime_list.hpp"
//1000以下の素数
constexpr int prime_list1000[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
///@brief 素数表
#line 4 "math/fast_fact.hpp"
namespace prime
{
    using ull = unsigned long long;
    // Rho factorize
    
    ll find_factor(ll n){
        static ull v = 7001;
        v ^= v << 13, v ^= v >> 7, v ^= v << 17;
        /*
        if (n == 4){
            return 2;
        }
        */

        if (~n & 1uL){
            return 2;
        }
        static ull c=v;
        auto f = [&](i128 x) -> ll {
            x %= n;
            return (x * x % n + c) % n;
        };
        ll x = v % n;
        ll y=x;
        ll d=1;

        while (d == 1){
            x = f(x);
            y = f(f(y));
            d = __gcd(abs(x - y), n);
        }

        if (d == n){
            return -1;
        }
        return d;
    }
    vector<ull> rho_fact(ull&n){
        if (n < 2){
            return {};
        }
        if(is_prime(n)){
            return {n};
        }
        vector<ull> res;
        while (n != 1){

            ull d=-1;
            while (d == -1){
                d=find_factor(n);
            }

            while (n % d == 0){
                res.emplace_back(d);
                n /= d;
            }
        }

        return res;
    }

    vector<ull> naive_fact(ull&n){
        vector<ull> res;
        
        for (const ll d :prime_list1000){
            while (n % d == 0){
                res.push_back(d);
                n /= d;
            }
        }
        return res;
    }

    vector<ull> fact(ull n){
        vector<ull> res = naive_fact(n);
        vector<ull> res2=rho_fact(n);
        res.insert(res.end(), all(res2));
        sort(all(res));
        return res;
    }
};
///@brief fast factorize(Pollard Rhoの素因数分解)
#line 5 "main.test.cpp"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    scanf("%d",&q);

    while(q--){
        ll a;
        scanf("%lld", &a);
        auto pf = prime::fact(a);
        cout << pf.size() << ' ';
        for (auto &p : pf){
            cout << p << ' ';
        }
        cout << '\n';
    }
}
