## 概要
ワイルドカードを含むパターンマッチングを実装したものです.\
ワイルドカードを含むパターンマッチングとは、以下のような問題です.
> 文字列 $S$ , $T$ と文字 $w$ が与えられるので、各 $i=0,1,\dots,\vert S \vert - \vert T \vert +1$ に対して以下を判定する:
> > $S[i:i+\vert T \vert)$ と $T$ が**マッチしている**か?
>
> ただし、文字列 $a,b$ に対して $a$ と $b$ が**マッチする**とは、以下の両方が成り立つこと:
> - $\vert a \vert = \vert b \vert$
> - 各 $i$ に対して、以下のいずれかが成り立つ
>   - $a_i=b_i$
>   - $a_i,b_i$ のいずれかが $w$ に一致する

愚直に計算すると $O(\vert S \vert \vert T \vert)$ 時間かかりますが、うまい方法をとると $n=\vert S \vert + \vert T \vert$ として $O(n\log n)$ 時間に落とすことができます.

## wildcard_pattern_matching
```cpp
std::vector<bool> wildcard_pattern_matching<int m>(const string& s,const string& t,char wildcard)
```

長さ $\vert \mathtt{s} \vert - \vert \mathtt{t} \vert +1$ のvectorを返します.\
返り値の $i$ 番目の要素には、 $\mathtt{s} [i:i+\vert T \vert)$ と $\mathtt{t}$ がマッチするか(`true`/`false`)が格納されています.\
[$ m] は内部計算に用いる NTT 素数を入力してください.デフォルトでは 998244353です.

### 計算量
- $n = \vert \mathtt{s} \vert + \vert \mathtt{t} \vert$ として $O(n\log n)$

## 制約
- $\vert \mathtt{s} \vert\geq\vert \mathtt{t} \vert$
- $m$ はNTT素数.

## 誤判定の確率
マッチ判定をを $\mod m$ の畳み込みで計算しているので,誤判定する可能性があります. 誤判定確率は一回当たりexpected $1/n$ です.

## 誤判定対策
複数modのmodにより判定したり,何度かサブルーチンを呼び出すことにより正答確率を上げることができます.