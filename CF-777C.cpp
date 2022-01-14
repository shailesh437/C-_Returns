#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define displayMatrix(mat,startrow,startcol,row,col) for(int i=startrow;i<=row;i++) {for(int j=startcol;j<=col;j++) cout<<mat[i][j]<<" "; cout<<endl; } 
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
int n,m;
int k;
int DP[100001]; 
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		cin>>n>>m;
		int grid[n+1][m+1];
		int dp[n+1][m+2]; 
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>grid[i][j];

			cin>>k;
			int range[k][2];
			for(int i=0;i<k;i++){
				cin>>range[i][0]>>range[i][1];
			}	
			for(int col=1;col<=m;col++){
				int sortedFromRow=1;
				for(int row=2;row<=n;row++){
					if(grid[row][col]>=grid[row-1][col]){
						dp[row][col]=sortedFromRow;
					}else{
						sortedFromRow = row;
						dp[row][col]=sortedFromRow;
					}
				}
			} 
			for(int col=1;col<=m;col++) dp[1][col]=1;
				for(int row=1;row<=n;row++){
					int minValAcrossCol=INT_MAX;
					for(int col=1;col<=m;col++){
						minValAcrossCol=min(minValAcrossCol,dp[row][col]);
					}
					dp[row][m+1]=minValAcrossCol;
				}
				displayMatrix(dp,1,1,n,m+1);
				for(int i=0;i<k;i++){
					if( range[i][0] >=dp[range[i][0]][m+1] 
						&&
						dp[range[i][1]][m+1]<=range[i][0]
						)
						cout<<"Yes"<<endl;
					else
						cout<<"No"<<endl;
				}	
			}
	 #ifndef ONLINE_JUDGE 
			clock_t end = clock();
			cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
			return 0;
		}
