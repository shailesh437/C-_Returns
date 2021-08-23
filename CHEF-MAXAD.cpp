#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define loop(a,b) for(int i=a;i<=b;i++)
using namespace std;
int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		int N;
		cin>>N;
		vi dp(N,0);
		vi inp(N,0);
		loop(0,N-1) cin>>inp[i];
		dp[0]=inp[0];
		dp[1]=max(inp[1],inp[0]);
		if(N==1){
			cout<<inp[0]<<endl;
			continue;	
		}
		if(N==2){
			cout<<max(inp[0],inp[1])<<endl;
			continue;
		}
		for(int i=2;i<N;i++){
			dp[i]=max(dp[i-1],dp[i-2]+inp[i]);
		}
		cout<<dp[N-1]<<endl;
	}
	return 0;
}
