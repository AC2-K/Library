# dynamic modint
## 概要
modint構造体です。コンパイル時にmodが定まらないときに使います。
## 使いかた
普通のintと同じです。ただし、実際に使う前に
```cpp
dynamic_modint32::set_mod(mod)
```
みたいにする必要があります。また、逆元を使いたいときは`mod`は`int`型の範囲に収まる**素数である**必要があります。\
## verify
良い感じのverifyが見つからなかったので自作しました...
ここでは $+,-,*$ のテストをしています。
```cpp
#include"template.hpp"
#include"math/dynamic_modint.hpp"
int mod;
bool eq(ll s, ll t) {
    if(!(0 <= t && t < mod)){
        cout << t << '\n';
    }
    assert(mod > 0);
    s %= mod;
    
    if (s < 0) {
        s += mod;
    }

    return s == t;
}
using mint = dynamic_modint32;
void test() {
    ll a = rand(), b = rand();
    mod = rand();
    if (mod <= 0) {
        return;
    }
    mint::set_mod(mod);
    mint ma = a, mb = b;
    
    if(!eq(a+b,(ma+mb).val())){
        cout << -1 << '\n';
    }

    if (!eq(a*b,(ma*mb).val())) {
        cout << -1 << '\n';
    }

    if(!eq(a-b,(ma-mb).val())){
        cout << -1 << '\n';
    }
}
int main(){
    while (1.*clock()/CLOCKS_PER_SEC <=3.0){
        test();
    }   
}
```
こちらは$/$のテスト
```cpp
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
```

どちらの正常に作動しました。