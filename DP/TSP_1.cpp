#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
using namespace std;
void file_i_o()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
}
int N,D;
int graph[2001][2001];
int dp[2001][2001];
int ALL_NODES_VISITED;
/*
int getTSP(int i,int remaining,vector<bool> &visited){
	if(remaining==0){
		return graph[i][0]+D*(i+1);
	}
	int result=INT_MAX;
	visited[i]=true;
	for(int j=0;j<N;j++){
		visited[j]=true;
		if(!visited[j]){ 
			int cost = graph[j][i]+getTSP(j,remaining-1,visited);
			result=min(result,
					 cost);
			}
		visited[j]=false;	
	}
	visited[i]=false;
	return result;
}*/
int getTSPByDPBitMasking(int mask,int startAt){
	if(mask==ALL_NODES_VISITED){
		return D*(startAt)+graph[startAt][0];
	}
	int ans=INT_MAX;
	for(int i=0;i<N;i++){
		int visited = 1<<i & mask;
		if(!visited){
			int subAns = D*(abs(i-startAt))
						+graph[startAt][i]
						+getTSPByDPBitMasking(mask|(1<<i),i);
			ans=min(ans,subAns);
		}
	}
	//cout<<"\n for startAt = "<<startAt<<" returning ans = "<<ans<<endl;
	return ans;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		cin>>N>>D;
		vector<bool> visited(N,0);
		memset(graph,0,sizeof graph);
		memset(dp,-1,sizeof dp);
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				int c;
				cin>>c;
				graph[i][j]=c;
				graph[j][i]=c;
			}
		}
		/*for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				cout<<graph[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
		//int mask = N<<1-1;  
		ALL_NODES_VISITED=(1<<N)-1;

		//remainingSet.erase(remainingSet.begin());
		//visited[0]=1;
		//int R = getTSP(0,N-1,visited);
		int R = getTSPByDPBitMasking(0,0);
		cout<<R<<endl;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
