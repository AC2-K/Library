#line 2 "main.test.cpp"
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
#line 2 "math/montgomery.hpp"
class montgomery64 {
    using mint = montgomery64;
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static u64 mod;
    static u64 r;
    static u64 n2;

    static u64 get_r() {
        u64 ret = mod;
        for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
        return ret;
    }
public:
    static void set_mod(const u128& m) {
        assert(m < (i128(1) << 64));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u128(m) % m;
        r = get_r();
        assert(r * mod == 1);
    }

protected:
    u128 a;

public:
    montgomery64() : a(0) {}
    template<typename T>
    montgomery64(const T& b) : a(reduce((u128(b) + mod)* n2)) {};
private:
    template<class T>
    static u64 reduce(const T& b) {
        return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
    }
public:
    template<class T>
    mint& operator=(const T& rhs) {
        return (*this) = mint(rhs);
    }

    mint& operator+=(const mint& b) {
        if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator-=(const mint& b) {
        if (i64(a -= b.a) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator*=(const mint& b) {
        a = reduce(u128(a) * b.a);
        return *this;
    }

    mint& operator/=(const mint& b) {
        *this *= b.inv();
        return *this;
    }

    mint operator+(const mint& b) const { return mint(*this) += b; }
    mint operator-(const mint& b) const { return mint(*this) -= b; }
    mint operator*(const mint& b) const { return mint(*this) *= b; }
    mint operator/(const mint& b) const { return mint(*this) /= b; }
    bool operator==(const mint& b) const {
        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
    }
    bool operator!=(const mint& b) const {
        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
    }
    mint operator-() const { return mint() - mint(*this); }

    mint pow(u128 n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const mint& b) {
        return os << b.val();
    }

    friend istream& operator>>(istream& is, mint& b) {
        int64_t t;
        is >> t;
        b = montgomery64(t);
        return (is);
    }

    mint inv() const { return pow(mod - 2); }

    u64 val() const {
        u64 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }

    static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;

class ArbitraryModInt {
    using mint = ArbitraryModInt;
    using i32 = int32_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;
    static u32 mod;
    static u32 r;
    static u32 n2;

    static u32 get_r() {
        u32 ret = mod;
        for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
        return ret;
    }
public:
    static void set_mod(u32 m) {
        assert(m < (1ll << 31));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u64(m) % m;
        r = get_r();
        assert(r * mod == 1);
    }
protected:
    u128 a;
public:
    ArbitraryModInt() : a(0) {}
    ArbitraryModInt(const int64_t& b)
        : a(reduce(u64(b% mod + mod)* n2)) {};

    static u32 reduce(const u64& b) {
        return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
    }

    mint& operator+=(const mint& b) {
        if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator-=(const mint& b) {
        if (i32(a -= b.a) < 0) a += 2 * mod;
        return *this;
    }

    mint& operator*=(const mint& b) {
        a = reduce(u64(a) * b.a);
        return *this;
    }

    mint& operator/=(const mint& b) {
        *this *= b.inv();
        return *this;
    }

    mint operator+(const mint& b) const { return mint(*this) += b; }
    mint operator-(const mint& b) const { return mint(*this) -= b; }
    mint operator*(const mint& b) const { return mint(*this) *= b; }
    mint operator/(const mint& b) const { return mint(*this) /= b; }
    bool operator==(const mint& b) const {
        return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
    }
    bool operator!=(const mint& b) const {
        return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
    }
    mint operator-() const { return mint() - mint(*this); }

    mint pow(u64 n) const {
        mint ret(1), mul(*this);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend ostream& operator<<(ostream& os, const mint& b) {
        return os << b.val();
    }

    friend istream& operator>>(istream& is, mint& b) {
        int64_t t;
        is >> t;
        b = ArbitraryModInt(t);
        return (is);
    }

    mint inv() const { return pow(mod - 2); }

    u32 val() const {
        u32 ret = reduce(a);
        return ret >= mod ? ret - mod : ret;
    }   

    static u32 get_mod() { return mod; }
};
typename ArbitraryModInt::u32 ArbitraryModInt::mod;
typename ArbitraryModInt::u32 ArbitraryModInt::r;
typename ArbitraryModInt::u32 ArbitraryModInt::n2;
/// @brief Montgomery
///by https://nyaannyaan.github.io/library/modint/modint-montgomery64.hpp,https://nyaannyaan.github.io/library/modint/arbitrary-prime-modint.hpp
#line 1 "math/mod_pow.hpp"
template <class T, class U = T>
U mod_pow(T base, T exp, T mod){
    if(base==0)return 0;
    T ans = 1;
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
#line 4 "math/fast_prime_check.hpp"
namespace prime {
    namespace miller{
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = __uint64_t;

        template<class mint>bool miller_rabin(u64 n, const u64 bases[], int siz){
            if (mint::get_mod() != n){
                mint::set_mod(n);
            }
            u64 d = n - 1;
            u64 q = __builtin_ctz(d);
            d >>= q;

            for(int i=0;i<siz;i++){
                u64 a = bases[i];
                if (a == n) {
                    return true;
                }

                if (mint(a).pow(d).val() != 1) {
                    bool flag = true;
                    for (u64 r = 0; r < q; r++) {
                        u64 pow = mint(a).pow(d * (1uL << r)).val();
                        if (pow == n - 1){
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

        bool is_prime(u64 n){
            static constexpr u64 bases_int[3] = {2, 7, 61};  // intだと、2,7,61で十分
            static constexpr u64 bases_ll[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
            if (n < 2) {
                return false;
            } else if (n == 2) {
                return true;
            } else if (~n & 1uL) {
                return false;
            }

            if(n<(1ul<<30)){
                return miller_rabin<ArbitraryModInt>(n, bases_int, 3);
            } else {
                return miller_rabin<montgomery64>(n, bases_ll, 7);
            }
        }
    };
};
using prime::miller::is_prime;
///@brief fast prime check(MillerRabinの素数判定法)
#line 7 "main.test.cpp"
namespace prime{
    namespace pollard{
        using i128 = __int128_t;
        using u128 = __uint128_t;
        using u64 = __uint64_t;

        template <typename T>
        T gcd(T x, T y){
            while (y != 0) {
                T ny = x % y;
                T nx = y;
                x = nx, y = ny;
            }
            return x;
        }
        u64 find_factor(u64 n){
            using mint = montgomery64;
            if(mint::get_mod() != n){
                mint::set_mod(n);
            }

            static u64 v = 7001;

            if (~n & 1uL){
                return 2;
            }
            if(is_prime(n)){
                return n;
            }
            while (1) {
                v ^= v << 13, v ^= v >> 7, v ^= v << 17;
                mint c = mint(v);
                auto f = [&](mint x) -> mint {
                    return x.pow(2) + c;
                };

                v ^= v << 13, v ^= v >> 7, v ^= v << 17;
                mint x = mint(v);
                mint y = f(x);
                u64 d = 1;
                while (d == 1){
                    d = gcd((u64)abs((ll)x.val() - (ll)y.val()), n);
                    x = f(x);
                    y = f(f(y));
                }
                if (1 < d && d < n) {
                    return d;
                }
            }
            exit(0);
        }

        vector<u64> rho_fact(u64 n){
            if (n < 2) {
                return {};
            }
            vector<u64> v;
            vector<u64> st{n};
            while (st.size()){
                u64 &m = st.back();
                if (is_prime(m)){
                    v.emplace_back(m);
                    st.pop_back();
                }else{
                    u64 d = find_factor(m);
                    m /= d;
                    st.emplace_back(d);
                }
            }
            return v;
        }
        vector<u64> naive(u64&n){
            static constexpr u64 basic_prime[] = {2, 3, 5, 7, 11, 13, 17, 1000000007, 998244353};
            vector<u64> res;
            for (const auto& p : basic_prime) {
                while (n % p == 0) {
                    n /= p;
                    res.emplace_back(p);
                }
            }

            return res;
        }
        vector<u64> fact(u64 n){
            if (n < 2) {
                return {};
            }
            vector<u64> v = naive(n);
            if (n != 1){
                vector<u64> v2 = rho_fact(n);
                v.insert(v.end(), all(v2));
            }
            sort(all(v));
            return v;
        }
    };  // namespace pollard
};  // namespace prime
using prime::pollard::fact;

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long x;
		cin >> x;
		cout << x << ' ' << is_prime(x) << '\n';
	}
}