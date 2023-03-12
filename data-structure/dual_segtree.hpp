template<class F, F(*comp)(F, F), F(*id)()>
class dual_segtree {
	int n;	

	int sz;

	const int lowest = -1;
	vector<pair<int, F>> dat;


	int cur;
public:
	dual_segtree(const int& n_) :n(n_), cur(0) {
		sz = 1;
		while (sz < n) {
			sz <<= 1;
		}

		dat.assign(sz << 1 , make_pair(lowest, id()));
	}

private:
	void innner_apply(const int& p, const int& l, const int& r, const int& L, const  int& R, const  F& f) {
		if (r <= L || R <= l) {
			return;
		}
		if (L <= l && r <= R) {
			F nf = comp(dat[p].second, f);
			dat[p] = make_pair(cur, nf);
			return;
		}
		else {
			int md = (l + r) >> 1;
			innner_apply(2 * p + 1, l, md, L, R, f);
			innner_apply(2 * p + 2, md, r, L, R, f);
		}
	}
public:
	void apply(const int& l, const int& r, const F& x) {
		//assert(0 <= l && l <= r && r <= n);
		innner_apply(0, 0, sz, l, r, x);
		cur++;
	}

	F operator[](int p) {
		p = p + sz - 1;	//1-index

		vector<pair<int, F>> path;
		path.emplace_back(dat[p]);
		while (p) {
			p = (p - 1) >> 1;
			path.emplace_back(dat[p]);
		};


		sort(path.begin(), path.end());

		F res = id();
		for (const auto& q : path) {
			if (q.first == lowest || q.second == id()) {
				continue;
			}
			res = comp(res, q.second);
		}

		return res;
	}
    //debug
	void print() {
		cout << "[";
		for (int i = 0; i < n; i++) {
			cout << (*this)[i] << ' ';
		}
		cout << "]\n";
	}
};

///@brief dual segtree(双対セグメント木)
///@docs docs/data-structure/dual_segtree.md