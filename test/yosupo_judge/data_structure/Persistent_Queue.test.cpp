#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"
#include <iostream>
#include <vector>
#include "../../../src/data-structure/persistent/queue.hpp"
#include "../../../src/stream.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int q;
    read(q);
    std::vector<kyopro::persistent_queue<int>> v(q + 1);
    for (int i = 1; i <= q; i++) {
        int t, idx;
        read(t, idx);
        idx++;

        if (!t) {
            int s;
            read(s);
            v[i] = v[idx].push(s);
        } else {
            put(v[idx].front());
            v[i] = v[idx].pop();
        }
    }
}