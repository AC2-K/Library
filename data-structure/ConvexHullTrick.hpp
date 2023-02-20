template<typename T = ll, bool query_type = false>
class CHT {
	class line {
	public:
		T a, b;
		bool is_query;
		mutable T nxt_a, nxt_b;
		mutable bool has_nxt;
		T get(T x)const { return a * x + b; }
		T get_nxt(T x)const { return nxt_a * x + nxt_b; }
		line(T a, T b, bool q = false) :a(a), b(b), is_query(q), has_nxt(false) {}
		friend bool operator<(const line& l, const line& r) {
			if (l.is_query) {
				if (!r.has_nxt)return true;
				return r.get(l.a) < r.get_nxt(l.a);
			}
			if (r.is_query) {
				if (!l.has_nxt)return false;
				return l.get(r.a) > l.get_nxt(r.a);
			}
			return l.a == r.a ? l.b < r.b : l.a < r.a;
		}
	};

	set<line> ls;
	bool is_needed(const typename set<line>::iterator& it) {
		if (it != ls.begin() && it->a == prev(it)->a){
			return it->b < prev(it)->b;
		}
		if (next(it) != ls.end() && it->a == next(it)->a){
			return it->b < next(it)->b;
		}
		if (it == ls.begin() || next(it) == ls.end()){
			return true;
		}
		//精度大丈夫...?
		return 1.*(it->b - prev(it)->b) * (next(it)->a - it->a) < 1.*(it->b - next(it)->b) * (prev(it)->a - it->a);	
	}

public:
	void add(T a,T b) {
		ls.emplace(query_type ? -a : a, query_type ? -b : b);
        const auto&ln=(query_type?line{-a,-b}:line{a,b});
        auto it=ls.find(ln);
		if (!is_needed(it)) {
			ls.erase(it);
			return;
		}
		while (it != ls.begin() && !is_needed(prev(it))){
            ls.erase(prev(it));
        }
		while (next(it) != ls.end() && !is_needed(next(it))){
            ls.erase(next(it));
        }
		if (it != ls.begin()) {
			prev(it)->has_nxt = true;
			prev(it)->nxt_a = it->a;
			prev(it)->nxt_b = it->b;
		}
		if (next(it) != ls.end()) {
			it->has_nxt = true;
			it->nxt_a = next(it)->a;
			it->nxt_b = next(it)->b;
		}
	}
	T operator()(T x) const {
		const auto& it = ls.lower_bound(line(x, 0, true));

		if (query_type) {	
			return -it->a * x - it->b;
		}
		else {
			return it->a * x + it->b;
		}
	}
};
///@brief ConvexHullTrick