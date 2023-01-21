int Solution::solve(vector<int> &A) {
    vector<long long int> pSum(A.size());
    map<long long int,long long int> m;
    pSum[0]=(long long int)A[0];
    if(A[0]==0) return 1;
    m[pSum[0]]=1;
    for(int i=1;i<A.size();i++){
        pSum[i]=(long long int)A[i]+pSum[i-1];
        m[pSum[i]]++;
        if(m[pSum[i]]>1 or pSum[i]==0) return 1;
    }
    return 0;
}
