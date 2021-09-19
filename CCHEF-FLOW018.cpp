#include<bits/stdc++.h>
#define ll long long int 
using namespace std; 
int dp[21];
int calcFact(int n){
	if(n<=1) return 1;
	if(dp[n]!=-1){
		return dp[n];
	}
	return dp[n]=n*calcFact(n-1);

}
int main(){ 
	memset(dp,-1,sizeof(dp));
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		cin>>n;
		cout<<calcFact(n);
		cout<<endl;
	} 
	return 0;
	}
