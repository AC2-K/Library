template<
    class X, class M,
    X(*fx)(X, X), const X& ex,
    M(*fm)(M, M), const M& em,
    X(*fxm)(X, M)
>
class lazy_segtree {
    int sz;
    vector<X> dat;
    vector<M> lz;
    void Init(int n) {
        dat.assign(4 * n, ex);
        lz.assign(4 * n, em);
        int x = 1;
        while (n > x) {
            x <<= 1;
        }
        sz = x;
    }
public:
    lazy_segtree(int n) {
        lazy_segtree(n, vector<X>(n, ex));
    }
    lazy_segtree(int n, const vector<X>& a) {
        Init(n);
        for (int i = 0; i < n; i++) {
            set(i, a[i]);
        }
        build();
    }
public:
    void set(int pos, X x) {
        assert(0 <= pos && pos < sz);
        dat[pos + sz - 1] = x;
    }
    void build() {
        for (int i = sz - 2; i >= 0; i--) {
            dat[i] = fx(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

private:
    void eval(int pos) {
        if (lz[pos] == em) return;
        if (pos < sz - 1) {
            lz[2 * pos + 1] = fm(lz[2 * pos + 1], lz[pos]);
            lz[2 * pos + 2] = fm(lz[2 * pos + 2], lz[pos]);
        }
        dat[pos] = fxm(dat[pos], lz[pos]);
        lz[pos] = em;
    }

private:
    void update(int L, int R, int l, int r, M x, int k) {
        eval(k);
        if (L <= l && r <= R) {
            lz[k] = fm(lz[k], x);
            eval(k);
        }
        else if (L < r && l < R) {
            int mid = (l + r) >> 1;
            update(L, R, l, mid, x, 2 * k + 1);
            update(L, R, mid, r, x, 2 * k + 2);
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
public:
    void update(int l, int r, M x) {
        assert(0 <= l && l <= r && r <= sz);
        update(l, r, 0, sz, x, 0);
    }

private:
    X prod(int L, int R, int l, int r, int k) {
        eval(k);
        if (r <= L || R <= l) {
            return ex;
        }
        else if (L <= l && r <= R) {
            return dat[k];
        }
        else {
            int mid = (l + r) >> 1;
            X vl = prod(L, R, l, mid, 2 * k + 1);
            X vr = prod(L, R, mid, r, 2 * k + 2);
            return fx(vl, vr);
        }
    }

public:
    X prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sz);
        return prod(l, r, 0, sz, 0);
    }

    X operator[](int pos) {
        return prod(pos,pos+1);
    }
};
//@brief 遅延評価セグメント木
//X:モノイド,M:作用素の集合
//fx:X × X -> X 
//fm:M × M -> M
//fxm:X × M -> X