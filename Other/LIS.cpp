#include"template.hpp"
template <class X>
class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    fx op;
    const X ex;
    vector<X> dat;
public:
    SegmentTree(int n_, fx fx_, X ex_) : n(), op(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }

    void set(int pos, X val) { 
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--){
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
    void update(int pos, X val) {
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) / 2;
            dat[pos] = op(dat[pos * 2 + 1], dat[pos * 2 + 2]);
        }
    }
    void add(int pos,X val){
        update(pos,get(pos)+val);
    }
    X query(int a, int b) { 
        if(a==0&&b==n)return dat[0];
        return query(a, b, 0, 0, n); 
    }

private:
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
template<class T>int LIS(vector<T> &a,bool strict=true) {
    int n=(int)a.size();
    vector<T> aval;
    for(auto aa:a)aval.push_back(aa);
    sort(all(aval));
    aval.erase(unique(all(aval)),aval.end());
    SegmentTree<int> dp(n+1,[](int a,int b){return max(a,b);},0);       //dp[i]=最後尾がiとなるようなLISの最大値
    int res=0;
    for(int i=0;i<n;i++){
        int h=lower_bound(all(aval),a[i])-aval.begin();
        h++;
        int upper=h;
        if(!strict)upper++;
        int A=dp.query(0,upper);
        if(dp.query(h,h+1)<A+1){
            dp.update(h,A+1);
            chmax(res,A+1);
        }
    }
    return res;
}