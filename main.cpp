#include"template.hpp"
#include"data-structure/segtree.hpp"
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
