template <typename X>
class SegmentTree
{
    using fx = function<X(X, X)>;
  
    vector<X> dat;
    X ex;
    int siz = 1;
    fx op;
  
public:
    SegmentTree(int N, fx _op, X _ex):
    {
        ex = _ex;
        op = _op;
        siz = 1;
        while (siz < N)
            siz *= 2;
        dat.resize(siz * 2);
        for (int i = 0; i < siz * 2; i++)
            dat[i] = _ex;
    }

    void update(int pos, X x)
    {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2)
        {
            pos /= 2;
            dat[pos] = op(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }
    X query(int l, int r)
    {
        return query(l, r, 1, siz + 1, 1);
    }
private:
    X query(int l, int r, int a, int b, int u)
    {
        if (r <= a || b <= l)
            return ex;
        if (l <= a && b <= r)
            return dat[u];
        int m = (a + b) / 2;
        int L = query(l, r, a, m, u * 2);
        int R = query(l, r, m, b, u * 2 + 1);
        return op(L, R);
    }
};
