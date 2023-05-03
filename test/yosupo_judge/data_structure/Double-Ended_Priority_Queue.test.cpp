#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <iostream>
#include "../../../src/BST/Treap.hpp"
using namespace std;
int main() {
    kyopro::Treap<int> st;
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
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