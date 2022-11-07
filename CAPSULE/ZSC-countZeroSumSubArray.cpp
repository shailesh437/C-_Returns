int Solution::solve(vector<int> &A) {
     vector<int> pSum(A.size());
    pSum[0]=A[0];
    int zeroSumPrefix=0;
    
    if(pSum[0]==0){
            zeroSumPrefix++;
        }
    map<int,int> m;
    int repeatSumPrefix=0;
    m[pSum[0]]++;
    for(int i=1;i<A.size();i++){
        pSum[i]=pSum[i-1]+A[i];
        m[pSum[i]]++;
        if(pSum[i]==0){
            zeroSumPrefix++;
        }
    }
    int dueTorepeatSum=0;
    int MOD=1000000007;
    for(auto it=m.begin();it!=m.end();it++){
        //cout<<endl<<it->first<<"::"<<it->second<<endl;
        if(it->first!=0 and it->second>1){
            int r = it->second;
            r = r*(r-1)/2;
            dueTorepeatSum+=r%MOD;
            dueTorepeatSum=dueTorepeatSum%MOD;
        }
    } 
    return (dueTorepeatSum+(zeroSumPrefix*(zeroSumPrefix+1)/2)%MOD)%MOD;
 

     
}
