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
int main(){	
	int N=10;
	int dp[100]={0};
	cout<<getMinCoins(N,dp)<<endl;
	return 0;
}
