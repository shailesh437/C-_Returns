#include<iostream>
using namespace std;

int getTotalWays_1(int N,int K){
	if(N<=0){
		return 1;
	}
	int ways=0;
	for(int i=1;i<=K;i++){
		if(N-i>=0)
		ways+=getTotalWays_1(N-i,K);
	}
	return ways;
}


int getTotalWays(int N,int dp[],int K){
	if(N<=0){
		return 1;
	}
	if(dp[N]!=0){
		return dp[N];
	}
	int ways=0;
	for(int i=1;i<=K;i++){
		if(N-i>=0)
		ways+=getTotalWays(N-i,dp,K);
	}
	return dp[N]=ways;
}

int getTotalWays_2(int N,int dp[],int K){
	if(N==0){
		return 1;
	}
	if(dp[N]!=0){
		return dp[N];
	}
	int ways=0;
	for(int i=1;i<=K;i++){
		if(N-i>=0)
		ways+=getTotalWays_2(N-i,dp,K);
	}
	return dp[N]=ways;
}

int main(){
	int N=4;
	int K=3;
	cout<<"\n getTotalWays = "<<getTotalWays_1(N,K);
	int dp[100]={0};
	cout<<"\n getTotalWays = "<<getTotalWays(N,dp,K);
	dp[100]={0};
	cout<<"\n getTotalWays = "<<getTotalWays_2(N,dp,K);
}
