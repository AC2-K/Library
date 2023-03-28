#define PROBLEM "https://yukicoder.me/problems/no/891"

#include"template.hpp"
#include"math/static_modint.hpp"
#include"math/matrix.hpp"
using mint = static_modint32<MOD>;
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    Matrix<mint> A({{a, b}, {1, 0}});
    A = A.pow(n);
    cout << A[1][0] << '\n';
}
