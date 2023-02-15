vector<int> press(vector<int> A){
    vector<int> B;
    vector<int> T;
    rep(i,A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,A.size()){
        int pos=lower_bound(all(T),A[i])-T.begin();
        B.push_back(pos);
    }
    return B;
}