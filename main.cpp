#include"template.hpp"
#include"data-structure/binary_trie.hpp"
int main(){
    binary_trie<uint32_t> st;
    int q;
    cin >> q;
    while(q--){
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            st.insert(x);
        }else{
            x--;
            auto v = st[x];
            cout << v << '\n';
            st.erase(v);
        }
    }
}