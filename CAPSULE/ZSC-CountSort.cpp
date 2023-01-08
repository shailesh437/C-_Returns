vector<int> Solution::solve(vector<int> &A) {
    int maxEle=INT_MIN;
    int minEle=INT_MAX;
    for(int x:A){
        maxEle=max(x,maxEle);
        minEle=min(x,minEle);
    }
    vector<int> freq(maxEle+1,0);
    for(int i=0;i<A.size();i++){
        freq[A[i]]++;
    }
    for(int i=1;i<=maxEle;i++){
        freq[i]+=freq[i-1];
    }
    vector<int> ans(A.size());
    for(int i=A.size()-1;i>=0;i--){
        int idx=freq[A[i]]-1;
        ans[idx]=A[i];
        freq[A[i]]--;
    }
    return ans;
}
