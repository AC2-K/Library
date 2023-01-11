#include"template.hpp"
class DLP {
	ll mod_inv(ll a, ll m) {
		a %= m;
		ll b = m, u = 1, v = 0;
		while (b > 0) {
			ll t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		u %= m;
		if (u < 0) u += m;
		return u;
	}
	ll mod_pow(ll base, ll exp, ll M) {
		ll ans = 1;
		base %= M;
		while (exp > 0) {
			if (exp & 1) {
				ans *= base;
				ans %= M;
			}
			base *= base;
			base %= M;
			exp >>= 1;
		}
		return ans;
	}


	//X^n = Y (mod M)なる最小のnを見つける
public:
	ll find(ll x, ll y, const ll M) {
		ll g = 1;
		for (ll i = M; i >= 0; i /= 2) {
			(g *= x) %= M;
		}
		ll t = 1, c = 0;
		for (; t % g; c++) {
			if (t == y)return c;
			(t *= x) %= M;
		}
		if (y % g)return -1;
		t /= g;
		y /= g;

		if (M == 1)return 0;
		x %= M;
		y %= M;
		if (x == 0) {
			if (y == 1)return 0;
			else return -1;
		}


		//sqrt(M)を求める
		ll ok = 1e9;
		ll ng = 0;
		while (abs(ng - ok) > 1) {
			ll mid = ng + (ok - ng) / 2;
			if (mid >= M / mid)ok = mid;
			else ng = mid;
		}
		ll d = ok;
		//n=pd+qに分解する。p<=dかつq<d
		ll exp = M - 2;
		//x^pd=y(inv x)^q
		ll inv_x = mod_inv(x,M);
		map<ll, ll> find_q;
		ll pow_inv = y;
		for (ll q = 0; q <= d; q++) {
			if (find_q.find(pow_inv) == find_q.end())find_q[pow_inv] = q;
			pow_inv *= inv_x;
			pow_inv %= M;
		}

		ll pow_xd = 1;
		ll xd = mod_pow(x, d, M);
		for (ll p = 0; p <= d; p++) {
			if (pow_xd == 1 && p > 0) {
				return p * d;
			}
			else if (find_q.find(pow_xd) != find_q.end()) {
				//見つかったとき
				ll q = find_q[pow_xd];
				return d * p + q;
			}
			pow_xd *= xd;
			pow_xd %= M;
		}
		return -1;	//nod found
	}
};