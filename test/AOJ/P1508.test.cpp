#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include "../../src/data-structure/bbst/SplayTree.hpp"
#include "../../src/stream.hpp"
#include "../../src/template.hpp"

using namespace std;
using namespace kyopro;

constexpr inline int op(int x, int y) noexcept { return min(x, y); }
constexpr inline int e() noexcept { return 1e9; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) read(a[i]);
    SplayTree<int, op, e> st(a);

    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int l, r;
            cin >> l >> r;
            int x = st.access(r);
            st.erase(r);
            st.insert(l, x);
        } else if (com == 1) {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r + 1) << endl;
        } else if (com == 2) {
            int i, x;
            cin >> i >> x;
            st.update(i, x);
        }
    }
}
