vector<int> dp(100001,-1);
int Solution::countMinSquares(int A) {
    if(A==0) return 0;
    if(dp[A]!=-1) return dp[A];
    int ans=INT_MAX;
    for(int x=1;x*x<=A;x++){
        ans=min(ans,1+countMinSquares(A-(x*x)));
    }
    return dp[A]=ans;
}
