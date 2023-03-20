vector<vector<int>> dp;
int MOD=1000000007;
int countDigSum(int actualDig,int sum,int totalDig){
    if(actualDig==0) return sum==0;

    if(dp[actualDig][sum]!=-1) return dp[actualDig][sum];
    long long int ans=0;
    int startWith=(actualDig==totalDig)?1:0;
    for(int i=startWith;i<=9;i++){
        if(sum-i>=0){
            ans+=countDigSum(actualDig-1,sum-i,totalDig)%MOD;
            ans%=MOD;
        }
    }
    return dp[actualDig][sum]=ans;
}
int Solution::solve(int A, int B) {
    dp.clear();
    dp.resize(A+1,vector<int>(B+1,-1));
    return countDigSum(A,B,A);
}
