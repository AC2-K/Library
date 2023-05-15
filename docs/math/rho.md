## 概要
Pollard Rho素因数分解法を実装したものです.

## factorize
```cpp
std::vector<uint64_t> kyopro::rho::factorize(uint64_t n)
```
以下の条件をすべて満たす列 $p$ を返します.
- 各 $i$ について、 $p_i$ は素数
- $p_0 \leq p_1 \leq \dots \leq p_{{\vert p \vert} -1}$ 
- $p_0 p_1 \cdots p_{{\vert p \vert} -2} p_{{\vert p \vert} -1} = n$ 

簡単に言うと, $n$ の素因数のリストをソートしたもの返します.

## exp_factorize
```cpp
std::vector<pair<uint64_t,int>> kyopro::rho::exp_factorize(uint64_t n)
```
$n$ の素因数分解を $n=p_0^{e_0} p_1^{e_1} \cdots p_k^{e_k}$ とします.\
この時 $(p_i,e_i)$ をペアにした列, $((p_0,e_0),(p_1,e_1),\dots,(p_k,e_k))$ を返します.また、この列は $p_i$ らに関して昇順であることが保証されます.