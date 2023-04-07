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
void bfs(vector<vector<int>> &A,
			int i,
			int j,
			vector<vector<bool>> &visited
			){
	if(i<0 or i>=A.size()) return;
	if(j<0 or j>=A[0].size()) return;
	if(A[i][j]==0) return;

	vector<int> dx={-1,1,0,0,-1,-1,1,1};
	vector<int> dy={ 0,0,-1,1,-1,1,-1,1};
	
	for(int k=0;k<dx.size();k++){
		int r=i+dx[k];
		int c=j+dy[k]; 
		if(r<A.size() and c<A[0].size() 
			and r>=0 and c>=0 and 
			A[r][c]==1 and !visited[r][c]){
			visited[r][c]=true;
		bfs(A,r,c,visited);
		}
	}
	return;
}
int solve(vector<vector<int> > &A) {
	vector<vector<bool>> visited(A.size(),vector<bool> (A[0].size(),false));
	int island=0;	
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			if(A[i][j]==1 and !visited[i][j]){
				visited[i][j]=true;
				bfs(A,i,j,visited);
				island++;
			}
		}
	}
	return island;
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<vector<int> > A=
			{
			{0, 1, 0},
			{0, 0, 1},
			{1, 0, 0}
		};
		A={
			{1, 1, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{1, 0, 0, 1, 1},
			{0, 0, 0, 0, 0},
			{1, 0, 1, 0, 1}
		};
		int ans = solve(A);
		cout<<endl<<"ANS = "<<ans;	
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
