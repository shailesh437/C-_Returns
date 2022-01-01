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

vector<int> graph[100005];
int dp[100005];

int findLongestPath(int src){
	if(dp[src]!=-1){
		return dp[src];
	}
	int maxValue=0;
	int leaf=1;
	for(int child: graph[src]){
		leaf=0;
		maxValue = max(maxValue,findLongestPath(child));
	}
	return 	dp[src] = leaf?0:(1+maxValue);

}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		memset(dp,-1,sizeof dp);
		int N,M;
		cin>>N>>M;
		loop(i,0,M-1){

			int x,y;
			cin>>x>>y;
			graph[x].pb(y);	
		}
		int result = INT_MIN;
		loop(i,1,N){
			result = max(result,
					findLongestPath(i));

		}
		cout<<"Ans = "<<result;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
