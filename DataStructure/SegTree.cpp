#include"template.hpp"
/// @brief セグメント木
/// @tparam X 乗っけるモノイド
template <typename X>
class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    fx op;
    const X ex;
    vector<X> dat;
public:
    /// @brief コンストラクタ
    /// @param n_ サイズ
    /// @param fx_ モノイドX上の演算
    /// @param ex_ Xの単位元
    SegmentTree(int n_, fx fx_, X ex_) : n(), op(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    /// @brief セットするだけ O(1)
    /// @param pos 変更する位置(0-index)
    /// @param val 変更後の値
    void set(int pos, X val) { 
        dat[pos + n - 1] = val;
    }
    /// @brief setしたあと、構築する O(n)
    void build() {
        for (int k = n - 2; k >= 0; k--){
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    /// @brief A_posをvalに更新する O(\log n)
    /// @param pos 位置
    /// @param val 変更後の値
    void update(int pos, X val) {
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) / 2;
            dat[pos] = op(dat[pos * 2 + 1], dat[pos * 2 + 2]);
        }
    }
    /// @brief A_pos にval加算する O(\log n)
    /// @param pos 略
    /// @param val 略
    void add(int pos,X val){
        update(pos,get(pos)+val);
    }
    /// @brief 区間[a,b)に演算を作用させた結果を返す O(\log n)
    /// @param a 
    /// @param b 
    /// @return 
    X query(int a, int b) { 
        if(a==0&&b==n)return dat[0];
        return query(a, b, 0, 0, n); 
    }

private:
    /// @brief 上のやつの補助.詳しいことは省く!!! 
    /// @param a 
    /// @param b 
    /// @param k 
    /// @param l 
    /// @param r 
    /// @return 
    X query(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            X vl = query(a, b, id * 2 + 1, l, (l + r) / 2);
            X vr = query(a, b, id * 2 + 2, (l + r) / 2, r);
            return op(vl, vr);
        }
    }

public:
    /// @brief A_posを返す O(1)
    /// @param pos 
    /// @return 
    X get(int pos){return dat[pos+n-1];}
};
