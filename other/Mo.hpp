class Mo {
    int n;
    vector<pair<int, int>> lr;
    vector<int> ord;
public:
  explicit Mo(int n) : n(n) { lr.reserve(n); }
  void add(int l, int r) { lr.emplace_back(l, r); }

private:
    inline void line_up() {
        int q = lr.size();
        int bs = n / min<int>(n, (int)sqrt(q));
        ord.resize(q);
        iota(begin(ord), end(ord), 0);
        sort(begin(ord), end(ord), [&](int a, int b) {
            int ablock = lr[a].first / bs, bblock = lr[b].first / bs;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? lr[a].second > lr[b].second : lr[a].second < lr[b].second;
            });
    }
public:
    template< typename AL, typename AR, typename EL, typename ER, typename O >
    void build(const AL& add_left, const AR& add_right, const EL& erase_left, const ER& erase_right, const O& out) {
        line_up();
        int l = 0, r = 0;
        for (const auto& idx : ord) {
            while (l > lr[idx].first) add_left(--l);
            while (r < lr[idx].second) add_right(r++);
            while (l < lr[idx].first) erase_left(l++);
            while (r > lr[idx].second) erase_right(--r);
            out(idx);
        }
    }

    template< typename A, typename E, typename O >
    void build(const A& add, const E& erase, const O& out) {
        build(add, add, erase, erase, out);
    }
};
/// @brief mo's algorithm