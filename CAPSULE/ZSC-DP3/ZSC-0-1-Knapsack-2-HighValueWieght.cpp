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


int solve(vector<int> &A, vector<int> &B, int C) {
	int valueSum=0;
	for(int a:A)valueSum+=a;
		vector<vector<int>> dp(A.size()+1,
			vector<int> (valueSum+1,0));

	for(int i=1;i<=valueSum;i++){
		dp[0][i]=INT_MAX;
	} 
	for(int i=1;i<=A.size();i++){
		dp[i][0]=0;
	}    

	
	for(int eleIndex=1;eleIndex<=A.size();eleIndex++){
		for(int j=1;j<=valueSum;j++){
			if(j<A[eleIndex-1]){
				dp[eleIndex][j]=dp[eleIndex-1][j];
			}else{ 
				dp[eleIndex][j]=min(dp[eleIndex-1][j],
					(dp[eleIndex-1][j-A[eleIndex-1]]==INT_MAX)?INT_MAX:
					B[eleIndex-1]+dp[eleIndex-1][j-A[eleIndex-1]]);
			}
		}

	} 

	for(int i=valueSum;i>=0;i--){
		if(dp[A.size()][i]<=C){
			return i;
		}
	}
	return 0;
}
int main(){
	clock_t begin = clock();
	file_i_o();
	int TC=1;
	//cin>>TC;
	while(TC--){

		vector<int> A = {6, 10, 12}; 
		vector<int> B = {10, 20, 30}; 
		int C = 50;
		/*vector<int> A = {1, 3, 2, 4 };
		vector<int> B = {12, 13, 15, 19 };
		int C = 10;
		*/int ANS = solve(A,B,C);
		cout<<endl<<"ANS = "<<ANS;
	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
