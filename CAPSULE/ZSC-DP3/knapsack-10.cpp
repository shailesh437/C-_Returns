
int getMaxValueUnderC(vector<int> &value, 
	vector<int> &weight,
	int currentIndex, 
	int Capacity ,
	vector<vector<int>> &dp
	){
	if(currentIndex==value.size() or Capacity==0) return 0;
	if(   dp[currentIndex][Capacity] !=-1){
		return  dp[currentIndex][Capacity];
	}
	int ans=0;
	if(Capacity>=weight[currentIndex]){
		ans = max(getMaxValueUnderC(value,weight,currentIndex+1,Capacity,dp),
			value[currentIndex]+getMaxValueUnderC(value,weight,currentIndex+1,
				Capacity-weight[currentIndex],dp)
			);
	}else{
		ans = getMaxValueUnderC(value,weight,currentIndex+1, Capacity,dp);
	}
	//cout<<endl<<ans;
	return dp[currentIndex][Capacity] =  ans;                        
}

int getMaxValUnderC_Tabul(vector<int> &A, vector<int> &B, int C){
    vector<vector<int>> dp(A.size()+1,vector<int>(C+1,0));
    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=C;j++){
            dp[i][j]=dp[i-1][j];
            if(j-B[i-1]>=0){
                dp[i][j]=max(dp[i-1][j],
                             A[i-1]+dp[i-1][j-B[i-1]]);
            }
        }
    }
    return dp[A.size()][C];
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
vector<vector<int>> dp(A.size()+1,vector<int>(C+1,-1));
	//return getMaxValueUnderC(A,B,C,dp);
    return getMaxValUnderC_Tabul(A,B,C);

}
