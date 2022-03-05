#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll> 
#define pb push_back
#define inf 1e18
#define loop(i,a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;

#define log2darr(arr,a,b)	for(int z=0;z<=(a);z++) { for(int y=0;y<=(b);y++) cout<<(arr[z][y])<<" ";cout<<endl;}
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
	void prepareMat(vector<vector<int>> &mat,
		vector<int> &nums,int n,int k){

		for(int i=0;i<n;i++){
			int lengthCovered=0;
			for(int j=i;j<n && (k>=(nums[j]+lengthCovered));j++){
				mat[i][j]=pow(k-nums[j]-lengthCovered,2);
				lengthCovered+=(nums[j]+1);
				if(j==n-1){
					mat[i][j]=0;
				}
			}
		}
		mat[n-1][n-1]=0;
		//log2darr(mat,n-1,n-1);
	}
int solveWordWrap(vector<int>nums, int k) 
{ 
        // Code here
	int n=nums.size();
	vector<vector<int>> mat(n,vector<int>(n,-1));
		//memset(mat,0,sizeof mat);	
	prepareMat(mat,nums,n,k);
	int cost[n+1];
	memset(cost,0,sizeof cost);
	//logarr(cost,0,n-1);
	for(int i=n-2;i>=0;i--){
		int costFori=INT_MAX;
		for(int j=i;j<n;j++){
			if(mat[i][j]<0) break;
			cost[i]=mat[i][j]+cost[j+1];
			costFori = min(costFori,cost[i]);
		}
		cost[i] = costFori;
		//logarr(cost,0,n-1);
	}
	return cost[0];
}

int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){
		//int n=4;
		//vector<int> nums={3,2,2,5};
/*		int n=5;
		vector<int> nums={3,2,2,5,4};
		int k=6;
*/
		int n=8;
		vector<int> nums={10 ,6 ,5 ,3 ,1 ,10 ,8 ,2};
		int k=12;

		int ans = solveWordWrap(nums,k);
		cout<<endl<<ans;

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
