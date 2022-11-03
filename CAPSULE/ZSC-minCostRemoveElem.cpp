int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end(), greater<int>());
    int cost=0;
    for(int i=0;i<A.size();i++){
        cost+=A[i]*(i+1);
    }
    return cost;
}
