int Solution::solve(vector<int> &A) {
    int ANS=0;
    for(int x:A){
        if(x==0){
            ANS=1;
            break;
        }
    }
    vector<long> pSum(A.size());
    pSum[0]=A[0];
    map<long,int> m;
    m[pSum[0]]=1;
    for(int i=1;i<A.size();i++){
        pSum[i]=A[i]+pSum[i-1];
        if(m[pSum[i]] > 0 ){
            ANS=max(ANS,i-m[pSum[i]]+1);
        }else{
            m[pSum[i]]=i+1;
        }
        if(pSum[i] ==  0 ){
            ANS=max(ANS,i+1);
        }
        
    }
    return ANS;
}
