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
constexpr int64_t MOD = 1e9 + 7;
constexpr int64_t MOD2 = 998244353;
constexpr int dx[] = { 1,0,-1,0 };
constexpr int dy[] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
#line 1 "data-structure/segtree.hpp"
template<class S, S(*op)(S, S), S(*e)()>
class segtree {
    int n;
    vector<S> dat;
    void Init(int n_) {
        int x = 1;
        while (n_ > x) {
            x <<= 1;
        }
        n = x;
    }
public:
    segtree(int n_) : segtree(vector<S>(n_, e())) {   }
    segtree(const vector<S>& v) :dat(4 * v.size()) {
        Init(v.size());
        for (int i = 0; i < v.size(); i++) {
            set(i, v[i]);
        }
        build();
    }
    inline void set(int pos, S val) {
        assert(0 <= pos && pos < n);
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--) {
            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);
        }
    }

    void update(int pos, S val) {
        assert(0 <= pos && pos < n);
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) >> 1;
            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);
        }
    }
    inline S prod(int a, int b) {
        assert(0 <= a && b <= n);
        assert(a <= b);
        if (a == 0 && b == n)return dat[0];
        return prod(a, b, 0, 0, n);
    }

private:
    S prod(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return e();
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            int mid = (l + r) >> 1;
            S vl = prod(a, b, (id << 1) + 1, l, mid);
            S vr = prod(a, b, (id << 1) + 2, mid, r);
            return op(vl, vr);
        }
    }

public:
    //a[pos] <- a[pos]・x
    void add(int pos, S x) {
        update(pos, op(dat[n + pos - 1], x));
    }

    S operator [](int pos) {
        return dat[n + pos - 1];
    }
};
/// @brief segment tree(セグメント木)
///@docs docs/data-structure/segtree.md
#line 3 "main.cpp"
using namespace std;

template<unsigned long long mod>
class static_modint {
private:
	using mint = static_modint<mod>;
	using i64 = __int64_t;
	using u64 = __uint64_t;
	using u128 = __uint128_t;
	using i128 = __int128_t;

	i128 v;
	void normalize(i128& v) {
		v %= mod;
		if (v < 0) {
			v += mod;
		}
	}
public:
	static_modint(const u64& v_ = 0) :v(v_) { normalize(v); }


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
	friend mint operator*(const i64& l, const mint& r){
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
	mint pow(u128 e) {
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

	mint inv() {
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
		i64 vv;
		is >> vv;
		mt = vv;
		return is;
	}
};
using mint = static_modint<MOD2>;
struct F
{
    mint a,b;
};

F op(F l,F r){
    mint na = l.a * r.a;
    mint nb = (l.b * r.a + r.b);
    return F{na, nb};
}
F e(){
    return F{1,0};
}
int main() {
    int n,q;
    cin>>n>>q;
    segtree<F,op,e> seg(n);
    rep(i,n){
        mint a,b;
        cin>>a>>b;
        seg.set(i,F{a,b});
    }
    seg.build();
    while(q--){
        int t;
        cin>>t;
        if(t==0){
            int p;
            mint c,d;
            cin>>p>>c>>d;
            seg.update(p,F{c,d});
        }else{
            int l,r;
            mint x;
            cin>>l>>r>>x;
            F res=seg.prod(l,r);
            mint ans=res.a*x+res.b;
            cout<<ans<<'\n';
        }
    }
}
