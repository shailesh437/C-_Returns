int Solution::maxSubarray(int A, int B, vector<int> &C) {
    int maxSumLessThanB=0;
    for(int i=0;i<A;i++){
        int sum=0;
        for(int j=i;j<A;j++){
            sum+=C[j];
            if(sum<=B)
            maxSumLessThanB=max(maxSumLessThanB,sum);
        }
    }
    return maxSumLessThanB;
}
