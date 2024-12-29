
vector<vector<int>> dp;
int isMatchHelper(const string A, 
	const string B,
	int i, 
	int j){

	if(j>=B.length()){
		if(i<A.length()){ 
			return 0;	
		} 
		return 1;
	}		

	if(i==A.length()){
		if(B[j+1]=='*' || j==B.length()) return 1; 
		return 0;
	}

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

	int ans=0;
	if(j+1<B.length() and B[j+1]=='*' and  (A[i]==B[j] or B[j]=='.')){
		ans=isMatchHelper(A,B,i+1,j)||
		isMatchHelper(A,B,i,j+2);
	}else if(j+1<B.length() and B[j+1]=='*' and A[i]!=B[j]){
		ans=isMatchHelper(A,B,i,j+2);
	}
	else if(A[i]==B[j] or B[j]=='.'){
		ans=isMatchHelper(A,B,i+1,j+1);
	}else{
		ans=0;
	} 

	return dp[i][j]=ans;
}

int isMatch(const string A, const string B) {
dp=vector<vector<int>>(A.length(),vector<int>(B.length(),-1));  
return isMatchHelper(A,B,0,0);
}
