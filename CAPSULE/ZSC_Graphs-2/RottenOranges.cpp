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
	int row,
	int col,
	vector<vector<bool>> &visited,
	int &min,
	int orig_row,
	int orig_col
	){
	cout<<endl<<"called";	
	vector<int> dx={-1,1,0,0};
	vector<int> dy={0,0,-1,1};
	if(orig_row==row)
		min++;
	for(int k=0;k<4;k++){
		int r=row+dx[k];
		int c=col+dy[k];
		if(r>=0 and r<A.size() and c>=0 
			and c<A[0].size() and A[r][c]==1){
			visited[r][c]=true;
		A[r][c]=2;  
		cout<<endl<<"endeted";
		bfs(A,r,c,visited,min,row,col);

	}
}


}

int solve(vector<vector<int> > &A) {
	vector<vector<bool>> visited(A.size(),vector<bool> (A[0].size(),false));
	queue<pair<int,int>> Q_rotten_pos;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			if(A[i][j]==2){
				Q_rotten_pos.push(make_pair(i,j));
			}
		}
	}
	int mints=0;
	while(!Q_rotten_pos.empty()){
		int x = Q_rotten_pos.size();
		mints++;
		for(int i=0;i<x;i++){
			pair<int,int> rot_pos=Q_rotten_pos.front();
			Q_rotten_pos.pop();
			
			vector<int> dx={1,-1,0,0};
			vector<int> dy={0,0,1,-1};
			for(int k=0;k<dx.size();k++){
				int r = rot_pos.first+dx[k];
				int c = rot_pos.second+dy[k];
				if(r>=0 and r<A.size() and c>=0 and c<A[0].size() and A[r][c]==1){
					A[r][c]=2;
					Q_rotten_pos.push(make_pair(r,c));
				}
			}
		}
	}
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A[0].size();j++){
			if(A[i][j]==1){
				return -1;
			}
		}
	}
	return mints-1;
}  
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		vector<vector<int>> A = {
			{2, 1, 1},
			{1, 1, 0},
			{0, 1, 1}
		};
		/*A={
			{2, 1, 1},
			{0, 1, 1},
			{1, 0, 1}
		};*/
		int ans = solve(A);
		cout<<endl<<"ANS = "<<ans;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
