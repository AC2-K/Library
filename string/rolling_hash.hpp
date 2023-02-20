class RollingHash {
	static const ll mod = 1e9 + 7;
	const ll base;
	vector<ll> pow;
	static inline ll generate_base() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
		return rand(engine);
	}
	//id
	ll id(char c) {
		return (c - 'a' + 1);
	}
	void expand(int siz) {
		if ((int)pow.size() >= siz)return;

		int pre_siz = pow.size();
		pow.resize(siz + 1);
		for (int i = pre_siz; i <= siz; i++) {
			pow[i] = (pow[i - 1] * base) % mod;
		}
	}

public:
	RollingHash(ll base_ = generate_base()) :base(base_), pow{ 1 } {	}
	vector<ll> build(string& s) {
		vector<ll> hash(s.size() + 1);
		for (int i = 0; i < (int)s.size(); i++) {
			hash[i + 1] = (hash[i] * base % mod + id(s[i])) % mod;
		}
		return hash;
	}
	ll range(vector<ll>& hash, int l, int r) {
		expand(r - l);
		return ((hash[r] + mod - hash[l] * pow[r - l]) % mod + mod) % mod;
	}
};
///@brief rolling hash