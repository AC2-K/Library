
/// https://kazuma8128.hatenablog.com/entry/2018/05/06/022654
template <typename T>
class binary_trie {
    static_assert(is_unsigned<T>::value, "T must be unsigned!!!");
    static constexpr int w = numeric_limits<T>::digits;
    struct node {
		int cnt;
		node *ch[2];
		node() : cnt(0), ch{ nullptr, nullptr } {}
	};
	node* add(node* t,const T& val, int b = w - 1) {
		if (!t) t = new node;
		t->cnt += 1;
		if (b < 0) return t;
		bool f = (val >> b) & static_cast<T>(1);
		t->ch[f] = add(t->ch[f], val, b - 1);
		return t;
	}
	node* sub(node* t,const T& val, int b = w - 1) {
		assert(t);
		t->cnt -= 1;
		if (t->cnt == 0) return nullptr;
		if (b < 0) return t;
		bool f = (val >> b) & static_cast<T>(1);
		t->ch[f] = sub(t->ch[f], val, b - 1);
		return t;
	}
	node* get_max(node* t, const T& val, int b = w - 1) const {
		assert(t);
		if (b < 0) return 0;
		bool f = (val >> b) & static_cast<T>(1);
		f ^= !t->ch[f];
		return get_max(t->ch[f], val, b - 1) | (static_cast<T>(f) << b);
	}
	T get(node* t, int k, int b = w - 1) const {
		if (b < 0) return 0;
		int m = t->ch[0] ? t->ch[0]->cnt : 0;
		return k < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b - 1) | (static_cast<T>(1) << b);
	}
	node *root;

public:
  	binary_trie() : root(nullptr) {}
	int size() const {
		return root ? root->cnt : 0;
	}
	bool empty() const {
		return size() == 0;
	}
	void insert(const T& val) {
		root = add(root, val);
	}
	void erase(const T& val) {
		root = sub(root, val);
	}
	int count(const T& val) const {
		if (!root) return 0;
		node *t = root;
		for (int i = w - 1; i >= 0; i--) {
			bool f = (val >> i) & static_cast<T>(1);
			t = t->ch[f];
			if (!t) return 0;
		}
		return t->cnt;
	}
	T max_element(T bias = 0) const {
		return get_max(root, bias);
	}
	T min_element(T bias = 0) const {
		return get_max(root, ~bias);
	}
	T operator[](int k) const {
		assert(0 <= k && k < size());
		return get(root, k);
	}
};