#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../src/data-structure/BinaryTrie.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

using u32 = uint32_t;
const int offset = 1e9;

int main() {
    int n, q;
    read(n, q);

    BinaryTrie<u32, 32> pq;

    rep(i, n) {
        int s;
        read(s);
        pq.insert(s + offset);
    }

    while (q--) {
        int t;
        read(t);

        if (t == 0) {
            int x;
            read(x);
            pq.insert(x + offset);
        } else if (t == 1) {
            u32 mn = pq.min();
            pq.erase(mn);

            put((int)mn - offset);
        } else {
            u32 mx = pq.max();
            pq.erase(mx);

            put((int)mx - offset);
        }
    }
}
