int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int>> dp;
    dp.clear();
    dp.resize(A.size()+1,vector<int>(A.size()+1,0));
    dp[0][0]=A[0][0];
    for(int i=1;i<A.size();i++){
        for(int j=0;j<=i;j++)
                if(j==0){
                    dp[i][j]=dp[i-1][j]+A[i][j];
                }else if(j==i){
                    dp[i][j]=dp[i-1][j-1]+A[i][j];

                }else{
                    dp[i][j]=min(dp[i-1][j-1]+A[i][j],
                             dp[i-1][j]+A[i][j]);

                }
       //  logarr(dp[i],0,dp[i].size()-1);       
    }
    int ans=INT_MAX;
    for(int col=0;col<A[A.size()-1].size();col++){
       // cout<<endl<<dp[A.size()-1][col];
        ans=min(ans,dp[A.size()-1][col]);
    }    
    return ans;
}
