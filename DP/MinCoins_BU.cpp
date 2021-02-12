#include<iostream>
#include <climits>
using namespace std;

int coins[]={1,6,7,8,10};
int getMinCoins(int N,int dp[]){
	if(N==0){
		return 0;
	}
	if(dp[N]!=0){
		return dp[N];
	}
	int ans=INT_MAX;
	for(int i=0;i<5;i++){
		if(N-coins[i]>=0){
			ans=min(ans,1+getMinCoins(N-coins[i],dp));
		}
		dp[N]=ans;
	}
	return dp[N];
}
int getMinCoinsBU(int N,int dp[]){
for(int i=1;i<=N;i++){
	int ans = INT_MAX;
	for(int coin=0;coin<5;coin++){
		if(i-coins[coin]>=0)
		ans=min(ans,1+dp[i-coins[coin]]);
	}
	dp[i]=ans;
}
return dp[N];
}
int main(){	
	int N=16;
	int dp[100]={0};
	cout<<getMinCoins(N,dp)<<endl;
	dp[100]={0};
	N=16;
	cout<<getMinCoinsBU(N,dp)<<endl;
	N=32;
	dp[100]={0};
	cout<<getMinCoinsBU(32,dp)<<endl;
	return 0;
}
