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

int main(){
	clock_t begin = clock();
	file_i_o();
	int N,k;
	int value[701];
	int bracket[701];
	
vector<vector<int>> dp(701,vector<int>(701,0));
	int TC=1;
	//cin>>TC;
	while(TC--){
		cin>>N>>k;
		for(int i=1;i<=N;i++){
			cin>>value[i];
		}
		for(int i=1;i<=N;i++){
			cin>>bracket[i];
		}
		cout<<endl<<"N = "<<N<<"::k="<<k<<endl;
		logarr(value,1,N);
		logarr(bracket,1,N);
		
		for(int start=N;start>0;start--){
			for(int end=start+1;end<=N;end++){

				if(bracket[end]==bracket[start]+k){
					dp[start][end]=max(dp[start][end],value[start]+value[end]+dp[start+1][end-1]);
				}

				for(int m=start;m<end;m++){
					dp[start][end]=max(dp[start][end],									  
						dp[start][m]
						+dp[m+1][end]

						);	
				}
			}
		}

		cout<<endl<<"ANS = "<<dp[1][N];

	}
	 #ifndef ONLINE_JUDGE 
	clock_t end = clock();
	cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
}
