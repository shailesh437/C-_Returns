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
ll getMinHealth(ll currentCell
	,ll row
	,ll col
	,ll rows
	,ll cols
	,vector<vector<ll>> dp){
	if(row>=rows or col>=cols){
		return inf;
	}

	ll nextCellHealthNeeded = dp[row][col];
	ll ONE=1;
	return max(ONE,nextCellHealthNeeded-currentCell);
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		ll rows,cols;
		cin>>rows>>cols;
		//vector<vector<ll>> grid(rows,vector<ll>(cols));
		ll grid[rows][cols];
		vector<vector<ll>> dp(rows,vector<ll>(cols,inf));
		loop(i,0,rows-1)
		loop(j,0,cols-1)
		cin>>grid[i][j];
		ll currentCell,right,down,nextHealth;
		for(int row = rows-1;row>=0;row--){
			for(int col = cols-1;col>=0;col--){
				currentCell = grid[row][col];
				right=getMinHealth(currentCell,row,col+1,rows,cols,dp);
				down =getMinHealth(currentCell,row+1,col,rows,cols,dp);
				nextHealth = min(right,down);
				if(nextHealth!=inf){
					dp[row][col]=nextHealth;
				}else{
					dp[row][col]=(currentCell>=0)?1:
								  1-currentCell; 
				}
			}
		}
		cout<<dp[0][0];
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
