#include"template.hpp"
#include"math/dynamic_modint.hpp"

int mod;
int q = 100000;
bool is_prime(int q) {
    if (q < 2) {
        return false;
    }
    if (q == 2) {
        return true;
    }
    if (~q & 1) {
        return false;
    }
    for (int d = 2; 1ll * d * d <= q; d++) {
        if (q % d == 0) {
            return false;
        }
    }
    return true;
}
void test() {
    using mint = dynamic_modint32;
    mod = rand();
    if(!is_prime(mod)){
        return;
    }
    q--;
    mint::set_mod(mod);
    mint ma = rand(), mb = rand();
    if (mb.val() == 0) {
        q++;
        return;
    }
    mint mc = ma / mb;
    if ((mc * mb).val() != ma.val()) {

    }
}
int main() {
    while(q){
        test();
    }
}