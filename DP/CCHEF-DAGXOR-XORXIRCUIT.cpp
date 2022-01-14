#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define mod 1000000007
using namespace std; 
ll dp[100005][5]; 
vector<vector<ll>> adjMatrix(100005);
ll n;
ll calculatePossibleWays(ll node,ll XORValue,ll parent){
	if(node==n){
		return (XORValue == 0);
	}
	if(dp[node][XORValue] != -1){
		return dp[node][XORValue];
	}
	ll result=0;
	ll isLeaf=1;
	for(int k=0;k<4;k++){		
			ll possibleWaysAtAnyNode=1;
			for(auto child:adjMatrix[node]){
				if(child!=parent){
				isLeaf=0;
				possibleWaysAtAnyNode = ((possibleWaysAtAnyNode%mod) 
				*(calculatePossibleWays(child,XORValue^k,node)%mod))%mod;
				}
		}
			result=(result + possibleWaysAtAnyNode)%mod;

	}
	if(isLeaf){
		result=0;
		for(int k=0;k<4;k++){
			result = (result + calculatePossibleWays(n,XORValue^k,node))%mod;
		}

	}
	return dp[node][XORValue]=result;
}
int main(){
	int TC;
	cin>>TC;
	while(TC--){
		cin>>n;
		for(int i=0;i< (n-2) ;i++){
			ll u,v;
			cin>>u>>v;
			adjMatrix[u].pb(v);
			adjMatrix[v].pb(u);
		}
		memset(dp,-1,sizeof dp);
		ll ans = (4LL*calculatePossibleWays(1,0,0))%mod;
		cout<<ans<<endl;
		
		for(ll i=1;i<=n;i++){
			adjMatrix[i].clear();
		}
	} 
	return 0;
}
