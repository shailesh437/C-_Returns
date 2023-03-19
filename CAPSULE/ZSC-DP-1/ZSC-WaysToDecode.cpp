
int Solution::numDecodings(string A) {
    if(A.length()==1 and A[0]=='0') return 0;
    int MOD=1000000007;
  int dp[A.length()];
	memset(dp,0,sizeof dp);
	dp[0]=1;

    if(A[0]=='0') dp[0]=0;
	/*
	Game is keep checking the last 2 chars
	it could be 00 //nothing can be done so 0 
	it could be 0X //01,02..09 ...only 1 poss, same as prev one
	it could be X0 //valid only if X==1 or X==2 otherwise no contri
	it could be XX //if <=26 contributes to prev as well as prev2prev
	*/
	for(int i=1;i<A.length();i++){

		if(A[i]=='0' and A[i-1]=='0'){
			dp[i]=0;
		}else if(A[i]!='0' and A[i-1]=='0'){
			dp[i]=dp[i-1];
		}else if(A[i]=='0' and A[i-1]!='0'){
			if(A[i-1]=='1' or A[i-1]=='2' ){
				dp[i]=(i>=2)?dp[i-2]:1;
			}else{
				dp[i]=0;
			}
		}else { //if(A[i]!='0' and A[i-1]!='0')
			int numValOf2dig=(A[i-1]-'0')*10+ (A[i]-'0');
			if(numValOf2dig<=26){
				if(i>=2){
					dp[i]=dp[i-1]%MOD+dp[i-2]%MOD;
                    dp[i]%=MOD;
                }else{
                	dp[i]=dp[i-1]%MOD+1;
                    dp[i]%=MOD;

                } 
			}else{
				dp[i]=dp[i-1];
			}	
		}
	}
	return dp[A.length()-1];
}
