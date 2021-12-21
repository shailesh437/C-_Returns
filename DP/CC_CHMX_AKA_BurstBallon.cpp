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
ll burstBalloon(vector<int> &arr){
	ll n = arr.size();
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	for(int len =0;len<n;len++){
		for(int i=0,j=len;j<n;i++,j++){
			for(int k=i;k<=j;k++){
				ll right_range = (k==j)?0:dp[k+1][j];
				ll left_range = (k==i)?0:dp[i][k-1];
				ll current_last_burst_count = 
					((i==0)?1:arr[i-1])*
					((j==n-1)?1:arr[j+1])*
					arr[k];

				dp[i][j]=max(dp[i][j],
							left_range+right_range+current_last_burst_count);
				//cout<<"\n dp["<<i<<"]["<<j<<"] = "<<dp[i][j];	

			}
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
		int N;
		cin>>N;
		std::vector<int> inp(N);
		loop(i,0,N-1) cin>>inp[i];
		ll ans = burstBalloon(inp);
		cout<<ans;
	}
	 #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
	return 0;
	}
