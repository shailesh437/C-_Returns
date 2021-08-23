//https://www.codechef.com/UADPIP01/submit/BLJUMP

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define inf 1e18
#define vi  vector<ll> 

int main(){
	int TC;
	cin>>TC;
	while(TC--){
		ll N,K;
		cin>>N>>K;
		vi h(N);
		for(int i=0;i<N;i++){
			cin>>h[i];
		}
		vi dp(N,inf);	
		dp[0]=0;
		for(int i=1;i<N;i++){		
			for(int j=1;j<=K;j++){
				if((i-j)<0){
					break;
				}
				dp[i]=min(dp[i],abs(h[i]-h[i-j])+dp[i-j]);
			}	
		}
		cout<<dp[N-1]<<endl;
	}
	return 0;
}
