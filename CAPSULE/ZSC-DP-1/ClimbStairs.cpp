int MOD=1000000007;

int countWays(int stepsRemaining,vector<int> &dp){
    if(dp[stepsRemaining]!=-1) return dp[stepsRemaining];
    int ways=countWays(stepsRemaining-1,dp)%MOD+countWays(stepsRemaining-2,dp)%MOD;
    return dp[stepsRemaining]=ways%MOD;
}
int Solution::climbStairs(int A) {
    vector<int> dp(A+1,-1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    return countWays(A,dp);
}
