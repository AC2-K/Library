#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../src/data-structure/bbst/Treap.hpp"
#include "../../../src/stream.hpp"
using namespace std;
int main() {
    kyopro::Treap<int> st;
    int n, q;
    kyopro::read(n, q);
    for (int i = 0; i < n; ++i) {
        int a;
        kyopro::read(a);
        st.insert(a);
    }
    while (q--) {
        int t;
        kyopro::read(t);
        if (!t) {
            int x;
            kyopro::read(x);
            st.insert(x);
        } else if (t == 1) {
            int mn = st.min_element();
            kyopro::put(mn);
            st.erase(mn);
        } else {
            int mx = st.max_element();
            kyopro::put(mx);
            st.erase(mx);
        }
    }
}