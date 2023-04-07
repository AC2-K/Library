#define PROBLEM "https://yukicoder.me/problems/no/1471"
#include"template.hpp"
#include"misc/mo.hpp"

using namespace std;
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    char str[n];
    scanf("%s", str);
    
    Mo mo(q);
    vector<int> x(q);
    for (auto& xi : x) {
        int l, r;
        scanf("%d%d%d", &l, &r, &xi);
        l--;
        mo.add(l, r);
        xi--;
    }
    multiset<char> st;
    auto add = [&](int p) { st.emplace(str[p]); };
    auto erase = [&](int p) { st.erase(st.find(str[p])); };
    vector<char> ans(q);
    auto out = [&](int p) { ans[p] = *next(st.begin(), x[p]); };
    mo.build(add, erase, out);
    for (auto& a : ans) {
        printf("%c\n", a);
    }
}
