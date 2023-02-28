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
inline long long safe_mod(long long a, long long m) {
    return (a % m + m) % m;
}
inline long long mul(long long a, long long b, long long m) {
    a = safe_mod(a, m); b = safe_mod(b, m);
    if (b == 0) return 0;
    long long res = mul(safe_mod(a + a, m), b>>1, m);
    if (b & 1) res = safe_mod(res + a, m);
    return res;
}
template<typename T>
__uint128_t large_modpow(T base,T exp,T mod){
    if(base==0)return 0;
    __uint128_t ans = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) {
            ans = mul(ans,base,mod);
        }
        base = mul(base,base,mod);
        exp >>= 1;
    }
    return ans;
}
#line 3 "string/rolling_hash.hpp"
using ull = uint_fast64_t;


namespace for_hash {
	constexpr ull mapping_max = (ull)'Z';
	ull base = -1;	//baseをランダムにとる
	constexpr ull mod = (1uL << 61) - 1;
	constexpr ull primitive_root = 37;
	ull strong_rand() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ull> rand(1uL, mod - 1);
		return rand(engine);
	}
	void generate_base() {
        if(base != -1) return;
		ull r = mod - 1;
		while (gcd(r, mod - 1) != 1 || r <= mapping_max) {
			r = strong_rand();
		}
		base = large_modpow(primitive_root, r, mod);
	}
};

class RollingHash {
	using i128 = __int128_t;	//変えましょうね~
	static constexpr ull msk30 = (1ul << 30) - 1;
	static constexpr ull msk61 = (1ul << 31) - 1;
	string str;
	vector<ull> hash, pow;


	ull mul(i128 a, i128 b)const {
		i128 t = a * b;

		t = (t >> 61) + (t & for_hash::mod);

		if (t >= for_hash::mod) {
			t -= for_hash::mod;
		}


		return t;
	}

	ull mapping(const char& c) {
		return (ull)c;	//変更する?
	}
public:
	RollingHash() :str() {	}

	RollingHash(const string& str) :str(str) {
		for_hash::generate_base();
		build();
	}

	void build() {
		hash.resize(str.size() + 1);
		pow.resize(str.size() + 1, 1);

		for (int i = 0; i < str.size(); i++) {
			hash[i + 1] = mul(hash[i], for_hash::base) + mapping(str[i]);
			pow[i + 1] = mul(pow[i], for_hash::base);
			if (hash[i + 1] >= for_hash::mod) {
				hash[i + 1] -= for_hash::mod;
			}
		}
	}
	ull range(int l, int r) const {
		ull ret = for_hash::mod + hash[r] - mul(hash[l], pow[r - l]);
		return ret < for_hash::mod ? ret : ret - for_hash::mod;
	}
};

///@brief rolling hash
#line 3 "main.cpp"
int main() {
	string t, p;
	cin >> t >> p;
	RollingHash hasht(t), hashp(p);
	for (int i = 0; i + p.size() <= t.size(); i++) {
		if (hasht.range(i, i + p.size()) == hashp.range(0,p.size())) {
			cout << i << '\n';
		}
	}
}
