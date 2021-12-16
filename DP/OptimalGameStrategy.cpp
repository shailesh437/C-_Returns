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
ll game(vi &arr){
	int n = arr.size();
	int dp[n][n];
	memset(dp,-1,sizeof(dp));
	for(int len=0;len<n;len++){
		for(int i=0,j=len;j<n;i++,j++){
			int a = ((i+2)<=j)?dp[i+2][j]:0;
			int b = ((i+1)<=(j-1))?dp[i+1][j-1]:0;
			int c = (i<=(j-2))?dp[i][j-2]:0;
			dp[i][j]=max(arr[i] + min(a,b)
						,arr[j] + min(b,c)
						);

		}
	}
	return dp[0][n-1];
}
int main(){
clock_t begin = clock();
	file_i_o();
	int TC;
	cin>>TC;
	while(TC--){
		int n;
		cin>>n;
		vi arr(n);
		loop(i,0,n-1) std::cin>>arr[i];
		cout<<"\n Answer = "<<game(arr);
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
