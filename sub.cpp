#include"template.hpp"
#include"math/montgomery.hpp"

namespace fast_prime{
    //fast_is_prime
    using u64 = uint64_t;
    namespace miller_rabin{

        constexpr u64 bases_int[] = {2, 7, 67};
        constexpr u64 bases_long[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

        template<typename mint>
        bool miller_rabin(u64 n, const u64 bases[],const int len){
            if (mint::get_mod() != n){
                mint::set_mod(n);
            }

            u64 d = n - 1;
            u64 q = __builtin_ctzll(d);
            d >>= q;

            const mint e1 = 1, e2 = n - 1;

            for (int i = 0; i < len; i++){
                u64 a = bases[i];

                if (n <= a){
                    break;
                }

                u64 t = d;
                mint y = mint(a).pow(t);

                while(t!=n-1&&y!=e1&&y!=e2){
                    y *= y;
                    t <<= 1;
                }

                if (y != e2 && (~t & 1ul)){
                    return false;
                }
            }

            return true;
        }

        bool is_prime(u64 n){
            if (n == 2){
                return true;
            }
            else if (n < 2||(~n & 1)){
                return false;
            }

            if (n < (1ul << 30)){
                return miller_rabin<ArbitraryModInt>(n, bases_int, 3);
            }
            else{
                return miller_rabin<montgomery64>(n, bases_long, 7);
            }
        }
    };
};
using fast_prime::miller_rabin::is_prime;
int main(){
    int n;
    cin >> n;
    while (n--){
        unsigned long long x;
        cin>>x;
        cout << x << ' ';
        if(is_prime(x)){
            cout << "1\n";
        }else{
            cout << "0\n";
        }
    }
}