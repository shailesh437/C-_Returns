#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std; 
int dp[100005][2];
int vc(int u,int g,vector<vector<int>> &graph,vector<int> parent){
	if(graph[u].size()==0){
		return g;
	}
	if(dp[u][g]!=-1) return dp[u][g];
	int sum=0;
	for(int child: graph[u]){
		if(child!=parent[u]){
			parent[child]=u;
			if(!g){
				sum += vc(child,1,graph,parent);
			}else{
				sum += min(
					vc(child,1,graph,parent),
					vc(child,0,graph,parent)
					);
			}			
		}

	}
	return dp[u][g]=sum+g;
}	

int main(){ 
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		cin>>n;
		vector<vector<int>> graph(n+1,vector<int>(0));
		loop(i,0,n-2){
			int x,y;
			cin>>x>>y;
			graph[x].pb(y);
			graph[y].pb(x);
		}
		vector<int> parent(n+1,-1);
		memset(dp,-1,sizeof dp);
		cout<<min(vc(1,1,graph,parent),vc(1,0,graph,parent))<<endl;	

	} 
	return 0;
}
