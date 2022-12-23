class DSU
{
    private:
    vector<int> par,rank,siz;
    
    public:
    DSU(int n):par(n,-1),rank(n,0),siz(n,1){ }

    int root(int x){
        if(par[x]==-1)return x;
        else return par[x]=root(par[x]);
    }

    bool same(int x,int y){
        return root(x)==root(y);
    }

    bool merge(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry)return false;

        if(rank[rx]<rank[ry])swap(rx,ry);
        par[ry]=rx;

        siz[rx]+=siz[ry]; 
        return true;
    }
    
    int size(int x){
        return siz[root(x)];
    }
};
