int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    vector<vector<int>> dp(A.size(),vector<int> (A[0].size(),0));
    dp[A.size()-1][A[0].size()-1]=max(1,
                                    1-A[A.size()-1][A[0].size()-1]);
    int row=A.size()-1;
    for(int col=A[0].size()-2;col>=0;col--){
        dp[row][col]=max(1,dp[row][col+1]-A[row][col]);
    } 
    int col=A[0].size()-1;
    for(int row=A.size()-2;row>=0;row--){
        dp[row][col]=max(1,dp[row+1][col]-A[row][col]);
    } 
    for(int row=A.size()-2;row>=0;row--){
         for(int col=A[0].size()-2;col>=0;col--){
             dp[row][col]=max(1,
                              min(dp[row+1][col],dp[row][col+1])-A[row][col]
                              );  
         }
    }
    return dp[0][0];
}
