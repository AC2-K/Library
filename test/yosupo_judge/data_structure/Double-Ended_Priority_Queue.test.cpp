#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../src/data-structure/bbst/Treap.hpp"
#include "../../../src/stream.hpp"
#include"../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    Treap<int> st;
    int n, q;
    read(n, q);
    for (int i = 0; i < n; ++i) {
        int a;
        read(a);
        st.insert(a);
    }
    while (q--) {
        // cout << "DEBUG = ";
        // for (const auto& q : st.nodes) cout << q->key << ' ';
        // cout << endl;
        // cout << "ROOT = ";
        // cout << st.root->key << endl;
        int t;
        read(t);
        if (!t) {
            int x;
            read(x);
            st.insert(x);
        } else if (t == 1) {
            int mn = st.min_element();
            put(mn);
            st.erase(mn);
        } else {
            int mx = st.max_element();
            put(mx);
            st.erase(mx);
        }
    }
}