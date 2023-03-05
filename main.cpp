#include"template.hpp"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
namespace modint {
	template<unsigned long long mod>
	class static_modint {
	private:
		using mint = modint::static_modint<mod>;
        using i64 = __int64_t;
        using u64 = __uint64_t;
        using u128 = __uint128_t;
        using i128 = __int128_t;

        i64 v = 0;
        void normalize(i64 &v){
            v %= mod;
			if (v < 0) {
				v += mod;
			}
        }

    public:
		static_modint(const i64& v_ = 0) :v(v_) { normalize(v); }


		u64 val() const {
			return (u64)v;
		}

		mint& operator+=(const mint& rhs) {
			v += rhs.val();
			normalize(v);
			return (*this);
		}
		mint& operator-=(const mint& rhs) {
			v -= rhs.val();
			normalize(v);
			return (*this);
		}
		mint& operator*=(const mint& rhs) {
			v *= rhs.val();
			normalize(v);
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
			v += rhs;
			normalize(v);
			return (*this);
		}
		mint& operator-=(const i64& rhs) {
			v -= rhs;
			normalize(v);
			return (*this);
		}
		mint& operator*=(const i64& rhs) {
			v *= rhs;
			normalize(v);
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

        friend mint operator/(const mint &l, const mint &r) {
            return mint(l) /= r;
        }

        //iostream
		friend ostream& operator<<(ostream& os, const mint& mt) {
			os << mt;
			return os;
		}

		friend istream& operator>>(istream& is, mint& mt) {
			i64 vv;
			is >> vv;
			mt = vv;
			return is;
		}
	};
};
using mint = modint::static_modint<MOD2>;
int main() {
    int N, M, K;
    cin >> N >> M >> K;
	vector<vector<mint>> dp(K + 1, vector<mint>(N + 1, mint(0)));  //dp[i][j]:=i回回してjにたどり着く確率
	dp[0][0] = 1;
	mint m_inv = mint(1) / M;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == N) {
				dp[i + 1][j] += dp[i][j];
				continue;
			}
			for (int l = 1; l <= M; l++) {
				int nxt = j + l;
				if (nxt > N) {
					int over = nxt - N;
					nxt = N - over;
				}
				dp[i + 1][nxt] += dp[i][j]*m_inv;
			}
		}
	}
	cout << dp[K][N] << endl;
}
