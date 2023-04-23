#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include <iostream>
#include "../../../src/data-structure-2d/RangeTree.hpp"
inline long long op(long long a, long long b) { return a + b; };
inline long long e() { return 0; }
int main() {
    using namespace std;
    kyopro::RangeTree<int, long long, op, e> rtree;

    int N, Q;
    scanf("%d %d\n", &N, &Q);
    int X[N], Y[N], W[N];
    int c[Q];
    int s[Q], t[Q], u[Q], v[Q];
    for (int i = 0; i < Q; ++i) {
        scanf("%d %d %d\n", &X[i], &Y[i], &W[i]);
        rtree.add_point(X[i], Y[i]);
    }
    for (int i = 0; i < Q; ++i) {
        scanf("%d ", &c[i]);
        if (c[i]) {
            scanf("%d %d %d %d\n", &s[i], &t[i], &u[i], &v[i]);
        } else {
            scanf("%d %d %d\n", &s[i], &t[i], &u[i]);
            rtree.add_point(s[i], t[i]);
        }
    }

    rtree.build();

    for (int i = 0; i < N; ++i) rtree.add(X[i], Y[i], W[i]);
    
    for (int i = 0; i < Q; ++i) {
        if (c[i]) {
            printf("%lld\n", rtree.sum(s[i], t[i], u[i], v[i]));
        } else {
            rtree.add(s[i], t[i], u[i]);
        }
    }
}