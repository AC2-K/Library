#line 1 "main.cpp"
#line 2 "src/template.hpp"
#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
#define popcount(x) __builtin_popcount(x)
using i128 = __int128_t;
using ll = long long;
using ld = long double;
using graph = std::vector<std::vector<int>>;
using P = std::pair<int, int>;
constexpr int inf = 1e9;
constexpr ll infl = 1e18;
constexpr ld eps = 1e-6;
const long double pi = acos(-1);
constexpr uint64_t MOD = 1e9 + 7;
constexpr uint64_t MOD2 = 998244353;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template <class T>
constexpr inline void chmax(T& x, T y) {
    if (x < y) x = y;
}
template <class T>
constexpr inline void chmin(T& x, T y) {
    if (x > y) x = y;
}
#line 4 "src/random/xor_shift.hpp"

namespace kyopro {
struct xor_shift32 {
    uint32_t rng;
    xor_shift32() : rng(std::rand()) {}
    uint32_t operator()() {
        rng ^= rng << 13;
        rng ^= rng >> 17;
        rng ^= rng << 5;
        return rng;
    }
};
};  // namespace kyopro
#line 6 "src/BST/Treap.hpp"
namespace kyopro {

template <class T>
class ReversibleBST {
    using u32 = uint32_t;
    xor_shift32 rng;
    struct Node {
        T key;
        u32 priority;
        std::shared_ptr<Node> l, r;
        Node(T key, u32 priority)
            : key(key), priority(priority), l(nullptr), r(nullptr) {}
    };
    using sptr = std::shared_ptr<Node>;
    sptr root = nullptr;
    void split(sptr t, T key, sptr& l, sptr& r) {
        if (!t) {
            l = r = nullptr;
        } else if (key < t->key) {
            split(t->l, key, l, t->l);
            r = t;
        } else {
            split(t->r, key, t->r, r), l = t;
        }
    }

    void merge(sptr& t, const sptr& l, const sptr& r) {
        if (!l || !r) {
            t = l ? l : r;
        } else if (l->priority > r->priority) {
            merge(l->r, l->r, r), t = l;
        } else {
            merge(r->l, l, r->l), t = r;
        }
    }

    void insert(sptr& t, const sptr& item) {
        if (!t) {
            t = item;
        } else if (item->priority > t->priority) {
            split(t, item->key, item->l, item->r);
            t = item;
        } else {
            insert(item->key < t->key ? t->l : t->r, item);
        }
    }

    void erase(sptr& t, T key) {
        if (!t) return;
        if (t->key == key) {
            merge(t, t->l, t->r);
        } else {
            erase(key < t->key ? t->l : t->r, key);
        }
    }

    const sptr find(const sptr& t, T key) const {
        if (!t) {
            return nullptr;
        } else if (t->key == key) {
            return t;
        } else {
            return find(key < t->key ? t->l : t->r, key);
        }
    }

public:
    void insert(T key) { insert(root, std::make_shared<Node>(key, rng())); }

    void erase(T key) { erase(root, key); }

    const Node* find(T key) const { return find(root, key).get(); }
    T pop_front() {
        assert(root);
        sptr cur = root;
        while (1) {
            if (cur->l) {
                cur = cur->l;
            } else {
                break;
            }
        }
        T ans = cur->key;
        merge(cur, cur->l, cur->r);
        return ans;
    }
    T pop_back() {
        assert(root);
        sptr cur = root;
        while (1) {
            if (cur->r) {
                cur = cur->r;
            } else {
                break;
            }
        }
        T ans = cur->key;
        merge(cur, cur->l, cur->r);
        return ans;
    }
};
};  // namespace kyopro
#line 3 "main.cpp"

int main() {
    kyopro::ReversibleBST<int> st;
    int n, q;
    scanf("%d%d", &n, &q);
    rep(i, n) {
        int a;
        std::cin >> a;
        st.insert(a);
    }
    while (q--) {
        int t;
        scanf("%d", &t);
        if (!t) {
            int x;
            scanf("%d", &x);
            st.insert(x);
        } else if (t == 1) {
            int mn = st.pop_front();
            printf("%d\n", mn);
            st.erase(mn);

        } else {
            int mx = st.pop_back();
            printf("%d\n", mx);
            st.erase(mx);
        }
    }
}
