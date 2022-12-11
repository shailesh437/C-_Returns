int Solution::cntBits(vector<int> &A) {
    int MOD=1000000007;
    unsigned long int ans=0;
    int N=A.size();

    for(int i=0;i<31;i++){
        int setBitCount=0;
        for(int j=0;j<A.size();j++){
            if( A[j] & (1<<i)) setBitCount++;
        }
        unsigned long val =(unsigned long) setBitCount%MOD*
                           (unsigned long)(N-setBitCount)%MOD;
        ans=ans%MOD;
        ans+=val%MOD;
        ans%=MOD; 
    } 
    return (int)((ans*2)%MOD);
}
