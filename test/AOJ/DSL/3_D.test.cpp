#define PROBLEM \
    "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/3/DSL_3_D"
#include "../../../src/data-structure/slide_window_minimum.hpp"
#include "../../../src/stream.hpp"
#include "../../../src/template.hpp"

using namespace std;
using namespace kyopro;

int main() {
    int n, l;
    read(n, l);
    slide_window_minimum<int, int> q;
    rep(i, l) {
        int a;
        read(a);
        q.emplace(i, a);
    }
    printf("%d", q.fold());
    for (int i = l; i < n; ++i) {
        int a;
        read(a);
        q.emplace(i, a);
        q.pop(i - l + 1);
        printf("%c%d", " \n"[i == n - 1], q.fold());
    }
    printf("\n");
}
