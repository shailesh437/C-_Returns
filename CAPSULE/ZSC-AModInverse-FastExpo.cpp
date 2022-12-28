long long int fastExpo(int base,int power,int MOD){
	if(power==1) return base%MOD;
	if(power==0) return 1;
	
	long long int common =
	(fastExpo(base,power/2,MOD)*
				fastExpo(base,power/2,MOD))%MOD;
	if(power&1){
		long long int ans1=(base%MOD*common%MOD)%MOD;		 
		return ans1;
	}
	return common;
}
int Solution::solve(int A, int B) {
    long long int ans = fastExpo(A%B,B-2,B);
     return (int)ans;
}
