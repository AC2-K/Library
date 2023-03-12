#line 1 "main.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
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
const long double pi = acos(-1);
constexpr uint64_t MOD = 1e9 + 7;
constexpr uint64_t MOD2 = 998244353;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 2 "math/static_modint.hpp"
template<__uint64_t mod>
class static_modint {
private:
	using mint = static_modint<mod>;
	using i64 = long long;
	using u64 = unsigned long long;
	using u128 = __uint128_t;
	using i128 = __int128_t;

	u64 v;
	u64 normalize(i64 v_) const {
		v_ %= mod;
		if (v_ < 0) {
			v_ += mod;
		}
		return v_;
	}
public:
	static_modint() :v(0) {}
	static_modint(const i64& v_) :v(normalize(v_)) { }

	//operator
	u64 val() const {
		return v;
	}
	mint& operator+=(const mint& rhs) {
		v += rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator-=(const mint& rhs) {
		v += mod - rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator*=(const mint& rhs) {
		v = (u128)v * rhs.val() % mod;
		return (*this);
	}


	mint operator+(const mint& r) const {
		return mint(*this) += r;
	}
	mint operator-(const mint& r) const {
		return mint(*this) -= r;
	}
	mint operator*(const mint& r) const {
		return mint(*this) *= r;
	}

	mint& operator+=(const i64& rhs) {
		(*this) += mint(rhs);
		return (*this);
	}
	mint& operator-=(const i64& rhs) {
		(*this) -= mint(rhs);
		return (*this);
	}
	mint& operator*=(const i64& rhs) {
		(*this) *= mint(rhs);
		return (*this);
	}
	friend mint operator+(const i64& l, const mint& r) {
		return mint(l) += r;
	}
	friend mint operator-(const i64& l, const mint& r) {
		return mint(l) -= r;
	}
	friend mint operator*(const i64& l, const mint& r) {
		return mint(l) *= r;
	}

	mint operator+(const i64& r) {
		return mint(*this) += r;
	}
	mint operator-(const i64& r) {
		return mint(*this) -= r;
	}
	mint operator*(const i64& r) {
		return mint(*this) *= r;
	}


	mint& operator=(const i64& r) {
		return (*this) = mint(r);
	}

	bool operator==(const mint& r) {
		return (*this).val() == r.val();
	}
	mint pow(u128 e) const {
		mint ans(1), base(*this);
		while (e) {
			if (e & 1) {
				ans *= base;
			}
			base *= base;
			e >>= 1;
		}
		return ans;
	}

	mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) {
		return (*this) *= r.inv();
	}
	friend mint operator/(const mint& l, const i64& r) {
		return mint(l) /= mint(r);
	}

	//iostream
	friend ostream& operator<<(ostream& os, const mint& mt) {
		os << mt.val();
		return os;
	}
	friend istream& operator>>(istream& is, mint& mt) {
		i64 v_;
		is >> v_;
		mt = v_;
		return is;
	}
};
template<__uint32_t mod>
class static_modint32 {
private:
	using mint = static_modint32<mod>;
	using i32 = __int32_t;
	using u32 = __uint32_t;
	using i64 = __int64_t;
	using u64 = unsigned long long;

	u32 v;
	u32 normalize(i64 v_) const {
		v_ %= mod;
		if (v_ < 0) {
			v_ += mod;
		}
		return v_;
	}
public:
	static_modint32() :v(0) {}
	static_modint32(const i64& v_) :v(normalize(v_)) { }

	//operator
	u64 val() const {
		return (u64)v;
	}
	mint& operator+=(const mint& rhs) {
		v += rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator-=(const mint& rhs) {
		v += mod - rhs.val();
		if (v >= mod) {
			v -= mod;
		}
		return (*this);
	}
	mint& operator*=(const mint& rhs) {
		v = (u64)v * rhs.val() % mod;
		return (*this);
	}

	mint operator+(const mint& r) const {
		return mint(*this) += r;
	}
	mint operator-(const mint& r) const {
		return mint(*this) -= r;
	}
	mint operator*(const mint& r) const {
		return mint(*this) *= r;
	}

	mint& operator+=(const i64& rhs) {
		(*this) += mint(rhs);
		return (*this);
	}
	mint& operator-=(const i64& rhs) {
		(*this) -= mint(rhs);
		return (*this);
	}
	mint& operator*=(const i64& rhs) {
		(*this) *= mint(rhs);
		return (*this);
	}
	friend mint operator+(const i64& l, const mint& r) {
		return mint(l) += r;
	}
	friend mint operator-(const i64& l, const mint& r) {
		return mint(l) -= r;
	}
	friend mint operator*(const i64& l, const mint& r) {
		return mint(l) *= r;
	}

	mint operator+(const i64& r) {
		return mint(*this) += r;
	}
	mint operator-(const i64& r) {
		return mint(*this) -= r;
	}
	mint operator*(const i64& r) {
		return mint(*this) *= r;
	}


	mint& operator=(const i64& r) {
		return (*this) = mint(r);
	}

	bool operator==(const mint& r) {
		return (*this).val() == r.val();
	}
	mint pow(u64 e) const {
		mint ans(1), base(*this);
		while (e) {
			if (e & 1) {
				ans *= base;
			}
			base *= base;
			e >>= 1;
		}
		return ans;
	}

	mint inv() const {
		return pow(mod - 2);
	}

	mint& operator/=(const mint& r) {
		return (*this) *= r.inv();
	}
	friend mint operator/(const mint& l, const i64& r) {
		return mint(l) /= mint(r);
	}

	//iostream
	friend ostream& operator<<(ostream& os, const mint& mt) {
		os << mt.val();
		return os;
	}
	friend istream& operator>>(istream& is, mint& mt) {
		i64 v_;
		is >> v_;
		mt = v_;
		return is;
	}
};
///@brief static modint(静的modint)
#line 2 "math/matrix.hpp"
template<typename T>
class Matrix {
    vector<vector<T>> dat;
    int h, w;
public:
    Matrix(const vector<vector<T>>& dat)
        : dat(dat), h(dat.size()), w(dat.front().size()) {}

    Matrix(int h_, int w_, const T& v = T())
        : dat(h_, vector<T>(w_, v)){}
    static Matrix<T> I(int sz) {
        Matrix<T> ans(sz);
        rep(i, sz) { ans[i][i] = 1; }
        return ans;
    }
    using mat = Matrix<T>;
    //access
    vector<T>& operator[](int i) { return dat[i]; }

    //operator
    mat& operator+=(const mat& r) {
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] += r.dat[i][j];
            }
        }
        return (*this);
    }
    mat& operator-=(const mat&r){
        assert(r.h == this->h);
        assert(r.w == this->w);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                dat[i][j] -= r.dat[i][j];
            }
        }
        return (*this);
    }
    mat& operator*=(const mat& r) {
        int ha = dat.size(), wa = dat.front().size();
        int hb = r.dat.size(), wb = r.dat.front().size();
        assert(wa == hb);

        vector<vector<T>> res(ha, vector<T>(wb));
        rep(i, ha) rep(j, wb) rep(k, wa) {
            res[i][j] += dat[i][k] * r.dat[k][j];
        }
        swap(res, dat);
        return (*this);
    }

    mat operator+(const mat& r) { return mat(*this) += r; }
    mat operator-(const mat& r) { return mat(*this) -= r; }
    mat operator*(const mat& r) { return mat(*this) *= r; }

    mat pow(__uint64_t e) const {
        mat pr=I(this->h);
        mat pw(*this);

        while(e){
            if(e&1){
                pw *= pw;
            }
            pw *= pw;
            e >>= 1;
        }
        return pr;
    }
};
#line 5 "main.test.cpp"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using mint = static_modint32<MOD2>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    using mat = Matrix<mint>;
    mat a(n, m), b(m, k);
    rep(i, n) rep(j, m) { cin >> a[i][j]; }
    rep(i, m) rep(j, k) { cin >> b[i][j]; }
    auto res = a * b;
    rep(i, n) {
        rep(j, k) { cout << res[i][j] << ' '; }
        cout << '\n';
    }
}
