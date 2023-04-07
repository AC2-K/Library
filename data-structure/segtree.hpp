/// @brief Segment Tree(セグメント木)
/// @tparam S 要素の型
/// @tparam op 二項演算
/// @tparam e 単位元
/// @docs docs/data-structure/segtree.md
template<class S, S(*op)(S, S), S(*e)()>
class segtree {
	int lg, sz, n;
	std::vector<S> dat;
public:
	segtree() :segtree(0) {}
	segtree(int n) : segtree(std::vector<S>(n, e())) {}
	segtree(const vector<S>& vec) : n((int)vec.size()) {
		sz = 1, lg = 0;
		while (sz <= n) {
			sz <<= 1;
			lg++;
		}

		dat = std::vector<S>(sz << 1, e());

		for (int i = 0; i < n; i++) {
			set(i, vec[i]);
		}
		build();
	}

	inline void set(const int p, const S& v) {
		dat[sz + p] = v;
	}
	inline void build() {
		for (int i = sz - 1; i > 0; i--) {
			dat[i] = op(dat[i << 1], dat[(i << 1) ^ 1]);
		}
	}
	S operator[](const int p) const { return dat[sz + p]; }

	inline void update(int p, const S& v) {
		p += sz;
		dat[p] = v;
		while (p >>= 1) {
			dat[p] = op(dat[(p << 1)], dat[(p << 1) ^ 1]);
		}
	}

	inline S prod(int l, int r) const {
		if (l == 0 && r == n) {
			return dat[1];
		}
		l += sz, r += sz;
		S sml = e(), smr = e();
		while (l != r) {
			if (l & 1)sml = op(sml, dat[l++]);
			if (r & 1)smr = op(dat[--r], smr);
			l >>= 1, r >>= 1;
		}
		return op(sml, smr);
	}
	inline void apply(int p, const S& v) {
		update(p, op(dat[sz + p], v));
	}
};